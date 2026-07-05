#pragma once

namespace LOGIN {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Collections::Generic;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Threading;
	using namespace GemeloDigitalController;
	using namespace GemeloDigitalModel;

	public ref class Estacion_ciclo : public System::Windows::Forms::Form
	{
	public:
		Estacion_ciclo(void)
		{
			InitializeComponent();

			checkBox2->Visible = false;
			checkBox3->Visible = false;
			checkBox4->Visible = false;
			checkBox5->Visible = false;
			checkBox6->Visible = false;

			this->pictureBox1->Paint += gcnew System::Windows::Forms::PaintEventHandler(
				this, &Estacion_ciclo::pictureBox1_Paint);

			ctrlBrazo = gcnew BrazoRoboticoController();

			lockTareas = gcnew Object();
			lockEventos = gcnew Object();
			lockFin = gcnew Object();

			simulacionConcurrenteActiva = false;
			modoConcurrenteDelCiclo = false;
			brazosFinalizados = 0;

			cicloActivoSufijo = nullptr;
			cicloActivoSufijo = CicloController::obtenerCicloActivo();

			if (cicloActivoSufijo != nullptr) {
				chkModoConcurrente->Enabled = false;
				button1->Enabled = false;
			}

			CargarEstado();
		}

	protected:
		~Estacion_ciclo()
		{
			if (components)
				delete components;
		}

	protected:
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Panel^ panel1;
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::Button^ button5;
	private: System::Windows::Forms::Button^ button4;
	private: System::Windows::Forms::Button^ button3;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::Panel^ panel2;
	private: System::Windows::Forms::CheckBox^ checkBox1;
	private: System::Windows::Forms::CheckBox^ checkBox6;
	private: System::Windows::Forms::CheckBox^ checkBox5;
	private: System::Windows::Forms::CheckBox^ checkBox4;
	private: System::Windows::Forms::CheckBox^ checkBox3;
	private: System::Windows::Forms::CheckBox^ checkBox2;
	private: System::Windows::Forms::CheckBox^ chkModoConcurrente;
	private: System::Windows::Forms::PictureBox^ pictureBox1;
	private: System::Windows::Forms::Label^ label5;

	private:
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		void InitializeComponent(void)
		{
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->panel2 = (gcnew System::Windows::Forms::Panel());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->checkBox6 = (gcnew System::Windows::Forms::CheckBox());
			this->checkBox5 = (gcnew System::Windows::Forms::CheckBox());
			this->checkBox4 = (gcnew System::Windows::Forms::CheckBox());
			this->checkBox3 = (gcnew System::Windows::Forms::CheckBox());
			this->checkBox2 = (gcnew System::Windows::Forms::CheckBox());
			this->chkModoConcurrente = (gcnew System::Windows::Forms::CheckBox());
			this->checkBox1 = (gcnew System::Windows::Forms::CheckBox());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->button5 = (gcnew System::Windows::Forms::Button());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->panel1->SuspendLayout();
			this->panel2->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			this->SuspendLayout();
			this->label2->AutoSize = true;
			this->label2->ForeColor = System::Drawing::Color::White;
			this->label2->Location = System::Drawing::Point(33, 69);
			this->label2->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(43, 13);
			this->label2->TabIndex = 1;
			this->label2->Text = L"Estado:";
			this->label3->AutoSize = true;
			this->label3->ForeColor = System::Drawing::Color::White;
			this->label3->Location = System::Drawing::Point(34, 152);
			this->label3->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(86, 13);
			this->label3->TabIndex = 4;
			this->label3->Text = L"Control de ciclo: ";
			this->panel1->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(30)), static_cast<System::Int32>(static_cast<System::Byte>(40)), static_cast<System::Int32>(static_cast<System::Byte>(58)));
			this->panel1->Controls->Add(this->label5);
			this->panel1->Controls->Add(this->panel2);
			this->panel1->Controls->Add(this->checkBox1);
			this->panel1->Controls->Add(this->chkModoConcurrente);
			this->panel1->Controls->Add(this->label4);
			this->panel1->Controls->Add(this->button5);
			this->panel1->Controls->Add(this->button4);
			this->panel1->Controls->Add(this->button3);
			this->panel1->Controls->Add(this->button1);
			this->panel1->Controls->Add(this->label3);
			this->panel1->Controls->Add(this->label2);
			this->panel1->Dock = System::Windows::Forms::DockStyle::Left;
			this->panel1->Location = System::Drawing::Point(0, 0);
			this->panel1->Margin = System::Windows::Forms::Padding(2);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(907, 593);
			this->panel1->TabIndex = 1;
			this->panel1->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &Estacion_ciclo::panel1_Paint);
			this->label5->AutoSize = true;
			this->label5->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->label5->ForeColor = System::Drawing::Color::White;
			this->label5->Location = System::Drawing::Point(33, 25);
			this->label5->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label5->Name = L"label5";
			this->label5->RightToLeft = System::Windows::Forms::RightToLeft::No;
			this->label5->Size = System::Drawing::Size(288, 16);
			this->label5->TabIndex = 14;
			this->label5->Text = L"Control de Estacion - Ciclo de Operacion";
			this->panel2->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(22)), static_cast<System::Int32>(static_cast<System::Byte>(32)), static_cast<System::Int32>(static_cast<System::Byte>(50)));
			this->panel2->Controls->Add(this->pictureBox1);
			this->panel2->Controls->Add(this->checkBox6);
			this->panel2->Controls->Add(this->checkBox5);
			this->panel2->Controls->Add(this->checkBox4);
			this->panel2->Controls->Add(this->checkBox3);
			this->panel2->Controls->Add(this->checkBox2);
			this->panel2->Location = System::Drawing::Point(34, 223);
			this->panel2->Margin = System::Windows::Forms::Padding(2);
			this->panel2->Name = L"panel2";
			this->panel2->Size = System::Drawing::Size(778, 359);
			this->panel2->TabIndex = 13;
			this->pictureBox1->Location = System::Drawing::Point(12, 2);
			this->pictureBox1->Margin = System::Windows::Forms::Padding(2);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(750, 300);
			this->pictureBox1->TabIndex = 19;
			this->pictureBox1->TabStop = false;
			this->checkBox6->AutoSize = true;
			this->checkBox6->ForeColor = System::Drawing::Color::White;
			this->checkBox6->Location = System::Drawing::Point(564, 340);
			this->checkBox6->Margin = System::Windows::Forms::Padding(2);
			this->checkBox6->Name = L"checkBox6";
			this->checkBox6->Size = System::Drawing::Size(62, 17);
			this->checkBox6->TabIndex = 18;
			this->checkBox6->Text = L"PAUSA";
			this->checkBox6->UseVisualStyleBackColor = true;
			this->checkBox5->AutoSize = true;
			this->checkBox5->ForeColor = System::Drawing::Color::White;
			this->checkBox5->Location = System::Drawing::Point(424, 340);
			this->checkBox5->Margin = System::Windows::Forms::Padding(2);
			this->checkBox5->Name = L"checkBox5";
			this->checkBox5->Size = System::Drawing::Size(65, 17);
			this->checkBox5->TabIndex = 17;
			this->checkBox5->Text = L"ERROR";
			this->checkBox5->UseVisualStyleBackColor = true;
			this->checkBox4->AutoSize = true;
			this->checkBox4->ForeColor = System::Drawing::Color::White;
			this->checkBox4->Location = System::Drawing::Point(278, 340);
			this->checkBox4->Margin = System::Windows::Forms::Padding(2);
			this->checkBox4->Name = L"checkBox4";
			this->checkBox4->Size = System::Drawing::Size(86, 17);
			this->checkBox4->TabIndex = 16;
			this->checkBox4->Text = L"SOLDANDO";
			this->checkBox4->UseVisualStyleBackColor = true;
			this->checkBox3->AutoSize = true;
			this->checkBox3->ForeColor = System::Drawing::Color::White;
			this->checkBox3->Location = System::Drawing::Point(138, 340);
			this->checkBox3->Margin = System::Windows::Forms::Padding(2);
			this->checkBox3->Name = L"checkBox3";
			this->checkBox3->Size = System::Drawing::Size(108, 17);
			this->checkBox3->TabIndex = 15;
			this->checkBox3->Text = L"POSICIONANDO";
			this->checkBox3->UseVisualStyleBackColor = true;
			this->checkBox2->AutoSize = true;
			this->checkBox2->ForeColor = System::Drawing::Color::White;
			this->checkBox2->Location = System::Drawing::Point(43, 340);
			this->checkBox2->Margin = System::Windows::Forms::Padding(2);
			this->checkBox2->Name = L"checkBox2";
			this->checkBox2->Size = System::Drawing::Size(71, 17);
			this->checkBox2->TabIndex = 14;
			this->checkBox2->Text = L"REPOSO";
			this->checkBox2->UseVisualStyleBackColor = true;
			this->checkBox1->AutoSize = true;
			this->checkBox1->ForeColor = System::Drawing::Color::White;
			this->checkBox1->Location = System::Drawing::Point(185, 69);
			this->checkBox1->Margin = System::Windows::Forms::Padding(2);
			this->checkBox1->Name = L"checkBox1";
			this->checkBox1->Size = System::Drawing::Size(125, 17);
			this->checkBox1->TabIndex = 12;
			this->checkBox1->Text = L"Secuencia aprobada";
			this->checkBox1->UseVisualStyleBackColor = true;

			this->chkModoConcurrente->AutoSize = true;
			this->chkModoConcurrente->ForeColor = System::Drawing::Color::White;
			this->chkModoConcurrente->Location = System::Drawing::Point(36, 111);
			this->chkModoConcurrente->Margin = System::Windows::Forms::Padding(2);
			this->chkModoConcurrente->Name = L"chkModoConcurrente";
			this->chkModoConcurrente->Size = System::Drawing::Size(190, 17);
			this->chkModoConcurrente->TabIndex = 13;
			this->chkModoConcurrente->Text = L"Modo automatico concurrente";
			this->chkModoConcurrente->UseVisualStyleBackColor = true;

			this->label4->AutoSize = true;
			this->label4->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(24)), static_cast<System::Int32>(static_cast<System::Byte>(138)), static_cast<System::Int32>(static_cast<System::Byte>(71)));
			this->label4->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->label4->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->label4->ForeColor = System::Drawing::Color::Lime;
			this->label4->Location = System::Drawing::Point(102, 67);
			this->label4->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(71, 15);
			this->label4->TabIndex = 11;
			this->label4->Text = L"OPERATIVO";
			this->label4->Click += gcnew System::EventHandler(this, &Estacion_ciclo::label4_Click);
			this->button5->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(245)), static_cast<System::Int32>(static_cast<System::Byte>(158)), static_cast<System::Int32>(static_cast<System::Byte>(11)));
			this->button5->FlatAppearance->BorderSize = 0;
			this->button5->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->button5->Location = System::Drawing::Point(679, 171);
			this->button5->Margin = System::Windows::Forms::Padding(2);
			this->button5->Name = L"button5";
			this->button5->Size = System::Drawing::Size(93, 28);
			this->button5->TabIndex = 9;
			this->button5->Text = L"5. Finalizar";
			this->button5->UseVisualStyleBackColor = false;
			this->button5->Click += gcnew System::EventHandler(this, &Estacion_ciclo::button5_Click);
			this->button4->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(245)), static_cast<System::Int32>(static_cast<System::Byte>(158)), static_cast<System::Int32>(static_cast<System::Byte>(11)));
			this->button4->FlatAppearance->BorderSize = 0;
			this->button4->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->button4->Location = System::Drawing::Point(430, 171);
			this->button4->Margin = System::Windows::Forms::Padding(2);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(93, 28);
			this->button4->TabIndex = 8;
			this->button4->Text = L"4. Reanudar";
			this->button4->UseVisualStyleBackColor = false;
			this->button4->Click += gcnew System::EventHandler(this, &Estacion_ciclo::button4_Click);
			this->button3->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(245)), static_cast<System::Int32>(static_cast<System::Byte>(158)), static_cast<System::Int32>(static_cast<System::Byte>(11)));
			this->button3->FlatAppearance->BorderSize = 0;
			this->button3->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->button3->Location = System::Drawing::Point(228, 171);
			this->button3->Margin = System::Windows::Forms::Padding(2);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(93, 28);
			this->button3->TabIndex = 7;
			this->button3->Text = L"3. Pausar";
			this->button3->UseVisualStyleBackColor = false;
			this->button3->Click += gcnew System::EventHandler(this, &Estacion_ciclo::button3_Click);
			this->button1->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(245)), static_cast<System::Int32>(static_cast<System::Byte>(158)), static_cast<System::Int32>(static_cast<System::Byte>(11)));
			this->button1->FlatAppearance->BorderSize = 0;
			this->button1->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->button1->Location = System::Drawing::Point(34, 171);
			this->button1->Margin = System::Windows::Forms::Padding(2);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(93, 28);
			this->button1->TabIndex = 5;
			this->button1->Text = L"1. Iniciar ciclo";
			this->button1->UseVisualStyleBackColor = false;
			this->button1->Click += gcnew System::EventHandler(this, &Estacion_ciclo::button1_Click);
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(904, 593);
			this->Controls->Add(this->panel1);
			this->Margin = System::Windows::Forms::Padding(2);
			this->Name = L"Estacion_ciclo";
			this->Text = L"Estacion_ciclo";
			this->Load += gcnew System::EventHandler(this, &Estacion_ciclo::Estacion_ciclo_Load);
			this->panel1->ResumeLayout(false);
			this->panel1->PerformLayout();
			this->panel2->ResumeLayout(false);
			this->panel2->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			this->ResumeLayout(false);
		}
