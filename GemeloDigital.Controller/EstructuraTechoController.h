#pragma once
using namespace System;
using namespace System::Collections::Generic;
using namespace System::IO;
using namespace GemeloDigitalModel;

namespace GemeloDigitalController {

    public ref class EstructuraTechoController {
    private:
        List<EstructuraTechoModel^>^ repositorio;
        static String^ RUTA = "datos\\estructuras_techo.dat";


    public:
        EstructuraTechoController() {
            repositorio = gcnew List<EstructuraTechoModel^>();
        }

        // CREATE
        bool agregar(int id, String^ material, double peso,
            int puntosUnion, double anchura) {
            EstructuraTechoModel^ e = buscarPorId(id);
            if (e == nullptr) {
                repositorio->Add(gcnew EstructuraTechoModel(
                    id, material, peso, puntosUnion, anchura));
                return true;
            }
            return false;
        }

        // READ - por ID
        EstructuraTechoModel^ buscarPorId(int id) {
            for each (EstructuraTechoModel ^ e in repositorio) {
                if (e->getId() == id) return e;
            }
            return nullptr;
        }

        // READ - todos
        List<EstructuraTechoModel^>^ obtenerTodos() {
            return repositorio;
        }

        // UPDATE - M: material | P: peso | E: estado | PU: puntosUnion | A: anchura
        bool modificar(int id, String^ opcion, String^ valor) {
            EstructuraTechoModel^ e = buscarPorId(id);
            if (e != nullptr) {
                if (opcion->Equals("M"))       e->setMaterial(valor);
                else if (opcion->Equals("P"))  e->setPeso(Convert::ToDouble(valor));
                else if (opcion->Equals("PU")) e->setPuntosUnion(Convert::ToInt32(valor));
                else if (opcion->Equals("A"))  e->setAnchura(Convert::ToDouble(valor));
                else if (opcion->Equals("E")) {
                    if (valor->Equals("DISPONIBLE"))       e->setEstado(EstadoPieza::DISPONIBLE);
                    else if (valor->Equals("EN_PROCESO"))  e->setEstado(EstadoPieza::EN_PROCESO);
                    else if (valor->Equals("ENSAMBLADA"))  e->setEstado(EstadoPieza::ENSAMBLADA);
                    else if (valor->Equals("DEFECTUOSA"))  e->setEstado(EstadoPieza::DEFECTUOSA);
                    else return false;
                }
                else return false;
                return true;
            }
            return false;
        }

        // DELETE
        bool eliminar(int id) {
            EstructuraTechoModel^ e = buscarPorId(id);
            if (e != nullptr) {
                repositorio->Remove(e);
                return true;
            }
            return false;
        }

		// ── Persistencia ─────────────────────────────────────────
        void guardarArchivo() {
            Directory::CreateDirectory("datos");
            StreamWriter^ sw = gcnew StreamWriter(RUTA, false, Text::Encoding::UTF8);
            for each(EstructuraTechoModel ^ e in repositorio)
                sw->WriteLine(String::Format("{0}|{1}|{2}|{3}|{4}|{5}",
                    e->getId(), e->getMaterial(), e->getPeso(),
                    (int)e->getEstado(), e->getPuntosUnion(), e->getAnchura()));
            sw->Close();
        }

        void cargarArchivo() {
            if (!File::Exists(RUTA)) return;
            repositorio->Clear();
            StreamReader^ sr = gcnew StreamReader(RUTA, Text::Encoding::UTF8);
            String^ linea;
            while ((linea = sr->ReadLine()) != nullptr) {
                if (linea->Trim()->Length == 0) continue;
                array<String^>^ c = linea->Split('|');
                EstructuraTechoModel^ e = gcnew EstructuraTechoModel(
                    Int32::Parse(c[0]), c[1], Double::Parse(c[2]),
                    Int32::Parse(c[4]), Double::Parse(c[5]));
                e->setEstado((EstadoPieza)Int32::Parse(c[3]));
                repositorio->Add(e);
            }
            sr->Close();
        }
    };
}