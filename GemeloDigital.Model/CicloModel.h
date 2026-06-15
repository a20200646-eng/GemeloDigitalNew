#pragma once
using namespace System;

namespace GemeloDigitalModel {

    public ref class CicloModel {
    private:
        String^ id;
        double  horasTrabajadas;
        String^ estado; // "PENDIENTE" o "REPORTADO"

    public:
        CicloModel(String^ id, double horasTrabajadas, String^ estado) {
            this->id = id;
            this->horasTrabajadas = horasTrabajadas;
            this->estado = estado;
        }

        property String^ Id {
            String^ get() { return id; }
        }

        property double HorasTrabajadas {
            double get() { return horasTrabajadas; }
            void   set(double value) { horasTrabajadas = value; }
        }

        property String^ Estado {
            String^ get() { return estado; }
            void    set(String^ value) { estado = value; }
        }
    };
}