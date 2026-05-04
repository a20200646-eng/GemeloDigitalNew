#pragma once
using namespace System;
using namespace System::Collections::Generic;
using namespace GemeloDigitalModel;

namespace GemeloDigitalController {

    public ref class GestorInventarioController {
    private:
        List<GestorInventarioModel^>^ repositorio;

    public:
        GestorInventarioController() {
            repositorio = gcnew List<GestorInventarioModel^>();
        }

        // CREATE
        bool agregar(int id, String^ nombre, String^ contrasena) {
            GestorInventarioModel^ g = buscarPorId(id);
            if (g == nullptr) {
                repositorio->Add(gcnew GestorInventarioModel(id, nombre, contrasena));
                return true;
            }
            return false;
        }

        // READ - por ID
        GestorInventarioModel^ buscarPorId(int id) {
            for each (GestorInventarioModel ^ g in repositorio) {
                if (g->getId() == id) return g;
            }
            return nullptr;
        }

        // READ - todos
        List<GestorInventarioModel^>^ obtenerTodos() {
            return repositorio;
        }

        // UPDATE - N: nombre | C: contrasena | T: totalPiezasGestionadas
        bool modificar(int id, String^ opcion, String^ valor) {
            GestorInventarioModel^ g = buscarPorId(id);
            if (g != nullptr) {
                if (opcion->Equals("N"))      g->setNombre(valor);
                else if (opcion->Equals("C")) g->setContrasena(valor);
                else if (opcion->Equals("T")) g->setTotalPiezasGestionadas(Convert::ToInt32(valor));
                else return false;
                return true;
            }
            return false;
        }

        // DELETE
        bool eliminar(int id) {
            GestorInventarioModel^ g = buscarPorId(id);
            if (g != nullptr) {
                repositorio->Remove(g);
                return true;
            }
            return false;
        }
    };
}