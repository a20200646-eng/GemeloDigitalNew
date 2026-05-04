#pragma once
using namespace System;
using namespace System::Collections::Generic;
using namespace GemeloDigitalModel;

namespace GemeloDigitalController {

    public ref class TareaCoordinadaController {
    private:
        List<TareaCoordinadaModel^>^ repositorio;

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
    };
}