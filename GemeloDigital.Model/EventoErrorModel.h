#pragma once
#include "EventoModel.h"
using namespace System;

namespace GemeloDigitalModel {

    public ref class EventoErrorModel : public EventoModel {
    private:
        String^ codigoError;
        String^ fase;

    public:
        EventoErrorModel(int id, String^ timestamp, String^ descripcion,
            String^ codigoError, String^ fase)
            : EventoModel(id, timestamp, descripcion, NivelEvento::ERROR) {
            this->codigoError = codigoError;
            this->fase = fase;
        }

        String^ getCodigoError() { return codigoError; }
        String^ getFase() { return fase; }
        void setCodigoError(String^ c) { codigoError = c; }
        void setFase(String^ f) { fase = f; }

        virtual void dataReport() override {
            Console::WriteLine("=== EVENTO ERROR ===");
            Console::WriteLine("ID: " + id + " | " + timestamp);
            Console::WriteLine("|Nivel: " + nivel.ToString());
            Console::WriteLine("|Codigo: " + codigoError + " | Fase: " + fase);
            Console::WriteLine("|Desc: " + descripcion);
        }
    };
}