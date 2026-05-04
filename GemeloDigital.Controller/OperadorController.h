#pragma once
using namespace System;
using namespace System::Collections::Generic;
using namespace GemeloDigitalModel;

namespace GemeloDigitalController {

    public ref class OperadorController {
    private:
        List<OperadorModel^>^ repositorio;

    public:
        OperadorController() {
            repositorio = gcnew List<OperadorModel^>();
        }

        // CREATE
        bool agregar(int id, String^ nombre, String^ contrasena, String^ turno) {
            OperadorModel^ o = buscarPorId(id);
            if (o == nullptr) {
                repositorio->Add(gcnew OperadorModel(id, nombre, contrasena, turno));
                return true;
            }
            return false;
        }

        // READ - por ID
        OperadorModel^ buscarPorId(int id) {
            for each (OperadorModel ^ o in repositorio) {
                if (o->getId() == id) return o;
            }
            return nullptr;
        }

        // READ - todos
        List<OperadorModel^>^ obtenerTodos() {
            return repositorio;
        }

        // UPDATE - N: nombre | C: contrasena | T: turno
        bool modificar(int id, String^ opcion, String^ valor) {
            OperadorModel^ o = buscarPorId(id);
            if (o != nullptr) {
                if (opcion->Equals("N"))      o->setNombre(valor);
                else if (opcion->Equals("C")) o->setContrasena(valor);
                else if (opcion->Equals("T")) o->setTurno(valor);
                else return false;
                return true;
            }
            return false;
        }

        // DELETE
        bool eliminar(int id) {
            OperadorModel^ o = buscarPorId(id);
            if (o != nullptr) {
                repositorio->Remove(o);
                return true;
            }
            return false;
        }
    };
}
