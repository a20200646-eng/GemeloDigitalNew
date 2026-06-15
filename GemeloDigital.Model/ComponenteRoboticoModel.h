/**/#pragma once
#include "Enumeraciones.h"
using namespace System;

namespace GemeloDigitalModel {

    public ref class ComponenteRoboticoModel abstract {
    protected:
        String^ id;
        String^ nombre;
        bool    activo;

    public:
        ComponenteRoboticoModel(String^ id, String^ nombre, bool activo) {
            this->id = id;
            this->nombre = nombre;
            this->activo = activo;
        }

        // Properties
        property String^ Id {
            String^ get() { return id; }
        }

        property String^ Nombre {
            String^ get() { return nombre; }
            void    set(String^ value) { nombre = value; }
        }

        property bool Activo {
            bool get() { return activo; }
            void set(bool value) { activo = value; }
        }

        // Metodo abstracto
        virtual void dataReport() = 0;
    };
}
