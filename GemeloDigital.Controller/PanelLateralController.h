#pragma once
using namespace System;
using namespace System::Collections::Generic;
using namespace System::IO;
using namespace GemeloDigitalModel;

namespace GemeloDigitalController {

    public ref class PanelLateralController {
    private:
        List<PanelLateralModel^>^ repositorio;
        static String^ RUTA = "datos\\paneles_laterales.dat";

    public:
        PanelLateralController() {
            repositorio = gcnew List<PanelLateralModel^>();
            cargarArchivo();
        }

        // CREATE
        bool agregar(int id, String^ material, double peso,
            LadoPanel lado, int puntosAnclaje) {
            if (buscarPorId(id) != nullptr) return false;
            repositorio->Add(gcnew PanelLateralModel(
                id, material, peso, lado, puntosAnclaje));
            guardarArchivo();
            return true;
        }

        // READ - por ID
        PanelLateralModel^ buscarPorId(int id) {
            for each (PanelLateralModel ^ p in repositorio)
                if (p->Id == id) return p;
            return nullptr;
        }

        // READ - todos
        List<PanelLateralModel^>^ obtenerTodos() {
            return repositorio;
        }

        // UPDATE - reemplaza todos los atributos modificables
        // Lado no se modifica — es estructural igual que Tipo en PiezaModel
        bool modificar(int id, String^ material, double peso,
            EstadoPieza estado, int puntosAnclaje) {
            PanelLateralModel^ p = buscarPorId(id);
            if (p == nullptr) return false;
            p->Material = material;
            p->Peso = peso;
            p->Estado = estado;
            p->PuntosAnclaje = puntosAnclaje;
            guardarArchivo();
            return true;
        }

        // DELETE
        bool eliminar(int id) {
            PanelLateralModel^ p = buscarPorId(id);
            if (p == nullptr) return false;
            repositorio->Remove(p);
            guardarArchivo();
            return true;
        }

        // Formato: id|material|peso|estado|lado|puntosAnclaje
        void guardarArchivo() {
            Directory::CreateDirectory("datos");
            StreamWriter^ sw = gcnew StreamWriter(RUTA, false, Text::Encoding::UTF8);
            for each (PanelLateralModel ^ p in repositorio)
                sw->WriteLine(String::Format("{0}|{1}|{2}|{3}|{4}|{5}",
                    p->Id, p->Material, p->Peso,
                    (int)p->Estado, (int)p->Lado, p->PuntosAnclaje));
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
                PanelLateralModel^ p = gcnew PanelLateralModel(
                    Int32::Parse(c[0]), c[1], Double::Parse(c[2]),
                    (LadoPanel)Int32::Parse(c[4]), Int32::Parse(c[5]));
                p->Estado = (EstadoPieza)Int32::Parse(c[3]);
                repositorio->Add(p);
            }
            sr->Close();
        }
    };
}