#pragma once
using namespace System;
using namespace System::Collections::Generic;
using namespace System::IO;
using namespace GemeloDigitalModel;

namespace GemeloDigitalController {
    // ============================================================
    // TareaCoordinadaController
    // Formato: id|estado|totalConfirmado|totalRequerido
    // ============================================================

    public ref class TareaCoordinadaController {
    private:
        List<TareaCoordinadaModel^>^ repositorio;
        static String^ RUTA = "datos\\tareas_coordinadas.dat";


    public:
        TareaCoordinadaController() {
            repositorio = gcnew List<TareaCoordinadaModel^>();
        }

        // CREATE
        bool agregar(int id, int totalRequerido) {
            TareaCoordinadaModel^ t = buscarPorId(id);
            if (t == nullptr) {
                repositorio->Add(gcnew TareaCoordinadaModel(id, totalRequerido));
                return true;
            }
            return false;
        }

        // READ - por ID
        TareaCoordinadaModel^ buscarPorId(int id) {
            for each (TareaCoordinadaModel ^ t in repositorio) {
                if (t->getId() == id) return t;
            }
            return nullptr;
        }

        // READ - todos
        List<TareaCoordinadaModel^>^ obtenerTodos() {
            return repositorio;
        }

        // UPDATE - E: estado | TC: totalConfirmado | TR: totalRequerido
        bool modificar(int id, String^ opcion, String^ valor) {
            TareaCoordinadaModel^ t = buscarPorId(id);
            if (t != nullptr) {
                if (opcion->Equals("E"))       t->setEstado(valor);
                else if (opcion->Equals("TC")) t->setTotalConfirmado(Convert::ToInt32(valor));
                else if (opcion->Equals("TR")) t->setTotalRequerido(Convert::ToInt32(valor));
                else return false;
                return true;
            }
            return false;
        }

        // DELETE
        bool eliminar(int id) {
            TareaCoordinadaModel^ t = buscarPorId(id);
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
            for each(TareaCoordinadaModel ^ t in repositorio)
                sw->WriteLine(String::Format("{0}|{1}|{2}|{3}",
                    t->getId(), t->getEstado(),
                    t->getTotalConfirmado(), t->getTotalRequerido()));
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
                t->setEstado(c[1]);
                t->setTotalConfirmado(Int32::Parse(c[2]));
                repositorio->Add(t);
            }
            sr->Close();
        }
    };
}