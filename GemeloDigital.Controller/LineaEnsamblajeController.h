#pragma once
using namespace System;
using namespace System::Collections::Generic;
using namespace GemeloDigitalModel;

namespace GemeloDigitalController {

    public ref class LineaEnsamblajeController {
    private:
        List<LineaEnsamblajeModel^>^ repositorio;

    public:
        LineaEnsamblajeController() {
            repositorio = gcnew List<LineaEnsamblajeModel^>();
        }

        // CREATE
        bool agregar(int id) {
            LineaEnsamblajeModel^ l = buscarPorId(id);
            if (l == nullptr) {
                repositorio->Add(gcnew LineaEnsamblajeModel(id));
                return true;
            }
            return false;
        }

        // READ - por ID
        LineaEnsamblajeModel^ buscarPorId(int id) {
            for each (LineaEnsamblajeModel ^ l in repositorio) {
                if (l->getId() == id) return l;
            }
            return nullptr;
        }

        // READ - todos
        List<LineaEnsamblajeModel^>^ obtenerTodos() {
            return repositorio;
        }

        // UPDATE - I: indiceActual | S: secuenciaAprobada
        bool modificar(int id, String^ opcion, String^ valor) {
            LineaEnsamblajeModel^ l = buscarPorId(id);
            if (l != nullptr) {
                if (opcion->Equals("I"))      l->setIndiceActual(Convert::ToInt32(valor));
                else if (opcion->Equals("S")) l->setSecuenciaAprobada(valor->Equals("true"));
                else return false;
                return true;
            }
            return false;
        }

        // DELETE
        bool eliminar(int id) {
            LineaEnsamblajeModel^ l = buscarPorId(id);
            if (l != nullptr) {
                repositorio->Remove(l);
                return true;
            }
            return false;
        }

        // Agregar pieza a la linea
        bool agregarPieza(int idLinea, PiezaModel^ pieza) {
            LineaEnsamblajeModel^ l = buscarPorId(idLinea);
            if (l != nullptr && pieza != nullptr) {
                l->agregarPieza(pieza);
                return true;
            }
            return false;
        }
    };
}