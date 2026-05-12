#pragma once
using namespace System;
using namespace System::Collections::Generic;
using namespace GemeloDigitalModel;

using namespace System::IO; // Para manejo de archivos (si se decide implementar persistencia en archivos)

namespace GemeloDigitalController {

    public ref class OperadorController {
    private:
        List<OperadorModel^>^ repositorio;
		static String^ RUTA = "datos\\operadores.dat"; // Ruta para persistencia

    public:



        OperadorController() {
            repositorio = gcnew List<OperadorModel^>();
        }

        // CREATE
        bool agregar(int id, String^ nombre, String^ contrasena, String^ turno) {
            OperadorModel^ o = buscarPorId(id);
            if (o == nullptr) {
                repositorio->Add(gcnew OperadorModel(id, nombre, contrasena, turno));
                return true;
            }
            return false;
        }

        // READ - por ID
        OperadorModel^ buscarPorId(int id) {
            for each (OperadorModel ^ o in repositorio) {
                if (o->getId() == id) return o;
            }
            return nullptr;
        }

        // READ - todos
        List<OperadorModel^>^ obtenerTodos() {
            return repositorio;
        }

        // UPDATE - N: nombre | C: contrasena | T: turno
        bool modificar(int id, String^ opcion, String^ valor) {
            OperadorModel^ o = buscarPorId(id);
            if (o != nullptr) {
                if (opcion->Equals("N"))      o->setNombre(valor);
                else if (opcion->Equals("C")) o->setContrasena(valor);
                else if (opcion->Equals("T")) o->setTurno(valor);
                else return false;
                return true;
            }
            return false;
        }

        // DELETE
        bool eliminar(int id) {
            OperadorModel^ o = buscarPorId(id);
            if (o != nullptr) {
                repositorio->Remove(o);
                return true;
            }
            return false;
        }

        void guardarArchivo() {
            Directory::CreateDirectory("datos");
            StreamWriter^ sw = gcnew StreamWriter(RUTA, false, Text::Encoding::UTF8);
            for each (OperadorModel ^ o in repositorio)
                sw->WriteLine(String::Format("{0}|{1}|{2}|{3}",
                    o->getId(), o->getNombre(), o->getContrasena(), o->getTurno()));
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
                repositorio->Add(gcnew OperadorModel(
                    Int32::Parse(c[0]), c[1], c[2], c[3]));
            }
            sr->Close();
        }

    };
}
