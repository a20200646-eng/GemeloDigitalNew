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

        double getPosicionObjetivo() { return posicionObjetivo; }
        double getTolerancia() { return tolerancia; }
        void setPosicionObjetivo(double p) { posicionObjetivo = p; }
        void setTolerancia(double t) { tolerancia = t; }

        virtual void dataReport() override {
            Console::WriteLine("=== TAREA: POSICIONAR ===");
            Console::WriteLine("ID: " + id + " | Estado: " + estado);
            Console::WriteLine("|Posicion Objetivo: " + posicionObjetivo);
            Console::WriteLine("|Tolerancia: " + tolerancia);
        }
    };
}