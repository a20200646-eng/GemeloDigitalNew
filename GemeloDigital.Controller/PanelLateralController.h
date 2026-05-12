#pragma once
using namespace System;
using namespace System::Collections::Generic;
using namespace System::IO;
using namespace GemeloDigitalModel;

namespace GemeloDigitalController {

    public ref class PanelLateralController {
    private:
        List<PanelLateralModel^>^ repositorio;
        static String^ RUTA = "datos\\paneles_laterales.dat";


    public:
        PanelLateralController() {
            repositorio = gcnew List<PanelLateralModel^>();
        }

        // CREATE
        bool agregar(int id, String^ material, double peso,
            LadoPanel lado, int puntosAnclaje) {
            PanelLateralModel^ p = buscarPorId(id);
            if (p == nullptr) {
                repositorio->Add(gcnew PanelLateralModel(
                    id, material, peso, lado, puntosAnclaje));
                return true;
            }
            return false;
        }

        // READ - por ID
        PanelLateralModel^ buscarPorId(int id) {
            for each (PanelLateralModel ^ p in repositorio) {
                if (p->getId() == id) return p;
            }
            return nullptr;
        }

        // READ - todos
        List<PanelLateralModel^>^ obtenerTodos() {
            return repositorio;
        }

        // UPDATE - M: material | P: peso | E: estado | PA: puntosAnclaje
        bool modificar(int id, String^ opcion, String^ valor) {
            PanelLateralModel^ p = buscarPorId(id);
            if (p != nullptr) {
                if (opcion->Equals("M"))       p->setMaterial(valor);
                else if (opcion->Equals("P"))  p->setPeso(Convert::ToDouble(valor));
                else if (opcion->Equals("PA")) p->setPuntosAnclaje(Convert::ToInt32(valor));
                else if (opcion->Equals("E")) {
                    if (valor->Equals("DISPONIBLE"))       p->setEstado(EstadoPieza::DISPONIBLE);
                    else if (valor->Equals("EN_PROCESO"))  p->setEstado(EstadoPieza::EN_PROCESO);
                    else if (valor->Equals("ENSAMBLADA"))  p->setEstado(EstadoPieza::ENSAMBLADA);
                    else if (valor->Equals("DEFECTUOSA"))  p->setEstado(EstadoPieza::DEFECTUOSA);
                    else return false;
                }
                else return false;
                return true;
            }
            return false;
        }

        // DELETE
        bool eliminar(int id) {
            PanelLateralModel^ p = buscarPorId(id);
            if (p != nullptr) {
                repositorio->Remove(p);
                return true;
            }
            return false;
        }

		// ── Persistencia ─────────────────────────────────────────
        void guardarArchivo() {
            Directory::CreateDirectory("datos");
            StreamWriter^ sw = gcnew StreamWriter(RUTA, false, Text::Encoding::UTF8);
            for each(PanelLateralModel ^ p in repositorio)
                sw->WriteLine(String::Format("{0}|{1}|{2}|{3}|{4}|{5}",
                    p->getId(), p->getMaterial(), p->getPeso(),
                    (int)p->getEstado(), (int)p->getLado(), p->getPuntosAnclaje()));
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
                PanelLateralModel^ p = gcnew PanelLateralModel(
                    Int32::Parse(c[0]), c[1], Double::Parse(c[2]),
                    (LadoPanel)Int32::Parse(c[4]), Int32::Parse(c[5]));
                p->setEstado((EstadoPieza)Int32::Parse(c[3]));
                repositorio->Add(p);
            }
            sr->Close();
        }
    };
}