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
        SensorFuerzaModel(String^ id, String^ nombre, bool activo,
            double fuerzaActual, double fuerzaMinima, double fuerzaMaxima)
            : SensorModel(id, nombre, activo) {
            this->fuerzaActual = fuerzaActual;
            this->fuerzaMinima = fuerzaMinima;
            this->fuerzaMaxima = fuerzaMaxima;
        }

        property double FuerzaActual {
            double get() { return fuerzaActual; }
            void   set(double value) { fuerzaActual = value; }
        }

        property double FuerzaMinima {
            double get() { return fuerzaMinima; }
            void   set(double value) { fuerzaMinima = value; }
        }

        property double FuerzaMaxima {
            double get() { return fuerzaMaxima; }
            void   set(double value) { fuerzaMaxima = value; }
        }

        virtual void dataReport() override {
            Console::WriteLine("  [SensorFuerza] ID: " + Id + " | Nombre: " + Nombre);
            Console::WriteLine("  |Activo: " + Activo);
            Console::WriteLine("  |Fuerza Actual: " + FuerzaActual);
            Console::WriteLine("  |Fuerza Min: " + FuerzaMinima + " | Fuerza Max: " + FuerzaMaxima);
        }
    };
}