#pragma once
using namespace System;
using namespace System::Collections::Generic;
using namespace System::IO;
using namespace GemeloDigitalModel;

namespace GemeloDigitalController {

    public ref class TareaPosicionarController {
    private:
        List<TareaPosicionarModel^>^ repositorio;
        static String^ RUTA = "datos\\tareas_posicionar.dat";

    public:
        TareaPosicionarController() {
            repositorio = gcnew List<TareaPosicionarModel^>();
            cargarArchivo();
        }

        // CREATE
        bool agregar(int id, double posicionObjetivo, double tolerancia) {
            if (buscarPorId(id) != nullptr) return false;
            repositorio->Add(gcnew TareaPosicionarModel(id, posicionObjetivo, tolerancia));
            guardarArchivo();
            return true;
        }

        // READ - por ID
        TareaPosicionarModel^ buscarPorId(int id) {
            for each (TareaPosicionarModel ^ t in repositorio)
                if (t->Id == id) return t;
            return nullptr;
        }

        // READ - todos
        List<TareaPosicionarModel^>^ obtenerTodos() {
            return repositorio;
        }

        // UPDATE - reemplaza todos los atributos modificables
        bool modificar(int id, String^ estado,
            double posicionObjetivo, double tolerancia) {
            TareaPosicionarModel^ t = buscarPorId(id);
            if (t == nullptr) return false;
            t->Estado = estado;
            t->PosicionObjetivo = posicionObjetivo;
            t->Tolerancia = tolerancia;
            guardarArchivo();
            return true;
        }

        // DELETE
        bool eliminar(int id) {
            TareaPosicionarModel^ t = buscarPorId(id);
            if (t == nullptr) return false;
            repositorio->Remove(t);
            guardarArchivo();
            return true;
        }

        // Formato: id|estado|posicionObjetivo|tolerancia
        void guardarArchivo() {
            Directory::CreateDirectory("datos");
            StreamWriter^ sw = gcnew StreamWriter(RUTA, false, Text::Encoding::UTF8);
            for each (TareaPosicionarModel ^ t in repositorio)
                sw->WriteLine(String::Format("{0}|{1}|{2}|{3}",
                    t->Id, t->Estado, t->PosicionObjetivo, t->Tolerancia));
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
                TareaPosicionarModel^ t = gcnew TareaPosicionarModel(
                    Int32::Parse(c[0]), Double::Parse(c[2]), Double::Parse(c[3]));
                t->Estado = c[1];
                repositorio->Add(t);
            }
            sr->Close();
        }
    };
}