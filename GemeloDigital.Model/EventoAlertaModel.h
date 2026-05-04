#pragma once
#include "EventoModel.h"
using namespace System;

namespace GemeloDigitalModel {

    public ref class EventoAlertaModel : public EventoModel {
    private:
        int brazoId;
        String^ tipoAlerta;

    public:
        EventoAlertaModel(int id, String^ timestamp, String^ descripcion,
            int brazoId, String^ tipoAlerta)
            : EventoModel(id, timestamp, descripcion, NivelEvento::ALERTA) {
            this->brazoId = brazoId;
            this->tipoAlerta = tipoAlerta;
        }

        int getBrazoId() { return brazoId; }
        String^ getTipoAlerta() { return tipoAlerta; }
        void setTipoAlerta(String^ t) { tipoAlerta = t; }

        virtual void dataReport() override {
            Console::WriteLine("=== EVENTO ALERTA ===");
            Console::WriteLine("ID: " + id + " | " + timestamp);
            Console::WriteLine("|Nivel: " + nivel.ToString());
            Console::WriteLine("|Brazo ID: " + brazoId + " | Tipo: " + tipoAlerta);
            Console::WriteLine("|Desc: " + descripcion);
        }
    };
}