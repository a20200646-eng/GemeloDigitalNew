#pragma once
#include "UsuarioModel.h"
using namespace System;

namespace GemeloDigitalModel {

    public ref class AdministradorModel : public UsuarioModel {
    private:
        int nivelAcceso;

    public:
        AdministradorModel(int id, String^ nombre, String^ contrasena, int nivelAcceso)
            : UsuarioModel(id, nombre, contrasena, RolUsuario::ADMINISTRADOR) {
            this->nivelAcceso = nivelAcceso;
        }

        int getNivelAcceso() { return nivelAcceso; }
        void setNivelAcceso(int n) { nivelAcceso = n; }

        virtual void dataReport() override {
            Console::WriteLine("=== ADMINISTRADOR ===");
            Console::WriteLine("ID: " + id);
            Console::WriteLine("|Nombre: " + nombre);
            Console::WriteLine("|Rol: " + rol.ToString());
            Console::WriteLine("|Nivel Acceso: " + nivelAcceso);
        }
    };
}