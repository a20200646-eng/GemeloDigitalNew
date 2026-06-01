#pragma once
using namespace System;
using namespace System::Collections::Generic;
using namespace System::IO;
using namespace GemeloDigitalModel;

namespace GemeloDigitalController {

    public ref class TareaCoordinadaController {
    private:
        List<TareaCoordinadaModel^>^ repositorio;
        static String^ RUTA = "datos\\tareas_coordinadas.dat";

    public:
        TareaCoordinadaController() {
            repositorio = gcnew List<TareaCoordinadaModel^>();
            cargarArchivo();
        }

        // CREATE
        bool agregar(int id, int totalRequerido) {
            if (buscarPorId(id) != nullptr) return false;
            repositorio->Add(gcnew TareaCoordinadaModel(id, totalRequerido));
            guardarArchivo();
            return true;
        }

        // READ - por ID
        TareaCoordinadaModel^ buscarPorId(int id) {
            for each (TareaCoordinadaModel ^ t in repositorio)
                if (t->Id == id) return t;
            return nullptr;
        }

        // READ - todos
        List<TareaCoordinadaModel^>^ obtenerTodos() {
            return repositorio;
        }

        // UPDATE - reemplaza todos los atributos modificables
        bool modificar(int id, String^ estado, int totalConfirmado, int totalRequerido) {
            TareaCoordinadaModel^ t = buscarPorId(id);
            if (t == nullptr) return false;
            t->Estado = estado;
            t->TotalConfirmado = totalConfirmado;
            t->TotalRequerido = totalRequerido;
            guardarArchivo();
            return true;
        }

        // DELETE
        bool eliminar(int id) {
            TareaCoordinadaModel^ t = buscarPorId(id);
            if (t == nullptr) return false;
            repositorio->Remove(t);
            guardarArchivo();
            return true;
        }

        // Formato: id|estado|totalConfirmado|totalRequerido
        void guardarArchivo() {
            Directory::CreateDirectory("datos");
            StreamWriter^ sw = gcnew StreamWriter(RUTA, false, Text::Encoding::UTF8);
            for each (TareaCoordinadaModel ^ t in repositorio)
                sw->WriteLine(String::Format("{0}|{1}|{2}|{3}",
                    t->Id, t->Estado,
                    t->TotalConfirmado, t->TotalRequerido));
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
                TareaCoordinadaModel^ t = gcnew TareaCoordinadaModel(
                    Int32::Parse(c[0]), Int32::Parse(c[3]));
                t->Estado = c[1];
                t->TotalConfirmado = Int32::Parse(c[2]);
                repositorio->Add(t);
            }
            sr->Close();
        }
    };
}