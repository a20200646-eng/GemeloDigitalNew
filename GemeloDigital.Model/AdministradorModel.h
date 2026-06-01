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

        property int NivelAcceso {
            int  get() { return nivelAcceso; }
            void set(int value) { nivelAcceso = value; }
        }

        virtual void dataReport() override {
            Console::WriteLine("=== ADMINISTRADOR ===");
            Console::WriteLine("ID: " + Id);
            Console::WriteLine("|Nombre: " + Nombre);
            Console::WriteLine("|Rol: " + Rol.ToString());
            Console::WriteLine("|Nivel Acceso: " + NivelAcceso);
        }
    };
}