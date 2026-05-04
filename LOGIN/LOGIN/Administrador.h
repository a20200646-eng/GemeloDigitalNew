#pragma once
#include "Usuario.h"

public ref class Administrador : public Usuario {
public:
    Administrador(String^ n, String^ c)
        : Usuario(n, c, "Admin") {
    }

    void gestionarCuentas() {}

    virtual void mostrarAcciones() override {}
};