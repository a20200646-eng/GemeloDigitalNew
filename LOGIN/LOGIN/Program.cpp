#include "MyForm.h"

using namespace System;
using namespace System::Windows::Forms;
using namespace LOGIN;

[STAThread]
int main(array<String^>^ args) {
    Application::EnableVisualStyles();
    Application::SetCompatibleTextRenderingDefault(false);
    LOGIN::MyForm^ ventana = gcnew LOGIN::MyForm();
    Application::Run(ventana);
    return 0;
}