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
            cargarArchivo();
        }

        // CREATE
        bool agregar(int id, String^ nombre, bool activo,
            double anguloActual, double anguloMinimo, double anguloMaximo) {
            if (buscarPorId(id) != nullptr) return false;
            repositorio->Add(gcnew ArticulacionModel(
                id, nombre, activo, anguloActual, anguloMinimo, anguloMaximo));
            guardarArchivo();
            return true;
        }

        // READ - por ID
        ArticulacionModel^ buscarPorId(int id) {
            for each (ArticulacionModel ^ a in repositorio)
                if (a->Id == id) return a;
            return nullptr;
        }

        // READ - todos
        List<ArticulacionModel^>^ obtenerTodos() {
            return repositorio;
        }

        // UPDATE - reemplaza todos los atributos modificables
        bool modificar(int id, String^ nombre, bool activo,
            double anguloActual, double anguloMinimo, double anguloMaximo) {
            ArticulacionModel^ a = buscarPorId(id);
            if (a == nullptr) return false;
            a->Nombre = nombre;
            a->Activo = activo;
            a->AnguloActual = anguloActual;
            a->AnguloMinimo = anguloMinimo;
            a->AnguloMaximo = anguloMaximo;
            guardarArchivo();
            return true;
        }

        // DELETE
        bool eliminar(int id) {
            ArticulacionModel^ a = buscarPorId(id);
            if (a == nullptr) return false;
            repositorio->Remove(a);
            guardarArchivo();
            return true;
        }

        // Formato: id|nombre|activo|anguloActual|anguloMinimo|anguloMaximo
        void guardarArchivo() {
            Directory::CreateDirectory("datos");
            StreamWriter^ sw = gcnew StreamWriter(RUTA, false, Text::Encoding::UTF8);
            for each (ArticulacionModel ^ a in repositorio)
                sw->WriteLine(String::Format("{0}|{1}|{2}|{3}|{4}|{5}",
                    a->Id, a->Nombre, (a->Activo ? 1 : 0),
                    a->AnguloActual, a->AnguloMinimo, a->AnguloMaximo));
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
                repositorio->Add(gcnew ArticulacionModel(
                    Int32::Parse(c[0]), c[1], c[2]->Equals("1"),
                    Double::Parse(c[3]), Double::Parse(c[4]), Double::Parse(c[5])));
            }
            sr->Close();
        }
    };
}