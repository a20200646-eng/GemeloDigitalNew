#pragma once
using namespace System;
using namespace System::Collections::Generic;
using namespace System::IO;
using namespace GemeloDigitalModel;

namespace GemeloDigitalController {

    public ref class SensorFuerzaController {
    private:
        List<SensorFuerzaModel^>^ repositorio;
        static String^ RUTA = "datos\\sensores_fuerza.dat";

    public:
        SensorFuerzaController() {
            repositorio = gcnew List<SensorFuerzaModel^>();
            cargarArchivo();
        }

        // CREATE
        bool agregar(int id, String^ nombre, bool activo,
            double fuerzaActual, double fuerzaMinima, double fuerzaMaxima) {
            if (buscarPorId(id) != nullptr) return false;
            repositorio->Add(gcnew SensorFuerzaModel(
                id, nombre, activo, fuerzaActual, fuerzaMinima, fuerzaMaxima));
            guardarArchivo();
            return true;
        }

        // READ - por ID
        SensorFuerzaModel^ buscarPorId(int id) {
            for each (SensorFuerzaModel ^ s in repositorio)
                if (s->Id == id) return s;
            return nullptr;
        }

        // READ - todos
        List<SensorFuerzaModel^>^ obtenerTodos() {
            return repositorio;
        }

        // UPDATE - reemplaza todos los atributos modificables
        bool modificar(int id, String^ nombre, bool activo,
            double fuerzaActual, double fuerzaMinima, double fuerzaMaxima) {
            SensorFuerzaModel^ s = buscarPorId(id);
            if (s == nullptr) return false;
            s->Nombre = nombre;
            s->Activo = activo;
            s->FuerzaActual = fuerzaActual;
            s->FuerzaMinima = fuerzaMinima;
            s->FuerzaMaxima = fuerzaMaxima;
            guardarArchivo();
            return true;
        }

        // DELETE
        bool eliminar(int id) {
            SensorFuerzaModel^ s = buscarPorId(id);
            if (s == nullptr) return false;
            repositorio->Remove(s);
            guardarArchivo();
            return true;
        }

        // Formato: id|nombre|activo|fuerzaActual|fuerzaMinima|fuerzaMaxima
        void guardarArchivo() {
            Directory::CreateDirectory("datos");
            StreamWriter^ sw = gcnew StreamWriter(RUTA, false, Text::Encoding::UTF8);
            for each (SensorFuerzaModel ^ s in repositorio)
                sw->WriteLine(String::Format("{0}|{1}|{2}|{3}|{4}|{5}",
                    s->Id, s->Nombre, (s->Activo ? 1 : 0),
                    s->FuerzaActual, s->FuerzaMinima, s->FuerzaMaxima));
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
                repositorio->Add(gcnew SensorFuerzaModel(
                    Int32::Parse(c[0]), c[1], c[2]->Equals("1"),
                    Double::Parse(c[3]), Double::Parse(c[4]), Double::Parse(c[5])));
            }
            sr->Close();
        }
    };
}