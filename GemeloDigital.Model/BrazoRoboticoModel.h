#pragma once
#include "ArticulacionModel.h"
#include "GripperModel.h"
#include "SensorModel.h"
#include "Enumeraciones.h"
using namespace System;
using namespace System::Collections::Generic;


namespace GemeloDigitalModel {

    public ref class BrazoRoboticoModel {
    private:
        int id;
        List<ArticulacionModel^>^ articulaciones;
        GripperModel^ gripper;
        List<SensorModel^>^ sensores;
        RolBrazo rol;
        EstadoBrazo estado;

    public:
        BrazoRoboticoModel(int id, RolBrazo rol) {
            this->id = id;
            this->rol = rol;
            this->estado = EstadoBrazo::REPOSO;
            this->gripper = nullptr;
            articulaciones = gcnew List<ArticulacionModel^>();
            sensores = gcnew List<SensorModel^>();
        }

        // Getters
        int getId() { return id; }
        RolBrazo getRol() { return rol; }
        EstadoBrazo getEstado() { return estado; }
        GripperModel^ getGripper() { return gripper; }
        List<ArticulacionModel^>^ getArticulaciones() { return articulaciones; }
        List<SensorModel^>^ getSensores() { return sensores; }

        // Setters
        void setEstado(EstadoBrazo e) { estado = e; }
        void setGripper(GripperModel^ g) { gripper = g; }

        // Agregar componentes internos
        void agregarArticulacion(ArticulacionModel^ a) { articulaciones->Add(a); }
        void agregarSensor(SensorModel^ s) { sensores->Add(s); }

        void dataReport() {
            Console::WriteLine("=== BRAZO ROBOTICO ===");
            Console::WriteLine("ID: " + id);
            Console::WriteLine("|Rol: " + rol.ToString());
            Console::WriteLine("|Estado: " + estado.ToString());

            Console::WriteLine("|-- Articulaciones (" + articulaciones->Count + "):");
            for each (ArticulacionModel ^ a in articulaciones) {
                a->dataReport();
            }

            Console::WriteLine("|-- Gripper:");
            if (gripper != nullptr) {
                gripper->dataReport();
            }
            else {
                Console::WriteLine("  Sin gripper asignado");
            }

            Console::WriteLine("|-- Sensores (" + sensores->Count + "):");
            for each (SensorModel ^ s in sensores) {
                s->dataReport();
            }
        }
    };
}