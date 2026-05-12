#pragma once
using namespace System;
using namespace System::Collections::Generic;
using namespace System::IO;
using namespace GemeloDigitalModel;

namespace GemeloDigitalController {
    // ============================================================
    // EventoAlertaController
    // Formato: id|timestamp|descripcion|brazoId|tipoAlerta
    // (nivel siempre ALERTA)
    // ============================================================

    public ref class EventoAlertaController {
    private:
        List<EventoAlertaModel^>^ repositorio;
        static String^ RUTA = "datos\\eventos_alerta.dat";


    public:
        EventoAlertaController() {
            repositorio = gcnew List<EventoAlertaModel^>();
        }

        // CREATE
        bool agregar(int id, String^ timestamp, String^ descripcion,
            int brazoId, String^ tipoAlerta) {
            EventoAlertaModel^ e = buscarPorId(id);
            if (e == nullptr) {
                repositorio->Add(gcnew EventoAlertaModel(
                    id, timestamp, descripcion, brazoId, tipoAlerta));
                return true;
            }
            return false;
        }

        // READ - por ID
        EventoAlertaModel^ buscarPorId(int id) {
            for each (EventoAlertaModel ^ e in repositorio) {
                if (e->getId() == id) return e;
            }
            return nullptr;
        }

        // READ - todos
        List<EventoAlertaModel^>^ obtenerTodos() {
            return repositorio;
        }

        // UPDATE - D: descripcion | T: tipoAlerta
        bool modificar(int id, String^ opcion, String^ valor) {
            EventoAlertaModel^ e = buscarPorId(id);
            if (e != nullptr) {
                if (opcion->Equals("D"))      e->setDescripcion(valor);
                else if (opcion->Equals("T")) e->setTipoAlerta(valor);
                else return false;
                return true;
            }
            return false;
        }

        // DELETE
        bool eliminar(int id) {
            EventoAlertaModel^ e = buscarPorId(id);
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
            for each(EventoAlertaModel ^ e in repositorio)
                sw->WriteLine(String::Format("{0}|{1}|{2}|{3}|{4}",
                    e->getId(), e->getTimestamp(), e->getDescripcion(),
                    e->getBrazoId(), e->getTipoAlerta()));
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
                    Int32::Parse(c[0]), c[1], c[2], Int32::Parse(c[3]), c[4]));
            }
            sr->Close();
        }
    };
}