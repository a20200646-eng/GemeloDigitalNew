#pragma once
#include "SensorModel.h"
using namespace System;

namespace GemeloDigitalModel {

    public ref class SensorPosicionModel : public SensorModel {
    private:
        double anguloMedido;
        double tolerancia;

    public:
        SensorPosicionModel(String^ id, String^ nombre, bool activo,
            double anguloMedido, double tolerancia)
            : SensorModel(id, nombre, activo) {
            this->anguloMedido = anguloMedido;
            this->tolerancia = tolerancia;
        }

        property double AnguloMedido {
            double get() { return anguloMedido; }
            void   set(double value) { anguloMedido = value; }
        }

        property double Tolerancia {
            double get() { return tolerancia; }
            void   set(double value) { tolerancia = value; }
        }

        virtual void dataReport() override {
            Console::WriteLine("  [SensorPosicion] ID: " + Id + " | Nombre: " + Nombre);
            Console::WriteLine("  |Activo: " + Activo);
            Console::WriteLine("  |Angulo Medido: " + AnguloMedido);
            Console::WriteLine("  |Tolerancia: " + Tolerancia);
        }
    };
}