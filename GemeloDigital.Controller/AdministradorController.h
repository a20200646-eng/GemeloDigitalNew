#pragma once
using namespace System;
using namespace System::Collections::Generic;
using namespace System::IO;
using namespace GemeloDigitalModel;

namespace GemeloDigitalController {

    public ref class AdministradorController {
    private:
        List<AdministradorModel^>^ repositorio;
        static String^ RUTA = "datos\\administradores.dat";
    public:
        AdministradorController() {
            repositorio = gcnew List<AdministradorModel^>();
        }

        // CREATE
        bool agregar(int id, String^ nombre, String^ contrasena, int nivelAcceso) {
            AdministradorModel^ a = buscarPorId(id);
            if (a == nullptr) {
                repositorio->Add(gcnew AdministradorModel(id, nombre, contrasena, nivelAcceso));
                return true;
            }
            return false;
        }

        // READ - por ID
        AdministradorModel^ buscarPorId(int id) {
            for each (AdministradorModel ^ a in repositorio) {
                if (a->getId() == id) return a;
            }
            return nullptr;
        }

        // READ - todos
        List<AdministradorModel^>^ obtenerTodos() {
            return repositorio;
        }

        // UPDATE - N: nombre | C: contrasena | NA: nivelAcceso
        bool modificar(int id, String^ opcion, String^ valor) {
            AdministradorModel^ a = buscarPorId(id);
            if (a != nullptr) {
                if (opcion->Equals("N"))       a->setNombre(valor);
                else if (opcion->Equals("C"))  a->setContrasena(valor);
                else if (opcion->Equals("NA")) a->setNivelAcceso(Convert::ToInt32(valor));
                else return false;
                return true;
            }
            return false;
        }

        // DELETE
        bool eliminar(int id) {
            AdministradorModel^ a = buscarPorId(id);
            if (a != nullptr) {
                repositorio->Remove(a);
                return true;
            }
            return false;
        }

        // PERSIST - guardar
        // Formato: id|nombre|contrasena|nivelAcceso
        void guardarArchivo() {
            Directory::CreateDirectory("datos");
            StreamWriter^ sw = gcnew StreamWriter(RUTA, false, Text::Encoding::UTF8);
            for each (AdministradorModel ^ a in repositorio)
                sw->WriteLine(String::Format("{0}|{1}|{2}|{3}",
                    a->getId(), a->getNombre(), a->getContrasena(), a->getNivelAcceso()));
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
                repositorio->Add(gcnew AdministradorModel(
                    Int32::Parse(c[0]), c[1], c[2], Int32::Parse(c[3])));
            }
            sr->Close();
        }
    };
}