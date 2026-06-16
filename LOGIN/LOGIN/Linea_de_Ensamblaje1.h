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
			System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle1 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle2 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle3 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			this->labelTitulo = (gcnew System::Windows::Forms::Label());
			this->labelSecLineas = (gcnew System::Windows::Forms::Label());
			this->dgvLineas = (gcnew System::Windows::Forms::DataGridView());
			this->colLineaId = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->colLineaIndice = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->colLineaSecuencia = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->btnNuevaLinea = (gcnew System::Windows::Forms::Button());
			this->panelDetalle = (gcnew System::Windows::Forms::Panel());
			this->labelLineaSel = (gcnew System::Windows::Forms::Label());
			this->labelSecuenciaHdr = (gcnew System::Windows::Forms::Label());
			this->btnSecuencia = (gcnew System::Windows::Forms::Button());
			this->labelSecuenciaNota = (gcnew System::Windows::Forms::Label());
			this->labelSecCola = (gcnew System::Windows::Forms::Label());
			this->dgvCola = (gcnew System::Windows::Forms::DataGridView());
			this->colPos = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->colTipo = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->colPiezaId = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->colMaterial = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->colEstado = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->labelSecAgregar = (gcnew System::Windows::Forms::Label());
			this->panelAgregar = (gcnew System::Windows::Forms::Panel());
			this->labelSelPieza = (gcnew System::Windows::Forms::Label());
			this->comboBoxPiezas = (gcnew System::Windows::Forms::ComboBox());
			this->btnAgregarCola = (gcnew System::Windows::Forms::Button());
			this->panelNota = (gcnew System::Windows::Forms::Panel());
			this->labelNota = (gcnew System::Windows::Forms::Label());
			this->labelSecFlujo = (gcnew System::Windows::Forms::Label());
			this->panelFlujo = (gcnew System::Windows::Forms::Panel());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgvLineas))->BeginInit();
			this->panelDetalle->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgvCola))->BeginInit();
			this->panelAgregar->SuspendLayout();
			this->panelNota->SuspendLayout();
			this->SuspendLayout();
			this->labelTitulo->AutoSize = true;
			this->labelTitulo->Font = (gcnew System::Drawing::Font(L"Segoe UI", 14, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->labelTitulo->ForeColor = System::Drawing::Color::White;
			this->labelTitulo->Location = System::Drawing::Point(20, 16);
			this->labelTitulo->Name = L"labelTitulo";
			this->labelTitulo->Size = System::Drawing::Size(198, 25);
			this->labelTitulo->TabIndex = 0;
			this->labelTitulo->Text = L"Lineas de Ensamblaje";
			this->labelSecLineas->AutoSize = true;
			this->labelSecLineas->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->labelSecLineas->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(230)), static_cast<System::Int32>(static_cast<System::Byte>(160)), static_cast<System::Int32>(static_cast<System::Byte>(0)));
			this->labelSecLineas->Location = System::Drawing::Point(20, 52);
			this->labelSecLineas->Name = L"labelSecLineas";
			this->labelSecLineas->Size = System::Drawing::Size(115, 15);
			this->labelSecLineas->TabIndex = 1;
			this->labelSecLineas->Text = L"Lineas configuradas";
			this->dgvLineas->AllowUserToAddRows = false;
			this->dgvLineas->AutoSizeColumnsMode = System::Windows::Forms::DataGridViewAutoSizeColumnsMode::Fill;
			this->dgvLineas->BackgroundColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(28)), static_cast<System::Int32>(static_cast<System::Byte>(38)), static_cast<System::Int32>(static_cast<System::Byte>(54)));
			this->dgvLineas->ColumnHeadersBorderStyle = System::Windows::Forms::DataGridViewHeaderBorderStyle::Single;
			dataGridViewCellStyle1->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(15)), static_cast<System::Int32>(static_cast<System::Byte>(22)), static_cast<System::Int32>(static_cast<System::Byte>(32)));
			dataGridViewCellStyle1->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			dataGridViewCellStyle1->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(230)), static_cast<System::Int32>(static_cast<System::Byte>(160)), static_cast<System::Int32>(static_cast<System::Byte>(0)));
			this->dgvLineas->ColumnHeadersDefaultCellStyle = dataGridViewCellStyle1;
			this->dgvLineas->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dgvLineas->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(3) { this->colLineaId, this->colLineaIndice, this->colLineaSecuencia });
			dataGridViewCellStyle2->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleLeft;
			dataGridViewCellStyle2->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(28)), static_cast<System::Int32>(static_cast<System::Byte>(38)), static_cast<System::Int32>(static_cast<System::Byte>(54)));
			dataGridViewCellStyle2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			dataGridViewCellStyle2->ForeColor = System::Drawing::Color::White;
			dataGridViewCellStyle2->SelectionBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(50)), static_cast<System::Int32>(static_cast<System::Byte>(80)), static_cast<System::Int32>(static_cast<System::Byte>(120)));
			dataGridViewCellStyle2->SelectionForeColor = System::Drawing::Color::White;
			dataGridViewCellStyle2->WrapMode = System::Windows::Forms::DataGridViewTriState::False;
			this->dgvLineas->DefaultCellStyle = dataGridViewCellStyle2;
			this->dgvLineas->EnableHeadersVisualStyles = false;
			this->dgvLineas->GridColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->dgvLineas->Location = System::Drawing::Point(20, 72);
			this->dgvLineas->MultiSelect = false;
			this->dgvLineas->Name = L"dgvLineas";
			this->dgvLineas->ReadOnly = true;
			this->dgvLineas->RowHeadersVisible = false;
			this->dgvLineas->RowTemplate->Height = 28;
			this->dgvLineas->SelectionMode = System::Windows::Forms::DataGridViewSelectionMode::FullRowSelect;
			this->dgvLineas->Size = System::Drawing::Size(660, 100);
			this->dgvLineas->TabIndex = 2;
			this->dgvLineas->CellContentClick += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &Linea_de_Ensamblaje1::dgvLineas_CellContentClick);
			this->dgvLineas->SelectionChanged += gcnew System::EventHandler(this, &Linea_de_Ensamblaje1::dgvLineas_SelectionChanged);
			this->colLineaId->HeaderText = L"ID";
			this->colLineaId->MinimumWidth = 60;
			this->colLineaId->Name = L"colLineaId";
			this->colLineaId->ReadOnly = true;
			this->colLineaIndice->HeaderText = L"Indice Actual";
			this->colLineaIndice->Name = L"colLineaIndice";
			this->colLineaIndice->ReadOnly = true;
			this->colLineaSecuencia->HeaderText = L"Secuencia Aprobada";
			this->colLineaSecuencia->Name = L"colLineaSecuencia";
			this->colLineaSecuencia->ReadOnly = true;
			this->btnNuevaLinea->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(80)), static_cast<System::Int32>(static_cast<System::Byte>(80)), static_cast<System::Int32>(static_cast<System::Byte>(80)));
			this->btnNuevaLinea->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->btnNuevaLinea->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->btnNuevaLinea->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(160)), static_cast<System::Int32>(static_cast<System::Byte>(160)), static_cast<System::Int32>(static_cast<System::Byte>(160)));
			this->btnNuevaLinea->Location = System::Drawing::Point(20, 182);
			this->btnNuevaLinea->Name = L"btnNuevaLinea";
			this->btnNuevaLinea->Size = System::Drawing::Size(140, 34);
			this->btnNuevaLinea->TabIndex = 3;
			this->btnNuevaLinea->Text = L"Nueva linea";
			this->btnNuevaLinea->UseVisualStyleBackColor = false;
			this->btnNuevaLinea->Click += gcnew System::EventHandler(this, &Linea_de_Ensamblaje1::btnNuevaLinea_Click_1);
			this->panelDetalle->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(28)), static_cast<System::Int32>(static_cast<System::Byte>(38)), static_cast<System::Int32>(static_cast<System::Byte>(54)));
			this->panelDetalle->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->panelDetalle->Controls->Add(this->labelLineaSel);
			this->panelDetalle->Controls->Add(this->labelSecuenciaHdr);
			this->panelDetalle->Controls->Add(this->btnSecuencia);
			this->panelDetalle->Controls->Add(this->labelSecuenciaNota);
			this->panelDetalle->Location = System::Drawing::Point(700, 72);
			this->panelDetalle->Name = L"panelDetalle";
			this->panelDetalle->Size = System::Drawing::Size(460, 100);
			this->panelDetalle->TabIndex = 4;
			this->labelLineaSel->AutoSize = true;
			this->labelLineaSel->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->labelLineaSel->ForeColor = System::Drawing::Color::White;
			this->labelLineaSel->Location = System::Drawing::Point(10, 10);
			this->labelLineaSel->Name = L"labelLineaSel";
			this->labelLineaSel->Size = System::Drawing::Size(127, 15);
			this->labelLineaSel->TabIndex = 0;
			this->labelLineaSel->Text = L"Linea seleccionada: --";
			this->labelSecuenciaHdr->AutoSize = true;
			this->labelSecuenciaHdr->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(160)), static_cast<System::Int32>(static_cast<System::Byte>(180)), static_cast<System::Int32>(static_cast<System::Byte>(210)));
			this->labelSecuenciaHdr->Location = System::Drawing::Point(10, 40);
			this->labelSecuenciaHdr->Name = L"labelSecuenciaHdr";
			this->labelSecuenciaHdr->Size = System::Drawing::Size(61, 13);
			this->labelSecuenciaHdr->TabIndex = 1;
			this->labelSecuenciaHdr->Text = L"Secuencia:";
			this->btnSecuencia->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->btnSecuencia->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->btnSecuencia->Location = System::Drawing::Point(90, 34);
			this->btnSecuencia->Name = L"btnSecuencia";
			this->btnSecuencia->Size = System::Drawing::Size(130, 28);
			this->btnSecuencia->TabIndex = 2;
			this->btnSecuencia->Text = L"PENDIENTE";
			this->btnSecuencia->UseVisualStyleBackColor = false;
			this->labelSecuenciaNota->AutoSize = true;
			this->labelSecuenciaNota->Font = (gcnew System::Drawing::Font(L"Segoe UI", 8, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->labelSecuenciaNota->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(160)), static_cast<System::Int32>(static_cast<System::Byte>(180)), static_cast<System::Int32>(static_cast<System::Byte>(210)));
			this->labelSecuenciaNota->Location = System::Drawing::Point(230, 40);
			this->labelSecuenciaNota->Name = L"labelSecuenciaNota";
			this->labelSecuenciaNota->Size = System::Drawing::Size(116, 13);
			this->labelSecuenciaNota->TabIndex = 3;
			this->labelSecuenciaNota->Text = L"(El Jefe debe aprobarla)";
			this->labelSecCola->AutoSize = true;
			this->labelSecCola->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->labelSecCola->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(230)), static_cast<System::Int32>(static_cast<System::Byte>(160)), static_cast<System::Int32>(static_cast<System::Byte>(0)));
			this->labelSecCola->Location = System::Drawing::Point(20, 228);
			this->labelSecCola->Name = L"labelSecCola";
			this->labelSecCola->Size = System::Drawing::Size(153, 15);
			this->labelSecCola->TabIndex = 5;
			this->labelSecCola->Text = L"Cola de piezas -- Linea #--";
			this->dgvCola->AllowUserToAddRows = false;
			this->dgvCola->AutoSizeColumnsMode = System::Windows::Forms::DataGridViewAutoSizeColumnsMode::Fill;
			this->dgvCola->BackgroundColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(28)), static_cast<System::Int32>(static_cast<System::Byte>(38)), static_cast<System::Int32>(static_cast<System::Byte>(54)));
			this->dgvCola->ColumnHeadersBorderStyle = System::Windows::Forms::DataGridViewHeaderBorderStyle::Single;
			this->dgvCola->ColumnHeadersDefaultCellStyle = dataGridViewCellStyle1;
			this->dgvCola->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dgvCola->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(5) { this->colPos, this->colTipo, this->colPiezaId, this->colMaterial, this->colEstado });
			dataGridViewCellStyle3->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleLeft;
			dataGridViewCellStyle3->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(28)), static_cast<System::Int32>(static_cast<System::Byte>(38)), static_cast<System::Int32>(static_cast<System::Byte>(54)));
			dataGridViewCellStyle3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			dataGridViewCellStyle3->ForeColor = System::Drawing::Color::White;
			dataGridViewCellStyle3->SelectionBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(50)), static_cast<System::Int32>(static_cast<System::Byte>(80)), static_cast<System::Int32>(static_cast<System::Byte>(120)));
			dataGridViewCellStyle3->SelectionForeColor = System::Drawing::Color::White;
			dataGridViewCellStyle3->WrapMode = System::Windows::Forms::DataGridViewTriState::False;
			this->dgvCola->DefaultCellStyle = dataGridViewCellStyle3;
			this->dgvCola->EnableHeadersVisualStyles = false;
			this->dgvCola->GridColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->dgvCola->Location = System::Drawing::Point(20, 250);
			this->dgvCola->Name = L"dgvCola";
			this->dgvCola->ReadOnly = true;
			this->dgvCola->RowHeadersVisible = false;
			this->dgvCola->RowTemplate->Height = 28;
			this->dgvCola->Size = System::Drawing::Size(1140, 160);
			this->dgvCola->TabIndex = 6;
			this->colPos->HeaderText = L"Pos.";
			this->colPos->MinimumWidth = 50;
			this->colPos->Name = L"colPos";
			this->colPos->ReadOnly = true;
			this->colTipo->HeaderText = L"Tipo";
			this->colTipo->Name = L"colTipo";
			this->colTipo->ReadOnly = true;
			this->colPiezaId->HeaderText = L"ID Pieza";
			this->colPiezaId->Name = L"colPiezaId";
			this->colPiezaId->ReadOnly = true;
			this->colMaterial->HeaderText = L"Material";
			this->colMaterial->Name = L"colMaterial";
			this->colMaterial->ReadOnly = true;
			this->colEstado->HeaderText = L"Estado";
			this->colEstado->Name = L"colEstado";
			this->colEstado->ReadOnly = true;
			this->labelSecAgregar->AutoSize = true;
			this->labelSecAgregar->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->labelSecAgregar->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(230)), static_cast<System::Int32>(static_cast<System::Byte>(160)), static_cast<System::Int32>(static_cast<System::Byte>(0)));
			this->labelSecAgregar->Location = System::Drawing::Point(20, 424);
			this->labelSecAgregar->Name = L"labelSecAgregar";
			this->labelSecAgregar->Size = System::Drawing::Size(130, 15);
			this->labelSecAgregar->TabIndex = 7;
			this->labelSecAgregar->Text = L"Agregar pieza a la cola";
			this->panelAgregar->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(28)), static_cast<System::Int32>(static_cast<System::Byte>(38)), static_cast<System::Int32>(static_cast<System::Byte>(54)));
			this->panelAgregar->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->panelAgregar->Controls->Add(this->labelSelPieza);
			this->panelAgregar->Controls->Add(this->comboBoxPiezas);
			this->panelAgregar->Controls->Add(this->btnAgregarCola);
			this->panelAgregar->Location = System::Drawing::Point(20, 448);
			this->panelAgregar->Name = L"panelAgregar";
			this->panelAgregar->Size = System::Drawing::Size(1140, 60);
			this->panelAgregar->TabIndex = 8;
			this->labelSelPieza->AutoSize = true;
			this->labelSelPieza->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(160)), static_cast<System::Int32>(static_cast<System::Byte>(180)), static_cast<System::Int32>(static_cast<System::Byte>(210)));
			this->labelSelPieza->Location = System::Drawing::Point(10, 22);
			this->labelSelPieza->Name = L"labelSelPieza";
			this->labelSelPieza->Size = System::Drawing::Size(94, 13);
			this->labelSelPieza->TabIndex = 0;
			this->labelSelPieza->Text = L"Seleccionar pieza:";
			this->comboBoxPiezas->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(30)), static_cast<System::Int32>(static_cast<System::Byte>(41)), static_cast<System::Int32>(static_cast<System::Byte>(59)));
			this->comboBoxPiezas->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->comboBoxPiezas->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->comboBoxPiezas->ForeColor = System::Drawing::Color::White;
			this->comboBoxPiezas->Location = System::Drawing::Point(120, 18);
			this->comboBoxPiezas->Name = L"comboBoxPiezas";
			this->comboBoxPiezas->Size = System::Drawing::Size(700, 21);
			this->comboBoxPiezas->TabIndex = 1;
			this->btnAgregarCola->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(230)), static_cast<System::Int32>(static_cast<System::Byte>(160)), static_cast<System::Int32>(static_cast<System::Byte>(0)));
			this->btnAgregarCola->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->btnAgregarCola->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->btnAgregarCola->ForeColor = System::Drawing::Color::Black;
			this->btnAgregarCola->Location = System::Drawing::Point(840, 14);
			this->btnAgregarCola->Name = L"btnAgregarCola";
			this->btnAgregarCola->Size = System::Drawing::Size(180, 34);
			this->btnAgregarCola->TabIndex = 2;
			this->btnAgregarCola->Text = L"Agregar a cola";
			this->btnAgregarCola->UseVisualStyleBackColor = false;
			this->btnAgregarCola->Click += gcnew System::EventHandler(this, &Linea_de_Ensamblaje1::btnAgregarCola_Click_1);
			this->panelNota->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(20)), static_cast<System::Int32>(static_cast<System::Byte>(40)), static_cast<System::Int32>(static_cast<System::Byte>(80)));
			this->panelNota->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->panelNota->Controls->Add(this->labelNota);
			this->panelNota->Location = System::Drawing::Point(20, 524);
			this->panelNota->Name = L"panelNota";
			this->panelNota->Size = System::Drawing::Size(1140, 36);
			this->panelNota->TabIndex = 9;
			this->labelNota->AutoSize = true;
			this->labelNota->Font = (gcnew System::Drawing::Font(L"Segoe UI", 8.5F, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->labelNota->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(100)), static_cast<System::Int32>(static_cast<System::Byte>(160)), static_cast<System::Int32>(static_cast<System::Byte>(255)));
			this->labelNota->Location = System::Drawing::Point(10, 10);
			this->labelNota->Name = L"labelNota";
			this->labelNota->Size = System::Drawing::Size(686, 15);
			this->labelNota->TabIndex = 0;
			this->labelNota->Text = L"El Gestor solo puede agregar piezas a la cola y crear lineas. La aprobacion de la secuencia es exclusiva del Jefe de Operaciones.";
			this->labelSecFlujo->AutoSize = true;
			this->labelSecFlujo->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->labelSecFlujo->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(230)), static_cast<System::Int32>(static_cast<System::Byte>(160)), static_cast<System::Int32>(static_cast<System::Byte>(0)));
			this->labelSecFlujo->Location = System::Drawing::Point(20, 574);
			this->labelSecFlujo->Name = L"labelSecFlujo";
			this->labelSecFlujo->Size = System::Drawing::Size(236, 15);
			this->labelSecFlujo->TabIndex = 10;
			this->labelSecFlujo->Text = L"Flujo completo de una pieza en el sistema";
			this->panelFlujo->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(18)), static_cast<System::Int32>(static_cast<System::Byte>(26)), static_cast<System::Int32>(static_cast<System::Byte>(38)));
			this->panelFlujo->Location = System::Drawing::Point(20, 598);
			this->panelFlujo->Name = L"panelFlujo";
			this->panelFlujo->Size = System::Drawing::Size(1140, 80);
			this->panelFlujo->TabIndex = 11;
			this->panelFlujo->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &Linea_de_Ensamblaje1::panelFlujo_Paint);
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(18)), static_cast<System::Int32>(static_cast<System::Byte>(26)), static_cast<System::Int32>(static_cast<System::Byte>(38)));
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
			this->Load += gcnew System::EventHandler(this, &Linea_de_Ensamblaje1::Linea_de_Ensamblaje1_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgvLineas))->EndInit();
			this->panelDetalle->ResumeLayout(false);
			this->panelDetalle->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgvCola))->EndInit();
			this->panelAgregar->ResumeLayout(false);
			this->panelAgregar->PerformLayout();
			this->panelNota->ResumeLayout(false);
			this->panelNota->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();
		}
