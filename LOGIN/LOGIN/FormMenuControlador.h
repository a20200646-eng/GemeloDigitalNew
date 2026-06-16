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
	using namespace GemeloDigitalController;
	using namespace GemeloDigitalModel;

	/// <summary>
	/// Resumen de FormMenuControlador
	/// </summary>
	public ref class FormMenuControlador : public System::Windows::Forms::Form
	{
	public:
		FormMenuControlador(void)
		{
			InitializeComponent();

			panelController = gcnew PanelLateralController();
			techoController = gcnew EstructuraTechoController();

			mostrandoPaneles = true;

			cargarPaneles();
			actualizarResumen();
		}

	protected:
		/// <summary>
		/// Limpiar los recursos que se estén usando.
		/// </summary>
		~FormMenuControlador()
		{
			if (components)
			{
				delete components;
			}
		}









	private: System::Windows::Forms::Label^ label6;
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::DataGridView^ dataGridView1;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Column1;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Rol;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Column2;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Column3;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Column4;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Column5;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Panel^ panel1;
	private: System::Windows::Forms::Button^ button3;
	private: System::Windows::Forms::TextBox^ textBox4;
	private: System::Windows::Forms::TextBox^ textBox3;
	private: System::Windows::Forms::TextBox^ textBox2;
	private: System::Windows::Forms::TextBox^ textBox1;
	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Button^ button6;
	private: System::Windows::Forms::Panel^ panel2;
	private: System::Windows::Forms::Panel^ panel3;
	private: System::Windows::Forms::Label^ label8;
	private: System::Windows::Forms::Label^ label7;
	private: System::Windows::Forms::Label^ label14;
	private: System::Windows::Forms::Label^ label15;
	private: System::Windows::Forms::Label^ label12;
	private: System::Windows::Forms::Label^ label13;
	private: System::Windows::Forms::Label^ label9;
	private: System::Windows::Forms::Label^ label11;
	private: System::Windows::Forms::Label^ label10;

	protected:

	private:

		

		bool mostrandoPaneles;

		/// <summary>
		/// Variable del diseñador necesaria.
		/// </summary>
		System::ComponentModel::Container ^components;
		PanelLateralController^ panelController;
	private: System::Windows::Forms::Label^ label16;
	private: System::Windows::Forms::ComboBox^ comboBox1;
	private: System::Windows::Forms::ComboBox^ comboBox2;
		   EstructuraTechoController^ techoController;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Método necesario para admitir el Diseñador. No se puede modificar
		/// el contenido de este método con el editor de código.
		/// </summary>
		void InitializeComponent(void)
		{
			System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle1 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(FormMenuControlador::typeid));
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
			this->Column1 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Rol = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column2 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column3 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column4 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column5 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->comboBox2 = (gcnew System::Windows::Forms::ComboBox());
			this->label16 = (gcnew System::Windows::Forms::Label());
			this->comboBox1 = (gcnew System::Windows::Forms::ComboBox());
			this->button6 = (gcnew System::Windows::Forms::Button());
			this->textBox4 = (gcnew System::Windows::Forms::TextBox());
			this->textBox3 = (gcnew System::Windows::Forms::TextBox());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->panel2 = (gcnew System::Windows::Forms::Panel());
			this->panel3 = (gcnew System::Windows::Forms::Panel());
			this->label14 = (gcnew System::Windows::Forms::Label());
			this->label15 = (gcnew System::Windows::Forms::Label());
			this->label12 = (gcnew System::Windows::Forms::Label());
			this->label13 = (gcnew System::Windows::Forms::Label());
			this->label9 = (gcnew System::Windows::Forms::Label());
			this->label11 = (gcnew System::Windows::Forms::Label());
			this->label10 = (gcnew System::Windows::Forms::Label());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->label7 = (gcnew System::Windows::Forms::Label());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->BeginInit();
			this->panel1->SuspendLayout();
			this->panel2->SuspendLayout();
			this->panel3->SuspendLayout();
			this->SuspendLayout();
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label6->ForeColor = System::Drawing::Color::White;
			this->label6->Location = System::Drawing::Point(27, 32);
			this->label6->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label6->Name = L"label6";
			this->label6->RightToLeft = System::Windows::Forms::RightToLeft::No;
			this->label6->Size = System::Drawing::Size(148, 16);
			this->label6->TabIndex = 11;
			this->label6->Text = L"Inventario de Piezas";
			// 
			// button1
			// 
			this->button1->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(22)), static_cast<System::Int32>(static_cast<System::Byte>(32)),
				static_cast<System::Int32>(static_cast<System::Byte>(50)));
			this->button1->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->button1->FlatAppearance->BorderColor = System::Drawing::SystemColors::Window;
			this->button1->FlatAppearance->BorderSize = 0;
			this->button1->FlatAppearance->MouseDownBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(245)),
				static_cast<System::Int32>(static_cast<System::Byte>(158)), static_cast<System::Int32>(static_cast<System::Byte>(11)));
			this->button1->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button1->ForeColor = System::Drawing::Color::White;
			this->button1->Location = System::Drawing::Point(41, 72);
			this->button1->Margin = System::Windows::Forms::Padding(2);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(273, 41);
			this->button1->TabIndex = 12;
			this->button1->Text = L"Paneles Laterales";
			this->button1->UseVisualStyleBackColor = false;
			this->button1->Click += gcnew System::EventHandler(this, &FormMenuControlador::button1_Click);
			// 
			// button2
			// 
			this->button2->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(22)), static_cast<System::Int32>(static_cast<System::Byte>(32)),
				static_cast<System::Int32>(static_cast<System::Byte>(50)));
			this->button2->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->button2->FlatAppearance->BorderColor = System::Drawing::SystemColors::Window;
			this->button2->FlatAppearance->BorderSize = 0;
			this->button2->FlatAppearance->MouseDownBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(245)),
				static_cast<System::Int32>(static_cast<System::Byte>(158)), static_cast<System::Int32>(static_cast<System::Byte>(11)));
			this->button2->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button2->ForeColor = System::Drawing::Color::White;
			this->button2->Location = System::Drawing::Point(371, 72);
			this->button2->Margin = System::Windows::Forms::Padding(2);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(336, 41);
			this->button2->TabIndex = 13;
			this->button2->Text = L"Estructuras Techo";
			this->button2->UseVisualStyleBackColor = false;
			this->button2->Click += gcnew System::EventHandler(this, &FormMenuControlador::button2_Click);
			// 
			// dataGridView1
			// 
			this->dataGridView1->AutoSizeColumnsMode = System::Windows::Forms::DataGridViewAutoSizeColumnsMode::Fill;
			this->dataGridView1->BackgroundColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(15)),
				static_cast<System::Int32>(static_cast<System::Byte>(23)), static_cast<System::Int32>(static_cast<System::Byte>(42)));
			this->dataGridView1->ColumnHeadersBorderStyle = System::Windows::Forms::DataGridViewHeaderBorderStyle::Single;
			this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView1->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(6) {
				this->Column1,
					this->Rol, this->Column2, this->Column3, this->Column4, this->Column5
			});
			this->dataGridView1->Cursor = System::Windows::Forms::Cursors::Default;
			this->dataGridView1->EnableHeadersVisualStyles = false;
			this->dataGridView1->GridColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->dataGridView1->Location = System::Drawing::Point(41, 163);
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
			this->dataGridView1->Size = System::Drawing::Size(858, 130);
			this->dataGridView1->TabIndex = 18;
			this->dataGridView1->CellContentClick += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &FormMenuControlador::dataGridView1_CellContentClick);
			// 
			// Column1
			// 
			this->Column1->HeaderText = L"ID";
			this->Column1->MinimumWidth = 6;
			this->Column1->Name = L"Column1";
			// 
			// Rol
			// 
			this->Rol->HeaderText = L"Material";
			this->Rol->MinimumWidth = 6;
			this->Rol->Name = L"Rol";
			// 
			// Column2
			// 
			this->Column2->HeaderText = L"Peso (kg)";
			this->Column2->MinimumWidth = 6;
			this->Column2->Name = L"Column2";
			// 
			// Column3
			// 
			this->Column3->HeaderText = L"Estado";
			this->Column3->MinimumWidth = 6;
			this->Column3->Name = L"Column3";
			// 
			// Column4
			// 
			this->Column4->HeaderText = L"Lado";
			this->Column4->MinimumWidth = 6;
			this->Column4->Name = L"Column4";
			// 
			// Column5
			// 
			this->Column5->HeaderText = L"Anclajes";
			this->Column5->MinimumWidth = 6;
			this->Column5->Name = L"Column5";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 7.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label3->ForeColor = System::Drawing::Color::White;
			this->label3->Location = System::Drawing::Point(14, 16);
			this->label3->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(108, 13);
			this->label3->TabIndex = 19;
			this->label3->Text = L"Agregar nueva pieza:";
			// 
			// panel1
			// 
			this->panel1->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(22)), static_cast<System::Int32>(static_cast<System::Byte>(32)),
				static_cast<System::Int32>(static_cast<System::Byte>(50)));
			this->panel1->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->panel1->Controls->Add(this->comboBox2);
			this->panel1->Controls->Add(this->label16);
			this->panel1->Controls->Add(this->comboBox1);
			this->panel1->Controls->Add(this->button6);
			this->panel1->Controls->Add(this->textBox4);
			this->panel1->Controls->Add(this->textBox3);
			this->panel1->Controls->Add(this->textBox2);
			this->panel1->Controls->Add(this->textBox1);
			this->panel1->Controls->Add(this->button3);
			this->panel1->Controls->Add(this->label5);
			this->panel1->Controls->Add(this->label4);
			this->panel1->Controls->Add(this->label2);
			this->panel1->Controls->Add(this->label1);
			this->panel1->Controls->Add(this->label3);
			this->panel1->Location = System::Drawing::Point(48, 319);
			this->panel1->Margin = System::Windows::Forms::Padding(2);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(880, 166);
			this->panel1->TabIndex = 20;
			// 
			// comboBox2
			// 
			this->comboBox2->FormattingEnabled = true;
			this->comboBox2->Location = System::Drawing::Point(494, 65);
			this->comboBox2->Name = L"comboBox2";
			this->comboBox2->Size = System::Drawing::Size(152, 21);
			this->comboBox2->TabIndex = 31;
			this->comboBox2->SelectedIndexChanged += gcnew System::EventHandler(this, &FormMenuControlador::comboBox2_SelectedIndexChanged);
			// 
			// label16
			// 
			this->label16->AutoSize = true;
			this->label16->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 7.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label16->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(142)), static_cast<System::Int32>(static_cast<System::Byte>(157)),
				static_cast<System::Int32>(static_cast<System::Byte>(177)));
			this->label16->Location = System::Drawing::Point(491, 108);
			this->label16->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label16->Name = L"label16";
			this->label16->Size = System::Drawing::Size(98, 13);
			this->label16->TabIndex = 30;
			this->label16->Text = L"Estacion Asignada:";
			this->label16->Click += gcnew System::EventHandler(this, &FormMenuControlador::label16_Click);
			// 
			// comboBox1
			// 
			this->comboBox1->FormattingEnabled = true;
			this->comboBox1->Location = System::Drawing::Point(494, 128);
			this->comboBox1->Name = L"comboBox1";
			this->comboBox1->Size = System::Drawing::Size(152, 21);
			this->comboBox1->TabIndex = 29;
			// 
			// button6
			// 
			this->button6->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(220)), static_cast<System::Int32>(static_cast<System::Byte>(38)),
				static_cast<System::Int32>(static_cast<System::Byte>(38)));
			this->button6->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->button6->FlatAppearance->BorderColor = System::Drawing::Color::White;
			this->button6->FlatAppearance->BorderSize = 0;
			this->button6->FlatAppearance->MouseDownBackColor = System::Drawing::Color::White;
			this->button6->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->button6->Location = System::Drawing::Point(280, 108);
			this->button6->Margin = System::Windows::Forms::Padding(2);
			this->button6->Name = L"button6";
			this->button6->Size = System::Drawing::Size(157, 41);
			this->button6->TabIndex = 28;
			this->button6->Text = L"Eliminar";
			this->button6->UseVisualStyleBackColor = false;
			this->button6->Click += gcnew System::EventHandler(this, &FormMenuControlador::button6_Click);
			// 
			// textBox4
			// 
			this->textBox4->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(30)), static_cast<System::Int32>(static_cast<System::Byte>(41)),
				static_cast<System::Int32>(static_cast<System::Byte>(59)));
			this->textBox4->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->textBox4->ForeColor = System::Drawing::Color::White;
			this->textBox4->Location = System::Drawing::Point(689, 65);
			this->textBox4->Margin = System::Windows::Forms::Padding(2);
			this->textBox4->Name = L"textBox4";
			this->textBox4->Size = System::Drawing::Size(152, 20);
			this->textBox4->TabIndex = 27;
			// 
			// textBox3
			// 
			this->textBox3->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(30)), static_cast<System::Int32>(static_cast<System::Byte>(41)),
				static_cast<System::Int32>(static_cast<System::Byte>(59)));
			this->textBox3->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->textBox3->ForeColor = System::Drawing::Color::White;
			this->textBox3->Location = System::Drawing::Point(494, 65);
			this->textBox3->Margin = System::Windows::Forms::Padding(2);
			this->textBox3->Name = L"textBox3";
			this->textBox3->Size = System::Drawing::Size(152, 20);
			this->textBox3->TabIndex = 26;
			// 
			// textBox2
			// 
			this->textBox2->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(30)), static_cast<System::Int32>(static_cast<System::Byte>(41)),
				static_cast<System::Int32>(static_cast<System::Byte>(59)));
			this->textBox2->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->textBox2->ForeColor = System::Drawing::Color::White;
			this->textBox2->Location = System::Drawing::Point(266, 65);
			this->textBox2->Margin = System::Windows::Forms::Padding(2);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(152, 20);
			this->textBox2->TabIndex = 25;
			// 
			// textBox1
			// 
			this->textBox1->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(30)), static_cast<System::Int32>(static_cast<System::Byte>(41)),
				static_cast<System::Int32>(static_cast<System::Byte>(59)));
			this->textBox1->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->textBox1->ForeColor = System::Drawing::Color::White;
			this->textBox1->Location = System::Drawing::Point(32, 65);
			this->textBox1->Margin = System::Windows::Forms::Padding(2);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(152, 20);
			this->textBox1->TabIndex = 24;
			// 
			// button3
			// 
			this->button3->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(245)), static_cast<System::Int32>(static_cast<System::Byte>(158)),
				static_cast<System::Int32>(static_cast<System::Byte>(11)));
			this->button3->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->button3->FlatAppearance->BorderColor = System::Drawing::Color::White;
			this->button3->FlatAppearance->BorderSize = 0;
			this->button3->FlatAppearance->MouseDownBackColor = System::Drawing::Color::White;
			this->button3->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button3->ForeColor = System::Drawing::Color::Black;
			this->button3->Location = System::Drawing::Point(43, 108);
			this->button3->Margin = System::Windows::Forms::Padding(2);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(208, 41);
			this->button3->TabIndex = 21;
			this->button3->Text = L"Agregar Panel";
			this->button3->UseVisualStyleBackColor = false;
			this->button3->Click += gcnew System::EventHandler(this, &FormMenuControlador::button3_Click);
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 7.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label5->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(142)), static_cast<System::Int32>(static_cast<System::Byte>(157)),
				static_cast<System::Int32>(static_cast<System::Byte>(177)));
			this->label5->Location = System::Drawing::Point(687, 39);
			this->label5->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(50, 13);
			this->label5->TabIndex = 23;
			this->label5->Text = L"Anclajes:";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 7.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label4->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(142)), static_cast<System::Int32>(static_cast<System::Byte>(157)),
				static_cast<System::Int32>(static_cast<System::Byte>(177)));
			this->label4->Location = System::Drawing::Point(491, 39);
			this->label4->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(34, 13);
			this->label4->TabIndex = 22;
			this->label4->Text = L"Lado:";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 7.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label2->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(142)), static_cast<System::Int32>(static_cast<System::Byte>(157)),
				static_cast<System::Int32>(static_cast<System::Byte>(177)));
			this->label2->Location = System::Drawing::Point(264, 39);
			this->label2->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(34, 13);
			this->label2->TabIndex = 21;
			this->label2->Text = L"Peso:";
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 7.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(142)), static_cast<System::Int32>(static_cast<System::Byte>(157)),
				static_cast<System::Int32>(static_cast<System::Byte>(177)));
			this->label1->Location = System::Drawing::Point(29, 39);
			this->label1->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(47, 13);
			this->label1->TabIndex = 20;
			this->label1->Text = L"Material:";
			// 
			// panel2
			// 
			this->panel2->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(245)), static_cast<System::Int32>(static_cast<System::Byte>(158)),
				static_cast<System::Int32>(static_cast<System::Byte>(11)));
			this->panel2->BackgroundImageLayout = System::Windows::Forms::ImageLayout::None;
			this->panel2->Controls->Add(this->panel3);
			this->panel2->ForeColor = System::Drawing::SystemColors::ActiveBorder;
			this->panel2->Location = System::Drawing::Point(51, 514);
			this->panel2->Margin = System::Windows::Forms::Padding(2);
			this->panel2->Name = L"panel2";
			this->panel2->Size = System::Drawing::Size(877, 92);
			this->panel2->TabIndex = 21;
			// 
			// panel3
			// 
			this->panel3->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(26)), static_cast<System::Int32>(static_cast<System::Byte>(45)),
				static_cast<System::Int32>(static_cast<System::Byte>(71)));
			this->panel3->BackgroundImageLayout = System::Windows::Forms::ImageLayout::None;
			this->panel3->Controls->Add(this->label14);
			this->panel3->Controls->Add(this->label15);
			this->panel3->Controls->Add(this->label12);
			this->panel3->Controls->Add(this->label13);
			this->panel3->Controls->Add(this->label9);
			this->panel3->Controls->Add(this->label11);
			this->panel3->Controls->Add(this->label10);
			this->panel3->Controls->Add(this->label8);
			this->panel3->Controls->Add(this->label7);
			this->panel3->ForeColor = System::Drawing::SystemColors::ActiveBorder;
			this->panel3->Location = System::Drawing::Point(2, 2);
			this->panel3->Margin = System::Windows::Forms::Padding(2);
			this->panel3->Name = L"panel3";
			this->panel3->Size = System::Drawing::Size(872, 87);
			this->panel3->TabIndex = 22;
			// 
			// label14
			// 
			this->label14->AutoSize = true;
			this->label14->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 7.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label14->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(142)), static_cast<System::Int32>(static_cast<System::Byte>(157)),
				static_cast<System::Int32>(static_cast<System::Byte>(177)));
			this->label14->Location = System::Drawing::Point(647, 54);
			this->label14->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label14->Name = L"label14";
			this->label14->Size = System::Drawing::Size(70, 13);
			this->label14->TabIndex = 38;
			this->label14->Text = L"Ensambladas";
			// 
			// label15
			// 
			this->label15->AutoSize = true;
			this->label15->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 16.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label15->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(245)), static_cast<System::Int32>(static_cast<System::Byte>(158)),
				static_cast<System::Int32>(static_cast<System::Byte>(11)));
			this->label15->Location = System::Drawing::Point(601, 41);
			this->label15->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label15->Name = L"label15";
			this->label15->Size = System::Drawing::Size(25, 26);
			this->label15->TabIndex = 37;
			this->label15->Text = L"4";
			// 
			// label12
			// 
			this->label12->AutoSize = true;
			this->label12->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 7.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label12->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(142)), static_cast<System::Int32>(static_cast<System::Byte>(157)),
				static_cast<System::Int32>(static_cast<System::Byte>(177)));
			this->label12->Location = System::Drawing::Point(460, 54);
			this->label12->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label12->Name = L"label12";
			this->label12->Size = System::Drawing::Size(61, 13);
			this->label12->TabIndex = 36;
			this->label12->Text = L"En proceso";
			// 
			// label13
			// 
			this->label13->AutoSize = true;
			this->label13->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 16.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label13->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(245)), static_cast<System::Int32>(static_cast<System::Byte>(158)),
				static_cast<System::Int32>(static_cast<System::Byte>(11)));
			this->label13->Location = System::Drawing::Point(407, 41);
			this->label13->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label13->Name = L"label13";
			this->label13->Size = System::Drawing::Size(25, 26);
			this->label13->TabIndex = 35;
			this->label13->Text = L"1";
			// 
			// label9
			// 
			this->label9->AutoSize = true;
			this->label9->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 7.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label9->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(142)), static_cast<System::Int32>(static_cast<System::Byte>(157)),
				static_cast<System::Int32>(static_cast<System::Byte>(177)));
			this->label9->Location = System::Drawing::Point(222, 54);
			this->label9->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(98, 13);
			this->label9->TabIndex = 34;
			this->label9->Text = L"Techos disponibles";
			// 
			// label11
			// 
			this->label11->AutoSize = true;
			this->label11->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 16.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label11->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(245)), static_cast<System::Int32>(static_cast<System::Byte>(158)),
				static_cast<System::Int32>(static_cast<System::Byte>(11)));
			this->label11->Location = System::Drawing::Point(184, 41);
			this->label11->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label11->Name = L"label11";
			this->label11->Size = System::Drawing::Size(25, 26);
			this->label11->TabIndex = 33;
			this->label11->Text = L"2";
			// 
			// label10
			// 
			this->label10->AutoSize = true;
			this->label10->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 7.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label10->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(142)), static_cast<System::Int32>(static_cast<System::Byte>(157)),
				static_cast<System::Int32>(static_cast<System::Byte>(177)));
			this->label10->Location = System::Drawing::Point(57, 54);
			this->label10->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label10->Name = L"label10";
			this->label10->Size = System::Drawing::Size(100, 13);
			this->label10->TabIndex = 32;
			this->label10->Text = L"Paneles disponibles";
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 16.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label8->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(245)), static_cast<System::Int32>(static_cast<System::Byte>(158)),
				static_cast<System::Int32>(static_cast<System::Byte>(11)));
			this->label8->Location = System::Drawing::Point(22, 41);
			this->label8->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(25, 26);
			this->label8->TabIndex = 30;
			this->label8->Text = L"3";
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label7->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(245)), static_cast<System::Int32>(static_cast<System::Byte>(158)),
				static_cast<System::Int32>(static_cast<System::Byte>(11)));
			this->label7->Location = System::Drawing::Point(7, 9);
			this->label7->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(137, 18);
			this->label7->TabIndex = 29;
			this->label7->Text = L"Resumen de stock:";
			// 
			// FormMenuControlador
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(30)), static_cast<System::Int32>(static_cast<System::Byte>(40)),
				static_cast<System::Int32>(static_cast<System::Byte>(58)));
			this->ClientSize = System::Drawing::Size(965, 609);
			this->Controls->Add(this->panel2);
			this->Controls->Add(this->dataGridView1);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->panel1);
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->Margin = System::Windows::Forms::Padding(2);
			this->Name = L"FormMenuControlador";
			this->Text = L"FormMenuControlador";
			this->Load += gcnew System::EventHandler(this, &FormMenuControlador::FormMenuControlador_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->EndInit();
			this->panel1->ResumeLayout(false);
			this->panel1->PerformLayout();
			this->panel2->ResumeLayout(false);
			this->panel3->ResumeLayout(false);
			this->panel3->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

	private:



		void cargarPaneles()
		{
			dataGridView1->Rows->Clear();

			for each (PanelLateralModel ^ p in panelController->obtenerTodos())
			{
				// Estado legible
				String^ estadoStr;
				switch (p->Estado) {
				case EstadoPieza::DISPONIBLE:  estadoStr = "DISPONIBLE";  break;
				case EstadoPieza::EN_PROCESO:  estadoStr = "EN_PROCESO";  break;
				case EstadoPieza::ENSAMBLADA:  estadoStr = "ENSAMBLADA";  break;
				case EstadoPieza::DEFECTUOSA:  estadoStr = "DEFECTUOSA";  break;
				default:                       estadoStr = "DESCONOCIDO"; break;
				}

				// Lado legible
				String^ ladoStr = (p->Lado == LadoPanel::IZQUIERDO) ? "IZQUIERDO" : "DERECHO";

				dataGridView1->Rows->Add(p->Id, p->Material, p->Peso, estadoStr, ladoStr, p->PuntosAnclaje);
			}
		}

		void cargarTechos()
		{
			dataGridView1->Rows->Clear();

			for each (EstructuraTechoModel ^ t in techoController->obtenerTodos())
			{
				String^ estadoStr;
				switch (t->Estado) {
				case EstadoPieza::DISPONIBLE:  estadoStr = "DISPONIBLE";  break;
				case EstadoPieza::EN_PROCESO:  estadoStr = "EN_PROCESO";  break;
				case EstadoPieza::ENSAMBLADA:  estadoStr = "ENSAMBLADA";  break;
				case EstadoPieza::DEFECTUOSA:  estadoStr = "DEFECTUOSA";  break;
				default:                       estadoStr = "DESCONOCIDO"; break;
				}

				dataGridView1->Rows->Add(t->Id, t->Material, t->Peso, estadoStr, t->PuntosUnion, t->Anchura);
			}
		}

	void actualizarResumen() 
	{
		int panelesDisponibles = 0;
		int techosDisponibles = 0;

		int enProceso = 0;
		int ensambladas = 0;

		for each (PanelLateralModel ^ p in panelController->obtenerTodos()) 
		{
			if (p->Estado == EstadoPieza::DISPONIBLE)
				panelesDisponibles++;

			if (p->Estado == EstadoPieza::EN_PROCESO)
				enProceso++;

			if (p->Estado == EstadoPieza::ENSAMBLADA)
				ensambladas++;
		}

		for each (EstructuraTechoModel ^ t in techoController->obtenerTodos())
		{
			if (t->Estado == EstadoPieza::DISPONIBLE)
				techosDisponibles++;

			if (t->Estado == EstadoPieza::EN_PROCESO)
				enProceso++;

			if (t->Estado == EstadoPieza::ENSAMBLADA)
				ensambladas++;
		}

		label8->Text = panelesDisponibles.ToString();
		label11->Text = techosDisponibles.ToString();
		label13->Text = enProceso.ToString();
		label15->Text = ensambladas.ToString();
	}

	void CargarEstaciones()
	{
		comboBox1->Items->Clear();
		EstacionTrabajoController^ ctrlEst = gcnew EstacionTrabajoController();
		TipoEstacion filtro;
		if (mostrandoPaneles)
			filtro = (comboBox2->SelectedIndex == 1)
			? TipoEstacion::PANEL_DER
			: TipoEstacion::PANEL_IZQ;
		else
			filtro = TipoEstacion::TECHO;

		for each(EstacionTrabajoModel ^ e in ctrlEst->obtenerTodos())
			if (e->Tipo == filtro)
				comboBox1->Items->Add(e->Id + " (stock: " + e->CantidadPiezas + ")");

		if (comboBox1->Items->Count > 0)
			comboBox1->SelectedIndex = 0;
	}

	private: System::Void textBox1_TextChanged(System::Object^ sender, System::EventArgs^ e) {
	}
private: System::Void FormMenuControlador_Load(System::Object^ sender, System::EventArgs^ e) {
	mostrandoPaneles = true;
	button3->Text = "Agregar Panel";
	this->Column4->HeaderText = L"Lado";
	this->Column5->HeaderText = L"Anclajes";
	cargarPaneles();
	actualizarResumen();// Al cargar el formulario, actualizamos el resumen para mostrar los datos iniciales.
	comboBox2->Items->Clear();
	comboBox2->Items->Add("IZQUIERDO");
	comboBox2->Items->Add("DERECHO");
	comboBox2->SelectedIndex = 0;
	CargarEstaciones(); // Cargamos las estaciones disponibles para paneles al inicio.
}
private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
	// En button1_Click (Paneles):
	this->Column4->HeaderText = L"Lado";
	this->Column5->HeaderText = L"Anclajes";

	

	mostrandoPaneles = true;

	button3->Text = "Agregar Panel";
	label4->Text = "Lado:";
	label5->Text = "Anclajes:";

	cargarPaneles();

	comboBox2->Visible = true;  // lado
	comboBox2->Items->Clear();
	comboBox2->Items->Add("IZQUIERDO");
	comboBox2->Items->Add("DERECHO");
	comboBox2->SelectedIndex = 0;
	textBox3->Visible = false;
	CargarEstaciones();  // recarga comboBox1 según lado
}
private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {

	// En button2_Click (Techos):
	this->Column4->HeaderText = L"Pts Unión";
	this->Column5->HeaderText = L"Anchura (cm)";

	mostrandoPaneles = false;

	button3->Text = "Agregar Techo";
	label4->Text = "Anchura (cm):";
	label5->Text = "Pts Unión :"; 

	cargarTechos();
	comboBox2->Visible = false;
	textBox3->Visible = true;  // anchura sigue siendo textbox
	CargarEstaciones();
}
private: System::Void button3_Click(System::Object^ sender, System::EventArgs^ e) {
	if (textBox1->Text->Trim() == "" || textBox2->Text->Trim() == "" ||
		textBox4->Text->Trim() == "")
	{
		MessageBox::Show("Completa todos los campos obligatorios.", "Aviso",
			MessageBoxButtons::OK, MessageBoxIcon::Warning);
		return;
	}
	double peso;
	int anclajes;
	if (!Double::TryParse(textBox2->Text, peso) ||
		!Int32::TryParse(textBox4->Text, anclajes))
	{
		MessageBox::Show("Peso debe ser decimal. Anclajes debe ser entero.", "Error",
			MessageBoxButtons::OK, MessageBoxIcon::Warning);
		return;
	}


	if (mostrandoPaneles) 
	{

		int num = panelController->obtenerTodos()->Count + 1;
		String^ id = "PL-" + num.ToString("D3");

		LadoPanel lado = (comboBox2->SelectedIndex == 1)
			? LadoPanel::DERECHO : LadoPanel::IZQUIERDO;
		String^ estId = comboBox1->SelectedIndex >= 0
			? comboBox1->SelectedItem->ToString()->Substring(0, 7)->Trim()
			: "";
		panelController->agregar(id, textBox1->Text, peso, lado, anclajes, estId);

		// Incrementar stock de la estación
		EstacionTrabajoController^ ctrlEst = gcnew EstacionTrabajoController();
		EstacionTrabajoModel^ est = ctrlEst->buscarPorId(estId);
		if (est != nullptr)
			ctrlEst->modificar(estId, est->Tipo, est->CantidadPiezas + 1);
		cargarPaneles();

	}
	else 
	{

		int num = techoController->obtenerTodos()->Count + 1;
		String^ id = "ET-" + num.ToString("D3");

		String^ estId = comboBox1->SelectedIndex >= 0
			? comboBox1->SelectedItem->ToString()->Substring(0, 7)->Trim()
			: "";
		techoController->agregar(id, textBox1->Text, peso, anclajes,
			Double::Parse(textBox3->Text), estId);

		EstacionTrabajoController^ ctrlEst = gcnew EstacionTrabajoController();
		EstacionTrabajoModel^ est = ctrlEst->buscarPorId(estId);
		if (est != nullptr)
			ctrlEst->modificar(estId, est->Tipo, est->CantidadPiezas + 1);

		cargarTechos();
	}
	
	actualizarResumen();

	textBox1->Clear(); textBox2->Clear(); textBox3->Clear(); textBox4->Clear();
	MessageBox::Show("Pieza agregada.", "Éxito",
		MessageBoxButtons::OK, MessageBoxIcon::Information);

}
private: System::Void button6_Click(System::Object^ sender, System::EventArgs^ e) {
	if (dataGridView1->CurrentRow == nullptr) {
		MessageBox::Show("Selecciona una fila para eliminar.",
			"Aviso", MessageBoxButtons::OK, MessageBoxIcon::Warning);
		return;
	}

	String^ id = dataGridView1->CurrentRow->Cells[0]->Value->ToString();

	if (MessageBox::Show("¿Eliminar el registro con ID " + id + "?",
		"Confirmar", MessageBoxButtons::YesNo, MessageBoxIcon::Warning)
		!= System::Windows::Forms::DialogResult::Yes) return;

	if (mostrandoPaneles) {

		//no instanciamos PanelController nuevamente porque cargarPaneles usa su propio controller.
		panelController->eliminar(id);
		cargarPaneles();

	}
	else {
	
		techoController->eliminar(id);
		cargarTechos();
	}


	
	actualizarResumen();
	textBox1->Clear(); textBox2->Clear(); textBox3->Clear(); textBox4->Clear();
	MessageBox::Show("Registro eliminado.", "Éxito",
		MessageBoxButtons::OK, MessageBoxIcon::Information);
}
private: System::Void dataGridView1_CellContentClick(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e) {




}
private: System::Void label16_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void comboBox2_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {
	CargarEstaciones();
}
};
}
