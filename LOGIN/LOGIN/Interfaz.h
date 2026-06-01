#pragma once

//Include de los formularios del jefe 
#include "FormMenuJefe.h" //Corresponde al Dashboard del jefe de operaciones
#include "Estacion_ciclo.h" //Corresponde a la sección de estación/ciclo del jefe de operaciones
#include "Linea_de_Ensamblaje.h" //Corresponde a la sección de línea de ensamblaje del jefe de operaciones
#include "Eventos_JefeOperaciones.h" //Corresponde a la sección de eventos del jefe de operaciones
#include "Reportes_de_Costos.h" //Corresponde a la sección de reportes del jefe de operaciones


//inlcude del Administrador
#include "Dashboard_admin.h" //Corresponde al Dashboard del administrador
#include "FormMenuAdmin.h" //Corresponde a la sección de usuarios del administrador
#include "Historial_de_Eventos.h" //Corresponde a la sección de eventos del administrador
#include "Reportes_de_Costos_Admin.h" //Corresponde a la sección de reportes del administrador

//include del operador
#include "Dashboard_Operador.h" //Corresponde al Dashboard del operador
#include "FormMenuOperador.h" //Corresponde a las tareas del operador
#include "Brazos_Operador.h" //Corresponde a la sección de brazos del operador
#include "EventosOperador.h" //Corresponde a la sección de eventos del operador

//include del controlador de piezas
#include "Dashboard_Inventario.h" //Corresponde al Dashboard del controlador de piezas
#include "FormMenuControlador.h" //Corresponde a la sección de inventario del controlador de piezas
#include "Estaciones_de_Trabajo_Inventario.h" //Corresponde a la sección de estaciones de trabajo del controlador de piezas
#include "Linea_de_Ensamblaje1.h" //corresponde a la sección de línea de ensamblaje del controlador de piezas



