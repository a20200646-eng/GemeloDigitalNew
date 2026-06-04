#pragma once
using namespace System;
using namespace System::Collections::Generic;
using namespace System::IO;
using namespace GemeloDigitalModel;

namespace GemeloDigitalController {

    public ref class GestorInventarioController {
    private:
        List<GestorInventarioModel^>^ repositorio;
        static String^ RUTA = "datos\\gestores.dat";

    public:
        GestorInventarioController() {
            repositorio = gcnew List<GestorInventarioModel^>();
            cargarArchivo();
        }

        // CREATE
        bool agregar(String^ id, String^ nombre, String^ contrasena) {
            if (buscarPorId(id) != nullptr) return false;
            repositorio->Add(gcnew GestorInventarioModel(id, nombre, contrasena));
            guardarArchivo();
            return true;
        }

        // READ - por ID
        GestorInventarioModel^ buscarPorId(String^ id) {
            for each (GestorInventarioModel ^ g in repositorio)
                if (g->Id->Equals(id)) return g;
            return nullptr;
        }

        // READ - todos
        List<GestorInventarioModel^>^ obtenerTodos() {
            return repositorio;
        }

        // UPDATE - reemplaza todos los atributos modificables
        bool modificar(String^ id, String^ nombre, String^ contrasena, int totalPiezasGestionadas) {
            GestorInventarioModel^ g = buscarPorId(id);
            if (g == nullptr) return false;
            g->Nombre = nombre;
            g->Contrasena = contrasena;
            g->TotalPiezasGestionadas = totalPiezasGestionadas;
            guardarArchivo();
            return true;
        }

        // DELETE
        bool eliminar(String^ id) {
            GestorInventarioModel^ g = buscarPorId(id);
            if (g == nullptr) return false;
            repositorio->Remove(g);
            guardarArchivo();
            return true;
        }

        // Formato: id|nombre|contrasena|totalPiezasGestionadas
        void guardarArchivo() {
            Directory::CreateDirectory("datos");
            StreamWriter^ sw = gcnew StreamWriter(RUTA, false, Text::Encoding::UTF8);
            for each (GestorInventarioModel ^ g in repositorio)
                sw->WriteLine(String::Format("{0}|{1}|{2}|{3}",
                    g->Id, g->Nombre, g->Contrasena, g->TotalPiezasGestionadas));
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
                GestorInventarioModel^ g = gcnew GestorInventarioModel(
                    c[0], c[1], c[2]);
                g->TotalPiezasGestionadas = Int32::Parse(c[3]);
                repositorio->Add(g);
            }
            sr->Close();
        }
    };
}