#pragma once
using namespace System;
using namespace System::Collections::Generic;
using namespace System::IO;
using namespace GemeloDigitalModel;

namespace GemeloDigitalController {

    public ref class ServomotorController {
    private:
        List<ServomotorModel^>^ repositorio;
        static String^ RUTA = "datos\\servomotores.dat";

    public:
        ServomotorController() {
            repositorio = gcnew List<ServomotorModel^>();
            cargarArchivo();
        }

        // CREATE
        bool agregar(String^ id, String^ nombre, bool activo,
            int pulsosPWM, double torqueMaximo, double velocidadGiro) {
            if (buscarPorId(id) != nullptr) return false;
            repositorio->Add(gcnew ServomotorModel(
                id, nombre, activo, pulsosPWM, torqueMaximo, velocidadGiro));
            guardarArchivo();
            return true;
        }

        // READ - por ID
        ServomotorModel^ buscarPorId(String^ id) {
            for each (ServomotorModel ^ s in repositorio)
                if (s->Id->Equals(id)) return s;
            return nullptr;
        }

        // READ - todos
        List<ServomotorModel^>^ obtenerTodos() {
            return repositorio;
        }

        // UPDATE - reemplaza todos los atributos modificables
        bool modificar(String^ id, String^ nombre, bool activo,
            int pulsosPWM, double torqueMaximo, double velocidadGiro) {
            ServomotorModel^ s = buscarPorId(id);
            if (s == nullptr) return false;
            s->Nombre = nombre;
            s->Activo = activo;
            s->PulsosPWM = pulsosPWM;
            s->TorqueMaximo = torqueMaximo;
            s->VelocidadGiro = velocidadGiro;
            guardarArchivo();
            return true;
        }

        // DELETE
        bool eliminar(String^ id) {
            ServomotorModel^ s = buscarPorId(id);
            if (s == nullptr) return false;
            repositorio->Remove(s);
            guardarArchivo();
            return true;
        }

        // Formato: id|nombre|activo|pulsosPWM|torqueMaximo|velocidadGiro
        void guardarArchivo() {
            Directory::CreateDirectory("datos");
            StreamWriter^ sw = gcnew StreamWriter(RUTA, false, Text::Encoding::UTF8);
            for each (ServomotorModel ^ s in repositorio)
                sw->WriteLine(String::Format("{0}|{1}|{2}|{3}|{4}|{5}",
                    s->Id, s->Nombre, (s->Activo ? 1 : 0),
                    s->PulsosPWM, s->TorqueMaximo, s->VelocidadGiro));
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
                repositorio->Add(gcnew ServomotorModel(
                    c[0], c[1], c[2]->Equals("1"),
                    Int32::Parse(c[3]), Double::Parse(c[4]), Double::Parse(c[5])));
            }
            sr->Close();
        }
    };
}