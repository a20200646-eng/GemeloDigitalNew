#pragma once
#include "DBConnection.h"
using namespace System;
using namespace System::Collections::Generic;
using namespace System::Data;
using namespace System::Data::SqlClient;
using namespace GemeloDigitalModel;

namespace GemeloDigitalController {

    public ref class SensorFuerzaController {
    public:
        SensorFuerzaController() {}

        // CREATE — uso principal: seed inicial
        bool agregar(String^ id, String^ nombre, bool activo,
            double fuerzaActual, double fuerzaMinima, double fuerzaMaxima, String^ brazoId) {
            SqlConnection^ conn = DBConnection::GetConnection();
            SqlCommand^ cmd = gcnew SqlCommand("sp_SensoresFuerza_Insertar", conn);
            cmd->CommandType = CommandType::StoredProcedure;
            cmd->Parameters->AddWithValue("@Id", id);
            cmd->Parameters->AddWithValue("@Nombre", nombre);
            cmd->Parameters->AddWithValue("@Activo", activo);
            cmd->Parameters->AddWithValue("@FuerzaActual", fuerzaActual);
            cmd->Parameters->AddWithValue("@FuerzaMinima", fuerzaMinima);
            cmd->Parameters->AddWithValue("@FuerzaMaxima", fuerzaMaxima);
            cmd->Parameters->AddWithValue("@BrazoId", brazoId);
            try {
                conn->Open();
                cmd->ExecuteNonQuery();
                return true;
            }
            catch (Exception^ ex) {
                throw gcnew Exception("Error al agregar sensor de fuerza en SQL: " + ex->Message);
            }
            finally {
                if (conn->State == ConnectionState::Open) conn->Close();
            }
        }

        // READ — el sensor de fuerza de un brazo (uso principal: poblar BrazoRoboticoModel)
        List<SensorFuerzaModel^>^ obtenerPorBrazoId(String^ brazoId) {
            List<SensorFuerzaModel^>^ lista = gcnew List<SensorFuerzaModel^>();
            SqlConnection^ conn = DBConnection::GetConnection();
            SqlCommand^ cmd = gcnew SqlCommand("sp_SensoresFuerza_ObtenerPorBrazo", conn);
            cmd->CommandType = CommandType::StoredProcedure;
            cmd->Parameters->AddWithValue("@BrazoId", brazoId);
            try {
                conn->Open();
                SqlDataReader^ reader = cmd->ExecuteReader();
                while (reader->Read())
                    lista->Add(LeerSensor(reader));
                reader->Close();
            }
            catch (Exception^ ex) {
                throw gcnew Exception("Error al obtener sensor de fuerza por brazo: " + ex->Message);
            }
            finally {
                if (conn->State == ConnectionState::Open) conn->Close();
            }
            return lista;
        }

        // READ — por ID
        SensorFuerzaModel^ buscarPorId(String^ id) {
            SensorFuerzaModel^ s = nullptr;
            SqlConnection^ conn = DBConnection::GetConnection();
            SqlCommand^ cmd = gcnew SqlCommand("sp_SensoresFuerza_BuscarPorId", conn);
            cmd->CommandType = CommandType::StoredProcedure;
            cmd->Parameters->AddWithValue("@Id", id);
            try {
                conn->Open();
                SqlDataReader^ reader = cmd->ExecuteReader();
                if (reader->Read()) s = LeerSensor(reader);
                reader->Close();
            }
            catch (Exception^ ex) {
                throw gcnew Exception("Error al buscar sensor de fuerza por ID: " + ex->Message);
            }
            finally {
                if (conn->State == ConnectionState::Open) conn->Close();
            }
            return s;
        }

        // UPDATE — solo FuerzaActual (campo dinamico, tarea Sostener)
        // sp usa SET NOCOUNT ON -> verificar con buscarPorId()
        bool modificar(String^ id, double nuevaFuerza) {
            SqlConnection^ conn = DBConnection::GetConnection();
            SqlCommand^ cmd = gcnew SqlCommand("sp_SensoresFuerza_ActualizarFuerza", conn);
            cmd->CommandType = CommandType::StoredProcedure;
            cmd->Parameters->AddWithValue("@Id", id);
            cmd->Parameters->AddWithValue("@FuerzaActual", nuevaFuerza);
            try {
                conn->Open();
                cmd->ExecuteNonQuery();
            }
            catch (Exception^ ex) {
                throw gcnew Exception("Error al actualizar sensor de fuerza: " + ex->Message);
            }
            finally {
                if (conn->State == ConnectionState::Open) conn->Close();
            }

            SensorFuerzaModel^ verif = buscarPorId(id);
            return (verif != nullptr && Math::Abs(verif->FuerzaActual - nuevaFuerza) < 0.0001);
        }

    private:
        // Columnas: Id(0) Nombre(1) Activo(2) FuerzaActual(3) FuerzaMinima(4) FuerzaMaxima(5) BrazoId(6)
        SensorFuerzaModel^ LeerSensor(SqlDataReader^ reader) {
            String^ id = reader->GetValue(0)->ToString();
            String^ nombre = reader->GetValue(1)->ToString();

            bool activo = false;
            Object^ valActivo = reader->GetValue(2);
            if (valActivo != nullptr && valActivo != DBNull::Value) {
                String^ s = valActivo->ToString()->ToLower()->Trim();
                activo = (s == "1" || s == "true");
            }

            double fuerzaActual = 0.0; Double::TryParse(reader->GetValue(3)->ToString(), fuerzaActual);
            double fuerzaMinima = 0.0; Double::TryParse(reader->GetValue(4)->ToString(), fuerzaMinima);
            double fuerzaMaxima = 0.0; Double::TryParse(reader->GetValue(5)->ToString(), fuerzaMaxima);

            return gcnew SensorFuerzaModel(id, nombre, activo, fuerzaActual, fuerzaMinima, fuerzaMaxima);
        }
    };
}