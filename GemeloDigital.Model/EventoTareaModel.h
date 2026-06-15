#pragma once
#include "EventoModel.h"
using namespace System;

namespace GemeloDigitalModel {

    public ref class EventoTareaModel : public EventoModel {
    private:
        String^ tareaId;
        String^ resultado;

    public:
        EventoTareaModel(String^ id, String^ timestamp, String^ descripcion,
            String^ tareaId, String^ resultado)
            : EventoModel(id, timestamp, descripcion, NivelEvento::INFO) {
            this->tareaId = tareaId;
            this->resultado = resultado;
        }

        property String^ TareaId {
            String^ get() { return tareaId; }
        }

        property String^ Resultado {
            String^ get() { return resultado; }
            void    set(String^ value) { resultado = value; }
        }

        virtual void dataReport() override {
            Console::WriteLine("=== EVENTO TAREA ===");
            Console::WriteLine("ID: " + Id + " | " + Timestamp);
            Console::WriteLine("|Nivel: " + Nivel.ToString());
            Console::WriteLine("|Tarea ID: " + TareaId + " | Resultado: " + Resultado);
            Console::WriteLine("|Desc: " + Descripcion);
        }
    };
}