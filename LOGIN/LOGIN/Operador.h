#pragma once
#include "Usuario.h"
public ref class Operador : public Usuario {
public:
    Operador(String^ n, String^ c)
        : Usuario(n, c, "Operador") {
    }

    void confirmarCiclo() {}

    virtual void mostrarAcciones() override {}
};