#pragma once
#include "UsuarioModel.h"
using namespace System;

namespace GemeloDigitalModel {

    public ref class GestorInventarioModel : public UsuarioModel {
    private:
        int totalPiezasGestionadas;

    public:
        GestorInventarioModel(String^ id, String^ nombre, String^ contrasena)
            : UsuarioModel(id, nombre, contrasena, RolUsuario::GESTOR) {
            this->totalPiezasGestionadas = 0;
        }

        property int TotalPiezasGestionadas {
            int  get() { return totalPiezasGestionadas; }
            void set(int value) { totalPiezasGestionadas = value; }
        }

        virtual void dataReport() override {
            Console::WriteLine("=== GESTOR DE INVENTARIO ===");
            Console::WriteLine("ID: " + Id);
            Console::WriteLine("|Nombre: " + Nombre);
            Console::WriteLine("|Rol: " + Rol.ToString());
            Console::WriteLine("|Piezas gestionadas: " + TotalPiezasGestionadas);
        }
    };
}