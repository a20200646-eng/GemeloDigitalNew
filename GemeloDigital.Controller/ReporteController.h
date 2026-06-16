#pragma once
#include "DBConnection.h"

using namespace System;
using namespace System::Collections::Generic;
using namespace System::Data;
using namespace System::Data::SqlClient;
using namespace GemeloDigitalModel;

namespace GemeloDigitalController {

    // ReporteCostos — clase auxiliar (igual que antes, no cambia)
    public ref class ReporteCostos {
    private:
        String^ id;
        int     ciclosIncluidos;
        double  horasTotales;
        double  costoPorHora;
        String^ fechaGeneracion;
        String^ cicloId;
        String^ descripcion;

    public:
        ReporteCostos(String^ id, int ciclosIncluidos,
            double horasTotales, double costoPorHora) {
            this->id = id;
            this->ciclosIncluidos = ciclosIncluidos;
            this->horasTotales = horasTotales;
            this->costoPorHora = costoPorHora;
            this->fechaGeneracion = "";
            this->cicloId = "";
            this->descripcion = "";
        }

        ReporteCostos(String^ id, String^ fechaGeneracion, String^ cicloId,
            double costoTotal, String^ descripcion) {
            this->id = id;
            this->fechaGeneracion = fechaGeneracion;
            this->cicloId = cicloId;
            this->costoPorHora = costoTotal;
            this->horasTotales = 1.0;
            this->ciclosIncluidos = 1;
            this->descripcion = descripcion;
        }

        property String^ Id { String^ get() { return id; } }
        property String^ FechaGeneracion { String^ get() { return fechaGeneracion; } void set(String^ v) { fechaGeneracion = v; } }
        property String^ CicloId { String^ get() { return cicloId; } void set(String^ v) { cicloId = v; } }
        property String^ Descripcion { String^ get() { return descripcion; } void set(String^ v) { descripcion = v; } }
        property int CiclosIncluidos { int  get() { return ciclosIncluidos; } void set(int v) { ciclosIncluidos = v; } }
        property double HorasTotales { double get() { return horasTotales; } void set(double v) { horasTotales = v; } }
        property double CostoPorHora { double get() { return costoPorHora; } void set(double v) { costoPorHora = v; } }

        double calcularCostoTotal() { return horasTotales * costoPorHora; }
    };

    public ref class ReporteController {
    public:
        ReporteController() {}

        // ==========================================================
        // CREATE: INSERTAR REPORTE
        // El SP: sp_ReportesCostos_Insertar(@Id, @FechaGeneracion,
        //        @CicloId, @CostoTotal, @Descripcion)
        // ==========================================================
        bool agregar(String^ id, String^ fechaGeneracion, String^ cicloId,
            double costoTotal, String^ descripcion) {

            SqlConnection^ conn = DBConnection::GetConnection();
            SqlCommand^ cmd = gcnew SqlCommand("sp_ReportesCostos_Insertar", conn);
            cmd->CommandType = CommandType::StoredProcedure;

            cmd->Parameters->AddWithValue("@Id", id);
            cmd->Parameters->AddWithValue("@FechaGeneracion", fechaGeneracion);
            cmd->Parameters->AddWithValue("@CicloId", cicloId);
            cmd->Parameters->AddWithValue("@CostoTotal", costoTotal);
            cmd->Parameters->AddWithValue("@Descripcion", descripcion);

            try {
                conn->Open();
                cmd->ExecuteNonQuery();
                return true;
            }
            catch (Exception^ ex) {
                throw gcnew Exception("Error al insertar reporte: " + ex->Message);
            }
            finally {
                if (conn->State == ConnectionState::Open) conn->Close();
            }
        }

        // Sobrecarga para compatibilidad con el código anterior
        bool agregar(String^ id, int ciclosIncluidos, double horasTotales, double costoPorHora) {
            String^ fecha = DateTime::Now.ToString("yyyy-MM-dd HH:mm:ss");
            double costoTotal = horasTotales * costoPorHora;
            String^ desc = String::Format("Ciclos: {0} | Horas: {1} | Costo/hora: {2}",
                ciclosIncluidos, horasTotales, costoPorHora);
            return agregar(id, fecha, "", costoTotal, desc);
        }

        // ==========================================================
        // READ: BUSCAR POR ID (filtrado en memoria)
        // ==========================================================
        ReporteCostos^ buscarPorId(String^ id) {
            for each (ReporteCostos ^ r in obtenerTodos())
                if (r->Id->Equals(id)) return r;
            return nullptr;
        }

        // ==========================================================
        // READ: OBTENER TODOS
        // ==========================================================
        List<ReporteCostos^>^ obtenerTodos() {
            List<ReporteCostos^>^ lista = gcnew List<ReporteCostos^>();
            SqlConnection^ conn = DBConnection::GetConnection();
            SqlCommand^ cmd = gcnew SqlCommand("sp_ReportesCostos_ObtenerTodos", conn);
            cmd->CommandType = CommandType::StoredProcedure;

            try {
                conn->Open();
                SqlDataReader^ reader = cmd->ExecuteReader();
                while (reader->Read()) {
                    String^ id = reader->GetValue(0)->ToString();
                    String^ fechaGeneracion = reader->GetValue(1)->ToString();
                    String^ cicloId = reader->GetValue(2)->ToString();

                    double costoTotal = 0.0;
                    Double::TryParse(reader->GetValue(3)->ToString(), costoTotal);

                    String^ desc = reader->IsDBNull(4) ? "" : reader->GetValue(4)->ToString();

                    lista->Add(gcnew ReporteCostos(id, fechaGeneracion, cicloId, costoTotal, desc));
                }
                reader->Close();
            }
            catch (Exception^ ex) {
                throw gcnew Exception("Error al obtener reportes: " + ex->Message);
            }
            finally {
                if (conn->State == ConnectionState::Open) conn->Close();
            }
            return lista;
        }

        // Compatibilidad — reportes son solo INSERT y SELECT según handoff
        void guardarArchivo() {}
        void cargarArchivo() {}
    };
}