#pragma once
using namespace System;
using namespace System::Collections::Generic;
using namespace System::IO;
using namespace GemeloDigitalModel;

namespace GemeloDigitalController {

    // ============================================================
    // TareaSoldarController
    // Formato: id|estado|puntosObjetivo|puntosCompletados|temperatura
    // ============================================================

    public ref class TareaSoldarController {
    private:
        List<TareaSoldarModel^>^ repositorio;
        static String^ RUTA = "datos\\tareas_soldar.dat";

    public:
        TareaSoldarController() {
            repositorio = gcnew List<TareaSoldarModel^>();
            

        }
       

        // CREATE
        bool agregar(int id, int puntosObjetivo, double temperatura) {
            TareaSoldarModel^ t = buscarPorId(id);
            if (t == nullptr) {
                repositorio->Add(gcnew TareaSoldarModel(id, puntosObjetivo, temperatura));
                return true;
            }
            return false;
        }

        // READ - por ID
        TareaSoldarModel^ buscarPorId(int id) {
            for each (TareaSoldarModel ^ t in repositorio) {
                if (t->getId() == id) return t;
            }
            return nullptr;
        }

        // READ - todos
        List<TareaSoldarModel^>^ obtenerTodos() {
            return repositorio;
        }

        // UPDATE - E: estado | PO: puntosObjetivo | PC: puntosCompletados | T: temperatura
        bool modificar(int id, String^ opcion, String^ valor) {
            TareaSoldarModel^ t = buscarPorId(id);
            if (t != nullptr) {
                if (opcion->Equals("E"))       t->setEstado(valor);
                else if (opcion->Equals("PO")) t->setPuntosObjetivo(Convert::ToInt32(valor));
                else if (opcion->Equals("PC")) t->setPuntosCompletados(Convert::ToInt32(valor));
                else if (opcion->Equals("T"))  t->setTemperatura(Convert::ToDouble(valor));
                else return false;
                return true;
            }
            return false;
        }

        // DELETE
        bool eliminar(int id) {
            TareaSoldarModel^ t = buscarPorId(id);
            if (t != nullptr) {
                repositorio->Remove(t);
                return true;
            }
            return false;
        }

		//persistencia

        void guardarArchivo() {
            Directory::CreateDirectory("datos");
            StreamWriter^ sw = gcnew StreamWriter(RUTA, false, Text::Encoding::UTF8);
            for each(TareaSoldarModel ^ t in repositorio)
                sw->WriteLine(String::Format("{0}|{1}|{2}|{3}|{4}",
                    t->getId(), t->getEstado(), t->getPuntosObjetivo(),
                    t->getPuntosCompletados(), t->getTemperatura()));
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
                TareaSoldarModel^ t = gcnew TareaSoldarModel(
                    Int32::Parse(c[0]), Int32::Parse(c[2]), Double::Parse(c[4]));
                t->setEstado(c[1]);
                t->setPuntosCompletados(Int32::Parse(c[3]));
                repositorio->Add(t);
            }
            sr->Close();
        }


    };
}