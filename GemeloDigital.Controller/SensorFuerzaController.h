#pragma once
using namespace System;
using namespace System::Collections::Generic;
using namespace System::IO;
using namespace GemeloDigitalModel;

namespace GemeloDigitalController {

    public ref class SensorFuerzaController {
    private:
        List<SensorFuerzaModel^>^ repositorio;
        static String^ RUTA = "datos\\sensores_fuerza.dat";

    public:
        SensorFuerzaController() {
            repositorio = gcnew List<SensorFuerzaModel^>();
        }

        // CREATE
        bool agregar(int id, String^ nombre, bool activo,
            double fuerzaActual, double fuerzaMinima, double fuerzaMaxima) {
            SensorFuerzaModel^ s = buscarPorId(id);
            if (s == nullptr) {
                repositorio->Add(gcnew SensorFuerzaModel(
                    id, nombre, activo, fuerzaActual, fuerzaMinima, fuerzaMaxima));
                return true;
            }
            return false;
        }

        // READ - por ID
        SensorFuerzaModel^ buscarPorId(int id) {
            for each (SensorFuerzaModel ^ s in repositorio) {
                if (s->getId() == id) return s;
            }
            return nullptr;
        }

        // READ - todos
        List<SensorFuerzaModel^>^ obtenerTodos() {
            return repositorio;
        }

        // UPDATE - N: nombre | A: activo | FA: fuerzaActual | FMI: fuerzaMinima | FMA: fuerzaMaxima
        bool modificar(int id, String^ opcion, String^ valor) {
            SensorFuerzaModel^ s = buscarPorId(id);
            if (s != nullptr) {
                if (opcion->Equals("N"))        s->setNombre(valor);
                else if (opcion->Equals("A"))   s->setActivo(valor->Equals("true"));
                else if (opcion->Equals("FA"))  s->setFuerzaActual(Convert::ToDouble(valor));
                else if (opcion->Equals("FMI")) s->setFuerzaMinima(Convert::ToDouble(valor));
                else if (opcion->Equals("FMA")) s->setFuerzaMaxima(Convert::ToDouble(valor));
                else return false;
                return true;
            }
            return false;
        }

        // DELETE
        bool eliminar(int id) {
            SensorFuerzaModel^ s = buscarPorId(id);
            if (s != nullptr) {
                repositorio->Remove(s);
                return true;
            }
            return false;
        }

        //PERSISTANCE
        // Formato: id|nombre|activo|fuerzaActual|fuerzaMinima|fuerzaMaxima
        void guardarArchivo() {
            Directory::CreateDirectory("datos");
            StreamWriter^ sw = gcnew StreamWriter(RUTA, false, Text::Encoding::UTF8);
            for each (SensorFuerzaModel ^ s in repositorio)
                sw->WriteLine(String::Format("{0}|{1}|{2}|{3}|{4}|{5}",
                    s->getId(), s->getNombre(), (s->getActivo() ? 1 : 0),
                    s->getFuerzaActual(), s->getFuerzaMinima(), s->getFuerzaMaxima()));
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
                SensorFuerzaModel^ s = gcnew SensorFuerzaModel(
                    Int32::Parse(c[0]), c[1],Boolean::Parse(c[2]),
                    Double::Parse(c[3]), Double::Parse(c[4]), Double::Parse(c[5]));
                repositorio->Add(s);
            }
            sr->Close();
        }

    };
}