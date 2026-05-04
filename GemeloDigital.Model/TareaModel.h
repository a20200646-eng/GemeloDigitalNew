#pragma once
using namespace System;

namespace GemeloDigitalModel {

    public ref class TareaModel abstract {
    protected:
        int id;
        String^ estado;

    public:
        TareaModel(int id, String^ estado) {
            this->id = id;
            this->estado = estado;
        }

        int getId() { return id; }
        String^ getEstado() { return estado; }
        void setEstado(String^ e) { estado = e; }

        virtual void dataReport() = 0;
    };
}