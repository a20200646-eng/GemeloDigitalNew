#pragma once
using namespace System;
using namespace System::Collections::Generic;
using namespace System::IO;
using namespace GemeloDigitalModel;

namespace GemeloDigitalController {

    public ref class LineaEnsamblajeController {
    private:
        List<LineaEnsamblajeModel^>^ repositorio;
        static String^ RUTA_LINEAS = "datos\\lineas_ensamblaje.dat";
        static String^ RUTA_COLA = "datos\\linea_cola_piezas.dat";

    public:
        LineaEnsamblajeController() {
            repositorio = gcnew List<LineaEnsamblajeModel^>();
            PanelLateralController^ ctrlPanel = gcnew PanelLateralController();
            EstructuraTechoController^ ctrlTecho = gcnew EstructuraTechoController();
            cargarArchivo(ctrlPanel, ctrlTecho);
        }

        // CREATE
        bool agregar(String^ id) {
            if (buscarPorId(id) != nullptr) return false;
            repositorio->Add(gcnew LineaEnsamblajeModel(id));
            guardarArchivo();
            return true;
        }

        // READ - por ID
        LineaEnsamblajeModel^ buscarPorId(String^ id) {
            for each (LineaEnsamblajeModel ^ l in repositorio)
                if (l->Id->Equals(id)) return l;
            return nullptr;
        }

        // READ - todos
        List<LineaEnsamblajeModel^>^ obtenerTodos() {
            return repositorio;
        }

        // UPDATE - reemplaza atributos modificables
        bool modificar(String^ id, int indiceActual, bool secuenciaAprobada) {
            LineaEnsamblajeModel^ l = buscarPorId(id);
            if (l == nullptr) return false;
            l->IndiceActual = indiceActual;
            l->SecuenciaAprobada = secuenciaAprobada;
            guardarArchivo();
            return true;
        }

        // DELETE
        bool eliminar(String^ id) {
            LineaEnsamblajeModel^ l = buscarPorId(id);
            if (l == nullptr) return false;
            repositorio->Remove(l);
            guardarArchivo();
            return true;
        }

        // Agregar pieza a la cola de la linea
        bool agregarPieza(String^ idLinea, PiezaModel^ pieza) {
            LineaEnsamblajeModel^ l = buscarPorId(idLinea);
            if (l == nullptr || pieza == nullptr) return false;
            l->agregarPieza(pieza);
            guardarArchivo();
            return true;
        }

        // lineas_ensamblaje.dat → id|indiceActual|secuenciaAprobada
        // linea_cola_piezas.dat → lineaId|tipoPieza|piezaId
        //   tipoPieza: 0=PanelLateral  1=EstructuraTecho
        void guardarArchivo() {
            Directory::CreateDirectory("datos");
            StreamWriter^ swL = gcnew StreamWriter(RUTA_LINEAS, false, Text::Encoding::UTF8);
            StreamWriter^ swC = gcnew StreamWriter(RUTA_COLA, false, Text::Encoding::UTF8);

            for each (LineaEnsamblajeModel ^ l in repositorio) {
                swL->WriteLine(String::Format("{0}|{1}|{2}",
                    l->Id, l->IndiceActual, (l->SecuenciaAprobada ? 1 : 0)));

                for each (PiezaModel ^ p in l->ColaPiezas) {
                    PanelLateralModel^ pl = dynamic_cast<PanelLateralModel^>(p);
                    int tipo = (pl != nullptr) ? 0 : 1;
                    swC->WriteLine(String::Format("{0}|{1}|{2}", l->Id, tipo, p->Id));
                }
            }
            swL->Close();
            swC->Close();
        }

        // Requiere ctrlPanel y ctrlTecho ya cargados
        // Llamar DESPUES de PanelLateralController y EstructuraTechoController
        void cargarArchivo(PanelLateralController^ ctrlPanel,
            EstructuraTechoController^ ctrlTecho) {
            if (!File::Exists(RUTA_LINEAS)) return;
            repositorio->Clear();

            // PASO 1: reconstruir lineas
            StreamReader^ sr = gcnew StreamReader(RUTA_LINEAS, Text::Encoding::UTF8);
            String^ linea;
            while ((linea = sr->ReadLine()) != nullptr) {
                if (linea->Trim()->Length == 0) continue;
                array<String^>^ c = linea->Split('|');
                LineaEnsamblajeModel^ l = gcnew LineaEnsamblajeModel(c[0]);
                l->IndiceActual = Int32::Parse(c[1]);
                l->SecuenciaAprobada = c[2]->Equals("1");
                repositorio->Add(l);
            }
            sr->Close();

            // PASO 2: reconstruir cola de piezas
            if (!File::Exists(RUTA_COLA)) return;
            sr = gcnew StreamReader(RUTA_COLA, Text::Encoding::UTF8);
            while ((linea = sr->ReadLine()) != nullptr) {
                if (linea->Trim()->Length == 0) continue;
                array<String^>^ c = linea->Split('|');
                LineaEnsamblajeModel^ l = buscarPorId(c[0]);
                int tipo = Int32::Parse(c[1]);
                String^ piezaId = c[2];
                if (l == nullptr) continue;
                if (tipo == 0) {
                    PanelLateralModel^ p = ctrlPanel->buscarPorId(piezaId);
                    if (p != nullptr) l->ColaPiezas->Add(p);
                }
                else {
                    EstructuraTechoModel^ e = ctrlTecho->buscarPorId(piezaId);
                    if (e != nullptr) l->ColaPiezas->Add(e);
                }
            }
            sr->Close();
        }
    };
}