#pragma once
#include "PiezaModel.h"
using namespace System;

namespace GemeloDigitalModel {

    public ref class PanelLateralModel : public PiezaModel {
    private:
        LadoPanel lado;
        int       puntosAnclaje;
        String^ estacionId;

    public:
        PanelLateralModel(String^ id, String^ material, double peso,
            LadoPanel lado, int puntosAnclaje, String^ estacionId)
            : PiezaModel(id, "Panel Lateral", material, peso, EstadoPieza::DISPONIBLE) {
            this->lado = lado;
            this->puntosAnclaje = puntosAnclaje;
            this->estacionId = estacionId;
        }

        property LadoPanel Lado {
            LadoPanel get() { return lado; }
            void      set(LadoPanel value) { lado = value; }
        }

        property int PuntosAnclaje {
            int  get() { return puntosAnclaje; }
            void set(int value) { puntosAnclaje = value; }
        }

        property String^ EstacionId {
            String^ get() { return estacionId; }
            void    set(String^ value) { estacionId = value; }
        }

        virtual void dataReport() override {
            Console::WriteLine("=== PANEL LATERAL ===");
            Console::WriteLine("ID: " + Id);
            Console::WriteLine("|Material: " + Material);
            Console::WriteLine("|Peso: " + Peso + " kg");
            Console::WriteLine("|Lado: " + Lado.ToString());
            Console::WriteLine("|Puntos de Anclaje: " + PuntosAnclaje);
            Console::WriteLine("|Estado: " + Estado.ToString());
        }
    };
}