#pragma once
#include "SensorModel.h"
using namespace System;


namespace GemeloDigitalModel {

    public ref class SensorPosicionModel : public SensorModel {
    private:
        double anguloMedido;
        double tolerancia;

    public:
        SensorPosicionModel(int id, String^ nombre, bool activo,
            double anguloMedido, double tolerancia)
            : SensorModel(id, nombre, activo) {
            this->anguloMedido = anguloMedido;
            this->tolerancia = tolerancia;
        }

        // Getters
        double getAnguloMedido() { return anguloMedido; }
        double getTolerancia() { return tolerancia; }

        // Setters
        void setAnguloMedido(double a) { anguloMedido = a; }
        void setTolerancia(double t) { tolerancia = t; }

        virtual void dataReport() override {
            Console::WriteLine("  [SensorPosicion] ID: " + id + " | Nombre: " + nombre);
            Console::WriteLine("  |Activo: " + activo);
            Console::WriteLine("  |Angulo Medido: " + anguloMedido);
            Console::WriteLine("  |Tolerancia: " + tolerancia);
        }
    };
}