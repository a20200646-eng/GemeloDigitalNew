#pragma once

using namespace System;
using namespace System::Collections::Generic;
using namespace System::Data;
using namespace System::Data::SqlClient;
using namespace GemeloDigitalModel;

namespace GemeloDigitalController {

    public ref class GestorInventarioController {
    private:
        String^ connectionString;

    public:
        GestorInventarioController() {
            connectionString = "Server=bdmijael23.cczveeoo8rq2.us-east-1.rds.amazonaws.com,1433;" +
                "Database=bdmijael23;" +
                "User Id=admin;" +
                "Password=abcd1234;";
        }

        void cargarArchivo() {}

        // ==========================================================
        // 1. CREATE: AGREGAR GESTOR (Ajustado a las columnas reales)
        // ==========================================================
        bool agregar(String^ id, String^ nombre, String^ contrasena) {
            if (buscarPorId(id) != nullptr) return false;

            SqlConnection^ conn = gcnew SqlConnection(connectionString);
            // Insertamos usando las columnas reales descubiertas: Usuario y [Contraseña]
            String^ query = "INSERT INTO Usuarios (Id, Nombre, Usuario, [Contraseña], NivelAcceso, Turno) " +
                "VALUES (@Id, @Nombre, @Usuario, @Contrasena, 2, 'Mañana');";
            SqlCommand^ cmd = gcnew SqlCommand(query, conn);

            cmd->Parameters->AddWithValue("@Id", id);
            cmd->Parameters->AddWithValue("@Nombre", nombre);
            cmd->Parameters->AddWithValue("@Usuario", id); // Usamos el ID como nombre de usuario por defecto
            cmd->Parameters->AddWithValue("@Contrasena", String::IsNullOrEmpty(contrasena) ? "" : contrasena);

            try {
                conn->Open();
                cmd->ExecuteNonQuery();
                return true;
            }
            catch (Exception^ ex) {
                throw gcnew Exception("Error al agregar gestor en SQL: " + ex->Message);
            }
            finally {
                if (conn->State == ConnectionState::Open) conn->Close();
            }
        }

        // ==========================================================
        // 2. READ: BUSCAR GESTOR POR ID (Mapeo Blindado con tu SP)
        // ==========================================================
        GestorInventarioModel^ buscarPorId(String^ id) {
            GestorInventarioModel^ gestor = nullptr;
            SqlConnection^ conn = gcnew SqlConnection(connectionString);
            SqlCommand^ cmd = gcnew SqlCommand("sp_Usuarios_BuscarPorId", conn);
            cmd->CommandType = CommandType::StoredProcedure;
            cmd->Parameters->AddWithValue("@Id", id);

            try {
                conn->Open();
                SqlDataReader^ reader = cmd->ExecuteReader();

                if (reader->Read()) {
                    String^ dbId = reader->GetValue(0)->ToString();
                    String^ dbNombre = reader->GetValue(1)->ToString();

                    // El SP original devuelve la contraseña en la posición 3 según el orden de tu tabla
                    String^ dbContrasena = reader->GetValue(3)->ToString();

                    gestor = gcnew GestorInventarioModel(dbId, dbNombre, dbContrasena);
                    // Mantenemos la propiedad del modelo en 0 ya que la BD no guarda este contador
                    gestor->TotalPiezasGestionadas = 0;
                }
                reader->Close();
            }
            catch (Exception^ ex) {
                throw gcnew Exception("Error al buscar gestor en SQL: " + ex->Message);
            }
            finally {
                if (conn->State == ConnectionState::Open) conn->Close();
            }
            return gestor;
        }

        // ==========================================================
        // 3. READ: OBTENER TODOS LOS GESTORES
        // ==========================================================
        List<GestorInventarioModel^>^ obtenerTodos() {
            List<GestorInventarioModel^>^ lista = gcnew List<GestorInventarioModel^>();
            SqlConnection^ conn = gcnew SqlConnection(connectionString);
            String^ query = "SELECT Id, Nombre, [Contraseña] FROM Usuarios WHERE NivelAcceso = 2;";
            SqlCommand^ cmd = gcnew SqlCommand(query, conn);

            try {
                conn->Open();
                SqlDataReader^ reader = cmd->ExecuteReader();

                while (reader->Read()) {
                    String^ dbId = reader->GetValue(0)->ToString();
                    String^ dbNombre = reader->GetValue(1)->ToString();
                    String^ dbContrasena = reader->GetValue(2)->ToString();

                    GestorInventarioModel^ g = gcnew GestorInventarioModel(dbId, dbNombre, dbContrasena);
                    g->TotalPiezasGestionadas = 0;
                    lista->Add(g);
                }
                reader->Close();
            }
            catch (Exception^ ex) {
                throw gcnew Exception("Error al obtener la lista de gestores: " + ex->Message);
            }
            finally {
                if (conn->State == ConnectionState::Open) conn->Close();
            }
            return lista;
        }

        // ==========================================================
        // 4. UPDATE: MODIFICAR GESTOR
        // ==========================================================
        bool modificar(String^ id, String^ nombre, String^ contrasena, int totalPiezasGestionadas) {
            SqlConnection^ conn = gcnew SqlConnection(connectionString);
            String^ query = "UPDATE Usuarios SET Nombre = @Nombre, [Contraseña] = @Contrasena WHERE Id = @Id;";
            SqlCommand^ cmd = gcnew SqlCommand(query, conn);

            cmd->Parameters->AddWithValue("@Id", id);
            cmd->Parameters->AddWithValue("@Nombre", nombre);
            cmd->Parameters->AddWithValue("@Contrasena", String::IsNullOrEmpty(contrasena) ? "" : contrasena);

            try {
                conn->Open();
                int filasAfectadas = cmd->ExecuteNonQuery();
                return (filasAfectadas > 0);
            }
            catch (Exception^ ex) {
                throw gcnew Exception("Error al modificar el gestor en SQL: " + ex->Message);
            }
            finally {
                if (conn->State == ConnectionState::Open) conn->Close();
            }
        }

        // ==========================================================
        // 5. DELETE: ELIMINAR GESTOR
        // ==========================================================
        bool eliminar(String^ id) {
            SqlConnection^ conn = gcnew SqlConnection(connectionString);
            SqlCommand^ cmd = gcnew SqlCommand("sp_Usuarios_Eliminar", conn);
            cmd->CommandType = CommandType::StoredProcedure;
            cmd->Parameters->AddWithValue("@Id", id);

            try {
                conn->Open();
                int filasAfectadas = cmd->ExecuteNonQuery();
                return (filasAfectadas > 0);
            }
            catch (Exception^ ex) {
                throw gcnew Exception("Error al eliminar gestor en SQL: " + ex->Message);
            }
            finally {
                if (conn->State == ConnectionState::Open) conn->Close();
            }
        }
    };
}