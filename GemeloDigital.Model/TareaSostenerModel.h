#pragma once
#include "TareaModel.h"
using namespace System;

namespace GemeloDigitalModel {

    public ref class TareaSostenerModel : public TareaModel {
    private:
        double fuerzaSosten;
        int duracion;

    public:
        TareaSostenerModel(int id, double fuerzaSosten, int duracion)
            : TareaModel(id, "PENDIENTE") {
            this->fuerzaSosten = fuerzaSosten;
            this->duracion = duracion;
        }

        double getFuerzaSosten() { return fuerzaSosten; }
        int getDuracion() { return duracion; }
        void setFuerzaSosten(double f) { fuerzaSosten = f; }
        void setDuracion(int d) { duracion = d; }

        virtual void dataReport() override {
            Console::WriteLine("=== TAREA: SOSTENER ===");
            Console::WriteLine("ID: " + id + " | Estado: " + estado);
            Console::WriteLine("|Fuerza Sosten: " + fuerzaSosten + " N");
            Console::WriteLine("|Duracion: " + duracion + " seg");
        }
    };
}