#pragma once
using namespace System;
using namespace System::IO::Ports;
using namespace System::Threading;

namespace GemeloDigitalController {

    public ref class BrazoFisicoCliente {
    public:
        static String^ PuertoCom;
        static int BaudRate;

        static BrazoFisicoCliente() {
            PuertoCom = "COM12"; // <- AJUSTAR si cambia
            BaudRate = 115200;
        }

        static bool irAPose(String^ nombrePose) {
            return EnviarComando("P:" + nombrePose);
        }

    private:
        static SerialPort^ puerto;

        static void AsegurarConexion() {
            if (puerto == nullptr) {
                puerto = gcnew SerialPort(PuertoCom, BaudRate, Parity::None, 8, StopBits::One);
                puerto->NewLine = "\n";
                puerto->WriteTimeout = 1000;
                puerto->ReadTimeout = 8000; // margen para secuencias con espera inteligente // MOV2 hace 2 movimientos seguidos, necesita mas margen
            }
            if (!puerto->IsOpen) {
                puerto->Open();
                Thread::Sleep(2000);
            }
        }

        static bool EnviarComando(String^ comando) {
            try {
                AsegurarConexion();
                puerto->WriteLine(comando);
                String^ respuesta = puerto->ReadLine();
                return respuesta->StartsWith("OK");
            }
            catch (Exception^ ex) {
                System::Diagnostics::Debug::WriteLine("Error comunicando con ESP32: " + ex->Message);
                return false;
            }
        }
    };
}