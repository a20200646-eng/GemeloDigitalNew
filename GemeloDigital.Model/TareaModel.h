#pragma once
using namespace System;

namespace GemeloDigitalModel {

    public ref class TareaModel abstract {
    protected:
        int     id;
        String^ estado;

    public:
        TareaModel(int id, String^ estado) {
            this->id = id;
            this->estado = estado;
        }

        property int Id {
            int get() { return id; }
        }

        property String^ Estado {
            String^ get() { return estado; }
            void    set(String^ value) { estado = value; }
        }

        virtual void dataReport() = 0;
    };
}