#pragma endregion

	private:
		BrazoRoboticoController^ ctrlBrazo;
		String^ cicloActivoSufijo;

		Object^ lockTareas;
		Object^ lockEventos;
		Object^ lockFin;

		bool simulacionConcurrenteActiva;
		bool modoConcurrenteDelCiclo;
		int brazosFinalizados;

		void CargarEstado() {
			List<BrazoRoboticoModel^>^ brazos = ctrlBrazo->obtenerTodos();

			bool hayError = false;
			for each (BrazoRoboticoModel ^ b in brazos)
				if (b->Estado == GemeloDigitalModel::EstadoBrazo::EN_ERROR)
					hayError = true;

			label4->Text = hayError ? "ALERTA" : "OPERATIVO";
			label4->ForeColor = hayError ? Color::Orange : Color::FromArgb(0, 200, 100);

			LineaEnsamblajeController^ ctrlLinea = gcnew LineaEnsamblajeController();
			bool hayLineaAprobada = false;
			for each (LineaEnsamblajeModel ^ l in ctrlLinea->obtenerTodos())
				if (l->SecuenciaAprobada) { hayLineaAprobada = true; break; }

			checkBox1->Checked = hayLineaAprobada;
			pictureBox1->Invalidate();
		}

	private: System::Void panel1_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {}

	private: System::Void button5_Click(System::Object^ sender, System::EventArgs^ e) {
		if (simulacionConcurrenteActiva) {
			MessageBox::Show(
				"No puedes finalizar mientras el modo automatico concurrente sigue ejecutandose.",
				"Ejecucion en proceso",
				MessageBoxButtons::OK,
				MessageBoxIcon::Warning
			);
			return;
		}

		cicloActivoSufijo = nullptr;
		CicloController::limpiarCicloActivo();

		for each (BrazoRoboticoModel ^ b in ctrlBrazo->obtenerTodos())
			ctrlBrazo->modificar(b->Id, GemeloDigitalModel::EstadoBrazo::REPOSO);

		CicloController^ ctrlCiclo = gcnew CicloController();
		String^ nuevoCicloId = (ctrlCiclo->obtenerTodos()->Count + 1).ToString();
		ctrlCiclo->agregar(nuevoCicloId, 0.5, "PENDIENTE");

		modoConcurrenteDelCiclo = false;
		simulacionConcurrenteActiva = false;
		brazosFinalizados = 0;

		chkModoConcurrente->Checked = false;
		chkModoConcurrente->Enabled = true;

		button1->Enabled = true;
		button3->Enabled = true;
		button4->Enabled = true;
		button5->Enabled = true;

		CargarEstado();

		MessageBox::Show(
			"Ciclo #" + nuevoCicloId + " completado.\n0.5 hrs registradas - estado: PENDIENTE.",
			"Ciclo finalizado", MessageBoxButtons::OK, MessageBoxIcon::Information);

		cicloActivoSufijo = nullptr;
	}

	private: System::Void label4_Click(System::Object^ sender, System::EventArgs^ e) {}

		   String^ GetEstadoVisualBrazo(String^ brazoId) {
			   if (cicloActivoSufijo == nullptr) return "REPOSO";
			   TareaCoordinadaController^ ctrlCoo = gcnew TareaCoordinadaController();
			   for each (TareaCoordinadaModel ^ t in ctrlCoo->obtenerTodos()) {
				   if (t->Id->Contains(cicloActivoSufijo) && t->Id->Contains(brazoId)) {
					   if (t->Estado == "COMPLETADA") return "COORDINADO";
					   return "EN PROCESO";
				   }
			   }
			   return "REPOSO";
		   }

		   Color GetColorEstadoVisual(String^ estado) {
			   if (estado == "COORDINADO") return Color::FromArgb(0, 180, 90);
			   if (estado == "EN PROCESO") return Color::FromArgb(50, 100, 200);
			   return Color::FromArgb(80, 90, 110);
		   }

	private: System::Void pictureBox1_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
		Graphics^ g = e->Graphics;
		g->SmoothingMode = Drawing2D::SmoothingMode::AntiAlias;

		int w = pictureBox1->Width;
		int h = pictureBox1->Height;

		Drawing::Rectangle rChasis = Drawing::Rectangle(w / 2 - 100, h / 2 - 50, 200, 100);
		g->FillRectangle(gcnew SolidBrush(Color::FromArgb(50, 60, 80)), rChasis);
		g->DrawRectangle(gcnew Pen(Color::FromArgb(80, 90, 110), 1), rChasis);
		StringFormat^ sf = gcnew StringFormat();
		sf->Alignment = StringAlignment::Center;
		sf->LineAlignment = StringAlignment::Center;
		g->DrawString("CHASIS", gcnew Drawing::Font("Segoe UI", 10, FontStyle::Bold),
			gcnew SolidBrush(Color::FromArgb(120, 130, 150)), rChasis, sf);

		array<String^>^ brazos = { "LATERAL_IZQ", "LATERAL_DER", "CENTRAL_SUP" };
		array<String^>^ etiquetas = { "BRAZO IZQ", "BRAZO DER", "BRAZO CENT" };
		array<Drawing::Rectangle>^ rects = {
			Drawing::Rectangle(30, h / 2 - 50, 140, 100),
			Drawing::Rectangle(w - 170, h / 2 - 50, 140, 100),
			Drawing::Rectangle(w / 2 - 70, 20, 140, 90)
		};

		for (int i = 0; i < brazos->Length; i++) {
			String^ estadoVisual = GetEstadoVisualBrazo(brazos[i]);
			Color colorBrazo = GetColorEstadoVisual(estadoVisual);
			g->FillRectangle(gcnew SolidBrush(colorBrazo), rects[i]);
			g->DrawRectangle(gcnew Pen(Color::FromArgb(200, 200, 200), 1), rects[i]);
			g->DrawString(etiquetas[i] + "\n" + estadoVisual,
				gcnew Drawing::Font("Segoe UI", 8, FontStyle::Bold),
				gcnew SolidBrush(Color::White), rects[i], sf);
		}

		array<String^>^ textos = { "REPOSO", "EN PROCESO", "COORDINADO" };
		array<Color>^ colores = {
			Color::FromArgb(80, 90, 110),
			Color::FromArgb(50, 100, 200),
			Color::FromArgb(0, 180, 90)
		};
		int xLey = 20;
		for (int i = 0; i < textos->Length; i++) {
			g->FillRectangle(gcnew SolidBrush(colores[i]),
				Drawing::Rectangle(xLey, h - 30, 16, 16));
			g->DrawString(textos[i],
				gcnew Drawing::Font("Segoe UI", 8),
				gcnew SolidBrush(Color::White),
				Drawing::PointF(xLey + 20, h - 25));
			xLey += 160;
		}
	}

	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
		LineaEnsamblajeController^ ctrlLinea = gcnew LineaEnsamblajeController();

		// CORRECCIÓN: buscar linea aprobada y recargarla con buscarPorId
		// para asegurar que la cola este bien cargada
		LineaEnsamblajeModel^ lineaActiva = nullptr;
		for each (LineaEnsamblajeModel ^ l in ctrlLinea->obtenerTodos()) {
			if (l->SecuenciaAprobada) {
				lineaActiva = ctrlLinea->buscarPorId(l->Id);
				break;
			}
		}

		if (lineaActiva == nullptr) {
			MessageBox::Show("No hay linea con secuencia aprobada.",
				"Sin linea aprobada", MessageBoxButtons::OK, MessageBoxIcon::Warning);
			return;
		}

		// Verificar que la linea tiene piezas en cola
		if (lineaActiva->ColaPiezas->Count == 0) {
			MessageBox::Show("La linea aprobada no tiene piezas en cola.",
				"Cola vacia", MessageBoxButtons::OK, MessageBoxIcon::Warning);
			return;
		}

		TareaPosicionarController^ ctrlPos = gcnew TareaPosicionarController();
		TareaSostenerController^ ctrlSos = gcnew TareaSostenerController();
		TareaSoldarController^ ctrlSol = gcnew TareaSoldarController();
		TareaCoordinadaController^ ctrlCoo = gcnew TareaCoordinadaController();

		List<String^>^ idsPos = gcnew List<String^>();
		List<String^>^ idsSos = gcnew List<String^>();
		List<String^>^ idsSol = gcnew List<String^>();
		List<String^>^ idsCoo = gcnew List<String^>();

		for each (TareaPosicionarModel ^ t in ctrlPos->obtenerTodos()) idsPos->Add(t->Id);
		for each (TareaSostenerModel ^ t in ctrlSos->obtenerTodos()) idsSos->Add(t->Id);
		for each (TareaSoldarModel ^ t in ctrlSol->obtenerTodos()) idsSol->Add(t->Id);
		for each (TareaCoordinadaModel ^ t in ctrlCoo->obtenerTodos()) idsCoo->Add(t->Id);

		for each (String ^ id in idsPos) ctrlPos->eliminar(id);
		for each (String ^ id in idsSos) ctrlSos->eliminar(id);
		for each (String ^ id in idsSol) ctrlSol->eliminar(id);
		for each (String ^ id in idsCoo) ctrlCoo->eliminar(id);

		CicloController^ ctrlCiclo = gcnew CicloController();
		int numCiclo = ctrlCiclo->obtenerTodos()->Count + 1;
		String^ cicloSufijo = lineaActiva->Id + "-C" + numCiclo.ToString("D3");
		cicloActivoSufijo = cicloSufijo;
		CicloController::guardarCicloActivo(cicloSufijo);

		modoConcurrenteDelCiclo = chkModoConcurrente->Checked;
		chkModoConcurrente->Enabled = false;
		button1->Enabled = false;

		for each (PiezaModel ^ pieza in lineaActiva->ColaPiezas) {
			String^ brazo;
			PanelLateralModel^ pl = dynamic_cast<PanelLateralModel^>(pieza);
			if (pl != nullptr)
				brazo = (pl->Lado == LadoPanel::IZQUIERDO) ? "LATERAL_IZQ" : "LATERAL_DER";
			else
				brazo = "CENTRAL_SUP";

			ctrlPos->agregar("POS-" + cicloSufijo + "-" + brazo, 90.0, 0.5);
			ctrlSos->agregar("SOS-" + cicloSufijo + "-" + brazo, 10.0, 5);
			ctrlSol->agregar("SOL-" + cicloSufijo + "-" + brazo, 3, 250.0);
			ctrlCoo->agregar("COO-" + cicloSufijo + "-" + brazo, 1);
		}

		for each (BrazoRoboticoModel ^ b in ctrlBrazo->obtenerTodos())
		{
			ctrlBrazo->modificar(b->Id, GemeloDigitalModel::EstadoBrazo::POSICIONANDO);
			ctrlBrazo->ResetearComponentes(b->Id);
		}

		CargarEstado();

		if (modoConcurrenteDelCiclo) {
			MessageBox::Show(
				"Ciclo iniciado. Tareas generadas correctamente.\nModo automatico concurrente activado.",
				"Ciclo iniciado",
				MessageBoxButtons::OK,
				MessageBoxIcon::Information
			);

			IniciarEjecucionConcurrente();
		}
		else {
			MessageBox::Show(
				"Ciclo iniciado. Tareas generadas correctamente.\nModo manual activo.",
				"Ciclo iniciado",
				MessageBoxButtons::OK,
				MessageBoxIcon::Information
			);
		}
	}

		   private: void IniciarEjecucionConcurrente() {
			   if (cicloActivoSufijo == nullptr) {
				   MessageBox::Show(
					   "No existe un ciclo activo para ejecutar en modo concurrente.",
					   "Sin ciclo activo",
					   MessageBoxButtons::OK,
					   MessageBoxIcon::Warning
				   );
				   return;
			   }

			   if (simulacionConcurrenteActiva) {
				   MessageBox::Show(
					   "La ejecucion concurrente ya esta en proceso.",
					   "Proceso activo",
					   MessageBoxButtons::OK,
					   MessageBoxIcon::Information
				   );
				   return;
			   }

			   simulacionConcurrenteActiva = true;
			   brazosFinalizados = 0;

			   button3->Enabled = false;
			   button4->Enabled = false;
			   button5->Enabled = false;

			   Thread^ hiloIzq = gcnew Thread(gcnew ParameterizedThreadStart(this, &Estacion_ciclo::EjecutarBrazoConcurrente));
			   Thread^ hiloDer = gcnew Thread(gcnew ParameterizedThreadStart(this, &Estacion_ciclo::EjecutarBrazoConcurrente));
			   Thread^ hiloCen = gcnew Thread(gcnew ParameterizedThreadStart(this, &Estacion_ciclo::EjecutarBrazoConcurrente));

			   hiloIzq->IsBackground = true;
			   hiloDer->IsBackground = true;
			   hiloCen->IsBackground = true;

			   hiloIzq->Start("LATERAL_IZQ");
			   hiloDer->Start("LATERAL_DER");
			   hiloCen->Start("CENTRAL_SUP");
		   }


	private: void EjecutarBrazoConcurrente(Object^ datosBrazo) {
		String^ brazo = safe_cast<String^>(datosBrazo);

		CompletarTareaSegura("POS", brazo);
		RegistrarEventoSeguro(
			"Brazo " + brazo + " completo POSICIONAR en modo concurrente",
			"POS-" + cicloActivoSufijo + "-" + brazo,
			"COMPLETADA"
		);
		RefrescarVistaSeguro();
		Thread::Sleep(800);

		CompletarTareaSegura("SOS", brazo);
		RegistrarEventoSeguro(
			"Brazo " + brazo + " completo SOSTENER en modo concurrente",
			"SOS-" + cicloActivoSufijo + "-" + brazo,
			"COMPLETADA"
		);
		RefrescarVistaSeguro();
		Thread::Sleep(800);

		CompletarTareaSegura("SOL", brazo);
		RegistrarEventoSeguro(
			"Brazo " + brazo + " completo SOLDAR en modo concurrente",
			"SOL-" + cicloActivoSufijo + "-" + brazo,
			"COMPLETADA"
		);
		RefrescarVistaSeguro();
		Thread::Sleep(800);

		CompletarTareaSegura("COO", brazo);
		RegistrarEventoSeguro(
			"Brazo " + brazo + " completo COORDINADA en modo concurrente",
			"COO-" + cicloActivoSufijo + "-" + brazo,
			"COMPLETADA"
		);
		RefrescarVistaSeguro();

		Monitor::Enter(lockFin);
		try {
			brazosFinalizados++;

			if (brazosFinalizados == 3) {
				simulacionConcurrenteActiva = false;
				MostrarFinConcurrenteSeguro();
			}
		}
		finally {
			Monitor::Exit(lockFin);
		}
	}

	private: void CompletarTareaSegura(String^ tipo, String^ brazo) {
		Monitor::Enter(lockTareas);

		try {
			try {
				String^ idTarea = tipo + "-" + cicloActivoSufijo + "-" + brazo;

				if (tipo->Equals("POS")) {
					TareaPosicionarController^ ctrl = gcnew TareaPosicionarController();
					TareaPosicionarModel^ t = ctrl->buscarPorId(idTarea);

					if (t != nullptr) {
						ctrl->modificar(
							idTarea,
							"COMPLETADA",
							t->PosicionObjetivo,
							t->Tolerancia
						);
					}
				}
				else if (tipo->Equals("SOS")) {
					TareaSostenerController^ ctrl = gcnew TareaSostenerController();
					TareaSostenerModel^ t = ctrl->buscarPorId(idTarea);

					if (t != nullptr) {
						ctrl->modificar(
							idTarea,
							"COMPLETADA",
							t->FuerzaSosten,
							t->Duracion
						);
					}
				}
				else if (tipo->Equals("SOL")) {
					TareaSoldarController^ ctrl = gcnew TareaSoldarController();
					TareaSoldarModel^ t = ctrl->buscarPorId(idTarea);

					if (t != nullptr) {
						ctrl->modificar(
							idTarea,
							"COMPLETADA",
							t->PuntosObjetivo,
							t->PuntosObjetivo,
							t->Temperatura
						);
					}
				}
				else if (tipo->Equals("COO")) {
					TareaCoordinadaController^ ctrl = gcnew TareaCoordinadaController();
					TareaCoordinadaModel^ t = ctrl->buscarPorId(idTarea);

					if (t != nullptr) {
						ctrl->modificar(
							idTarea,
							"COMPLETADA",
							1,
							t->TotalRequerido
						);
					}
				}
			}
			catch (Exception^ ex) {
				System::Diagnostics::Debug::WriteLine(
					"Error al completar tarea concurrente: " + ex->Message
				);
			}
		}
		finally {
			Monitor::Exit(lockTareas);
		}
	}


	private: void RegistrarEventoSeguro(String^ descripcion, String^ tareaId, String^ resultado) {
		Monitor::Enter(lockEventos);

		try {
			try {
				EventoTareaController^ ctrlEvento = gcnew EventoTareaController();

				String^ idEvento = DateTime::Now.Ticks.ToString()
					+ "-"
					+ Thread::CurrentThread->ManagedThreadId.ToString();

				String^ timestamp = DateTime::Now.ToString("yyyy-MM-dd HH:mm:ss");

				ctrlEvento->agregar(
					idEvento,
					timestamp,
					descripcion,
					tareaId,
					resultado
				);
			}
			catch (Exception^ ex) {
				System::Diagnostics::Debug::WriteLine(
					"No se pudo registrar evento concurrente: " + ex->Message
				);
			}
		}
		finally {
			Monitor::Exit(lockEventos);
		}
	}

	private: void RefrescarVistaSeguro() {
		if (this->InvokeRequired) {
			this->BeginInvoke(
				gcnew MethodInvoker(this, &Estacion_ciclo::RefrescarVistaSeguro)
			);
		}
		else {
			CargarEstado();
			pictureBox1->Invalidate();
		}
	}

	private: void MostrarFinConcurrenteSeguro() {
		if (this->InvokeRequired) {
			this->BeginInvoke(
				gcnew MethodInvoker(this, &Estacion_ciclo::MostrarFinConcurrenteSeguro)
			);
		}
		else {
			RefrescarVistaSeguro();

			button5->Enabled = true;

			MessageBox::Show(
				"Modo automatico concurrente finalizado.\nLos 3 brazos completaron sus tareas en paralelo.\nAhora puedes finalizar el ciclo.",
				"Ejecucion concurrente completada",
				MessageBoxButtons::OK,
				MessageBoxIcon::Information
			);
		}
	}



	private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {
		for each (BrazoRoboticoModel ^ b in ctrlBrazo->obtenerTodos())
			ctrlBrazo->modificar(b->Id, GemeloDigitalModel::EstadoBrazo::POSICIONANDO);
		CargarEstado();
	}

	private: System::Void button3_Click(System::Object^ sender, System::EventArgs^ e) {
		if (modoConcurrenteDelCiclo) {
			MessageBox::Show(
				"La pausa manual no esta disponible durante el modo automatico concurrente.",
				"Modo automatico",
				MessageBoxButtons::OK,
				MessageBoxIcon::Information
			);
			return;
		}

		for each (BrazoRoboticoModel ^ b in ctrlBrazo->obtenerTodos())
			ctrlBrazo->modificar(b->Id, GemeloDigitalModel::EstadoBrazo::PAUSA);

		CargarEstado();
	}

	private: System::Void button4_Click(System::Object^ sender, System::EventArgs^ e) {
		if (modoConcurrenteDelCiclo) {
			MessageBox::Show(
				"La reanudacion manual no esta disponible durante el modo automatico concurrente.",
				"Modo automatico",
				MessageBoxButtons::OK,
				MessageBoxIcon::Information
			);
			return;
		}

		for each (BrazoRoboticoModel ^ b in ctrlBrazo->obtenerTodos())
			ctrlBrazo->modificar(b->Id, GemeloDigitalModel::EstadoBrazo::POSICIONANDO);

		CargarEstado();
	}

	private: System::Void button6_Click(System::Object^ sender, System::EventArgs^ e) {
		if (MessageBox::Show(
			"Confirma detencion de emergencia? Todos los brazos pasaran a estado ERROR.",
			"Emergencia", MessageBoxButtons::YesNo, MessageBoxIcon::Warning)
			== System::Windows::Forms::DialogResult::Yes) {
			for each (BrazoRoboticoModel ^ b in ctrlBrazo->obtenerTodos())
				ctrlBrazo->modificar(b->Id, GemeloDigitalModel::EstadoBrazo::EN_ERROR);
			CargarEstado();
		}
	}

	private: System::Void Estacion_ciclo_Load(System::Object^ sender, System::EventArgs^ e) {}
	};
}