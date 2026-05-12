#pragma once
using namespace System;
using namespace System::Collections::Generic;
using namespace System::IO;
using namespace GemeloDigitalModel;

namespace GemeloDigitalController {
    // ============================================================
    // TareaSostenerController
    // Formato: id|estado|fuerzaSosten|duracion
    // ============================================================

    public ref class TareaSostenerController {
    private:
        List<TareaSostenerModel^>^ repositorio;
        static String^ RUTA = "datos\\tareas_sostener.dat";


    public:
        TareaSostenerController() {
            repositorio = gcnew List<TareaSostenerModel^>();
        }

        // CREATE
        bool agregar(int id, double fuerzaSosten, int duracion) {
            TareaSostenerModel^ t = buscarPorId(id);
            if (t == nullptr) {
                repositorio->Add(gcnew TareaSostenerModel(id, fuerzaSosten, duracion));
                return true;
            }
            return false;
        }

        // READ - por ID
        TareaSostenerModel^ buscarPorId(int id) {
            for each (TareaSostenerModel ^ t in repositorio) {
                if (t->getId() == id) return t;
            }
            return nullptr;
        }

        // READ - todos
        List<TareaSostenerModel^>^ obtenerTodos() {
            return repositorio;
        }

        // UPDATE - E: estado | F: fuerzaSosten | D: duracion
        bool modificar(int id, String^ opcion, String^ valor) {
            TareaSostenerModel^ t = buscarPorId(id);
            if (t != nullptr) {
                if (opcion->Equals("E"))      t->setEstado(valor);
                else if (opcion->Equals("F")) t->setFuerzaSosten(Convert::ToDouble(valor));
                else if (opcion->Equals("D")) t->setDuracion(Convert::ToInt32(valor));
                else return false;
                return true;
            }
            return false;
        }

        // DELETE
        bool eliminar(int id) {
            TareaSostenerModel^ t = buscarPorId(id);
            if (t != nullptr) {
                repositorio->Remove(t);
                return true;
            }
            return false;
        }

		// ── Persistencia ─────────────────────────────────────────
        void guardarArchivo() {
            Directory::CreateDirectory("datos");
            StreamWriter^ sw = gcnew StreamWriter(RUTA, false, Text::Encoding::UTF8);
            for each(TareaSostenerModel ^ t in repositorio)
                sw->WriteLine(String::Format("{0}|{1}|{2}|{3}",
                    t->getId(), t->getEstado(), t->getFuerzaSosten(), t->getDuracion()));
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
                    Int32::Parse(c[0]), Double::Parse(c[2]), Double::Parse(c[3]));
                t->setEstado(c[1]);
                repositorio->Add(t);
            }
            sr->Close();
        }
    };
}