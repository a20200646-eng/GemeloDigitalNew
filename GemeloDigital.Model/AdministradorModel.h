#pragma once
#include "UsuarioModel.h"
using namespace System;

namespace GemeloDigitalModel {

    public ref class AdministradorModel : public UsuarioModel {
    private:
        int nivelAcceso;
		String^ turno;

    public:
        AdministradorModel(String^ id, String^ nombre, String^ contrasena, int nivelAcceso, String^ turno)
            : UsuarioModel(id, nombre, contrasena, RolUsuario::ADMINISTRADOR) {
            this->nivelAcceso = nivelAcceso;
            this->turno = turno;
        }

        property int NivelAcceso {
            int  get() { return nivelAcceso; }
            void set(int value) { nivelAcceso = value; }
        }

        property String^ Turno {
            String^ get() { return turno; }
            void set(String^ value) { turno = value; }
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