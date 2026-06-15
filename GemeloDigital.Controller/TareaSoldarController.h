#pragma once
using namespace System;
using namespace System::Collections::Generic;
using namespace System::IO;
using namespace GemeloDigitalModel;

namespace GemeloDigitalController {

    public ref class TareaSoldarController {
    private:
        List<TareaSoldarModel^>^ repositorio;
        static String^ RUTA = "datos\\tareas_soldar.dat";

    public:
        TareaSoldarController() {
            repositorio = gcnew List<TareaSoldarModel^>();
            cargarArchivo();
        }

        // CREATE
        bool agregar(String^ id, int puntosObjetivo, double temperatura) {
            if (buscarPorId(id) != nullptr) return false;
            repositorio->Add(gcnew TareaSoldarModel(id, puntosObjetivo, temperatura));
            guardarArchivo();
            return true;
        }

        // READ - por ID
        TareaSoldarModel^ buscarPorId(String^ id) {
            for each (TareaSoldarModel ^ t in repositorio)
                if (t->Id->Equals(id)) return t;
            return nullptr;
        }

        // READ - todos
        List<TareaSoldarModel^>^ obtenerTodos() {
            return repositorio;
        }

        // UPDATE - reemplaza todos los atributos modificables
        bool modificar(String^ id, String^ estado, int puntosObjetivo,
            int puntosCompletados, double temperatura) {
            TareaSoldarModel^ t = buscarPorId(id);
            if (t == nullptr) return false;
            t->Estado = estado;
            t->PuntosObjetivo = puntosObjetivo;
            t->PuntosCompletados = puntosCompletados;
            t->Temperatura = temperatura;
            guardarArchivo();
            return true;
        }

        // DELETE
        bool eliminar(String^ id) {
            TareaSoldarModel^ t = buscarPorId(id);
            if (t == nullptr) return false;
            repositorio->Remove(t);
            guardarArchivo();
            return true;
        }

        // Formato: id|estado|puntosObjetivo|puntosCompletados|temperatura
        void guardarArchivo() {
            Directory::CreateDirectory("datos");
            StreamWriter^ sw = gcnew StreamWriter(RUTA, false, Text::Encoding::UTF8);
            for each (TareaSoldarModel ^ t in repositorio)
                sw->WriteLine(String::Format("{0}|{1}|{2}|{3}|{4}",
                    t->Id, t->Estado, t->PuntosObjetivo,
                    t->PuntosCompletados, t->Temperatura));
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
                TareaSoldarModel^ t = gcnew TareaSoldarModel(
                    c[0], Int32::Parse(c[2]), Double::Parse(c[4]));
                t->Estado = c[1];
                t->PuntosCompletados = Int32::Parse(c[3]);
                repositorio->Add(t);
            }
            sr->Close();
        }
    };
}