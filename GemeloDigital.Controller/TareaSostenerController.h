#pragma once
using namespace System;
using namespace System::Collections::Generic;
using namespace System::IO;
using namespace GemeloDigitalModel;

namespace GemeloDigitalController {

    public ref class TareaSostenerController {
    private:
        List<TareaSostenerModel^>^ repositorio;
        static String^ RUTA = "datos\\tareas_sostener.dat";

    public:
        TareaSostenerController() {
            repositorio = gcnew List<TareaSostenerModel^>();
            cargarArchivo();
        }

        // CREATE
        bool agregar(int id, double fuerzaSosten, int duracion) {
            if (buscarPorId(id) != nullptr) return false;
            repositorio->Add(gcnew TareaSostenerModel(id, fuerzaSosten, duracion));
            guardarArchivo();
            return true;
        }

        // READ - por ID
        TareaSostenerModel^ buscarPorId(int id) {
            for each (TareaSostenerModel ^ t in repositorio)
                if (t->Id == id) return t;
            return nullptr;
        }

        // READ - todos
        List<TareaSostenerModel^>^ obtenerTodos() {
            return repositorio;
        }

        // UPDATE - reemplaza todos los atributos modificables
        bool modificar(int id, String^ estado, double fuerzaSosten, int duracion) {
            TareaSostenerModel^ t = buscarPorId(id);
            if (t == nullptr) return false;
            t->Estado = estado;
            t->FuerzaSosten = fuerzaSosten;
            t->Duracion = duracion;
            guardarArchivo();
            return true;
        }

        // DELETE
        bool eliminar(int id) {
            TareaSostenerModel^ t = buscarPorId(id);
            if (t == nullptr) return false;
            repositorio->Remove(t);
            guardarArchivo();
            return true;
        }

        // Formato: id|estado|fuerzaSosten|duracion
        void guardarArchivo() {
            Directory::CreateDirectory("datos");
            StreamWriter^ sw = gcnew StreamWriter(RUTA, false, Text::Encoding::UTF8);
            for each (TareaSostenerModel ^ t in repositorio)
                sw->WriteLine(String::Format("{0}|{1}|{2}|{3}",
                    t->Id, t->Estado, t->FuerzaSosten, t->Duracion));
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
                TareaSostenerModel^ t = gcnew TareaSostenerModel(
                    Int32::Parse(c[0]), Double::Parse(c[2]), Int32::Parse(c[3]));
                t->Estado = c[1];
                repositorio->Add(t);
            }
            sr->Close();
        }
    };
}