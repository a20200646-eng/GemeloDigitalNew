#pragma once
using namespace System;
using namespace System::Collections::Generic;
using namespace GemeloDigitalModel;

namespace GemeloDigitalController {

    public ref class PanelLateralController {
    private:
        List<PanelLateralModel^>^ repositorio;

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
    };
}