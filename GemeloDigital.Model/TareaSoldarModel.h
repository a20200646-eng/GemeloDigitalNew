#pragma once
#include "TareaModel.h"
using namespace System;

namespace GemeloDigitalModel {

    public ref class TareaSoldarModel : public TareaModel {
    private:
        int    puntosObjetivo;
        int    puntosCompletados;
        double temperatura;

    public:
        TareaSoldarModel(int id, int puntosObjetivo, double temperatura)
            : TareaModel(id, "PENDIENTE") {
            this->puntosObjetivo = puntosObjetivo;
            this->puntosCompletados = 0;
            this->temperatura = temperatura;
        }

        property int PuntosObjetivo {
            int  get() { return puntosObjetivo; }
            void set(int value) { puntosObjetivo = value; }
        }

        property int PuntosCompletados {
            int  get() { return puntosCompletados; }
            void set(int value) { puntosCompletados = value; }
        }

        property double Temperatura {
            double get() { return temperatura; }
            void   set(double value) { temperatura = value; }
        }

        virtual void dataReport() override {
            Console::WriteLine("=== TAREA: SOLDAR ===");
            Console::WriteLine("ID: " + Id + " | Estado: " + Estado);
            Console::WriteLine("|Puntos: " + PuntosCompletados + " / " + PuntosObjetivo);
            Console::WriteLine("|Temperatura: " + Temperatura + " C");
        }
    };
}