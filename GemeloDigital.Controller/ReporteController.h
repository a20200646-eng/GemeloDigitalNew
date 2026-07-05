#pragma once
#include "DBConnection.h"

using namespace System;
using namespace System::Collections::Generic;
using namespace System::Data;
using namespace System::Data::SqlClient;
using namespace GemeloDigitalModel;

namespace GemeloDigitalController {

    // ReporteCostos — clase auxiliar (ya no carga CicloId individual, ahora es N:N)
    public ref class ReporteCostos {
    private:
        String^ id;
        int     ciclosIncluidos;
        double  horasTotales;
        double  costoPorHora;
        String^ fechaGeneracion;
        String^ descripcion;

    public:
        ReporteCostos(String^ id, int ciclosIncluidos,
            double horasTotales, double costoPorHora) {
            this->id = id;
            this->ciclosIncluidos = ciclosIncluidos;
            this->horasTotales = horasTotales;
            this->costoPorHora = costoPorHora;
            this->fechaGeneracion = "";
            this->descripcion = "";
        }

        ReporteCostos(String^ id, String^ fechaGeneracion,
            double costoTotal, String^ descripcion) {
            this->id = id;
            this->fechaGeneracion = fechaGeneracion;
            this->costoPorHora = costoTotal;
            this->horasTotales = 1.0;
            this->ciclosIncluidos = 1;
            this->descripcion = descripcion;
        }

        property String^ Id{ String ^ get() { return id; } }
        property String^ FechaGeneracion{ String ^ get() { return fechaGeneracion; } void set(String ^ v) { fechaGeneracion = v; } }
        property String^ Descripcion{ String ^ get() { return descripcion; } void set(String ^ v) { descripcion = v; } }
        property int CiclosIncluidos{ int  get() { return ciclosIncluidos; } void set(int v) { ciclosIncluidos = v; } }
        property double HorasTotales{ double get() { return horasTotales; } void set(double v) { horasTotales = v; } }
        property double CostoPorHora{ double get() { return costoPorHora; } void set(double v) { costoPorHora = v; } }

        double calcularCostoTotal() { return horasTotales * costoPorHora; }
    };

    public ref class ReporteController {
    public:
        ReporteController() {}

        // ==========================================================
        // CREATE: INSERTAR REPORTE + relacion N:N con los ciclos incluidos
        // El SP: sp_ReportesCostos_Insertar(@Id, @FechaGeneracion, @CostoTotal, @Descripcion)
        // ==========================================================
        bool agregar(String^ id, String^ fechaGeneracion,
            double costoTotal, String^ descripcion, List<String^>^ ciclosIds) {

            SqlConnection^ conn = DBConnection::GetConnection();
            try {
                conn->Open();

                SqlCommand^ cmd = gcnew SqlCommand("sp_ReportesCostos_Insertar", conn);
                cmd->CommandType = CommandType::StoredProcedure;
                cmd->Parameters->AddWithValue("@Id", id);
                cmd->Parameters->AddWithValue("@FechaGeneracion", fechaGeneracion);
                cmd->Parameters->AddWithValue("@CostoTotal", costoTotal);
                cmd->Parameters->AddWithValue("@Descripcion", descripcion);
                cmd->ExecuteNonQuery();

                // Insertar relacion N:N para cada ciclo incluido
                if (ciclosIds != nullptr) {
                    for each(String ^ cicloId in ciclosIds) {
                        SqlCommand^ cmdRel = gcnew SqlCommand("sp_ReporteCiclos_Insertar", conn);
                        cmdRel->CommandType = CommandType::StoredProcedure;
                        cmdRel->Parameters->AddWithValue("@ReporteId", id);
                        cmdRel->Parameters->AddWithValue("@CicloId", cicloId);
                        cmdRel->ExecuteNonQuery();
                    }
                }

                return true;
            }
            catch (Exception^ ex) {
                throw gcnew Exception("Error al insertar reporte: " + ex->Message);
            }
            finally {
                if (conn->State == ConnectionState::Open) conn->Close();
            }
        }

        // Sobrecarga para compatibilidad con el codigo anterior (recibe lista de ciclos)
        bool agregar(String^ id, List<String^>^ ciclosIds, double horasTotales, double costoPorHora) {
            String^ fecha = DateTime::Now.ToString("yyyy-MM-dd HH:mm:ss");
            double costoTotal = horasTotales * costoPorHora;
            int ciclosIncluidos = (ciclosIds != nullptr) ? ciclosIds->Count : 0;
            String^ desc = String::Format("Ciclos: {0} | Horas: {1} | Costo/hora: {2}",
                ciclosIncluidos, horasTotales, costoPorHora);
            return agregar(id, fecha, costoTotal, desc, ciclosIds);
        }

        // ==========================================================
        // READ: BUSCAR POR ID (filtrado en memoria)
        // ==========================================================
        ReporteCostos^ buscarPorId(String^ id) {
            for each(ReporteCostos ^ r in obtenerTodos())
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

                    double costoTotal = 0.0;
                    Double::TryParse(reader->GetValue(2)->ToString(), costoTotal);

                    String^ desc = reader->IsDBNull(3) ? "" : reader->GetValue(3)->ToString();

                    lista->Add(gcnew ReporteCostos(id, fechaGeneracion, costoTotal, desc));
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

        // Compatibilidad — reportes son solo INSERT y SELECT segun handoff
        void guardarArchivo() {}
        void cargarArchivo() {}
    };
}