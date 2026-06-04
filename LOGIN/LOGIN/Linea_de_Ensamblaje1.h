#pragma once
using namespace GemeloDigitalController;
using namespace GemeloDigitalModel;

namespace LOGIN {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections::Generic;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	public ref class Linea_de_Ensamblaje1 : public System::Windows::Forms::Form
	{
	private:
		LineaEnsamblajeController^ ctrlLinea;
		PanelLateralController^ ctrlPanel;
		EstructuraTechoController^ ctrlTecho;

	public:
		Linea_de_Ensamblaje1(void)
		{
			InitializeComponent();
			ctrlLinea = gcnew LineaEnsamblajeController();
			ctrlPanel = gcnew PanelLateralController();
			ctrlTecho = gcnew EstructuraTechoController();
			this->Load += gcnew EventHandler(this, &Linea_de_Ensamblaje1::Form_Load);
		}

	protected:
		~Linea_de_Ensamblaje1()
		{
			if (components) delete components;
		}

	private:
		System::ComponentModel::Container^ components;

		// Controles
		System::Windows::Forms::Label^ labelTitulo;
		System::Windows::Forms::Label^ labelSecLineas;
		System::Windows::Forms::DataGridView^ dgvLineas;
		System::Windows::Forms::DataGridViewTextBoxColumn^ colLineaId;
		System::Windows::Forms::DataGridViewTextBoxColumn^ colLineaIndice;
		System::Windows::Forms::DataGridViewTextBoxColumn^ colLineaSecuencia;
		System::Windows::Forms::Button^ btnNuevaLinea;
		System::Windows::Forms::Panel^ panelDetalle;
		System::Windows::Forms::Label^ labelLineaSel;
		System::Windows::Forms::Label^ labelSecuenciaHdr;
		System::Windows::Forms::Button^ btnSecuencia;
		System::Windows::Forms::Label^ labelSecuenciaNota;
		System::Windows::Forms::Label^ labelSecCola;
		System::Windows::Forms::DataGridView^ dgvCola;
		System::Windows::Forms::DataGridViewTextBoxColumn^ colPos;
		System::Windows::Forms::DataGridViewTextBoxColumn^ colTipo;
		System::Windows::Forms::DataGridViewTextBoxColumn^ colPiezaId;
		System::Windows::Forms::DataGridViewTextBoxColumn^ colMaterial;
		System::Windows::Forms::DataGridViewTextBoxColumn^ colEstado;
		System::Windows::Forms::Label^ labelSecAgregar;
		System::Windows::Forms::Panel^ panelAgregar;
		System::Windows::Forms::Label^ labelSelPieza;
		System::Windows::Forms::ComboBox^ comboBoxPiezas;
		System::Windows::Forms::Button^ btnAgregarCola;
		System::Windows::Forms::Panel^ panelNota;
		System::Windows::Forms::Label^ labelNota;
		System::Windows::Forms::Label^ labelSecFlujo;
		System::Windows::Forms::Panel^ panelFlujo;

#pragma region Windows Form Designer generated code
		void InitializeComponent(void)
		{
			this->labelTitulo = gcnew System::Windows::Forms::Label();
			this->labelSecLineas = gcnew System::Windows::Forms::Label();
			this->dgvLineas = gcnew System::Windows::Forms::DataGridView();
			this->colLineaId = gcnew System::Windows::Forms::DataGridViewTextBoxColumn();
			this->colLineaIndice = gcnew System::Windows::Forms::DataGridViewTextBoxColumn();
			this->colLineaSecuencia = gcnew System::Windows::Forms::DataGridViewTextBoxColumn();
			this->btnNuevaLinea = gcnew System::Windows::Forms::Button();
			this->panelDetalle = gcnew System::Windows::Forms::Panel();
			this->labelLineaSel = gcnew System::Windows::Forms::Label();
			this->labelSecuenciaHdr = gcnew System::Windows::Forms::Label();
			this->btnSecuencia = gcnew System::Windows::Forms::Button();
			this->labelSecuenciaNota = gcnew System::Windows::Forms::Label();
			this->labelSecCola = gcnew System::Windows::Forms::Label();
			this->dgvCola = gcnew System::Windows::Forms::DataGridView();
			this->colPos = gcnew System::Windows::Forms::DataGridViewTextBoxColumn();
			this->colTipo = gcnew System::Windows::Forms::DataGridViewTextBoxColumn();
			this->colPiezaId = gcnew System::Windows::Forms::DataGridViewTextBoxColumn();
			this->colMaterial = gcnew System::Windows::Forms::DataGridViewTextBoxColumn();
			this->colEstado = gcnew System::Windows::Forms::DataGridViewTextBoxColumn();
			this->labelSecAgregar = gcnew System::Windows::Forms::Label();
			this->panelAgregar = gcnew System::Windows::Forms::Panel();
			this->labelSelPieza = gcnew System::Windows::Forms::Label();
			this->comboBoxPiezas = gcnew System::Windows::Forms::ComboBox();
			this->btnAgregarCola = gcnew System::Windows::Forms::Button();
			this->panelNota = gcnew System::Windows::Forms::Panel();
			this->labelNota = gcnew System::Windows::Forms::Label();
			this->labelSecFlujo = gcnew System::Windows::Forms::Label();
			this->panelFlujo = gcnew System::Windows::Forms::Panel();

			this->panelDetalle->SuspendLayout();
			this->panelAgregar->SuspendLayout();
			this->panelNota->SuspendLayout();
			this->panelFlujo->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgvLineas))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgvCola))->BeginInit();
			this->SuspendLayout();

			System::Drawing::Color fondoForm = System::Drawing::Color::FromArgb(18, 26, 38);
			System::Drawing::Color fondoPanel = System::Drawing::Color::FromArgb(28, 38, 54);
			System::Drawing::Color acento = System::Drawing::Color::FromArgb(230, 160, 0);
			System::Drawing::Color textoPrinc = System::Drawing::Color::White;
			System::Drawing::Color textoSec = System::Drawing::Color::FromArgb(160, 180, 210);

			// ---- labelTitulo ----
			this->labelTitulo->AutoSize = true;
			this->labelTitulo->Font = gcnew System::Drawing::Font(L"Segoe UI", 14.0F,
				FontStyle::Bold, GraphicsUnit::Point, static_cast<Byte>(0));
			this->labelTitulo->ForeColor = textoPrinc;
			this->labelTitulo->Location = System::Drawing::Point(20, 16);
			this->labelTitulo->Text = L"Líneas de Ensamblaje";

			// ---- labelSecLineas ----
			this->labelSecLineas->AutoSize = true;
			this->labelSecLineas->Font = gcnew System::Drawing::Font(L"Segoe UI", 9.0F,
				FontStyle::Bold, GraphicsUnit::Point, static_cast<Byte>(0));
			this->labelSecLineas->ForeColor = acento;
			this->labelSecLineas->Location = System::Drawing::Point(20, 52);
			this->labelSecLineas->Text = L"Líneas configuradas";

			// ---- dgvLineas ----
			System::Windows::Forms::DataGridViewCellStyle^ estCelda =
				gcnew System::Windows::Forms::DataGridViewCellStyle();
			estCelda->BackColor = fondoPanel;
			estCelda->ForeColor = textoPrinc;
			estCelda->SelectionBackColor = System::Drawing::Color::FromArgb(50, 80, 120);
			estCelda->SelectionForeColor = textoPrinc;

			System::Windows::Forms::DataGridViewCellStyle^ estHeader =
				gcnew System::Windows::Forms::DataGridViewCellStyle();
			estHeader->BackColor = System::Drawing::Color::FromArgb(15, 22, 32);
			estHeader->ForeColor = acento;
			estHeader->Font = gcnew System::Drawing::Font(L"Segoe UI", 9.0F,
				FontStyle::Bold, GraphicsUnit::Point, static_cast<Byte>(0));

			this->dgvLineas->BackgroundColor = fondoPanel;
			this->dgvLineas->GridColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->dgvLineas->DefaultCellStyle = estCelda;
			this->dgvLineas->ColumnHeadersDefaultCellStyle = estHeader;
			this->dgvLineas->ColumnHeadersBorderStyle =
				System::Windows::Forms::DataGridViewHeaderBorderStyle::Single;
			this->dgvLineas->ColumnHeadersHeightSizeMode =
				System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dgvLineas->EnableHeadersVisualStyles = false;
			this->dgvLineas->RowHeadersVisible = false;
			this->dgvLineas->ReadOnly = true;
			this->dgvLineas->AllowUserToAddRows = false;
			this->dgvLineas->MultiSelect = false;
			this->dgvLineas->SelectionMode =
				System::Windows::Forms::DataGridViewSelectionMode::FullRowSelect;
			this->dgvLineas->AutoSizeColumnsMode =
				System::Windows::Forms::DataGridViewAutoSizeColumnsMode::Fill;
			this->dgvLineas->Location = System::Drawing::Point(20, 72);
			this->dgvLineas->Size = System::Drawing::Size(660, 100);
			this->dgvLineas->RowTemplate->Height = 28;

			this->colLineaId->HeaderText = L"ID";
			this->colLineaId->Name = L"colLineaId";
			this->colLineaId->MinimumWidth = 60;
			this->colLineaIndice->HeaderText = L"Índice Actual";
			this->colLineaIndice->Name = L"colLineaIndice";
			this->colLineaSecuencia->HeaderText = L"Secuencia Aprobada";
			this->colLineaSecuencia->Name = L"colLineaSecuencia";

			this->dgvLineas->Columns->Add(colLineaId);
			this->dgvLineas->Columns->Add(colLineaIndice);
			this->dgvLineas->Columns->Add(colLineaSecuencia);

			this->dgvLineas->SelectionChanged += gcnew EventHandler(this,
				&Linea_de_Ensamblaje1::dgvLineas_SelectionChanged);

			// ---- btnNuevaLinea ----
			this->btnNuevaLinea->BackColor = acento;
			this->btnNuevaLinea->ForeColor = System::Drawing::Color::Black;
			this->btnNuevaLinea->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->btnNuevaLinea->Font = gcnew System::Drawing::Font(L"Segoe UI", 9.0F,
				FontStyle::Bold, GraphicsUnit::Point, static_cast<Byte>(0));
			this->btnNuevaLinea->Location = System::Drawing::Point(20, 182);
			this->btnNuevaLinea->Size = System::Drawing::Size(140, 34);
			this->btnNuevaLinea->Text = L"Nueva línea";
			this->btnNuevaLinea->UseVisualStyleBackColor = false;
			this->btnNuevaLinea->Click += gcnew EventHandler(this,
				&Linea_de_Ensamblaje1::btnNuevaLinea_Click);

			// ---- panelDetalle ----
			this->panelDetalle->BackColor = fondoPanel;
			this->panelDetalle->BorderStyle =
				System::Windows::Forms::BorderStyle::FixedSingle;
			this->panelDetalle->Location = System::Drawing::Point(700, 72);
			this->panelDetalle->Size = System::Drawing::Size(460, 100);

			this->labelLineaSel->AutoSize = true;
			this->labelLineaSel->Font = gcnew System::Drawing::Font(L"Segoe UI", 9.0F,
				FontStyle::Bold, GraphicsUnit::Point, static_cast<Byte>(0));
			this->labelLineaSel->ForeColor = textoPrinc;
			this->labelLineaSel->Location = System::Drawing::Point(10, 10);
			this->labelLineaSel->Text = L"Línea seleccionada: —";

			this->labelSecuenciaHdr->AutoSize = true;
			this->labelSecuenciaHdr->ForeColor = textoSec;
			this->labelSecuenciaHdr->Location = System::Drawing::Point(10, 40);
			this->labelSecuenciaHdr->Text = L"Secuencia:";

			this->btnSecuencia->Location = System::Drawing::Point(90, 34);
			this->btnSecuencia->Size = System::Drawing::Size(130, 28);
			this->btnSecuencia->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->btnSecuencia->Font = gcnew System::Drawing::Font(L"Segoe UI", 9.0F,
				FontStyle::Bold, GraphicsUnit::Point, static_cast<Byte>(0));
			this->btnSecuencia->Text = L"PENDIENTE";
			this->btnSecuencia->UseVisualStyleBackColor = false;

			this->labelSecuenciaNota->AutoSize = true;
			this->labelSecuenciaNota->ForeColor = textoSec;
			this->labelSecuenciaNota->Font = gcnew System::Drawing::Font(L"Segoe UI", 8.0F,
				FontStyle::Italic, GraphicsUnit::Point, static_cast<Byte>(0));
			this->labelSecuenciaNota->Location = System::Drawing::Point(230, 40);
			this->labelSecuenciaNota->Text = L"(El Jefe debe aprobarla)";

			this->panelDetalle->Controls->Add(this->labelLineaSel);
			this->panelDetalle->Controls->Add(this->labelSecuenciaHdr);
			this->panelDetalle->Controls->Add(this->btnSecuencia);
			this->panelDetalle->Controls->Add(this->labelSecuenciaNota);

			// ---- labelSecCola ----
			this->labelSecCola->AutoSize = true;
			this->labelSecCola->Font = gcnew System::Drawing::Font(L"Segoe UI", 9.0F,
				FontStyle::Bold, GraphicsUnit::Point, static_cast<Byte>(0));
			this->labelSecCola->ForeColor = acento;
			this->labelSecCola->Location = System::Drawing::Point(20, 228);
			this->labelSecCola->Text = L"Cola de piezas — Línea #—";

			// ---- dgvCola ----
			this->dgvCola->BackgroundColor = fondoPanel;
			this->dgvCola->GridColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->dgvCola->DefaultCellStyle = estCelda;
			this->dgvCola->ColumnHeadersDefaultCellStyle = estHeader;
			this->dgvCola->ColumnHeadersBorderStyle =
				System::Windows::Forms::DataGridViewHeaderBorderStyle::Single;
			this->dgvCola->ColumnHeadersHeightSizeMode =
				System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dgvCola->EnableHeadersVisualStyles = false;
			this->dgvCola->RowHeadersVisible = false;
			this->dgvCola->ReadOnly = true;
			this->dgvCola->AllowUserToAddRows = false;
			this->dgvCola->AutoSizeColumnsMode =
				System::Windows::Forms::DataGridViewAutoSizeColumnsMode::Fill;
			this->dgvCola->Location = System::Drawing::Point(20, 250);
			this->dgvCola->Size = System::Drawing::Size(1140, 160);
			this->dgvCola->RowTemplate->Height = 28;

			this->colPos->HeaderText = L"Pos.";
			this->colPos->Name = L"colPos";
			this->colPos->MinimumWidth = 50;
			this->colTipo->HeaderText = L"Tipo";
			this->colTipo->Name = L"colTipo";
			this->colPiezaId->HeaderText = L"ID Pieza";
			this->colPiezaId->Name = L"colPiezaId";
			this->colMaterial->HeaderText = L"Material";
			this->colMaterial->Name = L"colMaterial";
			this->colEstado->HeaderText = L"Estado";
			this->colEstado->Name = L"colEstado";

			this->dgvCola->Columns->Add(colPos);
			this->dgvCola->Columns->Add(colTipo);
			this->dgvCola->Columns->Add(colPiezaId);
			this->dgvCola->Columns->Add(colMaterial);
			this->dgvCola->Columns->Add(colEstado);

			// ---- labelSecAgregar ----
			this->labelSecAgregar->AutoSize = true;
			this->labelSecAgregar->Font = gcnew System::Drawing::Font(L"Segoe UI", 9.0F,
				FontStyle::Bold, GraphicsUnit::Point, static_cast<Byte>(0));
			this->labelSecAgregar->ForeColor = acento;
			this->labelSecAgregar->Location = System::Drawing::Point(20, 424);
			this->labelSecAgregar->Text = L"Agregar pieza a la cola";

			// ---- panelAgregar ----
			this->panelAgregar->BackColor = fondoPanel;
			this->panelAgregar->BorderStyle =
				System::Windows::Forms::BorderStyle::FixedSingle;
			this->panelAgregar->Location = System::Drawing::Point(20, 448);
			this->panelAgregar->Size = System::Drawing::Size(1140, 60);

			this->labelSelPieza->AutoSize = true;
			this->labelSelPieza->ForeColor = textoSec;
			this->labelSelPieza->Location = System::Drawing::Point(10, 22);
			this->labelSelPieza->Text = L"Seleccionar pieza:";

			this->comboBoxPiezas->BackColor = System::Drawing::Color::FromArgb(30, 41, 59);
			this->comboBoxPiezas->ForeColor = textoPrinc;
			this->comboBoxPiezas->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->comboBoxPiezas->Location = System::Drawing::Point(120, 18);
			this->comboBoxPiezas->Size = System::Drawing::Size(700, 24);
			this->comboBoxPiezas->DropDownStyle =
				System::Windows::Forms::ComboBoxStyle::DropDownList;

			this->btnAgregarCola->BackColor = acento;
			this->btnAgregarCola->ForeColor = System::Drawing::Color::Black;
			this->btnAgregarCola->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->btnAgregarCola->Font = gcnew System::Drawing::Font(L"Segoe UI", 9.0F,
				FontStyle::Bold, GraphicsUnit::Point, static_cast<Byte>(0));
			this->btnAgregarCola->Location = System::Drawing::Point(840, 14);
			this->btnAgregarCola->Size = System::Drawing::Size(180, 34);
			this->btnAgregarCola->Text = L"Agregar a cola";
			this->btnAgregarCola->UseVisualStyleBackColor = false;
			this->btnAgregarCola->Click += gcnew EventHandler(this,
				&Linea_de_Ensamblaje1::btnAgregarCola_Click);

			this->panelAgregar->Controls->Add(this->labelSelPieza);
			this->panelAgregar->Controls->Add(this->comboBoxPiezas);
			this->panelAgregar->Controls->Add(this->btnAgregarCola);

			// ---- panelNota ----
			this->panelNota->BackColor = System::Drawing::Color::FromArgb(20, 40, 80);
			this->panelNota->BorderStyle =
				System::Windows::Forms::BorderStyle::FixedSingle;
			this->panelNota->Location = System::Drawing::Point(20, 524);
			this->panelNota->Size = System::Drawing::Size(1140, 36);

			this->labelNota->AutoSize = true;
			this->labelNota->Font = gcnew System::Drawing::Font(L"Segoe UI", 8.5F,
				FontStyle::Italic, GraphicsUnit::Point, static_cast<Byte>(0));
			this->labelNota->ForeColor = System::Drawing::Color::FromArgb(100, 160, 255);
			this->labelNota->Location = System::Drawing::Point(10, 10);
			this->labelNota->Text =
				L"ℹ  El Gestor solo puede agregar piezas a la cola y crear líneas. "
				L"La aprobación de la secuencia es exclusiva del Jefe de Operaciones.";
			this->panelNota->Controls->Add(this->labelNota);

			// ---- labelSecFlujo ----
			this->labelSecFlujo->AutoSize = true;
			this->labelSecFlujo->Font = gcnew System::Drawing::Font(L"Segoe UI", 9.0F,
				FontStyle::Bold, GraphicsUnit::Point, static_cast<Byte>(0));
			this->labelSecFlujo->ForeColor = acento;
			this->labelSecFlujo->Location = System::Drawing::Point(20, 574);
			this->labelSecFlujo->Text = L"Flujo completo de una pieza en el sistema";

			// ---- panelFlujo ----
			this->panelFlujo->BackColor = fondoForm;
			this->panelFlujo->Location = System::Drawing::Point(20, 598);
			this->panelFlujo->Size = System::Drawing::Size(1140, 80);
			this->panelFlujo->Paint += gcnew System::Windows::Forms::PaintEventHandler(
				this, &Linea_de_Ensamblaje1::panelFlujo_Paint);

			// ---- Form ----
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = fondoForm;
			this->ClientSize = System::Drawing::Size(1200, 700);
			this->Controls->Add(this->labelTitulo);
			this->Controls->Add(this->labelSecLineas);
			this->Controls->Add(this->dgvLineas);
			this->Controls->Add(this->btnNuevaLinea);
			this->Controls->Add(this->panelDetalle);
			this->Controls->Add(this->labelSecCola);
			this->Controls->Add(this->dgvCola);
			this->Controls->Add(this->labelSecAgregar);
			this->Controls->Add(this->panelAgregar);
			this->Controls->Add(this->panelNota);
			this->Controls->Add(this->labelSecFlujo);
			this->Controls->Add(this->panelFlujo);
			this->Name = L"Linea_de_Ensamblaje1";
			this->Text = L"Linea_de_Ensamblaje1";

			this->panelDetalle->ResumeLayout(false);
			this->panelDetalle->PerformLayout();
			this->panelAgregar->ResumeLayout(false);
			this->panelAgregar->PerformLayout();
			this->panelNota->ResumeLayout(false);
			this->panelNota->PerformLayout();
			this->panelFlujo->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgvLineas))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgvCola))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();
		}
