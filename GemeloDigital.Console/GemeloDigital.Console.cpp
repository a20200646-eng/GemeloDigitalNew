#include "pch.h"

using namespace System;
using namespace System::Collections::Generic;
using namespace GemeloDigitalModel;
using namespace GemeloDigitalController;

int main(array<System::String ^> ^args)
{
        // ═══════════════════════════════════════════════════
        // PASO 1: Crear la Estacion Body Framing
        // ═══════════════════════════════════════════════════
        EstacionBodyFramingController^ ctrlEstacion = gcnew EstacionBodyFramingController();
        ctrlEstacion->agregar(1); // Crea estacion con ID=1
		EstacionBodyFramingModel^ estacion = ctrlEstacion->buscarPorId(1);//buscamos la estacion y guardamos en variable para usarla luego.

        // ═══════════════════════════════════════════════════
        // PASO 2: Crear los 3 brazos roboticos
        // ═══════════════════════════════════════════════════
		BrazoRoboticoController^ ctrlBrazo = gcnew BrazoRoboticoController(); //creamos el controlador de brazo para agregar los brazos a la estacion

		ctrlBrazo->agregar(1, RolBrazo::LATERAL_IZQ);// Brazo 1: Lateral Izquierdo (6DOF)
		ctrlBrazo->agregar(2, RolBrazo::LATERAL_DER);// Brazo 2: Lateral Derecho (6DOF)
		ctrlBrazo->agregar(3, RolBrazo::CENTRAL_SUP);// Brazo 3: Central Superior (4DOF)

        // Agregar articulaciones al Brazo 1 (6DOF)
		ctrlBrazo->agregarArticulacion(1, 101, "Art1", 0.0, -180.0, 180.0);// Articulacion 1: Base rotatoria - (ID brazo, ID articulacion, nombre, posicion inicial, limite inferior, limite superior)
		ctrlBrazo->agregarArticulacion(1, 102, "Art2", 0.0, -90.0, 90.0);// Articulacion 2: Hombro

        // Asignar gripper al Brazo 1
        ctrlBrazo->asignarGripper(1, 201, "Gripper1", 0.0, 50.0, true);// Gripper 1: Pinza - (ID brazo, ID gripper, nombre, posicion inicial, fuerza, estado - abierto o cerrado)

        // Agregar sensores al Brazo 1
        ctrlBrazo->agregarSensorPosicion(1, 301, "SensPos1", 0.0, 0.5);// Sensor de posicion - (ID brazo, ID sensor, nombre, angulo medido, rango)
        ctrlBrazo->agregarSensorFuerza(1, 401, "SensFuerza1", 0.0, 10.0, 100.0);// Sensor de fuerza - (ID brazo, ID sensor, nombre, fuerza actual, limite inferior, limite superior)
        // Vincular brazos a la estacion
		ctrlEstacion->agregarBrazo(1, ctrlBrazo->buscarPorId(1)); //Agregamos el brazo 1 a la estacion 1 (ID estacion, Objeto Brazo)
        ctrlEstacion->agregarBrazo(1, ctrlBrazo->buscarPorId(2)); //Agregamos el brazo 2 a la estacion 1
        ctrlEstacion->agregarBrazo(1, ctrlBrazo->buscarPorId(3)); //Agregamos el brazo 3 a la estacion 1

        // ═══════════════════════════════════════════════════
        // PASO 3: Registrar un Operador
        // ═══════════════════════════════════════════════════
        OperadorController^ ctrlOperador = gcnew OperadorController();
		ctrlOperador->agregar(1, "Juan Perez", "pass123", "MANANA"); // Agrega un operador con ID=1, nombre, contraseña y turno
		OperadorModel^ operador = ctrlOperador->buscarPorId(1); //buscamos el operador y guardamos en variable para usarla luego.
		operador->dataReport();// Mostramos los datos del operador registrado

        // ═══════════════════════════════════════════════════
        // PASO 4: Registrar piezas en inventario
        // ═══════════════════════════════════════════════════
        PanelLateralController^ ctrlPanel = gcnew PanelLateralController();
		ctrlPanel->agregar(1, "Acero", 25.5, LadoPanel::IZQUIERDO, 8);// Agrega un panel lateral con ID=1, material, peso, lado y puntos de anclaje
        ctrlPanel->agregar(2, "Acero", 25.5, LadoPanel::DERECHO, 8);// Agrega un panel lateral con ID=2, material, peso, lado y puntos de anclaje
        EstructuraTechoController^ ctrlTecho = gcnew EstructuraTechoController();
		ctrlTecho->agregar(3, "Aluminio", 18.0, 6, 1.45);// Agrega una estructura de techo con ID=3, material, peso, puntos de union y anchura

        // ═══════════════════════════════════════════════════
        // PASO 5: Iniciar ciclo con ControladorSistema
        // ═══════════════════════════════════════════════════
        ControladorSistema^ controlador = gcnew ControladorSistema();
        controlador->setEstacion(estacion);
        controlador->iniciarCiclo();   // EstadoSistema -> INICIALIZANDO
        controlador->activar();        // EstadoSistema -> OPERATIVO

        // ═══════════════════════════════════════════════════
        // PASO 6: Crear y ejecutar tareas
        // ═══════════════════════════════════════════════════
        TareaPosicionarController^ ctrlPos = gcnew TareaPosicionarController();
        ctrlPos->agregar(1, 90.0, 0.5);  // Brazo 1 posiciona panel izq
        ctrlPos->agregar(2, 90.0, 0.5);  // Brazo 2 posiciona panel der
        ctrlPos->agregar(3, 45.0, 0.5);  // Brazo 3 posiciona techo

        // Cambiar estado de tareas
        ctrlPos->modificar(1, "E", "COMPLETADA");
        ctrlPos->modificar(2, "E", "COMPLETADA");
        ctrlPos->modificar(3, "E", "COMPLETADA");

        // Tarea coordinada: los 3 brazos sostienen simultaneamente
        TareaCoordinadaController^ ctrlCoord = gcnew TareaCoordinadaController();
        ctrlCoord->agregar(10, 3); // totalRequerido = 3
        ctrlCoord->modificar(10, "TC", "3"); // Los 3 confirmaron
        ctrlCoord->modificar(10, "E", "COMPLETADA");

        // Soldadura
        TareaSoldarController^ ctrlSold = gcnew TareaSoldarController();
        ctrlSold->agregar(20, 8, 850.0); // 8 puntos, 850 grados
        ctrlSold->modificar(20, "PC", "8"); // 8 puntos completados
        ctrlSold->modificar(20, "E", "COMPLETADA");

        // ═══════════════════════════════════════════════════
        // PASO 7: Registrar eventos del ciclo
        // ═══════════════════════════════════════════════════
        EventoTareaController^ ctrlEvTarea = gcnew EventoTareaController();
        ctrlEvTarea->agregar(1, "2026-05-04 08:30:00",
            "Posicionamiento completado", 1, "OK");
        ctrlEvTarea->agregar(2, "2026-05-04 08:31:00",
            "Soldadura completada", 20, "OK");

        // ═══════════════════════════════════════════════════
        // PASO 8: Generar reporte de costos
        // ═══════════════════════════════════════════════════
        ReporteController^ ctrlReporte = gcnew ReporteController();
        ctrlReporte->agregar(1, 1, 0.5, 120.0); // 1 ciclo, 0.5 hrs, $120
        ReporteCostos^ reporte = ctrlReporte->buscarPorId(1);
        reporte->dataReport();

        // ═══════════════════════════════════════════════════
        // PASO 9: Finalizar ciclo
        // ═══════════════════════════════════════════════════
        controlador->finalizarCiclo(); // EstadoSistema -> INACTIVO
        estacion->dataReport();

    return 0;
}
