#pragma once
using namespace System;
using namespace System::Collections::Generic;
using namespace GemeloDigitalModel;

namespace GemeloDigitalController {

    public ref class ArticulacionController {
    private:
        List<ArticulacionModel^>^ repositorio;

    public:
        ArticulacionController() {
            repositorio = gcnew List<ArticulacionModel^>();
        }

        // CREATE
        bool agregar(int id, String^ nombre, bool activo,
            double anguloActual, double anguloMinimo, double anguloMaximo) {
            ArticulacionModel^ art = buscarPorId(id);
            if (art == nullptr) {
                repositorio->Add(gcnew ArticulacionModel(
                    id, nombre, activo, anguloActual, anguloMinimo, anguloMaximo));
                return true;
            }
            return false;
        }

        // READ - por ID
        ArticulacionModel^ buscarPorId(int id) {
            for each (ArticulacionModel ^ a in repositorio) {
                if (a->getId() == id) return a;
            }
            return nullptr;
        }

        // READ - todos
        List<ArticulacionModel^>^ obtenerTodos() {
            return repositorio;
        }

        // UPDATE - A: activo | N: nombre | AA: anguloActual | AMI: anguloMinimo | AMA: anguloMaximo
        bool modificar(int id, String^ opcion, String^ valor) {
            ArticulacionModel^ art = buscarPorId(id);
            if (art != nullptr) {
                if (opcion->Equals("N"))        art->setNombre(valor);
                else if (opcion->Equals("A"))   art->setActivo(valor->Equals("true"));
                else if (opcion->Equals("AA"))  art->setAnguloActual(Convert::ToDouble(valor));
                else if (opcion->Equals("AMI")) art->setAnguloMinimo(Convert::ToDouble(valor));
                else if (opcion->Equals("AMA")) art->setAnguloMaximo(Convert::ToDouble(valor));
                else return false;
                return true;
            }
            return false;
        }

        // DELETE
        bool eliminar(int id) {
            ArticulacionModel^ art = buscarPorId(id);
            if (art != nullptr) {
                repositorio->Remove(art);
                return true;
            }
            return false;
        }
    };
}