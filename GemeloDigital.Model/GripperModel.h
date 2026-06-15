#pragma once
#include "ActuadorModel.h"
using namespace System;

namespace GemeloDigitalModel {

    public ref class GripperModel : public ActuadorModel {
    private:
        double apertura;
        double fuerzaAgarre;
        bool   abierto;

    public:
        GripperModel(String^ id, String^ nombre, bool activo,
            double apertura, double fuerzaAgarre, bool abierto)
            : ActuadorModel(id, nombre, activo) {
            this->apertura = apertura;
            this->fuerzaAgarre = fuerzaAgarre;
            this->abierto = abierto;
        }

        property double Apertura {
            double get() { return apertura; }
            void   set(double value) { apertura = value; }
        }

        property double FuerzaAgarre {
            double get() { return fuerzaAgarre; }
            void   set(double value) { fuerzaAgarre = value; }
        }

        property bool Abierto {
            bool get() { return abierto; }
            void set(bool value) { abierto = value; }
        }

        virtual void dataReport() override {
            Console::WriteLine("  [Gripper] ID: " + Id + " | Nombre: " + Nombre);
            Console::WriteLine("  |Activo: " + Activo);
            Console::WriteLine("  |Apertura: " + Apertura);
            Console::WriteLine("  |Fuerza Agarre: " + FuerzaAgarre);
            Console::WriteLine("  |Abierto: " + Abierto);
        }
    };
}