namespace LOGIN {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Resumen de Interfaz
	/// </summary>
	public ref class Interfaz : public System::Windows::Forms::Form
	{
	public:
		Interfaz(void)
		{
			InitializeComponent();
			//
			//TODO: agregar código de constructor aquí
			//
		}

	protected:
		/// <summary>
		/// Limpiar los recursos que se estén usando.
		/// </summary>
		~Interfaz()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Panel^ panel1;
	protected:
	private: System::Windows::Forms::Panel^ panel11;
	public: System::Windows::Forms::PictureBox^ pictureBox1;
	private:
	public: System::Windows::Forms::Label^ label4;
	public: System::Windows::Forms::Label^ label1;
	public: System::Windows::Forms::Button^ button6;

	private: System::Windows::Forms::Panel^ panel10;
	public: System::Windows::Forms::Button^ button1;
	public: System::Windows::Forms::Button^ button2;
	public: System::Windows::Forms::Button^ button3;
	public: System::Windows::Forms::Button^ button4;
	public: System::Windows::Forms::Button^ button5;
	private: System::Windows::Forms::Panel^ panel2;



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
			this->panel2->Controls->Add(formHijo);
			this->panel2->Tag = formHijo;
			formHijo->BringToFront(); // Lo trae al frente para que no lo tape ningún otro control
			formHijo->Show(); // Lo renderiza en pantalla
		}


	

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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(Interfaz::typeid));
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->panel11 = (gcnew System::Windows::Forms::Panel());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->button6 = (gcnew System::Windows::Forms::Button());
			this->panel10 = (gcnew System::Windows::Forms::Panel());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->button5 = (gcnew System::Windows::Forms::Button());
			this->panel2 = (gcnew System::Windows::Forms::Panel());
			this->panel1->SuspendLayout();
			this->panel11->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			this->panel10->SuspendLayout();
			this->SuspendLayout();
			// 
			// panel1
			// 
			this->panel1->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(15)), static_cast<System::Int32>(static_cast<System::Byte>(23)),
				static_cast<System::Int32>(static_cast<System::Byte>(42)));
			this->panel1->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->panel1->Controls->Add(this->panel11);
			this->panel1->Controls->Add(this->button6);
			this->panel1->Controls->Add(this->panel10);
			this->panel1->Dock = System::Windows::Forms::DockStyle::Left;
			this->panel1->Location = System::Drawing::Point(0, 0);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(303, 740);
			this->panel1->TabIndex = 7;
			// 
			// panel11
			// 
			this->panel11->Controls->Add(this->pictureBox1);
			this->panel11->Controls->Add(this->label4);
			this->panel11->Controls->Add(this->label1);
			this->panel11->Location = System::Drawing::Point(1, 2);
			this->panel11->Margin = System::Windows::Forms::Padding(2);
			this->panel11->Name = L"panel11";
			this->panel11->Size = System::Drawing::Size(302, 94);
			this->panel11->TabIndex = 16;
			// 
			// pictureBox1
			// 
			this->pictureBox1->BackColor = System::Drawing::Color::Transparent;
			this->pictureBox1->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox1.BackgroundImage")));
			this->pictureBox1->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->pictureBox1->Location = System::Drawing::Point(25, 18);
			this->pictureBox1->Margin = System::Windows::Forms::Padding(2);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(52, 55);
			this->pictureBox1->TabIndex = 10;
			this->pictureBox1->TabStop = false;
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Font = (gcnew System::Drawing::Font(L"MS Reference Sans Serif", 7.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label4->ForeColor = System::Drawing::SystemColors::ButtonFace;
			this->label4->Location = System::Drawing::Point(81, 28);
			this->label4->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(127, 16);
			this->label4->TabIndex = 8;
			this->label4->Text = L"Usuario Sistema";
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"MS Reference Sans Serif", 7.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->ForeColor = System::Drawing::Color::Cyan;
			this->label1->Location = System::Drawing::Point(81, 49);
			this->label1->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(160, 16);
			this->label1->TabIndex = 9;
			this->label1->Text = L"Jefe de Operaciones";
			// 
			// button6
			// 
			this->button6->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(30)), static_cast<System::Int32>(static_cast<System::Byte>(40)),
				static_cast<System::Int32>(static_cast<System::Byte>(58)));
			this->button6->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Center;
			this->button6->FlatAppearance->BorderSize = 0;
			this->button6->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button6->Font = (gcnew System::Drawing::Font(L"MS Reference Sans Serif", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button6->ForeColor = System::Drawing::Color::Transparent;
			this->button6->Location = System::Drawing::Point(68, 650);
			this->button6->Margin = System::Windows::Forms::Padding(2);
			this->button6->Name = L"button6";
			this->button6->Size = System::Drawing::Size(174, 30);
			this->button6->TabIndex = 11;
			this->button6->Text = L"Cerrar Sesión";
			this->button6->UseVisualStyleBackColor = false;
			this->button6->Click += gcnew System::EventHandler(this, &Interfaz::button6_Click);
			// 
			// panel10
			// 
			this->panel10->Controls->Add(this->button1);
			this->panel10->Controls->Add(this->button2);
			this->panel10->Controls->Add(this->button3);
			this->panel10->Controls->Add(this->button4);
			this->panel10->Controls->Add(this->button5);
			this->panel10->ForeColor = System::Drawing::Color::White;
			this->panel10->Location = System::Drawing::Point(1, 99);
			this->panel10->Margin = System::Windows::Forms::Padding(2);
			this->panel10->Name = L"panel10";
			this->panel10->Size = System::Drawing::Size(300, 241);
			this->panel10->TabIndex = 15;
			// 
			// button1
			// 
			this->button1->FlatAppearance->BorderColor = System::Drawing::Color::Black;
			this->button1->FlatAppearance->MouseDownBackColor = System::Drawing::Color::DarkSlateGray;
			this->button1->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button1->Font = (gcnew System::Drawing::Font(L"MS Reference Sans Serif", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button1->ForeColor = System::Drawing::Color::Transparent;
			this->button1->ImageAlign = System::Drawing::ContentAlignment::TopLeft;
			this->button1->Location = System::Drawing::Point(0, 0);
			this->button1->Margin = System::Windows::Forms::Padding(2);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(302, 37);
			this->button1->TabIndex = 7;
			this->button1->Text = L"Dashboard";
			this->button1->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &Interfaz::button1_Click);
			// 
			// button2
			// 
			this->button2->FlatAppearance->BorderColor = System::Drawing::Color::Black;
			this->button2->FlatAppearance->MouseDownBackColor = System::Drawing::Color::DarkSlateGray;
			this->button2->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button2->Font = (gcnew System::Drawing::Font(L"MS Reference Sans Serif", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button2->ForeColor = System::Drawing::Color::Transparent;
			this->button2->Location = System::Drawing::Point(0, 37);
			this->button2->Margin = System::Windows::Forms::Padding(2);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(302, 40);
			this->button2->TabIndex = 4;
			this->button2->Text = L"Estación/Ciclo";
			this->button2->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &Interfaz::button2_Click);
			// 
			// button3
			// 
			this->button3->FlatAppearance->BorderColor = System::Drawing::Color::Black;
			this->button3->FlatAppearance->MouseDownBackColor = System::Drawing::Color::DarkSlateGray;
			this->button3->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button3->Font = (gcnew System::Drawing::Font(L"MS Reference Sans Serif", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button3->ForeColor = System::Drawing::Color::Transparent;
			this->button3->Location = System::Drawing::Point(0, 77);
			this->button3->Margin = System::Windows::Forms::Padding(2);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(302, 40);
			this->button3->TabIndex = 3;
			this->button3->Text = L"Línea de ensamblaje";
			this->button3->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &Interfaz::button3_Click);
			// 
			// button4
			// 
			this->button4->FlatAppearance->BorderColor = System::Drawing::Color::Black;
			this->button4->FlatAppearance->MouseDownBackColor = System::Drawing::Color::DarkSlateGray;
			this->button4->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button4->Font = (gcnew System::Drawing::Font(L"MS Reference Sans Serif", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button4->ForeColor = System::Drawing::Color::Transparent;
			this->button4->Location = System::Drawing::Point(0, 117);
			this->button4->Margin = System::Windows::Forms::Padding(2);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(302, 38);
			this->button4->TabIndex = 1;
			this->button4->Text = L"Eventos";
			this->button4->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->button4->UseVisualStyleBackColor = true;
			this->button4->Click += gcnew System::EventHandler(this, &Interfaz::button4_Click);
			// 
			// button5
			// 
			this->button5->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Center;
			this->button5->FlatAppearance->BorderColor = System::Drawing::Color::Black;
			this->button5->FlatAppearance->MouseDownBackColor = System::Drawing::Color::DarkSlateGray;
			this->button5->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button5->Font = (gcnew System::Drawing::Font(L"MS Reference Sans Serif", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button5->ForeColor = System::Drawing::Color::Transparent;
			this->button5->Location = System::Drawing::Point(0, 155);
			this->button5->Margin = System::Windows::Forms::Padding(2);
			this->button5->Name = L"button5";
			this->button5->Size = System::Drawing::Size(302, 38);
			this->button5->TabIndex = 2;
			this->button5->Text = L"Reportes";
			this->button5->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->button5->UseVisualStyleBackColor = true;
			this->button5->Click += gcnew System::EventHandler(this, &Interfaz::button5_Click);
			// 
			// panel2
			// 
			this->panel2->Dock = System::Windows::Forms::DockStyle::Fill;
			this->panel2->Location = System::Drawing::Point(303, 0);
			this->panel2->Name = L"panel2";
			this->panel2->Size = System::Drawing::Size(924, 740);
			this->panel2->TabIndex = 8;
			// 
			// Interfaz
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1227, 740);
			this->Controls->Add(this->panel2);
			this->Controls->Add(this->panel1);
			this->Name = L"Interfaz";
			this->Text = L"Interfaz";
			this->Load += gcnew System::EventHandler(this, &Interfaz::Interfaz_Load);
			this->panel1->ResumeLayout(false);
			this->panel11->ResumeLayout(false);
			this->panel11->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			this->panel10->ResumeLayout(false);
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void Interfaz_Load(System::Object^ sender, System::EventArgs^ e) {
	}


private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {

	if (label1->Text == "Jefe de Operaciones") {
		AbrirFormHijo(gcnew Estacion_ciclo());

	}
	else if (label1->Text == "Operador") {
		AbrirFormHijo(gcnew FormMenuOperador());

	}
	else if (label1->Text == "Controlador de piezas") {
		AbrirFormHijo(gcnew FormMenuControlador());

	}
	else if (label1->Text == "Administrador") {
		AbrirFormHijo(gcnew FormMenuAdmin());

	}
}
private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
	if (label1->Text == "Jefe de Operaciones") {
		AbrirFormHijo(gcnew FormMenuJefe());
	} else if (label1->Text == "Operador") {
		AbrirFormHijo(gcnew Dashboard_Operador());
	}
	else if (label1->Text == "Controlador de piezas") {
		AbrirFormHijo(gcnew Dashboard_Inventario());
	}
	else if (label1->Text == "Administrador") {
		AbrirFormHijo(gcnew Dashboard_admin());
	}
	
}
private: System::Void button4_Click(System::Object^ sender, System::EventArgs^ e) {

	if (label1->Text == "Jefe de Operaciones") {
		AbrirFormHijo(gcnew Eventos_JefeOperaciones());
	}
	else if (label1->Text == "Operador") {
		AbrirFormHijo(gcnew EventosOperador());
	}
	else if (label1->Text == "Controlador de piezas") {
		AbrirFormHijo(gcnew Linea_de_Ensamblaje1());
	}
	else if (label1->Text == "Administrador") {
		AbrirFormHijo(gcnew Reportes_de_Costos_Admin());
	}

}
private: System::Void button6_Click(System::Object^ sender, System::EventArgs^ e) {
	this->Close();

}
private: System::Void button3_Click(System::Object^ sender, System::EventArgs^ e) {
	if (label1->Text == "Jefe de Operaciones") {
		AbrirFormHijo(gcnew Linea_de_Ensamblaje());
	}
	else if (label1->Text == "Operador") {
		AbrirFormHijo(gcnew Brazos_Operador());
	}
	else if (label1->Text == "Controlador de piezas") {
		AbrirFormHijo(gcnew Estaciones_de_Trabajo_Inventario());
	}
	else if (label1->Text == "Administrador") {
		AbrirFormHijo(gcnew Historial_de_Eventos());
	}

}
private: System::Void button5_Click(System::Object^ sender, System::EventArgs^ e) {
	if (label1->Text == "Jefe de Operaciones") {
		AbrirFormHijo(gcnew Reportes_de_Costos());
	}
}
};
}
