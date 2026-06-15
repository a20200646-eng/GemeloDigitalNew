#pragma once
using namespace System;
using namespace System::Collections::Generic;
using namespace System::Data;
using namespace System::Data::SqlClient;
using namespace GemeloDigitalModel;

namespace GemeloDigitalController {

    public ref class BrazoRoboticoController {
    private:
        // Usamos la misma cadena de conexión de LineaEnsamblajeController
        String^ connectionString = "Server=bdmijael23.cczveeoo8rq2.us-east-1.rds.amazonaws.com,1433;" +
            "Database=bdmijael23;" +
            "User Id=admin;" +
            "Password=abcd1234;";

    public:
        BrazoRoboticoController() {}

        // Método vacío para mantener compatibilidad con las invocaciones de la UI original
        void cargarArchivo() {}

        // ==========================================================
        // CREATE: AGREGAR BRAZO ROBÓTICO
        // ==========================================================
        bool agregar(String^ id, RolBrazo rol) {
            if (buscarPorId(id) != nullptr) return false;

            SqlConnection^ conn = gcnew SqlConnection(connectionString);
            SqlCommand^ cmd = gcnew SqlCommand("sp_BrazosRoboticos_Insertar", conn);
            cmd->CommandType = CommandType::StoredProcedure;

            cmd->Parameters->AddWithValue("@Id", id);
            cmd->Parameters->AddWithValue("@Rol", (int)rol);
            cmd->Parameters->AddWithValue("@Estado", (int)EstadoBrazo::REPOSO);

            try {
                conn->Open();
                cmd->ExecuteNonQuery();
                return true;
            }
            catch (Exception^ ex) {
                throw gcnew Exception("Error al agregar brazo robótico: " + ex->Message);
            }
            finally {
                if (conn->State == ConnectionState::Open) conn->Close();
            }
        }

        // ==========================================================
        // READ: BUSCAR BRAZO POR ID (Carga el brazo y sus componentes)
        // ==========================================================
        BrazoRoboticoModel^ buscarPorId(String^ id) {
            BrazoRoboticoModel^ brazoObj = nullptr;
            SqlConnection^ conn = gcnew SqlConnection(connectionString);
            SqlCommand^ cmd = gcnew SqlCommand("sp_BrazosRoboticos_BuscarPorId", conn);
            cmd->CommandType = CommandType::StoredProcedure;
            cmd->Parameters->AddWithValue("@Id", id);

            try {
                conn->Open();
                SqlDataReader^ reader = cmd->ExecuteReader();

                if (reader->Read()) {
                    String^ resId = reader->GetValue(0)->ToString();
                    RolBrazo resRol = (RolBrazo)Int32::Parse(reader->GetValue(1)->ToString());
                    EstadoBrazo resEstado = (EstadoBrazo)Int32::Parse(reader->GetValue(2)->ToString());

                    brazoObj = gcnew BrazoRoboticoModel(resId, resRol);
                    brazoObj->Estado = resEstado;
                    brazoObj->Gripper = nullptr; // Inicializar vacío para inyección posterior
                }
                reader->Close();

                // Si el brazo existe, inyectamos relacionalmente sus subcomponentes
                if (brazoObj != nullptr) {
                    CargarArticulacionesParaBrazo(brazoObj, conn);
                    CargarGripperParaBrazo(brazoObj, conn);
                    CargarSensoresParaBrazo(brazoObj, conn);
                }
            }
            catch (Exception^ ex) {
                throw gcnew Exception("Error al buscar brazo por ID: " + ex->Message);
            }
            finally {
                if (conn->State == ConnectionState::Open) conn->Close();
            }
            return brazoObj;
        }

        // ==========================================================
        // READ: OBTENER TODOS LOS BRAZOS
        // ==========================================================
        List<BrazoRoboticoModel^>^ obtenerTodos() {
            List<BrazoRoboticoModel^>^ lista = gcnew List<BrazoRoboticoModel^>();
            SqlConnection^ conn = gcnew SqlConnection(connectionString);
            SqlCommand^ cmd = gcnew SqlCommand("sp_BrazosRoboticos_ObtenerTodos", conn);
            cmd->CommandType = CommandType::StoredProcedure;

            try {
                conn->Open();
                SqlDataReader^ reader = cmd->ExecuteReader();

                while (reader->Read()) {
                    String^ id = reader->GetValue(0)->ToString();
                    RolBrazo rol = (RolBrazo)Int32::Parse(reader->GetValue(1)->ToString());
                    EstadoBrazo estado = (EstadoBrazo)Int32::Parse(reader->GetValue(2)->ToString());

                    BrazoRoboticoModel^ b = gcnew BrazoRoboticoModel(id, rol);
                    b->Estado = estado;
                    b->Gripper = nullptr;
                    lista->Add(b);
                }
                reader->Close();

                // Hidratamos los componentes internos de cada brazo en la lista
                for each (BrazoRoboticoModel ^ b in lista) {
                    CargarArticulacionesParaBrazo(b, conn);
                    CargarGripperParaBrazo(b, conn);
                    CargarSensoresParaBrazo(b, conn);
                }
            }
            catch (Exception^ ex) {
                throw gcnew Exception("Error al obtener todos los brazos: " + ex->Message);
            }
            finally {
                if (conn->State == ConnectionState::Open) conn->Close();
            }
            return lista;
        }

        // ==========================================================
        // UPDATE: MODIFICAR ESTADO DEL BRAZO (Crítico para operación)
        // ==========================================================
        bool modificar(String^ id, EstadoBrazo nuevoEstado) {
            SqlConnection^ conn = gcnew SqlConnection(connectionString);
            SqlCommand^ cmd = gcnew SqlCommand("sp_BrazosRoboticos_ModificarEstado", conn);
            cmd->CommandType = CommandType::StoredProcedure;

            cmd->Parameters->AddWithValue("@Id", id);
            cmd->Parameters->AddWithValue("@Estado", (int)nuevoEstado);

            try {
                conn->Open();
                int filasAfectadas = cmd->ExecuteNonQuery();
                return (filasAfectadas > 0);
            }
            catch (Exception^ ex) {
                throw gcnew Exception("Error al actualizar estado del brazo: " + ex->Message);
            }
            finally {
                if (conn->State == ConnectionState::Open) conn->Close();
            }
        }

        // ==========================================================
        // DELETE: ELIMINAR BRAZO (Mantiene la firma pública)
        // ==========================================================
        bool eliminar(String^ id) {
            SqlConnection^ conn = gcnew SqlConnection(connectionString);
            SqlCommand^ cmd = gcnew SqlCommand("sp_BrazosRoboticos_Eliminar", conn);
            cmd->CommandType = CommandType::StoredProcedure;
            cmd->Parameters->AddWithValue("@Id", id);

            try {
                conn->Open();
                int filasAfectadas = cmd->ExecuteNonQuery();
                return (filasAfectadas > 0);
            }
            catch (Exception^ ex) {
                throw gcnew Exception("Error al eliminar brazo robótico: " + ex->Message);
            }
            finally {
                if (conn->State == ConnectionState::Open) conn->Close();
            }
        }

        // ==========================================================
        // GESTIÓN DE COMPONENTES INTERNOS (Inserciones directas a SQL)
        // ==========================================================
        bool agregarArticulacion(String^ idBrazo, String^ idArt, String^ nombre,
            double anguloActual, double anguloMin, double anguloMax) {

            if (buscarPorId(idBrazo) == nullptr) return false;

            SqlConnection^ conn = gcnew SqlConnection(connectionString);
            SqlCommand^ cmd = gcnew SqlCommand("sp_BrazoArticulaciones_Insertar", conn);
            cmd->CommandType = CommandType::StoredProcedure;

            cmd->Parameters->AddWithValue("@BrazoId", idBrazo);
            cmd->Parameters->AddWithValue("@IdArt", idArt);
            cmd->Parameters->AddWithValue("@Nombre", nombre);
            cmd->Parameters->AddWithValue("@Activo", 1);
            cmd->Parameters->AddWithValue("@AnguloActual", anguloActual);
            cmd->Parameters->AddWithValue("@AnguloMin", anguloMin);
            cmd->Parameters->AddWithValue("@AnguloMax", anguloMax);

            try {
                conn->Open();
                cmd->ExecuteNonQuery();
                return true;
            }
            catch (Exception^ ex) {
                throw gcnew Exception("Error al registrar articulación: " + ex->Message);
            }
            finally {
                if (conn->State == ConnectionState::Open) conn->Close();
            }
        }

        bool asignarGripper(String^ idBrazo, String^ idGripper, String^ nombre,
            double apertura, double fuerzaAgarre, bool abierto) {

            if (buscarPorId(idBrazo) == nullptr) return false;

            SqlConnection^ conn = gcnew SqlConnection(connectionString);
            SqlCommand^ cmd = gcnew SqlCommand("sp_BrazoGrippers_Asignar", conn);
            cmd->CommandType = CommandType::StoredProcedure;

            cmd->Parameters->AddWithValue("@BrazoId", idBrazo);
            cmd->Parameters->AddWithValue("@IdGripper", idGripper);
            cmd->Parameters->AddWithValue("@Nombre", nombre);
            cmd->Parameters->AddWithValue("@Activo", 1);
            cmd->Parameters->AddWithValue("@Apertura", apertura);
            cmd->Parameters->AddWithValue("@FuerzaAgarre", fuerzaAgarre);
            cmd->Parameters->AddWithValue("@Abierto", abierto ? 1 : 0);

            try {
                conn->Open();
                cmd->ExecuteNonQuery();
                return true;
            }
            catch (Exception^ ex) {
                throw gcnew Exception("Error al asignar gripper: " + ex->Message);
            }
            finally {
                if (conn->State == ConnectionState::Open) conn->Close();
            }
        }

        bool agregarSensorPosicion(String^ idBrazo, String^ idSensor, String^ nombre,
            double anguloMedido, double tolerancia) {

            if (buscarPorId(idBrazo) == nullptr) return false;

            SqlConnection^ conn = gcnew SqlConnection(connectionString);
            SqlCommand^ cmd = gcnew SqlCommand("sp_BrazoSensoresPos_Insertar", conn);
            cmd->CommandType = CommandType::StoredProcedure;

            cmd->Parameters->AddWithValue("@BrazoId", idBrazo);
            cmd->Parameters->AddWithValue("@IdSensor", idSensor);
            cmd->Parameters->AddWithValue("@Nombre", nombre);
            cmd->Parameters->AddWithValue("@Activo", 1);
            cmd->Parameters->AddWithValue("@AnguloMedido", anguloMedido);
            cmd->Parameters->AddWithValue("@Tolerancia", tolerancia);

            try {
                conn->Open();
                cmd->ExecuteNonQuery();
                return true;
            }
            catch (Exception^ ex) {
                throw gcnew Exception("Error al registrar sensor de posición: " + ex->Message);
            }
            finally {
                if (conn->State == ConnectionState::Open) conn->Close();
            }
        }

        bool agregarSensorFuerza(String^ idBrazo, String^ idSensor, String^ nombre,
            double fuerzaActual, double fuerzaMin, double fuerzaMax) {

            if (buscarPorId(idBrazo) == nullptr) return false;

            SqlConnection^ conn = gcnew SqlConnection(connectionString);
            SqlCommand^ cmd = gcnew SqlCommand("sp_BrazoSensoresFue_Insertar", conn);
            cmd->CommandType = CommandType::StoredProcedure;

            cmd->Parameters->AddWithValue("@BrazoId", idBrazo);
            cmd->Parameters->AddWithValue("@IdSensor", idSensor);
            cmd->Parameters->AddWithValue("@Nombre", nombre);
            cmd->Parameters->AddWithValue("@Activo", 1);
            cmd->Parameters->AddWithValue("@FuerzaActual", fuerzaActual);
            cmd->Parameters->AddWithValue("@FuerzaMin", fuerzaMin);
            cmd->Parameters->AddWithValue("@FuerzaMax", fuerzaMax);

            try {
                conn->Open();
                cmd->ExecuteNonQuery();
                return true;
            }
            catch (Exception^ ex) {
                throw gcnew Exception("Error al registrar sensor de fuerza: " + ex->Message);
            }
            finally {
                if (conn->State == ConnectionState::Open) conn->Close();
            }
        }

    private:
        // ==========================================================
        // MÉTODOS PRIVADOS DE HIDRATACIÓN RELACIONAL (SUB-QUERIES)
        // ==========================================================
        void CargarArticulacionesParaBrazo(BrazoRoboticoModel^ b, SqlConnection^ conn) {
            SqlCommand^ cmd = gcnew SqlCommand("sp_BrazoArticulaciones_ObtenerPorBrazo", conn);
            cmd->CommandType = CommandType::StoredProcedure;
            cmd->Parameters->AddWithValue("@BrazoId", b->Id);

            SqlDataReader^ reader = cmd->ExecuteReader();
            while (reader->Read()) {
                ArticulacionModel^ a = gcnew ArticulacionModel(
                    reader->GetValue(0)->ToString(),
                    reader->GetValue(1)->ToString(),
                    Int32::Parse(reader->GetValue(2)->ToString()) == 1,
                    Double::Parse(reader->GetValue(3)->ToString()),
                    Double::Parse(reader->GetValue(4)->ToString()),
                    Double::Parse(reader->GetValue(5)->ToString())
                );
                b->Articulaciones->Add(a);
            }
            reader->Close();
        }

        void CargarGripperParaBrazo(BrazoRoboticoModel^ b, SqlConnection^ conn) {
            SqlCommand^ cmd = gcnew SqlCommand("sp_BrazoGrippers_ObtenerPorBrazo", conn);
            cmd->CommandType = CommandType::StoredProcedure;
            cmd->Parameters->AddWithValue("@BrazoId", b->Id);

            SqlDataReader^ reader = cmd->ExecuteReader();
            if (reader->Read()) {
                b->Gripper = gcnew GripperModel(
                    reader->GetValue(0)->ToString(),
                    reader->GetValue(1)->ToString(),
                    Int32::Parse(reader->GetValue(2)->ToString()) == 1,
                    Double::Parse(reader->GetValue(3)->ToString()),
                    Double::Parse(reader->GetValue(4)->ToString()),
                    Int32::Parse(reader->GetValue(5)->ToString()) == 1
                );
            }
            reader->Close();
        }

        void CargarSensoresParaBrazo(BrazoRoboticoModel^ b, SqlConnection^ conn) {
            // 1. Cargar Sensores de Posición
            SqlCommand^ cmdPos = gcnew SqlCommand("sp_BrazoSensoresPos_ObtenerPorBrazo", conn);
            cmdPos->CommandType = CommandType::StoredProcedure;
            cmdPos->Parameters->AddWithValue("@BrazoId", b->Id);

            SqlDataReader^ readerPos = cmdPos->ExecuteReader();
            while (readerPos->Read()) {
                SensorPosicionModel^ sp = gcnew SensorPosicionModel(
                    readerPos->GetValue(0)->ToString(),
                    readerPos->GetValue(1)->ToString(),
                    Int32::Parse(readerPos->GetValue(2)->ToString()) == 1,
                    Double::Parse(readerPos->GetValue(3)->ToString()),
                    Double::Parse(readerPos->GetValue(4)->ToString())
                );
                b->Sensores->Add(sp);
            }
            readerPos->Close();

            // 2. Cargar Sensores de Fuerza
            SqlCommand^ cmdFue = gcnew SqlCommand("sp_BrazoSensoresFue_ObtenerPorBrazo", conn);
            cmdFue->CommandType = CommandType::StoredProcedure;
            cmdFue->Parameters->AddWithValue("@BrazoId", b->Id);

            SqlDataReader^ readerFue = cmdFue->ExecuteReader();
            while (readerFue->Read()) {
                SensorFuerzaModel^ sf = gcnew SensorFuerzaModel(
                    readerFue->GetValue(0)->ToString(),
                    readerFue->GetValue(1)->ToString(),
                    Int32::Parse(readerFue->GetValue(2)->ToString()) == 1,
                    Double::Parse(readerFue->GetValue(3)->ToString()),
                    Double::Parse(readerFue->GetValue(4)->ToString()),
                    Double::Parse(readerFue->GetValue(5)->ToString())
                );
                b->Sensores->Add(sf);
            }
            readerFue->Close();
        }
    };
}