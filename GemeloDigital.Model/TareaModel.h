#pragma once
using namespace System;

namespace GemeloDigitalModel {

    public ref class TareaModel abstract {
    protected:
        String^ id;
        String^ estado;

    public:
        TareaModel(String^ id, String^ estado) {
            this->id = id;
            this->estado = estado;
        }

        property String^ Id {
            String^ get() { return id; }
        }

        property String^ Estado {
            String^ get() { return estado; }
            void    set(String^ value) { estado = value; }
        }

        virtual void dataReport() = 0;
    };
}