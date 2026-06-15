#pragma once

using namespace System;
using namespace System::Collections::Generic;
using namespace System::Data;
using namespace System::Data::SqlClient;
using namespace GemeloDigitalModel;

namespace GemeloDigitalController {

    public ref class EstructuraTechoController {
    private:
        // Cadena de conexión configurada exactamente con tus datos de AWS RDS
        String^ connectionString = "Server=bdmijael23.cczveeoo8rq2.us-east-1.rds.amazonaws.com,1433;" +
            "Database=bdmijael23;" +
            "User Id=admin;" +
            "Password=abcd1234;";

    public:
        EstructuraTechoController() {
            // No requiere lógica de inicialización para archivos locales .dat
        }

        // ==========================================================
        // 1. CREATE: AGREGAR ESTRUCTURA TECHO (CON ESTADO INICIAL BLINDADO)
        // ==========================================================
        bool agregar(String^ id, String^ material, double peso,
            int puntosUnion, double anchura, String^ estacionId) {

            SqlConnection^ conn = gcnew SqlConnection(connectionString);
            SqlCommand^ cmd = gcnew SqlCommand("sp_EstructurasTecho_Insertar", conn);
            cmd->CommandType = CommandType::StoredProcedure;

            // Mapeo de parámetros para el SP
            cmd->Parameters->AddWithValue("@Id", id);
            cmd->Parameters->AddWithValue("@Material", material);
            cmd->Parameters->AddWithValue("@Peso", peso);
            cmd->Parameters->AddWithValue("@PuntosUnion", puntosUnion);
            cmd->Parameters->AddWithValue("@Anchura", anchura);
            cmd->Parameters->AddWithValue("@EstacionId", estacionId);

            // Inyectamos el estado por defecto (0 = DISPONIBLE) requerido por tu SP en la base de datos
            cmd->Parameters->AddWithValue("@Estado", static_cast<int>(EstadoPieza::DISPONIBLE));

            try {
                conn->Open();
                cmd->ExecuteNonQuery();
                return true;
            }
            catch (Exception^ ex) {
                throw gcnew Exception("Error al agregar estructura techo en SQL: " + ex->Message);
                return false;
            }
            finally {
                if (conn->State == ConnectionState::Open) conn->Close();
            }
        }

        // ==========================================================
        // 2. READ: BUSCAR POR ID (BLINDADO CON PARSE SEGURO)
        // ==========================================================
        EstructuraTechoModel^ buscarPorId(String^ id) {
            EstructuraTechoModel^ techo = nullptr;
            SqlConnection^ conn = gcnew SqlConnection(connectionString);
            SqlCommand^ cmd = gcnew SqlCommand("sp_EstructurasTecho_BuscarPorId", conn);
            cmd->CommandType = CommandType::StoredProcedure;

            cmd->Parameters->AddWithValue("@Id", id);

            try {
                conn->Open();
                SqlDataReader^ reader = cmd->ExecuteReader();

                if (reader->Read()) {
                    String^ resId = reader->GetValue(0)->ToString();
                    String^ resMaterial = reader->GetValue(1)->ToString();

                    // Lectura segura de Peso (Double)
                    double resPeso = 0.0;
                    Double::TryParse(reader->GetValue(2)->ToString(), resPeso);

                    // Lectura segura de PuntosUnion (Int)
                    int resPuntosUnion = 0;
                    Int32::TryParse(reader->GetValue(4)->ToString(), resPuntosUnion);

                    // Lectura segura de Anchura (Double)
                    double resAnchura = 0.0;
                    Double::TryParse(reader->GetValue(5)->ToString(), resAnchura);

                    String^ resEstacionId = reader->GetValue(6)->ToString();

                    // Instanciar el modelo con su constructor base
                    techo = gcnew EstructuraTechoModel(resId, resMaterial, resPeso, resPuntosUnion, resAnchura, resEstacionId);

                    // Leer Estado de forma segura (Enum EstadoPieza)
                    EstadoPieza resEstado = EstadoPieza::DISPONIBLE;
                    int estadoInt;
                    if (Int32::TryParse(reader->GetValue(3)->ToString(), estadoInt)) {
                        resEstado = static_cast<EstadoPieza>(estadoInt);
                    }
                    techo->Estado = resEstado;
                }
                reader->Close();
            }
            catch (Exception^ ex) {
                throw gcnew Exception("Error al buscar estructura techo por ID: " + ex->Message);
            }
            finally {
                if (conn->State == ConnectionState::Open) conn->Close();
            }
            return techo;
        }

        // ==========================================================
        // 3. READ: OBTENER TODOS LOS TECHOS (TOTALMENTE BLINDADO)
        // ==========================================================
        List<EstructuraTechoModel^>^ obtenerTodos() {
            List<EstructuraTechoModel^>^ lista = gcnew List<EstructuraTechoModel^>();
            SqlConnection^ conn = gcnew SqlConnection(connectionString);
            SqlCommand^ cmd = gcnew SqlCommand("sp_EstructurasTecho_ObtenerTodos", conn);
            cmd->CommandType = CommandType::StoredProcedure;

            try {
                conn->Open();
                SqlDataReader^ reader = cmd->ExecuteReader();

                while (reader->Read()) {
                    String^ id = reader->GetValue(0)->ToString();
                    String^ material = reader->GetValue(1)->ToString();

                    // Extracción genérica por .ToString() y conversión robusta
                    double peso = 0.0;
                    Double::TryParse(reader->GetValue(2)->ToString(), peso);

                    int puntosUnion = 0;
                    Int32::TryParse(reader->GetValue(4)->ToString(), puntosUnion);

                    double anchura = 0.0;
                    Double::TryParse(reader->GetValue(5)->ToString(), anchura);

                    String^ estacionId = reader->GetValue(6)->ToString();

                    EstructuraTechoModel^ techo = gcnew EstructuraTechoModel(id, material, peso, puntosUnion, anchura, estacionId);

                    // Conversión ultra-segura del Enum EstadoPieza
                    EstadoPieza estado = EstadoPieza::DISPONIBLE;
                    int estadoInt;
                    if (Int32::TryParse(reader->GetValue(3)->ToString(), estadoInt)) {
                        estado = static_cast<EstadoPieza>(estadoInt);
                    }
                    techo->Estado = estado;

                    lista->Add(techo);
                }
                reader->Close();
            }
            catch (Exception^ ex) {
                throw gcnew Exception("Error al obtener estructuras de techo desde SQL: " + ex->Message);
            }
            finally {
                if (conn->State == ConnectionState::Open) conn->Close();
            }
            return lista;
        }

        // ==========================================================
        // 4. UPDATE: MODIFICAR ESTRUCTURA TECHO (CORREGIDO Y LIMPIO)
        // ==========================================================
        bool modificar(String^ id, String^ material, double peso,
            EstadoPieza estado, int puntosUnion, double anchura, String^ estacionId) {

            SqlConnection^ conn = gcnew SqlConnection(connectionString);
            // Corregido directamente el nombre del Stored Procedure para evitar el try-catch anidado
            SqlCommand^ cmd = gcnew SqlCommand("sp_EstructurasTecho_Modificar", conn);
            cmd->CommandType = CommandType::StoredProcedure;

            cmd->Parameters->AddWithValue("@Id", id);
            cmd->Parameters->AddWithValue("@Material", material);
            cmd->Parameters->AddWithValue("@Peso", peso);
            cmd->Parameters->AddWithValue("@Estado", static_cast<int>(estado)); // Enum EstadoPieza como INT
            cmd->Parameters->AddWithValue("@PuntosUnion", puntosUnion);
            cmd->Parameters->AddWithValue("@Anchura", anchura);
            cmd->Parameters->AddWithValue("@EstacionId", estacionId);

            try {
                conn->Open();
                int filasAfectadas = cmd->ExecuteNonQuery();
                return (filasAfectadas > 0);
            }
            catch (Exception^ ex) {
                throw gcnew Exception("Error al modificar estructura techo en SQL: " + ex->Message);
                return false;
            }
            finally {
                if (conn->State == ConnectionState::Open) conn->Close();
            }
        }

        // ==========================================================
        // 5. DELETE: ELIMINAR ESTRUCTURA TECHO
        // ==========================================================
        bool eliminar(String^ id) {
            SqlConnection^ conn = gcnew SqlConnection(connectionString);
            SqlCommand^ cmd = gcnew SqlCommand("sp_EstructurasTecho_Eliminar", conn);
            cmd->CommandType = CommandType::StoredProcedure;

            cmd->Parameters->AddWithValue("@Id", id);

            try {
                conn->Open();
                int filasAfectadas = cmd->ExecuteNonQuery();
                return (filasAfectadas > 0);
            }
            catch (Exception^ ex) {
                throw gcnew Exception("Error al eliminar estructura techo en SQL: " + ex->Message);
                return false;
            }
            finally {
                if (conn->State == ConnectionState::Open) conn->Close();
            }
        }
    };
}