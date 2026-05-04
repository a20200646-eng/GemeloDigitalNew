#pragma once
using namespace System;
using namespace System::Collections::Generic;
using namespace GemeloDigitalModel;

namespace GemeloDigitalController {

    public ref class ServomotorController {
    private:
        List<ServomotorModel^>^ repositorio;

    public:
        ServomotorController() {
            repositorio = gcnew List<ServomotorModel^>();
        }

        // CREATE
        bool agregar(int id, String^ nombre, bool activo,
            int pulsosPWM, double torqueMaximo, double velocidadGiro) {
            ServomotorModel^ s = buscarPorId(id);
            if (s == nullptr) {
                repositorio->Add(gcnew ServomotorModel(
                    id, nombre, activo, pulsosPWM, torqueMaximo, velocidadGiro));
                return true;
            }
            return false;
        }

        // READ - por ID
        ServomotorModel^ buscarPorId(int id) {
            for each (ServomotorModel ^ s in repositorio) {
                if (s->getId() == id) return s;
            }
            return nullptr;
        }

        // READ - todos
        List<ServomotorModel^>^ obtenerTodos() {
            return repositorio;
        }

        // UPDATE - N: nombre | A: activo | P: pulsosPWM | T: torqueMaximo | V: velocidadGiro
        bool modificar(int id, String^ opcion, String^ valor) {
            ServomotorModel^ s = buscarPorId(id);
            if (s != nullptr) {
                if (opcion->Equals("N"))      s->setNombre(valor);
                else if (opcion->Equals("A")) s->setActivo(valor->Equals("true"));
                else if (opcion->Equals("P")) s->setPulsosPWM(Convert::ToInt32(valor));
                else if (opcion->Equals("T")) s->setTorqueMaximo(Convert::ToDouble(valor));
                else if (opcion->Equals("V")) s->setVelocidadGiro(Convert::ToDouble(valor));
                else return false;
                return true;
            }
            return false;
        }

        // DELETE
        bool eliminar(int id) {
            ServomotorModel^ s = buscarPorId(id);
            if (s != nullptr) {
                repositorio->Remove(s);
                return true;
            }
            return false;
        }
    };
}