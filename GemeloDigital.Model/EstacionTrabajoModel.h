#pragma once
using namespace System;

namespace GemeloDigitalModel {

    public ref class EstacionTrabajoModel {
    private:
        String^ id;
        String^ tipoPiezaAceptada;
        bool    ocupada;

    public:
        EstacionTrabajoModel(String^ id, String^ tipoPiezaAceptada, bool ocupada) {
            this->id = id;
            this->tipoPiezaAceptada = tipoPiezaAceptada;
            this->ocupada = ocupada;
        }

        property String^ Id {
            String^ get() { return id; }
        }

        property String^ TipoPiezaAceptada {
            String^ get() { return tipoPiezaAceptada; }
            void    set(String^ value) { tipoPiezaAceptada = value; }
        }

        property bool Ocupada {
            bool get() { return ocupada; }
            void set(bool value) { ocupada = value; }
        }

        void dataReport() {
            Console::WriteLine("=== ESTACION DE TRABAJO ===");
            Console::WriteLine("ID: " + Id);
            Console::WriteLine("|Tipo Pieza Aceptada: " + TipoPiezaAceptada);
            Console::WriteLine("|Ocupada: " + Ocupada);
        }
    };
}