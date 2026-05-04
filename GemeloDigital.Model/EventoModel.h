#pragma once
#include "Enumeraciones.h"
using namespace System;

namespace GemeloDigitalModel {

    public ref class EventoModel abstract {
    protected:
        int id;
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

        int getId() { return id; }
        String^ getTimestamp() { return timestamp; }
        String^ getDescripcion() { return descripcion; }
        NivelEvento getNivel() { return nivel; }

        void setDescripcion(String^ d) { descripcion = d; }
        void setNivel(NivelEvento n) { nivel = n; }

        virtual void dataReport() = 0;
    };
}