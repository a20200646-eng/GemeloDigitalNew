#pragma once
#include "DBConnection.h"
using namespace System;
using namespace System::Collections::Generic;
using namespace System::Data;
using namespace System::Data::SqlClient;
using namespace GemeloDigitalModel;

namespace GemeloDigitalController {

    public ref class SensorPosicionController {
    public:
        SensorPosicionController() {}

        // CREATE — uso principal: seed inicial
        bool agregar(String^ id, String^ nombre, bool activo,
            double anguloMedido, double tolerancia, String^ brazoId) {
            SqlConnection^ conn = DBConnection::GetConnection();
            SqlCommand^ cmd = gcnew SqlCommand("sp_SensoresPosicion_Insertar", conn);
            cmd->CommandType = CommandType::StoredProcedure;
            cmd->Parameters->AddWithValue("@Id", id);
            cmd->Parameters->AddWithValue("@Nombre", nombre);
            cmd->Parameters->AddWithValue("@Activo", activo);
            cmd->Parameters->AddWithValue("@AnguloMedido", anguloMedido);
            cmd->Parameters->AddWithValue("@Tolerancia", tolerancia);
            cmd->Parameters->AddWithValue("@BrazoId", brazoId);
            try {
                conn->Open();
                cmd->ExecuteNonQuery();
                return true;
            }
            catch (Exception^ ex) {
                throw gcnew Exception("Error al agregar sensor de posicion en SQL: " + ex->Message);
            }
            finally {
                if (conn->State == ConnectionState::Open) conn->Close();
            }
        }

        // READ — el sensor de posicion de un brazo (uso principal: poblar BrazoRoboticoModel)
        List<SensorPosicionModel^>^ obtenerPorBrazoId(String^ brazoId) {
            List<SensorPosicionModel^>^ lista = gcnew List<SensorPosicionModel^>();
            SqlConnection^ conn = DBConnection::GetConnection();
            SqlCommand^ cmd = gcnew SqlCommand("sp_SensoresPosicion_ObtenerPorBrazo", conn);
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
                throw gcnew Exception("Error al obtener sensor de posicion por brazo: " + ex->Message);
            }
            finally {
                if (conn->State == ConnectionState::Open) conn->Close();
            }
            return lista;
        }

        // READ — por ID
        SensorPosicionModel^ buscarPorId(String^ id) {
            SensorPosicionModel^ s = nullptr;
            SqlConnection^ conn = DBConnection::GetConnection();
            SqlCommand^ cmd = gcnew SqlCommand("sp_SensoresPosicion_BuscarPorId", conn);
            cmd->CommandType = CommandType::StoredProcedure;
            cmd->Parameters->AddWithValue("@Id", id);
            try {
                conn->Open();
                SqlDataReader^ reader = cmd->ExecuteReader();
                if (reader->Read()) s = LeerSensor(reader);
                reader->Close();
            }
            catch (Exception^ ex) {
                throw gcnew Exception("Error al buscar sensor de posicion por ID: " + ex->Message);
            }
            finally {
                if (conn->State == ConnectionState::Open) conn->Close();
            }
            return s;
        }

        // UPDATE — solo AnguloMedido (campo dinamico)
        // sp usa SET NOCOUNT ON -> verificar con buscarPorId()
        bool modificar(String^ id, double nuevoAngulo) {
            SqlConnection^ conn = DBConnection::GetConnection();
            SqlCommand^ cmd = gcnew SqlCommand("sp_SensoresPosicion_ActualizarMedicion", conn);
            cmd->CommandType = CommandType::StoredProcedure;
            cmd->Parameters->AddWithValue("@Id", id);
            cmd->Parameters->AddWithValue("@AnguloMedido", nuevoAngulo);
            try {
                conn->Open();
                cmd->ExecuteNonQuery();
            }
            catch (Exception^ ex) {
                throw gcnew Exception("Error al actualizar sensor de posicion: " + ex->Message);
            }
            finally {
                if (conn->State == ConnectionState::Open) conn->Close();
            }

            SensorPosicionModel^ verif = buscarPorId(id);
            return (verif != nullptr && Math::Abs(verif->AnguloMedido - nuevoAngulo) < 0.0001);
        }

    private:
        // Columnas: Id(0) Nombre(1) Activo(2) AnguloMedido(3) Tolerancia(4) BrazoId(5)
        SensorPosicionModel^ LeerSensor(SqlDataReader^ reader) {
            String^ id = reader->GetValue(0)->ToString();
            String^ nombre = reader->GetValue(1)->ToString();

            bool activo = false;
            Object^ valActivo = reader->GetValue(2);
            if (valActivo != nullptr && valActivo != DBNull::Value) {
                String^ s = valActivo->ToString()->ToLower()->Trim();
                activo = (s == "1" || s == "true");
            }

            double anguloMedido = 0.0; Double::TryParse(reader->GetValue(3)->ToString(), anguloMedido);
            double tolerancia = 0.0; Double::TryParse(reader->GetValue(4)->ToString(), tolerancia);

            return gcnew SensorPosicionModel(id, nombre, activo, anguloMedido, tolerancia);
        }
    };
}