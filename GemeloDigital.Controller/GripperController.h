#pragma once
#include "DBConnection.h"
using namespace System;
using namespace System::Collections::Generic;
using namespace System::Data;
using namespace System::Data::SqlClient;
using namespace GemeloDigitalModel;

namespace GemeloDigitalController {

    public ref class GripperController {
    public:
        GripperController() {}

        // CREATE — uso principal: seed inicial
        bool agregar(String^ id, String^ nombre, bool activo,
            double apertura, double fuerzaAgarre, bool abierto, String^ brazoId) {
            SqlConnection^ conn = DBConnection::GetConnection();
            SqlCommand^ cmd = gcnew SqlCommand("sp_Grippers_Insertar", conn);
            cmd->CommandType = CommandType::StoredProcedure;
            cmd->Parameters->AddWithValue("@Id", id);
            cmd->Parameters->AddWithValue("@Nombre", nombre);
            cmd->Parameters->AddWithValue("@Activo", activo);
            cmd->Parameters->AddWithValue("@Apertura", apertura);
            cmd->Parameters->AddWithValue("@FuerzaAgarre", fuerzaAgarre);
            cmd->Parameters->AddWithValue("@Abierto", abierto);
            cmd->Parameters->AddWithValue("@BrazoId", brazoId);
            try {
                conn->Open();
                cmd->ExecuteNonQuery();
                return true;
            }
            catch (Exception^ ex) {
                throw gcnew Exception("Error al agregar gripper en SQL: " + ex->Message);
            }
            finally {
                if (conn->State == ConnectionState::Open) conn->Close();
            }
        }

        // READ — el gripper de un brazo (lista de 1; uso principal: poblar BrazoRoboticoModel)
        List<GripperModel^>^ obtenerPorBrazoId(String^ brazoId) {
            List<GripperModel^>^ lista = gcnew List<GripperModel^>();
            SqlConnection^ conn = DBConnection::GetConnection();
            SqlCommand^ cmd = gcnew SqlCommand("sp_Grippers_ObtenerPorBrazo", conn);
            cmd->CommandType = CommandType::StoredProcedure;
            cmd->Parameters->AddWithValue("@BrazoId", brazoId);
            try {
                conn->Open();
                SqlDataReader^ reader = cmd->ExecuteReader();
                while (reader->Read())
                    lista->Add(LeerGripper(reader));
                reader->Close();
            }
            catch (Exception^ ex) {
                throw gcnew Exception("Error al obtener gripper por brazo: " + ex->Message);
            }
            finally {
                if (conn->State == ConnectionState::Open) conn->Close();
            }
            return lista;
        }

        // READ — por ID
        GripperModel^ buscarPorId(String^ id) {
            GripperModel^ g = nullptr;
            SqlConnection^ conn = DBConnection::GetConnection();
            SqlCommand^ cmd = gcnew SqlCommand("sp_Grippers_BuscarPorId", conn);
            cmd->CommandType = CommandType::StoredProcedure;
            cmd->Parameters->AddWithValue("@Id", id);
            try {
                conn->Open();
                SqlDataReader^ reader = cmd->ExecuteReader();
                if (reader->Read()) g = LeerGripper(reader);
                reader->Close();
            }
            catch (Exception^ ex) {
                throw gcnew Exception("Error al buscar gripper por ID: " + ex->Message);
            }
            finally {
                if (conn->State == ConnectionState::Open) conn->Close();
            }
            return g;
        }

        // UPDATE — Apertura, FuerzaAgarre, Abierto (campos dinamicos, tarea Sostener)
        // sp usa SET NOCOUNT ON -> verificar con buscarPorId()
        bool modificar(String^ id, double apertura, double fuerzaAgarre, bool abierto) {
            SqlConnection^ conn = DBConnection::GetConnection();
            SqlCommand^ cmd = gcnew SqlCommand("sp_Grippers_ActualizarEstado", conn);
            cmd->CommandType = CommandType::StoredProcedure;
            cmd->Parameters->AddWithValue("@Id", id);
            cmd->Parameters->AddWithValue("@Apertura", apertura);
            cmd->Parameters->AddWithValue("@FuerzaAgarre", fuerzaAgarre);
            cmd->Parameters->AddWithValue("@Abierto", abierto);
            try {
                conn->Open();
                cmd->ExecuteNonQuery();
            }
            catch (Exception^ ex) {
                throw gcnew Exception("Error al actualizar gripper: " + ex->Message);
            }
            finally {
                if (conn->State == ConnectionState::Open) conn->Close();
            }

            GripperModel^ verif = buscarPorId(id);
            return (verif != nullptr
                && Math::Abs(verif->FuerzaAgarre - fuerzaAgarre) < 0.0001
                && verif->Abierto == abierto);
        }

    private:
        // Columnas: Id(0) Nombre(1) Activo(2) Apertura(3) FuerzaAgarre(4) Abierto(5) BrazoId(6)
        GripperModel^ LeerGripper(SqlDataReader^ reader) {
            String^ id = reader->GetValue(0)->ToString();
            String^ nombre = reader->GetValue(1)->ToString();

            bool activo = LeerBit(reader->GetValue(2));
            double apertura = 0.0; Double::TryParse(reader->GetValue(3)->ToString(), apertura);
            double fuerzaAgarre = 0.0; Double::TryParse(reader->GetValue(4)->ToString(), fuerzaAgarre);
            bool abierto = LeerBit(reader->GetValue(5));

            return gcnew GripperModel(id, nombre, activo, apertura, fuerzaAgarre, abierto);
        }

        bool LeerBit(Object^ val) {
            if (val == nullptr || val == DBNull::Value) return false;
            String^ s = val->ToString()->ToLower()->Trim();
            return (s == "1" || s == "true");
        }
    };
}