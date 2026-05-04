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
        ArticulacionModel(int id, String^ nombre, bool activo,
            double anguloActual, double anguloMinimo, double anguloMaximo)
            : ComponenteRoboticoModel(id, nombre, activo) {
            this->anguloActual = anguloActual;
            this->anguloMinimo = anguloMinimo;
            this->anguloMaximo = anguloMaximo;
        }

        // Getters
        double getAnguloActual() { return anguloActual; }
        double getAnguloMinimo() { return anguloMinimo; }
        double getAnguloMaximo() { return anguloMaximo; }

        // Setters
        void setAnguloActual(double a) { anguloActual = a; }
        void setAnguloMinimo(double a) { anguloMinimo = a; }
        void setAnguloMaximo(double a) { anguloMaximo = a; }

        virtual void dataReport() override {
            Console::WriteLine("  [Articulacion] ID: " + id + " | Nombre: " + nombre);
            Console::WriteLine("  |Activo: " + activo);
            Console::WriteLine("  |Angulo Actual: " + anguloActual);
            Console::WriteLine("  |Angulo Min: " + anguloMinimo + " | Angulo Max: " + anguloMaximo);
        }
    };
}
