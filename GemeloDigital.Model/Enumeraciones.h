#pragma once
using namespace System;

namespace GemeloDigitalModel {

    public enum class RolBrazo {
        LATERAL_IZQ,
        LATERAL_DER,
        CENTRAL_SUP
    };

    public enum class EstadoBrazo {
        REPOSO,
        CALIBRANDO,
        POSICIONANDO,
        SOLDANDO,
        EN_ERROR,
        PAUSA
    };

    public enum class EstadoPieza {
        DISPONIBLE,
        EN_PROCESO,
        ENSAMBLADA,
        DEFECTUOSA
    };

    public enum class TipoEstacion {
        PANEL_IZQ, 
        PANEL_DER, 
        TECHO 
    };

    public enum class RolUsuario {
        JEFE,
        OPERADOR,
        GESTOR,
        ADMINISTRADOR
    };

    public enum class LadoPanel {
        IZQUIERDO,
        DERECHO
    };

    public enum class NivelEvento {
        INFO,
        ALERTA,
        ERROR
    };

    public enum class EstadoSistema {
        INACTIVO,
        INICIALIZANDO,
        OPERATIVO,
        PAUSADO,
        EMERGENCIA
    };
}
