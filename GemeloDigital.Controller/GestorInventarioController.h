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
        }

        // CREATE
        bool agregar(int id, String^ nombre, String^ contrasena) {
            GestorInventarioModel^ g = buscarPorId(id);
            if (g == nullptr) {
                repositorio->Add(gcnew GestorInventarioModel(id, nombre, contrasena));
                return true;
            }
            return false;
        }

        // READ - por ID
        GestorInventarioModel^ buscarPorId(int id) {
            for each (GestorInventarioModel ^ g in repositorio) {
                if (g->getId() == id) return g;
            }
            return nullptr;
        }

        // READ - todos
        List<GestorInventarioModel^>^ obtenerTodos() {
            return repositorio;
        }

        // UPDATE - N: nombre | C: contrasena | T: totalPiezasGestionadas
        bool modificar(int id, String^ opcion, String^ valor) {
            GestorInventarioModel^ g = buscarPorId(id);
            if (g != nullptr) {
                if (opcion->Equals("N"))      g->setNombre(valor);
                else if (opcion->Equals("C")) g->setContrasena(valor);
                else if (opcion->Equals("T")) g->setTotalPiezasGestionadas(Convert::ToInt32(valor));
                else return false;
                return true;
            }
            return false;
        }

        // DELETE
        bool eliminar(int id) {
            GestorInventarioModel^ g = buscarPorId(id);
            if (g != nullptr) {
                repositorio->Remove(g);
                return true;
            }
            return false;
        }

        // PERSIST - guardar
         // Formato: id|nombre|contrasena|totalPiezasGestionadas
        void guardarArchivo() {
            Directory::CreateDirectory("datos");
            StreamWriter^ sw = gcnew StreamWriter(RUTA, false, Text::Encoding::UTF8);
            for each (GestorInventarioModel ^ g in repositorio)
                sw->WriteLine(String::Format("{0}|{1}|{2}|{3}",
                    g->getId(), g->getNombre(), g->getContrasena(), g->getTotalPiezasGestionadas()));
            sw->Close();
        }

        // PERSIST - cargar
        void cargarArchivo() {
            if (!File::Exists(RUTA)) return;
            repositorio->Clear();
            StreamReader^ sr = gcnew StreamReader(RUTA, Text::Encoding::UTF8);
            String^ linea;
            while ((linea = sr->ReadLine()) != nullptr) {
                if (linea->Trim()->Length == 0) continue;
                array<String^>^ c = linea->Split('|');
                GestorInventarioModel^ obj = gcnew GestorInventarioModel(
                    Int32::Parse(c[0]), c[1], c[2]);

                //setear las piezas gestionadas

                obj->setTotalPiezasGestionadas(Int32::Parse(c[3]));
                repositorio->Add(obj);

            }
            sr->Close();
        }
    };
}