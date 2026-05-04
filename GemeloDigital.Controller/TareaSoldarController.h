#pragma once
using namespace System;
using namespace System::Collections::Generic;
using namespace GemeloDigitalModel;

namespace GemeloDigitalController {

    public ref class TareaSoldarController {
    private:
        List<TareaSoldarModel^>^ repositorio;

    public:
        TareaSoldarController() {
            repositorio = gcnew List<TareaSoldarModel^>();
        }

        // CREATE
        bool agregar(int id, int puntosObjetivo, double temperatura) {
            TareaSoldarModel^ t = buscarPorId(id);
            if (t == nullptr) {
                repositorio->Add(gcnew TareaSoldarModel(id, puntosObjetivo, temperatura));
                return true;
            }
            return false;
        }

        // READ - por ID
        TareaSoldarModel^ buscarPorId(int id) {
            for each (TareaSoldarModel ^ t in repositorio) {
                if (t->getId() == id) return t;
            }
            return nullptr;
        }

        // READ - todos
        List<TareaSoldarModel^>^ obtenerTodos() {
            return repositorio;
        }

        // UPDATE - E: estado | PO: puntosObjetivo | PC: puntosCompletados | T: temperatura
        bool modificar(int id, String^ opcion, String^ valor) {
            TareaSoldarModel^ t = buscarPorId(id);
            if (t != nullptr) {
                if (opcion->Equals("E"))       t->setEstado(valor);
                else if (opcion->Equals("PO")) t->setPuntosObjetivo(Convert::ToInt32(valor));
                else if (opcion->Equals("PC")) t->setPuntosCompletados(Convert::ToInt32(valor));
                else if (opcion->Equals("T"))  t->setTemperatura(Convert::ToDouble(valor));
                else return false;
                return true;
            }
            return false;
        }

        // DELETE
        bool eliminar(int id) {
            TareaSoldarModel^ t = buscarPorId(id);
            if (t != nullptr) {
                repositorio->Remove(t);
                return true;
            }
            return false;
        }
    };
}