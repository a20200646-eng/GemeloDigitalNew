#pragma once
using namespace System;
using namespace System::Collections::Generic;
using namespace System::IO;
using namespace GemeloDigitalModel;

namespace GemeloDigitalController {

    // ReporteCostos — clase auxiliar del Controller, no tiene Model
    public ref class ReporteCostos {
    private:
        String^    id;
        int    ciclosCompletados;
        double tiempoOperativo;
        double costoPorCiclo;

    public:
        ReporteCostos(String^ id, int ciclosCompletados,
            double tiempoOperativo, double costoPorCiclo) {
            this->id = id;
            this->ciclosCompletados = ciclosCompletados;
            this->tiempoOperativo = tiempoOperativo;
            this->costoPorCiclo = costoPorCiclo;
        }

        property String^ Id {
            String^ get() { return id; }
        }

        property int CiclosCompletados {
            int  get() { return ciclosCompletados; }
            void set(int value) { ciclosCompletados = value; }
        }

        property double TiempoOperativo {
            double get() { return tiempoOperativo; }
            void   set(double value) { tiempoOperativo = value; }
        }

        property double CostoPorCiclo {
            double get() { return costoPorCiclo; }
            void   set(double value) { costoPorCiclo = value; }
        }

        // Calculado dinamicamente — no se almacena
        double calcularCostoTotal() { return ciclosCompletados * costoPorCiclo; }

        void dataReport() {
            Console::WriteLine("=== REPORTE DE COSTOS ===");
            Console::WriteLine("ID: " + Id);
            Console::WriteLine("|Ciclos: " + CiclosCompletados);
            Console::WriteLine("|Tiempo operativo: " + TiempoOperativo + " hrs");
            Console::WriteLine("|Costo/ciclo: $" + CostoPorCiclo);
            Console::WriteLine("|COSTO TOTAL: $" + calcularCostoTotal());
        }
    };

    public ref class ReporteController {
    private:
        List<ReporteCostos^>^ repositorio;
        static String^ RUTA = "datos\\reportes.dat";

    public:
        ReporteController() {
            repositorio = gcnew List<ReporteCostos^>();
            cargarArchivo();
        }

        // CREATE
        bool agregar(String^ id, int ciclos, double tiempo, double costoCiclo) {
            if (buscarPorId(id) != nullptr) return false;
            repositorio->Add(gcnew ReporteCostos(id, ciclos, tiempo, costoCiclo));
            guardarArchivo();
            return true;
        }

        // READ - por ID
        ReporteCostos^ buscarPorId(String^ id) {
            for each (ReporteCostos ^ r in repositorio)
                if (r->Id->Equals(id)) return r;
            return nullptr;
        }

        // READ - todos
        List<ReporteCostos^>^ obtenerTodos() {
            return repositorio;
        }

        // UPDATE - reemplaza todos los atributos modificables
        bool modificar(String^ id, int ciclosCompletados,
            double tiempoOperativo, double costoPorCiclo) {
            ReporteCostos^ r = buscarPorId(id);
            if (r == nullptr) return false;
            r->CiclosCompletados = ciclosCompletados;
            r->TiempoOperativo = tiempoOperativo;
            r->CostoPorCiclo = costoPorCiclo;
            guardarArchivo();
            return true;
        }

        // DELETE
        bool eliminar(String^ id) {
            ReporteCostos^ r = buscarPorId(id);
            if (r == nullptr) return false;
            repositorio->Remove(r);
            guardarArchivo();
            return true;
        }

        // Formato: id|ciclosCompletados|tiempoOperativo|costoPorCiclo
        void guardarArchivo() {
            Directory::CreateDirectory("datos");
            StreamWriter^ sw = gcnew StreamWriter(RUTA, false, Text::Encoding::UTF8);
            for each (ReporteCostos ^ r in repositorio)
                sw->WriteLine(String::Format("{0}|{1}|{2}|{3}",
                    r->Id, r->CiclosCompletados,
                    r->TiempoOperativo, r->CostoPorCiclo));
            sw->Close();
        }

        void cargarArchivo() {
            if (!File::Exists(RUTA)) return;
            repositorio->Clear();
            StreamReader^ sr = gcnew StreamReader(RUTA, Text::Encoding::UTF8);
            String^ linea;
            while ((linea = sr->ReadLine()) != nullptr) {
                if (linea->Trim()->Length == 0) continue;
                array<String^>^ c = linea->Split('|');
                repositorio->Add(gcnew ReporteCostos(
                    c[0], Int32::Parse(c[1]),
                    Double::Parse(c[2]), Double::Parse(c[3])));
            }
            sr->Close();
        }
    };
}