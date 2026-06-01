#pragma once
#include "BrazoRoboticoModel.h"
#include "Enumeraciones.h"
using namespace System;
using namespace System::Collections::Generic;

namespace GemeloDigitalModel {

    public ref class EstacionBodyFramingModel {
    private:
        int                        id;
        List<BrazoRoboticoModel^>^ brazos;
        EstadoSistema              estadoSistema;

    public:
        EstacionBodyFramingModel(int id) {
            this->id = id;
            this->estadoSistema = EstadoSistema::INACTIVO;
            brazos = gcnew List<BrazoRoboticoModel^>();
        }

        property int Id {
            int get() { return id; }
        }

		property EstadoSistema EstadoSistemaActual { //EstadoSistema es un enum definido en Enumeraciones.h y EstadoSistemaActual es el nombre de la propiedad
            EstadoSistema get() { return estadoSistema; }
            void          set(EstadoSistema value) { estadoSistema = value; }
        }

        property List<BrazoRoboticoModel^>^ Brazos {
            List<BrazoRoboticoModel^>^ get() { return brazos; }
        }

        // Metodo de agregacion — responsabilidad del Model
        void agregarBrazo(BrazoRoboticoModel^ b) { brazos->Add(b); }

        void dataReport() {
            Console::WriteLine("====== ESTACION BODY FRAMING ======");
            Console::WriteLine("ID: " + Id);
            Console::WriteLine("|Estado Sistema: " + EstadoSistemaActual.ToString());
            Console::WriteLine("|Brazos registrados: " + Brazos->Count);
            Console::WriteLine("");
            for each (BrazoRoboticoModel ^ b in Brazos) {
                b->dataReport();
                Console::WriteLine("");
            }
        }
    };
}