#pragma once
#include "TareaModel.h"
using namespace System;

namespace GemeloDigitalModel {

    public ref class TareaSoldarModel : public TareaModel {
    private:
        int puntosObjetivo;
        int puntosCompletados;
        double temperatura;

    public:
        TareaSoldarModel(int id, int puntosObjetivo, double temperatura)
            : TareaModel(id, "PENDIENTE") {
            this->puntosObjetivo = puntosObjetivo;
            this->puntosCompletados = 0;
            this->temperatura = temperatura;
        }

        int getPuntosObjetivo() { return puntosObjetivo; }
        int getPuntosCompletados() { return puntosCompletados; }
        double getTemperatura() { return temperatura; }
        void setPuntosObjetivo(int p) { puntosObjetivo = p; }
        void setPuntosCompletados(int p) { puntosCompletados = p; }
        void setTemperatura(double t) { temperatura = t; }

        virtual void dataReport() override {
            Console::WriteLine("=== TAREA: SOLDAR ===");
            Console::WriteLine("ID: " + id + " | Estado: " + estado);
            Console::WriteLine("|Puntos: " + puntosCompletados + " / " + puntosObjetivo);
            Console::WriteLine("|Temperatura: " + temperatura + " C");
        }
    };
}
