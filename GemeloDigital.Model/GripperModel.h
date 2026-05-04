#pragma once
#include "ActuadorModel.h"
using namespace System;


namespace GemeloDigitalModel {

    public ref class GripperModel : public ActuadorModel {
    private:
        double apertura;
        double fuerzaAgarre;
        bool abierto;

    public:
        GripperModel(int id, String^ nombre, bool activo,
            double apertura, double fuerzaAgarre, bool abierto)
            : ActuadorModel(id, nombre, activo) {
            this->apertura = apertura;
            this->fuerzaAgarre = fuerzaAgarre;
            this->abierto = abierto;
        }

        // Getters
        double getApertura() { return apertura; }
        double getFuerzaAgarre() { return fuerzaAgarre; }
        bool getAbierto() { return abierto; }

        // Setters
        void setApertura(double a) { apertura = a; }
        void setFuerzaAgarre(double f) { fuerzaAgarre = f; }
        void setAbierto(bool a) { abierto = a; }

        virtual void dataReport() override {
            Console::WriteLine("  [Gripper] ID: " + id + " | Nombre: " + nombre);
            Console::WriteLine("  |Activo: " + activo);
            Console::WriteLine("  |Apertura: " + apertura);
            Console::WriteLine("  |Fuerza Agarre: " + fuerzaAgarre);
            Console::WriteLine("  |Abierto: " + abierto);
        }
    };
}