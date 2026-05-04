#pragma once
using namespace System;
using namespace System::Collections::Generic;
using namespace GemeloDigitalModel;

namespace GemeloDigitalController {

    public ref class BrazoRoboticoController {
    private:
        List<BrazoRoboticoModel^>^ repositorio;

    public:
        BrazoRoboticoController() {
            repositorio = gcnew List<BrazoRoboticoModel^>();
        }

        // CREATE
        bool agregar(int id, RolBrazo rol) {
            BrazoRoboticoModel^ b = buscarPorId(id);
            if (b == nullptr) {
                repositorio->Add(gcnew BrazoRoboticoModel(id, rol));
                return true;
            }
            return false;
        }

        // READ - por ID
        BrazoRoboticoModel^ buscarPorId(int id) {
            for each (BrazoRoboticoModel ^ b in repositorio) {
                if (b->getId() == id) return b;
            }
            return nullptr;
        }

        // READ - todos
        List<BrazoRoboticoModel^>^ obtenerTodos() {
            return repositorio;
        }

        // UPDATE - solo estado es modificable
        // E: estado
        bool modificar(int id, String^ opcion, String^ valor) {
            BrazoRoboticoModel^ b = buscarPorId(id);
            if (b != nullptr) {
                if (opcion->Equals("E")) {
                    if (valor->Equals("REPOSO"))          b->setEstado(EstadoBrazo::REPOSO);
                    else if (valor->Equals("CALIBRANDO")) b->setEstado(EstadoBrazo::CALIBRANDO);
                    else if (valor->Equals("POSICIONANDO"))b->setEstado(EstadoBrazo::POSICIONANDO);
                    else if (valor->Equals("SOLDANDO"))   b->setEstado(EstadoBrazo::SOLDANDO);
                    else if (valor->Equals("ERROR"))      b->setEstado(EstadoBrazo::ERROR);
                    else if (valor->Equals("PAUSA"))      b->setEstado(EstadoBrazo::PAUSA);
                    else return false;
                }
                else return false;
                return true;
            }
            return false;
        }

        // DELETE
        bool eliminar(int id) {
            BrazoRoboticoModel^ b = buscarPorId(id);
            if (b != nullptr) {
                repositorio->Remove(b);
                return true;
            }
            return false;
        }

        // Gestión de componentes internos del brazo
        bool agregarArticulacion(int idBrazo, int idArt, String^ nombre,
            double anguloActual, double anguloMin, double anguloMax) {
            BrazoRoboticoModel^ b = buscarPorId(idBrazo);
            if (b != nullptr) {
                b->agregarArticulacion(gcnew ArticulacionModel(
                    idArt, nombre, true, anguloActual, anguloMin, anguloMax));
                return true;
            }
            return false;
        }

        bool asignarGripper(int idBrazo, int idGripper, String^ nombre,
            double apertura, double fuerzaAgarre, bool abierto) {
            BrazoRoboticoModel^ b = buscarPorId(idBrazo);
            if (b != nullptr) {
                b->setGripper(gcnew GripperModel(
                    idGripper, nombre, true, apertura, fuerzaAgarre, abierto));
                return true;
            }
            return false;
        }

        bool agregarSensorPosicion(int idBrazo, int idSensor, String^ nombre,
            double anguloMedido, double tolerancia) {
            BrazoRoboticoModel^ b = buscarPorId(idBrazo);
            if (b != nullptr) {
                b->agregarSensor(gcnew SensorPosicionModel(
                    idSensor, nombre, true, anguloMedido, tolerancia));
                return true;
            }
            return false;
        }

        bool agregarSensorFuerza(int idBrazo, int idSensor, String^ nombre,
            double fuerzaActual, double fuerzaMin, double fuerzaMax) {
            BrazoRoboticoModel^ b = buscarPorId(idBrazo);
            if (b != nullptr) {
                b->agregarSensor(gcnew SensorFuerzaModel(
                    idSensor, nombre, true, fuerzaActual, fuerzaMin, fuerzaMax));
                return true;
            }
            return false;
        }
    };
}