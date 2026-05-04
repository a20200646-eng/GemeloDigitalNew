#pragma once
#include "Usuario.h"

public ref class JefeOperaciones : public Usuario {
public:
    JefeOperaciones(String^ n, String^ c)
        : Usuario(n, c, "Jefe") {
    }

    void aprobarSecuencia() {
  
    }

    void detenerLinea() {
     
    }

    virtual void mostrarAcciones() override {}
};