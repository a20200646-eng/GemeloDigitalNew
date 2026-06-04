#pragma once
using namespace GemeloDigitalController;
using namespace GemeloDigitalModel;
namespace LOGIN {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Collections::Generic;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

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
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Column1;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Rol;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Column2;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Panel^ panel2;
	private: System::Windows::Forms::Panel^ panel1;
	private: System::Windows::Forms::CheckBox^ checkBox1;
	private: System::Windows::Forms::TextBox^ textBox1;
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

	private:
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		void InitializeComponent(void)
		{
			System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle1 =
				(gcnew System::Windows::Forms::DataGridViewCellStyle());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
			this->Column1 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Rol = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column2 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->panel2 = (gcnew System::Windows::Forms::Panel());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->checkBox1 = (gcnew System::Windows::Forms::CheckBox());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->button6 = (gcnew System::Windows::Forms::Button());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->panel4 = (gcnew System::Windows::Forms::Panel());
			this->panel8 = (gcnew System::Windows::Forms::Panel());
			this->panel7 = (gcnew System::Windows::Forms::Panel());
			this->panel6 = (gcnew System::Windows::Forms::Panel());
			this->panel5 = (gcnew System::Windows::Forms::Panel());
			this->panel3 = (gcnew System::Windows::Forms::Panel());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(
				this->dataGridView1))->BeginInit();
			this->panel2->SuspendLayout();
			this->panel1->SuspendLayout();
			this->panel4->SuspendLayout();
			this->SuspendLayout();

			// label1
			this->label1->AutoSize = true;
			this->label1->ForeColor = Color::FromArgb(245, 158, 11);
			this->label1->Location = System::Drawing::Point(43, 54);
			this->label1->Name = L"label1";
			this->label1->TabIndex = 1;
			this->label1->Text = L"Estaciones configuradas";

			// dataGridView1
			this->dataGridView1->AutoSizeColumnsMode =
				System::Windows::Forms::DataGridViewAutoSizeColumnsMode::Fill;
			this->dataGridView1->BackgroundColor = Color::FromArgb(15, 23, 42);
			this->dataGridView1->ColumnHeadersBorderStyle =
				System::Windows::Forms::DataGridViewHeaderBorderStyle::Single;
			this->dataGridView1->ColumnHeadersHeightSizeMode =
				System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView1->Columns->AddRange(
				gcnew cli::array<System::Windows::Forms::DataGridViewColumn^>(3) {
				this->Column1, this->Rol, this->Column2
			});
			this->dataGridView1->EnableHeadersVisualStyles = false;
			this->dataGridView1->GridColor =
				System::Drawing::SystemColors::ActiveCaptionText;
			this->dataGridView1->Location = System::Drawing::Point(45, 81);
			this->dataGridView1->Name = L"dataGridView1";
			dataGridViewCellStyle1->BackColor = Color::FromArgb(30, 58, 95);
			dataGridViewCellStyle1->ForeColor =
				System::Drawing::SystemColors::WindowText;
			dataGridViewCellStyle1->SelectionBackColor =
				System::Drawing::SystemColors::Highlight;
			dataGridViewCellStyle1->SelectionForeColor =
				System::Drawing::SystemColors::HighlightText;
			this->dataGridView1->RowHeadersDefaultCellStyle = dataGridViewCellStyle1;
			this->dataGridView1->RowHeadersVisible = false;
			this->dataGridView1->ReadOnly = true;
			this->dataGridView1->SelectionMode =
				System::Windows::Forms::DataGridViewSelectionMode::FullRowSelect;
			this->dataGridView1->RowTemplate->Height = 24;
			this->dataGridView1->Size = System::Drawing::Size(802, 133);
			this->dataGridView1->TabIndex = 28;

			// Estilo header
			System::Windows::Forms::DataGridViewCellStyle^ estiloHeader =
				gcnew System::Windows::Forms::DataGridViewCellStyle();
			estiloHeader->BackColor = Color::FromArgb(15, 22, 32);
			estiloHeader->ForeColor = Color::FromArgb(245, 158, 11);
			estiloHeader->Font = gcnew System::Drawing::Font(L"Segoe UI", 9.0F,
				FontStyle::Bold, GraphicsUnit::Point, static_cast<Byte>(0));
			this->dataGridView1->ColumnHeadersDefaultCellStyle = estiloHeader;

			// Column1 — ID
			this->Column1->HeaderText = L"ID";
			this->Column1->Name = L"Column1";
			this->Column1->MinimumWidth = 60;

			// Rol — Tipo Pieza
			this->Rol->HeaderText = L"Tipo Pieza Aceptada";
			this->Rol->Name = L"Rol";
			this->Rol->MinimumWidth = 150;

			// Column2 — Ocupada
			this->Column2->HeaderText = L"Ocupada";
			this->Column2->Name = L"Column2";
			this->Column2->MinimumWidth = 80;

