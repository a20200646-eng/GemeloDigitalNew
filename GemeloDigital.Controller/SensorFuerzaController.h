#pragma once
using namespace System;
using namespace System::Collections::Generic;
using namespace GemeloDigitalModel;

namespace GemeloDigitalController {

    public ref class SensorFuerzaController {
    private:
        List<SensorFuerzaModel^>^ repositorio;

    public:
        SensorFuerzaController() {
            repositorio = gcnew List<SensorFuerzaModel^>();
        }

        // CREATE
        bool agregar(int id, String^ nombre, bool activo,
            double fuerzaActual, double fuerzaMinima, double fuerzaMaxima) {
            SensorFuerzaModel^ s = buscarPorId(id);
            if (s == nullptr) {
                repositorio->Add(gcnew SensorFuerzaModel(
                    id, nombre, activo, fuerzaActual, fuerzaMinima, fuerzaMaxima));
                return true;
            }
            return false;
        }

        // READ - por ID
        SensorFuerzaModel^ buscarPorId(int id) {
            for each (SensorFuerzaModel ^ s in repositorio) {
                if (s->getId() == id) return s;
            }
            return nullptr;
        }

        // READ - todos
        List<SensorFuerzaModel^>^ obtenerTodos() {
            return repositorio;
        }

        // UPDATE - N: nombre | A: activo | FA: fuerzaActual | FMI: fuerzaMinima | FMA: fuerzaMaxima
        bool modificar(int id, String^ opcion, String^ valor) {
            SensorFuerzaModel^ s = buscarPorId(id);
            if (s != nullptr) {
                if (opcion->Equals("N"))        s->setNombre(valor);
                else if (opcion->Equals("A"))   s->setActivo(valor->Equals("true"));
                else if (opcion->Equals("FA"))  s->setFuerzaActual(Convert::ToDouble(valor));
                else if (opcion->Equals("FMI")) s->setFuerzaMinima(Convert::ToDouble(valor));
                else if (opcion->Equals("FMA")) s->setFuerzaMaxima(Convert::ToDouble(valor));
                else return false;
                return true;
            }
            return false;
        }

        // DELETE
        bool eliminar(int id) {
            SensorFuerzaModel^ s = buscarPorId(id);
            if (s != nullptr) {
                repositorio->Remove(s);
                return true;
            }
            return false;
        }
    };
}