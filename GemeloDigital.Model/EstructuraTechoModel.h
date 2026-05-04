#pragma once
#include "PiezaModel.h"
using namespace System;

namespace GemeloDigitalModel {

    public ref class EstructuraTechoModel : public PiezaModel {
    private:
        int puntosUnion;
        double anchura;

    public:
        EstructuraTechoModel(int id, String^ material, double peso,
            int puntosUnion, double anchura)
            : PiezaModel(id, "Estructura Techo", material, peso, EstadoPieza::DISPONIBLE) {
            this->puntosUnion = puntosUnion;
            this->anchura = anchura;
        }

        int getPuntosUnion() { return puntosUnion; }
        double getAnchura() { return anchura; }
        void setPuntosUnion(int p) { puntosUnion = p; }
        void setAnchura(double a) { anchura = a; }

        virtual void dataReport() override {
            Console::WriteLine("=== ESTRUCTURA TECHO ===");
            Console::WriteLine("ID: " + id);
            Console::WriteLine("|Material: " + material);
            Console::WriteLine("|Peso: " + peso + " kg");
            Console::WriteLine("|Puntos de Union: " + puntosUnion);
            Console::WriteLine("|Anchura: " + anchura + " m");
            Console::WriteLine("|Estado: " + estado.ToString());
        }
    };
}