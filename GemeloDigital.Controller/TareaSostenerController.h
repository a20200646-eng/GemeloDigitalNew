#pragma once
using namespace System;
using namespace System::Collections::Generic;
using namespace GemeloDigitalModel;

namespace GemeloDigitalController {

    public ref class TareaSostenerController {
    private:
        List<TareaSostenerModel^>^ repositorio;

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
    };
}