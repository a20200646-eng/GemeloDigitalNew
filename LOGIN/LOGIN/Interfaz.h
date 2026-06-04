#pragma once

#include <dwmapi.h>
#pragma comment(lib,"dwmapi.lib")

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


using namespace GemeloDigitalController; //Para acceder a los controladores desde los formularios hijos
using namespace GemeloDigitalModel; //Para acceder a los modelos desde los formularios hijos
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

	private:
		Form^ Login; //Guardar al form login
	public:
		Interfaz(Form^ PadreLogin)
		{
			InitializeComponent();
			Login = PadreLogin;
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
			this->panel1->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(228, 700);
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
			this->panel11->Size = System::Drawing::Size(226, 76);
			this->panel11->TabIndex = 16;
			// 
			// pictureBox1
			// 
			this->pictureBox1->BackColor = System::Drawing::Color::Transparent;
			this->pictureBox1->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox1.BackgroundImage")));
			this->pictureBox1->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->pictureBox1->Location = System::Drawing::Point(19, 15);
			this->pictureBox1->Margin = System::Windows::Forms::Padding(2);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(39, 45);
			this->pictureBox1->TabIndex = 10;
			this->pictureBox1->TabStop = false;
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 7.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label4->ForeColor = System::Drawing::SystemColors::ButtonFace;
			this->label4->Location = System::Drawing::Point(61, 23);
			this->label4->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(98, 13);
			this->label4->TabIndex = 8;
			this->label4->Text = L"Usuario Sistema";
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 7.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->ForeColor = System::Drawing::Color::Cyan;
			this->label1->Location = System::Drawing::Point(61, 40);
			this->label1->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(124, 13);
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
			this->button6->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button6->ForeColor = System::Drawing::Color::Transparent;
			this->button6->Location = System::Drawing::Point(51, 528);
			this->button6->Margin = System::Windows::Forms::Padding(2);
			this->button6->Name = L"button6";
			this->button6->Size = System::Drawing::Size(130, 24);
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
			this->panel10->Location = System::Drawing::Point(1, 80);
			this->panel10->Margin = System::Windows::Forms::Padding(2);
			this->panel10->Name = L"panel10";
			this->panel10->Size = System::Drawing::Size(225, 196);
			this->panel10->TabIndex = 15;
			// 
			// button1
			// 
			this->button1->FlatAppearance->BorderColor = System::Drawing::Color::Black;
			this->button1->FlatAppearance->MouseDownBackColor = System::Drawing::Color::DarkSlateGray;
			this->button1->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button1->ForeColor = System::Drawing::Color::Transparent;
			this->button1->ImageAlign = System::Drawing::ContentAlignment::TopLeft;
			this->button1->Location = System::Drawing::Point(0, 0);
			this->button1->Margin = System::Windows::Forms::Padding(2);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(226, 30);
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
			this->button2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button2->ForeColor = System::Drawing::Color::Transparent;
			this->button2->Location = System::Drawing::Point(0, 30);
			this->button2->Margin = System::Windows::Forms::Padding(2);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(226, 32);
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
			this->button3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button3->ForeColor = System::Drawing::Color::Transparent;
			this->button3->Location = System::Drawing::Point(0, 63);
			this->button3->Margin = System::Windows::Forms::Padding(2);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(226, 32);
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
			this->button4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button4->ForeColor = System::Drawing::Color::Transparent;
			this->button4->Location = System::Drawing::Point(0, 95);
			this->button4->Margin = System::Windows::Forms::Padding(2);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(226, 31);
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
			this->button5->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button5->ForeColor = System::Drawing::Color::Transparent;
			this->button5->Location = System::Drawing::Point(0, 126);
			this->button5->Margin = System::Windows::Forms::Padding(2);
			this->button5->Name = L"button5";
			this->button5->Size = System::Drawing::Size(226, 31);
			this->button5->TabIndex = 2;
			this->button5->Text = L"Reportes";
			this->button5->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->button5->UseVisualStyleBackColor = true;
			this->button5->Click += gcnew System::EventHandler(this, &Interfaz::button5_Click);
			// 
			// panel2
			// 
			this->panel2->BackColor = System::Drawing::Color::Transparent;
			this->panel2->Dock = System::Windows::Forms::DockStyle::Fill;
			this->panel2->Location = System::Drawing::Point(228, 0);
			this->panel2->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->panel2->Name = L"panel2";
			this->panel2->Size = System::Drawing::Size(860, 700);
			this->panel2->TabIndex = 8;
			this->panel2->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &Interfaz::panel2_Paint);
			// 
			// Interfaz
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1088, 700);
			this->Controls->Add(this->panel2);
			this->Controls->Add(this->panel1);
			this->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->Name = L"Interfaz";
			this->ShowIcon = false;
			this->FormClosing += gcnew System::Windows::Forms::FormClosingEventHandler(this, &Interfaz::Interfaz_FormClosing);
			this->Load += gcnew System::EventHandler(this, &Interfaz::Interfaz_Load);
			this->panel1->ResumeLayout(false);
			this->panel11->ResumeLayout(false);
			this->panel11->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			this->panel10->ResumeLayout(false);
			this->ResumeLayout(false);

		}
