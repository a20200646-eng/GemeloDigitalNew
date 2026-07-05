#pragma once

using namespace System;
using namespace System::Collections::Generic;
using namespace System::Data;
using namespace System::Data::SqlClient;
using namespace GemeloDigitalModel;

namespace GemeloDigitalController {

    public ref class EstacionTrabajoController {
    private:
       
    public:
        EstacionTrabajoController() {
            // No requiere lógica de inicialización para archivos locales
        }

        // ==========================================================
        // 1. CREATE: AGREGAR ESTACIÓN DE TRABAJO
        // ==========================================================
        bool agregar(String^ id, TipoEstacion tipo, int cantidadPiezas) {
            SqlConnection^ conn = DBConnection::GetConnection();
            SqlCommand^ cmd = gcnew SqlCommand("sp_EstacionesTrabajo_Insertar", conn);
            cmd->CommandType = CommandType::StoredProcedure;

            cmd->Parameters->AddWithValue("@Id", id);
            cmd->Parameters->AddWithValue("@Tipo", static_cast<int>(tipo));
            cmd->Parameters->AddWithValue("@CantidadPiezas", cantidadPiezas);

            try {
                conn->Open();
                cmd->ExecuteNonQuery();
                return true;
            }
            catch (Exception^ ex) {
                throw gcnew Exception("Error al agregar estación en SQL: " + ex->Message);
                return false;
            }
            finally {
                if (conn->State == ConnectionState::Open) conn->Close();
            }
        }

        // ==========================================================
        // 2. READ: BUSCAR POR ID (CORREGIDO Y BLINDADO)
        // ==========================================================
        EstacionTrabajoModel^ buscarPorId(String^ id) {
            EstacionTrabajoModel^ estacion = nullptr;
            SqlConnection^ conn = DBConnection::GetConnection();
            SqlCommand^ cmd = gcnew SqlCommand("sp_EstacionesTrabajo_BuscarPorId", conn);
            cmd->CommandType = CommandType::StoredProcedure;

            cmd->Parameters->AddWithValue("@Id", id);

            try {
                conn->Open();
                SqlDataReader^ reader = cmd->ExecuteReader();

                if (reader->Read()) {
                    String^ resId = reader->GetString(0);

                    // --- LEER TIPO DE FORMA SEGURA (EVITA COLGADAS) ---
                    TipoEstacion resTipo = TipoEstacion::PANEL_IZQ; // Valor por defecto en caso falle
                    Object^ objTipo = reader->GetValue(1);
                    if (objTipo != nullptr && objTipo != DBNull::Value) {
                        int tipoInt;
                        if (Int32::TryParse(objTipo->ToString(), tipoInt)) {
                            resTipo = static_cast<TipoEstacion>(tipoInt);
                        }
                        else {
                            try {
                                resTipo = static_cast<TipoEstacion>(Enum::Parse(TipoEstacion::typeid, objTipo->ToString()));
                            }
                            catch (Exception^) {}
                        }
                    }

                    int resCantidad = reader->GetInt32(2);
                    estacion = gcnew EstacionTrabajoModel(resId, resTipo, resCantidad);
                }
                reader->Close();
            }
            catch (Exception^ ex) {
                throw gcnew Exception("Error al buscar estación por ID: " + ex->Message);
            }
            finally {
                if (conn->State == ConnectionState::Open) conn->Close();
            }
            return estacion;
        }

        // ==========================================================
        // 3. READ: BUSCAR POR TIPO (Primera con stock libre)
        // ==========================================================
        EstacionTrabajoModel^ buscarPorTipo(TipoEstacion tipo) {
            List<EstacionTrabajoModel^>^ lista = obtenerTodos();
            for each (EstacionTrabajoModel ^ e in lista) {
                if (e->Tipo == tipo && e->CantidadPiezas > 0) {
                    return e;
                }
            }
            return nullptr;
        }

        // ==========================================================
        // 4. READ: OBTENER TODAS LAS ESTACIONES (CORREGIDO Y BLINDADO)
        // ==========================================================
        List<EstacionTrabajoModel^>^ obtenerTodos() {
            List<EstacionTrabajoModel^>^ lista = gcnew List<EstacionTrabajoModel^>();
            SqlConnection^ conn = DBConnection::GetConnection();
            SqlCommand^ cmd = gcnew SqlCommand("sp_EstacionesTrabajo_ObtenerTodos", conn);
            cmd->CommandType = CommandType::StoredProcedure;

            try {
                conn->Open();
                SqlDataReader^ reader = cmd->ExecuteReader();

                while (reader->Read()) {
                    String^ id = reader->GetString(0);

                    // --- LEER TIPO DE FORMA SEGURA PARA EVITAR INVALIDCAST ---
                    TipoEstacion tipo = TipoEstacion::PANEL_IZQ; // Valor por defecto
                    Object^ objTipo = reader->GetValue(1);
                    if (objTipo != nullptr && objTipo != DBNull::Value) {
                        int tipoInt;
                        // Caso A: Si en la base de datos viene como número entero (0, 1, 2)
                        if (Int32::TryParse(objTipo->ToString(), tipoInt)) {
                            tipo = static_cast<TipoEstacion>(tipoInt);
                        }
                        // Caso B: Si en la base de datos viene como texto del Enum ("PANEL_IZQ", etc.)
                        else {
                            try {
                                tipo = static_cast<TipoEstacion>(Enum::Parse(TipoEstacion::typeid, objTipo->ToString()));
                            }
                            catch (Exception^) {
                                // Mantiene el valor por defecto si ocurre algún error imprevisto
                            }
                        }
                    }

                    int cantidad = reader->GetInt32(2);
                    lista->Add(gcnew EstacionTrabajoModel(id, tipo, cantidad));
                }
                reader->Close();
            }
            catch (Exception^ ex) {
                throw gcnew Exception("Error al obtener estaciones desde SQL: " + ex->Message);
            }
            finally {
                if (conn->State == ConnectionState::Open) conn->Close();
            }
            return lista;
        }

        // ==========================================================
        // 5. UPDATE: MODIFICAR ESTACIÓN
        // ==========================================================
        bool modificar(String^ id, TipoEstacion tipo, int cantidadPiezas) {
            SqlConnection^ conn = DBConnection::GetConnection();
            SqlCommand^ cmd = gcnew SqlCommand("sp_EstacionesTrabajo_Modificar", conn);
            cmd->CommandType = CommandType::StoredProcedure;

            cmd->Parameters->AddWithValue("@Id", id);
            cmd->Parameters->AddWithValue("@Tipo", static_cast<int>(tipo));
            cmd->Parameters->AddWithValue("@CantidadPiezas", cantidadPiezas);

            try {
                conn->Open();
                int filasAfectadas = cmd->ExecuteNonQuery();
                return (filasAfectadas > 0);
            }
            catch (Exception^ ex) {
                throw gcnew Exception("Error al modificar estación en SQL: " + ex->Message);
                return false;
            }
            finally {
                if (conn->State == ConnectionState::Open) conn->Close();
            }
        }

        // ==========================================================
        // 6. DELETE: ELIMINAR ESTACIÓN
        // ==========================================================
        bool eliminar(String^ id) {
            SqlConnection^ conn = DBConnection::GetConnection();
            SqlCommand^ cmd = gcnew SqlCommand("sp_EstacionesTrabajo_Eliminar", conn);
            cmd->CommandType = CommandType::StoredProcedure;

            cmd->Parameters->AddWithValue("@Id", id);

            try {
                conn->Open();
                int filasAfectadas = cmd->ExecuteNonQuery();
                return (filasAfectadas > 0);
            }
            catch (Exception^ ex) {
                throw gcnew Exception("Error al eliminar estación en SQL: " + ex->Message);
                return false;
            }
            finally {
                if (conn->State == ConnectionState::Open) conn->Close();
            }
        }
    };
}