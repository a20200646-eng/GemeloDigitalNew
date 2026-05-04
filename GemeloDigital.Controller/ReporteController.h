#pragma once
using namespace System;
using namespace System::Collections::Generic;
using namespace GemeloDigitalModel;

namespace GemeloDigitalController {

    // ReporteCostos se define aqui directamente — no es una clase del Model
    public ref class ReporteCostos {
    private:
        int id;
        int ciclosCompletados;
        double tiempoOperativo;
        double costoPorCiclo;

    public:
        ReporteCostos(int id, int ciclosCompletados,
            double tiempoOperativo, double costoPorCiclo) {
            this->id = id;
            this->ciclosCompletados = ciclosCompletados;
            this->tiempoOperativo = tiempoOperativo;
            this->costoPorCiclo = costoPorCiclo;
        }

        int getId() { return id; }
        int getCiclosCompletados() { return ciclosCompletados; }
        double getTiempoOperativo() { return tiempoOperativo; }
        double getCostoPorCiclo() { return costoPorCiclo; }

        void setCiclosCompletados(int c) { ciclosCompletados = c; }
        void setTiempoOperativo(double t) { tiempoOperativo = t; }
        void setCostoPorCiclo(double c) { costoPorCiclo = c; }

        double calcularCostoTotal() { return ciclosCompletados * costoPorCiclo; }

        void dataReport() {
            Console::WriteLine("=== REPORTE DE COSTOS ===");
            Console::WriteLine("ID: " + id);
            Console::WriteLine("|Ciclos: " + ciclosCompletados);
            Console::WriteLine("|Tiempo operativo: " + tiempoOperativo + " hrs");
            Console::WriteLine("|Costo/ciclo: $" + costoPorCiclo);
            Console::WriteLine("|COSTO TOTAL: $" + calcularCostoTotal());
        }
    };

    public ref class ReporteController {
    private:
        List<ReporteCostos^>^ repositorio;

    public:
        ReporteController() {
            repositorio = gcnew List<ReporteCostos^>();
        }

        // CREATE
        bool agregar(int id, int ciclos, double tiempo, double costoCiclo) {
            ReporteCostos^ r = buscarPorId(id);
            if (r == nullptr) {
                repositorio->Add(gcnew ReporteCostos(id, ciclos, tiempo, costoCiclo));
                return true;
            }
            return false;
        }

        // READ - por ID
        ReporteCostos^ buscarPorId(int id) {
            for each (ReporteCostos ^ r in repositorio) {
                if (r->getId() == id) return r;
            }
            return nullptr;
        }

        // READ - todos
        List<ReporteCostos^>^ obtenerTodos() {
            return repositorio;
        }

        // UPDATE - C: ciclos | T: tiempoOperativo | P: costoPorCiclo
        bool modificar(int id, String^ opcion, String^ valor) {
            ReporteCostos^ r = buscarPorId(id);
            if (r != nullptr) {
                if (opcion->Equals("C"))      r->setCiclosCompletados(Convert::ToInt32(valor));
                else if (opcion->Equals("T")) r->setTiempoOperativo(Convert::ToDouble(valor));
                else if (opcion->Equals("P")) r->setCostoPorCiclo(Convert::ToDouble(valor));
                else return false;
                return true;
            }
            return false;
        }

        // DELETE
        bool eliminar(int id) {
            ReporteCostos^ r = buscarPorId(id);
            if (r != nullptr) {
                repositorio->Remove(r);
                return true;
            }
            return false;
        }
    };
}