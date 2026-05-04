#pragma once
using namespace System;
using namespace System::Collections::Generic;
using namespace GemeloDigitalModel;

namespace GemeloDigitalController {

    // RegistroEventos se define aqui directamente — no es una clase del Model
    public ref class RegistroEventos {
    private:
        List<EventoModel^>^ historial;

    public:
        RegistroEventos() {
            historial = gcnew List<EventoModel^>();
        }

        List<EventoModel^>^ getHistorial() { return historial; }
        int getTotalEventos() { return historial->Count; }

        void agregarEvento(EventoModel^ e) { historial->Add(e); }

        void dataReport() {
            Console::WriteLine("=== REGISTRO DE EVENTOS ===");
            Console::WriteLine("Total: " + historial->Count + " eventos");
            for each (EventoModel ^ e in historial) {
                e->dataReport();
                Console::WriteLine("");
            }
        }
    };

    public ref class RegistroEventosController {
    private:
        List<RegistroEventos^>^ repositorio;

    public:
        RegistroEventosController() {
            repositorio = gcnew List<RegistroEventos^>();
        }

        // CREATE
        bool agregar(int id) {
            RegistroEventos^ r = buscarPorId(id);
            if (r == nullptr) {
                repositorio->Add(gcnew RegistroEventos());
                return true;
            }
            return false;
        }

        // READ - por ID
        RegistroEventos^ buscarPorId(int id) {
            if (id >= 0 && id < repositorio->Count)
                return repositorio[id];
            return nullptr;
        }

        // READ - todos
        List<RegistroEventos^>^ obtenerTodos() {
            return repositorio;
        }

        // Agregar evento al registro
        bool agregarEvento(int idRegistro, EventoModel^ evento) {
            RegistroEventos^ r = buscarPorId(idRegistro);
            if (r != nullptr && evento != nullptr) {
                r->agregarEvento(evento);
                return true;
            }
            return false;
        }

        // DELETE
        bool eliminar(int id) {
            RegistroEventos^ r = buscarPorId(id);
            if (r != nullptr) {
                repositorio->Remove(r);
                return true;
            }
            return false;
        }
    };
}