#pragma once
using namespace System;
using namespace System::Collections::Generic;
using namespace System::IO;
using namespace GemeloDigitalModel;

namespace GemeloDigitalController {
    // ============================================================
    // EventoErrorController
    // Formato: id|timestamp|descripcion|codigoError|fase
    // (nivel siempre ERROR)
    // ============================================================

    public ref class EventoErrorController {
    private:
        List<EventoErrorModel^>^ repositorio;
        static String^ RUTA = "datos\\eventos_error.dat";


    public:
        EventoErrorController() {
            repositorio = gcnew List<EventoErrorModel^>();
        }

        // CREATE
        bool agregar(int id, String^ timestamp, String^ descripcion,
            String^ codigoError, String^ fase) {
            EventoErrorModel^ e = buscarPorId(id);
            if (e == nullptr) {
                repositorio->Add(gcnew EventoErrorModel(
                    id, timestamp, descripcion, codigoError, fase));
                return true;
            }
            return false;
        }

        // READ - por ID
        EventoErrorModel^ buscarPorId(int id) {
            for each (EventoErrorModel ^ e in repositorio) {
                if (e->getId() == id) return e;
            }
            return nullptr;
        }

        // READ - todos
        List<EventoErrorModel^>^ obtenerTodos() {
            return repositorio;
        }

        // UPDATE - D: descripcion | C: codigoError | F: fase
        bool modificar(int id, String^ opcion, String^ valor) {
            EventoErrorModel^ e = buscarPorId(id);
            if (e != nullptr) {
                if (opcion->Equals("D"))      e->setDescripcion(valor);
                else if (opcion->Equals("C")) e->setCodigoError(valor);
                else if (opcion->Equals("F")) e->setFase(valor);
                else return false;
                return true;
            }
            return false;
        }

        // DELETE
        bool eliminar(int id) {
            EventoErrorModel^ e = buscarPorId(id);
            if (e != nullptr) {
                repositorio->Remove(e);
                return true;
            }
            return false;
        }

		//PERSISTENCIA

        void guardarArchivo() {
            Directory::CreateDirectory("datos");
            StreamWriter^ sw = gcnew StreamWriter(RUTA, false, Text::Encoding::UTF8);
            for each(EventoErrorModel ^ e in repositorio)
                sw->WriteLine(String::Format("{0}|{1}|{2}|{3}|{4}",
                    e->getId(), e->getTimestamp(), e->getDescripcion(),
                    e->getCodigoError(), e->getFase()));
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
                    Int32::Parse(c[0]), c[1], c[2], c[3], c[4]));
            }
            sr->Close();
        }
    };
}