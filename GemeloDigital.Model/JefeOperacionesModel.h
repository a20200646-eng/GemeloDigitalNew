#pragma once
#include "UsuarioModel.h"
using namespace System;

namespace GemeloDigitalModel {

    public ref class JefeOperacionesModel : public UsuarioModel {
    private:
        int nivelAutorizacion;

    public:
        JefeOperacionesModel(String^ id, String^ nombre, String^ contrasena, int nivelAutorizacion)
            : UsuarioModel(id, nombre, contrasena, RolUsuario::JEFE) {
            this->nivelAutorizacion = nivelAutorizacion;
        }

        property int NivelAutorizacion {
            int  get() { return nivelAutorizacion; }
            void set(int value) { nivelAutorizacion = value; }
        }

        virtual void dataReport() override {
            Console::WriteLine("=== JEFE DE OPERACIONES ===");
            Console::WriteLine("ID: " + Id);
            Console::WriteLine("|Nombre: " + Nombre);
            Console::WriteLine("|Rol: " + Rol.ToString());
            Console::WriteLine("|Nivel Autorizacion: " + NivelAutorizacion);
        }
    };
}