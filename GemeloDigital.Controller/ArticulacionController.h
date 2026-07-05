#pragma once
#include "DBConnection.h"
using namespace System;
using namespace System::Collections::Generic;
using namespace System::Data;
using namespace System::Data::SqlClient;
using namespace GemeloDigitalModel;

namespace GemeloDigitalController {

    public ref class ArticulacionController {
    public:
        ArticulacionController() {}

        // CREATE — uso principal: seed inicial
        bool agregar(String^ id, String^ nombre, bool activo,
            double anguloActual, double anguloMinimo, double anguloMaximo, String^ brazoId) {
            SqlConnection^ conn = DBConnection::GetConnection();
            SqlCommand^ cmd = gcnew SqlCommand("sp_Articulaciones_Insertar", conn);
            cmd->CommandType = CommandType::StoredProcedure;
            cmd->Parameters->AddWithValue("@Id", id);
            cmd->Parameters->AddWithValue("@Nombre", nombre);
            cmd->Parameters->AddWithValue("@Activo", activo);
            cmd->Parameters->AddWithValue("@AnguloActual", anguloActual);
            cmd->Parameters->AddWithValue("@AnguloMinimo", anguloMinimo);
            cmd->Parameters->AddWithValue("@AnguloMaximo", anguloMaximo);
            cmd->Parameters->AddWithValue("@BrazoId", brazoId);
            try {
                conn->Open();
                cmd->ExecuteNonQuery();
                return true;
            }
            catch (Exception^ ex) {
                throw gcnew Exception("Error al agregar articulacion en SQL: " + ex->Message);
            }
            finally {
                if (conn->State == ConnectionState::Open) conn->Close();
            }
        }

        // READ — todas las articulaciones de un brazo (uso principal: poblar BrazoRoboticoModel)
        List<ArticulacionModel^>^ obtenerPorBrazoId(String^ brazoId) {
            List<ArticulacionModel^>^ lista = gcnew List<ArticulacionModel^>();
            SqlConnection^ conn = DBConnection::GetConnection();
            SqlCommand^ cmd = gcnew SqlCommand("sp_Articulaciones_ObtenerPorBrazo", conn);
            cmd->CommandType = CommandType::StoredProcedure;
            cmd->Parameters->AddWithValue("@BrazoId", brazoId);
            try {
                conn->Open();
                SqlDataReader^ reader = cmd->ExecuteReader();
                while (reader->Read())
                    lista->Add(LeerArticulacion(reader));
                reader->Close();
            }
            catch (Exception^ ex) {
                throw gcnew Exception("Error al obtener articulaciones por brazo: " + ex->Message);
            }
            finally {
                if (conn->State == ConnectionState::Open) conn->Close();
            }
            return lista;
        }

        // READ — por ID
        ArticulacionModel^ buscarPorId(String^ id) {
            ArticulacionModel^ a = nullptr;
            SqlConnection^ conn = DBConnection::GetConnection();
            SqlCommand^ cmd = gcnew SqlCommand("sp_Articulaciones_BuscarPorId", conn);
            cmd->CommandType = CommandType::StoredProcedure;
            cmd->Parameters->AddWithValue("@Id", id);
            try {
                conn->Open();
                SqlDataReader^ reader = cmd->ExecuteReader();
                if (reader->Read()) a = LeerArticulacion(reader);
                reader->Close();
            }
            catch (Exception^ ex) {
                throw gcnew Exception("Error al buscar articulacion por ID: " + ex->Message);
            }
            finally {
                if (conn->State == ConnectionState::Open) conn->Close();
            }
            return a;
        }

        // UPDATE — solo AnguloActual (campo dinamico que avanzan las tareas del Operador)
        // sp usa SET NOCOUNT ON -> no confiar en filasAfectadas, verificar con buscarPorId()
        bool modificar(String^ id, double nuevoAngulo) {
            SqlConnection^ conn = DBConnection::GetConnection();
            SqlCommand^ cmd = gcnew SqlCommand("sp_Articulaciones_ActualizarAngulo", conn);
            cmd->CommandType = CommandType::StoredProcedure;
            cmd->Parameters->AddWithValue("@Id", id);
            cmd->Parameters->AddWithValue("@AnguloActual", nuevoAngulo);
            try {
                conn->Open();
                cmd->ExecuteNonQuery();
            }
            catch (Exception^ ex) {
                throw gcnew Exception("Error al actualizar angulo de articulacion: " + ex->Message);
            }
            finally {
                if (conn->State == ConnectionState::Open) conn->Close();
            }

            ArticulacionModel^ verif = buscarPorId(id);
            return (verif != nullptr && Math::Abs(verif->AnguloActual - nuevoAngulo) < 0.0001);
        }

    private:
        // Lectura blindada de una fila -> ArticulacionModel
        // Columnas: Id(0) Nombre(1) Activo(2) AnguloActual(3) AnguloMinimo(4) AnguloMaximo(5) BrazoId(6)
        ArticulacionModel^ LeerArticulacion(SqlDataReader^ reader) {
            String^ id = reader->GetValue(0)->ToString();
            String^ nombre = reader->GetValue(1)->ToString();

            bool activo = false;
            Object^ valActivo = reader->GetValue(2);
            if (valActivo != nullptr && valActivo != DBNull::Value) {
                String^ s = valActivo->ToString()->ToLower()->Trim();
                activo = (s == "1" || s == "true");
            }

            double anguloActual = 0.0; Double::TryParse(reader->GetValue(3)->ToString(), anguloActual);
            double anguloMinimo = 0.0; Double::TryParse(reader->GetValue(4)->ToString(), anguloMinimo);
            double anguloMaximo = 0.0; Double::TryParse(reader->GetValue(5)->ToString(), anguloMaximo);

            return gcnew ArticulacionModel(id, nombre, activo, anguloActual, anguloMinimo, anguloMaximo);
        }
    };
}