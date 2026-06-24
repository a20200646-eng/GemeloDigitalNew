#pragma once
#include "DBConnection.h"
#include "PanelLateralController.h"
#include "EstructuraTechoController.h"
#include "CicloController.h"

using namespace System;
using namespace System::Collections::Generic;
using namespace System::Data;
using namespace System::Data::SqlClient;
using namespace GemeloDigitalModel; 

namespace GemeloDigitalController {

    public ref class LineaEnsamblajeController {
    public:
        LineaEnsamblajeController() {}

        void cargarArchivo(PanelLateralController^ ctrlPanel, EstructuraTechoController^ ctrlTecho) {}

        // ==========================================================
        // CREATE
        // ==========================================================
        bool agregar(String^ id) {
            if (buscarPorId(id) != nullptr) return false;

            SqlConnection^ conn = DBConnection::GetConnection();
            SqlCommand^ cmd = gcnew SqlCommand("sp_LineasEnsamblaje_Insertar", conn);
            cmd->CommandType = CommandType::StoredProcedure;
            cmd->Parameters->AddWithValue("@Id", id);
            cmd->Parameters->AddWithValue("@IndiceActual", 0);
            cmd->Parameters->AddWithValue("@SecuenciaAprobada", 0);

            try {
                conn->Open();
                cmd->ExecuteNonQuery();
                return true;
            }
            catch (Exception^ ex) {
                throw gcnew Exception("Error al agregar linea: " + ex->Message);
            }
            finally {
                if (conn->State == ConnectionState::Open) conn->Close();
            }
        }

        // ==========================================================
        // READ: BUSCAR POR ID
        // ==========================================================
        LineaEnsamblajeModel^ buscarPorId(String^ id) {
            LineaEnsamblajeModel^ lineaObj = nullptr;
            SqlConnection^ conn = DBConnection::GetConnection();
            SqlCommand^ cmd = gcnew SqlCommand("sp_LineasEnsamblaje_BuscarPorId", conn);
            cmd->CommandType = CommandType::StoredProcedure;
            cmd->Parameters->AddWithValue("@Id", id);

            try {
                conn->Open();
                SqlDataReader^ reader = cmd->ExecuteReader();

                if (reader->Read()) {
                    String^ resId = reader->GetValue(0)->ToString();

                    int resIndiceActual = 0;
                    Int32::TryParse(reader->GetValue(1)->ToString(), resIndiceActual);

                    // FIX: BIT de SQL Server puede devolver "True"/"False" o "1"/"0"
                    bool resSecuenciaAprobada = false;
                    Object^ valAprobada = reader->GetValue(2);
                    if (valAprobada != nullptr && valAprobada != DBNull::Value) {
                        String^ strVal = valAprobada->ToString()->ToLower()->Trim();
                        resSecuenciaAprobada = (strVal == "1" || strVal == "true");
                    }

                    lineaObj = gcnew LineaEnsamblajeModel(resId);
                    lineaObj->IndiceActual = resIndiceActual;
                    lineaObj->SecuenciaAprobada = resSecuenciaAprobada;
                }
                reader->Close();
            }
            catch (Exception^ ex) {
                throw gcnew Exception("Error al buscar linea por ID: " + ex->Message);
            }
            finally {
                if (conn->State == ConnectionState::Open) conn->Close();
            }

            if (lineaObj != nullptr)
                CargarColaPiezasParaLinea(lineaObj);

            return lineaObj;
        }

        // ==========================================================
        // READ: OBTENER TODAS
        // ==========================================================
        List<LineaEnsamblajeModel^>^ obtenerTodos() {
            List<LineaEnsamblajeModel^>^ lista = gcnew List<LineaEnsamblajeModel^>();
            SqlConnection^ conn = DBConnection::GetConnection();
            SqlCommand^ cmd = gcnew SqlCommand("sp_LineasEnsamblaje_ObtenerTodos", conn);
            cmd->CommandType = CommandType::StoredProcedure;

            try {
                conn->Open();
                SqlDataReader^ reader = cmd->ExecuteReader();

                while (reader->Read()) {
                    String^ id = reader->GetValue(0)->ToString();

                    int indiceActual = 0;
                    Int32::TryParse(reader->GetValue(1)->ToString(), indiceActual);

                    // FIX: BIT de SQL Server puede devolver "True"/"False" o "1"/"0"
                    bool secuenciaAprobada = false;
                    Object^ valAprobada = reader->GetValue(2);
                    if (valAprobada != nullptr && valAprobada != DBNull::Value) {
                        String^ strVal = valAprobada->ToString()->ToLower()->Trim();
                        secuenciaAprobada = (strVal == "1" || strVal == "true");
                    }

                    LineaEnsamblajeModel^ l = gcnew LineaEnsamblajeModel(id);
                    l->IndiceActual = indiceActual;
                    l->SecuenciaAprobada = secuenciaAprobada;
                    lista->Add(l);
                }
                reader->Close();
            }
            catch (Exception^ ex) {
                throw gcnew Exception("Error al obtener lineas: " + ex->Message);
            }
            finally {
                if (conn->State == ConnectionState::Open) conn->Close();
            }

            for each (LineaEnsamblajeModel ^ l in lista)
                CargarColaPiezasParaLinea(l);

            return lista;
        }

        // ==========================================================
        // UPDATE
        // ==========================================================
        bool modificar(String^ id, int indiceActual, bool secuenciaAprobada) {
            SqlConnection^ conn = DBConnection::GetConnection();
            SqlCommand^ cmd = gcnew SqlCommand("sp_LineasEnsamblaje_Modificar", conn);
            cmd->CommandType = CommandType::StoredProcedure;

            cmd->Parameters->AddWithValue("@Id", id);
            cmd->Parameters->AddWithValue("@IndiceActual", indiceActual);
            cmd->Parameters->AddWithValue("@SecuenciaAprobada", secuenciaAprobada ? 1 : 0);

            try {
                conn->Open();
                int filasAfectadas = cmd->ExecuteNonQuery();
                return (filasAfectadas > 0);
            }
            catch (Exception^ ex) {
                throw gcnew Exception("Error al modificar linea: " + ex->Message);
            }
            finally {
                if (conn->State == ConnectionState::Open) conn->Close();
            }
        }

        // ==========================================================
        // DELETE
        // ==========================================================
        
        // Devuelve "" si se elimino correctamente, o un mensaje de motivo si esta bloqueado por regla de negocio.
        // Solo lanza throw para errores tecnicos (BD/conexion).
        String^ eliminar(String^ id) {
            if (tieneCicloActivo(id)) {
                return "No se puede eliminar la linea: tiene un ciclo activo en curso.";
            }

            // Cargar la linea para conocer las piezas en su cola ANTES de borrar
            LineaEnsamblajeModel^ l = buscarPorId(id);
            List<PiezaModel^>^ piezas = (l != nullptr)
                ? gcnew List<PiezaModel^>(l->ColaPiezas)
                : gcnew List<PiezaModel^>();

            SqlConnection^ conn = DBConnection::GetConnection();
            try {
                conn->Open();

                SqlCommand^ cmdCola = gcnew SqlCommand("sp_LineaCola_LimpiarPorLinea", conn);
                cmdCola->CommandType = CommandType::StoredProcedure;
                cmdCola->Parameters->AddWithValue("@LineaId", id);
                cmdCola->ExecuteNonQuery();

                SqlCommand^ cmdLinea = gcnew SqlCommand("sp_LineasEnsamblaje_Eliminar", conn);
                cmdLinea->CommandType = CommandType::StoredProcedure;
                cmdLinea->Parameters->AddWithValue("@Id", id);
                cmdLinea->ExecuteNonQuery();
            }
            catch (Exception^ ex) {
                throw gcnew Exception("Error al eliminar linea: " + ex->Message);
            }
            finally {
                if (conn->State == ConnectionState::Open) conn->Close();
            }

            // Verificamos si realmente se elimino (NOCOUNT ON hace que ExecuteNonQuery no sea confiable)
            bool eliminada = (buscarPorId(id) == nullptr);
            if (!eliminada) {
                return "No se pudo eliminar la linea.";
            }

            // Restaurar estado DISPONIBLE solo de piezas que NO estan ENSAMBLADA
            PanelLateralController^ ctrlPanel = gcnew PanelLateralController();
            EstructuraTechoController^ ctrlTecho = gcnew EstructuraTechoController();
            for each (PiezaModel ^ p in piezas) {
                if (p->Estado == EstadoPieza::ENSAMBLADA) continue; // se queda como esta

                PanelLateralModel^ pl = dynamic_cast<PanelLateralModel^>(p);
                if (pl != nullptr)
                    ctrlPanel->modificar(p->Id, p->Material, p->Peso,
                        EstadoPieza::DISPONIBLE, pl->PuntosAnclaje, pl->EstacionId);
                else {
                    EstructuraTechoModel^ et = dynamic_cast<EstructuraTechoModel^>(p);
                    if (et != nullptr)
                        ctrlTecho->modificar(p->Id, p->Material, p->Peso,
                            EstadoPieza::DISPONIBLE, et->PuntosUnion, et->Anchura, et->EstacionId);
                }
            }

            return ""; // exito
        }








        // ==========================================================
        // AGREGAR PIEZA A LA COLA
        // ==========================================================
        bool agregarPieza(String^ idLinea, PiezaModel^ pieza) {
            LineaEnsamblajeModel^ l = buscarPorId(idLinea);
            if (l == nullptr || pieza == nullptr) return false;

            l->agregarPieza(pieza);
            int posicionOrden = l->ColaPiezas->Count;

            SqlConnection^ conn = DBConnection::GetConnection();
            try {
                conn->Open();

                PanelLateralModel^ pl = dynamic_cast<PanelLateralModel^>(pieza);
                int tipoPieza = (pl != nullptr) ? 0 : 1;

                SqlCommand^ cmd = gcnew SqlCommand("sp_LineaCola_Insertar", conn);
                cmd->CommandType = CommandType::StoredProcedure;
                cmd->Parameters->AddWithValue("@LineaId", idLinea);
                cmd->Parameters->AddWithValue("@Orden", posicionOrden);
                cmd->Parameters->AddWithValue("@TipoPieza", tipoPieza);
                cmd->Parameters->AddWithValue("@PiezaId", pieza->Id);

                cmd->ExecuteNonQuery();
                return true;
            }
            catch (Exception^ ex) {
                throw gcnew Exception("Error al registrar pieza en cola SQL: " + ex->Message);
            }
            finally {
                if (conn->State == ConnectionState::Open) conn->Close();
            }
        }


        // ==========================================================
        // RETIRAR UNA PIEZA DE LA COLA (sin borrar la linea)
        // ==========================================================
        
        // Devuelve "" si se retiro correctamente, o un mensaje de motivo si esta bloqueado por regla de negocio.
        // Solo lanza throw para errores tecnicos (BD/conexion).
        String^ eliminarPieza(String^ idLinea, String^ piezaId, String^ tipoPieza) {
            if (tieneCicloActivo(idLinea)) {
                return "No se puede retirar la pieza: la linea tiene un ciclo activo en curso.";
            }

            // Verificar estado actual de la pieza antes de retirar
            EstadoPieza estadoActual;
            if (tipoPieza->StartsWith("Panel")) {
                PanelLateralController^ ctrlPanel = gcnew PanelLateralController();
                PanelLateralModel^ p = ctrlPanel->buscarPorId(piezaId);
                if (p == nullptr) return "Pieza no encontrada.";
                estadoActual = p->Estado;
            }
            else {
                EstructuraTechoController^ ctrlTecho = gcnew EstructuraTechoController();
                EstructuraTechoModel^ e = ctrlTecho->buscarPorId(piezaId);
                if (e == nullptr) return "Pieza no encontrada.";
                estadoActual = e->Estado;
            }

            if (estadoActual == EstadoPieza::ENSAMBLADA) {
                return "No se puede retirar una pieza ya ENSAMBLADA.";
            }

            SqlConnection^ conn = DBConnection::GetConnection();
            SqlCommand^ cmd = gcnew SqlCommand("sp_LineaCola_EliminarPieza", conn);
            cmd->CommandType = CommandType::StoredProcedure;
            cmd->Parameters->AddWithValue("@LineaId", idLinea);
            cmd->Parameters->AddWithValue("@PiezaId", piezaId);

            try {
                conn->Open();
                cmd->ExecuteNonQuery();
            }
            catch (Exception^ ex) {
                throw gcnew Exception("Error al retirar pieza de cola: " + ex->Message);
            }
            finally {
                if (conn->State == ConnectionState::Open) conn->Close();
            }

            // Restaurar estado DISPONIBLE
            if (tipoPieza->StartsWith("Panel")) {
                PanelLateralController^ ctrlPanel = gcnew PanelLateralController();
                PanelLateralModel^ p = ctrlPanel->buscarPorId(piezaId);
                if (p != nullptr)
                    ctrlPanel->modificar(p->Id, p->Material, p->Peso,
                        EstadoPieza::DISPONIBLE, p->PuntosAnclaje, p->EstacionId);
            }
            else {
                EstructuraTechoController^ ctrlTecho = gcnew EstructuraTechoController();
                EstructuraTechoModel^ e = ctrlTecho->buscarPorId(piezaId);
                if (e != nullptr)
                    ctrlTecho->modificar(e->Id, e->Material, e->Peso,
                        EstadoPieza::DISPONIBLE, e->PuntosUnion, e->Anchura, e->EstacionId);
            }

            return ""; // exito
        }



        // ==========================================================
        // VERIFICA SI LA LINEA TIENE UN CICLO ACTIVO EN CURSO
        // ==========================================================
        bool tieneCicloActivo(String^ idLinea) {
            String^ sufijoActivo = CicloController::obtenerCicloActivo();
            if (sufijoActivo == nullptr) return false;
            return sufijoActivo->StartsWith(idLinea + "-C");
        }


    private:
        void CargarColaPiezasParaLinea(LineaEnsamblajeModel^ lineaObj) {
            PanelLateralController^ ctrlPanel = gcnew PanelLateralController();
            EstructuraTechoController^ ctrlTecho = gcnew EstructuraTechoController();

            List<array<String^>^>^ filas = gcnew List<array<String^>^>();

            SqlConnection^ conn = DBConnection::GetConnection();
            SqlCommand^ cmd = gcnew SqlCommand("sp_LineaCola_ObtenerPorLinea", conn);
            cmd->CommandType = CommandType::StoredProcedure;
            cmd->Parameters->AddWithValue("@LineaId", lineaObj->Id);

            try {
                conn->Open();
                SqlDataReader^ reader = cmd->ExecuteReader();
                while (reader->Read()) {
                    array<String^>^ fila = gcnew array<String^>(2);
                    fila[0] = reader->GetValue(2)->ToString(); // TipoPieza — posición 2
                    fila[1] = reader->GetValue(1)->ToString(); // PiezaId — posición 1
                    filas->Add(fila);
                }
                reader->Close();
   
            }
            catch (Exception^ ex) {
                throw gcnew Exception("Error al leer cola de piezas: " + ex->Message);
            }
            finally {
                if (conn->State == ConnectionState::Open) conn->Close();
            }

            for each (array<String^> ^ fila in filas) {
                int tipoPieza = 0;
                Int32::TryParse(fila[0], tipoPieza);
                String^ piezaId = fila[1];

                if (tipoPieza == 0) {
                    PanelLateralModel^ p = ctrlPanel->buscarPorId(piezaId);
                    if (p != nullptr) lineaObj->ColaPiezas->Add(p);
                }
                else {
                    EstructuraTechoModel^ e = ctrlTecho->buscarPorId(piezaId);
                    if (e != nullptr) lineaObj->ColaPiezas->Add(e);
                }
            }
        }
    };
}