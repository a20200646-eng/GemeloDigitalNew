#pragma once
using namespace System;
using namespace System::Collections::Generic;
using namespace GemeloDigitalModel;

namespace GemeloDigitalController {

    public ref class AdministradorController {
    private:
        List<AdministradorModel^>^ repositorio;

    public:
        AdministradorController() {
            repositorio = gcnew List<AdministradorModel^>();
        }

        // CREATE
        bool agregar(int id, String^ nombre, String^ contrasena, int nivelAcceso) {
            AdministradorModel^ a = buscarPorId(id);
            if (a == nullptr) {
                repositorio->Add(gcnew AdministradorModel(id, nombre, contrasena, nivelAcceso));
                return true;
            }
            return false;
        }

        // READ - por ID
        AdministradorModel^ buscarPorId(int id) {
            for each (AdministradorModel ^ a in repositorio) {
                if (a->getId() == id) return a;
            }
            return nullptr;
        }

        // READ - todos
        List<AdministradorModel^>^ obtenerTodos() {
            return repositorio;
        }

        // UPDATE - N: nombre | C: contrasena | NA: nivelAcceso
        bool modificar(int id, String^ opcion, String^ valor) {
            AdministradorModel^ a = buscarPorId(id);
            if (a != nullptr) {
                if (opcion->Equals("N"))       a->setNombre(valor);
                else if (opcion->Equals("C"))  a->setContrasena(valor);
                else if (opcion->Equals("NA")) a->setNivelAcceso(Convert::ToInt32(valor));
                else return false;
                return true;
            }
            return false;
        }

        // DELETE
        bool eliminar(int id) {
            AdministradorModel^ a = buscarPorId(id);
            if (a != nullptr) {
                repositorio->Remove(a);
                return true;
            }
            return false;
        }
    };
}