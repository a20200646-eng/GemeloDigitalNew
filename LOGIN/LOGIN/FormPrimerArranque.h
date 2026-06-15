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
            this->panelTitulo = (gcnew System::Windows::Forms::Panel());
            this->lblTitulo = (gcnew System::Windows::Forms::Label());
            this->lblSubtitulo = (gcnew System::Windows::Forms::Label());
            this->panelAviso = (gcnew System::Windows::Forms::Panel());
            this->lblAviso = (gcnew System::Windows::Forms::Label());
            this->lblNombre = (gcnew System::Windows::Forms::Label());
            this->txtNombre = (gcnew System::Windows::Forms::TextBox());
            this->lblContrasena = (gcnew System::Windows::Forms::Label());
            this->txtContrasena = (gcnew System::Windows::Forms::TextBox());
            this->lblConfirmar = (gcnew System::Windows::Forms::Label());
            this->txtConfirmar = (gcnew System::Windows::Forms::TextBox());
            this->lblTurno = (gcnew System::Windows::Forms::Label());
            this->cmbTurno = (gcnew System::Windows::Forms::ComboBox());
            this->btnCrear = (gcnew System::Windows::Forms::Button());
            this->panelTitulo->SuspendLayout();
            this->panelAviso->SuspendLayout();
            this->SuspendLayout();
            // 
            // panelTitulo
            // 
            this->panelTitulo->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(15)), static_cast<System::Int32>(static_cast<System::Byte>(23)),
                static_cast<System::Int32>(static_cast<System::Byte>(42)));
            this->panelTitulo->Controls->Add(this->lblTitulo);
            this->panelTitulo->Controls->Add(this->lblSubtitulo);
            this->panelTitulo->Dock = System::Windows::Forms::DockStyle::Top;
            this->panelTitulo->Location = System::Drawing::Point(0, 0);
            this->panelTitulo->Name = L"panelTitulo";
            this->panelTitulo->Size = System::Drawing::Size(368, 70);
            this->panelTitulo->TabIndex = 0;
            // 
            // lblTitulo
            // 
            this->lblTitulo->AutoSize = true;
            this->lblTitulo->Font = (gcnew System::Drawing::Font(L"Segoe UI", 14, System::Drawing::FontStyle::Bold));
            this->lblTitulo->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
                static_cast<System::Int32>(static_cast<System::Byte>(255)));
            this->lblTitulo->Location = System::Drawing::Point(12, 8);
            this->lblTitulo->Name = L"lblTitulo";
            this->lblTitulo->Size = System::Drawing::Size(177, 32);
            this->lblTitulo->TabIndex = 0;
            this->lblTitulo->Text = L"GemeloDigital";
            // 
            // lblSubtitulo
            // 
            this->lblSubtitulo->AutoSize = true;
            this->lblSubtitulo->Font = (gcnew System::Drawing::Font(L"Segoe UI", 8));
            this->lblSubtitulo->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(148)), static_cast<System::Int32>(static_cast<System::Byte>(163)),
                static_cast<System::Int32>(static_cast<System::Byte>(184)));
            this->lblSubtitulo->Location = System::Drawing::Point(14, 40);
            this->lblSubtitulo->Name = L"lblSubtitulo";
            this->lblSubtitulo->Size = System::Drawing::Size(203, 19);
            this->lblSubtitulo->TabIndex = 1;
            this->lblSubtitulo->Text = L"Configuración inicial del sistema";
            // 
            // panelAviso
            // 
            this->panelAviso->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(30)), static_cast<System::Int32>(static_cast<System::Byte>(58)),
                static_cast<System::Int32>(static_cast<System::Byte>(95)));
            this->panelAviso->Controls->Add(this->lblAviso);
            this->panelAviso->Location = System::Drawing::Point(12, 82);
            this->panelAviso->Name = L"panelAviso";
            this->panelAviso->Size = System::Drawing::Size(352, 36);
            this->panelAviso->TabIndex = 1;
            // 
            // lblAviso
            // 
            this->lblAviso->AutoSize = true;
            this->lblAviso->Font = (gcnew System::Drawing::Font(L"Segoe UI", 7.5F));
            this->lblAviso->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(147)), static_cast<System::Int32>(static_cast<System::Byte>(197)),
                static_cast<System::Int32>(static_cast<System::Byte>(253)));
            this->lblAviso->Location = System::Drawing::Point(8, 10);
            this->lblAviso->Name = L"lblAviso";
            this->lblAviso->Size = System::Drawing::Size(344, 17);
            this->lblAviso->TabIndex = 0;
            this->lblAviso->Text = L"No se encontraron usuarios. Crea el administrador inicial.";
            // 
            // lblNombre
            // 
            this->lblNombre->AutoSize = true;
            this->lblNombre->Font = (gcnew System::Drawing::Font(L"Segoe UI", 8));
            this->lblNombre->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(148)), static_cast<System::Int32>(static_cast<System::Byte>(163)),
                static_cast<System::Int32>(static_cast<System::Byte>(184)));
            this->lblNombre->Location = System::Drawing::Point(12, 132);
            this->lblNombre->Name = L"lblNombre";
            this->lblNombre->Size = System::Drawing::Size(130, 19);
            this->lblNombre->TabIndex = 2;
            this->lblNombre->Text = L"Nombre de usuario:";
            // 
            // txtNombre
            // 
            this->txtNombre->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(30)), static_cast<System::Int32>(static_cast<System::Byte>(40)),
                static_cast<System::Int32>(static_cast<System::Byte>(58)));
            this->txtNombre->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9));
            this->txtNombre->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
                static_cast<System::Int32>(static_cast<System::Byte>(255)));
            this->txtNombre->Location = System::Drawing::Point(12, 150);
            this->txtNombre->Name = L"txtNombre";
            this->txtNombre->Size = System::Drawing::Size(352, 27);
            this->txtNombre->TabIndex = 3;
            // 
            // lblContrasena
            // 
            this->lblContrasena->AutoSize = true;
            this->lblContrasena->Font = (gcnew System::Drawing::Font(L"Segoe UI", 8));
            this->lblContrasena->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(148)), static_cast<System::Int32>(static_cast<System::Byte>(163)),
                static_cast<System::Int32>(static_cast<System::Byte>(184)));
            this->lblContrasena->Location = System::Drawing::Point(12, 184);
            this->lblContrasena->Name = L"lblContrasena";
            this->lblContrasena->Size = System::Drawing::Size(82, 19);
            this->lblContrasena->TabIndex = 4;
            this->lblContrasena->Text = L"Contraseña:";
            // 
            // txtContrasena
            // 
            this->txtContrasena->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(30)), static_cast<System::Int32>(static_cast<System::Byte>(40)),
                static_cast<System::Int32>(static_cast<System::Byte>(58)));
            this->txtContrasena->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9));
            this->txtContrasena->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
                static_cast<System::Int32>(static_cast<System::Byte>(255)));
            this->txtContrasena->Location = System::Drawing::Point(12, 202);
            this->txtContrasena->Name = L"txtContrasena";
            this->txtContrasena->PasswordChar = '*';
            this->txtContrasena->Size = System::Drawing::Size(352, 27);
            this->txtContrasena->TabIndex = 5;
            // 
            // lblConfirmar
            // 
            this->lblConfirmar->AutoSize = true;
            this->lblConfirmar->Font = (gcnew System::Drawing::Font(L"Segoe UI", 8));
            this->lblConfirmar->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(148)), static_cast<System::Int32>(static_cast<System::Byte>(163)),
                static_cast<System::Int32>(static_cast<System::Byte>(184)));
            this->lblConfirmar->Location = System::Drawing::Point(12, 236);
            this->lblConfirmar->Name = L"lblConfirmar";
            this->lblConfirmar->Size = System::Drawing::Size(144, 19);
            this->lblConfirmar->TabIndex = 6;
            this->lblConfirmar->Text = L"Confirmar contraseña:";
            // 
            // txtConfirmar
            // 
            this->txtConfirmar->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(30)), static_cast<System::Int32>(static_cast<System::Byte>(40)),
                static_cast<System::Int32>(static_cast<System::Byte>(58)));
            this->txtConfirmar->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9));
            this->txtConfirmar->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
                static_cast<System::Int32>(static_cast<System::Byte>(255)));
            this->txtConfirmar->Location = System::Drawing::Point(12, 254);
            this->txtConfirmar->Name = L"txtConfirmar";
            this->txtConfirmar->PasswordChar = '*';
            this->txtConfirmar->Size = System::Drawing::Size(352, 27);
            this->txtConfirmar->TabIndex = 7;
            // 
            // lblTurno
            // 
            this->lblTurno->AutoSize = true;
            this->lblTurno->Font = (gcnew System::Drawing::Font(L"Segoe UI", 8));
            this->lblTurno->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(148)), static_cast<System::Int32>(static_cast<System::Byte>(163)),
                static_cast<System::Int32>(static_cast<System::Byte>(184)));
            this->lblTurno->Location = System::Drawing::Point(12, 288);
            this->lblTurno->Name = L"lblTurno";
            this->lblTurno->Size = System::Drawing::Size(48, 19);
            this->lblTurno->TabIndex = 8;
            this->lblTurno->Text = L"Turno:";
            // 
            // cmbTurno
            // 
            this->cmbTurno->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(30)), static_cast<System::Int32>(static_cast<System::Byte>(40)),
                static_cast<System::Int32>(static_cast<System::Byte>(58)));
            this->cmbTurno->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
            this->cmbTurno->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9));
            this->cmbTurno->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
                static_cast<System::Int32>(static_cast<System::Byte>(255)));
            this->cmbTurno->Items->AddRange(gcnew cli::array< System::Object^  >(3) { L"Mañana", L"Tarde", L"Noche" });
            this->cmbTurno->Location = System::Drawing::Point(12, 306);
            this->cmbTurno->Name = L"cmbTurno";
            this->cmbTurno->Size = System::Drawing::Size(352, 28);
            this->cmbTurno->TabIndex = 9;
            // 
            // btnCrear
            // 
            this->btnCrear->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(37)), static_cast<System::Int32>(static_cast<System::Byte>(99)),
                static_cast<System::Int32>(static_cast<System::Byte>(235)));
            this->btnCrear->FlatAppearance->BorderSize = 0;
            this->btnCrear->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
            this->btnCrear->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Bold));
            this->btnCrear->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
                static_cast<System::Int32>(static_cast<System::Byte>(255)));
            this->btnCrear->Location = System::Drawing::Point(12, 342);
            this->btnCrear->Name = L"btnCrear";
            this->btnCrear->Size = System::Drawing::Size(352, 36);
            this->btnCrear->TabIndex = 10;
            this->btnCrear->Text = L"Crear administrador";
            this->btnCrear->UseVisualStyleBackColor = false;
            this->btnCrear->Click += gcnew System::EventHandler(this, &FormPrimerArranque::btnCrear_Click);
            // 
            // FormPrimerArranque
            // 
            this->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(22)), static_cast<System::Int32>(static_cast<System::Byte>(30)),
                static_cast<System::Int32>(static_cast<System::Byte>(46)));
            this->ClientSize = System::Drawing::Size(368, 390);
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
            this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
            this->MaximizeBox = false;
            this->Name = L"FormPrimerArranque";
            this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
            this->Text = L"GemeloDigital - Configuración inicial";
            this->panelTitulo->ResumeLayout(false);
            this->panelTitulo->PerformLayout();
            this->panelAviso->ResumeLayout(false);
            this->panelAviso->PerformLayout();
            this->ResumeLayout(false);
            this->PerformLayout();

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
                // Generamos un ID simple para el primer admin o puedes pedirlo en UI
                ctrl->agregar("1", nombre, pass, 1, turno);
                MessageBox::Show(
                    L"Administrador creado correctamente.\nYa puede iniciar sesión.",
                    L"Éxito", MessageBoxButtons::OK, MessageBoxIcon::Information);
                this->DialogResult = System::Windows::Forms::DialogResult::OK;
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