#pragma once
using namespace System;
using namespace System::Collections::Generic;
using namespace GemeloDigitalModel;

namespace GemeloDigitalController {

    public ref class EstacionBodyFramingController {
    private:
        List<EstacionBodyFramingModel^>^ repositorio;

    public:
        EstacionBodyFramingController() {
            repositorio = gcnew List<EstacionBodyFramingModel^>();
        }

        // CREATE
        bool agregar(int id) {
            EstacionBodyFramingModel^ e = buscarPorId(id);
            if (e == nullptr) {
                repositorio->Add(gcnew EstacionBodyFramingModel(id));
                return true;
            }
            return false;
        }

        // READ - por ID
        EstacionBodyFramingModel^ buscarPorId(int id) {
            for each (EstacionBodyFramingModel ^ e in repositorio) {
                if (e->getId() == id) return e;
            }
            return nullptr;
        }

        // READ - todos
        List<EstacionBodyFramingModel^>^ obtenerTodos() {
            return repositorio;
        }

        // UPDATE - solo estado del sistema es modificable
        // E: estadoSistema
        bool modificar(int id, String^ opcion, String^ valor) {
            EstacionBodyFramingModel^ e = buscarPorId(id);
            if (e != nullptr) {
                if (opcion->Equals("E")) {
                    if (valor->Equals("INACTIVO"))           e->setEstadoSistema(EstadoSistema::INACTIVO);
                    else if (valor->Equals("INICIALIZANDO")) e->setEstadoSistema(EstadoSistema::INICIALIZANDO);
                    else if (valor->Equals("OPERATIVO"))     e->setEstadoSistema(EstadoSistema::OPERATIVO);
                    else if (valor->Equals("PAUSADO"))       e->setEstadoSistema(EstadoSistema::PAUSADO);
                    else if (valor->Equals("EMERGENCIA"))    e->setEstadoSistema(EstadoSistema::EMERGENCIA);
                    else return false;
                }
                else return false;
                return true;
            }
            return false;
        }

        // DELETE
        bool eliminar(int id) {
            EstacionBodyFramingModel^ e = buscarPorId(id);
            if (e != nullptr) {
                repositorio->Remove(e);
                return true;
            }
            return false;
        }

        // Agregar brazo a la estacion
        bool agregarBrazo(int idEstacion, BrazoRoboticoModel^ brazo) {
            EstacionBodyFramingModel^ e = buscarPorId(idEstacion);
            if (e != nullptr && brazo != nullptr) {
                e->agregarBrazo(brazo);
                return true;
            }
            return false;
        }
    };
}
