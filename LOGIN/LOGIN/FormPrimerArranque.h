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
        System::Windows::Forms::Label^ lblTurno;
        System::Windows::Forms::ComboBox^ cmbTurno;
        System::Windows::Forms::Button^ btnCrear;

#pragma region Windows Form Designer generated code
        void InitializeComponent(void) {
            this->components = nullptr;
            this->panelTitulo = gcnew System::Windows::Forms::Panel();
            this->lblTitulo = gcnew System::Windows::Forms::Label();
            this->lblSubtitulo = gcnew System::Windows::Forms::Label();
            this->panelAviso = gcnew System::Windows::Forms::Panel();
            this->lblAviso = gcnew System::Windows::Forms::Label();
            this->lblNombre = gcnew System::Windows::Forms::Label();
            this->txtNombre = gcnew System::Windows::Forms::TextBox();
            this->lblContrasena = gcnew System::Windows::Forms::Label();
            this->txtContrasena = gcnew System::Windows::Forms::TextBox();
            this->lblConfirmar = gcnew System::Windows::Forms::Label();
            this->txtConfirmar = gcnew System::Windows::Forms::TextBox();
            this->lblTurno = gcnew System::Windows::Forms::Label();
            this->cmbTurno = gcnew System::Windows::Forms::ComboBox();
            this->btnCrear = gcnew System::Windows::Forms::Button();

            this->SuspendLayout();

            // panelTitulo
            this->panelTitulo->BackColor = Color::FromArgb(15, 23, 42);
            this->panelTitulo->Dock = DockStyle::Top;
            this->panelTitulo->Size = System::Drawing::Size(360, 70);
            this->panelTitulo->Controls->Add(this->lblTitulo);
            this->panelTitulo->Controls->Add(this->lblSubtitulo);

            // lblTitulo
            this->lblTitulo->Text = L"GemeloDigital";
            this->lblTitulo->ForeColor = Color::White;
            this->lblTitulo->Font = gcnew System::Drawing::Font(L"Segoe UI", 14, FontStyle::Bold);
            this->lblTitulo->Location = System::Drawing::Point(12, 8);
            this->lblTitulo->AutoSize = true;

            // lblSubtitulo
            this->lblSubtitulo->Text = L"Configuración inicial del sistema";
            this->lblSubtitulo->ForeColor = Color::FromArgb(148, 163, 184);
            this->lblSubtitulo->Font = gcnew System::Drawing::Font(L"Segoe UI", 8);
            this->lblSubtitulo->Location = System::Drawing::Point(14, 40);
            this->lblSubtitulo->AutoSize = true;

            // panelAviso
            this->panelAviso->BackColor = Color::FromArgb(30, 58, 95);
            this->panelAviso->Location = System::Drawing::Point(12, 82);
            this->panelAviso->Size = System::Drawing::Size(336, 36);
            this->panelAviso->Controls->Add(this->lblAviso);

            // lblAviso
            this->lblAviso->Text = L"No se encontraron usuarios. Crea el administrador inicial.";
            this->lblAviso->ForeColor = Color::FromArgb(147, 197, 253);
            this->lblAviso->Font = gcnew System::Drawing::Font(L"Segoe UI", 7.5F);
            this->lblAviso->Location = System::Drawing::Point(8, 10);
            this->lblAviso->AutoSize = true;

            // lblNombre
            this->lblNombre->Text = L"Nombre de usuario:";
            this->lblNombre->ForeColor = Color::FromArgb(148, 163, 184);
            this->lblNombre->Font = gcnew System::Drawing::Font(L"Segoe UI", 8);
            this->lblNombre->Location = System::Drawing::Point(12, 132);
            this->lblNombre->AutoSize = true;

            // txtNombre
            this->txtNombre->Location = System::Drawing::Point(12, 150);
            this->txtNombre->Size = System::Drawing::Size(336, 22);
            this->txtNombre->BackColor = Color::FromArgb(30, 40, 58);
            this->txtNombre->ForeColor = Color::White;
            this->txtNombre->Font = gcnew System::Drawing::Font(L"Segoe UI", 9);

            // lblContrasena
            this->lblContrasena->Text = L"Contraseña:";
            this->lblContrasena->ForeColor = Color::FromArgb(148, 163, 184);
            this->lblContrasena->Font = gcnew System::Drawing::Font(L"Segoe UI", 8);
            this->lblContrasena->Location = System::Drawing::Point(12, 184);
            this->lblContrasena->AutoSize = true;

            // txtContrasena
            this->txtContrasena->Location = System::Drawing::Point(12, 202);
            this->txtContrasena->Size = System::Drawing::Size(336, 22);
            this->txtContrasena->PasswordChar = '*';
            this->txtContrasena->BackColor = Color::FromArgb(30, 40, 58);
            this->txtContrasena->ForeColor = Color::White;
            this->txtContrasena->Font = gcnew System::Drawing::Font(L"Segoe UI", 9);

            // lblConfirmar
            this->lblConfirmar->Text = L"Confirmar contraseña:";
            this->lblConfirmar->ForeColor = Color::FromArgb(148, 163, 184);
            this->lblConfirmar->Font = gcnew System::Drawing::Font(L"Segoe UI", 8);
            this->lblConfirmar->Location = System::Drawing::Point(12, 236);
            this->lblConfirmar->AutoSize = true;

            // txtConfirmar
            this->txtConfirmar->Location = System::Drawing::Point(12, 254);
            this->txtConfirmar->Size = System::Drawing::Size(336, 22);
            this->txtConfirmar->PasswordChar = '*';
            this->txtConfirmar->BackColor = Color::FromArgb(30, 40, 58);
            this->txtConfirmar->ForeColor = Color::White;
            this->txtConfirmar->Font = gcnew System::Drawing::Font(L"Segoe UI", 9);

            // lblTurno
            this->lblTurno->Text = L"Turno:";
            this->lblTurno->ForeColor = Color::FromArgb(148, 163, 184);
            this->lblTurno->Font = gcnew System::Drawing::Font(L"Segoe UI", 8);
            this->lblTurno->Location = System::Drawing::Point(12, 288);
            this->lblTurno->AutoSize = true;

            // cmbTurno
            this->cmbTurno->Location = System::Drawing::Point(12, 306);
            this->cmbTurno->Size = System::Drawing::Size(336, 22);
            this->cmbTurno->DropDownStyle = ComboBoxStyle::DropDownList;
            this->cmbTurno->BackColor = Color::FromArgb(30, 40, 58);
            this->cmbTurno->ForeColor = Color::White;
            this->cmbTurno->Font = gcnew System::Drawing::Font(L"Segoe UI", 9);
            this->cmbTurno->Items->Add("Mañana");
            this->cmbTurno->Items->Add("Tarde");
            this->cmbTurno->Items->Add("Noche");
            this->cmbTurno->SelectedIndex = 0;

            // btnCrear
            this->btnCrear->Text = L"Crear administrador";
            this->btnCrear->Location = System::Drawing::Point(12, 342);
            this->btnCrear->Size = System::Drawing::Size(336, 36);
            this->btnCrear->BackColor = Color::FromArgb(37, 99, 235);
            this->btnCrear->ForeColor = Color::White;
            this->btnCrear->Font = gcnew System::Drawing::Font(L"Segoe UI", 10, FontStyle::Bold);
            this->btnCrear->FlatStyle = FlatStyle::Flat;
            this->btnCrear->FlatAppearance->BorderSize = 0;
            this->btnCrear->Click += gcnew System::EventHandler(this, &FormPrimerArranque::btnCrear_Click);

            // Form
            this->BackColor = Color::FromArgb(22, 30, 46);
            this->ClientSize = System::Drawing::Size(360, 396);
            this->Text = L"GemeloDigital - Configuración inicial";
            this->MaximizeBox = false;
            this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
            this->StartPosition = FormStartPosition::CenterScreen;
            this->Controls->Add(this->panelTitulo);
            this->Controls->Add(this->panelAviso);
            this->Controls->Add(this->lblNombre);
            this->Controls->Add(this->txtNombre);
            this->Controls->Add(this->lblContrasena);
            this->Controls->Add(this->txtContrasena);
            this->Controls->Add(this->lblConfirmar);
            this->Controls->Add(this->txtConfirmar);
            this->Controls->Add(this->lblTurno);
            this->Controls->Add(this->cmbTurno);
            this->Controls->Add(this->btnCrear);

            this->ResumeLayout(false);
        }
#pragma endregion

        System::Void btnCrear_Click(System::Object^ sender, System::EventArgs^ e) {
            String^ nombre = txtNombre->Text->Trim();
            String^ pass = txtContrasena->Text;
            String^ conf = txtConfirmar->Text;
            String^ turno = cmbTurno->SelectedItem->ToString();

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
                ctrl->agregar("1", nombre, pass, 1, turno);
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

        System::Void FormPrimerArranque_Load(System::Object^ sender, System::EventArgs^ e) {
        }
    };
}