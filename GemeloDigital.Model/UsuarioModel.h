#pragma once
#include "Enumeraciones.h"
using namespace System;

namespace GemeloDigitalModel {

    public ref class UsuarioModel abstract {
    protected:
        int id;
        String^ nombre;
        String^ contrasena;
        RolUsuario rol;

    public:
        UsuarioModel(int id, String^ nombre, String^ contrasena, RolUsuario rol) {
            this->id = id;
            this->nombre = nombre;
            this->contrasena = contrasena;
            this->rol = rol;
        }

        // Getters
        int getId() { return id; }
        String^ getNombre() { return nombre; }
        String^ getContrasena() { return contrasena; }
        RolUsuario getRol() { return rol; }

        // Setters - id no se modifica
        void setNombre(String^ n) { nombre = n; }
        void setContrasena(String^ c) { contrasena = c; }

        virtual void dataReport() = 0;
    };
}