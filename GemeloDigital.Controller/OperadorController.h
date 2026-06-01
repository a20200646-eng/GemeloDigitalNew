#pragma once
using namespace System;
using namespace System::Collections::Generic;
using namespace System::IO;
using namespace GemeloDigitalModel;

namespace GemeloDigitalController {

    public ref class OperadorController {
    private:
        List<OperadorModel^>^ repositorio;
        static String^ RUTA = "datos\\operadores.dat";

    public:
        OperadorController() {
            repositorio = gcnew List<OperadorModel^>();
            cargarArchivo();
        }

        // CREATE
        bool agregar(int id, String^ nombre, String^ contrasena, String^ turno) {
            if (buscarPorId(id) != nullptr) return false;
            repositorio->Add(gcnew OperadorModel(id, nombre, contrasena, turno));
            guardarArchivo();
            return true;
        }

        // READ - por ID
        OperadorModel^ buscarPorId(int id) {
            for each (OperadorModel ^ o in repositorio)
                if (o->Id == id) return o;
            return nullptr;
        }

        // READ - todos
        List<OperadorModel^>^ obtenerTodos() {
            return repositorio;
        }

        // UPDATE - reemplaza todos los atributos modificables
        bool modificar(int id, String^ nombre, String^ contrasena, String^ turno) {
            OperadorModel^ o = buscarPorId(id);
            if (o == nullptr) return false;
            o->Nombre = nombre;
            o->Contrasena = contrasena;
            o->Turno = turno;
            guardarArchivo();
            return true;
        }

        // DELETE
        bool eliminar(int id) {
            OperadorModel^ o = buscarPorId(id);
            if (o == nullptr) return false;
            repositorio->Remove(o);
            guardarArchivo();
            return true;
        }

        // Formato: id|nombre|contrasena|turno
        void guardarArchivo() {
            Directory::CreateDirectory("datos");
            StreamWriter^ sw = gcnew StreamWriter(RUTA, false, Text::Encoding::UTF8);
            for each (OperadorModel ^ o in repositorio)
                sw->WriteLine(String::Format("{0}|{1}|{2}|{3}",
                    o->Id, o->Nombre, o->Contrasena, o->Turno));
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