#pragma once
using namespace System;
using namespace System::Collections::Generic;
using namespace System::IO;
using namespace GemeloDigitalModel;

namespace GemeloDigitalController {

    public ref class GripperController {
    private:
        List<GripperModel^>^ repositorio;
        static String^ RUTA = "datos\\grippers.dat";

    public:
        GripperController() {
            repositorio = gcnew List<GripperModel^>();
            cargarArchivo();
        }

        // CREATE
        bool agregar(int id, String^ nombre, bool activo,
            double apertura, double fuerzaAgarre, bool abierto) {
            if (buscarPorId(id) != nullptr) return false;
            repositorio->Add(gcnew GripperModel(
                id, nombre, activo, apertura, fuerzaAgarre, abierto));
            guardarArchivo();
            return true;
        }

        // READ - por ID
        GripperModel^ buscarPorId(int id) {
            for each (GripperModel ^ g in repositorio)
                if (g->Id == id) return g;
            return nullptr;
        }

        // READ - todos
        List<GripperModel^>^ obtenerTodos() {
            return repositorio;
        }

        // UPDATE - reemplaza todos los atributos modificables
        bool modificar(int id, String^ nombre, bool activo,
            double apertura, double fuerzaAgarre, bool abierto) {
            GripperModel^ g = buscarPorId(id);
            if (g == nullptr) return false;
            g->Nombre = nombre;
            g->Activo = activo;
            g->Apertura = apertura;
            g->FuerzaAgarre = fuerzaAgarre;
            g->Abierto = abierto;
            guardarArchivo();
            return true;
        }

        // DELETE
        bool eliminar(int id) {
            GripperModel^ g = buscarPorId(id);
            if (g == nullptr) return false;
            repositorio->Remove(g);
            guardarArchivo();
            return true;
        }

        // Formato: id|nombre|activo|apertura|fuerzaAgarre|abierto
        void guardarArchivo() {
            Directory::CreateDirectory("datos");
            StreamWriter^ sw = gcnew StreamWriter(RUTA, false, Text::Encoding::UTF8);
            for each (GripperModel ^ g in repositorio)
                sw->WriteLine(String::Format("{0}|{1}|{2}|{3}|{4}|{5}",
                    g->Id, g->Nombre, (g->Activo ? 1 : 0),
                    g->Apertura, g->FuerzaAgarre, (g->Abierto ? 1 : 0)));
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
                repositorio->Add(gcnew GripperModel(
                    Int32::Parse(c[0]), c[1], c[2]->Equals("1"),
                    Double::Parse(c[3]), Double::Parse(c[4]), c[5]->Equals("1")));
            }
            sr->Close();
        }
    };
}