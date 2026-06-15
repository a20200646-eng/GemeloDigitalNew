#pragma once
#include "PanelLateralController.h"
#include "EstructuraTechoController.h"

using namespace System;
using namespace System::Collections::Generic;
using namespace System::Data;
using namespace System::Data::SqlClient;
using namespace GemeloDigitalModel;

namespace GemeloDigitalController {

    public ref class LineaEnsamblajeController {
    private:
        String^ connectionString = "Server=bdmijael23.cczveeoo8rq2.us-east-1.rds.amazonaws.com,1433;" +
            "Database=bdmijael23;" +
            "User Id=admin;" +
            "Password=abcd1234;";

    public:
        LineaEnsamblajeController() {}

        void cargarArchivo(PanelLateralController^ ctrlPanel, EstructuraTechoController^ ctrlTecho) {
            // Método vacío para compatibilidad con las invocaciones de tus formularios gráficos.
        }

        // ==========================================================
        // CREATE: AGREGAR LÍNEA
        // ==========================================================
        bool agregar(String^ id) {
            if (buscarPorId(id) != nullptr) return false;

            SqlConnection^ conn = gcnew SqlConnection(connectionString);
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
                throw gcnew Exception("Error al agregar línea de ensamblaje: " + ex->Message);
            }
            finally {
                if (conn->State == ConnectionState::Open) conn->Close();
            }
        }

        // ==========================================================
        // READ: BUSCAR LÍNEA POR ID
        // ==========================================================
        LineaEnsamblajeModel^ buscarPorId(String^ id) {
            LineaEnsamblajeModel^ lineaObj = nullptr;
            SqlConnection^ conn = gcnew SqlConnection(connectionString);
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

                    int resAprobadaInt = 0;
                    Int32::TryParse(reader->GetValue(2)->ToString(), resAprobadaInt);
                    bool resSecuenciaAprobada = (resAprobadaInt == 1);

                    lineaObj = gcnew LineaEnsamblajeModel(resId);
                    lineaObj->IndiceActual = resIndiceActual;
                    lineaObj->SecuenciaAprobada = resSecuenciaAprobada;
                }
                reader->Close();

