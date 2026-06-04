#pragma once
#include "PiezaModel.h"
using namespace System;

namespace GemeloDigitalModel {

    public ref class EstructuraTechoModel : public PiezaModel {
    private:
        int    puntosUnion;
        double anchura;

    public:
        EstructuraTechoModel(String^ id, String^ material, double peso,
            int puntosUnion, double anchura)
            : PiezaModel(id, "Estructura Techo", material, peso, EstadoPieza::DISPONIBLE) {
            this->puntosUnion = puntosUnion;
            this->anchura = anchura;
        }

        property int PuntosUnion {
            int  get() { return puntosUnion; }
            void set(int value) { puntosUnion = value; }
        }

        property double Anchura {
            double get() { return anchura; }
            void   set(double value) { anchura = value; }
        }

        virtual void dataReport() override {
            Console::WriteLine("=== ESTRUCTURA TECHO ===");
            Console::WriteLine("ID: " + Id);
            Console::WriteLine("|Material: " + Material);
            Console::WriteLine("|Peso: " + Peso + " kg");
            Console::WriteLine("|Puntos de Union: " + PuntosUnion);
            Console::WriteLine("|Anchura: " + Anchura + " m");
            Console::WriteLine("|Estado: " + Estado.ToString());
        }
    };
}