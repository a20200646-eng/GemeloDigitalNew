#pragma once
#include "ActuadorModel.h"
using namespace System;


namespace GemeloDigitalModel {

    public ref class ServomotorModel : public ActuadorModel {
    private:
        int pulsosPWM;
        double torqueMaximo;
        double velocidadGiro;

    public:
        ServomotorModel(int id, String^ nombre, bool activo,
            int pulsosPWM, double torqueMaximo, double velocidadGiro)
            : ActuadorModel(id, nombre, activo) {
            this->pulsosPWM = pulsosPWM;
            this->torqueMaximo = torqueMaximo;
            this->velocidadGiro = velocidadGiro;
        }

        // Getters
        int getPulsosPWM() { return pulsosPWM; }
        double getTorqueMaximo() { return torqueMaximo; }
        double getVelocidadGiro() { return velocidadGiro; }

        // Setters
        void setPulsosPWM(int p) { pulsosPWM = p; }
        void setTorqueMaximo(double t) { torqueMaximo = t; }
        void setVelocidadGiro(double v) { velocidadGiro = v; }

        virtual void dataReport() override {
            Console::WriteLine("  [Servomotor] ID: " + id + " | Nombre: " + nombre);
            Console::WriteLine("  |Activo: " + activo);
            Console::WriteLine("  |Pulsos PWM: " + pulsosPWM);
            Console::WriteLine("  |Torque Maximo: " + torqueMaximo);
            Console::WriteLine("  |Velocidad Giro: " + velocidadGiro);
        }
    };
}