#pragma once
#include "Enumeraciones.h"
using namespace System;

namespace GemeloDigitalModel {

    public ref class PiezaModel abstract {
    protected:
        int         id;
        String^ tipo;
        String^ material;
        double      peso;
        EstadoPieza estado;

    public:
        PiezaModel(int id, String^ tipo, String^ material, double peso, EstadoPieza estado) {
            this->id = id;
            this->tipo = tipo;
            this->material = material;
            this->peso = peso;
            this->estado = estado;
        }

        property int Id {
            int get() { return id; }
        }

        property String^ Tipo {
            String^ get() { return tipo; }
        }

        property String^ Material {
            String^ get() { return material; }
            void    set(String^ value) { material = value; }
        }

        property double Peso {
            double get() { return peso; }
            void   set(double value) { peso = value; }
        }

        property EstadoPieza Estado {
            EstadoPieza get() { return estado; }
            void        set(EstadoPieza value) { estado = value; }
        }

        virtual void dataReport() = 0;
    };
}