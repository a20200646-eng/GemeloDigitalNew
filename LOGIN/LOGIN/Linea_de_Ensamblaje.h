#pragma once

namespace LOGIN {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace GemeloDigitalController;
	using namespace GemeloDigitalModel;

	/// <summary>
	/// Resumen de Linea_de_Ensamblaje
	/// </summary>
	public ref class Linea_de_Ensamblaje : public System::Windows::Forms::Form
	{
	public:
		Linea_de_Ensamblaje(void)
		{
			InitializeComponent();
			//
			//TODO: agregar código de constructor aquí
			//
			// Inicializar controllers
			ctrlLinea = gcnew LineaEnsamblajeController();
			ctrlPanel = gcnew PanelLateralController();
			ctrlTecho = gcnew EstructuraTechoController();
			
		}

	protected:
		/// <summary>
		/// Limpiar los recursos que se estén usando.
		/// </summary>
		~Linea_de_Ensamblaje()
		{
			if (components)
			{
				delete components;
			}
		}

	private: System::Windows::Forms::Panel^ panel5;
	private: System::Windows::Forms::Label^ label11;
	private: System::Windows::Forms::Label^ label12;
	private: System::Windows::Forms::Panel^ panel3;
	private: System::Windows::Forms::Label^ label9;
	private: System::Windows::Forms::Label^ label10;
	private: System::Windows::Forms::Panel^ panel9;
	private: System::Windows::Forms::Panel^ panel4;




	private: System::Windows::Forms::Panel^ panel6;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label6;
	private: System::Windows::Forms::Panel^ panel2;
	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::DataGridView^ dataGridView1;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Column1;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Rol;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Column2;
	private: System::Windows::Forms::Panel^ panel1;
	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::DataGridView^ dataGridView2;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ dataGridViewTextBoxColumn1;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ dataGridViewTextBoxColumn2;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ dataGridViewTextBoxColumn3;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Column3;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Column4;
	private: System::Windows::Forms::Panel^ panel7;
	private: System::Windows::Forms::Panel^ panel8;
	private: System::Windows::Forms::Label^ label7;
	private: System::Windows::Forms::Label^ label8;








	protected:

	private:
		/// <summary>
		/// Variable del diseñador necesaria.
		/// </summary>
		System::ComponentModel::Container ^components;
		PanelLateralController^ ctrlPanel;
		EstructuraTechoController^ ctrlTecho;
		LineaEnsamblajeController^ ctrlLinea;
		LineaEnsamblajeModel^ lineaSeleccionada;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Método necesario para admitir el Diseñador. No se puede modificar
		/// el contenido de este método con el editor de código.
		/// </summary>
		void InitializeComponent(void)
		{
			System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle1 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle2 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			this->panel5 = (gcnew System::Windows::Forms::Panel());
			this->label11 = (gcnew System::Windows::Forms::Label());
			this->label12 = (gcnew System::Windows::Forms::Label());
			this->panel3 = (gcnew System::Windows::Forms::Panel());
			this->label9 = (gcnew System::Windows::Forms::Label());
			this->label10 = (gcnew System::Windows::Forms::Label());
			this->panel9 = (gcnew System::Windows::Forms::Panel());
			this->panel4 = (gcnew System::Windows::Forms::Panel());
			this->panel6 = (gcnew System::Windows::Forms::Panel());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->panel2 = (gcnew System::Windows::Forms::Panel());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
			this->Column1 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Rol = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column2 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->dataGridView2 = (gcnew System::Windows::Forms::DataGridView());
			this->dataGridViewTextBoxColumn1 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->dataGridViewTextBoxColumn2 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->dataGridViewTextBoxColumn3 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column3 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column4 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->panel7 = (gcnew System::Windows::Forms::Panel());
			this->panel8 = (gcnew System::Windows::Forms::Panel());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->panel5->SuspendLayout();
			this->panel3->SuspendLayout();
			this->panel6->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->BeginInit();
			this->panel1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView2))->BeginInit();
			this->panel7->SuspendLayout();
			this->panel8->SuspendLayout();
			this->SuspendLayout();
			// 
			// panel5
			// 
			this->panel5->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(14)), static_cast<System::Int32>(static_cast<System::Byte>(22)),
				static_cast<System::Int32>(static_cast<System::Byte>(40)));
			this->panel5->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->panel5->Controls->Add(this->label11);
			this->panel5->Controls->Add(this->label12);
			this->panel5->ForeColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->panel5->Location = System::Drawing::Point(362, 76);
			this->panel5->Margin = System::Windows::Forms::Padding(2);
			this->panel5->Name = L"panel5";
			this->panel5->Size = System::Drawing::Size(161, 56);
			this->panel5->TabIndex = 18;
			// 
			// label11
			// 
			this->label11->AutoSize = true;
			this->label11->Font = (gcnew System::Drawing::Font(L"Calibri", 7.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label11->ForeColor = System::Drawing::Color::White;
			this->label11->Location = System::Drawing::Point(2, 38);
			this->label11->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label11->Name = L"label11";
			this->label11->Size = System::Drawing::Size(68, 13);
			this->label11->TabIndex = 4;
			this->label11->Text = L"Índice actual";
			// 
			// label12
			// 
			this->label12->AutoSize = true;
			this->label12->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label12->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(124)), static_cast<System::Int32>(static_cast<System::Byte>(58)),
				static_cast<System::Int32>(static_cast<System::Byte>(237)));
			this->label12->Location = System::Drawing::Point(9, 7);
			this->label12->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label12->Name = L"label12";
			this->label12->Size = System::Drawing::Size(15, 16);
			this->label12->TabIndex = 11;
			this->label12->Text = L"2";
			// 
			// panel3
			// 
			this->panel3->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(14)), static_cast<System::Int32>(static_cast<System::Byte>(22)),
				static_cast<System::Int32>(static_cast<System::Byte>(40)));
			this->panel3->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->panel3->Controls->Add(this->label9);
			this->panel3->Controls->Add(this->label10);
			this->panel3->ForeColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->panel3->Location = System::Drawing::Point(195, 76);
			this->panel3->Margin = System::Windows::Forms::Padding(2);
			this->panel3->Name = L"panel3";
			this->panel3->Size = System::Drawing::Size(161, 56);
			this->panel3->TabIndex = 22;
			// 
			// label9
			// 
			this->label9->AutoSize = true;
			this->label9->Font = (gcnew System::Drawing::Font(L"Calibri", 7.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label9->ForeColor = System::Drawing::Color::White;
			this->label9->Location = System::Drawing::Point(2, 38);
			this->label9->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(73, 13);
			this->label9->TabIndex = 4;
			this->label9->Text = L"Piezas en cola";
			// 
			// label10
			// 
			this->label10->AutoSize = true;
			this->label10->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label10->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(217)), static_cast<System::Int32>(static_cast<System::Byte>(119)),
				static_cast<System::Int32>(static_cast<System::Byte>(6)));
			this->label10->Location = System::Drawing::Point(8, 7);
			this->label10->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label10->Name = L"label10";
			this->label10->Size = System::Drawing::Size(15, 16);
			this->label10->TabIndex = 11;
			this->label10->Text = L"4";
			// 
			// panel9
			// 
			this->panel9->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(124)), static_cast<System::Int32>(static_cast<System::Byte>(58)),
				static_cast<System::Int32>(static_cast<System::Byte>(237)));
			this->panel9->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->panel9->ForeColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->panel9->Location = System::Drawing::Point(362, 67);
			this->panel9->Margin = System::Windows::Forms::Padding(2);
			this->panel9->Name = L"panel9";
			this->panel9->Size = System::Drawing::Size(161, 65);
			this->panel9->TabIndex = 17;
			// 
			// panel4
			// 
			this->panel4->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(217)), static_cast<System::Int32>(static_cast<System::Byte>(119)),
				static_cast<System::Int32>(static_cast<System::Byte>(6)));
			this->panel4->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->panel4->ForeColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->panel4->Location = System::Drawing::Point(195, 67);
			this->panel4->Margin = System::Windows::Forms::Padding(2);
			this->panel4->Name = L"panel4";
			this->panel4->Size = System::Drawing::Size(161, 65);
			this->panel4->TabIndex = 21;
			// 
			// panel6
			// 
			this->panel6->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(14)), static_cast<System::Int32>(static_cast<System::Byte>(22)),
				static_cast<System::Int32>(static_cast<System::Byte>(40)));
			this->panel6->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->panel6->Controls->Add(this->label2);
			this->panel6->Controls->Add(this->label6);
			this->panel6->ForeColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->panel6->Location = System::Drawing::Point(28, 76);
			this->panel6->Margin = System::Windows::Forms::Padding(2);
			this->panel6->Name = L"panel6";
			this->panel6->Size = System::Drawing::Size(161, 56);
			this->panel6->TabIndex = 16;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Calibri", 7.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label2->ForeColor = System::Drawing::Color::White;
			this->label2->Location = System::Drawing::Point(2, 38);
			this->label2->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(55, 13);
			this->label2->TabIndex = 4;
			this->label2->Text = L"Secuencia";
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label6->ForeColor = System::Drawing::Color::Green;
			this->label6->Location = System::Drawing::Point(2, 7);
			this->label6->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(90, 16);
			this->label6->TabIndex = 11;
			this->label6->Text = L"APROBADA";
			this->label6->Click += gcnew System::EventHandler(this, &Linea_de_Ensamblaje::label6_Click);
			// 
			// panel2
			// 
			this->panel2->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(22)), static_cast<System::Int32>(static_cast<System::Byte>(163)),
				static_cast<System::Int32>(static_cast<System::Byte>(74)));
			this->panel2->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->panel2->ForeColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->panel2->Location = System::Drawing::Point(28, 67);
			this->panel2->Margin = System::Windows::Forms::Padding(2);
			this->panel2->Name = L"panel2";
			this->panel2->Size = System::Drawing::Size(161, 65);
			this->panel2->TabIndex = 15;
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(245)), static_cast<System::Int32>(static_cast<System::Byte>(158)),
				static_cast<System::Int32>(static_cast<System::Byte>(11)));
			this->label5->Location = System::Drawing::Point(26, 158);
			this->label5->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(104, 13);
			this->label5->TabIndex = 23;
			this->label5->Text = L"Líneas configuradas";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(245)), static_cast<System::Int32>(static_cast<System::Byte>(158)),
				static_cast<System::Int32>(static_cast<System::Byte>(11)));
			this->label3->Location = System::Drawing::Point(318, 158);
			this->label3->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(132, 13);
			this->label3->TabIndex = 24;
			this->label3->Text = L"Acción sobre la secuencia";
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
			this->dataGridView1->Cursor = System::Windows::Forms::Cursors::Default;
			this->dataGridView1->EnableHeadersVisualStyles = false;
			this->dataGridView1->GridColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->dataGridView1->Location = System::Drawing::Point(28, 193);
			this->dataGridView1->Margin = System::Windows::Forms::Padding(2);
			this->dataGridView1->Name = L"dataGridView1";
			this->dataGridView1->RowHeadersBorderStyle = System::Windows::Forms::DataGridViewHeaderBorderStyle::Single;
			dataGridViewCellStyle1->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleLeft;
			dataGridViewCellStyle1->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(30)), static_cast<System::Int32>(static_cast<System::Byte>(58)),
				static_cast<System::Int32>(static_cast<System::Byte>(95)));
			dataGridViewCellStyle1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 7.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			dataGridViewCellStyle1->ForeColor = System::Drawing::SystemColors::WindowText;
			dataGridViewCellStyle1->SelectionBackColor = System::Drawing::SystemColors::Highlight;
			dataGridViewCellStyle1->SelectionForeColor = System::Drawing::SystemColors::HighlightText;
			dataGridViewCellStyle1->WrapMode = System::Windows::Forms::DataGridViewTriState::True;
			this->dataGridView1->RowHeadersDefaultCellStyle = dataGridViewCellStyle1;
			this->dataGridView1->RowHeadersVisible = false;
			this->dataGridView1->RowHeadersWidth = 51;
			this->dataGridView1->RowTemplate->Height = 24;
			this->dataGridView1->Size = System::Drawing::Size(275, 108);
			this->dataGridView1->TabIndex = 25;
			// Configuración necesaria para que SelectionChanged funcione correctamente al cambiar filas.
			// FullRowSelect garantiza que al hacer clic en cualquier celda se seleccione la fila completa.
			// MultiSelect = false evita selecciones múltiples que complican la lógica del handler.
			this->dataGridView1->MultiSelect = false;
			
			this->dataGridView1->SelectionMode = System::Windows::Forms::DataGridViewSelectionMode::FullRowSelect;
			//
			this->dataGridView1->CellContentClick += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &Linea_de_Ensamblaje::dataGridView1_CellContentClick);
			this->dataGridView1->SelectionChanged += gcnew System::EventHandler(this, &Linea_de_Ensamblaje::dataGridView1_SelectionChanged);
			// 
			// Column1
			// 
			this->Column1->HeaderText = L"ID";
			this->Column1->MinimumWidth = 6;
			this->Column1->Name = L"Column1";
			// 
			// Rol
			// 
			this->Rol->HeaderText = L"Índice Actual";
			this->Rol->MinimumWidth = 6;
			this->Rol->Name = L"Rol";
			// 
			// Column2
			// 
			this->Column2->HeaderText = L"Sec. Aprobada";
			this->Column2->MinimumWidth = 6;
			this->Column2->Name = L"Column2";
			// 
			// panel1
			// 
			this->panel1->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(22)), static_cast<System::Int32>(static_cast<System::Byte>(32)),
				static_cast<System::Int32>(static_cast<System::Byte>(50)));
			this->panel1->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->panel1->Controls->Add(this->button2);
			this->panel1->Controls->Add(this->button1);
			this->panel1->Location = System::Drawing::Point(320, 193);
			this->panel1->Margin = System::Windows::Forms::Padding(2);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(382, 108);
			this->panel1->TabIndex = 26;
			// 
			// button2
			// 
			this->button2->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(239)), static_cast<System::Int32>(static_cast<System::Byte>(68)),
				static_cast<System::Int32>(static_cast<System::Byte>(68)));
			this->button2->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->button2->FlatAppearance->BorderColor = System::Drawing::Color::White;
			this->button2->FlatAppearance->BorderSize = 0;
			this->button2->FlatAppearance->CheckedBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(245)),
				static_cast<System::Int32>(static_cast<System::Byte>(158)), static_cast<System::Int32>(static_cast<System::Byte>(11)));
			this->button2->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->button2->ForeColor = System::Drawing::Color::Black;
			this->button2->Location = System::Drawing::Point(185, 20);
			this->button2->Margin = System::Windows::Forms::Padding(2);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(154, 37);
			this->button2->TabIndex = 19;
			this->button2->Text = L"  Desaprobar secuencia";
			this->button2->UseVisualStyleBackColor = false;
			this->button2->Click += gcnew System::EventHandler(this, &Linea_de_Ensamblaje::button2_Click);
			// 
			// button1
			// 
			this->button1->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(22)), static_cast<System::Int32>(static_cast<System::Byte>(163)),
				static_cast<System::Int32>(static_cast<System::Byte>(74)));
			this->button1->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->button1->FlatAppearance->BorderColor = System::Drawing::Color::White;
			this->button1->FlatAppearance->BorderSize = 0;
			this->button1->FlatAppearance->CheckedBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(245)),
				static_cast<System::Int32>(static_cast<System::Byte>(158)), static_cast<System::Int32>(static_cast<System::Byte>(11)));
			this->button1->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->button1->ForeColor = System::Drawing::Color::Black;
			this->button1->Location = System::Drawing::Point(17, 20);
			this->button1->Margin = System::Windows::Forms::Padding(2);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(154, 37);
			this->button1->TabIndex = 18;
			this->button1->Text = L"  Aprobar secuencia";
			this->button1->UseVisualStyleBackColor = false;
			this->button1->Click += gcnew System::EventHandler(this, &Linea_de_Ensamblaje::button1_Click);
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(245)), static_cast<System::Int32>(static_cast<System::Byte>(158)),
				static_cast<System::Int32>(static_cast<System::Byte>(11)));
			this->label4->Location = System::Drawing::Point(28, 312);
			this->label4->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(104, 13);
			this->label4->TabIndex = 27;
			this->label4->Text = L"Líneas configuradas";
			// 
			// dataGridView2
			// 
			this->dataGridView2->AutoSizeColumnsMode = System::Windows::Forms::DataGridViewAutoSizeColumnsMode::Fill;
			this->dataGridView2->BackgroundColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(15)),
				static_cast<System::Int32>(static_cast<System::Byte>(23)), static_cast<System::Int32>(static_cast<System::Byte>(42)));
			this->dataGridView2->ColumnHeadersBorderStyle = System::Windows::Forms::DataGridViewHeaderBorderStyle::Single;
			this->dataGridView2->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView2->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(5) {
				this->dataGridViewTextBoxColumn1,
					this->dataGridViewTextBoxColumn2, this->dataGridViewTextBoxColumn3, this->Column3, this->Column4
			});
			this->dataGridView2->Cursor = System::Windows::Forms::Cursors::Default;
			this->dataGridView2->EnableHeadersVisualStyles = false;
			this->dataGridView2->GridColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->dataGridView2->Location = System::Drawing::Point(22, 327);
			this->dataGridView2->Margin = System::Windows::Forms::Padding(2);
			this->dataGridView2->Name = L"dataGridView2";
			this->dataGridView2->RowHeadersBorderStyle = System::Windows::Forms::DataGridViewHeaderBorderStyle::Single;
			dataGridViewCellStyle2->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleLeft;
			dataGridViewCellStyle2->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(30)), static_cast<System::Int32>(static_cast<System::Byte>(58)),
				static_cast<System::Int32>(static_cast<System::Byte>(95)));
			dataGridViewCellStyle2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 7.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			dataGridViewCellStyle2->ForeColor = System::Drawing::SystemColors::WindowText;
			dataGridViewCellStyle2->SelectionBackColor = System::Drawing::SystemColors::Highlight;
			dataGridViewCellStyle2->SelectionForeColor = System::Drawing::SystemColors::HighlightText;
			dataGridViewCellStyle2->WrapMode = System::Windows::Forms::DataGridViewTriState::True;
			this->dataGridView2->RowHeadersDefaultCellStyle = dataGridViewCellStyle2;
			this->dataGridView2->RowHeadersVisible = false;
			this->dataGridView2->RowHeadersWidth = 51;
			this->dataGridView2->RowTemplate->Height = 24;
			this->dataGridView2->Size = System::Drawing::Size(654, 108);
			this->dataGridView2->TabIndex = 28;
			// 
			// dataGridViewTextBoxColumn1
			// 
			this->dataGridViewTextBoxColumn1->HeaderText = L"Pos.";
			this->dataGridViewTextBoxColumn1->MinimumWidth = 6;
			this->dataGridViewTextBoxColumn1->Name = L"dataGridViewTextBoxColumn1";
			// 
			// dataGridViewTextBoxColumn2
			// 
			this->dataGridViewTextBoxColumn2->HeaderText = L"Tipo";
			this->dataGridViewTextBoxColumn2->MinimumWidth = 6;
			this->dataGridViewTextBoxColumn2->Name = L"dataGridViewTextBoxColumn2";
			// 
			// dataGridViewTextBoxColumn3
			// 
			this->dataGridViewTextBoxColumn3->HeaderText = L"ID Pieza";
			this->dataGridViewTextBoxColumn3->MinimumWidth = 6;
			this->dataGridViewTextBoxColumn3->Name = L"dataGridViewTextBoxColumn3";
			// 
			// Column3
			// 
			this->Column3->HeaderText = L"Material";
			this->Column3->MinimumWidth = 6;
			this->Column3->Name = L"Column3";
			// 
			// Column4
			// 
			this->Column4->HeaderText = L"Estado";
			this->Column4->MinimumWidth = 6;
			this->Column4->Name = L"Column4";
			// 
			// panel7
			// 
			this->panel7->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(49)), static_cast<System::Int32>(static_cast<System::Byte>(108)),
				static_cast<System::Int32>(static_cast<System::Byte>(205)));
			this->panel7->Controls->Add(this->panel8);
			this->panel7->Location = System::Drawing::Point(24, 448);
			this->panel7->Margin = System::Windows::Forms::Padding(2);
			this->panel7->Name = L"panel7";
			this->panel7->Size = System::Drawing::Size(652, 38);
			this->panel7->TabIndex = 29;
			// 
			// panel8
			// 
			this->panel8->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(15)), static_cast<System::Int32>(static_cast<System::Byte>(23)),
				static_cast<System::Int32>(static_cast<System::Byte>(42)));
			this->panel8->Controls->Add(this->label7);
			this->panel8->Location = System::Drawing::Point(2, 2);
			this->panel8->Margin = System::Windows::Forms::Padding(2);
			this->panel8->Name = L"panel8";
			this->panel8->Size = System::Drawing::Size(647, 33);
			this->panel8->TabIndex = 30;
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(49)), static_cast<System::Int32>(static_cast<System::Byte>(108)),
				static_cast<System::Int32>(static_cast<System::Byte>(205)));
			this->label7->Location = System::Drawing::Point(2, 11);
			this->label7->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(468, 13);
			this->label7->TabIndex = 30;
			this->label7->Text = L"  El Jefe puede aprobar o desaprobar la secuencia. Solo el Gestor puede agregar p"
				L"iezas a la cola.";
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label8->ForeColor = System::Drawing::Color::White;
			this->label8->Location = System::Drawing::Point(27, 25);
			this->label8->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label8->Name = L"label8";
			this->label8->RightToLeft = System::Windows::Forms::RightToLeft::No;
			this->label8->Size = System::Drawing::Size(153, 16);
			this->label8->TabIndex = 30;
			this->label8->Text = L"Línea de Ensamblaje";
			// 
			// Linea_de_Ensamblaje
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(30)), static_cast<System::Int32>(static_cast<System::Byte>(40)),
				static_cast<System::Int32>(static_cast<System::Byte>(58)));
			this->ClientSize = System::Drawing::Size(756, 514);
			this->Controls->Add(this->label8);
			this->Controls->Add(this->panel7);
			this->Controls->Add(this->dataGridView2);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->panel1);
			this->Controls->Add(this->dataGridView1);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->panel5);
			this->Controls->Add(this->panel3);
			this->Controls->Add(this->panel9);
			this->Controls->Add(this->panel4);
			this->Controls->Add(this->panel6);
			this->Controls->Add(this->panel2);
			this->Margin = System::Windows::Forms::Padding(2);
			this->Name = L"Linea_de_Ensamblaje";
			this->Text = L"Linea_de_Ensamblaje";
			this->Load += gcnew System::EventHandler(this, &Linea_de_Ensamblaje::Linea_de_Ensamblaje_Load);
			this->panel5->ResumeLayout(false);
			this->panel5->PerformLayout();
			this->panel3->ResumeLayout(false);
			this->panel3->PerformLayout();
			this->panel6->ResumeLayout(false);
			this->panel6->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->EndInit();
			this->panel1->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView2))->EndInit();
			this->panel7->ResumeLayout(false);
			this->panel8->ResumeLayout(false);
			this->panel8->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
		void CargarLineas() {
			dataGridView1->Rows->Clear();
			auto lineas = ctrlLinea->obtenerTodos();

			for each (LineaEnsamblajeModel ^ l in lineas) {
				dataGridView1->Rows->Add(
					l->Id,
					l->IndiceActual.ToString(),
					l->SecuenciaAprobada ? "SI" : "NO"
				);
			}
			// KPIs con primera línea por defecto
			if (lineas->Count > 0) {
				lineaSeleccionada = lineas[0];
				ActualizarKPIs();
				CargarColaPiezas();
			}
			else {
				label6->Text = "SIN DATOS";
				label6->ForeColor = Drawing::Color::Gray;
				label10->Text = "0";
				label12->Text = "0";
				dataGridView2->Rows->Clear();
			}
		}


		void ActualizarKPIs() {
			if (lineaSeleccionada == nullptr) return;

			label6->Text = lineaSeleccionada->SecuenciaAprobada ? "APROBADA" : "PENDIENTE";
			label6->ForeColor = lineaSeleccionada->SecuenciaAprobada
				? Drawing::Color::FromArgb(0, 200, 100)
				: Drawing::Color::Orange;
			label10->Text = lineaSeleccionada->ColaPiezas->Count.ToString();
			label12->Text = lineaSeleccionada->IndiceActual.ToString();
		}

		void CargarColaPiezas() {
			dataGridView2->Rows->Clear();
			if (lineaSeleccionada == nullptr) return;

			int pos = 0;
			for each (PiezaModel ^ p in lineaSeleccionada->ColaPiezas) {
				PanelLateralModel^ pl = dynamic_cast<PanelLateralModel^>(p);
				String^ tipo = (pl != nullptr) ? "Panel Lateral" : "Estructura Techo";

				dataGridView2->Rows->Add(pos.ToString(), tipo, p->Id, p->Material, p->Estado.ToString());

				Drawing::Color color;
				switch (p->Estado) {
				case EstadoPieza::DISPONIBLE: color = Drawing::Color::FromArgb(0, 200, 100); break;
				case EstadoPieza::EN_PROCESO: color = Drawing::Color::Orange; break;
				case EstadoPieza::ENSAMBLADA: color = Drawing::Color::CornflowerBlue; break;
				case EstadoPieza::DEFECTUOSA: color = Drawing::Color::FromArgb(200, 40, 40); break;
				default: color = Drawing::Color::White; break;
				}
				dataGridView2->Rows[pos]->Cells[4]->Style->ForeColor = color;
				pos++;
			}
		}





	private: System::Void label6_Click(System::Object^ sender, System::EventArgs^ e) {
	}
