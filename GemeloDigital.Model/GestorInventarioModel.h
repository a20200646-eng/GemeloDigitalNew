#pragma once
#include "UsuarioModel.h"
using namespace System;

namespace GemeloDigitalModel {

    public ref class GestorInventarioModel : public UsuarioModel {
    private:
        int totalPiezasGestionadas;

    public:
        GestorInventarioModel(int id, String^ nombre, String^ contrasena)
            : UsuarioModel(id, nombre, contrasena, RolUsuario::GESTOR) {
            this->totalPiezasGestionadas = 0;
        }

        int getTotalPiezasGestionadas() { return totalPiezasGestionadas; }
        void setTotalPiezasGestionadas(int t) { totalPiezasGestionadas = t; }

        virtual void dataReport() override {
            Console::WriteLine("=== GESTOR DE INVENTARIO ===");
            Console::WriteLine("ID: " + id);
            Console::WriteLine("|Nombre: " + nombre);
            Console::WriteLine("|Rol: " + rol.ToString());
            Console::WriteLine("|Piezas gestionadas: " + totalPiezasGestionadas);
        }
    };
}
