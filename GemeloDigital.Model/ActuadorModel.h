#pragma once
#include "ComponenteRoboticoModel.h"
using namespace System;


namespace GemeloDigitalModel {

    public ref class ActuadorModel abstract : public ComponenteRoboticoModel {
    public:
        ActuadorModel(String^ id, String^ nombre, bool activo)
            : ComponenteRoboticoModel(id, nombre, activo) {
        }

        virtual void dataReport() override = 0;
    };
}


