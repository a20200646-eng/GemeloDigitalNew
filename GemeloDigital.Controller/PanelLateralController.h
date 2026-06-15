#pragma once

using namespace System;
using namespace System::Collections::Generic;
using namespace System::Data;
using namespace System::Data::SqlClient;
using namespace GemeloDigitalModel;

namespace GemeloDigitalController {

    public ref class PanelLateralController {
    private:
        String^ connectionString = "Server=bdmijael23.cczveeoo8rq2.us-east-1.rds.amazonaws.com,1433;" +
            "Database=bdmijael23;" +
            "User Id=admin;" +
            "Password=abcd1234;";

    public:
        PanelLateralController() {}

        // ==========================================================
        // 1. CREATE: AGREGAR PANEL LATERAL
        // ==========================================================
        bool agregar(String^ id, String^ material, double peso, LadoPanel lado,
            int puntosAnclaje, String^ estacionId) {

            SqlConnection^ conn = gcnew SqlConnection(connectionString);
            SqlCommand^ cmd = gcnew SqlCommand("sp_PanelesLaterales_Insertar", conn);
            cmd->CommandType = CommandType::StoredProcedure;

            cmd->Parameters->AddWithValue("@Id", id);
            cmd->Parameters->AddWithValue("@Material", material);
            cmd->Parameters->AddWithValue("@Peso", peso);
            cmd->Parameters->AddWithValue("@Lado", static_cast<int>(lado));
            cmd->Parameters->AddWithValue("@PuntosAnclaje", puntosAnclaje);
            cmd->Parameters->AddWithValue("@EstacionId", estacionId);
            cmd->Parameters->AddWithValue("@Estado", static_cast<int>(EstadoPieza::DISPONIBLE));

            try {
                conn->Open();
                cmd->ExecuteNonQuery();
                return true;
            }
            catch (Exception^ ex) {
                throw gcnew Exception("Error al agregar panel lateral en SQL: " + ex->Message);
                return false;
            }
            finally {
                if (conn->State == ConnectionState::Open) conn->Close();
            }
        }

        // ==========================================================
        // 2. READ: BUSCAR POR ID (TOTALMENTE BLINDADO CONTRA TIPOS SQL)
        // ==========================================================
        PanelLateralModel^ buscarPorId(String^ id) {
            PanelLateralModel^ panel = nullptr;
            SqlConnection^ conn = gcnew SqlConnection(connectionString);
            SqlCommand^ cmd = gcnew SqlCommand("sp_PanelesLaterales_BuscarPorId", conn);
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

                    // Lectura segura de PuntosAnclaje (Int)
                    int resAnclaje = 0;
                    Int32::TryParse(reader->GetValue(5)->ToString(), resAnclaje);

                    String^ resEstacionId = reader->GetValue(6)->ToString();

                    // Leer Lado de forma segura (Enum LadoPanel)
                    LadoPanel resLado = LadoPanel::IZQUIERDO;
                    int ladoInt;
                    if (Int32::TryParse(reader->GetValue(4)->ToString(), ladoInt)) {
                        resLado = static_cast<LadoPanel>(ladoInt);
                    }

                    // Instanciar modelo
                    panel = gcnew PanelLateralModel(resId, resMaterial, resPeso, resLado, resAnclaje, resEstacionId);

                    // Leer Estado de forma segura (Enum EstadoPieza)
                    EstadoPieza resEstado = EstadoPieza::DISPONIBLE;
                    int estadoInt;
                    if (Int32::TryParse(reader->GetValue(3)->ToString(), estadoInt)) {
                        resEstado = static_cast<EstadoPieza>(estadoInt);
                    }
                    panel->Estado = resEstado;
                }
                reader->Close();
            }
            catch (Exception^ ex) {
                throw gcnew Exception("Error al buscar panel lateral por ID: " + ex->Message);
            }
            finally {
                if (conn->State == ConnectionState::Open) conn->Close();
            }
            return panel;
        }

        // ==========================================================
        // 3. READ: OBTENER TODOS LOS PANELES (TOTALMENTE BLINDADO)
        // ==========================================================
        List<PanelLateralModel^>^ obtenerTodos() {
            List<PanelLateralModel^>^ lista = gcnew List<PanelLateralModel^>();
            SqlConnection^ conn = gcnew SqlConnection(connectionString);
            SqlCommand^ cmd = gcnew SqlCommand("sp_PanelesLaterales_ObtenerTodos", conn);
            cmd->CommandType = CommandType::StoredProcedure;

            try {
                conn->Open();
                SqlDataReader^ reader = cmd->ExecuteReader();

                while (reader->Read()) {
                    // Extraemos los valores de forma genérica y segura usando .ToString()
                    String^ id = reader->GetValue(0)->ToString();
                    String^ material = reader->GetValue(1)->ToString();

                    // Conversión ultra-segura para el Peso (Double) sin importar el tipo en SQL
                    double peso = 0.0;
                    Double::TryParse(reader->GetValue(2)->ToString(), peso);

                    // Conversión ultra-segura para Puntos de Anclaje (Int)
                    int puntosAnclaje = 0;
                    Int32::TryParse(reader->GetValue(5)->ToString(), puntosAnclaje);

                    String^ estacionId = reader->GetValue(6)->ToString();

                    // Conversión ultra-segura para el Enum LadoPanel
                    LadoPanel lado = LadoPanel::IZQUIERDO;
                    int ladoInt;
                    if (Int32::TryParse(reader->GetValue(4)->ToString(), ladoInt)) {
                        lado = static_cast<LadoPanel>(ladoInt);
                    }

                    // Creamos el objeto con los datos base
                    PanelLateralModel^ panel = gcnew PanelLateralModel(id, material, peso, lado, puntosAnclaje, estacionId);

                    // Conversión ultra-segura para el Enum EstadoPieza
                    EstadoPieza estado = EstadoPieza::DISPONIBLE;
                    int estadoInt;
                    if (Int32::TryParse(reader->GetValue(3)->ToString(), estadoInt)) {
                        estado = static_cast<EstadoPieza>(estadoInt);
                    }
                    panel->Estado = estado;

                    lista->Add(panel);
                }
                reader->Close();
            }
            catch (Exception^ ex) {
                throw gcnew Exception("Error al obtener paneles laterales desde SQL: " + ex->Message);
            }
            finally {
                if (conn->State == ConnectionState::Open) conn->Close();
            }
            return lista;
        }

        // ==========================================================
        // 4. UPDATE: MODIFICAR PANEL LATERAL
        // ==========================================================
        bool modificar(String^ id, String^ material, double peso,
            EstadoPieza estado, int puntosAnclaje, String^ estacionId) {

            PanelLateralModel^ panelExistente = buscarPorId(id);
            int ladoOriginal = 0;
            if (panelExistente != nullptr) {
                ladoOriginal = static_cast<int>(panelExistente->Lado);
            }

            SqlConnection^ conn = gcnew SqlConnection(connectionString);
            SqlCommand^ cmd = gcnew SqlCommand("sp_PanelesLaterales_Modificar", conn);
            cmd->CommandType = CommandType::StoredProcedure;

            cmd->Parameters->AddWithValue("@Id", id);
            cmd->Parameters->AddWithValue("@Material", material);
            cmd->Parameters->AddWithValue("@Peso", peso);
            cmd->Parameters->AddWithValue("@Estado", static_cast<int>(estado));
            cmd->Parameters->AddWithValue("@PuntosAnclaje", puntosAnclaje);
            cmd->Parameters->AddWithValue("@EstacionId", estacionId);
            cmd->Parameters->AddWithValue("@Lado", ladoOriginal);

            try {
                conn->Open();
                int filasAfectadas = cmd->ExecuteNonQuery();
                return (filasAfectadas > 0);
            }
            catch (Exception^ ex) {
                throw gcnew Exception("Error al modificar panel lateral en SQL: " + ex->Message);
                return false;
            }
            finally {
                if (conn->State == ConnectionState::Open) conn->Close();
            }
        }

        // ==========================================================
        // 5. DELETE: ELIMINAR PANEL LATERAL
        // ==========================================================
        bool eliminar(String^ id) {
            SqlConnection^ conn = gcnew SqlConnection(connectionString);
            SqlCommand^ cmd = gcnew SqlCommand("sp_PanelesLaterales_Eliminar", conn);
            cmd->CommandType = CommandType::StoredProcedure;

            cmd->Parameters->AddWithValue("@Id", id);

            try {
                conn->Open();
                int filasAfectadas = cmd->ExecuteNonQuery();
                return (filasAfectadas > 0);
            }
            catch (Exception^ ex) {
                throw gcnew Exception("Error al eliminar panel lateral en SQL: " + ex->Message);
                return false;
            }
            finally {
                if (conn->State == ConnectionState::Open) conn->Close();
            }
        }
    };
}