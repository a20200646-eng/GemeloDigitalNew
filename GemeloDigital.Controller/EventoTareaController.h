#pragma once
using namespace System;
using namespace System::Collections::Generic;
using namespace System::IO;
using namespace GemeloDigitalModel;

namespace GemeloDigitalController {
    // ============================================================
    // EventoTareaController
    // Formato: id|timestamp|descripcion|tareaId|resultado
    // (nivel siempre INFO — no se guarda, se restaura en constructor)
    // ============================================================

    public ref class EventoTareaController {
    private:
        List<EventoTareaModel^>^ repositorio;
        static String^ RUTA = "datos\\eventos_tarea.dat";


    public:
        EventoTareaController() {
            repositorio = gcnew List<EventoTareaModel^>();
        }

        // CREATE
        bool agregar(int id, String^ timestamp, String^ descripcion,
            int tareaId, String^ resultado) {
            EventoTareaModel^ e = buscarPorId(id);
            if (e == nullptr) {
                repositorio->Add(gcnew EventoTareaModel(
                    id, timestamp, descripcion, tareaId, resultado));
                return true;
            }
            return false;
        }

        // READ - por ID
        EventoTareaModel^ buscarPorId(int id) {
            for each (EventoTareaModel ^ e in repositorio) {
                if (e->getId() == id) return e;
            }
            return nullptr;
        }

        // READ - todos
        List<EventoTareaModel^>^ obtenerTodos() {
            return repositorio;
        }

        // UPDATE - D: descripcion | R: resultado
        bool modificar(int id, String^ opcion, String^ valor) {
            EventoTareaModel^ e = buscarPorId(id);
            if (e != nullptr) {
                if (opcion->Equals("D"))      e->setDescripcion(valor);
                else if (opcion->Equals("R")) e->setResultado(valor);
                else return false;
                return true;
            }
            return false;
        }

        // DELETE
        bool eliminar(int id) {
            EventoTareaModel^ e = buscarPorId(id);
            if (e != nullptr) {
                repositorio->Remove(e);
                return true;
            }
            return false;
        }

		// ── Persistencia ─────────────────────────────────────────
        void guardarArchivo() {
            Directory::CreateDirectory("datos");
            StreamWriter^ sw = gcnew StreamWriter(RUTA, false, Text::Encoding::UTF8);
            for each(EventoTareaModel ^ e in repositorio)
                sw->WriteLine(String::Format("{0}|{1}|{2}|{3}|{4}",
                    e->getId(), e->getTimestamp(), e->getDescripcion(),
                    e->getTareaId(), e->getResultado()));
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