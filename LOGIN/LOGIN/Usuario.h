#pragma once
using namespace System;

public ref class Usuario abstract {
protected:
    String^ _nombre;
    String^ _contrasena;
    String^ _rol;

public:
    Usuario(String^ nombre, String^ contrasena, String^ rol) {
        _nombre = nombre;
        _contrasena = contrasena;
        _rol = rol;
    }

    String^ getNombre() {
        return _nombre;
    }

    String^ getRol() {
        return _rol;
    }

    virtual void mostrarAcciones() abstract;
};