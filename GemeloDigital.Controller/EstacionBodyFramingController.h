#pragma once
using namespace System;
using namespace System::Collections::Generic;
using namespace System::IO;
using namespace GemeloDigitalModel;

namespace GemeloDigitalController {
    // ============================================================
    // EstacionBodyFramingController
    //
    // Persistencia en DOS archivos:
    //   datos\estacion.dat        → id|estadoSistema
    //   datos\estacion_brazos.dat → estacionId|brazoId
    //
    // cargarArchivo(BrazoRoboticoController^) recibe el controller
    // de brazos ya cargado para poder reconstruir las referencias.
    // Llamar SIEMPRE DESPUES de BrazoRoboticoController.cargarArchivo().
    // ============================================================

    public ref class EstacionBodyFramingController {
    private:
        List<EstacionBodyFramingModel^>^ repositorio;

        static String^ RUTA_ESTACION = "datos\\estacion.dat";
        static String^ RUTA_BRAZOS = "datos\\estacion_brazos.dat";

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

		// ── Persistencia ─────────────────────────────────────────

        // estacion.dat        → id|estadoSistema
        // estacion_brazos.dat → estacionId|brazoId
        void guardarArchivo() {
            Directory::CreateDirectory("datos");

            StreamWriter^ swE = gcnew StreamWriter(RUTA_ESTACION, false, Text::Encoding::UTF8);
            StreamWriter^ swB = gcnew StreamWriter(RUTA_BRAZOS, false, Text::Encoding::UTF8);

            for each(EstacionBodyFramingModel ^ e in repositorio) {
                swE->WriteLine(String::Format("{0}|{1}",
                    e->getId(), (int)e->getEstadoSistema()));
                for each(BrazoRoboticoModel ^ b in e->getBrazos())
                    swB->WriteLine(String::Format("{0}|{1}", e->getId(), b->getId()));
            }

            swE->Close();
            swB->Close();
        }

        // Requiere ctrlBrazo ya cargado para reconstruir referencias
        void cargarArchivo(BrazoRoboticoController^ ctrlBrazo) {
            if (!File::Exists(RUTA_ESTACION)) return;
            repositorio->Clear();

            // PASO 1: reconstruir estaciones
            StreamReader^ sr = gcnew StreamReader(RUTA_ESTACION, Text::Encoding::UTF8);
            String^ linea;
            while ((linea = sr->ReadLine()) != nullptr) {
                if (linea->Trim()->Length == 0) continue;
                array<String^>^ c = linea->Split('|');
                EstacionBodyFramingModel^ e = gcnew EstacionBodyFramingModel(Int32::Parse(c[0]));
                e->setEstadoSistema((EstadoSistema)Int32::Parse(c[1]));
                repositorio->Add(e);
            }
            sr->Close();

            // PASO 2: reconstruir asociacion estacion<->brazo
            if (!File::Exists(RUTA_BRAZOS)) return;
            sr = gcnew StreamReader(RUTA_BRAZOS, Text::Encoding::UTF8);
            while ((linea = sr->ReadLine()) != nullptr) {
                if (linea->Trim()->Length == 0) continue;
                array<String^>^ c = linea->Split('|');
                EstacionBodyFramingModel^ e = buscarPorId(Int32::Parse(c[0]));
                BrazoRoboticoModel^ b = ctrlBrazo->buscarPorId(Int32::Parse(c[1]));
                if (e != nullptr && b != nullptr) e->getBrazos()->Add(b);
            }
            sr->Close();
        }
    };
}
