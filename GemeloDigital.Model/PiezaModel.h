#pragma once
#include "Enumeraciones.h"
using namespace System;

namespace GemeloDigitalModel {

    public ref class PiezaModel abstract {
    protected:
        int id;
        String^ tipo;
        String^ material;
        double peso;
        EstadoPieza estado;

    public:
        PiezaModel(int id, String^ tipo, String^ material, double peso, EstadoPieza estado) {
            this->id = id;
            this->tipo = tipo;
            this->material = material;
            this->peso = peso;
            this->estado = estado;
        }

        int getId() { return id; }
        String^ getTipo() { return tipo; }
        String^ getMaterial() { return material; }
        double getPeso() { return peso; }
        EstadoPieza getEstado() { return estado; }

        void setMaterial(String^ m) { material = m; }
        void setPeso(double p) { peso = p; }
        void setEstado(EstadoPieza e) { estado = e; }

        virtual void dataReport() = 0;
    };
}