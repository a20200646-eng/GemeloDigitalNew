#pragma once

using namespace System;
using namespace System::Data;
using namespace System::Data::SqlClient;

namespace GemeloDigitalController {

    public ref class DBConnection {
    private:
        // Cadena de conexión actualizada con tus credenciales reales
        static String^ connectionString = "Server=bdmijael23.cczveeoo8rq2.us-east-1.rds.amazonaws.com,1433;"
            "Database=bdmijael23;"
            "User Id=admin;"
            "Password=abcd1234;";

    public:
        // Método estático para obtener la conexión en cualquier Controller
        static SqlConnection^ GetConnection() {
            return gcnew SqlConnection(connectionString);
        }
    };
}