#pragma endregion

		// ---------------------------------------------------------------
		// Load
		// ---------------------------------------------------------------
		void Form_Load(System::Object^ sender, System::EventArgs^ e)
		{
			CargarLineas();
			CargarComboPiezas();
		}

		// ---------------------------------------------------------------
		// Cargar tabla de líneas
		// ---------------------------------------------------------------
		void CargarLineas()
		{
			dgvLineas->Rows->Clear();
			for each (LineaEnsamblajeModel ^ l in ctrlLinea->obtenerTodos())
			{
				String^ secStr = l->SecuenciaAprobada ? "SÍ" : "PENDIENTE";
				int idx = dgvLineas->Rows->Add(l->Id, l->IndiceActual, secStr);
				// Colorear secuencia
				dgvLineas->Rows[idx]->Cells[2]->Style->ForeColor =
					l->SecuenciaAprobada
					? System::Drawing::Color::FromArgb(0, 200, 100)
					: System::Drawing::Color::FromArgb(230, 160, 0);
			}
		}

		// ---------------------------------------------------------------
		// Al seleccionar una línea → actualizar detalle y cola
		// ---------------------------------------------------------------
		void dgvLineas_SelectionChanged(System::Object^ sender, System::EventArgs^ e)
		{
			if (dgvLineas->SelectedRows->Count == 0) return;
			String^ id = dgvLineas->SelectedRows[0]->Cells[0]->Value->ToString();
			LineaEnsamblajeModel^ l = ctrlLinea->buscarPorId(id);
			if (l == nullptr) return;

			// Actualizar panel detalle
			labelLineaSel->Text = "Línea seleccionada: #" + l->Id;
			labelSecCola->Text = "Cola de piezas — Línea #" + l->Id;

			btnSecuencia->Text = l->SecuenciaAprobada ? "APROBADA" : "PENDIENTE";
			btnSecuencia->BackColor = l->SecuenciaAprobada
				? System::Drawing::Color::FromArgb(0, 120, 60)
				: System::Drawing::Color::FromArgb(120, 80, 0);

			// Cargar cola
			CargarCola(l);
		}

		// ---------------------------------------------------------------
		// Cargar cola de piezas de la línea seleccionada
		// ---------------------------------------------------------------
		void CargarCola(LineaEnsamblajeModel^ l)
		{
			dgvCola->Rows->Clear();
			int pos = 0;
			for each (PiezaModel ^ p in l->ColaPiezas)
			{
				String^ estadoStr;
				System::Drawing::Color colorEstado;
				switch (p->Estado)
				{
				case EstadoPieza::DISPONIBLE:
					estadoStr = "DISPONIBLE";
					colorEstado = System::Drawing::Color::FromArgb(0, 200, 100);
					break;
				case EstadoPieza::EN_PROCESO:
					estadoStr = "EN PROCESO";
					colorEstado = System::Drawing::Color::FromArgb(80, 160, 255);
					break;
				case EstadoPieza::ENSAMBLADA:
					estadoStr = "ENSAMBLADA";
					colorEstado = System::Drawing::Color::FromArgb(160, 80, 200);
					break;
				case EstadoPieza::DEFECTUOSA:
					estadoStr = "DEFECTUOSA";
					colorEstado = System::Drawing::Color::FromArgb(200, 40, 40);
					break;
				default:
					estadoStr = "—";
					colorEstado = System::Drawing::Color::Gray;
					break;
				}

				int idx = dgvCola->Rows->Add(
					pos, p->Tipo, p->Id, p->Material, estadoStr);
				dgvCola->Rows[idx]->Cells[4]->Style->ForeColor = colorEstado;
				pos++;
			}
		}

		// ---------------------------------------------------------------
		// Cargar combo de piezas disponibles
		// ---------------------------------------------------------------
		void CargarComboPiezas()
		{
			comboBoxPiezas->Items->Clear();

			for each (PanelLateralModel ^ p in ctrlPanel->obtenerTodos())
			{
				if (p->Estado == EstadoPieza::DISPONIBLE)
				{
					String^ item = "Panel Lateral  ID=" + p->Id
						+ "  " + p->Material + "  DISPONIBLE";
					comboBoxPiezas->Items->Add(item);
				}
			}
			for each (EstructuraTechoModel ^ t in ctrlTecho->obtenerTodos())
			{
				if (t->Estado == EstadoPieza::DISPONIBLE)
				{
					String^ item = "Estructura Techo  ID=" + t->Id
						+ "  " + t->Material + "  DISPONIBLE";
					comboBoxPiezas->Items->Add(item);
				}
			}

			if (comboBoxPiezas->Items->Count > 0)
				comboBoxPiezas->SelectedIndex = 0;
		}

		// ---------------------------------------------------------------
		// Botón Nueva línea
		// ---------------------------------------------------------------
		void btnNuevaLinea_Click(System::Object^ sender, System::EventArgs^ e)
		{
			String^ nuevoId = (ctrlLinea->obtenerTodos()->Count + 1).ToString();
			ctrlLinea->agregar(nuevoId);
			CargarLineas();
		}

		// ---------------------------------------------------------------
		// Botón Agregar a cola
		// ---------------------------------------------------------------
		void btnAgregarCola_Click(System::Object^ sender, System::EventArgs^ e)
		{
			if (dgvLineas->SelectedRows->Count == 0)
			{
				MessageBox::Show("Selecciona una línea primero.", "Aviso",
					MessageBoxButtons::OK, MessageBoxIcon::Information);
				return;
			}
			if (comboBoxPiezas->SelectedIndex < 0)
			{
				MessageBox::Show("No hay piezas disponibles para agregar.", "Aviso",
					MessageBoxButtons::OK, MessageBoxIcon::Information);
				return;
			}

			String^ lineaId = dgvLineas->SelectedRows[0]->Cells[0]->Value->ToString();
			String^ itemStr = comboBoxPiezas->SelectedItem->ToString();

			// Determinar tipo y extraer ID de la pieza seleccionada
			PiezaModel^ pieza = nullptr;
			if (itemStr->StartsWith("Panel Lateral"))
			{
				// Extraer ID del string "Panel Lateral  ID=X  ..."
				int inicio = itemStr->IndexOf("ID=") + 3;
				int fin = itemStr->IndexOf("  ", inicio);
				String^ id = itemStr->Substring(inicio, fin - inicio)->Trim();
				pieza = ctrlPanel->buscarPorId(id);
			}
			else
			{
				int inicio = itemStr->IndexOf("ID=") + 3;
				int fin = itemStr->IndexOf("  ", inicio);
				String^ id = itemStr->Substring(inicio, fin - inicio)->Trim();
				pieza = ctrlTecho->buscarPorId(id);
			}

			if (pieza == nullptr)
			{
				MessageBox::Show("No se pudo encontrar la pieza.", "Error",
					MessageBoxButtons::OK, MessageBoxIcon::Error);
				return;
			}

			ctrlLinea->agregarPieza(lineaId, pieza);

			// Recargar
			LineaEnsamblajeModel^ l = ctrlLinea->buscarPorId(lineaId);
			if (l != nullptr) CargarCola(l);
			CargarComboPiezas(); // Refrescar combo
		}

		// ---------------------------------------------------------------
		// Flujo GDI+ — 5 cajas con flechas
		// ---------------------------------------------------------------
		void panelFlujo_Paint(System::Object^ sender,
			System::Windows::Forms::PaintEventArgs^ e)
		{
			Graphics^ g = e->Graphics;
			g->SmoothingMode =
				System::Drawing::Drawing2D::SmoothingMode::AntiAlias;

			array<String^>^ pasos = gcnew array<String^>(5) {
				"Gestor carga\nal inventario",
					"Gestor asigna\na la cola",
					"Jefe aprueba\nla secuencia",
					"Brazo toma\nla pieza",
					"Brazo posiciona\ny suelda"
			};
			array<System::Drawing::Color>^ colores = gcnew array<System::Drawing::Color>(5) {
				System::Drawing::Color::FromArgb(100, 40, 160),  // violeta
					System::Drawing::Color::FromArgb(100, 40, 160),  // violeta
					System::Drawing::Color::FromArgb(160, 110, 0),   // naranja oscuro
					System::Drawing::Color::FromArgb(20, 80, 160),   // azul
					System::Drawing::Color::FromArgb(20, 80, 160)    // azul
			};

			int boxW = 190, boxH = 60, gap = 30;
			int startX = 10, startY = 10;
			System::Drawing::Font^ font = gcnew System::Drawing::Font(
				L"Segoe UI", 8.0F, FontStyle::Regular,
				GraphicsUnit::Point, static_cast<Byte>(0));

			for (int i = 0; i < 5; i++)
			{
				int x = startX + i * (boxW + gap);
				System::Drawing::Rectangle rect(x, startY, boxW, boxH);
				System::Drawing::Pen^ pen = gcnew System::Drawing::Pen(
					colores[i], 2);
				g->DrawRectangle(pen, rect);

				System::Drawing::SolidBrush^ brush =
					gcnew System::Drawing::SolidBrush(
						System::Drawing::Color::White);
				System::Drawing::StringFormat^ sf =
					gcnew System::Drawing::StringFormat();
				sf->Alignment = System::Drawing::StringAlignment::Center;
				sf->LineAlignment = System::Drawing::StringAlignment::Center;
				g->DrawString(pasos[i], font,
					gcnew System::Drawing::SolidBrush(
						System::Drawing::Color::White),
					System::Drawing::RectangleF(
						(float)x, (float)startY,
						(float)boxW, (float)boxH), sf);

				// Flecha entre cajas
				if (i < 4)
				{
					int ax = x + boxW + 4;
					int ay = startY + boxH / 2;
					System::Drawing::Pen^ arrowPen =
						gcnew System::Drawing::Pen(
							System::Drawing::Color::FromArgb(160, 180, 210), 1.5f);
					g->DrawLine(arrowPen,
						ax, ay, ax + gap - 8, ay);
					g->DrawLine(arrowPen,
						ax + gap - 8, ay,
						ax + gap - 14, ay - 5);
					g->DrawLine(arrowPen,
						ax + gap - 8, ay,
						ax + gap - 14, ay + 5);
				}
			}
		}
	};
}