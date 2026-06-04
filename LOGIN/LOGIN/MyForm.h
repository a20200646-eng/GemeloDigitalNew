#pragma once

#include "Interfaz.h"
#include "FormPrimerArranque.h"   // <-- agregamos esta línea
using namespace LOGIN;


namespace LOGIN {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;


	/// <summary>
	/// Resumen de MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: agregar código de constructor aquí
			//
		}
	protected:
		virtual property System::Windows::Forms::CreateParams^ CreateParams {
			System::Windows::Forms::CreateParams^ get() override {
				System::Windows::Forms::CreateParams^ cp = __super::CreateParams;
				// CS_DROPSHADOW = 0x00020000;
				cp->ClassStyle |= 0x20000;
				return cp;
			}
		}
	private:
		// Variables para rastrear el estado del movimiento
		bool moviendo = false;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label6;

	private:
		// Variable global para rastrear y controlar el formulario que está en pantalla
		Form^ formActivo = nullptr;

		void AbrirFormHijo(Form^ formHijo) {
			// 1. Si ya hay un formulario abierto en el panel, lo cerramos para liberar memoria
			if (this->formActivo != nullptr) {
				this->formActivo->Close();
			}

			// 2. Guardamos el nuevo formulario como el activo
			this->formActivo = formHijo;

			// 3. Configuración para transformar la ventana en un control interno
			formHijo->TopLevel = false; // Frena que se abra como una ventana flotante externa
			formHijo->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None; // Quita la barra de título, bordes y botones de cerrar
			formHijo->Dock = DockStyle::Fill; // Fuerza al formulario hijo a estirarse al tamaño exacto del panel contenedor

			// 4. Agregamos el formulario al panel contenedor y lo mostramos

		}

		   Point posicionInicial;

	private: System::Void pictureBoxBarra_MouseDown(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
		// Se activa cuando el usuario presiona el click sobre la barra
		if (e->Button == System::Windows::Forms::MouseButtons::Left) {
			moviendo = true;
			posicionInicial = Point(e->X, e->Y);
		}
	}

	private: System::Void pictureBoxBarra_MouseMove(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
		// Si el mouse se mueve y el click está presionado, se desplaza la ventana
		if (moviendo) {
			Point posicionActual = this->PointToScreen(e->Location);
			this->Location = Point(posicionActual.X - posicionInicial.X, posicionActual.Y - posicionInicial.Y);
		}
	}

	private: System::Void pictureBoxBarra_MouseUp(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
		// Detiene el movimiento al soltar el click
		moviendo = false;
	}
	private: System::Void ManejarEnter(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e) {
		// Si la tecla presionada es Enter
		if (e->KeyCode == Keys::Enter) {
			// Evita el sonido de error de Windows
			e->SuppressKeyPress = true;

			// Simula el clic del botón de ingresar
			this->btnIngresar->PerformClick();
		}
	}
	

	protected:
		/// <summary>
		/// Limpiar los recursos que se estén usando.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}


	private: System::Windows::Forms::Button^ btnIngresar;



	private: System::Windows::Forms::Panel^ panel1;
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::Label^ label2;



	private: System::Windows::Forms::Label^ label5;


	private: System::Windows::Forms::PictureBox^ pictureBox1;
	private: System::Windows::Forms::PictureBox^ pictureBox2;
	private: System::Windows::Forms::TextBox^ txtUsuario;
	private: System::Windows::Forms::TextBox^ txtPassword;
	private: System::Windows::Forms::PictureBox^ pictureBox3;
	private: System::Windows::Forms::PictureBox^ pictureBox4;


	protected:

	protected:

	private:
		/// <summary>
		/// Variable del diseñador necesaria.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Método necesario para admitir el Diseñador. No se puede modificar
		/// el contenido de este método con el editor de código.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(MyForm::typeid));
			this->btnIngresar = (gcnew System::Windows::Forms::Button());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->pictureBox4 = (gcnew System::Windows::Forms::PictureBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->pictureBox2 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->txtUsuario = (gcnew System::Windows::Forms::TextBox());
			this->txtPassword = (gcnew System::Windows::Forms::TextBox());
			this->pictureBox3 = (gcnew System::Windows::Forms::PictureBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->panel1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox4))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox3))->BeginInit();
			this->SuspendLayout();
			// 
			// btnIngresar
			// 
			this->btnIngresar->BackColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->btnIngresar->FlatAppearance->BorderColor = System::Drawing::Color::AliceBlue;
			this->btnIngresar->FlatAppearance->MouseDownBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(192)),
				static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->btnIngresar->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnIngresar->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnIngresar->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
			this->btnIngresar->Location = System::Drawing::Point(98, 262);
			this->btnIngresar->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
			this->btnIngresar->Name = L"btnIngresar";
			this->btnIngresar->Size = System::Drawing::Size(97, 29);
			this->btnIngresar->TabIndex = 2;
			this->btnIngresar->Text = L"INGRESAR";
			this->btnIngresar->UseVisualStyleBackColor = false;
			this->btnIngresar->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// panel1
			// 
			this->panel1->BackColor = System::Drawing::Color::Black;
			this->panel1->Controls->Add(this->pictureBox4);
			this->panel1->Controls->Add(this->label2);
			this->panel1->Controls->Add(this->button1);
			this->panel1->Dock = System::Windows::Forms::DockStyle::Top;
			this->panel1->Location = System::Drawing::Point(0, 0);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(596, 37);
			this->panel1->TabIndex = 6;
			this->panel1->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &MyForm::panel1_Paint);
			this->panel1->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::pictureBoxBarra_MouseDown);
			this->panel1->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::pictureBoxBarra_MouseMove);
			this->panel1->MouseUp += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::pictureBoxBarra_MouseUp);
			// 
			// pictureBox4
			// 
			this->pictureBox4->Location = System::Drawing::Point(353, 36);
			this->pictureBox4->Name = L"pictureBox4";
			this->pictureBox4->Size = System::Drawing::Size(100, 50);
			this->pictureBox4->TabIndex = 8;
			this->pictureBox4->TabStop = false;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->BackColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->label2->ForeColor = System::Drawing::SystemColors::ButtonFace;
			this->label2->Location = System::Drawing::Point(3, 11);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(91, 20);
			this->label2->TabIndex = 7;
			this->label2->Text = L"POOderosos";
			// 
			// button1
			// 
			this->button1->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"button1.BackgroundImage")));
			this->button1->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Center;
			this->button1->FlatAppearance->BorderSize = 0;
			this->button1->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button1->Location = System::Drawing::Point(568, 5);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(25, 26);
			this->button1->TabIndex = 7;
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click_1);
			// 
			// pictureBox2
			// 
			this->pictureBox2->BackColor = System::Drawing::Color::Transparent;
			this->pictureBox2->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox2.Image")));
			this->pictureBox2->Location = System::Drawing::Point(44, 202);
			this->pictureBox2->Name = L"pictureBox2";
			this->pictureBox2->Size = System::Drawing::Size(25, 27);
			this->pictureBox2->SizeMode = System::Windows::Forms::PictureBoxSizeMode::CenterImage;
			this->pictureBox2->TabIndex = 9;
			this->pictureBox2->TabStop = false;
			// 
			// pictureBox1
			// 
			this->pictureBox1->BackColor = System::Drawing::Color::Transparent;
			this->pictureBox1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox1.Image")));
			this->pictureBox1->Location = System::Drawing::Point(44, 139);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(25, 26);
			this->pictureBox1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::CenterImage;
			this->pictureBox1->TabIndex = 8;
			this->pictureBox1->TabStop = false;
			this->pictureBox1->Click += gcnew System::EventHandler(this, &MyForm::pictureBox1_Click);
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->BackColor = System::Drawing::Color::Transparent;
			this->label5->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label5->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
			this->label5->Location = System::Drawing::Point(115, 68);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(65, 25);
			this->label5->TabIndex = 5;
			this->label5->Text = L"Login";
			this->label5->Click += gcnew System::EventHandler(this, &MyForm::label1_Click);
			// 
			// txtUsuario
			// 
			this->txtUsuario->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->txtUsuario->Location = System::Drawing::Point(78, 138);
			this->txtUsuario->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
			this->txtUsuario->Name = L"txtUsuario";
			this->txtUsuario->Size = System::Drawing::Size(153, 27);
			this->txtUsuario->TabIndex = 0;
			this->txtUsuario->TextChanged += gcnew System::EventHandler(this, &MyForm::textBox1_TextChanged);
			this->txtUsuario->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &MyForm::ManejarEnter);
			// 
			// txtPassword
			// 
			this->txtPassword->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->txtPassword->Location = System::Drawing::Point(78, 202);
			this->txtPassword->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
			this->txtPassword->Name = L"txtPassword";
			this->txtPassword->PasswordChar = '*';
			this->txtPassword->Size = System::Drawing::Size(153, 27);
			this->txtPassword->TabIndex = 1;
			this->txtPassword->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &MyForm::ManejarEnter);
			// 
			// pictureBox3
			// 
			this->pictureBox3->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(2)), static_cast<System::Int32>(static_cast<System::Byte>(54)),
				static_cast<System::Int32>(static_cast<System::Byte>(105)));
			this->pictureBox3->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->pictureBox3->Dock = System::Windows::Forms::DockStyle::Fill;
			this->pictureBox3->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox3.Image")));
			this->pictureBox3->Location = System::Drawing::Point(0, 37);
			this->pictureBox3->Name = L"pictureBox3";
			this->pictureBox3->Size = System::Drawing::Size(596, 314);
			this->pictureBox3->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pictureBox3->TabIndex = 8;
			this->pictureBox3->TabStop = false;
			this->pictureBox3->Click += gcnew System::EventHandler(this, &MyForm::pictureBox3_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->BackColor = System::Drawing::Color::Transparent;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
			this->label1->Location = System::Drawing::Point(75, 116);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(84, 18);
			this->label1->TabIndex = 9;
			this->label1->Text = L"User Name";
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->BackColor = System::Drawing::Color::Transparent;
			this->label6->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label6->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
			this->label6->Location = System::Drawing::Point(75, 180);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(75, 18);
			this->label6->TabIndex = 10;
			this->label6->Text = L"Password";
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 20);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
			this->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->ClientSize = System::Drawing::Size(596, 351);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->pictureBox2);
			this->Controls->Add(this->btnIngresar);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->pictureBox1);
			this->Controls->Add(this->txtPassword);
			this->Controls->Add(this->txtUsuario);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->pictureBox3);
			this->Controls->Add(this->panel1);
			this->DoubleBuffered = true;
			this->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
			this->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			this->panel1->ResumeLayout(false);
			this->panel1->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox4))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox3))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void MyForm_Load(System::Object^ sender, System::EventArgs^ e) {
		GemeloDigitalController::AdministradorController^ ctrl =
			gcnew GemeloDigitalController::AdministradorController();

		if (ctrl->obtenerTodos()->Count == 0) {
			this->Hide();
			FormPrimerArranque^ fpa = gcnew FormPrimerArranque();
			fpa->ShowDialog();
			this->Show();
		}
	}
	private: System::Void textBox1_TextChanged(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
		String^ user = txtUsuario->Text->Trim();
		String^ pass = txtPassword->Text->Trim();

		if (user == "" || pass == "") {
			MessageBox::Show("Por favor, ingrese usuario y contraseña.", "Campos Vacíos", MessageBoxButtons::OK, MessageBoxIcon::Warning);
			return;
		}

		try {
			// 1. Instanciamos el controlador que lee el archivo de datos .dat de tus compañeros
			GemeloDigitalController::AdministradorController^ contrUsuario = gcnew GemeloDigitalController::AdministradorController();

			// 2. Obtenemos todos los usuarios de la persistencia
			System::Collections::Generic::List<GemeloDigitalModel::AdministradorModel^>^ listaUsuarios = contrUsuario->obtenerTodos();

			
			GemeloDigitalModel::AdministradorModel^ usuarioEncontrado = nullptr;

			// 3. Buscamos si las credenciales coinciden con algún registro
			for each (GemeloDigitalModel::AdministradorModel ^ u in listaUsuarios) {
				if (u->Nombre->Trim()->Equals(user, StringComparison::OrdinalIgnoreCase) && u->Contrasena == pass) {
					usuarioEncontrado = u;
					break;
				}
			}

			// === EVALUACIÓN DE ROLES DINÁMICOS ===
			if (usuarioEncontrado != nullptr) {
				Interfaz^ Principal = gcnew Interfaz(this);
				int nivel = usuarioEncontrado->NivelAcceso;

				// ROL 1: Administrador (Nivel 1)
				if (nivel == 1) {
					Principal->label1->Text = "Administrador";
					Principal->button1->Text = "Dashboard";
					Principal->button2->Text = "Usuarios";
					Principal->button3->Text = "Eventos";
					Principal->button4->Text = "Reportes";
					Principal->button6->Text = "Salir";
					Principal->button5->Visible = false;
				}
				// ROL 2: Jefe de Operaciones (Nivel 2)
				else if (nivel == 2) {
					Principal->label1->Text = "Jefe de Operaciones";
					Principal->button1->Text = "Dashboard";
					Principal->button2->Text = "Estación / Ciclo";
					Principal->button3->Text = "Línea Ensamblaje";
					Principal->button4->Text = "Eventos";
					Principal->button5->Text = "Reportes";
					Principal->button6->Text = "Cerrar sesión";
				}
				// ROL 3: Operador (Nivel 3)
				else if (nivel == 3) {
					Principal->label1->Text = "Operador";
					Principal->button1->Text = "Dashboard";
					Principal->button2->Text = "Tareas";
					Principal->button3->Text = "Brazos";
					Principal->button4->Text = "Eventos";
					Principal->button6->Text = "Salir";
					Principal->button5->Visible = false;
				}
				// 🌟 NUEVO ROL 4: Gestor (Nivel 4)
				else if (nivel == 4) {
					Principal->label1->Text = "Gestor de Planta";
					Principal->button1->Text = "Dashboard";
					Principal->button2->Text = "Eventos";        // El gestor ve eventos directamente
					Principal->button3->Text = "Reportes";       // Ve reportes
					Principal->button6->Text = "Salir";
					Principal->button4->Visible = false;         // Ocultamos botones sobrantes
					Principal->button5->Visible = false;
				}

				// Mostrar la pantalla principal y ocultar el login
				Principal->Show();

				// Limpiar campos de texto para el próximo login
				txtUsuario->Text = "";
				txtPassword->Text = "";
				this->Hide();
			}
			else {
				MessageBox::Show("Usuario o contraseña incorrectos.", "Error de Autenticación", MessageBoxButtons::OK, MessageBoxIcon::Error);
			}
		}
		catch (Exception^ ex) {
			MessageBox::Show("Error al conectar con la base de datos de usuarios: " + ex->Message, "Error Crítico");
		}
	}
	private: System::Void label1_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void panel1_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
	}
	private: System::Void label3_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void pictureBox1_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void pictureBox3_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void button1_Click_1(System::Object^ sender, System::EventArgs^ e) {
		this->Close();
	}
	private: System::Void label1_Click_1(System::Object^ sender, System::EventArgs^ e) {
	}
};
}