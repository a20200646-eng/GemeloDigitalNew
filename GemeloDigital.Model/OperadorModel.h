#pragma once
#include "UsuarioModel.h"
using namespace System;

namespace GemeloDigitalModel {

    public ref class OperadorModel : public UsuarioModel {
    private:
        String^ turno;

    public:
        OperadorModel(int id, String^ nombre, String^ contrasena, String^ turno)
            : UsuarioModel(id, nombre, contrasena, RolUsuario::OPERADOR) {
            this->turno = turno;
        }

        property String^ Turno {
            String^ get() { return turno; }
            void    set(String^ value) { turno = value; }
        }

        virtual void dataReport() override {
            Console::WriteLine("=== OPERADOR ===");
            Console::WriteLine("ID: " + Id);
            Console::WriteLine("|Nombre: " + Nombre);
            Console::WriteLine("|Rol: " + Rol.ToString());
            Console::WriteLine("|Turno: " + Turno);
        }
    };
}