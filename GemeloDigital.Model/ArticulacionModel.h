#pragma once
#include "ComponenteRoboticoModel.h"
using namespace System;

namespace GemeloDigitalModel {

    public ref class ArticulacionModel : public ComponenteRoboticoModel {
    private:
        double anguloActual;
        double anguloMinimo;
        double anguloMaximo;

    public:
        ArticulacionModel(String^ id, String^ nombre, bool activo,
            double anguloActual, double anguloMinimo, double anguloMaximo)
            : ComponenteRoboticoModel(id, nombre, activo) {
            this->anguloActual = anguloActual;
            this->anguloMinimo = anguloMinimo;
            this->anguloMaximo = anguloMaximo;
        }

        property double AnguloActual {
            double get() { return anguloActual; }
            void   set(double value) { anguloActual = value; }
        }

        property double AnguloMinimo {
            double get() { return anguloMinimo; }
            void   set(double value) { anguloMinimo = value; }
        }

        property double AnguloMaximo {
            double get() { return anguloMaximo; }
            void   set(double value) { anguloMaximo = value; }
        }

        virtual void dataReport() override {
            Console::WriteLine("  [Articulacion] ID: " + Id + " | Nombre: " + Nombre);
            Console::WriteLine("  |Activo: " + Activo);
            Console::WriteLine("  |Angulo Actual: " + AnguloActual);
            Console::WriteLine("  |Angulo Min: " + AnguloMinimo + " | Angulo Max: " + AnguloMaximo);
        }
    };
}