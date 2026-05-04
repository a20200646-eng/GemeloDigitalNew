#pragma once
#include "Enumeraciones.h"
using namespace System;

namespace GemeloDigitalModel {

    public ref class ComponenteRoboticoModel abstract {
    protected:
        int id;
        String^ nombre;
        bool activo;

    public:
        ComponenteRoboticoModel(int id, String^ nombre, bool activo) {
            this->id = id;
            this->nombre = nombre;
            this->activo = activo;
        }

        // Getters
        int getId() { return id; }
        String^ getNombre() { return nombre; }
        bool getActivo() { return activo; }

        // Setters - id no se modifica
        void setNombre(String^ nombre) { this->nombre = nombre; }
        void setActivo(bool activo) { this->activo = activo; }

        // Metodo abstracto
        virtual void dataReport() = 0;
    };
}
