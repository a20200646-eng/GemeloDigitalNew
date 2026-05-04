#pragma once
using namespace System;
using namespace System::Collections::Generic;
using namespace GemeloDigitalModel;

namespace GemeloDigitalController {

    public ref class GripperController {
    private:
        List<GripperModel^>^ repositorio;

    public:
        GripperController() {
            repositorio = gcnew List<GripperModel^>();
        }

        // CREATE
        bool agregar(int id, String^ nombre, bool activo,
            double apertura, double fuerzaAgarre, bool abierto) {
            GripperModel^ g = buscarPorId(id);
            if (g == nullptr) {
                repositorio->Add(gcnew GripperModel(
                    id, nombre, activo, apertura, fuerzaAgarre, abierto));
                return true;
            }
            return false;
        }

        // READ - por ID
        GripperModel^ buscarPorId(int id) {
            for each (GripperModel ^ g in repositorio) {
                if (g->getId() == id) return g;
            }
            return nullptr;
        }

        // READ - todos
        List<GripperModel^>^ obtenerTodos() {
            return repositorio;
        }

        // UPDATE - N: nombre | A: activo | AP: apertura | F: fuerzaAgarre | AB: abierto
        bool modificar(int id, String^ opcion, String^ valor) {
            GripperModel^ g = buscarPorId(id);
            if (g != nullptr) {
                if (opcion->Equals("N"))       g->setNombre(valor);
                else if (opcion->Equals("A"))  g->setActivo(valor->Equals("true"));
                else if (opcion->Equals("AP")) g->setApertura(Convert::ToDouble(valor));
                else if (opcion->Equals("F"))  g->setFuerzaAgarre(Convert::ToDouble(valor));
                else if (opcion->Equals("AB")) g->setAbierto(valor->Equals("true"));
                else return false;
                return true;
            }
            return false;
        }

        // DELETE
        bool eliminar(int id) {
            GripperModel^ g = buscarPorId(id);
            if (g != nullptr) {
                repositorio->Remove(g);
                return true;
            }
            return false;
        }
    };
}