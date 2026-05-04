#pragma once
using namespace System;
using namespace System::Collections::Generic;
using namespace GemeloDigitalModel;

namespace GemeloDigitalController {

    public ref class TareaPosicionarController {
    private:
        List<TareaPosicionarModel^>^ repositorio;

    public:
        TareaPosicionarController() {
            repositorio = gcnew List<TareaPosicionarModel^>();
        }

        // CREATE
        bool agregar(int id, double posicionObjetivo, double tolerancia) {
            TareaPosicionarModel^ t = buscarPorId(id);
            if (t == nullptr) {
                repositorio->Add(gcnew TareaPosicionarModel(id, posicionObjetivo, tolerancia));
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
    };
}