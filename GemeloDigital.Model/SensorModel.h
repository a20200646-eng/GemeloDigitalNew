
#pragma once
#include "ComponenteRoboticoModel.h"
using namespace System;


namespace GemeloDigitalModel {

    public ref class SensorModel abstract : public ComponenteRoboticoModel {
    public:
        SensorModel(String^ id, String^ nombre, bool activo)
            : ComponenteRoboticoModel(id, nombre, activo) {
        }

        virtual void dataReport() override = 0;
    };
}