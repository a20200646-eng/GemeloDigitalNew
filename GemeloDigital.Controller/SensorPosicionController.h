#pragma once
using namespace System;
using namespace System::Collections::Generic;
using namespace GemeloDigitalModel;

namespace GemeloDigitalController {

    public ref class SensorPosicionController {
    private:
        List<SensorPosicionModel^>^ repositorio;

    public:
        SensorPosicionController() {
            repositorio = gcnew List<SensorPosicionModel^>();
        }

        // CREATE
        bool agregar(int id, String^ nombre, bool activo,
            double anguloMedido, double tolerancia) {
            SensorPosicionModel^ s = buscarPorId(id);
            if (s == nullptr) {
                repositorio->Add(gcnew SensorPosicionModel(
                    id, nombre, activo, anguloMedido, tolerancia));
                return true;
            }
            return false;
        }

        // READ - por ID
        SensorPosicionModel^ buscarPorId(int id) {
            for each (SensorPosicionModel ^ s in repositorio) {
                if (s->getId() == id) return s;
            }
            return nullptr;
        }

        // READ - todos
        List<SensorPosicionModel^>^ obtenerTodos() {
            return repositorio;
        }

        // UPDATE - N: nombre | A: activo | AM: anguloMedido | T: tolerancia
        bool modificar(int id, String^ opcion, String^ valor) {
            SensorPosicionModel^ s = buscarPorId(id);
            if (s != nullptr) {
                if (opcion->Equals("N"))       s->setNombre(valor);
                else if (opcion->Equals("A"))  s->setActivo(valor->Equals("true"));
                else if (opcion->Equals("AM")) s->setAnguloMedido(Convert::ToDouble(valor));
                else if (opcion->Equals("T"))  s->setTolerancia(Convert::ToDouble(valor));
                else return false;
                return true;
            }
            return false;
        }

        // DELETE
        bool eliminar(int id) {
            SensorPosicionModel^ s = buscarPorId(id);
            if (s != nullptr) {
                repositorio->Remove(s);
                return true;
            }
            return false;
        }
    };
}