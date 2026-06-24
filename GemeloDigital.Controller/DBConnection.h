#pragma once

using namespace System;
using namespace System::Data;
using namespace System::Data::SqlClient;

namespace GemeloDigitalController {

    public ref class DBConnection {
    private:
        // Cadena de conexión actualizada con tus credenciales reales
        static String^ connectionString =
            "Server=200.16.7.140,1433;"
            "Database=a20206433;"
            "User Id=a20206433;"
            "Password=r75c9Q53;";

    public:
        // Método estático para obtener la conexión en cualquier Controller
        static SqlConnection^ GetConnection() {
            return gcnew SqlConnection(connectionString);
        }
    };
}