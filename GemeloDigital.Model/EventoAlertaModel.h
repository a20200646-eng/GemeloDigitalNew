#pragma once
#include "EventoModel.h"
using namespace System;

namespace GemeloDigitalModel {

    public ref class EventoAlertaModel : public EventoModel {
    private:
        String^ brazoId;
        String^ tipoAlerta;

    public:
        EventoAlertaModel(String^ id, String^ timestamp, String^ descripcion,
            String^ brazoId, String^ tipoAlerta)
            : EventoModel(id, timestamp, descripcion, NivelEvento::ALERTA) {
            this->brazoId = brazoId;
            this->tipoAlerta = tipoAlerta;
        }

        property String^ BrazoId {
            String^ get() { return brazoId; }
        }

        property String^ TipoAlerta {
            String^ get() { return tipoAlerta; }
            void    set(String^ value) { tipoAlerta = value; }
        }

        virtual void dataReport() override {
            Console::WriteLine("=== EVENTO ALERTA ===");
            Console::WriteLine("ID: " + Id + " | " + Timestamp);
            Console::WriteLine("|Nivel: " + Nivel.ToString());
            Console::WriteLine("|Brazo ID: " + BrazoId + " | Tipo: " + TipoAlerta);
            Console::WriteLine("|Desc: " + Descripcion);
        }
    };
}