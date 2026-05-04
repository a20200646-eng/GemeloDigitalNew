#pragma once
#include "BrazoRoboticoModel.h"
#include "Enumeraciones.h"
using namespace System;
using namespace System::Collections::Generic;

namespace GemeloDigitalModel {

    public ref class EstacionBodyFramingModel {
    private:
        int id;
        List<BrazoRoboticoModel^>^ brazos;
        EstadoSistema estadoSistema;

    public:
        EstacionBodyFramingModel(int id) {
            this->id = id;
            this->estadoSistema = EstadoSistema::INACTIVO;
            brazos = gcnew List<BrazoRoboticoModel^>();
        }

        // Getters
        int getId() { return id; }
        EstadoSistema getEstadoSistema() { return estadoSistema; }
        List<BrazoRoboticoModel^>^ getBrazos() { return brazos; }

        // Setters
        void setEstadoSistema(EstadoSistema e) { estadoSistema = e; }

        // Agregar brazo
        void agregarBrazo(BrazoRoboticoModel^ b) { brazos->Add(b); }

        void dataReport() {
            Console::WriteLine("====== ESTACION BODY FRAMING ======");
            Console::WriteLine("ID: " + id);
            Console::WriteLine("|Estado Sistema: " + estadoSistema.ToString());
            Console::WriteLine("|Brazos registrados: " + brazos->Count);
            Console::WriteLine("");
            for each (BrazoRoboticoModel ^ b in brazos) {
                b->dataReport();
                Console::WriteLine("");
            }
        }
    };
}
