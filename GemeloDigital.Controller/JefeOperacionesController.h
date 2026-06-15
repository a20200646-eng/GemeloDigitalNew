#pragma once
using namespace System;
using namespace System::Collections::Generic;
using namespace System::IO;
using namespace GemeloDigitalModel;

namespace GemeloDigitalController {

    public ref class JefeOperacionesController {
    private:
        List<JefeOperacionesModel^>^ repositorio;
        static String^ RUTA = "datos\\jefes.dat";

    public:
        JefeOperacionesController() {
            repositorio = gcnew List<JefeOperacionesModel^>();
            cargarArchivo();
        }

        // CREATE
        bool agregar(String^ id, String^ nombre, String^ contrasena, int nivelAutorizacion) {
            if (buscarPorId(id) != nullptr) return false;
            repositorio->Add(gcnew JefeOperacionesModel(id, nombre, contrasena, nivelAutorizacion));
            guardarArchivo();
            return true;
        }

        // READ - por ID
        JefeOperacionesModel^ buscarPorId(String^ id) {
            for each (JefeOperacionesModel ^ j in repositorio)
                if (j->Id->Equals(id)) return j;
            return nullptr;
        }

        // READ - todos
        List<JefeOperacionesModel^>^ obtenerTodos() {
            return repositorio;
        }

        // UPDATE - reemplaza todos los atributos modificables
        bool modificar(String^ id, String^ nombre, String^ contrasena, int nivelAutorizacion) {
            JefeOperacionesModel^ j = buscarPorId(id);
            if (j == nullptr) return false;
            j->Nombre = nombre;
            j->Contrasena = contrasena;
            j->NivelAutorizacion = nivelAutorizacion;
            guardarArchivo();
            return true;
        }

        // DELETE
        bool eliminar(String^ id) {
            JefeOperacionesModel^ j = buscarPorId(id);
            if (j == nullptr) return false;
            repositorio->Remove(j);
            guardarArchivo();
            return true;
        }
		//=============================================================================================
		//BUSCAR POR CREDENCIALES
        JefeOperacionesModel^ buscarPorCredenciales(String^ nombre, String^ contrasena) {
            for each(JefeOperacionesModel ^ j in repositorio) {
				if (j->Nombre == nombre && j->Contrasena == contrasena) {
					return j;
				}

            }
            return nullptr;
        }
        //=============================================================================================




        // Formato: id|nombre|contrasena|nivelAutorizacion
        void guardarArchivo() {
            Directory::CreateDirectory("datos");
            StreamWriter^ sw = gcnew StreamWriter(RUTA, false, Text::Encoding::UTF8);
            for each (JefeOperacionesModel ^ j in repositorio)
                sw->WriteLine(String::Format("{0}|{1}|{2}|{3}",
                    j->Id, j->Nombre, j->Contrasena, j->NivelAutorizacion));
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
                repositorio->Add(gcnew JefeOperacionesModel(
                    c[0], c[1], c[2], Int32::Parse(c[3])));
            }
            sr->Close();
        }
    };
}