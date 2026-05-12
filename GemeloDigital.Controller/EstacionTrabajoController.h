#pragma once
using namespace System;
using namespace System::Collections::Generic;
using namespace System::IO;
using namespace GemeloDigitalModel;

namespace GemeloDigitalController {

    public ref class EstacionTrabajoController {
    private:
        List<EstacionTrabajoModel^>^ repositorio;
        static String^ RUTA = "datos\\estaciones_trabajo.dat";


    public:
        EstacionTrabajoController() {
            repositorio = gcnew List<EstacionTrabajoModel^>();
        }

        // CREATE
        bool agregar(int id, String^ tipoPiezaAceptada, bool ocupada) {
            EstacionTrabajoModel^ e = buscarPorId(id);
            if (e == nullptr) {
                repositorio->Add(gcnew EstacionTrabajoModel(id, tipoPiezaAceptada, ocupada));
                return true;
            }
            return false;
        }

        // READ - por ID
        EstacionTrabajoModel^ buscarPorId(int id) {
            for each (EstacionTrabajoModel ^ e in repositorio) {
                if (e->getId() == id) return e;
            }
            return nullptr;
        }

        // READ - todos
        List<EstacionTrabajoModel^>^ obtenerTodos() {
            return repositorio;
        }

        // UPDATE - T: tipoPiezaAceptada | O: ocupada
        bool modificar(int id, String^ opcion, String^ valor) {
            EstacionTrabajoModel^ e = buscarPorId(id);
            if (e != nullptr) {
                if (opcion->Equals("T"))      e->setTipoPiezaAceptada(valor);
                else if (opcion->Equals("O")) e->setOcupada(valor->Equals("true"));
                else return false;
                return true;
            }
            return false;
        }

        // DELETE
        bool eliminar(int id) {
            EstacionTrabajoModel^ e = buscarPorId(id);
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
            for each(EstacionTrabajoModel ^ e in repositorio)
                sw->WriteLine(String::Format("{0}|{1}|{2}",
                    e->getId(), e->getTipoPiezaAceptada(), (e->getOcupada() ? 1 : 0)));
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
                repositorio->Add(gcnew EstacionTrabajoModel(
                    Int32::Parse(c[0]), c[1], c[2]->Equals("1")));
            }
            sr->Close();
        }
    };
}