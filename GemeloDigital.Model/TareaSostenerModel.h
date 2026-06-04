#pragma once
#include "TareaModel.h"
using namespace System;

namespace GemeloDigitalModel {

    public ref class TareaSostenerModel : public TareaModel {
    private:
        double fuerzaSosten;
        int    duracion;

    public:
        TareaSostenerModel(String^ id, double fuerzaSosten, int duracion)
            : TareaModel(id, "PENDIENTE") {
            this->fuerzaSosten = fuerzaSosten;
            this->duracion = duracion;
        }

        property double FuerzaSosten {
            double get() { return fuerzaSosten; }
            void   set(double value) { fuerzaSosten = value; }
        }

        property int Duracion {
            int  get() { return duracion; }
            void set(int value) { duracion = value; }
        }

        virtual void dataReport() override {
            Console::WriteLine("=== TAREA: SOSTENER ===");
            Console::WriteLine("ID: " + Id + " | Estado: " + Estado);
            Console::WriteLine("|Fuerza Sosten: " + FuerzaSosten + " N");
            Console::WriteLine("|Duracion: " + Duracion + " seg");
        }
    };
}