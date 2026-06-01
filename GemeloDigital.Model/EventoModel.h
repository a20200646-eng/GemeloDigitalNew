#pragma once
#include "Enumeraciones.h"
using namespace System;

namespace GemeloDigitalModel {

    public ref class EventoModel abstract {
    protected:
        int         id;
        String^ timestamp;
        String^ descripcion;
        NivelEvento nivel;

    public:
        EventoModel(int id, String^ timestamp, String^ descripcion, NivelEvento nivel) {
            this->id = id;
            this->timestamp = timestamp;
            this->descripcion = descripcion;
            this->nivel = nivel;
        }

        property int Id {
            int get() { return id; }
        }

        property String^ Timestamp {
            String^ get() { return timestamp; }
        }

        property String^ Descripcion {
            String^ get() { return descripcion; }
            void    set(String^ value) { descripcion = value; }
        }

        property NivelEvento Nivel {
            NivelEvento get() { return nivel; }
            void        set(NivelEvento value) { nivel = value; }
        }

        virtual void dataReport() = 0;
    };
}