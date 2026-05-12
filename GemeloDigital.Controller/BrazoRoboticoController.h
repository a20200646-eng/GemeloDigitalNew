#pragma once
using namespace System;
using namespace System::Collections::Generic;
using namespace System::IO;
using namespace GemeloDigitalModel;

namespace GemeloDigitalController {

    // ============================================================
    // BrazoRoboticoController
    //
    // Persistencia en CINCO archivos separados:
    //   datos\brazos.dat                → campos propios del brazo
    //   datos\brazo_articulaciones.dat  → articulaciones por brazo
    //   datos\brazo_grippers.dat        → gripper por brazo
    //   datos\brazo_sensores_pos.dat    → sensores de posicion por brazo
    //   datos\brazo_sensores_fuerza.dat → sensores de fuerza por brazo
    //
    // Al cargar: primero cargarArchivo() para reconstruir los brazos,
    // luego los componentes se reinyectan llamando a agregarArticulacion(),
    // asignarGripper(), agregarSensorPosicion() y agregarSensorFuerza().
    // ============================================================

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

        // ── Persistencia ─────────────────────────────────────────

        // brazos.dat      → id|rol|estado|gripper
        // articulaciones  → brazoId|id|nombre|activo|anguloActual|anguloMin|anguloMax
        // grippers        → brazoId|id|nombre|activo|apertura|fuerzaAgarre|abierto
        // sensores pos    → brazoId|id|nombre|activo|anguloMedido|tolerancia
        // sensores fuerza → brazoId|id|nombre|activo|fuerzaActual|fuerzaMin|fuerzaMax
        void guardarArchivo() {
            Directory::CreateDirectory("datos");

            // --- brazos.dat ---
            StreamWriter^ swB = gcnew StreamWriter(RUTA_BRAZOS, false, Text::Encoding::UTF8);
            // --- articulaciones ---
            StreamWriter^ swA = gcnew StreamWriter(RUTA_ARTS, false, Text::Encoding::UTF8);
            // --- grippers ---
            StreamWriter^ swG = gcnew StreamWriter(RUTA_GRIPPERS, false, Text::Encoding::UTF8);
            // --- sensores posicion y fuerza ---
            StreamWriter^ swSP = gcnew StreamWriter(RUTA_SENS_POS, false, Text::Encoding::UTF8);
            StreamWriter^ swSF = gcnew StreamWriter(RUTA_SENS_FUE, false, Text::Encoding::UTF8);

            for each (BrazoRoboticoModel ^ b in repositorio) {
                // Brazo
                swB->WriteLine(String::Format("{0}|{1}|{2}|{3}",
                    b->getId(), (int)b->getRol(), (int)b->getEstado(), b->getGripper())); 

                // Articulaciones del brazo
                for each (ArticulacionModel ^ a in b->getArticulaciones())
                    swA->WriteLine(String::Format("{0}|{1}|{2}|{3}|{4}|{5}|{6}",
                        b->getId(), a->getId(), a->getNombre(), (a->getActivo() ? 1 : 0),
                        a->getAnguloActual(), a->getAnguloMinimo(), a->getAnguloMaximo()));

                // Gripper del brazo
                GripperModel^ g = b->getGripper();
                if (g != nullptr)
                    swG->WriteLine(String::Format("{0}|{1}|{2}|{3}|{4}|{5}|{6}",
                        b->getId(), g->getId(), g->getNombre(), (g->getActivo() ? 1 : 0),
                        g->getApertura(), g->getFuerzaAgarre(), (g->getAbierto() ? 1 : 0)));

                // Sensores del brazo: distinguir tipo por dynamic_cast
                for each (SensorModel ^ s in b->getSensores()) {
                    SensorPosicionModel^ sp = dynamic_cast<SensorPosicionModel^>(s);
                    SensorFuerzaModel^ sf = dynamic_cast<SensorFuerzaModel^>(s);
                    if (sp != nullptr)
                        swSP->WriteLine(String::Format("{0}|{1}|{2}|{3}|{4}|{5}",
                            b->getId(), sp->getId(), sp->getNombre(), (sp->getActivo() ? 1 : 0),
                            sp->getAnguloMedido(), sp->getTolerancia()));
                    else if (sf != nullptr)
                        swSF->WriteLine(String::Format("{0}|{1}|{2}|{3}|{4}|{5}|{6}",
                            b->getId(), sf->getId(), sf->getNombre(), (sf->getActivo() ? 1 : 0),
                            sf->getFuerzaActual(), sf->getFuerzaMinima(), sf->getFuerzaMaxima()));
                }
            }

            swB->Close(); swA->Close(); swG->Close(); swSP->Close(); swSF->Close();
        }

        void cargarArchivo() {
            // PASO 1: reconstruir brazos basicos
            if (!File::Exists(RUTA_BRAZOS)) return;
            repositorio->Clear();
            StreamReader^ sr = gcnew StreamReader(RUTA_BRAZOS, Text::Encoding::UTF8);
            String^ linea;
            while ((linea = sr->ReadLine()) != nullptr) {
                if (linea->Trim()->Length == 0) continue;
                array<String^>^ c = linea->Split('|');
                BrazoRoboticoModel^ b = gcnew BrazoRoboticoModel(
                    Int32::Parse(c[0]), (RolBrazo)Int32::Parse(c[1]));
                b->setEstado((EstadoBrazo)Int32::Parse(c[2]));
                // No reconstruimos aquí el Gripper a partir de una cadena.
                // Los grippers se reinyectan en el PASO 3 leyendo el archivo correspondiente.
                b->setGripper(nullptr);
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
                        Int32::Parse(c[1]), c[2],Boolean::Parse(c[3]),
                        Double::Parse(c[4]), Double::Parse(c[5]), Double::Parse(c[6]));
                    BrazoRoboticoModel^ b = buscarPorId(Int32::Parse(c[0]));
                    if (b != nullptr) b->getArticulaciones()->Add(a);
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
                        Int32::Parse(c[1]), c[2],Boolean::Parse(c[3]),
                        Double::Parse(c[4]), Double::Parse(c[5]), c[6]->Equals("1"));
                    BrazoRoboticoModel^ b = buscarPorId(Int32::Parse(c[0]));
                    if (b != nullptr) b->setGripper(g);
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
                        Int32::Parse(c[1]), c[2],Boolean::Parse(c[3]), Double::Parse(c[4]), Double::Parse(c[5]));

                    BrazoRoboticoModel^ b = buscarPorId(Int32::Parse(c[0]));
                    if (b != nullptr) b->getSensores()->Add(s);
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
						Int32::Parse(c[1]), c[2], Boolean::Parse(c[3]),
                        Double::Parse(c[4]), Double::Parse(c[5]), Double::Parse(c[6]));
                    BrazoRoboticoModel^ b = buscarPorId(Int32::Parse(c[0]));
                    if (b != nullptr) b->getSensores()->Add(s);
                }
                sr->Close();
            }
        }
    };
}