#pragma once
using namespace System;
using namespace System::Collections::Generic;
using namespace System::IO;
using namespace GemeloDigitalModel;

namespace GemeloDigitalController {
    // ============================================================
    // TareaPosicionarController
    // Formato: id|estado|posicionObjetivo|tolerancia
    // ============================================================

    public ref class TareaPosicionarController {
    private:
        List<TareaPosicionarModel^>^ repositorio;
        static String^ RUTA = "datos\\tareas_posicionar.dat";

    public:
        TareaPosicionarController() {
            repositorio = gcnew List<TareaPosicionarModel^>();
        }

        // CREATE
        bool agregar(int id, double posicionObjetivo, double tolerancia) {
            TareaPosicionarModel^ t = buscarPorId(id);
            if (t == nullptr) {
                repositorio ->Add(gcnew TareaPosicionarModel(id, posicionObjetivo, tolerancia));
                return true;
            }
            return false;
        }

        // READ - por ID
        TareaPosicionarModel^ buscarPorId(int id) {
            for each (TareaPosicionarModel ^ t in repositorio) {
                if (t->getId() == id) return t;
            }
            return nullptr;
        }

        // READ - todos
        List<TareaPosicionarModel^>^ obtenerTodos() {
            return repositorio;
        }

        // UPDATE - E: estado | PO: posicionObjetivo | T: tolerancia
        bool modificar(int id, String^ opcion, String^ valor) {
            TareaPosicionarModel^ t = buscarPorId(id);
            if (t != nullptr) {
                if (opcion->Equals("E"))       t->setEstado(valor);
                else if (opcion->Equals("PO")) t->setPosicionObjetivo(Convert::ToDouble(valor));
                else if (opcion->Equals("T"))  t->setTolerancia(Convert::ToDouble(valor));
                else return false;
                return true;
            }
            return false;
        }

        // DELETE
        bool eliminar(int id) {
            TareaPosicionarModel^ t = buscarPorId(id);
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
            for each(TareaPosicionarModel ^ t in repositorio)
                sw->WriteLine(String::Format("{0}|{1}|{2}|{3}",
                    t->getId(), t->getEstado(), t->getPosicionObjetivo(), t->getTolerancia()));
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
                TareaPosicionarModel^ t = gcnew TareaPosicionarModel(
                    Int32::Parse(c[0]), Double::Parse(c[2]), Double::Parse(c[3]));
                t->setEstado(c[1]);
                repositorio->Add(t);
            }
            sr->Close();
        }
    };
}