#pragma once
#include "EventoModel.h"
using namespace System;

namespace GemeloDigitalModel {

    public ref class EventoErrorModel : public EventoModel {
    private:
        String^ codigoError;
        String^ fase;

    public:
        EventoErrorModel(String^ id, String^ timestamp, String^ descripcion,
            String^ codigoError, String^ fase)
            : EventoModel(id, timestamp, descripcion, NivelEvento::ERROR) {
            this->codigoError = codigoError;
            this->fase = fase;
        }

        property String^ CodigoError {
            String^ get() { return codigoError; }
            void    set(String^ value) { codigoError = value; }
        }

        property String^ Fase {
            String^ get() { return fase; }
            void    set(String^ value) { fase = value; }
        }

        virtual void dataReport() override {
            Console::WriteLine("=== EVENTO ERROR ===");
            Console::WriteLine("ID: " + Id + " | " + Timestamp);
            Console::WriteLine("|Nivel: " + Nivel.ToString());
            Console::WriteLine("|Codigo: " + CodigoError + " | Fase: " + Fase);
            Console::WriteLine("|Desc: " + Descripcion);
        }
    };
}