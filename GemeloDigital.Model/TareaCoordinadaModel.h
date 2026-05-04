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

        int getTotalConfirmado() { return totalConfirmado; }
        int getTotalRequerido() { return totalRequerido; }
        void setTotalConfirmado(int t) { totalConfirmado = t; }
        void setTotalRequerido(int t) { totalRequerido = t; }

        virtual void dataReport() override {
            Console::WriteLine("=== TAREA COORDINADA ===");
            Console::WriteLine("ID: " + id + " | Estado: " + estado);
            Console::WriteLine("|Confirmados: " + totalConfirmado + " / " + totalRequerido);
        }
    };
}