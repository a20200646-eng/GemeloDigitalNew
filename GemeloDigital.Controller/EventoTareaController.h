#pragma once
using namespace System;
using namespace System::Collections::Generic;
using namespace GemeloDigitalModel;

namespace GemeloDigitalController {

    public ref class EventoTareaController {
    private:
        List<EventoTareaModel^>^ repositorio;

    public:
        EventoTareaController() {
            repositorio = gcnew List<EventoTareaModel^>();
        }

        // CREATE
        bool agregar(int id, String^ timestamp, String^ descripcion,
            int tareaId, String^ resultado) {
            EventoTareaModel^ e = buscarPorId(id);
            if (e == nullptr) {
                repositorio->Add(gcnew EventoTareaModel(
                    id, timestamp, descripcion, tareaId, resultado));
                return true;
            }
            return false;
        }

        // READ - por ID
        EventoTareaModel^ buscarPorId(int id) {
            for each (EventoTareaModel ^ e in repositorio) {
                if (e->getId() == id) return e;
            }
            return nullptr;
        }

        // READ - todos
        List<EventoTareaModel^>^ obtenerTodos() {
            return repositorio;
        }

        // UPDATE - D: descripcion | R: resultado
        bool modificar(int id, String^ opcion, String^ valor) {
            EventoTareaModel^ e = buscarPorId(id);
            if (e != nullptr) {
                if (opcion->Equals("D"))      e->setDescripcion(valor);
                else if (opcion->Equals("R")) e->setResultado(valor);
                else return false;
                return true;
            }
            return false;
        }

        // DELETE
        bool eliminar(int id) {
            EventoTareaModel^ e = buscarPorId(id);
            if (e != nullptr) {
                repositorio->Remove(e);
                return true;
            }
            return false;
        }
    };
}