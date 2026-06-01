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
        bool agregar(int id, String^ tipoPiezaAceptada, bool ocupada) {
            if (buscarPorId(id) != nullptr) return false;
            repositorio->Add(gcnew EstacionTrabajoModel(id, tipoPiezaAceptada, ocupada));
            guardarArchivo();
            return true;
        }

        // READ - por ID
        EstacionTrabajoModel^ buscarPorId(int id) {
            for each (EstacionTrabajoModel ^ e in repositorio)
                if (e->Id == id) return e;
            return nullptr;
        }

        // READ - todos
        List<EstacionTrabajoModel^>^ obtenerTodos() {
            return repositorio;
        }

        // UPDATE - reemplaza todos los atributos modificables
        bool modificar(int id, String^ tipoPiezaAceptada, bool ocupada) {
            EstacionTrabajoModel^ e = buscarPorId(id);
            if (e == nullptr) return false;
            e->TipoPiezaAceptada = tipoPiezaAceptada;
            e->Ocupada = ocupada;
            guardarArchivo();
            return true;
        }

        // DELETE
        bool eliminar(int id) {
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
                    e->Id, e->TipoPiezaAceptada, (e->Ocupada ? 1 : 0)));
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
                repositorio->Add(gcnew EstacionTrabajoModel(
                    Int32::Parse(c[0]), c[1], c[2]->Equals("1")));
            }
            sr->Close();
        }
    };
}