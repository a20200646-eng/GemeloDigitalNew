#pragma once
#include "ActuadorModel.h"
using namespace System;

namespace GemeloDigitalModel {

    public ref class ServomotorModel : public ActuadorModel {
    private:
        int    pulsosPWM;
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

        property int PulsosPWM {
            int  get() { return pulsosPWM; }
            void set(int value) { pulsosPWM = value; }
        }

        property double TorqueMaximo {
            double get() { return torqueMaximo; }
            void   set(double value) { torqueMaximo = value; }
        }

        property double VelocidadGiro {
            double get() { return velocidadGiro; }
            void   set(double value) { velocidadGiro = value; }
        }

        virtual void dataReport() override {
            Console::WriteLine("  [Servomotor] ID: " + Id + " | Nombre: " + Nombre);
            Console::WriteLine("  |Activo: " + Activo);
            Console::WriteLine("  |Pulsos PWM: " + PulsosPWM);
            Console::WriteLine("  |Torque Maximo: " + TorqueMaximo);
            Console::WriteLine("  |Velocidad Giro: " + VelocidadGiro);
        }
    };
}