			// label2
			this->label2->AutoSize = true;
			this->label2->ForeColor = Color::FromArgb(245, 158, 11);
			this->label2->Location = System::Drawing::Point(43, 241);
			this->label2->Name = L"label2";
			this->label2->TabIndex = 29;
			this->label2->Text = L"Agregar estación de trabajo";

			// panel2 (borde naranja)
			this->panel2->BackColor = Color::FromArgb(245, 158, 11);
			this->panel2->BorderStyle =
				System::Windows::Forms::BorderStyle::FixedSingle;
			this->panel2->Controls->Add(this->panel1);
			this->panel2->Location = System::Drawing::Point(42, 273);
			this->panel2->Name = L"panel2";
			this->panel2->Size = System::Drawing::Size(803, 125);
			this->panel2->TabIndex = 36;

			// panel1 (fondo oscuro dentro del panel2)
			this->panel1->BackColor = Color::FromArgb(15, 23, 42);
			this->panel1->BorderStyle =
				System::Windows::Forms::BorderStyle::FixedSingle;
			this->panel1->Controls->Add(this->checkBox1);
			this->panel1->Controls->Add(this->textBox1);
			this->panel1->Controls->Add(this->label5);
			this->panel1->Controls->Add(this->label6);
			this->panel1->Location = System::Drawing::Point(2, 2);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(797, 117);
			this->panel1->TabIndex = 28;

			// checkBox1
			this->checkBox1->AutoSize = true;
			this->checkBox1->ForeColor = Color::White;
			this->checkBox1->Location = System::Drawing::Point(366, 67);
			this->checkBox1->Name = L"checkBox1";
			this->checkBox1->TabIndex = 31;
			this->checkBox1->Text = L"Ocupada";

			// textBox1
			this->textBox1->BackColor = Color::FromArgb(30, 41, 59);
			this->textBox1->BorderStyle =
				System::Windows::Forms::BorderStyle::FixedSingle;
			this->textBox1->ForeColor = Color::White;
			this->textBox1->Location = System::Drawing::Point(39, 66);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(306, 20);
			this->textBox1->TabIndex = 30;

			// label5
			this->label5->AutoSize = true;
			this->label5->ForeColor = Color::FromArgb(142, 157, 177);
			this->label5->Location = System::Drawing::Point(37, 40);
			this->label5->Name = L"label5";
			this->label5->TabIndex = 27;
			this->label5->Text = L"Tipo de pieza aceptada";

			// label6
			this->label6->AutoSize = true;
			this->label6->ForeColor = Color::FromArgb(245, 158, 11);
			this->label6->Location = System::Drawing::Point(37, 19);
			this->label6->Name = L"label6";
			this->label6->TabIndex = 0;
			this->label6->Text = L"Agregar nueva estación:";

			// button6 — Agregar estación
			this->button6->BackColor = Color::FromArgb(245, 158, 11);
			this->button6->FlatAppearance->BorderSize = 0;
			this->button6->FlatStyle =
				System::Windows::Forms::FlatStyle::Popup;
			this->button6->ForeColor = Color::Black;
			this->button6->Location = System::Drawing::Point(46, 402);
			this->button6->Name = L"button6";
			this->button6->Size = System::Drawing::Size(208, 41);
			this->button6->TabIndex = 37;
			this->button6->Text = L"Agregar estación";
			this->button6->UseVisualStyleBackColor = false;
			this->button6->Click += gcnew EventHandler(this,
				&Estaciones_de_Trabajo_Inventario::button6_Click);

			// button1 — Cambiar Ocupada
			this->button1->BackColor = Color::FromArgb(15, 23, 42);
			this->button1->FlatAppearance->BorderColor =
				System::Drawing::SystemColors::Window;
			this->button1->FlatAppearance->BorderSize = 0;
			this->button1->FlatStyle =
				System::Windows::Forms::FlatStyle::Popup;
			this->button1->ForeColor = Color::FromArgb(245, 158, 11);
			this->button1->Location = System::Drawing::Point(294, 402);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(208, 41);
			this->button1->TabIndex = 38;
			this->button1->Text = L"Cambiar Ocupada";
			this->button1->UseVisualStyleBackColor = false;
			this->button1->Click += gcnew EventHandler(this,
				&Estaciones_de_Trabajo_Inventario::button1_Click);

			// button2 — Eliminar
			this->button2->BackColor = Color::FromArgb(192, 0, 0);
			this->button2->FlatAppearance->BorderSize = 0;
			this->button2->FlatStyle =
				System::Windows::Forms::FlatStyle::Popup;
			this->button2->ForeColor = Color::White;
			this->button2->Location = System::Drawing::Point(548, 402);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(208, 41);
			this->button2->TabIndex = 39;
			this->button2->Text = L"Eliminar";
			this->button2->UseVisualStyleBackColor = false;
			this->button2->Click += gcnew EventHandler(this,
				&Estaciones_de_Trabajo_Inventario::button2_Click);

