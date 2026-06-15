#pragma once
#include "Enumeraciones.h"
using namespace System;

namespace GemeloDigitalModel {

    public ref class EstacionTrabajoModel {
    private:
        String^ id;
		TipoEstacion tipo;
        int     cantidadPiezas;

    public:
        EstacionTrabajoModel(String^ id, TipoEstacion tipo, int cantidadPiezas) {
            this->id = id;
            this->tipo = tipo;
            this->cantidadPiezas = cantidadPiezas;
        }

        property String^ Id {
            String^ get() { return id; }
        }

        property TipoEstacion Tipo {
            TipoEstacion get() { return tipo; }
            void set(TipoEstacion value) { tipo = value; }
        }

        property int CantidadPiezas {
            int get() { return cantidadPiezas; }
			void set(int value) { cantidadPiezas = value; }
        }
    };
}