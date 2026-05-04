#pragma once
using namespace System;
using namespace System::Collections::Generic;
using namespace GemeloDigitalModel;

namespace GemeloDigitalController {

    public ref class EstacionTrabajoController {
    private:
        List<EstacionTrabajoModel^>^ repositorio;

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
    };
}