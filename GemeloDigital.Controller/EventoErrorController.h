#pragma once
using namespace System;
using namespace System::Collections::Generic;
using namespace GemeloDigitalModel;

namespace GemeloDigitalController {

    public ref class EventoErrorController {
    private:
        List<EventoErrorModel^>^ repositorio;

    public:
        EventoErrorController() {
            repositorio = gcnew List<EventoErrorModel^>();
        }

        // CREATE
        bool agregar(int id, String^ timestamp, String^ descripcion,
            String^ codigoError, String^ fase) {
            EventoErrorModel^ e = buscarPorId(id);
            if (e == nullptr) {
                repositorio->Add(gcnew EventoErrorModel(
                    id, timestamp, descripcion, codigoError, fase));
                return true;
            }
            return false;
        }

        // READ - por ID
        EventoErrorModel^ buscarPorId(int id) {
            for each (EventoErrorModel ^ e in repositorio) {
                if (e->getId() == id) return e;
            }
            return nullptr;
        }

        // READ - todos
        List<EventoErrorModel^>^ obtenerTodos() {
            return repositorio;
        }

        // UPDATE - D: descripcion | C: codigoError | F: fase
        bool modificar(int id, String^ opcion, String^ valor) {
            EventoErrorModel^ e = buscarPorId(id);
            if (e != nullptr) {
                if (opcion->Equals("D"))      e->setDescripcion(valor);
                else if (opcion->Equals("C")) e->setCodigoError(valor);
                else if (opcion->Equals("F")) e->setFase(valor);
                else return false;
                return true;
            }
            return false;
        }

        // DELETE
        bool eliminar(int id) {
            EventoErrorModel^ e = buscarPorId(id);
            if (e != nullptr) {
                repositorio->Remove(e);
                return true;
            }
            return false;
        }
    };
}