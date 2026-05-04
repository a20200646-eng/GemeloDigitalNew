#pragma once
#include "PiezaModel.h"
using namespace System;

namespace GemeloDigitalModel {

    public ref class PanelLateralModel : public PiezaModel {
    private:
        LadoPanel lado;
        int puntosAnclaje;

    public:
        PanelLateralModel(int id, String^ material, double peso,
            LadoPanel lado, int puntosAnclaje)
            : PiezaModel(id, "Panel Lateral", material, peso, EstadoPieza::DISPONIBLE) {
            this->lado = lado;
            this->puntosAnclaje = puntosAnclaje;
        }

        LadoPanel getLado() { return lado; }
        int getPuntosAnclaje() { return puntosAnclaje; }
        void setLado(LadoPanel l) { lado = l; }
        void setPuntosAnclaje(int p) { puntosAnclaje = p; }

        virtual void dataReport() override {
            Console::WriteLine("=== PANEL LATERAL ===");
            Console::WriteLine("ID: " + id);
            Console::WriteLine("|Material: " + material);
            Console::WriteLine("|Peso: " + peso + " kg");
            Console::WriteLine("|Lado: " + lado.ToString());
            Console::WriteLine("|Puntos de Anclaje: " + puntosAnclaje);
            Console::WriteLine("|Estado: " + estado.ToString());
        }
    };
}