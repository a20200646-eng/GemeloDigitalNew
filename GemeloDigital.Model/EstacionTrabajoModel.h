#pragma once
using namespace System;

namespace GemeloDigitalModel {

    public ref class EstacionTrabajoModel {
    private:
        int id;
        String^ tipoPiezaAceptada;
        bool ocupada;

    public:
        EstacionTrabajoModel(int id, String^ tipoPiezaAceptada, bool ocupada) {
            this->id = id;
            this->tipoPiezaAceptada = tipoPiezaAceptada;
            this->ocupada = ocupada;
        }

        // Getters
        int getId() { return id; }
        String^ getTipoPiezaAceptada() { return tipoPiezaAceptada; }
        bool getOcupada() { return ocupada; }

        // Setters - id no se modifica
        void setTipoPiezaAceptada(String^ t) { tipoPiezaAceptada = t; }
        void setOcupada(bool o) { ocupada = o; }

        void dataReport() {
            Console::WriteLine("=== ESTACION DE TRABAJO ===");
            Console::WriteLine("ID: " + id);
            Console::WriteLine("|Tipo Pieza Aceptada: " + tipoPiezaAceptada);
            Console::WriteLine("|Ocupada: " + ocupada);
        }
    };
}