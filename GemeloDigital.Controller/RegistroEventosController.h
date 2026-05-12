#pragma once
using namespace System;
using namespace System::Collections::Generic;
using namespace System::IO;
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
        // Un solo archivo:
        // registro_historial.dat → registroIndex|tipoEvento|eventoId
        //   tipoEvento: 0=EventoTarea  1=EventoAlerta  2=EventoError
        static String^ RUTA_HIST = "datos\\registro_historial.dat";

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

        // PERSIST - guardar
        // Formato: registroIndex|tipoEvento|eventoId
        void guardarArchivo() {
            Directory::CreateDirectory("datos");
            StreamWriter^ sw = gcnew StreamWriter(RUTA_HIST, false, Text::Encoding::UTF8);

            for (int i = 0; i < repositorio->Count; i++) {
                for each (EventoModel ^ e in repositorio[i]->getHistorial()) {
                    EventoTareaModel^ et = dynamic_cast<EventoTareaModel^>(e);
                    EventoAlertaModel^ ea = dynamic_cast<EventoAlertaModel^>(e);
                    EventoErrorModel^ ee = dynamic_cast<EventoErrorModel^>(e);
                    int tipo = (et != nullptr) ? 0 : (ea != nullptr) ? 1 : 2;
                    sw->WriteLine(String::Format("{0}|{1}|{2}", i, tipo, e->getId()));
                }
            }
            sw->Close();
        }

        // PERSIST - cargar
        // Requiere los 3 controllers de eventos ya cargados.
        // El numero de registros se reconstruye automaticamente
        // a partir del indice mas alto encontrado en el archivo.
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