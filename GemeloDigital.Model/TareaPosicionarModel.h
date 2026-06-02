#pragma once
#include "TareaModel.h"
using namespace System;

namespace GemeloDigitalModel {

    public ref class TareaPosicionarModel : public TareaModel {
    private:
        double posicionObjetivo;
        double tolerancia;

    public:
        TareaPosicionarModel(int id, double posicionObjetivo, double tolerancia)
            : TareaModel(id, "PENDIENTE") {
            this->posicionObjetivo = posicionObjetivo;
            this->tolerancia = tolerancia;
        }

        property double PosicionObjetivo {
            double get() { return posicionObjetivo; }
            void   set(double value) { posicionObjetivo = value; }
        }

        property double Tolerancia {
            double get() { return tolerancia; }
            void   set(double value) { tolerancia = value; }
        }

        virtual void dataReport() override {
            Console::WriteLine("=== TAREA: POSICIONAR ===");
            Console::WriteLine("ID: " + Id + " | Estado: " + Estado);
            Console::WriteLine("|Posicion Objetivo: " + PosicionObjetivo);
            Console::WriteLine("|Tolerancia: " + Tolerancia);
        }
    };
}

