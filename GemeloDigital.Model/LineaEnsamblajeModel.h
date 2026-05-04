#pragma once
#include "PiezaModel.h"
using namespace System;
using namespace System::Collections::Generic;

namespace GemeloDigitalModel {

    public ref class LineaEnsamblajeModel {
    private:
        int id;
        List<PiezaModel^>^ colaPiezas;
        int indiceActual;
        bool secuenciaAprobada;

    public:
        LineaEnsamblajeModel(int id) {
            this->id = id;
            this->indiceActual = 0;
            this->secuenciaAprobada = false;
            colaPiezas = gcnew List<PiezaModel^>();
        }

        // Getters
        int getId() { return id; }
        int getIndiceActual() { return indiceActual; }
        bool getSecuenciaAprobada() { return secuenciaAprobada; }
        List<PiezaModel^>^ getColaPiezas() { return colaPiezas; }

        // Setters
        void setIndiceActual(int i) { indiceActual = i; }
        void setSecuenciaAprobada(bool s) { secuenciaAprobada = s; }

        // Agregar pieza a la cola
        void agregarPieza(PiezaModel^ p) { colaPiezas->Add(p); }

        void dataReport() {
            Console::WriteLine("=== LINEA DE ENSAMBLAJE ===");
            Console::WriteLine("ID: " + id);
            Console::WriteLine("|Indice Actual: " + indiceActual);
            Console::WriteLine("|Secuencia Aprobada: " + secuenciaAprobada);
            Console::WriteLine("|Piezas en cola: " + colaPiezas->Count);
        }
    };
}