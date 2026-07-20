#pragma once
#include "DBConnection.h" 

using namespace System;
using namespace System::Collections::Generic;
using namespace System::Data;
using namespace System::Data::SqlClient;
using namespace GemeloDigitalModel;
//pedro
namespace GemeloDigitalController {

    public ref class AdministradorController {
    public:
        AdministradorController() {}

        // CREATE — ahora lee el Id real generado por el SP
        bool agregar(String^ id, String^ nombre, String^ contrasena, int nivelAcceso, String^ turno) {
            // REMOVIDO: buscarPorId(id) — era inútil porque id era un GUID temporal.
            // El SP ahora detecta duplicados por Usuario y devuelve @NuevoId = NULL si ya existe.

            SqlConnection^ conn = DBConnection::GetConnection();
            try {
                conn->Open();
                SqlCommand^ cmd = gcnew SqlCommand("sp_Usuarios_Insertar", conn);
                cmd->CommandType = CommandType::StoredProcedure;

                cmd->Parameters->AddWithValue("@Id", id);           // el SP lo ignora, pero evita error de parámetro faltante
                cmd->Parameters->AddWithValue("@Nombre", nombre);
                cmd->Parameters->AddWithValue("@Usuario", nombre);  // igual que antes
                cmd->Parameters->AddWithValue("@Contrasena", String::IsNullOrEmpty(contrasena) ? "" : contrasena);
                cmd->Parameters->AddWithValue("@NivelAcceso", nivelAcceso.ToString());
                cmd->Parameters->AddWithValue("@Turno", turno);

                // Parámetro OUTPUT para recibir el Id real generado
                SqlParameter^ paramNuevoId = gcnew SqlParameter("@NuevoId", SqlDbType::VarChar, 50);
                paramNuevoId->Direction = ParameterDirection::Output;
                cmd->Parameters->Add(paramNuevoId);

                cmd->ExecuteNonQuery();

                // Si el SP devolvió NULL → duplicado de usuario
                if (paramNuevoId->Value == DBNull::Value || paramNuevoId->Value == nullptr)
                    return false;

                // idGenerado contiene el U001/U002 real por si el Form lo necesita en el futuro
                String^ idGenerado = paramNuevoId->Value->ToString();
                return true;
            }
            catch (Exception^ ex) {
                throw gcnew Exception("Error al insertar en BD: " + ex->Message);
            }
            finally {
                if (conn->State == ConnectionState::Open) conn->Close();
            }
        }

        // READ - por ID (CON LECTURA BLINDADA)
        AdministradorModel^ buscarPorId(String^ id) {
            SqlConnection^ conn = DBConnection::GetConnection();
            AdministradorModel^ admin = nullptr;
            try {
                conn->Open();
                SqlCommand^ cmd = gcnew SqlCommand("sp_Usuarios_BuscarPorId", conn);
                cmd->CommandType = CommandType::StoredProcedure;
                cmd->Parameters->AddWithValue("@Id", id);

                SqlDataReader^ reader = cmd->ExecuteReader();
                if (reader->Read()) {
                    String^ dbId = reader->GetValue(0)->ToString();
                    String^ dbNombre = reader->GetValue(1)->ToString();
                    String^ dbContrasena = reader->GetValue(3)->ToString();

                    // BLINDAJE: Conversión segura sin importar si en SQL es INT o VARCHAR
                    int dbNivel = 0;
                    Int32::TryParse(reader->GetValue(4)->ToString(), dbNivel);

                    String^ dbTurno = reader->IsDBNull(5) ? "" : reader->GetValue(5)->ToString();

                    admin = gcnew AdministradorModel(dbId, dbNombre, dbContrasena, dbNivel, dbTurno);
                }
                reader->Close();
            }
            catch (Exception^ ex) {
                throw gcnew Exception("Error de conexión al buscar ID: " + ex->Message);
            }
            finally {
                if (conn->State == ConnectionState::Open) conn->Close();
            }
            return admin;
        }

        // READ - todos (CON LECTURA BLINDADA)
        List<AdministradorModel^>^ obtenerTodos() {
            SqlConnection^ conn = DBConnection::GetConnection();
            List<AdministradorModel^>^ lista = gcnew List<AdministradorModel^>();
            try {
                conn->Open();
                SqlCommand^ cmd = gcnew SqlCommand("sp_Usuarios_ObtenerTodos", conn);
                cmd->CommandType = CommandType::StoredProcedure;

                SqlDataReader^ reader = cmd->ExecuteReader();
                while (reader->Read()) {
                    String^ dbId = reader->GetValue(0)->ToString();
                    String^ dbNombre = reader->GetValue(1)->ToString();
                    String^ dbContrasena = reader->GetValue(3)->ToString();

                    // BLINDAJE: Conversión segura sin importar si en SQL es INT o VARCHAR
                    int dbNivel = 0;
                    Int32::TryParse(reader->GetValue(4)->ToString(), dbNivel);

                    String^ dbTurno = reader->IsDBNull(5) ? "" : reader->GetValue(5)->ToString();

                    lista->Add(gcnew AdministradorModel(dbId, dbNombre, dbContrasena, dbNivel, dbTurno));
                }
                reader->Close();
            }
            catch (Exception^ ex) {
                throw gcnew Exception("Error al obtener todos: " + ex->Message);
            }
            finally {
                if (conn->State == ConnectionState::Open) conn->Close();
            }
            return lista;
        }

        // UPDATE
        bool modificar(String^ id, String^ nombre, String^ contrasena, int nivelAcceso, String^ turno) {
            SqlConnection^ conn = DBConnection::GetConnection();
            try {
                conn->Open();
                SqlCommand^ cmd = gcnew SqlCommand("sp_Usuarios_Modificar", conn);
                cmd->CommandType = CommandType::StoredProcedure;

                cmd->Parameters->AddWithValue("@Id", id);
                cmd->Parameters->AddWithValue("@Nombre", nombre);
                cmd->Parameters->AddWithValue("@Usuario", nombre);
                cmd->Parameters->AddWithValue("@Contrasena", String::IsNullOrEmpty(contrasena) ? "" : contrasena);
                cmd->Parameters->AddWithValue("@NivelAcceso", nivelAcceso.ToString());
                cmd->Parameters->AddWithValue("@Turno", turno);

                cmd->ExecuteNonQuery();
                return true;
            }
            catch (Exception^ ex) {
                throw gcnew Exception("Error al modificar: " + ex->Message);
            }
            finally {
                if (conn->State == ConnectionState::Open) conn->Close();
            }
        }

        // DELETE
        bool eliminar(String^ id) {
            SqlConnection^ conn = DBConnection::GetConnection();
            try {
                conn->Open();
                SqlCommand^ cmd = gcnew SqlCommand("sp_Usuarios_Eliminar", conn);
                cmd->CommandType = CommandType::StoredProcedure;
                cmd->Parameters->AddWithValue("@Id", id);

                cmd->ExecuteNonQuery();
                return true;
            }
            catch (Exception^ ex) {
                throw gcnew Exception("Error al eliminar: " + ex->Message);
            }
            finally {
                if (conn->State == ConnectionState::Open) conn->Close();
            }
        }
    };
}