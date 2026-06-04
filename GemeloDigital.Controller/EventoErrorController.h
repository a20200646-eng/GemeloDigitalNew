#pragma once
using namespace System;
using namespace System::Collections::Generic;
using namespace System::IO;
using namespace GemeloDigitalModel;

namespace GemeloDigitalController {

    public ref class EventoErrorController {
    private:
        List<EventoErrorModel^>^ repositorio;
        static String^ RUTA = "datos\\eventos_error.dat";

    public:
        EventoErrorController() {
            repositorio = gcnew List<EventoErrorModel^>();
            cargarArchivo();
        }

        // CREATE
        bool agregar(String^ id, String^ timestamp, String^ descripcion,
            String^ codigoError, String^ fase) {
            if (buscarPorId(id) != nullptr) return false;
            repositorio->Add(gcnew EventoErrorModel(
                id, timestamp, descripcion, codigoError, fase));
            guardarArchivo();
            return true;
        }

        // READ - por ID
        EventoErrorModel^ buscarPorId(String^ id) {
            for each (EventoErrorModel ^ e in repositorio)
                if (e->Id->Equals(id)) return e;
            return nullptr;
        }

        // READ - todos
        List<EventoErrorModel^>^ obtenerTodos() {
            return repositorio;
        }

        // UPDATE - reemplaza atributos modificables
        // Timestamp es inmutable — identifica cuándo ocurrió el error
        bool modificar(String^ id, String^ descripcion, String^ codigoError, String^ fase) {
            EventoErrorModel^ e = buscarPorId(id);
            if (e == nullptr) return false;
            e->Descripcion = descripcion;
            e->CodigoError = codigoError;
            e->Fase = fase;
            guardarArchivo();
            return true;
        }

        // DELETE
        bool eliminar(String^ id) {
            EventoErrorModel^ e = buscarPorId(id);
            if (e == nullptr) return false;
            repositorio->Remove(e);
            guardarArchivo();
            return true;
        }

        // Formato: id|timestamp|descripcion|codigoError|fase
        void guardarArchivo() {
            Directory::CreateDirectory("datos");
            StreamWriter^ sw = gcnew StreamWriter(RUTA, false, Text::Encoding::UTF8);
            for each (EventoErrorModel ^ e in repositorio)
                sw->WriteLine(String::Format("{0}|{1}|{2}|{3}|{4}",
                    e->Id, e->Timestamp, e->Descripcion,
                    e->CodigoError, e->Fase));
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
                repositorio->Add(gcnew EventoErrorModel(
                    c[0], c[1], c[2], c[3], c[4]));
            }
            sr->Close();
        }
    };
}