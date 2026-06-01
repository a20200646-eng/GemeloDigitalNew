#pragma once
using namespace System;
using namespace System::Collections::Generic;
using namespace System::IO;
using namespace GemeloDigitalModel;

namespace GemeloDigitalController {

    public ref class EventoTareaController {
    private:
        List<EventoTareaModel^>^ repositorio;
        static String^ RUTA = "datos\\eventos_tarea.dat";

    public:
        EventoTareaController() {
            repositorio = gcnew List<EventoTareaModel^>();
            cargarArchivo();
        }

        // CREATE
        bool agregar(int id, String^ timestamp, String^ descripcion,
            int tareaId, String^ resultado) {
            if (buscarPorId(id) != nullptr) return false;
            repositorio->Add(gcnew EventoTareaModel(
                id, timestamp, descripcion, tareaId, resultado));
            guardarArchivo();
            return true;
        }

        // READ - por ID
        EventoTareaModel^ buscarPorId(int id) {
            for each (EventoTareaModel ^ e in repositorio)
                if (e->Id == id) return e;
            return nullptr;
        }

        // READ - todos
        List<EventoTareaModel^>^ obtenerTodos() {
            return repositorio;
        }

        // UPDATE - Timestamp y TareaId son inmutables
        bool modificar(int id, String^ descripcion, String^ resultado) {
            EventoTareaModel^ e = buscarPorId(id);
            if (e == nullptr) return false;
            e->Descripcion = descripcion;
            e->Resultado = resultado;
            guardarArchivo();
            return true;
        }

        // DELETE
        bool eliminar(int id) {
            EventoTareaModel^ e = buscarPorId(id);
            if (e == nullptr) return false;
            repositorio->Remove(e);
            guardarArchivo();
            return true;
        }

        // Formato: id|timestamp|descripcion|tareaId|resultado
        void guardarArchivo() {
            Directory::CreateDirectory("datos");
            StreamWriter^ sw = gcnew StreamWriter(RUTA, false, Text::Encoding::UTF8);
            for each (EventoTareaModel ^ e in repositorio)
                sw->WriteLine(String::Format("{0}|{1}|{2}|{3}|{4}",
                    e->Id, e->Timestamp, e->Descripcion,
                    e->TareaId, e->Resultado));
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
                repositorio->Add(gcnew EventoTareaModel(
                    Int32::Parse(c[0]), c[1], c[2], Int32::Parse(c[3]), c[4]));
            }
            sr->Close();
        }
    };
}