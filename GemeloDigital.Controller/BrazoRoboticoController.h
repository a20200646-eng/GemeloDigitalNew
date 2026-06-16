#pragma once
#include "DBConnection.h"

using namespace System;
using namespace System::Collections::Generic;
using namespace System::Data;
using namespace System::Data::SqlClient;
using namespace GemeloDigitalModel;

namespace GemeloDigitalController {

    public ref class BrazoRoboticoController {
    public:
        BrazoRoboticoController() {}

        void cargarArchivo() {}

        // ==========================================================
        // READ: BUSCAR BRAZO POR ID
        // Columnas reales: Id(0), Rol(1), Estado(2)
        // ==========================================================
        BrazoRoboticoModel^ buscarPorId(String^ id) {
            BrazoRoboticoModel^ brazoObj = nullptr;
            SqlConnection^ conn = DBConnection::GetConnection();
            SqlCommand^ cmd = gcnew SqlCommand("sp_BrazosRoboticos_BuscarPorId", conn);
            cmd->CommandType = CommandType::StoredProcedure;
            cmd->Parameters->AddWithValue("@Id", id);

            try {
                conn->Open();
                SqlDataReader^ reader = cmd->ExecuteReader();

                if (reader->Read()) {
                    String^ resId = reader->GetValue(0)->ToString();

                    RolBrazo resRol = RolBrazo::LATERAL_IZQ;
                    int rolInt;
                    if (Int32::TryParse(reader->GetValue(1)->ToString(), rolInt))
                        resRol = static_cast<RolBrazo>(rolInt);

                    EstadoBrazo resEstado = EstadoBrazo::REPOSO;
                    int estadoInt;
                    if (Int32::TryParse(reader->GetValue(2)->ToString(), estadoInt))
                        resEstado = static_cast<EstadoBrazo>(estadoInt);

                    brazoObj = gcnew BrazoRoboticoModel(resId, resRol);
                    brazoObj->Estado = resEstado;
                }
                reader->Close();
            }
            catch (Exception^ ex) {
                throw gcnew Exception("Error al buscar brazo por ID: " + ex->Message);
            }
            finally {
                if (conn->State == ConnectionState::Open) conn->Close();
            }
            return brazoObj;
        }

        // ==========================================================
        // READ: OBTENER TODOS LOS BRAZOS
        // Columnas reales: Id(0), Rol(1), Estado(2)
        // ==========================================================
        List<BrazoRoboticoModel^>^ obtenerTodos() {
            List<BrazoRoboticoModel^>^ lista = gcnew List<BrazoRoboticoModel^>();
            SqlConnection^ conn = DBConnection::GetConnection();
            SqlCommand^ cmd = gcnew SqlCommand("sp_BrazosRoboticos_ObtenerTodos", conn);
            cmd->CommandType = CommandType::StoredProcedure;

            try {
                conn->Open();
                SqlDataReader^ reader = cmd->ExecuteReader();

                while (reader->Read()) {
                    String^ id = reader->GetValue(0)->ToString();

                    RolBrazo rol = RolBrazo::LATERAL_IZQ;
                    int rolInt;
                    if (Int32::TryParse(reader->GetValue(1)->ToString(), rolInt))
                        rol = static_cast<RolBrazo>(rolInt);

                    EstadoBrazo estado = EstadoBrazo::REPOSO;
                    int estadoInt;
                    if (Int32::TryParse(reader->GetValue(2)->ToString(), estadoInt))
                        estado = static_cast<EstadoBrazo>(estadoInt);

                    BrazoRoboticoModel^ b = gcnew BrazoRoboticoModel(id, rol);
                    b->Estado = estado;
                    lista->Add(b);
                }
                reader->Close();
            }
            catch (Exception^ ex) {
                throw gcnew Exception("Error al obtener todos los brazos: " + ex->Message);
            }
            finally {
                if (conn->State == ConnectionState::Open) conn->Close();
            }
            return lista;
        }

        // ==========================================================
        // UPDATE: ACTUALIZAR ESTADO DEL BRAZO
        // CORRECTO: envia el numero entero del enum, no el texto
        // REPOSO=0, CALIBRANDO=1, POSICIONANDO=2, SOLDANDO=3,
        // EN_ERROR=4, PAUSA=5
        // ==========================================================
        bool modificar(String^ id, EstadoBrazo nuevoEstado) {
            SqlConnection^ conn = DBConnection::GetConnection();
            SqlCommand^ cmd = gcnew SqlCommand("sp_BrazosRoboticos_ActualizarEstado", conn);
            cmd->CommandType = CommandType::StoredProcedure;
            cmd->Parameters->AddWithValue("@Id", id);
            // FIX: cast a int primero, luego a String — nunca .ToString() directo
            cmd->Parameters->AddWithValue("@Estado", ((int)nuevoEstado).ToString());

            try {
                conn->Open();
                int filas = cmd->ExecuteNonQuery();
                return (filas > 0);
            }
            catch (Exception^ ex) {
                throw gcnew Exception("Error al actualizar estado del brazo: " + ex->Message);
            }
            finally {
                if (conn->State == ConnectionState::Open) conn->Close();
            }
        }

        // Sobrecarga String^ — el caller ya pasa el numero como string ("0","1",etc)
        bool modificar(String^ id, String^ estadoStr) {
            SqlConnection^ conn = DBConnection::GetConnection();
            SqlCommand^ cmd = gcnew SqlCommand("sp_BrazosRoboticos_ActualizarEstado", conn);
            cmd->CommandType = CommandType::StoredProcedure;
            cmd->Parameters->AddWithValue("@Id", id);
            cmd->Parameters->AddWithValue("@Estado", estadoStr);

            try {
                conn->Open();
                int filas = cmd->ExecuteNonQuery();
                return (filas > 0);
            }
            catch (Exception^ ex) {
                throw gcnew Exception("Error al actualizar estado del brazo: " + ex->Message);
            }
            finally {
                if (conn->State == ConnectionState::Open) conn->Close();
            }
        }

        // agregar() — solo semilla, brazos son fijos en produccion
        bool agregar(String^ id, RolBrazo rol) {
            if (buscarPorId(id) != nullptr) return false;

            SqlConnection^ conn = DBConnection::GetConnection();
            SqlCommand^ cmd = gcnew SqlCommand("sp_BrazosRoboticos_Insertar", conn);
            cmd->CommandType = CommandType::StoredProcedure;
            cmd->Parameters->AddWithValue("@Id", id);
            cmd->Parameters->AddWithValue("@Rol", ((int)rol).ToString());
            cmd->Parameters->AddWithValue("@Estado", "0");

            try {
                conn->Open();
                cmd->ExecuteNonQuery();
                return true;
            }
            catch (Exception^ ex) {
                throw gcnew Exception("Error al agregar brazo: " + ex->Message);
            }
            finally {
                if (conn->State == ConnectionState::Open) conn->Close();
            }
        }

        bool eliminar(String^ id) { return false; }
    };
}