			// label3
			this->label3->AutoSize = true;
			this->label3->ForeColor = Color::FromArgb(245, 158, 11);
			this->label3->Location = System::Drawing::Point(42, 464);
			this->label3->Name = L"label3";
			this->label3->TabIndex = 40;
			this->label3->Text = L"Diagrama de posiciones físicas (referencia)";

			// panel4 — contenedor diagrama
			this->panel4->BackColor = Color::FromArgb(15, 23, 42);
			this->panel4->BorderStyle =
				System::Windows::Forms::BorderStyle::FixedSingle;
			this->panel4->Controls->Add(this->panel8);
			this->panel4->Controls->Add(this->panel7);
			this->panel4->Controls->Add(this->panel6);
			this->panel4->Controls->Add(this->panel5);
			this->panel4->Controls->Add(this->panel3);
			this->panel4->Location = System::Drawing::Point(42, 489);
			this->panel4->Name = L"panel4";
			this->panel4->Size = System::Drawing::Size(797, 117);
			this->panel4->TabIndex = 32;

			// Slots del diagrama
			this->panel3->Location = System::Drawing::Point(12, 25);
			this->panel3->Size = System::Drawing::Size(140, 72);
			this->panel3->TabIndex = 0;
			this->panel5->Location = System::Drawing::Point(167, 25);
			this->panel5->Size = System::Drawing::Size(140, 72);
			this->panel5->TabIndex = 1;
			this->panel6->Location = System::Drawing::Point(319, 25);
			this->panel6->Size = System::Drawing::Size(140, 72);
			this->panel6->TabIndex = 1;
			this->panel7->Location = System::Drawing::Point(471, 25);
			this->panel7->Size = System::Drawing::Size(140, 72);
			this->panel7->TabIndex = 1;
			this->panel8->Location = System::Drawing::Point(624, 25);
			this->panel8->Size = System::Drawing::Size(140, 72);
			this->panel8->TabIndex = 1;

			// Form
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode =
				System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = Color::FromArgb(30, 40, 58);
			this->ClientSize = System::Drawing::Size(986, 640);
			this->Controls->Add(this->panel4);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->button6);
			this->Controls->Add(this->panel2);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->dataGridView1);
			this->Controls->Add(this->label1);
			this->Name = L"Estaciones_de_Trabajo_Inventario";
			this->Text = L"Estaciones_de_Trabajo_Inventario";
			this->Load += gcnew EventHandler(this,
				&Estaciones_de_Trabajo_Inventario::Estaciones_de_Trabajo_Inventario_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(
				this->dataGridView1))->EndInit();
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
				dataGridView1->Rows[n]->Cells[1]->Value = e->TipoPiezaAceptada;
				dataGridView1->Rows[n]->Cells[2]->Value = e->Ocupada ? L"SÍ" : L"NO";
				// Colorear columna Ocupada
				dataGridView1->Rows[n]->Cells[2]->Style->ForeColor =
					e->Ocupada
					? Color::FromArgb(245, 158, 11)  // naranja
					: Color::FromArgb(0, 200, 100);  // verde
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

				slot->BackColor = e->Ocupada
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
					FontStyle::Bold, GraphicsUnit::Point, static_cast<Byte>(0));

				Label^ lblTipo = gcnew Label();
				lblTipo->Text = e->TipoPiezaAceptada;
				lblTipo->ForeColor = e->Ocupada
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
		if (dataGridView1->SelectedRows->Count == 0)
		{
			MessageBox::Show(L"Seleccione una estación de la lista para modificar.",
				L"Aviso", MessageBoxButtons::OK, MessageBoxIcon::Warning);
			return;
		}
		String^ id = dataGridView1->SelectedRows[0]->Cells[0]->Value->ToString();
		EstacionTrabajoModel^ est = estacionCtrl->buscarPorId(id);
		if (est != nullptr)
		{
			estacionCtrl->modificar(est->Id, est->TipoPiezaAceptada, !est->Ocupada);
			refrescarTabla();
			ActualizarDiagrama();
		}
	}

	private: System::Void button6_Click(System::Object^ sender, System::EventArgs^ e)
	{
		String^ tipoPieza = textBox1->Text->Trim();
		if (tipoPieza->Length == 0)
		{
			MessageBox::Show(L"Ingrese el tipo de pieza aceptada.", L"Error",
				MessageBoxButtons::OK, MessageBoxIcon::Warning);
			return;
		}
		int sigId = estacionCtrl->obtenerTodos()->Count + 1;
		String^ idStr = L"EST-" + sigId.ToString("D3");
		if (estacionCtrl->agregar(idStr, tipoPieza, checkBox1->Checked))
		{
			textBox1->Clear();
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
	};
}