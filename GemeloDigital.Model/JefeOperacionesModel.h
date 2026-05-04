#pragma once
#include "UsuarioModel.h"
using namespace System;

namespace GemeloDigitalModel {

    public ref class JefeOperacionesModel : public UsuarioModel {
    private:
        int nivelAutorizacion;

    public:
        JefeOperacionesModel(int id, String^ nombre, String^ contrasena, int nivelAutorizacion)
            : UsuarioModel(id, nombre, contrasena, RolUsuario::JEFE) {
            this->nivelAutorizacion = nivelAutorizacion;
        }

        int getNivelAutorizacion() { return nivelAutorizacion; }
        void setNivelAutorizacion(int n) { nivelAutorizacion = n; }

        virtual void dataReport() override {
            Console::WriteLine("=== JEFE DE OPERACIONES ===");
            Console::WriteLine("ID: " + id);
            Console::WriteLine("|Nombre: " + nombre);
            Console::WriteLine("|Rol: " + rol.ToString());
            Console::WriteLine("|Nivel Autorizacion: " + nivelAutorizacion);
        }
    };
}