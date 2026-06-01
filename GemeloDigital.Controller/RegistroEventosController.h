#pragma once
#include "EventoTareaController.h"
#include "EventoAlertaController.h"
#include "EventoErrorController.h"
using namespace System;
using namespace System::Collections::Generic;
using namespace System::IO;
using namespace GemeloDigitalModel;


namespace GemeloDigitalController {

    // RegistroEventos — clase auxiliar del Controller, no tiene Model
    public ref class RegistroEventos {
    private:
        List<EventoModel^>^ historial;

    public:
        RegistroEventos() {
            historial = gcnew List<EventoModel^>();
        }

        property List<EventoModel^>^ Historial {
            List<EventoModel^>^ get() { return historial; }
        }

        property int TotalEventos {
            int get() { return historial->Count; }
        }

        void agregarEvento(EventoModel^ e) { historial->Add(e); }

        void dataReport() {
            Console::WriteLine("=== REGISTRO DE EVENTOS ===");
            Console::WriteLine("Total: " + TotalEventos + " eventos");
            for each (EventoModel ^ e in Historial) {
                e->dataReport();
                Console::WriteLine("");
            }
        }
    };

    public ref class RegistroEventosController {
    private:
        List<RegistroEventos^>^ repositorio;
        // registro_historial.dat → registroIndex|tipoEvento|eventoId
        //   tipoEvento: 0=EventoTarea  1=EventoAlerta  2=EventoError
        static String^ RUTA_HIST = "datos\\registro_historial.dat";

    public:
        RegistroEventosController() {
            repositorio = gcnew List<RegistroEventos^>();
            // NOTA: cargarArchivo() requiere los 3 controllers de eventos
            // Se llama manualmente desde AppContext despues de cargarlos
        }

        // CREATE
        bool agregar(int id) {
            if (buscarPorId(id) != nullptr) return false;
            repositorio->Add(gcnew RegistroEventos());
            guardarArchivo();
            return true;
        }

        // READ - por indice
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
            if (r == nullptr || evento == nullptr) return false;
            r->agregarEvento(evento);
            guardarArchivo();
            return true;
        }

        // DELETE
        bool eliminar(int id) {
            RegistroEventos^ r = buscarPorId(id);
            if (r == nullptr) return false;
            repositorio->Remove(r);
            guardarArchivo();
            return true;
        }

        // Formato: registroIndex|tipoEvento|eventoId
        void guardarArchivo() {
            Directory::CreateDirectory("datos");
            StreamWriter^ sw = gcnew StreamWriter(RUTA_HIST, false, Text::Encoding::UTF8);
            for (int i = 0; i < repositorio->Count; i++) {
                for each (EventoModel ^ e in repositorio[i]->Historial) {
                    EventoTareaModel^ et = dynamic_cast<EventoTareaModel^>(e);
                    EventoAlertaModel^ ea = dynamic_cast<EventoAlertaModel^>(e);
                    int tipo = (et != nullptr) ? 0 : (ea != nullptr) ? 1 : 2;
                    sw->WriteLine(String::Format("{0}|{1}|{2}", i, tipo, e->Id));
                }
            }
            sw->Close();
        }

        // Requiere los 3 controllers de eventos ya cargados
        // Llamar DESPUES de EventoTareaController, EventoAlertaController
        // y EventoErrorController
        void cargarArchivo(EventoTareaController^ ctrlTarea,
            EventoAlertaController^ ctrlAlerta,
            EventoErrorController^ ctrlError) {
            if (!File::Exists(RUTA_HIST)) return;
            repositorio->Clear();

            StreamReader^ sr = gcnew StreamReader(RUTA_HIST, Text::Encoding::UTF8);
            String^ linea;
            while ((linea = sr->ReadLine()) != nullptr) {
                if (linea->Trim()->Length == 0) continue;
                array<String^>^ c = linea->Split('|');
                int idx = Int32::Parse(c[0]);
                int tipo = Int32::Parse(c[1]);
                int eventoId = Int32::Parse(c[2]);

                // Crear registros intermedios si el indice los requiere
                while (repositorio->Count <= idx)
                    repositorio->Add(gcnew RegistroEventos());

                EventoModel^ evento = nullptr;
                if (tipo == 0) evento = ctrlTarea->buscarPorId(eventoId);
                else if (tipo == 1) evento = ctrlAlerta->buscarPorId(eventoId);
                else                evento = ctrlError->buscarPorId(eventoId);

                if (evento != nullptr)
                    repositorio[idx]->agregarEvento(evento);
            }
            sr->Close();
        }
    };
}