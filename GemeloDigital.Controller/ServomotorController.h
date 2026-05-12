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
        }

        // CREATE
        bool agregar(int id, String^ nombre, bool activo,
            int pulsosPWM, double torqueMaximo, double velocidadGiro) {
            ServomotorModel^ s = buscarPorId(id);
            if (s == nullptr) {
                repositorio->Add(gcnew ServomotorModel(
                    id, nombre, activo, pulsosPWM, torqueMaximo, velocidadGiro));
                return true;
            }
            return false;
        }

        // READ - por ID
        ServomotorModel^ buscarPorId(int id) {
            for each (ServomotorModel ^ s in repositorio) {
                if (s->getId() == id) return s;
            }
            return nullptr;
        }

        // READ - todos
        List<ServomotorModel^>^ obtenerTodos() {
            return repositorio;
        }

        // UPDATE - N: nombre | A: activo | P: pulsosPWM | T: torqueMaximo | V: velocidadGiro
        bool modificar(int id, String^ opcion, String^ valor) {
            ServomotorModel^ s = buscarPorId(id);
            if (s != nullptr) {
                if (opcion->Equals("N"))      s->setNombre(valor);
                else if (opcion->Equals("A")) s->setActivo(valor->Equals("true"));
                else if (opcion->Equals("P")) s->setPulsosPWM(Convert::ToInt32(valor));
                else if (opcion->Equals("T")) s->setTorqueMaximo(Convert::ToDouble(valor));
                else if (opcion->Equals("V")) s->setVelocidadGiro(Convert::ToDouble(valor));
                else return false;
                return true;
            }
            return false;
        }

        // DELETE
        bool eliminar(int id) {
            ServomotorModel^ s = buscarPorId(id);
            if (s != nullptr) {
                repositorio->Remove(s);
                return true;
            }
            return false;
        }

        //PERSISTANCE
        // Formato: id|nombre|activo|pulsosPWM|torqueMaximo|velocidadGiro
        void guardarArchivo() {
            Directory::CreateDirectory("datos");
            StreamWriter^ sw = gcnew StreamWriter(RUTA, false, Text::Encoding::UTF8);
            for each (ServomotorModel ^ s in repositorio)
                sw->WriteLine(String::Format("{0}|{1}|{2}|{3}|{4}|{5}",
                    s->getId(), s->getNombre(), (s->getActivo() ? 1 : 0),
                    s->getPulsosPWM(), s->getTorqueMaximo(), s->getVelocidadGiro()));
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
                ServomotorModel^ s = gcnew ServomotorModel(
                    Int32::Parse(c[0]), c[1],
                    Int32::Parse(c[3]),Boolean::Parse(c[2]), Double::Parse(c[4]), Double::Parse(c[5]));
                repositorio->Add(s);
            }
            sr->Close();
        }
    };
}