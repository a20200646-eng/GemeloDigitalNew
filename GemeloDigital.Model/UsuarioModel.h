#pragma once
#include "Enumeraciones.h"
using namespace System;

namespace GemeloDigitalModel {

    public ref class UsuarioModel abstract {
    protected:
        String^ id;
        String^ nombre;
        String^ contrasena;
        RolUsuario rol;

    public:
        UsuarioModel(String^ id, String^ nombre, String^ contrasena, RolUsuario rol) {
            this->id = id;
            this->nombre = nombre;
            this->contrasena = contrasena;
            this->rol = rol;
        }

        property String^ Id {
            String^ get() { return id; }
        }

        property String^ Nombre {
            String^ get() { return nombre; }
            void    set(String^ value) { nombre = value; }
        }

        property String^ Contrasena {
            String^ get() { return contrasena; }
            void    set(String^ value) { contrasena = value; }
        }

        property RolUsuario Rol {
            RolUsuario get() { return rol; }
        }

        virtual void dataReport() = 0;
    };
}