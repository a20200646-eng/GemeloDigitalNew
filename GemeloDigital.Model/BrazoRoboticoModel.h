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
        int                        id;
        List<ArticulacionModel^>^ articulaciones;
        GripperModel^ gripper;
        List<SensorModel^>^ sensores;
        RolBrazo                   rol;
        EstadoBrazo                estado;

    public:
        BrazoRoboticoModel(int id, RolBrazo rol) {
            this->id = id;
            this->rol = rol;
            this->estado = EstadoBrazo::REPOSO;
            this->gripper = nullptr;
            articulaciones = gcnew List<ArticulacionModel^>();
            sensores = gcnew List<SensorModel^>();
        }

        property int Id {
            int get() { return id; }
        }

        property RolBrazo Rol {
            RolBrazo get() { return rol; }
        }

        property EstadoBrazo Estado {
            EstadoBrazo get() { return estado; }
            void        set(EstadoBrazo value) { estado = value; }
        }

        property GripperModel^ Gripper {
            GripperModel^ get() { return gripper; }
            void          set(GripperModel^ value) { gripper = value; }
        }

        property List<ArticulacionModel^>^ Articulaciones {
            List<ArticulacionModel^>^ get() { return articulaciones; }
        }

        property List<SensorModel^>^ Sensores {
            List<SensorModel^>^ get() { return sensores; }
        }

        // Metodos de agregacion — se mantienen como metodos,
        // no como properties, porque son operaciones, no accesos a datos
        void agregarArticulacion(ArticulacionModel^ a) { articulaciones->Add(a); }
        void agregarSensor(SensorModel^ s) { sensores->Add(s); }

        void dataReport() {
            Console::WriteLine("=== BRAZO ROBOTICO ===");
            Console::WriteLine("ID: " + Id);
            Console::WriteLine("|Rol: " + Rol.ToString());
            Console::WriteLine("|Estado: " + Estado.ToString());

            Console::WriteLine("|-- Articulaciones (" + Articulaciones->Count + "):");
            for each (ArticulacionModel ^ a in Articulaciones)
                a->dataReport();

            Console::WriteLine("|-- Gripper:");
            if (Gripper != nullptr)
                Gripper->dataReport();
            else
                Console::WriteLine("  Sin gripper asignado");

            Console::WriteLine("|-- Sensores (" + Sensores->Count + "):");
            for each (SensorModel ^ s in Sensores)
                s->dataReport();
        }
    };
}