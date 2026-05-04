#pragma once
using namespace System;
using namespace System::Collections::Generic;
using namespace GemeloDigitalModel;

namespace GemeloDigitalController {

    public ref class EventoAlertaController {
    private:
        List<EventoAlertaModel^>^ repositorio;

    public:
        EventoAlertaController() {
            repositorio = gcnew List<EventoAlertaModel^>();
        }

        // CREATE
        bool agregar(int id, String^ timestamp, String^ descripcion,
            int brazoId, String^ tipoAlerta) {
            EventoAlertaModel^ e = buscarPorId(id);
            if (e == nullptr) {
                repositorio->Add(gcnew EventoAlertaModel(
                    id, timestamp, descripcion, brazoId, tipoAlerta));
                return true;
            }
            return false;
        }

        // READ - por ID
        EventoAlertaModel^ buscarPorId(int id) {
            for each (EventoAlertaModel ^ e in repositorio) {
                if (e->getId() == id) return e;
            }
            return nullptr;
        }

        // READ - todos
        List<EventoAlertaModel^>^ obtenerTodos() {
            return repositorio;
        }

        // UPDATE - D: descripcion | T: tipoAlerta
        bool modificar(int id, String^ opcion, String^ valor) {
            EventoAlertaModel^ e = buscarPorId(id);
            if (e != nullptr) {
                if (opcion->Equals("D"))      e->setDescripcion(valor);
                else if (opcion->Equals("T")) e->setTipoAlerta(valor);
                else return false;
                return true;
            }
            return false;
        }

        // DELETE
        bool eliminar(int id) {
            EventoAlertaModel^ e = buscarPorId(id);
            if (e != nullptr) {
                repositorio->Remove(e);
                return true;
            }
            return false;
        }
    };
}