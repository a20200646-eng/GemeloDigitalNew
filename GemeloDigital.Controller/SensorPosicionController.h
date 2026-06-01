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
            cargarArchivo();
        }

        // CREATE
        bool agregar(int id, String^ nombre, bool activo,
            double anguloMedido, double tolerancia) {
            if (buscarPorId(id) != nullptr) return false;
            repositorio->Add(gcnew SensorPosicionModel(
                id, nombre, activo, anguloMedido, tolerancia));
            guardarArchivo();
            return true;
        }

        // READ - por ID
        SensorPosicionModel^ buscarPorId(int id) {
            for each (SensorPosicionModel ^ s in repositorio)
                if (s->Id == id) return s;
            return nullptr;
        }

        // READ - todos
        List<SensorPosicionModel^>^ obtenerTodos() {
            return repositorio;
        }

        // UPDATE - reemplaza todos los atributos modificables
        bool modificar(int id, String^ nombre, bool activo,
            double anguloMedido, double tolerancia) {
            SensorPosicionModel^ s = buscarPorId(id);
            if (s == nullptr) return false;
            s->Nombre = nombre;
            s->Activo = activo;
            s->AnguloMedido = anguloMedido;
            s->Tolerancia = tolerancia;
            guardarArchivo();
            return true;
        }

        // DELETE
        bool eliminar(int id) {
            SensorPosicionModel^ s = buscarPorId(id);
            if (s == nullptr) return false;
            repositorio->Remove(s);
            guardarArchivo();
            return true;
        }

        // Formato: id|nombre|activo|anguloMedido|tolerancia
        void guardarArchivo() {
            Directory::CreateDirectory("datos");
            StreamWriter^ sw = gcnew StreamWriter(RUTA, false, Text::Encoding::UTF8);
            for each (SensorPosicionModel ^ s in repositorio)
                sw->WriteLine(String::Format("{0}|{1}|{2}|{3}|{4}",
                    s->Id, s->Nombre, (s->Activo ? 1 : 0),
                    s->AnguloMedido, s->Tolerancia));
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
                repositorio->Add(gcnew SensorPosicionModel(
                    Int32::Parse(c[0]), c[1], c[2]->Equals("1"),
                    Double::Parse(c[3]), Double::Parse(c[4])));
            }
            sr->Close();
        }
    };
}