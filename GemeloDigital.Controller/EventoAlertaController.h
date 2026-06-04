#pragma once
using namespace System;
using namespace System::Collections::Generic;
using namespace System::IO;
using namespace GemeloDigitalModel;

namespace GemeloDigitalController {

    public ref class EventoAlertaController {
    private:
        List<EventoAlertaModel^>^ repositorio;
        static String^ RUTA = "datos\\eventos_alerta.dat";

    public:
        EventoAlertaController() {
            repositorio = gcnew List<EventoAlertaModel^>();
            cargarArchivo();
        }

        // CREATE
        bool agregar(String^ id, String^ timestamp, String^ descripcion,
            String^ brazoId, String^ tipoAlerta) {
            if (buscarPorId(id) != nullptr) return false;
            repositorio->Add(gcnew EventoAlertaModel(
                id, timestamp, descripcion, brazoId, tipoAlerta));
            guardarArchivo();
            return true;
        }

        // READ - por ID
        EventoAlertaModel^ buscarPorId(String^ id) {
            for each (EventoAlertaModel ^ e in repositorio)
                if (e->Id->Equals(id)) return e;
            return nullptr;
        }

        // READ - todos
        List<EventoAlertaModel^>^ obtenerTodos() {
            return repositorio;
        }

        // UPDATE - reemplaza atributos modificables
        // Timestamp y BrazoId son inmutables — identifican el evento
        bool modificar(String^ id, String^ descripcion, String^ tipoAlerta) {
            EventoAlertaModel^ e = buscarPorId(id);
            if (e == nullptr) return false;
            e->Descripcion = descripcion;
            e->TipoAlerta = tipoAlerta;
            guardarArchivo();
            return true;
        }

        // DELETE
        bool eliminar(String^ id) {
            EventoAlertaModel^ e = buscarPorId(id);
            if (e == nullptr) return false;
            repositorio->Remove(e);
            guardarArchivo();
            return true;
        }

        // Formato: id|timestamp|descripcion|brazoId|tipoAlerta
        void guardarArchivo() {
            Directory::CreateDirectory("datos");
            StreamWriter^ sw = gcnew StreamWriter(RUTA, false, Text::Encoding::UTF8);
            for each (EventoAlertaModel ^ e in repositorio)
                sw->WriteLine(String::Format("{0}|{1}|{2}|{3}|{4}",
                    e->Id, e->Timestamp, e->Descripcion,
                    e->BrazoId, e->TipoAlerta));
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
                repositorio->Add(gcnew EventoAlertaModel(
                    c[0], c[1], c[2],c[3], c[4]));
            }
            sr->Close();
        }
    };
}