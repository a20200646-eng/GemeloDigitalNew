#pragma once
using namespace System;
using namespace System::Collections::Generic;
using namespace System::IO;
using namespace GemeloDigitalModel;

namespace GemeloDigitalController {

    // ============================================================
   // LineaEnsamblajeController
   //
   // Persistencia en DOS archivos:
   //   datos\lineas_ensamblaje.dat  → id|indiceActual|secuenciaAprobada
   //   datos\linea_cola_piezas.dat  → lineaId|tipoPieza|piezaId
   //     tipoPieza: 0 = PanelLateral, 1 = EstructuraTecho
   //
   // cargarArchivo(PanelLateralController^, EstructuraTechoController^)
   // Llamar DESPUES de que ambos controllers de piezas esten cargados.
   // ============================================================

    public ref class LineaEnsamblajeController {
    private:
        List<LineaEnsamblajeModel^>^ repositorio;
        static String^ RUTA_LINEAS = "datos\\lineas_ensamblaje.dat";
        static String^ RUTA_COLA = "datos\\linea_cola_piezas.dat";

    public:
        LineaEnsamblajeController() {
            repositorio = gcnew List<LineaEnsamblajeModel^>();
        }

        // CREATE
        bool agregar(int id) {
            LineaEnsamblajeModel^ l = buscarPorId(id);
            if (l == nullptr) {
                repositorio->Add(gcnew LineaEnsamblajeModel(id));
                return true;
            }
            return false;
        }

        // READ - por ID
        LineaEnsamblajeModel^ buscarPorId(int id) {
            for each (LineaEnsamblajeModel ^ l in repositorio) {
                if (l->getId() == id) return l;
            }
            return nullptr;
        }

        // READ - todos
        List<LineaEnsamblajeModel^>^ obtenerTodos() {
            return repositorio;
        }

        // UPDATE - I: indiceActual | S: secuenciaAprobada
        bool modificar(int id, String^ opcion, String^ valor) {
            LineaEnsamblajeModel^ l = buscarPorId(id);
            if (l != nullptr) {
                if (opcion->Equals("I"))      l->setIndiceActual(Convert::ToInt32(valor));
                else if (opcion->Equals("S")) l->setSecuenciaAprobada(valor->Equals("true"));
                else return false;
                return true;
            }
            return false;
        }

        // DELETE
        bool eliminar(int id) {
            LineaEnsamblajeModel^ l = buscarPorId(id);
            if (l != nullptr) {
                repositorio->Remove(l);
                return true;
            }
            return false;
        }

        // Agregar pieza a la linea
        bool agregarPieza(int idLinea, PiezaModel^ pieza) {
            LineaEnsamblajeModel^ l = buscarPorId(idLinea);
            if (l != nullptr && pieza != nullptr) {
                l->agregarPieza(pieza);
                return true;
            }
            return false;
        }

		// ── Persistencia ─────────────────────────────────────────
        // lineas_ensamblaje.dat → id|indiceActual|secuenciaAprobada
        // linea_cola_piezas.dat → lineaId|tipoPieza|piezaId
        //   tipoPieza: 0=PanelLateral 1=EstructuraTecho
        void guardarArchivo() {
            Directory::CreateDirectory("datos");
            StreamWriter^ swL = gcnew StreamWriter(RUTA_LINEAS, false, Text::Encoding::UTF8);
            StreamWriter^ swC = gcnew StreamWriter(RUTA_COLA, false, Text::Encoding::UTF8);

            for each(LineaEnsamblajeModel ^ l in repositorio) {
                swL->WriteLine(String::Format("{0}|{1}|{2}",
                    l->getId(), l->getIndiceActual(), (l->getSecuenciaAprobada() ? 1 : 0)));

                for each(PiezaModel ^ p in l->getColaPiezas()) {
                    PanelLateralModel^ pl = dynamic_cast<PanelLateralModel^>(p);
                    EstructuraTechoModel^ et = dynamic_cast<EstructuraTechoModel^>(p);
                    int tipo = (pl != nullptr) ? 0 : 1;
                    swC->WriteLine(String::Format("{0}|{1}|{2}", l->getId(), tipo, p->getId()));
                }
            }
            swL->Close(); swC->Close();
        }

        void cargarArchivo(PanelLateralController^ ctrlPanel, EstructuraTechoController^ ctrlTecho) {
            if (!File::Exists(RUTA_LINEAS)) return;
            repositorio->Clear();

            // PASO 1: reconstruir lineas
            StreamReader^ sr = gcnew StreamReader(RUTA_LINEAS, Text::Encoding::UTF8);
            String^ linea;
            while ((linea = sr->ReadLine()) != nullptr) {
                if (linea->Trim()->Length == 0) continue;
                array<String^>^ c = linea->Split('|');
                LineaEnsamblajeModel^ l = gcnew LineaEnsamblajeModel(Int32::Parse(c[0]));
                l->setIndiceActual(Int32::Parse(c[1]));
                l->setSecuenciaAprobada(c[2]->Equals("1"));
                repositorio->Add(l);
            }
            sr->Close();

            // PASO 2: reconstruir cola de piezas
            if (!File::Exists(RUTA_COLA)) return;
            sr = gcnew StreamReader(RUTA_COLA, Text::Encoding::UTF8);
            while ((linea = sr->ReadLine()) != nullptr) {
                if (linea->Trim()->Length == 0) continue;
                array<String^>^ c = linea->Split('|');
                LineaEnsamblajeModel^ l = buscarPorId(Int32::Parse(c[0]));
                int tipo = Int32::Parse(c[1]);
                int piezaId = Int32::Parse(c[2]);
                if (l == nullptr) continue;
                if (tipo == 0) {
                    PanelLateralModel^ p = ctrlPanel->buscarPorId(piezaId);
                    if (p != nullptr) l->getColaPiezas()->Add(p);
                }
                else {
                    EstructuraTechoModel^ e = ctrlTecho->buscarPorId(piezaId);
                    if (e != nullptr) l->getColaPiezas()->Add(e);
                }
            }
            sr->Close();
        }



    };
}