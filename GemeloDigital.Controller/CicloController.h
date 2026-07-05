#pragma once
#include "DBConnection.h"

using namespace System;
using namespace System::Collections::Generic;
using namespace System::Data;
using namespace System::Data::SqlClient;
using namespace GemeloDigitalModel;

namespace GemeloDigitalController {

    public ref class CicloController {
    public:
        CicloController() {}

        // ==========================================================
        // CREATE: INSERTAR CICLO
        // ==========================================================
        bool agregar(String^ id, double horas, String^ estado) {
            if (buscarPorId(id) != nullptr) return false;

            SqlConnection^ conn = DBConnection::GetConnection();
            SqlCommand^ cmd = gcnew SqlCommand("sp_Ciclos_Insertar", conn);
            cmd->CommandType = CommandType::StoredProcedure;

            cmd->Parameters->AddWithValue("@Id", id);
            cmd->Parameters->AddWithValue("@HorasTrabajadas", horas);
            cmd->Parameters->AddWithValue("@Estado", estado);

            try {
                conn->Open();
                cmd->ExecuteNonQuery();
                return true;
            }
            catch (Exception^ ex) {
                throw gcnew Exception("Error al insertar ciclo: " + ex->Message);
            }
            finally {
                if (conn->State == ConnectionState::Open) conn->Close();
            }
        }

        // ==========================================================
        // READ: BUSCAR POR ID
        // ==========================================================
        CicloModel^ buscarPorId(String^ id) {
            CicloModel^ ciclo = nullptr;
            SqlConnection^ conn = DBConnection::GetConnection();
            SqlCommand^ cmd = gcnew SqlCommand("sp_Ciclos_ObtenerTodos", conn);
            cmd->CommandType = CommandType::StoredProcedure;

            // No hay sp_Ciclos_BuscarPorId en los SPs entregados,
            // así que filtramos desde obtenerTodos en memoria.
            // Alternativa: usar sp_Ciclos_ObtenerTodos y filtrar.
            try {
                conn->Open();
                SqlDataReader^ reader = cmd->ExecuteReader();
                while (reader->Read()) {
                    String^ resId = reader->GetValue(0)->ToString();
                    if (resId->Equals(id)) {
                        double resHoras = 0.0;
                        Double::TryParse(reader->GetValue(1)->ToString(), resHoras);
                        String^ resEstado = reader->GetValue(2)->ToString();
                        ciclo = gcnew CicloModel(resId, resHoras, resEstado);
                        break;
                    }
                }
                reader->Close();
            }
            catch (Exception^ ex) {
                throw gcnew Exception("Error al buscar ciclo por ID: " + ex->Message);
            }
            finally {
                if (conn->State == ConnectionState::Open) conn->Close();
            }
            return ciclo;
        }

        // ==========================================================
        // READ: OBTENER TODOS
        // ==========================================================
        List<CicloModel^>^ obtenerTodos() {
            List<CicloModel^>^ lista = gcnew List<CicloModel^>();
            SqlConnection^ conn = DBConnection::GetConnection();
            SqlCommand^ cmd = gcnew SqlCommand("sp_Ciclos_ObtenerTodos", conn);
            cmd->CommandType = CommandType::StoredProcedure;

            try {
                conn->Open();
                SqlDataReader^ reader = cmd->ExecuteReader();
                while (reader->Read()) {
                    String^ id = reader->GetValue(0)->ToString();
                    double horas = 0.0;
                    Double::TryParse(reader->GetValue(1)->ToString(), horas);
                    String^ estado = reader->GetValue(2)->ToString();
                    lista->Add(gcnew CicloModel(id, horas, estado));
                }
                reader->Close();
            }
            catch (Exception^ ex) {
                throw gcnew Exception("Error al obtener ciclos: " + ex->Message);
            }
            finally {
                if (conn->State == ConnectionState::Open) conn->Close();
            }
            return lista;
        }

        // ==========================================================
        // READ: SOLO PENDIENTES (filtrado en memoria desde BD)
        // ==========================================================
        List<CicloModel^>^ obtenerPendientes() {
            List<CicloModel^>^ resultado = gcnew List<CicloModel^>();
            for each (CicloModel ^ c in obtenerTodos())
                if (c->Estado->Equals("PENDIENTE"))
                    resultado->Add(c);
            return resultado;
        }

        // ==========================================================
        // UPDATE: MARCAR COMO REPORTADO
        // ==========================================================
        bool marcarReportado(String^ id) {
            return actualizarEstado(id, "REPORTADO");
        }

        bool actualizarEstado(String^ id, String^ nuevoEstado) {
            SqlConnection^ conn = DBConnection::GetConnection();
            SqlCommand^ cmd = gcnew SqlCommand("sp_Ciclos_ActualizarEstado", conn);
            cmd->CommandType = CommandType::StoredProcedure;

            cmd->Parameters->AddWithValue("@Id", id);
            cmd->Parameters->AddWithValue("@Estado", nuevoEstado);

            try {
                conn->Open();
                int filas = cmd->ExecuteNonQuery();
                return (filas > 0);
            }
            catch (Exception^ ex) {
                throw gcnew Exception("Error al actualizar estado de ciclo: " + ex->Message);
            }
            finally {
                if (conn->State == ConnectionState::Open) conn->Close();
            }
        }

        // ==========================================================
        // CICLO ACTIVO (tabla CicloActivo — 1 solo registro)
        // ==========================================================
        static void guardarCicloActivo(String^ sufijo) {
            SqlConnection^ conn = DBConnection::GetConnection();
            SqlCommand^ cmd = gcnew SqlCommand("sp_CicloActivo_Guardar", conn);
            cmd->CommandType = CommandType::StoredProcedure;
            cmd->Parameters->AddWithValue("@Sufijo", sufijo);

            try {
                conn->Open();
                cmd->ExecuteNonQuery();
            }
            catch (Exception^ ex) {
                throw gcnew Exception("Error al guardar ciclo activo: " + ex->Message);
            }
            finally {
                if (conn->State == ConnectionState::Open) conn->Close();
            }
        }

        static String^ obtenerCicloActivo() {
            SqlConnection^ conn = DBConnection::GetConnection();
            SqlCommand^ cmd = gcnew SqlCommand("sp_CicloActivo_Obtener", conn);
            cmd->CommandType = CommandType::StoredProcedure;

            try {
                conn->Open();
                Object^ resultado = cmd->ExecuteScalar();
                if (resultado == nullptr || resultado == DBNull::Value)
                    return nullptr;
                String^ val = resultado->ToString()->Trim();
                return (val->Length == 0) ? nullptr : val;
            }
            catch (Exception^) {
                return nullptr;
            }
            finally {
                if (conn->State == ConnectionState::Open) conn->Close();
            }
        }

        static void limpiarCicloActivo() {
            SqlConnection^ conn = DBConnection::GetConnection();
            SqlCommand^ cmd = gcnew SqlCommand("sp_CicloActivo_Eliminar", conn);
            cmd->CommandType = CommandType::StoredProcedure;

            try {
                conn->Open();
                cmd->ExecuteNonQuery();
            }
            catch (Exception^ ex) {
                throw gcnew Exception("Error al limpiar ciclo activo: " + ex->Message);
            }
            finally {
                if (conn->State == ConnectionState::Open) conn->Close();
            }
        }

        // Compatibilidad — estos métodos ya no hacen nada con archivos
        void guardarArchivo() {}
        void cargarArchivo() {}
    };
}