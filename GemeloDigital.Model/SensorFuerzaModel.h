#pragma once
#include "SensorModel.h"
using namespace System;


namespace GemeloDigitalModel {

    public ref class SensorFuerzaModel : public SensorModel {
    private:
        double fuerzaActual;
        double fuerzaMinima;
        double fuerzaMaxima;

    public:
        SensorFuerzaModel(int id, String^ nombre, bool activo,
            double fuerzaActual, double fuerzaMinima, double fuerzaMaxima)
            : SensorModel(id, nombre, activo) {
            this->fuerzaActual = fuerzaActual;
            this->fuerzaMinima = fuerzaMinima;
            this->fuerzaMaxima = fuerzaMaxima;
        }

        // Getters
        double getFuerzaActual() { return fuerzaActual; }
        double getFuerzaMinima() { return fuerzaMinima; }
        double getFuerzaMaxima() { return fuerzaMaxima; }

        // Setters
        void setFuerzaActual(double f) { fuerzaActual = f; }
        void setFuerzaMinima(double f) { fuerzaMinima = f; }
        void setFuerzaMaxima(double f) { fuerzaMaxima = f; }

        virtual void dataReport() override {
            Console::WriteLine("  [SensorFuerza] ID: " + id + " | Nombre: " + nombre);
            Console::WriteLine("  |Activo: " + activo);
            Console::WriteLine("  |Fuerza Actual: " + fuerzaActual);
            Console::WriteLine("  |Fuerza Min: " + fuerzaMinima + " | Fuerza Max: " + fuerzaMaxima);
        }
    };
}