#pragma once
#include "TareaModel.h"
using namespace System;

namespace GemeloDigitalModel {

    public ref class TareaCoordinadaModel : public TareaModel {
    private:
        int totalConfirmado;
        int totalRequerido;

    public:
        TareaCoordinadaModel(int id, int totalRequerido)
            : TareaModel(id, "PENDIENTE") {
            this->totalConfirmado = 0;
            this->totalRequerido = totalRequerido;
        }

        property int TotalConfirmado {
            int  get() { return totalConfirmado; }
            void set(int value) { totalConfirmado = value; }
        }

        property int TotalRequerido {
            int  get() { return totalRequerido; }
            void set(int value) { totalRequerido = value; }
        }

        virtual void dataReport() override {
            Console::WriteLine("=== TAREA COORDINADA ===");
            Console::WriteLine("ID: " + Id + " | Estado: " + Estado);
            Console::WriteLine("|Confirmados: " + TotalConfirmado + " / " + TotalRequerido);
        }
    };
}