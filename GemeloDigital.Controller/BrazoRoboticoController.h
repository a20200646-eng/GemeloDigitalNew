#pragma once
using namespace System;
using namespace System::Collections::Generic;
using namespace System::IO;
using namespace GemeloDigitalModel;

namespace GemeloDigitalController {

    public ref class BrazoRoboticoController {
    private:
        List<BrazoRoboticoModel^>^ repositorio;

        static String^ RUTA_BRAZOS = "datos\\brazos.dat";
        static String^ RUTA_ARTS = "datos\\brazo_articulaciones.dat";
        static String^ RUTA_GRIPPERS = "datos\\brazo_grippers.dat";
        static String^ RUTA_SENS_POS = "datos\\brazo_sensores_pos.dat";
        static String^ RUTA_SENS_FUE = "datos\\brazo_sensores_fuerza.dat";

    public:
        BrazoRoboticoController() {
            repositorio = gcnew List<BrazoRoboticoModel^>();
            cargarArchivo();
        }

        // CREATE
        bool agregar(String^ id, RolBrazo rol) {
            if (buscarPorId(id) != nullptr) return false;
            repositorio->Add(gcnew BrazoRoboticoModel(id, rol));
            guardarArchivo();
            return true;
        }

        // READ - por ID
        BrazoRoboticoModel^ buscarPorId(String^ id) {
            for each (BrazoRoboticoModel ^ b in repositorio)
                if (b->Id->Equals(id)) return b;
            return nullptr;
        }

        // READ - todos
        List<BrazoRoboticoModel^>^ obtenerTodos() {
            return repositorio;
        }

        // UPDATE - solo Estado es modificable en un brazo
        // Rol es estructural y no cambia una vez creado el brazo
        bool modificar(String^ id, EstadoBrazo nuevoEstado) {
            BrazoRoboticoModel^ b = buscarPorId(id);
            if (b == nullptr) return false;
            b->Estado = nuevoEstado;
            guardarArchivo();
            return true;
        }

        // DELETE
        bool eliminar(String^ id) {
            BrazoRoboticoModel^ b = buscarPorId(id);
            if (b == nullptr) return false;
            repositorio->Remove(b);
            guardarArchivo();
            return true;
        }

        // Gestion de componentes internos
        bool agregarArticulacion(String^ idBrazo, String^ idArt, String^ nombre,
            double anguloActual, double anguloMin, double anguloMax) {
            BrazoRoboticoModel^ b = buscarPorId(idBrazo);
            if (b == nullptr) return false;
            b->agregarArticulacion(gcnew ArticulacionModel(
                idArt, nombre, true, anguloActual, anguloMin, anguloMax));
            guardarArchivo();
            return true;
        }

        bool asignarGripper(String^ idBrazo, String^ idGripper, String^ nombre,
            double apertura, double fuerzaAgarre, bool abierto) {
            BrazoRoboticoModel^ b = buscarPorId(idBrazo);
            if (b == nullptr) return false;
            b->Gripper = gcnew GripperModel(
                idGripper, nombre, true, apertura, fuerzaAgarre, abierto);
            guardarArchivo();
            return true;
        }

        bool agregarSensorPosicion(String^ idBrazo, String^ idSensor, String^ nombre,
            double anguloMedido, double tolerancia) {
            BrazoRoboticoModel^ b = buscarPorId(idBrazo);
            if (b == nullptr) return false;
            b->agregarSensor(gcnew SensorPosicionModel(
                idSensor, nombre, true, anguloMedido, tolerancia));
            guardarArchivo();
            return true;
        }

        bool agregarSensorFuerza(String^ idBrazo, String^ idSensor, String^ nombre,
            double fuerzaActual, double fuerzaMin, double fuerzaMax) {
            BrazoRoboticoModel^ b = buscarPorId(idBrazo);
            if (b == nullptr) return false;
            b->agregarSensor(gcnew SensorFuerzaModel(
                idSensor, nombre, true, fuerzaActual, fuerzaMin, fuerzaMax));
            guardarArchivo();
            return true;
        }

        // ── Persistencia ─────────────────────────────────────────
        // brazos.dat      → id|rol|estado
        // articulaciones  → brazoId|id|nombre|activo|anguloActual|anguloMin|anguloMax
        // grippers        → brazoId|id|nombre|activo|apertura|fuerzaAgarre|abierto
        // sensores pos    → brazoId|id|nombre|activo|anguloMedido|tolerancia
        // sensores fuerza → brazoId|id|nombre|activo|fuerzaActual|fuerzaMin|fuerzaMax
        void guardarArchivo() {
            Directory::CreateDirectory("datos");
            StreamWriter^ swB = gcnew StreamWriter(RUTA_BRAZOS, false, Text::Encoding::UTF8);
            StreamWriter^ swA = gcnew StreamWriter(RUTA_ARTS, false, Text::Encoding::UTF8);
            StreamWriter^ swG = gcnew StreamWriter(RUTA_GRIPPERS, false, Text::Encoding::UTF8);
            StreamWriter^ swSP = gcnew StreamWriter(RUTA_SENS_POS, false, Text::Encoding::UTF8);
            StreamWriter^ swSF = gcnew StreamWriter(RUTA_SENS_FUE, false, Text::Encoding::UTF8);

            for each (BrazoRoboticoModel ^ b in repositorio) {
                // Brazo — Gripper se guarda en su propio archivo
                swB->WriteLine(String::Format("{0}|{1}|{2}",
                    b->Id, (int)b->Rol, (int)b->Estado));

                // Articulaciones
                for each (ArticulacionModel ^ a in b->Articulaciones)
                    swA->WriteLine(String::Format("{0}|{1}|{2}|{3}|{4}|{5}|{6}",
                        b->Id, a->Id, a->Nombre, (a->Activo ? 1 : 0),
                        a->AnguloActual, a->AnguloMinimo, a->AnguloMaximo));

                // Gripper
                GripperModel^ g = b->Gripper;
                if (g != nullptr)
                    swG->WriteLine(String::Format("{0}|{1}|{2}|{3}|{4}|{5}|{6}",
                        b->Id, g->Id, g->Nombre, (g->Activo ? 1 : 0),
                        g->Apertura, g->FuerzaAgarre, (g->Abierto ? 1 : 0)));

                // Sensores — distinguir tipo con dynamic_cast
                for each (SensorModel ^ s in b->Sensores) {
                    SensorPosicionModel^ sp = dynamic_cast<SensorPosicionModel^>(s);
                    SensorFuerzaModel^ sf = dynamic_cast<SensorFuerzaModel^>(s);
                    if (sp != nullptr)
                        swSP->WriteLine(String::Format("{0}|{1}|{2}|{3}|{4}|{5}",
                            b->Id, sp->Id, sp->Nombre, (sp->Activo ? 1 : 0),
                            sp->AnguloMedido, sp->Tolerancia));
                    else if (sf != nullptr)
                        swSF->WriteLine(String::Format("{0}|{1}|{2}|{3}|{4}|{5}|{6}",
                            b->Id, sf->Id, sf->Nombre, (sf->Activo ? 1 : 0),
                            sf->FuerzaActual, sf->FuerzaMinima, sf->FuerzaMaxima));
                }
            }
            swB->Close(); swA->Close(); swG->Close(); swSP->Close(); swSF->Close();
        }

        void cargarArchivo() {
            if (!File::Exists(RUTA_BRAZOS)) return;
            repositorio->Clear();

            // PASO 1: reconstruir brazos
            StreamReader^ sr = gcnew StreamReader(RUTA_BRAZOS, Text::Encoding::UTF8);
            String^ linea;
            while ((linea = sr->ReadLine()) != nullptr) {
                if (linea->Trim()->Length == 0) continue;
                array<String^>^ c = linea->Split('|');
                BrazoRoboticoModel^ b = gcnew BrazoRoboticoModel(
                    c[0], (RolBrazo)Int32::Parse(c[1]));
                b->Estado = (EstadoBrazo)Int32::Parse(c[2]);
                b->Gripper = nullptr;
                repositorio->Add(b);
            }
            sr->Close();

            // PASO 2: reinyectar articulaciones
            if (File::Exists(RUTA_ARTS)) {
                sr = gcnew StreamReader(RUTA_ARTS, Text::Encoding::UTF8);
                while ((linea = sr->ReadLine()) != nullptr) {
                    if (linea->Trim()->Length == 0) continue;
                    array<String^>^ c = linea->Split('|');
                    ArticulacionModel^ a = gcnew ArticulacionModel(
                        c[1], c[2], c[3]->Equals("1"),
                        Double::Parse(c[4]), Double::Parse(c[5]), Double::Parse(c[6]));
                    BrazoRoboticoModel^ b = buscarPorId(c[0]);
                    if (b != nullptr) b->Articulaciones->Add(a);
                }
                sr->Close();
            }

            // PASO 3: reinyectar grippers
            if (File::Exists(RUTA_GRIPPERS)) {
                sr = gcnew StreamReader(RUTA_GRIPPERS, Text::Encoding::UTF8);
                while ((linea = sr->ReadLine()) != nullptr) {
                    if (linea->Trim()->Length == 0) continue;
                    array<String^>^ c = linea->Split('|');
                    GripperModel^ g = gcnew GripperModel(
                        c[1], c[2], c[3]->Equals("1"),
                        Double::Parse(c[4]), Double::Parse(c[5]), c[6]->Equals("1"));
                    BrazoRoboticoModel^ b = buscarPorId(c[0]);
                    if (b != nullptr) b->Gripper = g;
                }
                sr->Close();
            }

            // PASO 4: reinyectar sensores de posicion
            if (File::Exists(RUTA_SENS_POS)) {
                sr = gcnew StreamReader(RUTA_SENS_POS, Text::Encoding::UTF8);
                while ((linea = sr->ReadLine()) != nullptr) {
                    if (linea->Trim()->Length == 0) continue;
                    array<String^>^ c = linea->Split('|');
                    SensorPosicionModel^ s = gcnew SensorPosicionModel(
                        c[1], c[2], c[3]->Equals("1"),
                        Double::Parse(c[4]), Double::Parse(c[5]));
                    BrazoRoboticoModel^ b = buscarPorId(c[0]);
                    if (b != nullptr) b->Sensores->Add(s);
                }
                sr->Close();
            }

            // PASO 5: reinyectar sensores de fuerza
            if (File::Exists(RUTA_SENS_FUE)) {
                sr = gcnew StreamReader(RUTA_SENS_FUE, Text::Encoding::UTF8);
                while ((linea = sr->ReadLine()) != nullptr) {
                    if (linea->Trim()->Length == 0) continue;
                    array<String^>^ c = linea->Split('|');
                    SensorFuerzaModel^ s = gcnew SensorFuerzaModel(
                        c[1], c[2], c[3]->Equals("1"),
                        Double::Parse(c[4]), Double::Parse(c[5]), Double::Parse(c[6]));
                    BrazoRoboticoModel^ b = buscarPorId(c[0]);
                    if (b != nullptr) b->Sensores->Add(s);
                }
                sr->Close();
            }
        }
    };
}