#pragma endregion

		void SembrarDatosPrueba()
		{
			// ============================================================
			// CICLO REALISTA — ESTACION BODY FRAMING
			// Secuencia: se ensamblan 2 paneles laterales + 1 estructura
			// de techo sobre un chasis. 3 brazos roboticos en operacion.
			// Ciclo 1 COMPLETADO, Ciclo 2 EN CURSO.
			// ============================================================

			// --- 1. BRAZOS ROBOTICOS ---
			BrazoRoboticoController^ ctrlBrazo = gcnew BrazoRoboticoController();
			if (ctrlBrazo->obtenerTodos()->Count == 0)
			{
				// Brazo 1: Lateral Izquierdo — posiciona panel izquierdo
				ctrlBrazo->agregar("IDB1", RolBrazo::LATERAL_IZQ);
				ctrlBrazo->agregarArticulacion("IDB1", "A1IDB1", "Hombro", 35.0, -90.0, 90.0);
				ctrlBrazo->agregarArticulacion("IDB1", "A2IDB1", "Codo", 20.0, -60.0, 60.0);
				ctrlBrazo->agregarArticulacion("IDB1", "A3IDB1", "Muneca", 10.0, -45.0, 45.0);
				ctrlBrazo->asignarGripper("IDB1", "G1IDB1", "GripperIzq", 0.80, 9.0, true);
				ctrlBrazo->agregarSensorPosicion("IDB1", "SP1IDB1", "SPos-1", 35.0, 0.5);
				ctrlBrazo->agregarSensorFuerza("IDB1", "SF1IDB1", "SFza-1", 9.0, 0.0, 25.0);
				ctrlBrazo->modificar("IDB1", EstadoBrazo::POSICIONANDO);

				// Brazo 2: Lateral Derecho — posiciona panel derecho
				ctrlBrazo->agregar("IDB2", RolBrazo::LATERAL_DER);
				ctrlBrazo->agregarArticulacion("IDB2", "A1IDB2", "Hombro", 42.0, -90.0, 90.0);
				ctrlBrazo->agregarArticulacion("IDB2", "A2IDB2", "Codo", 28.0, -60.0, 60.0);
				ctrlBrazo->agregarArticulacion("IDB2", "A3IDB2", "Muneca", 15.0, -45.0, 45.0);
				ctrlBrazo->asignarGripper("IDB2", "G1IDB2", "GripperDer", 0.85, 8.5, true);
				ctrlBrazo->agregarSensorPosicion("IDB2", "SP1IDB2", "SPos-2", 42.0, 0.5);
				ctrlBrazo->agregarSensorFuerza("IDB2", "SF1IDB2", "SFza-2", 8.5, 0.0, 25.0);
				ctrlBrazo->modificar("IDB2", EstadoBrazo::SOLDANDO);

				// Brazo 3: Central Superior — suelda estructura de techo
				ctrlBrazo->agregar("IDB3", RolBrazo::CENTRAL_SUP);
				ctrlBrazo->agregarArticulacion("IDB3", "A1IDB3", "Hombro", 60.0, -90.0, 90.0);
				ctrlBrazo->agregarArticulacion("IDB3", "A2IDB3", "Codo", 45.0, -60.0, 60.0);
				ctrlBrazo->agregarArticulacion("IDB3", "A3IDB3", "Muneca", 22.0, -45.0, 45.0);
				ctrlBrazo->asignarGripper("IDB3", "G1IDB3", "GripperCen", 0.60, 12.0, false);
				ctrlBrazo->agregarSensorPosicion("IDB3", "SP1IDB3", "SPos-3", 60.0, 0.8);
				ctrlBrazo->agregarSensorFuerza("IDB3", "SF1IDB3", "SFza-3", 12.0, 0.0, 30.0);
				ctrlBrazo->modificar("IDB3", EstadoBrazo::REPOSO);
			}

			// --- 2. PIEZAS — Paneles laterales y estructura de techo ---
			PanelLateralController^ ctrlPanel = gcnew PanelLateralController();
			if (ctrlPanel->obtenerTodos()->Count == 0)
			{
				// Panel izquierdo — ciclo 1 ensamblado, ciclo 2 en proceso
				ctrlPanel->agregar("PL-001", "Acero Galvanizado", 18.5, LadoPanel::IZQUIERDO, 6);
				ctrlPanel->modificar("PL-001", "Acero Galvanizado", 18.5, EstadoPieza::ENSAMBLADA, 6);

				ctrlPanel->agregar("PL-002", "Acero Galvanizado", 18.5, LadoPanel::IZQUIERDO, 6);
				ctrlPanel->modificar("PL-002", "Acero Galvanizado", 18.5, EstadoPieza::EN_PROCESO, 6);

				// Panel derecho — ciclo 1 ensamblado, ciclo 2 en proceso
				ctrlPanel->agregar("PL-003", "Acero Galvanizado", 17.2, LadoPanel::DERECHO, 6);
				ctrlPanel->modificar("PL-003", "Acero Galvanizado", 17.2, EstadoPieza::ENSAMBLADA, 6);

				ctrlPanel->agregar("PL-004", "Acero Galvanizado", 17.2, LadoPanel::DERECHO, 6);
				ctrlPanel->modificar("PL-004", "Acero Galvanizado", 17.2, EstadoPieza::EN_PROCESO, 6);
			}

			EstructuraTechoController^ ctrlTecho = gcnew EstructuraTechoController();
			if (ctrlTecho->obtenerTodos()->Count == 0)
			{
				// Techo ciclo 1 — ensamblado
				ctrlTecho->agregar("ET-001", "Aluminio Reforzado", 12.0, 8, 140.0);
				ctrlTecho->modificar("ET-001", "Aluminio Reforzado", 12.0, EstadoPieza::ENSAMBLADA, 8, 140.0);

				// Techo ciclo 2 — disponible, esperando posicionamiento
				ctrlTecho->agregar("ET-002", "Aluminio Reforzado", 12.0, 8, 140.0);
			}

			// --- 3. LINEA DE ENSAMBLAJE ---
			// La linea encola las piezas en orden: PanelIzq → PanelDer → Techo
			LineaEnsamblajeController^ ctrlLinea = gcnew LineaEnsamblajeController();
			if (ctrlLinea->obtenerTodos()->Count == 0)
			{
				ctrlLinea->agregar("1");

				//Buscar piezas ya creadas por su ID
				PanelLateralModel^ pl002 = ctrlPanel->buscarPorId("PL-002");
				PanelLateralModel^ pl004 = ctrlPanel->buscarPorId("PL-004");
				EstructuraTechoModel^ et002 = ctrlTecho->buscarPorId("ET-002");

				// Agregar piezas del ciclo 2 a la cola (ciclo 1 ya fue procesado)
				if(pl002 != nullptr) ctrlLinea->agregarPieza("1", pl002);
				if(pl004 != nullptr) ctrlLinea->agregarPieza("1", pl004);
				if(et002 != nullptr) ctrlLinea->agregarPieza("1", et002);

				// Indice 0 = PanelIzq en proceso actualmente
				ctrlLinea->modificar("1", 0, false);
			}

			// --- 4. TAREAS DEL CICLO ACTIVO ---
			// Brazo 1 (LATERAL_IZQ): Posicionar panel + Sostener mientras se suelda
			// Brazo 2 (LATERAL_DER): Soldar puntos del panel derecho (EN CURSO)
			// Brazo 3 (CENTRAL_SUP): Coordinar posicion final antes de soldar techo

			TareaPosicionarController^ ctrlPos = gcnew TareaPosicionarController();
			if (ctrlPos->obtenerTodos()->Count == 0)
			{
				ctrlPos->agregar("POS1", 35.0, 0.5);
				ctrlPos->modificar("POS1", "COMPLETADA", 35.0, 0.5); // Panel izq ya posicionado
				ctrlPos->agregar("POS2", 42.0, 0.5);
				ctrlPos->modificar("POS2", "EN CURSO", 42.0, 0.5);   // Panel der posicionandose
			}

			TareaSostenerController^ ctrlSos = gcnew TareaSostenerController();
			if (ctrlSos->obtenerTodos()->Count == 0)
			{
				ctrlSos->agregar("SOS1", 9.0, 45);
				ctrlSos->modificar("SOS1", "EN CURSO", 9.0, 45); // Brazo 1 sostiene mientras brazo 2 suelda
				ctrlSos->agregar("SOS2", 8.5, 30);
				ctrlSos->modificar("SOS2", "PENDIENTE", 8.5, 30);
			}

			TareaSoldarController^ ctrlSol = gcnew TareaSoldarController();
			if (ctrlSol->obtenerTodos()->Count == 0)
			{
				// Ciclo 1 completado — 6/6 puntos panel izq
				ctrlSol->agregar("SOL1", 6, 440.0);
				ctrlSol->modificar("SOL1", "COMPLETADA", 6, 6, 440.0);

				// Ciclo 2 en curso — 4/8 puntos panel der
				ctrlSol->agregar("SOL2", 8, 450.0);
				ctrlSol->modificar("SOL2", "EN CURSO", 8, 4, 450.0);

				// Techo pendiente — brazo 3 aun en reposo
				ctrlSol->agregar("SOL3", 12, 430.0);
				ctrlSol->modificar("SOL3", "PENDIENTE", 12, 0, 430.0);
			}

			TareaCoordinadaController^ ctrlCoo = gcnew TareaCoordinadaController();
			if (ctrlCoo->obtenerTodos()->Count == 0)
			{
				// Los 3 brazos deben confirmar posicion antes de soldar techo
				ctrlCoo->agregar("Coo1", 3);
				ctrlCoo->modificar("Coo1", "EN CURSO", 1, 3); // Solo brazo 1 confirmo
			}

			// --- 5. ESTACION BODY FRAMING ---
			EstacionBodyFramingController^ ctrlEst = gcnew EstacionBodyFramingController();
			if (ctrlEst->obtenerTodos()->Count == 0)
				ctrlEst->agregar("1");

			// --- 6. REPORTE DE COSTOS ---
			// Ciclo 1: completado, 38 min, costo por ciclo $115
			// Ciclo 2: en curso (parcial)
			ReporteController^ ctrlReporte = gcnew ReporteController();
			if (ctrlReporte->obtenerTodos()->Count == 0)
			{
				ctrlReporte->agregar("REP1", 1, 38.0, 115.0);  // Ciclo completado
				ctrlReporte->agregar("REP2", 0, 12.5, 115.0);  // Ciclo en curso
			}

			// --- 7. EVENTOS ---
			// Narrativa: durante el ciclo 1 todo fue INFO/ALERTA menor.
			// En el ciclo 2 hay un error activo en el brazo 2.

			EventoTareaController^ ctrlEvTarea = gcnew EventoTareaController();
			if (ctrlEvTarea->obtenerTodos()->Count == 0)
			{
				// Ciclo 1 — tarea soldar panel izq completada
				ctrlEvTarea->agregar("ET-001", "2026-06-04 08:15:00",
					"Tarea Soldar PL-001 completada exitosamente", "1", "COMPLETADO");

				// Ciclo 1 — tarea posicionar panel izq completada
				ctrlEvTarea->agregar("ET-002", "2026-06-04 08:02:00",
					"Tarea Posicionar PL-001 completada", "1", "COMPLETADO");

				// Ciclo 2 — tarea soldar panel der en curso
				ctrlEvTarea->agregar("ET-003", "2026-06-04 08:28:00",
					"Tarea Soldar PL-004 iniciada — 4/8 puntos completados", "2", "EN PROCESO");
			}

			EventoAlertaController^ ctrlEvAlerta = gcnew EventoAlertaController();
			if (ctrlEvAlerta->obtenerTodos()->Count == 0)
			{
				// Brazo 2 reportó fuerza de agarre cerca del límite
				ctrlEvAlerta->agregar("EA-001", "2026-06-04 08:22:00",
					"Fuerza de agarre GripperDer proxima al limite (8.5 N / max 9.0 N)",
					"2", "FUERZA_LIMITE");

				// Brazo 1 pausado brevemente para recalibración
				ctrlEvAlerta->agregar("EA-002", "2026-06-04 08:05:00",
					"Brazo 1 detenido momentaneamente para recalibracion de angulo",
					"1", "RECALIBRACION");
			}

			EventoErrorController^ ctrlEvError = gcnew EventoErrorController();
			if (ctrlEvError->obtenerTodos()->Count == 0)
			{
				// Brazo 2 tuvo un error de posicionamiento que fue resuelto
				ctrlEvError->agregar("EE-001", "2026-06-04 08:18:00",
					"Brazo 2 excedio tolerancia de posicionamiento durante ciclo 2",
					"ERR-POS-002", "POSICIONAMIENTO");

				// Error de sensor en brazo 3 — aun activo
				ctrlEvError->agregar("EE-002", "2026-06-04 08:30:00",
					"SensorFza-3 reporta lectura anomala — brazo 3 en reposo preventivo",
					"ERR-SEN-003", "LECTURA_SENSOR");
			}

			// --- 8. REGISTRO DE EVENTOS (índice centralizado) ---
			RegistroEventosController^ ctrlRegistro = gcnew RegistroEventosController();
			ctrlRegistro->cargarArchivo(ctrlEvTarea, ctrlEvAlerta, ctrlEvError);

			if (ctrlRegistro->obtenerTodos()->Count == 0)
			{
				ctrlRegistro->agregar(); // crea el registro índice 0

				// Vincular todos los eventos al registro 0
				ctrlRegistro->agregarEvento(0, ctrlEvTarea->buscarPorId("ET-001"));
				ctrlRegistro->agregarEvento(0, ctrlEvTarea->buscarPorId("ET-002"));
				ctrlRegistro->agregarEvento(0, ctrlEvTarea->buscarPorId("ET-003"));
				ctrlRegistro->agregarEvento(0, ctrlEvAlerta->buscarPorId("EA-001"));
				ctrlRegistro->agregarEvento(0, ctrlEvAlerta->buscarPorId("EA-002"));
				ctrlRegistro->agregarEvento(0, ctrlEvError->buscarPorId("EE-001"));
				ctrlRegistro->agregarEvento(0, ctrlEvError->buscarPorId("EE-002"));
			}



		}




	private: System::Void Interfaz_Load(System::Object^ sender, System::EventArgs^ e) {
		HWND hwnd = (HWND)this->Handle.ToPointer();
		BOOL modooscuro = true;
		DwmSetWindowAttribute(hwnd, 20, &modooscuro, sizeof(modooscuro));
		SembrarDatosPrueba();
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
private: System::Void Interfaz_FormClosing(System::Object^ sender, System::Windows::Forms::FormClosingEventArgs^ e) {
	if (Login != nullptr) {
		Login->Show();
	}
}
private: System::Void panel2_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
}
};
}
