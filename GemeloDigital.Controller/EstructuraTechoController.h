#pragma once
using namespace System;
using namespace System::Collections::Generic;
using namespace System::IO;
using namespace GemeloDigitalModel;

namespace GemeloDigitalController {

    public ref class EstructuraTechoController {
    private:
        List<EstructuraTechoModel^>^ repositorio;
        static String^ RUTA = "datos\\estructuras_techo.dat";

    public:
        EstructuraTechoController() {
            repositorio = gcnew List<EstructuraTechoModel^>();
            cargarArchivo();
        }

        // CREATE
        bool agregar(String^ id, String^ material, double peso,
            int puntosUnion, double anchura) {
            if (buscarPorId(id) != nullptr) return false;
            repositorio->Add(gcnew EstructuraTechoModel(
                id, material, peso, puntosUnion, anchura));
            guardarArchivo();
            return true;
        }

        // READ - por ID
        EstructuraTechoModel^ buscarPorId(String^ id) {
            for each (EstructuraTechoModel ^ e in repositorio)
                if (e->Id->Equals(id)) return e;
            return nullptr;
        }

        // READ - todos
        List<EstructuraTechoModel^>^ obtenerTodos() {
            return repositorio;
        }

        // UPDATE - reemplaza todos los atributos modificables
        bool modificar(String^ id, String^ material, double peso,
            EstadoPieza estado, int puntosUnion, double anchura) {
            EstructuraTechoModel^ e = buscarPorId(id);
            if (e == nullptr) return false;
            e->Material = material;
            e->Peso = peso;
            e->Estado = estado;
            e->PuntosUnion = puntosUnion;
            e->Anchura = anchura;
            guardarArchivo();
            return true;
        }

        // DELETE
        bool eliminar(String^ id) {
            EstructuraTechoModel^ e = buscarPorId(id);
            if (e == nullptr) return false;
            repositorio->Remove(e);
            guardarArchivo();
            return true;
        }

        // Formato: id|material|peso|estado|puntosUnion|anchura
        void guardarArchivo() {
            Directory::CreateDirectory("datos");
            StreamWriter^ sw = gcnew StreamWriter(RUTA, false, Text::Encoding::UTF8);
            for each (EstructuraTechoModel ^ e in repositorio)
                sw->WriteLine(String::Format("{0}|{1}|{2}|{3}|{4}|{5}",
                    e->Id, e->Material, e->Peso,
                    (int)e->Estado, e->PuntosUnion, e->Anchura));
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
                EstructuraTechoModel^ e = gcnew EstructuraTechoModel(
                    c[0], c[1], Double::Parse(c[2]),
                    Int32::Parse(c[4]), Double::Parse(c[5]));
                e->Estado = (EstadoPieza)Int32::Parse(c[3]);
                repositorio->Add(e);
            }
            sr->Close();
        }
    };
}