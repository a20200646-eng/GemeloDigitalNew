#pragma once
using namespace System;
using namespace System::Collections::Generic;
using namespace System::IO;
using namespace GemeloDigitalModel;

namespace GemeloDigitalController {

    public ref class ReporteCostos {
    private:
        String^ id;
        int     ciclosIncluidos;
        double  horasTotales;
        double  costoPorHora;

    public:
        ReporteCostos(String^ id, int ciclosIncluidos,
            double horasTotales, double costoPorHora) {
            this->id = id;
            this->ciclosIncluidos = ciclosIncluidos;
            this->horasTotales = horasTotales;
            this->costoPorHora = costoPorHora;
        }

        property String^ Id {
            String^ get() { return id; }
        }

        property int CiclosIncluidos {
            int  get() { return ciclosIncluidos; }
            void set(int value) { ciclosIncluidos = value; }
        }

        property double HorasTotales {
            double get() { return horasTotales; }
            void   set(double value) { horasTotales = value; }
        }

        property double CostoPorHora {
            double get() { return costoPorHora; }
            void   set(double value) { costoPorHora = value; }
        }

        double calcularCostoTotal() { return horasTotales * costoPorHora; }
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
        bool agregar(String^ id, int ciclosIncluidos,
            double horasTotales, double costoPorHora) {
            if (buscarPorId(id) != nullptr) return false;
            repositorio->Add(gcnew ReporteCostos(id, ciclosIncluidos, horasTotales, costoPorHora));
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

        // UPDATE
        bool modificar(String^ id, int ciclosIncluidos,
            double horasTotales, double costoPorHora) {
            ReporteCostos^ r = buscarPorId(id);
            if (r == nullptr) return false;
            r->CiclosIncluidos = ciclosIncluidos;
            r->HorasTotales = horasTotales;
            r->CostoPorHora = costoPorHora;
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

        // Formato: id|turno|ciclosIncluidos|horasTotales|costoPorHora
        void guardarArchivo() {
            Directory::CreateDirectory("datos");
            StreamWriter^ sw = gcnew StreamWriter(RUTA, false, Text::Encoding::UTF8);
            for each (ReporteCostos ^ r in repositorio)
                sw->WriteLine(String::Format("{0}|{1}|{2}|{3}",
                    r->Id, r->CiclosIncluidos, r->HorasTotales, r->CostoPorHora));
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
                if (c->Length < 4) continue;
                repositorio->Add(gcnew ReporteCostos(
                    c[0], Int32::Parse(c[1]),
                    Double::Parse(c[2]), Double::Parse(c[3])));
            }
            sr->Close();
        }
    };
}