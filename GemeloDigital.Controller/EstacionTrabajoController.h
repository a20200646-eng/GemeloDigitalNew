#pragma once
using namespace System;
using namespace System::Collections::Generic;
using namespace System::IO;
using namespace GemeloDigitalModel;

namespace GemeloDigitalController {

    public ref class EstacionTrabajoController {
    private:
        List<EstacionTrabajoModel^>^ repositorio;
        static String^ RUTA = "datos\\estaciones_trabajo.dat";

    public:
        EstacionTrabajoController() {
            repositorio = gcnew List<EstacionTrabajoModel^>();
            cargarArchivo();
        }

        // CREATE
        bool agregar(String^ id, TipoEstacion tipo, int cantidadPiezas) {
            if (buscarPorId(id) != nullptr) return false;
            repositorio->Add(gcnew EstacionTrabajoModel(id, tipo, cantidadPiezas));
            guardarArchivo();
            return true;
        }

        // READ - por ID
        EstacionTrabajoModel^ buscarPorId(String^ id) {
            for each (EstacionTrabajoModel ^ e in repositorio)
                if (e->Id->Equals(id)) return e;
            return nullptr;
        }
		//READ - por tipo (devuelve la primera estación del tipo que tenga piezas disponibles)
        EstacionTrabajoModel^ buscarPorTipo(TipoEstacion tipo) {
            for each (EstacionTrabajoModel ^ e in repositorio)
                if (e->Tipo == tipo && e->CantidadPiezas > 0) return e;
            return nullptr;
        }

        // READ - todos
        List<EstacionTrabajoModel^>^ obtenerTodos() {
            return repositorio;
        }

        // UPDATE - reemplaza todos los atributos modificables
        bool modificar(String^ id, TipoEstacion tipo, int cantidadPiezas) {
            EstacionTrabajoModel^ e = buscarPorId(id);
            if (e == nullptr) return false;
            e->Tipo = tipo;
            e->CantidadPiezas = cantidadPiezas;
            guardarArchivo();
            return true;
        }



        // DELETE
        bool eliminar(String^ id) {
            EstacionTrabajoModel^ e = buscarPorId(id);
            if (e == nullptr) return false;
            repositorio->Remove(e);
            guardarArchivo();
            return true;
        }

        // Formato: id|tipoPiezaAceptada|ocupada
        void guardarArchivo() {
            Directory::CreateDirectory("datos");
            StreamWriter^ sw = gcnew StreamWriter(RUTA, false, Text::Encoding::UTF8);
            for each (EstacionTrabajoModel ^ e in repositorio)
                sw->WriteLine(String::Format("{0}|{1}|{2}",
                    e->Id, (int)e->Tipo, e->CantidadPiezas));
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

                String^ id = c[0]->Trim();
                String^ tipoStr = c[1]->Trim();
                String^ cantStr = c[2]->Trim();

                // Parsear tipo: primero intentar entero, si falla intentar nombre del enum
                TipoEstacion tipo;
                int tipoInt;
                if (Int32::TryParse(tipoStr, tipoInt)) {
                    tipo = (TipoEstacion)tipoInt;
                }
                else {
                    try {
                        tipo = (TipoEstacion)Enum::Parse(TipoEstacion::typeid, tipoStr);
                    }
                    catch (Exception^) {
                        // Línea con tipo inválido, saltarla
                        continue;
                    }
                }

                // Parsear cantidad de piezas
                int cantidad;
                if (!Int32::TryParse(cantStr, cantidad)) {
                    // Línea con cantidad inválida, saltarla
                    continue;
                }

                repositorio->Add(gcnew EstacionTrabajoModel(id, tipo, cantidad));
            }
            sr->Close();
        }
    };
}