                if (lineaObj != nullptr) {
                    CargarColaPiezasParaLinea(lineaObj, conn);
                }
            }
            catch (Exception^ ex) {
                throw gcnew Exception("Error al buscar línea por ID: " + ex->Message);
            }
            finally {
                if (conn->State == ConnectionState::Open) conn->Close();
            }
            return lineaObj;
        }

        // ==========================================================
        // READ: OBTENER TODAS LAS LÍNEAS
        // ==========================================================
        List<LineaEnsamblajeModel^>^ obtenerTodos() {
            List<LineaEnsamblajeModel^>^ lista = gcnew List<LineaEnsamblajeModel^>();
            SqlConnection^ conn = gcnew SqlConnection(connectionString);
            SqlCommand^ cmd = gcnew SqlCommand("sp_LineasEnsamblaje_ObtenerTodos", conn);
            cmd->CommandType = CommandType::StoredProcedure;

            try {
                conn->Open();
                SqlDataReader^ reader = cmd->ExecuteReader();

                while (reader->Read()) {
                    String^ id = reader->GetValue(0)->ToString();

                    int indiceActual = 0;
                    Int32::TryParse(reader->GetValue(1)->ToString(), indiceActual);

                    int aprobadaInt = 0;
                    Int32::TryParse(reader->GetValue(2)->ToString(), aprobadaInt);
                    bool secuenciaAprobada = (aprobadaInt == 1);

                    LineaEnsamblajeModel^ l = gcnew LineaEnsamblajeModel(id);
                    l->IndiceActual = indiceActual;
                    l->SecuenciaAprobada = secuenciaAprobada;
                    lista->Add(l);
                }
                reader->Close();

                for each (LineaEnsamblajeModel ^ l in lista) {
                    CargarColaPiezasParaLinea(l, conn);
                }
            }
            catch (Exception^ ex) {
                throw gcnew Exception("Error al obtener líneas: " + ex->Message);
            }
            finally {
                if (conn->State == ConnectionState::Open) conn->Close();
            }
            return lista;
        }

        // ==========================================================
        // UPDATE: MODIFICAR LÍNEA
        // ==========================================================
        bool modificar(String^ id, int indiceActual, bool secuenciaAprobada) {
            SqlConnection^ conn = gcnew SqlConnection(connectionString);
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
                throw gcnew Exception("Error al modificar línea: " + ex->Message);
            }
            finally {
                if (conn->State == ConnectionState::Open) conn->Close();
            }
        }

        // ==========================================================
        // DELETE: ELIMINAR LÍNEA
        // ==========================================================
        bool eliminar(String^ id) {
            SqlConnection^ conn = gcnew SqlConnection(connectionString);
            try {
                conn->Open();

                SqlCommand^ cmdCola = gcnew SqlCommand("sp_LineaCola_LimpiarPorLinea", conn);
                cmdCola->CommandType = CommandType::StoredProcedure;
                cmdCola->Parameters->AddWithValue("@LineaId", id);
                cmdCola->ExecuteNonQuery();

                SqlCommand^ cmdLinea = gcnew SqlCommand("sp_LineasEnsamblaje_Eliminar", conn);
                cmdLinea->CommandType = CommandType::StoredProcedure;
                cmdLinea->Parameters->AddWithValue("@Id", id);

                int filasAfectadas = cmdLinea->ExecuteNonQuery();
                return (filasAfectadas > 0);
            }
            catch (Exception^ ex) {
                throw gcnew Exception("Error al eliminar línea: " + ex->Message);
            }
            finally {
                if (conn->State == ConnectionState::Open) conn->Close();
            }
        }

        // ==========================================================
        // SOLUCIÓN AL ERROR: AGREGAR PIEZA ENVIANDO EL PARAMETRO @Orden
        // ==========================================================
        bool agregarPieza(String^ idLinea, PiezaModel^ pieza) {
            LineaEnsamblajeModel^ l = buscarPorId(idLinea);
            if (l == nullptr || pieza == nullptr) return false;

            l->agregarPieza(pieza);

            // Determinamos la posición/orden en la cola de elementos local
            int posicionOrden = l->ColaPiezas->Count;

            SqlConnection^ conn = gcnew SqlConnection(connectionString);
            try {
                conn->Open();

                PanelLateralModel^ pl = dynamic_cast<PanelLateralModel^>(pieza);
                int tipoPieza = (pl != nullptr) ? 0 : 1;

                SqlCommand^ cmd = gcnew SqlCommand("sp_LineaCola_Insertar", conn);
                cmd->CommandType = CommandType::StoredProcedure;
                cmd->Parameters->AddWithValue("@LineaId", idLinea);
                cmd->Parameters->AddWithValue("@TipoPieza", tipoPieza);
                cmd->Parameters->AddWithValue("@PiezaId", pieza->Id);

                // INYECTAMOS EL PARÁMETRO FALTANTE REQUERIDO POR TU BASE DE DATOS
                cmd->Parameters->AddWithValue("@Orden", posicionOrden);

                cmd->ExecuteNonQuery();
                return true;
            }
            catch (Exception^ ex) {
                throw gcnew Exception("Error al registrar pieza en la cola de producción en SQL: " + ex->Message);
            }
            finally {
                if (conn->State == ConnectionState::Open) conn->Close();
            }
        }

    private:
        void CargarColaPiezasParaLinea(LineaEnsamblajeModel^ lineaObj, SqlConnection^ conn) {
            PanelLateralController^ ctrlPanel = gcnew PanelLateralController();
            EstructuraTechoController^ ctrlTecho = gcnew EstructuraTechoController();

            SqlCommand^ cmd = gcnew SqlCommand("sp_LineaCola_ObtenerPorLinea", conn);
            cmd->CommandType = CommandType::StoredProcedure;
            cmd->Parameters->AddWithValue("@LineaId", lineaObj->Id);

            SqlDataReader^ reader = cmd->ExecuteReader();
            while (reader->Read()) {
                int tipoPieza = 0;
                Int32::TryParse(reader->GetValue(1)->ToString(), tipoPieza);
                String^ piezaId = reader->GetValue(2)->ToString();

                if (tipoPieza == 0) {
                    PanelLateralModel^ p = ctrlPanel->buscarPorId(piezaId);
                    if (p != nullptr) lineaObj->ColaPiezas->Add(p);
                }
                else {
                    EstructuraTechoModel^ e = ctrlTecho->buscarPorId(piezaId);
                    if (e != nullptr) lineaObj->ColaPiezas->Add(e);
                }
            }
            reader->Close();
        }
    };
}