#pragma once
#include "DBConnection.h"

using namespace System;
using namespace System::Collections::Generic;
using namespace System::Data;
using namespace System::Data::SqlClient;
using namespace GemeloDigitalModel;

namespace GemeloDigitalController {

    public ref class EventoTareaController {
    public:
        EventoTareaController() {}

        // ==========================================================
        // CREATE: INSERTAR EVENTO DE TAREA (historial, solo INSERT)
        // SP: sp_EventosTarea_Insertar(@Id, @Timestamp, @Descripcion,
        //     @TareaId, @Resultado)
        // ==========================================================
        bool agregar(String^ id, String^ timestamp, String^ descripcion,
            String^ tareaId, String^ resultado) {

            // No bloqueamos duplicados — es un historial (append-only)
            SqlConnection^ conn = DBConnection::GetConnection();
            SqlCommand^ cmd = gcnew SqlCommand("sp_EventosTarea_Insertar", conn);
            cmd->CommandType = CommandType::StoredProcedure;

            cmd->Parameters->AddWithValue("@Id", id);
            cmd->Parameters->AddWithValue("@Timestamp", timestamp);
            cmd->Parameters->AddWithValue("@Descripcion", descripcion);
            cmd->Parameters->AddWithValue("@TareaId", tareaId);
            cmd->Parameters->AddWithValue("@Resultado", resultado);

            try {
                conn->Open();
                cmd->ExecuteNonQuery();
                return true;
            }
            catch (Exception^ ex) {
                throw gcnew Exception("Error al registrar evento de tarea: " + ex->Message);
            }
            finally {
                if (conn->State == ConnectionState::Open) conn->Close();
            }
        }

        // ==========================================================
        // READ: BUSCAR POR ID (filtrado en memoria)
        // ==========================================================
        EventoTareaModel^ buscarPorId(String^ id) {
            for each (EventoTareaModel ^ e in obtenerTodos())
                if (e->Id->Equals(id)) return e;
            return nullptr;
        }

        // ==========================================================
        // READ: OBTENER TODOS (historial completo)
        // ==========================================================
        List<EventoTareaModel^>^ obtenerTodos() {
            List<EventoTareaModel^>^ lista = gcnew List<EventoTareaModel^>();
            SqlConnection^ conn = DBConnection::GetConnection();
            SqlCommand^ cmd = gcnew SqlCommand("sp_EventosTarea_ObtenerTodos", conn);
            cmd->CommandType = CommandType::StoredProcedure;

            try {
                conn->Open();
                SqlDataReader^ reader = cmd->ExecuteReader();
                while (reader->Read()) {
                    String^ id = reader->GetValue(0)->ToString();
                    String^ timestamp = reader->GetValue(1)->ToString();
                    String^ descripcion = reader->GetValue(2)->ToString();
                    String^ tareaId = reader->GetValue(3)->ToString();
                    String^ resultado = reader->GetValue(4)->ToString();
                    lista->Add(gcnew EventoTareaModel(id, timestamp, descripcion, tareaId, resultado));
                }
                reader->Close();
            }
            catch (Exception^ ex) {
                throw gcnew Exception("Error al obtener eventos de tarea: " + ex->Message);
            }
            finally {
                if (conn->State == ConnectionState::Open) conn->Close();
            }
            return lista;
        }

        // EventosTarea es solo INSERT y SELECT — no se modifica ni elimina
        void guardarArchivo() {}
        void cargarArchivo() {}
    };
}