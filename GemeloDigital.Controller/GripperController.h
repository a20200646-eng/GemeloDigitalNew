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
        }

        // CREATE
        bool agregar(int id, String^ nombre, bool activo,
            double apertura, double fuerzaAgarre, bool abierto) {
            GripperModel^ g = buscarPorId(id);
            if (g == nullptr) {
                repositorio->Add(gcnew GripperModel(
                    id, nombre, activo, apertura, fuerzaAgarre, abierto));
                return true;
            }
            return false;
        }

        // READ - por ID
        GripperModel^ buscarPorId(int id) {
            for each (GripperModel ^ g in repositorio) {
                if (g->getId() == id) return g;
            }
            return nullptr;
        }

        // READ - todos
        List<GripperModel^>^ obtenerTodos() {
            return repositorio;
        }

        // UPDATE - N: nombre | A: activo | AP: apertura | F: fuerzaAgarre | AB: abierto
        bool modificar(int id, String^ opcion, String^ valor) {
            GripperModel^ g = buscarPorId(id);
            if (g != nullptr) {
                if (opcion->Equals("N"))       g->setNombre(valor);
                else if (opcion->Equals("A"))  g->setActivo(valor->Equals("true"));
                else if (opcion->Equals("AP")) g->setApertura(Convert::ToDouble(valor));
                else if (opcion->Equals("F"))  g->setFuerzaAgarre(Convert::ToDouble(valor));
                else if (opcion->Equals("AB")) g->setAbierto(valor->Equals("true"));
                else return false;
                return true;
            }
            return false;
        }

        // DELETE
        bool eliminar(int id) {
            GripperModel^ g = buscarPorId(id);
            if (g != nullptr) {
                repositorio->Remove(g);
                return true;
            }
            return false;
        }

        //PERSISTANCE
        // Formato: id|nombre|activo|apertura|fuerzaAgarre|abierto
        void guardarArchivo() {
            Directory::CreateDirectory("datos");
            StreamWriter^ sw = gcnew StreamWriter(RUTA, false, Text::Encoding::UTF8);
            for each (GripperModel ^ g in repositorio)
                sw->WriteLine(String::Format("{0}|{1}|{2}|{3}|{4}|{5}",
                    g->getId(), g->getNombre(), (g->getActivo() ? 1 : 0),
                    g->getApertura(), g->getFuerzaAgarre(), (g->getAbierto() ? 1 : 0)));
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
                GripperModel^ g = gcnew GripperModel(
					Int32::Parse(c[0]), c[1], Boolean::Parse(c[2]),
                    Double::Parse(c[3]), Double::Parse(c[4]), c[5]->Equals("1"));
                repositorio->Add(g);
            }
            sr->Close();
        }
    };
}