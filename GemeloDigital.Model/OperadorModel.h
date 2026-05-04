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

        String^ getTurno() { return turno; }
        void setTurno(String^ t) { turno = t; }

        virtual void dataReport() override {
            Console::WriteLine("=== OPERADOR ===");
            Console::WriteLine("ID: " + id);
            Console::WriteLine("|Nombre: " + nombre);
            Console::WriteLine("|Rol: " + rol.ToString());
            Console::WriteLine("|Turno: " + turno);
        }
    };
}