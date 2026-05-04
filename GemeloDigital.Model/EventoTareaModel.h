#pragma once
#include "EventoModel.h"
using namespace System;

namespace GemeloDigitalModel {

    public ref class EventoTareaModel : public EventoModel {
    private:
        int tareaId;
        String^ resultado;

    public:
        EventoTareaModel(int id, String^ timestamp, String^ descripcion,
            int tareaId, String^ resultado)
            : EventoModel(id, timestamp, descripcion, NivelEvento::INFO) {
            this->tareaId = tareaId;
            this->resultado = resultado;
        }

        int getTareaId() { return tareaId; }
        String^ getResultado() { return resultado; }
        void setResultado(String^ r) { resultado = r; }

        virtual void dataReport() override {
            Console::WriteLine("=== EVENTO TAREA ===");
            Console::WriteLine("ID: " + id + " | " + timestamp);
            Console::WriteLine("|Nivel: " + nivel.ToString());
            Console::WriteLine("|Tarea ID: " + tareaId + " | Resultado: " + resultado);
            Console::WriteLine("|Desc: " + descripcion);
        }
    };
}