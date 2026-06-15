#pragma once

namespace LOGIN {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Collections::Generic;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace GemeloDigitalController;
	using namespace GemeloDigitalModel;

	public ref class Estaciones_de_Trabajo_Inventario : public System::Windows::Forms::Form
	{
	private:
		EstacionTrabajoController^ estacionCtrl;

	public:
		Estaciones_de_Trabajo_Inventario(void)
		{
			InitializeComponent();
			estacionCtrl = gcnew EstacionTrabajoController();
			refrescarTabla();
			ActualizarDiagrama();
		}

	protected:
		~Estaciones_de_Trabajo_Inventario()
		{
			if (components) delete components;
		}

	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::DataGridView^ dataGridView1;



	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Panel^ panel2;
	private: System::Windows::Forms::Panel^ panel1;
	private: System::Windows::Forms::CheckBox^ checkBox1;

	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::Label^ label6;
	private: System::Windows::Forms::Button^ button6;
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Panel^ panel4;
	private: System::Windows::Forms::Panel^ panel8;
	private: System::Windows::Forms::Panel^ panel7;
	private: System::Windows::Forms::Panel^ panel6;
	private: System::Windows::Forms::Panel^ panel5;
	private: System::Windows::Forms::Panel^ panel3;
	private: System::Windows::Forms::ComboBox^ comboBox1;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Column1;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Rol;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Column2;

	private:
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
        void InitializeComponent(void)
        {
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->panel2 = (gcnew System::Windows::Forms::Panel());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->comboBox1 = (gcnew System::Windows::Forms::ComboBox());
			this->checkBox1 = (gcnew System::Windows::Forms::CheckBox());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->button6 = (gcnew System::Windows::Forms::Button());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->panel4 = (gcnew System::Windows::Forms::Panel());
			this->panel3 = (gcnew System::Windows::Forms::Panel());
			this->panel5 = (gcnew System::Windows::Forms::Panel());
			this->panel6 = (gcnew System::Windows::Forms::Panel());
			this->panel7 = (gcnew System::Windows::Forms::Panel());
			this->panel8 = (gcnew System::Windows::Forms::Panel());
			this->Column1 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Rol = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column2 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->BeginInit();
			this->panel2->SuspendLayout();
			this->panel1->SuspendLayout();
			this->panel4->SuspendLayout();
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(245)), static_cast<System::Int32>(static_cast<System::Byte>(158)),
				static_cast<System::Int32>(static_cast<System::Byte>(11)));
			this->label1->Location = System::Drawing::Point(32, 44);
			this->label1->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(123, 13);
			this->label1->TabIndex = 1;
			this->label1->Text = L"Estaciones configuradas";
			// 
			// dataGridView1
			// 
			this->dataGridView1->AutoSizeColumnsMode = System::Windows::Forms::DataGridViewAutoSizeColumnsMode::Fill;
			this->dataGridView1->BackgroundColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(15)),
				static_cast<System::Int32>(static_cast<System::Byte>(23)), static_cast<System::Int32>(static_cast<System::Byte>(42)));
			this->dataGridView1->ColumnHeadersBorderStyle = System::Windows::Forms::DataGridViewHeaderBorderStyle::Single;
			this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView1->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(3) {
				this->Column1,
					this->Rol, this->Column2
			});
			this->dataGridView1->EnableHeadersVisualStyles = false;
			this->dataGridView1->Location = System::Drawing::Point(34, 68);
			this->dataGridView1->Margin = System::Windows::Forms::Padding(2);
			this->dataGridView1->Name = L"dataGridView1";
			this->dataGridView1->ReadOnly = true;
			this->dataGridView1->RowHeadersVisible = false;
			this->dataGridView1->RowTemplate->Height = 24;
			this->dataGridView1->SelectionMode = System::Windows::Forms::DataGridViewSelectionMode::FullRowSelect;
			this->dataGridView1->Size = System::Drawing::Size(602, 108);
			this->dataGridView1->TabIndex = 28;
			this->dataGridView1->CellContentClick += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &Estaciones_de_Trabajo_Inventario::dataGridView1_CellContentClick);
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(245)), static_cast<System::Int32>(static_cast<System::Byte>(158)),
				static_cast<System::Int32>(static_cast<System::Byte>(11)));
			this->label2->Location = System::Drawing::Point(32, 196);
			this->label2->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(137, 13);
			this->label2->TabIndex = 29;
			this->label2->Text = L"Agregar estación de trabajo";
			// 
			// panel2
			// 
			this->panel2->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(245)), static_cast<System::Int32>(static_cast<System::Byte>(158)),
				static_cast<System::Int32>(static_cast<System::Byte>(11)));
			this->panel2->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->panel2->Controls->Add(this->panel1);
			this->panel2->Location = System::Drawing::Point(32, 222);
			this->panel2->Margin = System::Windows::Forms::Padding(2);
			this->panel2->Name = L"panel2";
			this->panel2->Size = System::Drawing::Size(603, 102);
			this->panel2->TabIndex = 36;
			// 
			// panel1
			// 
			this->panel1->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(15)), static_cast<System::Int32>(static_cast<System::Byte>(23)),
				static_cast<System::Int32>(static_cast<System::Byte>(42)));
			this->panel1->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->panel1->Controls->Add(this->comboBox1);
			this->panel1->Controls->Add(this->checkBox1);
			this->panel1->Controls->Add(this->label5);
			this->panel1->Controls->Add(this->label6);
			this->panel1->Location = System::Drawing::Point(2, 2);
			this->panel1->Margin = System::Windows::Forms::Padding(2);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(598, 95);
			this->panel1->TabIndex = 28;
			// 
			// comboBox1
			// 
			this->comboBox1->FormattingEnabled = true;
			this->comboBox1->Items->AddRange(gcnew cli::array< System::Object^  >(3) { L"Panel Izquierdo", L"Panel Derecho", L"Techo" });
			this->comboBox1->Location = System::Drawing::Point(31, 54);
			this->comboBox1->Name = L"comboBox1";
			this->comboBox1->Size = System::Drawing::Size(121, 21);
			this->comboBox1->TabIndex = 32;
			// 
			// checkBox1
			// 
			this->checkBox1->AutoSize = true;
			this->checkBox1->ForeColor = System::Drawing::Color::White;
			this->checkBox1->Location = System::Drawing::Point(274, 54);
			this->checkBox1->Margin = System::Windows::Forms::Padding(2);
			this->checkBox1->Name = L"checkBox1";
			this->checkBox1->Size = System::Drawing::Size(70, 17);
			this->checkBox1->TabIndex = 31;
			this->checkBox1->Text = L"Ocupada";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(142)), static_cast<System::Int32>(static_cast<System::Byte>(157)),
				static_cast<System::Int32>(static_cast<System::Byte>(177)));
			this->label5->Location = System::Drawing::Point(28, 32);
			this->label5->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(119, 13);
			this->label5->TabIndex = 27;
			this->label5->Text = L"Tipo de pieza aceptada";
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(245)), static_cast<System::Int32>(static_cast<System::Byte>(158)),
				static_cast<System::Int32>(static_cast<System::Byte>(11)));
			this->label6->Location = System::Drawing::Point(28, 15);
			this->label6->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(123, 13);
			this->label6->TabIndex = 0;
			this->label6->Text = L"Agregar nueva estación:";
			// 
			// button6
			// 
			this->button6->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(245)), static_cast<System::Int32>(static_cast<System::Byte>(158)),
				static_cast<System::Int32>(static_cast<System::Byte>(11)));
			this->button6->FlatAppearance->BorderSize = 0;
			this->button6->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->button6->ForeColor = System::Drawing::Color::Black;
			this->button6->Location = System::Drawing::Point(34, 327);
			this->button6->Margin = System::Windows::Forms::Padding(2);
			this->button6->Name = L"button6";
			this->button6->Size = System::Drawing::Size(156, 33);
			this->button6->TabIndex = 37;
			this->button6->Text = L"Agregar estación";
			this->button6->UseVisualStyleBackColor = false;
			this->button6->Click += gcnew System::EventHandler(this, &Estaciones_de_Trabajo_Inventario::button6_Click);
			// 
			// button1
			// 
			this->button1->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(15)), static_cast<System::Int32>(static_cast<System::Byte>(23)),
				static_cast<System::Int32>(static_cast<System::Byte>(42)));
			this->button1->FlatAppearance->BorderColor = System::Drawing::SystemColors::Window;
			this->button1->FlatAppearance->BorderSize = 0;
			this->button1->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->button1->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(245)), static_cast<System::Int32>(static_cast<System::Byte>(158)),
				static_cast<System::Int32>(static_cast<System::Byte>(11)));
			this->button1->Location = System::Drawing::Point(220, 327);
			this->button1->Margin = System::Windows::Forms::Padding(2);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(156, 33);
			this->button1->TabIndex = 38;
			this->button1->Text = L"Cambiar Ocupada";
			this->button1->UseVisualStyleBackColor = false;
			this->button1->Click += gcnew System::EventHandler(this, &Estaciones_de_Trabajo_Inventario::button1_Click);
			// 
			// button2
			// 
			this->button2->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(192)), static_cast<System::Int32>(static_cast<System::Byte>(0)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			this->button2->FlatAppearance->BorderSize = 0;
			this->button2->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->button2->ForeColor = System::Drawing::Color::White;
			this->button2->Location = System::Drawing::Point(406, 327);
			this->button2->Margin = System::Windows::Forms::Padding(2);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(156, 33);
			this->button2->TabIndex = 39;
			this->button2->Text = L"Eliminar estación";
			this->button2->UseVisualStyleBackColor = false;
			this->button2->Click += gcnew System::EventHandler(this, &Estaciones_de_Trabajo_Inventario::button2_Click);
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(245)), static_cast<System::Int32>(static_cast<System::Byte>(158)),
				static_cast<System::Int32>(static_cast<System::Byte>(11)));
			this->label3->Location = System::Drawing::Point(32, 374);
			this->label3->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(121, 13);
			this->label3->TabIndex = 40;
			this->label3->Text = L"Diagrama de estaciones";
			// 
			// panel4
			// 
			this->panel4->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(15)), static_cast<System::Int32>(static_cast<System::Byte>(23)),
				static_cast<System::Int32>(static_cast<System::Byte>(42)));
			this->panel4->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->panel4->Controls->Add(this->panel3);
			this->panel4->Controls->Add(this->panel5);
			this->panel4->Controls->Add(this->panel6);
			this->panel4->Controls->Add(this->panel7);
			this->panel4->Controls->Add(this->panel8);
			this->panel4->Location = System::Drawing::Point(32, 398);
			this->panel4->Margin = System::Windows::Forms::Padding(2);
			this->panel4->Name = L"panel4";
			this->panel4->Size = System::Drawing::Size(603, 130);
			this->panel4->TabIndex = 41;
			// 
			// panel3
			// 
			this->panel3->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(40)), static_cast<System::Int32>(static_cast<System::Byte>(55)),
				static_cast<System::Int32>(static_cast<System::Byte>(80)));
			this->panel3->Location = System::Drawing::Point(8, 8);
			this->panel3->Margin = System::Windows::Forms::Padding(2);
			this->panel3->Name = L"panel3";
			this->panel3->Size = System::Drawing::Size(112, 114);
			this->panel3->TabIndex = 0;
			// 
			// panel5
			// 
			this->panel5->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(40)), static_cast<System::Int32>(static_cast<System::Byte>(55)),
				static_cast<System::Int32>(static_cast<System::Byte>(80)));
			this->panel5->Location = System::Drawing::Point(128, 8);
			this->panel5->Margin = System::Windows::Forms::Padding(2);
			this->panel5->Name = L"panel5";
			this->panel5->Size = System::Drawing::Size(112, 114);
			this->panel5->TabIndex = 1;
			// 
			// panel6
			// 
			this->panel6->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(50)), static_cast<System::Int32>(static_cast<System::Byte>(60)),
				static_cast<System::Int32>(static_cast<System::Byte>(80)));
			this->panel6->Location = System::Drawing::Point(248, 8);
			this->panel6->Margin = System::Windows::Forms::Padding(2);
			this->panel6->Name = L"panel6";
			this->panel6->Size = System::Drawing::Size(112, 114);
			this->panel6->TabIndex = 2;
			// 
			// panel7
			// 
			this->panel7->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(40)), static_cast<System::Int32>(static_cast<System::Byte>(55)),
				static_cast<System::Int32>(static_cast<System::Byte>(80)));
			this->panel7->Location = System::Drawing::Point(368, 8);
			this->panel7->Margin = System::Windows::Forms::Padding(2);
			this->panel7->Name = L"panel7";
			this->panel7->Size = System::Drawing::Size(112, 114);
			this->panel7->TabIndex = 3;
			// 
			// panel8
			// 
			this->panel8->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(40)), static_cast<System::Int32>(static_cast<System::Byte>(55)),
				static_cast<System::Int32>(static_cast<System::Byte>(80)));
			this->panel8->Location = System::Drawing::Point(484, 8);
			this->panel8->Margin = System::Windows::Forms::Padding(2);
			this->panel8->Name = L"panel8";
			this->panel8->Size = System::Drawing::Size(112, 114);
			this->panel8->TabIndex = 4;
			// 
			// Column1
			// 
			this->Column1->HeaderText = L"ID";
			this->Column1->MinimumWidth = 60;
			this->Column1->Name = L"Column1";
			this->Column1->ReadOnly = true;
			// 
			// Rol
			// 
			this->Rol->HeaderText = L"Tipo Pieza Aceptada";
			this->Rol->MinimumWidth = 150;
			this->Rol->Name = L"Rol";
			this->Rol->ReadOnly = true;
			// 
			// Column2
			// 
			this->Column2->HeaderText = L"Cant. Piezas";
			this->Column2->MinimumWidth = 80;
			this->Column2->Name = L"Column2";
			this->Column2->ReadOnly = true;
			// 
			// Estaciones_de_Trabajo_Inventario
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(22)), static_cast<System::Int32>(static_cast<System::Byte>(30)),
				static_cast<System::Int32>(static_cast<System::Byte>(46)));
			this->ClientSize = System::Drawing::Size(675, 552);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->dataGridView1);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->panel2);
			this->Controls->Add(this->button6);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->panel4);
			this->Margin = System::Windows::Forms::Padding(2);
			this->Name = L"Estaciones_de_Trabajo_Inventario";
			this->Text = L"Estaciones de Trabajo";
			this->Load += gcnew System::EventHandler(this, &Estaciones_de_Trabajo_Inventario::Estaciones_de_Trabajo_Inventario_Load_1);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->EndInit();
			this->panel2->ResumeLayout(false);
			this->panel1->ResumeLayout(false);
			this->panel1->PerformLayout();
			this->panel4->ResumeLayout(false);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

		void refrescarTabla()
		{
			dataGridView1->Rows->Clear();
			for each (EstacionTrabajoModel ^ e in estacionCtrl->obtenerTodos())
			{
				int n = dataGridView1->Rows->Add();
				dataGridView1->Rows[n]->Cells[0]->Value = e->Id;
				String^ tipoStr = e->Tipo == TipoEstacion::PANEL_IZQ ? "Panel Izq" :
					e->Tipo == TipoEstacion::PANEL_DER ? "Panel Der" : "Techo";
				dataGridView1->Rows[n]->Cells[1]->Value = tipoStr;
				dataGridView1->Rows[n]->Cells[2]->Value = e->CantidadPiezas;
				dataGridView1->Rows[n]->Cells[2]->Style->ForeColor =
					e->CantidadPiezas > 0
					? Color::FromArgb(245, 158, 11)
					: Color::FromArgb(0, 200, 100);
			}
		}

		void ActualizarDiagrama()
		{
			array<Panel^>^ slots = gcnew array<Panel^>(5) {
				panel3, panel5, panel6, panel7, panel8
			};

			// Limpiar todos
			for each (Panel ^ p in slots)
			{
				p->Controls->Clear();
				p->BackColor = Color::FromArgb(40, 55, 80);
			}

			// Slot central fijo — chasis
			panel6->BackColor = Color::FromArgb(50, 60, 80);
			Label^ lblChasis = gcnew Label();
			lblChasis->Text = "[CHASIS]";
			lblChasis->ForeColor = Color::FromArgb(100, 120, 150);
			lblChasis->AutoSize = false;
			lblChasis->Size = panel6->Size;
			lblChasis->TextAlign = ContentAlignment::MiddleCenter;
			lblChasis->Font = gcnew System::Drawing::Font(L"Segoe UI", 8.0F,
				FontStyle::Regular, GraphicsUnit::Point, static_cast<Byte>(0));
			panel6->Controls->Add(lblChasis);

			// Slots de estaciones (excluyendo el central)
			array<Panel^>^ slotsEst = gcnew array<Panel^>(4) {
				panel3, panel5, panel7, panel8
			};

			List<EstacionTrabajoModel^>^ lista = estacionCtrl->obtenerTodos();
			for (int i = 0; i < lista->Count && i < 4; i++)
			{
				EstacionTrabajoModel^ e = lista[i];
				Panel^ slot = slotsEst[i];

				slot->BackColor = e->CantidadPiezas > 0
					? Color::FromArgb(180, 100, 0)
					: Color::FromArgb(40, 55, 80);

				Label^ lblNombre = gcnew Label();
				lblNombre->Text = "Est. " + e->Id;
				lblNombre->ForeColor = Color::White;
				lblNombre->AutoSize = false;
				lblNombre->Size = System::Drawing::Size(slot->Width, 36);
				lblNombre->Location = System::Drawing::Point(0, 14);
				lblNombre->TextAlign = ContentAlignment::MiddleCenter;
				lblNombre->Font = gcnew System::Drawing::Font(L"Segoe UI", 8.0F,
					FontStyle::Bold, GraphicsUnit::Point, static_cast<System::Byte>(0));

				Label^ lblTipo = gcnew Label();
				String^ tipoStr = e->Tipo == TipoEstacion::PANEL_IZQ ? "Panel Izq" :
					e->Tipo == TipoEstacion::PANEL_DER ? "Panel Der" : "Techo";
				lblTipo->Text = tipoStr + " (" + e->CantidadPiezas + ")";
				lblTipo->ForeColor = e->CantidadPiezas > 0
					? Color::FromArgb(255, 200, 100)
					: Color::FromArgb(160, 180, 210);
				lblTipo->AutoSize = false;
				lblTipo->Size = System::Drawing::Size(slot->Width, 24);
				lblTipo->Location = System::Drawing::Point(0, 46);
				lblTipo->TextAlign = ContentAlignment::MiddleCenter;
				lblTipo->Font = gcnew System::Drawing::Font(L"Segoe UI", 7.5F,
					FontStyle::Regular, GraphicsUnit::Point, static_cast<Byte>(0));

				slot->Controls->Add(lblNombre);
				slot->Controls->Add(lblTipo);
			}
		}

	private: System::Void Estaciones_de_Trabajo_Inventario_Load(
		System::Object^ sender, System::EventArgs^ e) {
	}

	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e)
	{
		String^ id = dataGridView1->SelectedRows[0]->Cells[0]->Value->ToString();
		EstacionTrabajoModel^ est = estacionCtrl->buscarPorId(id);
		if (est != nullptr)
		{
			int nueva = est->CantidadPiezas + 1;
			estacionCtrl->modificar(est->Id, est->Tipo, nueva);
			refrescarTabla();
			ActualizarDiagrama();
		}
	}

	private: System::Void button6_Click(System::Object^ sender, System::EventArgs^ e)
	{
		// comboBox1 debe tener items: "Panel Izquierdo", "Panel Derecho", "Techo"
		if (comboBox1->SelectedIndex < 0)
		{
			MessageBox::Show(L"Seleccione el tipo de pieza.", L"Error",
				MessageBoxButtons::OK, MessageBoxIcon::Warning);
			return;
		}
		TipoEstacion tipo = comboBox1->SelectedIndex == 0 ? TipoEstacion::PANEL_IZQ :
			comboBox1->SelectedIndex == 1 ? TipoEstacion::PANEL_DER :
			TipoEstacion::TECHO;
		int sigId = estacionCtrl->obtenerTodos()->Count + 1;
		String^ idStr = L"EST-" + sigId.ToString("D3");
		if (estacionCtrl->agregar(idStr, tipo, 0))
		{
		
			checkBox1->Checked = false;
			refrescarTabla();
			ActualizarDiagrama();
			MessageBox::Show(L"Estación agregada con éxito.", L"Éxito",
				MessageBoxButtons::OK, MessageBoxIcon::Information);
		}
		else
		{
			MessageBox::Show(L"Error al guardar la estación.", L"Error",
				MessageBoxButtons::OK, MessageBoxIcon::Error);
		}
	}

	private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e)
	{
		if (dataGridView1->SelectedRows->Count == 0)
		{
			MessageBox::Show(L"Seleccione una estación para eliminar.", L"Aviso",
				MessageBoxButtons::OK, MessageBoxIcon::Warning);
			return;
		}
		String^ id = dataGridView1->SelectedRows[0]->Cells[0]->Value->ToString();
		System::Windows::Forms::DialogResult res = MessageBox::Show(
			L"¿Eliminar la estación " + id + L"?", L"Confirmar",
			MessageBoxButtons::YesNo, MessageBoxIcon::Question);
		if (res == System::Windows::Forms::DialogResult::Yes)
		{
			if (estacionCtrl->eliminar(id))
			{
				refrescarTabla();
				ActualizarDiagrama();
			}
			else
			{
				MessageBox::Show(L"No se pudo eliminar.", L"Error",
					MessageBoxButtons::OK, MessageBoxIcon::Error);
			}
		}
	}
	private: System::Void Estaciones_de_Trabajo_Inventario_Load_1(System::Object^ sender, System::EventArgs^ e) {
	}
private: System::Void dataGridView1_CellContentClick(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e) {
}
};
}