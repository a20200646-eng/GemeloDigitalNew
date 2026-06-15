#pragma once
using namespace System;
using namespace System::Collections::Generic;
using namespace GemeloDigitalModel;

namespace GemeloDigitalController {

    public ref class ControladorSistema {
    private:
        EstacionBodyFramingModel^ estacion;
        bool sistemaActivo;

    public:
        ControladorSistema() {
            estacion = nullptr;
            sistemaActivo = false;
        }

        property EstacionBodyFramingModel^ Estacion {
            EstacionBodyFramingModel^ get() { return estacion; }
            void                      set(EstacionBodyFramingModel^ value) { estacion = value; }
        }

        property bool SistemaActivo {
            bool get() { return sistemaActivo; }
        }

        // Iniciar ciclo de operacion
        bool iniciarCiclo() {
            if (estacion != nullptr && !sistemaActivo) {
                estacion->EstadoSistemaActual = EstadoSistema::INICIALIZANDO;
                sistemaActivo = true;
                Console::WriteLine("[SISTEMA] Ciclo iniciado.");
                return true;
            }
            Console::WriteLine("[SISTEMA] No se puede iniciar — estacion no asignada o ya activa.");
            return false;
        }

        // Pasar a estado operativo
        bool activar() {
            if (estacion != nullptr && sistemaActivo) {
                estacion->EstadoSistemaActual = EstadoSistema::OPERATIVO;
                Console::WriteLine("[SISTEMA] Sistema operativo.");
                return true;
            }
            return false;
        }

        // Pausar sistema
        bool pausar() {
            if (estacion != nullptr && sistemaActivo) {
                estacion->EstadoSistemaActual = EstadoSistema::PAUSADO;
                Console::WriteLine("[SISTEMA] Sistema pausado.");
                return true;
            }
            return false;
        }

        // Reanudar sistema
        bool reanudar() {
            if (estacion != nullptr && sistemaActivo) {
                estacion->EstadoSistemaActual = EstadoSistema::OPERATIVO;
                Console::WriteLine("[SISTEMA] Sistema reanudado.");
                return true;
            }
            return false;
        }

        // Detener emergencia
        bool detenerEmergencia() {
            if (estacion != nullptr) {
                estacion->EstadoSistemaActual = EstadoSistema::EMERGENCIA;
                sistemaActivo = false;
                Console::WriteLine("[SISTEMA] DETENCION DE EMERGENCIA ACTIVADA.");
                return true;
            }
            return false;
        }

        // Finalizar ciclo
        bool finalizarCiclo() {
            if (estacion != nullptr && sistemaActivo) {
                estacion->EstadoSistemaActual = EstadoSistema::INACTIVO;
                sistemaActivo = false;
                Console::WriteLine("[SISTEMA] Ciclo finalizado.");
                return true;
            }
            return false;
        }

        void dataReport() {
            Console::WriteLine("=== CONTROLADOR DEL SISTEMA ===");
            Console::WriteLine("|Sistema Activo: " + SistemaActivo);
            if (Estacion != nullptr)
                Estacion->dataReport();
            else
                Console::WriteLine("|Estacion: No asignada");
        }
    };
}