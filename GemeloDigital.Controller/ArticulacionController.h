#pragma once
using namespace System;
using namespace System::Collections::Generic;
using namespace System::IO;
using namespace GemeloDigitalModel;

namespace GemeloDigitalController {

    public ref class ArticulacionController {
    private:
        List<ArticulacionModel^>^ repositorio;
        static String^ RUTA = "datos\\articulaciones.dat";


    public:
        ArticulacionController() {
            repositorio = gcnew List<ArticulacionModel^>();
        }

        // CREATE
        bool agregar(int id, String^ nombre, bool activo,
            double anguloActual, double anguloMinimo, double anguloMaximo) {
            ArticulacionModel^ art = buscarPorId(id);
            if (art == nullptr) {
                repositorio->Add(gcnew ArticulacionModel(
                    id, nombre, activo, anguloActual, anguloMinimo, anguloMaximo));
                return true;
            }
            return false;
        }

        // READ - por ID
        ArticulacionModel^ buscarPorId(int id) {
            for each (ArticulacionModel ^ a in repositorio) {
                if (a->getId() == id) return a;
            }
            return nullptr;
        }

        // READ - todos
        List<ArticulacionModel^>^ obtenerTodos() {
            return repositorio;
        }

        // UPDATE - A: activo | N: nombre | AA: anguloActual | AMI: anguloMinimo | AMA: anguloMaximo
        bool modificar(int id, String^ opcion, String^ valor) {
            ArticulacionModel^ art = buscarPorId(id);
            if (art != nullptr) {
                if (opcion->Equals("N"))        art->setNombre(valor);
                else if (opcion->Equals("A"))   art->setActivo(valor->Equals("true"));
                else if (opcion->Equals("AA"))  art->setAnguloActual(Convert::ToDouble(valor));
                else if (opcion->Equals("AMI")) art->setAnguloMinimo(Convert::ToDouble(valor));
                else if (opcion->Equals("AMA")) art->setAnguloMaximo(Convert::ToDouble(valor));
                else return false;
                return true;
            }
            return false;
        }

        // DELETE
        bool eliminar(int id) {
            ArticulacionModel^ art = buscarPorId(id);
            if (art != nullptr) {
                repositorio->Remove(art);
                return true;
            }
            return false;
        }
        //PERSISNTANCE


        // Formato: id|nombre|activo|anguloActual|anguloMinimo|anguloMaximo
        void guardarArchivo() {
            Directory::CreateDirectory("datos");
            StreamWriter^ sw = gcnew StreamWriter(RUTA, false, Text::Encoding::UTF8);
            for each (ArticulacionModel ^ a in repositorio)
                sw->WriteLine(String::Format("{0}|{1}|{2}|{3}|{4}|{5}",
                    a->getId(), a->getNombre(), (a->getActivo() ? 1 : 0),
                    a->getAnguloActual(), a->getAnguloMinimo(), a->getAnguloMaximo()));
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
                ArticulacionModel^ a = gcnew ArticulacionModel(
                    Int32::Parse(c[0]), c[1],Boolean::Parse(c[2]),Double::Parse(c[3]), Double::Parse(c[4]), Double::Parse(c[5]));
                
                repositorio->Add(a);
            }
            sr->Close();
        }

    };
}
///HOLA