#pragma once
using namespace System;
using namespace System::Collections::Generic;
using namespace System::IO;
using namespace GemeloDigitalModel;

namespace GemeloDigitalController {

    public ref class CicloController {
    private:
        
        List<CicloModel^>^ repositorio;
        static String^ RUTA = "datos\\ciclos.dat";

    public:
        CicloController() {
            repositorio = gcnew List<CicloModel^>();
            cargarArchivo();
        }

        // CREATE
        bool agregar(String^ id, double horas, String^ estado) {
            if (buscarPorId(id) != nullptr) return false;
            repositorio->Add(gcnew CicloModel(id, horas, estado));
            guardarArchivo();
            return true;
        }

        // READ - por ID
        CicloModel^ buscarPorId(String^ id) {
            for each (CicloModel ^ c in repositorio)
                if (c->Id->Equals(id)) return c;
            return nullptr;
        }

        // READ - todos
        List<CicloModel^>^ obtenerTodos() {
            return repositorio;
        }

        // READ - solo PENDIENTES
        List<CicloModel^>^ obtenerPendientes() {
            List<CicloModel^>^ resultado = gcnew List<CicloModel^>();
            for each (CicloModel ^ c in repositorio)
                if (c->Estado->Equals("PENDIENTE")) resultado->Add(c);
            return resultado;
        }

        // UPDATE - marcar como REPORTADO
        bool marcarReportado(String^ id) {
            CicloModel^ c = buscarPorId(id);
            if (c == nullptr) return false;
            c->Estado = "REPORTADO";
            guardarArchivo();
            return true;
        }

        // Formato: id|horasTrabajadas|estado
        void guardarArchivo() {
            Directory::CreateDirectory("datos");
            StreamWriter^ sw = gcnew StreamWriter(RUTA, false, Text::Encoding::UTF8);
            for each (CicloModel ^ c in repositorio)
                sw->WriteLine(String::Format("{0}|{1}|{2}",
                    c->Id, c->HorasTrabajadas, c->Estado));
            sw->Close();
        }

        void cargarArchivo() {
            if (!File::Exists(RUTA)) return;
            repositorio->Clear();
            StreamReader^ sr = gcnew StreamReader(RUTA, Text::Encoding::UTF8);
            String^ linea;
            while ((linea = sr->ReadLine()) != nullptr) {
                if (linea->Trim()->Length == 0) continue;
                array<String^>^ c = linea->Split('|');
                if (c->Length < 3) continue;
                repositorio->Add(gcnew CicloModel(
                    c[0], Double::Parse(c[1]), c[2]));
            }
            sr->Close();
        }

		//Métodos para manejar el ciclo activo (el que se está ejecutando actualmente en la planta)
        // Ciclo activo
        static String^ RUTA_ACTIVO = "datos\\ciclo_activo.dat";

        static void guardarCicloActivo(String^ sufijo) {
            Directory::CreateDirectory("datos");
            File::WriteAllText(RUTA_ACTIVO, sufijo, Text::Encoding::UTF8);
        }

        static String^ obtenerCicloActivo() {
            if (!File::Exists(RUTA_ACTIVO)) return nullptr;
            String^ contenido = File::ReadAllText(RUTA_ACTIVO, Text::Encoding::UTF8)->Trim();
            return (contenido->Length == 0) ? nullptr : contenido;
        }

        static void limpiarCicloActivo() {
            if (File::Exists(RUTA_ACTIVO))
                File::Delete(RUTA_ACTIVO);
        }


    };
}