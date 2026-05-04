#pragma once
using namespace System;
using namespace System::Collections::Generic;
using namespace GemeloDigitalModel;

namespace GemeloDigitalController {

    public ref class JefeOperacionesController {
    private:
        List<JefeOperacionesModel^>^ repositorio;

    public:
        JefeOperacionesController() {
            repositorio = gcnew List<JefeOperacionesModel^>();
        }

        // CREATE
        bool agregar(int id, String^ nombre, String^ contrasena, int nivelAutorizacion) {
            JefeOperacionesModel^ j = buscarPorId(id);
            if (j == nullptr) {
                repositorio->Add(gcnew JefeOperacionesModel(id, nombre, contrasena, nivelAutorizacion));
                return true;
            }
            return false;
        }

        // READ - por ID
        JefeOperacionesModel^ buscarPorId(int id) {
            for each (JefeOperacionesModel ^ j in repositorio) {
                if (j->getId() == id) return j;
            }
            return nullptr;
        }

        // READ - todos
        List<JefeOperacionesModel^>^ obtenerTodos() {
            return repositorio;
        }

        // UPDATE - N: nombre | C: contrasena | NA: nivelAutorizacion
        bool modificar(int id, String^ opcion, String^ valor) {
            JefeOperacionesModel^ j = buscarPorId(id);
            if (j != nullptr) {
                if (opcion->Equals("N"))       j->setNombre(valor);
                else if (opcion->Equals("C"))  j->setContrasena(valor);
                else if (opcion->Equals("NA")) j->setNivelAutorizacion(Convert::ToInt32(valor));
                else return false;
                return true;
            }
            return false;
        }

        // DELETE
        bool eliminar(int id) {
            JefeOperacionesModel^ j = buscarPorId(id);
            if (j != nullptr) {
                repositorio->Remove(j);
                return true;
            }
            return false;
        }
    };
}