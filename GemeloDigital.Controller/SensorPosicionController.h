#pragma once
using namespace System;
using namespace System::Collections::Generic;
using namespace System::IO;
using namespace GemeloDigitalModel;

namespace GemeloDigitalController {

    public ref class SensorPosicionController {
    private:
        List<SensorPosicionModel^>^ repositorio;
        static String^ RUTA = "datos\\sensores_posicion.dat";


    public:
        SensorPosicionController() {
            repositorio = gcnew List<SensorPosicionModel^>();
        }

        // CREATE
        bool agregar(int id, String^ nombre, bool activo,
            double anguloMedido, double tolerancia) {
            SensorPosicionModel^ s = buscarPorId(id);
            if (s == nullptr) {
                repositorio->Add(gcnew SensorPosicionModel(
                    id, nombre, activo, anguloMedido, tolerancia));
                return true;
            }
            return false;
        }

        // READ - por ID
        SensorPosicionModel^ buscarPorId(int id) {
            for each (SensorPosicionModel ^ s in repositorio) {
                if (s->getId() == id) return s;
            }
            return nullptr;
        }

        // READ - todos
        List<SensorPosicionModel^>^ obtenerTodos() {
            return repositorio;
        }

        // UPDATE - N: nombre | A: activo | AM: anguloMedido | T: tolerancia
        bool modificar(int id, String^ opcion, String^ valor) {
            SensorPosicionModel^ s = buscarPorId(id);
            if (s != nullptr) {
                if (opcion->Equals("N"))       s->setNombre(valor);
                else if (opcion->Equals("A"))  s->setActivo(valor->Equals("true"));
                else if (opcion->Equals("AM")) s->setAnguloMedido(Convert::ToDouble(valor));
                else if (opcion->Equals("T"))  s->setTolerancia(Convert::ToDouble(valor));
                else return false;
                return true;
            }
            return false;
        }

        // DELETE
        bool eliminar(int id) {
            SensorPosicionModel^ s = buscarPorId(id);
            if (s != nullptr) {
                repositorio->Remove(s);
                return true;
            }
            return false;
        }

        //PERSISTANCE
        // Formato: id|nombre|activo|anguloMedido|tolerancia
        void guardarArchivo() {
            Directory::CreateDirectory("datos");
            StreamWriter^ sw = gcnew StreamWriter(RUTA, false, Text::Encoding::UTF8);
            for each (SensorPosicionModel ^ s in repositorio)
                sw->WriteLine(String::Format("{0}|{1}|{2}|{3}|{4}",
                    s->getId(), s->getNombre(), (s->getActivo() ? 1 : 0),
                    s->getAnguloMedido(), s->getTolerancia()));
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
                SensorPosicionModel^ s = gcnew SensorPosicionModel(
                    Int32::Parse(c[0]), c[1], Boolean::Parse(c[2]), Double::Parse(c[3]), Double::Parse(c[4]));
                repositorio->Add(s);
            }
            sr->Close();
        }

    };
}