private: System::Void Linea_de_Ensamblaje_Load(System::Object^ sender, System::EventArgs^ e) {
	CargarLineas();
}
private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {

	if (lineaSeleccionada == nullptr) return;

	// Validar que no haya otra línea ya aprobada
	for each (LineaEnsamblajeModel ^ l in ctrlLinea->obtenerTodos())
	{
		if (l->SecuenciaAprobada && l->Id != lineaSeleccionada->Id)
		{
			MessageBox::Show("Ya hay una línea aprobada activa: L-" + l->Id +
				"\nDesapruébala primero antes de aprobar otra.",
				"Línea activa", MessageBoxButtons::OK, MessageBoxIcon::Warning);
			return;
		}
	}

	ctrlLinea->modificar(lineaSeleccionada->Id, lineaSeleccionada->IndiceActual, true);
	ctrlLinea->cargarArchivo(ctrlPanel, ctrlTecho);
	lineaSeleccionada = ctrlLinea->buscarPorId(lineaSeleccionada->Id);
	CargarLineas();
}
private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {
	if (lineaSeleccionada == nullptr) return;
	ctrlLinea->modificar(lineaSeleccionada->Id, lineaSeleccionada->IndiceActual, false);
	ctrlLinea->cargarArchivo(ctrlPanel, ctrlTecho);
	lineaSeleccionada = ctrlLinea->buscarPorId(lineaSeleccionada->Id);
	CargarLineas();
}
private: System::Void dataGridView1_CellContentClick(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e) {
}
	   // Al cambiar la fila seleccionada, se actualiza lineaSeleccionada con la línea correspondiente
	   // y se recargan los KPIs y la cola de piezas del dataGridView2.
	   // lineaSeleccionada es el campo que mantiene el estado de la línea activa en este form.
private: System::Void dataGridView1_SelectionChanged(System::Object^ sender, System::EventArgs^ e) {
	if (dataGridView1->SelectedRows->Count == 0) return;

	String^ idSeleccionado = dataGridView1->SelectedRows[0]->Cells[0]->Value->ToString();
	lineaSeleccionada = ctrlLinea->buscarPorId(idSeleccionado);
	ActualizarKPIs();
	CargarColaPiezas();
}


};
}