#pragma endregion

		void Form_Load(System::Object^ sender, System::EventArgs^ e)
		{
			CargarLineas();
			CargarComboPiezas();
		}

		void CargarLineas()
		{
			dgvLineas->Rows->Clear();
			for each (LineaEnsamblajeModel ^ l in ctrlLinea->obtenerTodos())
			{
				String^ secStr = l->SecuenciaAprobada ? "SI" : "PENDIENTE";
				int idx = dgvLineas->Rows->Add(l->Id, l->IndiceActual, secStr);
				dgvLineas->Rows[idx]->Cells[2]->Style->ForeColor =
					l->SecuenciaAprobada
					? System::Drawing::Color::FromArgb(0, 200, 100)
					: System::Drawing::Color::FromArgb(230, 160, 0);
			}
			if (dgvLineas->Rows->Count > 0)
				dgvLineas->Rows[0]->Selected = true;
		}

		void dgvLineas_SelectionChanged(System::Object^ sender, System::EventArgs^ e)
		{
			if (dgvLineas->SelectedRows->Count == 0) return;
			String^ id = dgvLineas->SelectedRows[0]->Cells[0]->Value->ToString();
			LineaEnsamblajeModel^ l = ctrlLinea->buscarPorId(id);
			if (l == nullptr) return;

			labelLineaSel->Text = "Linea seleccionada: #" + l->Id;
			labelSecCola->Text = "Cola de piezas -- Linea #" + l->Id;

			btnSecuencia->Text = l->SecuenciaAprobada ? "APROBADA" : "PENDIENTE";
			btnSecuencia->BackColor = l->SecuenciaAprobada
				? System::Drawing::Color::FromArgb(0, 120, 60)
				: System::Drawing::Color::FromArgb(120, 80, 0);

			CargarCola(l);
		}

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
					estadoStr = "--";
					colorEstado = System::Drawing::Color::Gray;
					break;
				}
				int idx = dgvCola->Rows->Add(pos, p->Tipo, p->Id, p->Material, estadoStr);
				dgvCola->Rows[idx]->Cells[4]->Style->ForeColor = colorEstado;
				pos++;
			}
		}

		void CargarComboPiezas()
		{
			comboBoxPiezas->Items->Clear();
			for each (PanelLateralModel ^ p in ctrlPanel->obtenerTodos())
			{
				if (p->Estado == EstadoPieza::DISPONIBLE)
				{
					String^ item = "Panel Lateral  ID=" + p->Id + "  " + p->Material + "  DISPONIBLE";
					comboBoxPiezas->Items->Add(item);
				}
			}
			for each (EstructuraTechoModel ^ t in ctrlTecho->obtenerTodos())
			{
				if (t->Estado == EstadoPieza::DISPONIBLE)
				{
					String^ item = "Estructura Techo  ID=" + t->Id + "  " + t->Material + "  DISPONIBLE";
					comboBoxPiezas->Items->Add(item);
				}
			}
			if (comboBoxPiezas->Items->Count > 0)
				comboBoxPiezas->SelectedIndex = 0;
		}

		void panelFlujo_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e)
		{
			Graphics^ g = e->Graphics;
			g->SmoothingMode = System::Drawing::Drawing2D::SmoothingMode::AntiAlias;

			array<String^>^ pasos = gcnew array<String^>(5) {
				"Gestor carga\nal inventario",
					"Gestor asigna\na la cola",
					"Jefe aprueba\nla secuencia",
					"Brazo toma\nla pieza",
					"Brazo posiciona\ny suelda"
			};
			array<System::Drawing::Color>^ colores = gcnew array<System::Drawing::Color>(5) {
				System::Drawing::Color::FromArgb(100, 40, 160),
					System::Drawing::Color::FromArgb(100, 40, 160),
					System::Drawing::Color::FromArgb(160, 110, 0),
					System::Drawing::Color::FromArgb(20, 80, 160),
					System::Drawing::Color::FromArgb(20, 80, 160)
			};

			int boxW = 190, boxH = 60, gap = 30;
			int startX = 10, startY = 10;
			System::Drawing::Font^ font = gcnew System::Drawing::Font(L"Segoe UI", 8.0F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0));

			for (int i = 0; i < 5; i++)
			{
				int x = startX + i * (boxW + gap);
				System::Drawing::Rectangle rect(x, startY, boxW, boxH);
				g->DrawRectangle(gcnew System::Drawing::Pen(colores[i], 2), rect);
				System::Drawing::StringFormat^ sf = gcnew System::Drawing::StringFormat();
				sf->Alignment = System::Drawing::StringAlignment::Center;
				sf->LineAlignment = System::Drawing::StringAlignment::Center;
				g->DrawString(pasos[i], font, gcnew System::Drawing::SolidBrush(System::Drawing::Color::White),
					System::Drawing::RectangleF((float)x, (float)startY, (float)boxW, (float)boxH), sf);
				if (i < 4)
				{
					int ax = x + boxW + 4;
					int ay = startY + boxH / 2;
					System::Drawing::Pen^ arrowPen = gcnew System::Drawing::Pen(System::Drawing::Color::FromArgb(160, 180, 210), 1.5f);
					g->DrawLine(arrowPen, ax, ay, ax + gap - 8, ay);
					g->DrawLine(arrowPen, ax + gap - 8, ay, ax + gap - 14, ay - 5);
					g->DrawLine(arrowPen, ax + gap - 8, ay, ax + gap - 14, ay + 5);
				}
			}
		}

	private: System::Void Linea_de_Ensamblaje1_Load(System::Object^ sender, System::EventArgs^ e) {}

		   // CORREGIDO: boton deshabilitado — lineas son fijas (L-001, L-002, L-003)
	private: System::Void btnNuevaLinea_Click_1(System::Object^ sender, System::EventArgs^ e) {
		MessageBox::Show(
			"Las lineas de ensamblaje son fijas (L-001, L-002, L-003).\nNo se pueden crear nuevas lineas.",
			"Operacion no permitida", MessageBoxButtons::OK, MessageBoxIcon::Information);
	}

	private: System::Void btnAgregarCola_Click_1(System::Object^ sender, System::EventArgs^ e) {
		if (dgvLineas->SelectedRows->Count == 0)
		{
			MessageBox::Show("Selecciona una linea primero.", "Aviso",
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

		PiezaModel^ pieza = nullptr;
		if (itemStr->StartsWith("Panel Lateral"))
		{
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

		// Marcar pieza como EN_PROCESO
		PanelLateralModel^ pl = dynamic_cast<PanelLateralModel^>(pieza);
		if (pl != nullptr)
			ctrlPanel->modificar(pieza->Id, pieza->Material, pieza->Peso,
				EstadoPieza::EN_PROCESO, pl->PuntosAnclaje, pl->EstacionId);
		else {
			EstructuraTechoModel^ et = dynamic_cast<EstructuraTechoModel^>(pieza);
			if (et != nullptr)
				ctrlTecho->modificar(pieza->Id, pieza->Material, pieza->Peso,
					EstadoPieza::EN_PROCESO, et->PuntosUnion, et->Anchura, et->EstacionId);
		}

		LineaEnsamblajeModel^ l = ctrlLinea->buscarPorId(lineaId);
		if (l != nullptr) CargarCola(l);
		CargarComboPiezas();
	}

	private: System::Void dgvLineas_CellContentClick(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e) {}
	};
}