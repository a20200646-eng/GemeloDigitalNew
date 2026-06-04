#pragma once
using namespace GemeloDigitalController;
using namespace GemeloDigitalModel;

namespace LOGIN {
    using namespace System;
    using namespace System::Windows::Forms;
    using namespace System::Drawing;

    public ref class FormPrimerArranque : public System::Windows::Forms::Form {
    public:
        FormPrimerArranque(void) {
            InitializeComponent();
        }
    protected:
        ~FormPrimerArranque() {
            if (components) delete components;
        }

    private:
        System::ComponentModel::Container^ components;
        System::Windows::Forms::Panel^ panelTitulo;
        System::Windows::Forms::Label^ lblTitulo;
        System::Windows::Forms::Label^ lblSubtitulo;
        System::Windows::Forms::Panel^ panelAviso;
        System::Windows::Forms::Label^ lblAviso;
        System::Windows::Forms::Label^ lblNombre;
        System::Windows::Forms::TextBox^ txtNombre;
        System::Windows::Forms::Label^ lblContrasena;
        System::Windows::Forms::TextBox^ txtContrasena;
        System::Windows::Forms::Label^ lblConfirmar;
        System::Windows::Forms::TextBox^ txtConfirmar;
        System::Windows::Forms::Button^ btnCrear;
        System::Windows::Forms::Label^ lblNota1;
        System::Windows::Forms::Label^ lblNota2;

#pragma region Windows Form Designer generated code
        void InitializeComponent(void) {
            this->panelTitulo = gcnew Panel();
            this->lblTitulo = gcnew Label();
            this->panelAviso = gcnew Panel();
            this->lblAviso = gcnew Label();
            this->lblSubtitulo = gcnew Label();
            this->lblNombre = gcnew Label();
            this->txtNombre = gcnew TextBox();
            this->lblContrasena = gcnew Label();
            this->txtContrasena = gcnew TextBox();
            this->lblConfirmar = gcnew Label();
            this->txtConfirmar = gcnew TextBox();
            this->btnCrear = gcnew Button();
            this->lblNota1 = gcnew Label();
            this->lblNota2 = gcnew Label();

            this->SuspendLayout();

			// ------FORM CONFIGURACIÓN INICIAL------
            this->Text = L"GemeloDigital - Configuración inicial";
            this->ClientSize = Drawing::Size(800, 560);
            this->FormBorderStyle = Windows::Forms::FormBorderStyle::FixedSingle;
            this->MaximizeBox = false;
            this->StartPosition = FormStartPosition::CenterScreen;
            this->BackColor = Drawing::Color::FromArgb(18, 26, 38);

			// ----- Panel título -----
            this->panelTitulo->BackColor = Drawing::Color::FromArgb(10, 16, 26);
            this->panelTitulo->Dock = DockStyle::Top;
            this->panelTitulo->Height = 44;
            this->panelTitulo->Controls->Add(this->lblTitulo);

            this->lblTitulo->Text = L"Configuración inicial del sistema";
            this->lblTitulo->ForeColor = Drawing::Color::White;
            this->lblTitulo->Font = gcnew Drawing::Font(L"Segoe UI", 10, Drawing::FontStyle::Regular);
            this->lblTitulo->Location = Drawing::Point(16, 12);
            this->lblTitulo->AutoSize = true;

			// ----- Subtítulo -----
            this->lblSubtitulo->Text = L"Crear Administrador";
            this->lblSubtitulo->ForeColor = Drawing::Color::White;
            this->lblSubtitulo->Font = gcnew Drawing::Font(L"Segoe UI", 18, Drawing::FontStyle::Bold);
            this->lblSubtitulo->Location = Drawing::Point(30, 60);
            this->lblSubtitulo->AutoSize = true;

			// -- Panel aviso ─────────────────────────────────────────────
            this->panelAviso->BackColor = Drawing::Color::FromArgb(15, 40, 80);
            this->panelAviso->BorderStyle = BorderStyle::FixedSingle;
            this->panelAviso->Location = Drawing::Point(30, 110);
            this->panelAviso->Size = Drawing::Size(740, 48);
            this->panelAviso->Controls->Add(this->lblAviso);

            this->lblAviso->Text = L"No se encontró ningún administrador registrado. Cree el primero para continuar.";
            this->lblAviso->ForeColor = Drawing::Color::FromArgb(80, 160, 255);
            this->lblAviso->Font = gcnew Drawing::Font(L"Segoe UI", 9);
            this->lblAviso->Location = Drawing::Point(12, 14);
            this->lblAviso->AutoSize = true;

            // ── Nombre ────────────────────────────────────────────
            this->lblNombre->Text = L"Nombre de usuario";
            this->lblNombre->ForeColor = Drawing::Color::White;
            this->lblNombre->Font = gcnew Drawing::Font(L"Segoe UI", 9);
            this->lblNombre->Location = Drawing::Point(30, 178);
            this->lblNombre->AutoSize = true;

            this->txtNombre->Location = Drawing::Point(30, 198);
            this->txtNombre->Size = Drawing::Size(740, 28);
            this->txtNombre->BackColor = Drawing::Color::FromArgb(28, 38, 54);
            this->txtNombre->ForeColor = Drawing::Color::White;
            this->txtNombre->BorderStyle = BorderStyle::FixedSingle;
            this->txtNombre->Font = gcnew Drawing::Font(L"Segoe UI", 10);

            // ── Contraseña ────────────────────────────────────────
            this->lblContrasena->Text = L"Contraseña";
            this->lblContrasena->ForeColor = Drawing::Color::White;
            this->lblContrasena->Font = gcnew Drawing::Font(L"Segoe UI", 9);
            this->lblContrasena->Location = Drawing::Point(30, 242);
            this->lblContrasena->AutoSize = true;

            this->txtContrasena->Location = Drawing::Point(30, 262);
            this->txtContrasena->Size = Drawing::Size(740, 28);
            this->txtContrasena->PasswordChar = '*';
            this->txtContrasena->BackColor = Drawing::Color::FromArgb(28, 38, 54);
            this->txtContrasena->ForeColor = Drawing::Color::White;
            this->txtContrasena->BorderStyle = BorderStyle::FixedSingle;
            this->txtContrasena->Font = gcnew Drawing::Font(L"Segoe UI", 10);

            // ── Confirmar contraseña ──────────────────────────────
            this->lblConfirmar->Text = L"Confirmar contraseña";
            this->lblConfirmar->ForeColor = Drawing::Color::White;
            this->lblConfirmar->Font = gcnew Drawing::Font(L"Segoe UI", 9);
            this->lblConfirmar->Location = Drawing::Point(30, 306);
            this->lblConfirmar->AutoSize = true;

            this->txtConfirmar->Location = Drawing::Point(30, 326);
            this->txtConfirmar->Size = Drawing::Size(740, 28);
            this->txtConfirmar->PasswordChar = '*';
            this->txtConfirmar->BackColor = Drawing::Color::FromArgb(28, 38, 54);
            this->txtConfirmar->ForeColor = Drawing::Color::White;
            this->txtConfirmar->BorderStyle = BorderStyle::FixedSingle;
            this->txtConfirmar->Font = gcnew Drawing::Font(L"Segoe UI", 10);

            // ── Botón crear ───────────────────────────────────────
            this->btnCrear->Text = L"Crear administrador e iniciar sistema";
            this->btnCrear->Location = Drawing::Point(30, 374);
            this->btnCrear->Size = Drawing::Size(740, 46);
            this->btnCrear->BackColor = Drawing::Color::FromArgb(230, 160, 0);
            this->btnCrear->ForeColor = Drawing::Color::Black;
            this->btnCrear->FlatStyle = FlatStyle::Flat;
            this->btnCrear->FlatAppearance->BorderSize = 0;
            this->btnCrear->Font = gcnew Drawing::Font(L"Segoe UI", 11, Drawing::FontStyle::Bold);
            this->btnCrear->Click += gcnew EventHandler(this, &FormPrimerArranque::btnCrear_Click);

            // ── Notas al pie ──────────────────────────────────────
            this->lblNota1->Text = L"★  Este formulario se muestra solo cuando datos\\administradores.dat no existe o está vacío.";
            this->lblNota1->ForeColor = Drawing::Color::FromArgb(230, 160, 0);
            this->lblNota1->Font = gcnew Drawing::Font(L"Segoe UI", 8);
            this->lblNota1->Location = Drawing::Point(30, 436);
            this->lblNota1->AutoSize = true;

            this->lblNota2->Text = L"Al cerrar sin crear admin, el sistema termina.";
            this->lblNota2->ForeColor = Drawing::Color::FromArgb(160, 160, 160);
            this->lblNota2->Font = gcnew Drawing::Font(L"Segoe UI", 8);
            this->lblNota2->Location = Drawing::Point(30, 458);
            this->lblNota2->AutoSize = true;

            // ── Agregar controles al form ──────────────────────────
            this->Controls->Add(this->panelTitulo);
            this->Controls->Add(this->lblSubtitulo);
            this->Controls->Add(this->panelAviso);
            this->Controls->Add(this->lblNombre);
            this->Controls->Add(this->txtNombre);
            this->Controls->Add(this->lblContrasena);
            this->Controls->Add(this->txtContrasena);
            this->Controls->Add(this->lblConfirmar);
            this->Controls->Add(this->txtConfirmar);
            this->Controls->Add(this->btnCrear);
            this->Controls->Add(this->lblNota1);
            this->Controls->Add(this->lblNota2);

            this->ResumeLayout(false);
            this->PerformLayout();
        }
#pragma endregion

        // ── Lógica del botón ─────────────────────────────────────
        System::Void btnCrear_Click(System::Object^ sender, System::EventArgs^ e) {
            String^ nombre = txtNombre->Text->Trim();
            String^ pass = txtContrasena->Text;
            String^ conf = txtConfirmar->Text;

            // Validaciones
            if (nombre == "" || pass == "" || conf == "") {
                MessageBox::Show(L"Todos los campos son obligatorios.",
                    L"Campos vacíos", MessageBoxButtons::OK, MessageBoxIcon::Warning);
                return;
            }
            if (pass != conf) {
                MessageBox::Show(L"Las contraseñas no coinciden.",
                    L"Error", MessageBoxButtons::OK, MessageBoxIcon::Warning);
                txtConfirmar->Clear();
                txtConfirmar->Focus();
                return;
            }

            try {
                AdministradorController^ ctrl = gcnew AdministradorController();
                ctrl->agregar((1).ToString(), nombre, pass, 1);  // id=1, nivelAcceso=1 (Admin)
                MessageBox::Show(
                    L"Administrador creado correctamente.\nYa puede iniciar sesión.",
                    L"Éxito", MessageBoxButtons::OK, MessageBoxIcon::Information);
                this->DialogResult = Windows::Forms::DialogResult::OK;
                this->Close();
            }
            catch (Exception^ ex) {
                MessageBox::Show(L"Error al guardar: " + ex->Message,
                    L"Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
            }
        }
    };
}