#pragma once
using namespace System;
using namespace System::Collections::Generic;
using namespace System::IO;
using namespace GemeloDigitalModel;

namespace GemeloDigitalController {

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
        bool agregar(String^ id) {
            if (buscarPorId(id) != nullptr) return false;
            repositorio->Add(gcnew EstacionBodyFramingModel(id));
            guardarArchivo();
            return true;
        }

        // READ - por ID
        EstacionBodyFramingModel^ buscarPorId(String^ id) {
            for each (EstacionBodyFramingModel ^ e in repositorio)
                if (e->Id->Equals(id)) return e;
            return nullptr;
        }

        // READ - todos
        List<EstacionBodyFramingModel^>^ obtenerTodos() {
            return repositorio;
        }

        // UPDATE - solo EstadoSistema es modificable
        bool modificar(String^ id, EstadoSistema nuevoEstado) {
            EstacionBodyFramingModel^ e = buscarPorId(id);
            if (e == nullptr) return false;
            e->EstadoSistemaActual = nuevoEstado;
            guardarArchivo();
            return true;
        }

        // DELETE
        bool eliminar(String^ id) {
            EstacionBodyFramingModel^ e = buscarPorId(id);
            if (e == nullptr) return false;
            repositorio->Remove(e);
            guardarArchivo();
            return true;
        }

        // Agregar brazo a la estacion
        bool agregarBrazo(String^ idEstacion, BrazoRoboticoModel^ brazo) {
            EstacionBodyFramingModel^ e = buscarPorId(idEstacion);
            if (e == nullptr || brazo == nullptr) return false;
            e->agregarBrazo(brazo);
            guardarArchivo();
            return true;
        }

        // estacion.dat        → id|estadoSistema
        // estacion_brazos.dat → estacionId|brazoId
        void guardarArchivo() {
            Directory::CreateDirectory("datos");
            StreamWriter^ swE = gcnew StreamWriter(RUTA_ESTACION, false, Text::Encoding::UTF8);
            StreamWriter^ swB = gcnew StreamWriter(RUTA_BRAZOS, false, Text::Encoding::UTF8);

            for each (EstacionBodyFramingModel ^ e in repositorio) {
                swE->WriteLine(String::Format("{0}|{1}",
                    e->Id, (int)e->EstadoSistemaActual));
                for each (BrazoRoboticoModel ^ b in e->Brazos)
                    swB->WriteLine(String::Format("{0}|{1}", e->Id, b->Id));
            }
            swE->Close();
            swB->Close();
        }

        // Requiere ctrlBrazo ya cargado — llamar DESPUES de BrazoRoboticoController
        void cargarArchivo(BrazoRoboticoController^ ctrlBrazo) {
            if (!File::Exists(RUTA_ESTACION)) return;
            repositorio->Clear();

            // PASO 1: reconstruir estaciones
            StreamReader^ sr = gcnew StreamReader(RUTA_ESTACION, Text::Encoding::UTF8);
            String^ linea;
            while ((linea = sr->ReadLine()) != nullptr) {
                if (linea->Trim()->Length == 0) continue;
                array<String^>^ c = linea->Split('|');
                EstacionBodyFramingModel^ e = gcnew EstacionBodyFramingModel(c[0]);
                e->EstadoSistemaActual = (EstadoSistema)Int32::Parse(c[1]);
                repositorio->Add(e);
            }
            sr->Close();

            // PASO 2: reconstruir asociacion estacion <-> brazo
            if (!File::Exists(RUTA_BRAZOS)) return;
            sr = gcnew StreamReader(RUTA_BRAZOS, Text::Encoding::UTF8);
            while ((linea = sr->ReadLine()) != nullptr) {
                if (linea->Trim()->Length == 0) continue;
                array<String^>^ c = linea->Split('|');
                EstacionBodyFramingModel^ e = buscarPorId(c[0]);
                BrazoRoboticoModel^ b = ctrlBrazo->buscarPorId(c[1]);
                if (e != nullptr && b != nullptr) e->Brazos->Add(b);
            }
            sr->Close();
        }
    };
}