#pragma once
#include "PiezaModel.h"
using namespace System;
using namespace System::Collections::Generic;

namespace GemeloDigitalModel {

    public ref class LineaEnsamblajeModel {
    private:
        int                id;
        List<PiezaModel^>^ colaPiezas;
        int                indiceActual;
        bool               secuenciaAprobada;

    public:
        LineaEnsamblajeModel(int id) {
            this->id = id;
            this->indiceActual = 0;
            this->secuenciaAprobada = false;
            colaPiezas = gcnew List<PiezaModel^>();
        }

        property int Id {
            int get() { return id; }
        }

        property int IndiceActual {
            int  get() { return indiceActual; }
            void set(int value) { indiceActual = value; }
        }

        property bool SecuenciaAprobada {
            bool get() { return secuenciaAprobada; }
            void set(bool value) { secuenciaAprobada = value; }
        }

        property List<PiezaModel^>^ ColaPiezas {
            List<PiezaModel^>^ get() { return colaPiezas; }
        }

        // Metodo de agregacion — responsabilidad del Model
        void agregarPieza(PiezaModel^ p) { colaPiezas->Add(p); }

        void dataReport() {
            Console::WriteLine("=== LINEA DE ENSAMBLAJE ===");
            Console::WriteLine("ID: " + Id);
            Console::WriteLine("|Indice Actual: " + IndiceActual);
            Console::WriteLine("|Secuencia Aprobada: " + SecuenciaAprobada);
            Console::WriteLine("|Piezas en cola: " + ColaPiezas->Count);
        }
    };
}