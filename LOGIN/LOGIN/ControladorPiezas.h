#pragma once
#include "Usuario.h"

public ref class ControladorPiezas : public Usuario {
public:
    ControladorPiezas(String^ n, String^ c)
        : Usuario(n, c, "Controlador") {
    }

    void registrarPieza(Object^ pieza) {}

    virtual void mostrarAcciones() override {}
};