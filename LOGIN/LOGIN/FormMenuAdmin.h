#pragma once
#include "FormRegistro.h"
namespace LOGIN {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Resumen de FormMenuAdmin
	/// </summary>
	public ref class FormMenuAdmin : public System::Windows::Forms::Form
	{
	public:
		FormMenuAdmin(void)
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
		~FormMenuAdmin()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ label6;
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::Button^ button3;
	private: System::Windows::Forms::Button^ button4;
	private: System::Windows::Forms::DataGridView^ dataGridView1;






	private: System::Windows::Forms::Panel^ panel1;
	private: System::Windows::Forms::Button^ button6;
	private: System::Windows::Forms::TextBox^ textBox3;
	private: System::Windows::Forms::TextBox^ textBox2;
	private: System::Windows::Forms::TextBox^ textBox1;
	private: System::Windows::Forms::Button^ button5;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Panel^ panel2;
	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Column1;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Rol;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Column2;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Column5;

	private: System::Windows::Forms::Button^ button7;
	private: System::Windows::Forms::Button^ button8;
	private: System::Windows::Forms::Button^ button10;
	private: System::Windows::Forms::Button^ button9;
	protected:

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
			System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle1 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(FormMenuAdmin::typeid));
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
			this->Column1 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Rol = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column2 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column5 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->button8 = (gcnew System::Windows::Forms::Button());
			this->button10 = (gcnew System::Windows::Forms::Button());
			this->button7 = (gcnew System::Windows::Forms::Button());
			this->button6 = (gcnew System::Windows::Forms::Button());
			this->textBox3 = (gcnew System::Windows::Forms::TextBox());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->button5 = (gcnew System::Windows::Forms::Button());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->button9 = (gcnew System::Windows::Forms::Button());
			this->panel2 = (gcnew System::Windows::Forms::Panel());
			this->label5 = (gcnew System::Windows::Forms::Label());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->BeginInit();
			this->panel1->SuspendLayout();
			this->panel2->SuspendLayout();
			this->SuspendLayout();
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Font = (gcnew System::Drawing::Font(L"MS Reference Sans Serif", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label6->ForeColor = System::Drawing::Color::White;
			this->label6->Location = System::Drawing::Point(70, 53);
			this->label6->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label6->Name = L"label6";
			this->label6->RightToLeft = System::Windows::Forms::RightToLeft::No;
			this->label6->Size = System::Drawing::Size(200, 22);
			this->label6->TabIndex = 12;
			this->label6->Text = L"Gestión de Usuarios";
			// 
			// button1
			// 
			this->button1->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(22)), static_cast<System::Int32>(static_cast<System::Byte>(32)),
				static_cast<System::Int32>(static_cast<System::Byte>(50)));
			this->button1->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->button1->FlatAppearance->BorderColor = System::Drawing::Color::White;
			this->button1->FlatAppearance->BorderSize = 0;
			this->button1->FlatAppearance->MouseDownBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(245)),
				static_cast<System::Int32>(static_cast<System::Byte>(158)), static_cast<System::Int32>(static_cast<System::Byte>(11)));
			this->button1->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button1->ForeColor = System::Drawing::Color::White;
			this->button1->Location = System::Drawing::Point(74, 93);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(206, 45);
			this->button1->TabIndex = 13;
			this->button1->Text = L"Administradores";
			this->button1->UseVisualStyleBackColor = false;
			this->button1->Click += gcnew System::EventHandler(this, &FormMenuAdmin::button1_Click);
			// 
			// button2
			// 
			this->button2->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(22)), static_cast<System::Int32>(static_cast<System::Byte>(32)),
				static_cast<System::Int32>(static_cast<System::Byte>(50)));
			this->button2->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->button2->FlatAppearance->BorderColor = System::Drawing::Color::White;
			this->button2->FlatAppearance->BorderSize = 0;
			this->button2->FlatAppearance->MouseDownBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(245)),
				static_cast<System::Int32>(static_cast<System::Byte>(158)), static_cast<System::Int32>(static_cast<System::Byte>(11)));
			this->button2->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button2->ForeColor = System::Drawing::Color::White;
			this->button2->Location = System::Drawing::Point(322, 93);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(206, 45);
			this->button2->TabIndex = 14;
			this->button2->Text = L"Jefes de Operaciones";
			this->button2->UseVisualStyleBackColor = false;
			this->button2->Click += gcnew System::EventHandler(this, &FormMenuAdmin::button2_Click);
			// 
			// button3
			// 
			this->button3->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(22)), static_cast<System::Int32>(static_cast<System::Byte>(32)),
				static_cast<System::Int32>(static_cast<System::Byte>(50)));
			this->button3->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->button3->FlatAppearance->BorderColor = System::Drawing::Color::White;
			this->button3->FlatAppearance->BorderSize = 0;
			this->button3->FlatAppearance->MouseDownBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(245)),
				static_cast<System::Int32>(static_cast<System::Byte>(158)), static_cast<System::Int32>(static_cast<System::Byte>(11)));
			this->button3->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button3->ForeColor = System::Drawing::Color::White;
			this->button3->Location = System::Drawing::Point(571, 93);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(206, 45);
			this->button3->TabIndex = 15;
			this->button3->Text = L"Operadores";
			this->button3->UseVisualStyleBackColor = false;
			this->button3->Click += gcnew System::EventHandler(this, &FormMenuAdmin::button3_Click);
			// 
			// button4
			// 
			this->button4->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(22)), static_cast<System::Int32>(static_cast<System::Byte>(32)),
				static_cast<System::Int32>(static_cast<System::Byte>(50)));
			this->button4->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->button4->FlatAppearance->BorderColor = System::Drawing::Color::White;
			this->button4->FlatAppearance->BorderSize = 0;
			this->button4->FlatAppearance->MouseDownBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(245)),
				static_cast<System::Int32>(static_cast<System::Byte>(158)), static_cast<System::Int32>(static_cast<System::Byte>(11)));
			this->button4->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button4->ForeColor = System::Drawing::Color::White;
			this->button4->Location = System::Drawing::Point(818, 93);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(206, 45);
			this->button4->TabIndex = 16;
			this->button4->Text = L"Gestores";
			this->button4->UseVisualStyleBackColor = false;
			this->button4->Click += gcnew System::EventHandler(this, &FormMenuAdmin::button4_Click);
			// 
			// dataGridView1
			// 
			this->dataGridView1->AutoSizeColumnsMode = System::Windows::Forms::DataGridViewAutoSizeColumnsMode::Fill;
			this->dataGridView1->BackgroundColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(15)),
				static_cast<System::Int32>(static_cast<System::Byte>(23)), static_cast<System::Int32>(static_cast<System::Byte>(42)));
			this->dataGridView1->ColumnHeadersBorderStyle = System::Windows::Forms::DataGridViewHeaderBorderStyle::Single;
			this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView1->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(4) {
				this->Column1,
					this->Rol, this->Column2, this->Column5
			});
			this->dataGridView1->Cursor = System::Windows::Forms::Cursors::Default;
			this->dataGridView1->EnableHeadersVisualStyles = false;
			this->dataGridView1->GridColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->dataGridView1->Location = System::Drawing::Point(74, 191);
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
			this->dataGridView1->Size = System::Drawing::Size(950, 160);
			this->dataGridView1->TabIndex = 19;
			// 
			// Column1
			// 
			this->Column1->HeaderText = L"ID";
			this->Column1->MinimumWidth = 6;
			this->Column1->Name = L"Column1";
			// 
			// Rol
			// 
			this->Rol->HeaderText = L"Nombre";
			this->Rol->MinimumWidth = 6;
			this->Rol->Name = L"Rol";
			// 
			// Column2
			// 
			this->Column2->HeaderText = L"Contraseña";
			this->Column2->MinimumWidth = 6;
			this->Column2->Name = L"Column2";
			// 
			// Column5
			// 
			this->Column5->HeaderText = L"Turno";
			this->Column5->MinimumWidth = 6;
			this->Column5->Name = L"Column5";
			// 
			// panel1
			// 
			this->panel1->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(22)), static_cast<System::Int32>(static_cast<System::Byte>(32)),
				static_cast<System::Int32>(static_cast<System::Byte>(50)));
			this->panel1->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->panel1->Controls->Add(this->button8);
			this->panel1->Controls->Add(this->button10);
			this->panel1->Controls->Add(this->button7);
			this->panel1->Controls->Add(this->button6);
			this->panel1->Controls->Add(this->textBox3);
			this->panel1->Controls->Add(this->textBox2);
			this->panel1->Controls->Add(this->textBox1);
			this->panel1->Controls->Add(this->button5);
			this->panel1->Controls->Add(this->label4);
			this->panel1->Controls->Add(this->label2);
			this->panel1->Controls->Add(this->label1);
			this->panel1->Controls->Add(this->label3);
			this->panel1->Controls->Add(this->button9);
			this->panel1->Location = System::Drawing::Point(74, 369);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(1044, 204);
			this->panel1->TabIndex = 21;
			// 
			// button8
			// 
			this->button8->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(22)), static_cast<System::Int32>(static_cast<System::Byte>(32)),
				static_cast<System::Int32>(static_cast<System::Byte>(50)));
			this->button8->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->button8->Cursor = System::Windows::Forms::Cursors::No;
			this->button8->FlatAppearance->BorderColor = System::Drawing::Color::White;
			this->button8->FlatAppearance->BorderSize = 0;
			this->button8->FlatAppearance->MouseDownBackColor = System::Drawing::Color::MintCream;
			this->button8->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button8->ForeColor = System::Drawing::Color::Orange;
			this->button8->Location = System::Drawing::Point(743, 132);
			this->button8->Name = L"button8";
			this->button8->Size = System::Drawing::Size(202, 50);
			this->button8->TabIndex = 32;
			this->button8->Text = L"Modificar Contraseña";
			this->button8->UseVisualStyleBackColor = false;
			this->button8->Click += gcnew System::EventHandler(this, &FormMenuAdmin::button8_Click);
			// 
			// button10
			// 
			this->button10->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(245)), static_cast<System::Int32>(static_cast<System::Byte>(158)),
				static_cast<System::Int32>(static_cast<System::Byte>(11)));
			this->button10->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->button10->FlatAppearance->BorderColor = System::Drawing::Color::White;
			this->button10->FlatAppearance->BorderSize = 0;
			this->button10->FlatAppearance->MouseDownBackColor = System::Drawing::Color::MintCream;
			this->button10->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button10->ForeColor = System::Drawing::Color::Black;
			this->button10->Location = System::Drawing::Point(739, 128);
			this->button10->Name = L"button10";
			this->button10->Size = System::Drawing::Size(210, 57);
			this->button10->TabIndex = 33;
			this->button10->Text = L"Agregar";
			this->button10->UseVisualStyleBackColor = false;
			// 
			// button7
			// 
			this->button7->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(22)), static_cast<System::Int32>(static_cast<System::Byte>(32)),
				static_cast<System::Int32>(static_cast<System::Byte>(50)));
			this->button7->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->button7->Cursor = System::Windows::Forms::Cursors::No;
			this->button7->FlatAppearance->BorderColor = System::Drawing::Color::White;
			this->button7->FlatAppearance->BorderSize = 0;
			this->button7->FlatAppearance->MouseDownBackColor = System::Drawing::Color::MintCream;
			this->button7->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button7->ForeColor = System::Drawing::Color::Orange;
			this->button7->Location = System::Drawing::Point(513, 133);
			this->button7->Name = L"button7";
			this->button7->Size = System::Drawing::Size(202, 50);
			this->button7->TabIndex = 29;
			this->button7->Text = L"Modificar Nombre ";
			this->button7->UseVisualStyleBackColor = false;
			this->button7->Click += gcnew System::EventHandler(this, &FormMenuAdmin::button7_Click);
			// 
			// button6
			// 
			this->button6->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(220)), static_cast<System::Int32>(static_cast<System::Byte>(38)),
				static_cast<System::Int32>(static_cast<System::Byte>(38)));
			this->button6->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->button6->FlatAppearance->BorderColor = System::Drawing::Color::White;
			this->button6->FlatAppearance->BorderSize = 0;
			this->button6->FlatAppearance->MouseDownBackColor = System::Drawing::Color::MintCream;
			this->button6->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button6->Location = System::Drawing::Point(268, 133);
			this->button6->Name = L"button6";
			this->button6->Size = System::Drawing::Size(202, 50);
			this->button6->TabIndex = 28;
			this->button6->Text = L"Eliminar";
			this->button6->UseVisualStyleBackColor = false;
			this->button6->Click += gcnew System::EventHandler(this, &FormMenuAdmin::button6_Click);
			// 
			// textBox3
			// 
			this->textBox3->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(30)), static_cast<System::Int32>(static_cast<System::Byte>(41)),
				static_cast<System::Int32>(static_cast<System::Byte>(59)));
			this->textBox3->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->textBox3->Location = System::Drawing::Point(513, 80);
			this->textBox3->Name = L"textBox3";
			this->textBox3->Size = System::Drawing::Size(202, 22);
			this->textBox3->TabIndex = 26;
			// 
			// textBox2
			// 
			this->textBox2->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(30)), static_cast<System::Int32>(static_cast<System::Byte>(41)),
				static_cast<System::Int32>(static_cast<System::Byte>(59)));
			this->textBox2->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->textBox2->Location = System::Drawing::Point(268, 80);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(202, 22);
			this->textBox2->TabIndex = 25;
			// 
			// textBox1
			// 
			this->textBox1->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(30)), static_cast<System::Int32>(static_cast<System::Byte>(41)),
				static_cast<System::Int32>(static_cast<System::Byte>(59)));
			this->textBox1->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->textBox1->Location = System::Drawing::Point(42, 80);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(199, 22);
			this->textBox1->TabIndex = 24;
			// 
			// button5
			// 
			this->button5->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(245)), static_cast<System::Int32>(static_cast<System::Byte>(158)),
				static_cast<System::Int32>(static_cast<System::Byte>(11)));
			this->button5->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->button5->FlatAppearance->BorderColor = System::Drawing::Color::White;
			this->button5->FlatAppearance->BorderSize = 0;
			this->button5->FlatAppearance->MouseDownBackColor = System::Drawing::Color::MintCream;
			this->button5->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button5->ForeColor = System::Drawing::Color::Black;
			this->button5->Location = System::Drawing::Point(42, 133);
			this->button5->Name = L"button5";
			this->button5->Size = System::Drawing::Size(199, 50);
			this->button5->TabIndex = 21;
			this->button5->Text = L"Agregar";
			this->button5->UseVisualStyleBackColor = false;
			this->button5->Click += gcnew System::EventHandler(this, &FormMenuAdmin::button5_Click);
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Font = (gcnew System::Drawing::Font(L"MS Reference Sans Serif", 7.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label4->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(142)), static_cast<System::Int32>(static_cast<System::Byte>(157)),
				static_cast<System::Int32>(static_cast<System::Byte>(177)));
			this->label4->Location = System::Drawing::Point(510, 48);
			this->label4->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(99, 16);
			this->label4->TabIndex = 22;
			this->label4->Text = L"Extra (turno):";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"MS Reference Sans Serif", 7.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label2->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(142)), static_cast<System::Int32>(static_cast<System::Byte>(157)),
				static_cast<System::Int32>(static_cast<System::Byte>(177)));
			this->label2->Location = System::Drawing::Point(265, 48);
			this->label2->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(75, 16);
			this->label2->TabIndex = 21;
			this->label2->Text = L"Password:";
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"MS Reference Sans Serif", 7.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(142)), static_cast<System::Int32>(static_cast<System::Byte>(157)),
				static_cast<System::Int32>(static_cast<System::Byte>(177)));
			this->label1->Location = System::Drawing::Point(39, 48);
			this->label1->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(56, 16);
			this->label1->TabIndex = 20;
			this->label1->Text = L"Nombre";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"MS Reference Sans Serif", 7.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label3->ForeColor = System::Drawing::Color::White;
			this->label3->Location = System::Drawing::Point(18, 20);
			this->label3->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(162, 16);
			this->label3->TabIndex = 19;
			this->label3->Text = L"Agregar nuevo Usuario:";
			// 
			// button9
			// 
			this->button9->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(245)), static_cast<System::Int32>(static_cast<System::Byte>(158)),
				static_cast<System::Int32>(static_cast<System::Byte>(11)));
			this->button9->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->button9->FlatAppearance->BorderColor = System::Drawing::Color::White;
			this->button9->FlatAppearance->BorderSize = 0;
			this->button9->FlatAppearance->MouseDownBackColor = System::Drawing::Color::MintCream;
			this->button9->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button9->ForeColor = System::Drawing::Color::Black;
			this->button9->Location = System::Drawing::Point(509, 129);
			this->button9->Name = L"button9";
			this->button9->Size = System::Drawing::Size(210, 57);
			this->button9->TabIndex = 31;
			this->button9->Text = L"Agregar";
			this->button9->UseVisualStyleBackColor = false;
			// 
			// panel2
			// 
			this->panel2->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(254)), static_cast<System::Int32>(static_cast<System::Byte>(249)),
				static_cast<System::Int32>(static_cast<System::Byte>(195)));
			this->panel2->Controls->Add(this->label5);
			this->panel2->Location = System::Drawing::Point(74, 585);
			this->panel2->Name = L"panel2";
			this->panel2->Size = System::Drawing::Size(1043, 103);
			this->panel2->TabIndex = 22;
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(39, 24);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(302, 16);
			this->label5->TabIndex = 0;
			this->label5->Text = L" El administrador no puede eliminarse a sí mismo.";
			// 
			// FormMenuAdmin
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(30)), static_cast<System::Int32>(static_cast<System::Byte>(40)),
				static_cast<System::Int32>(static_cast<System::Byte>(58)));
			this->ClientSize = System::Drawing::Size(1215, 936);
			this->Controls->Add(this->panel2);
			this->Controls->Add(this->panel1);
			this->Controls->Add(this->dataGridView1);
			this->Controls->Add(this->button4);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->label6);
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->Name = L"FormMenuAdmin";
			this->Text = L"FormMenuAdmin";
			this->Load += gcnew System::EventHandler(this, &FormMenuAdmin::FormMenuAdmin_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->EndInit();
			this->panel1->ResumeLayout(false);
			this->panel1->PerformLayout();
			this->panel2->ResumeLayout(false);
			this->panel2->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void label1_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void label2_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void btnCrear_Click(System::Object^ sender, System::EventArgs^ e) {
		FormRegistro^ f = gcnew FormRegistro();
		f->Show();
		this->Hide();
	}
	private: System::Void btnDesactivar_Click(System::Object^ sender, System::EventArgs^ e) {
	}

		   // === EVENTO DE CARGA DE LA INTERFAZ ===
	private: System::Void FormMenuAdmin_Load(System::Object^ sender, System::EventArgs^ e) {
		// Forzamos de manera automática la carga de la pestaña Administradores al arrancar
		button1_Click(this->button1, nullptr);
	}

		   // === BOTÓN SUPERIOR: ADMINISTRADORES ===
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) { // Administradores
		this->label3->Text = "AGREGAR NUEVO ADMINISTRADOR";
		this->label4->Text = "Turno (Mañana/Tarde/Noche):";
		this->textBox1->Clear();
		this->textBox2->Clear();
		this->textBox3->Clear();
		this->button5->Tag = "Admin";
		CargarUsuariosPorRol("Admin");
	}

		   // === BOTÓN SUPERIOR: JEFE DE OPERACIONES ===
	private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) { // Jefe de Operaciones
		this->label3->Text = "AGREGAR NUEVO JEFE DE OPERACIONES";
		this->label4->Text = "Turno (Mañana/Tarde/Noche):";
		this->textBox1->Clear();
		this->textBox2->Clear();
		this->textBox3->Clear();
		this->button5->Tag = "Jefe";
		CargarUsuariosPorRol("Jefe");
	}

		   // === BOTÓN SUPERIOR: OPERADORES ===
	private: System::Void button3_Click(System::Object^ sender, System::EventArgs^ e) { // Operadores
		this->label3->Text = "AGREGAR NUEVO OPERADOR";
		this->label4->Text = "Turno (Mañana/Tarde/Noche):";
		this->textBox1->Clear();
		this->textBox2->Clear();
		this->textBox3->Clear();
		this->button5->Tag = "Operador";
		CargarUsuariosPorRol("Operador");
	}

		   // === BOTÓN SUPERIOR: GESTORES ===
	private: System::Void button4_Click(System::Object^ sender, System::EventArgs^ e) { // Gestores
		this->label3->Text = "AGREGAR NUEVO GESTOR";
		this->label4->Text = "Turno (Mañana/Tarde/Noche):";
		this->textBox1->Clear();
		this->textBox2->Clear();
		this->textBox3->Clear();
		this->button5->Tag = "Gestor";
		CargarUsuariosPorRol("Gestor");
	}

		   // === BOTÓN ACCIÓN: AGREGAR / GUARDAR USUARIO ===
	private: System::Void button5_Click(System::Object^ sender, System::EventArgs^ e) {
		String^ usuario = this->textBox1->Text->Trim();
		String^ password = this->textBox2->Text->Trim();
		String^ turno = this->textBox3->Text->Trim();

		if (usuario == "" || password == "" || turno == "") {
			MessageBox::Show("Por favor, rellene todos los campos (Nombre, Contraseña y Turno).",
				"Campos Vacíos", MessageBoxButtons::OK, MessageBoxIcon::Warning);
			return;
		}

		if (usuario->Length < 4 || password->Length < 4) {
			MessageBox::Show("El Nombre y la Contraseña deben tener al menos 4 caracteres.",
				"Seguridad Insuficiente", MessageBoxButtons::OK, MessageBoxIcon::Warning);
			return;
		}

		if (usuario->Contains(",") || password->Contains(",") || turno->Contains(",")) {
			MessageBox::Show("No se permite el uso de comas ( , ) en ningún campo.",
				"Carácter No Válido", MessageBoxButtons::OK, MessageBoxIcon::Error);
			return;
		}

		String^ turnoMinuscula = turno->ToLower();
		if (turnoMinuscula == "mañana" || turnoMinuscula == "manana") { turno = "Mañana"; }
		else if (turnoMinuscula == "tarde") { turno = "Tarde"; }
		else if (turnoMinuscula == "noche") { turno = "Noche"; }
		else {
			MessageBox::Show("El turno ingresado no es válido.\n\nPor favor use: Mañana, Tarde o Noche.",
				"Turno Incorrecto", MessageBoxButtons::OK, MessageBoxIcon::Warning);
			return;
		}

		try {
			String^ rutaUsuarios = "usuarios.txt";
			String^ rolDinamico = (this->button5->Tag != nullptr) ? this->button5->Tag->ToString() : "Admin";
			String^ nuevaLinea = usuario + "," + password + "," + rolDinamico + "," + turno;

			System::IO::StreamWriter^ sw = gcnew System::IO::StreamWriter(rutaUsuarios, true);
			sw->WriteLine(nuevaLinea);
			sw->Close();

			MessageBox::Show("¡" + rolDinamico + " '" + usuario + "' registrado con éxito en el turno " + turno + "!",
				"Registro Guardado", MessageBoxButtons::OK, MessageBoxIcon::Information);

			this->textBox1->Clear();
			this->textBox2->Clear();
			this->textBox3->Clear();

			CargarUsuariosPorRol(rolDinamico);
		}
		catch (Exception^ ex) {
			MessageBox::Show("Error crítico al guardar en la persistencia: " + ex->Message,
				"Error de Archivo", MessageBoxButtons::OK, MessageBoxIcon::Error);
		}
	}

		   // === FUNCIÓN AUXILIAR: FILTRADO INTELIGENTE DE LA TABLA ===
	private: void CargarUsuariosPorRol(String^ rolFiltrar) {
		try {
			String^ rutaUsuarios = "usuarios.txt";
			this->dataGridView1->Rows->Clear();

			if (System::IO::File::Exists(rutaUsuarios)) {
				array<String^>^ lineas = System::IO::File::ReadAllLines(rutaUsuarios);

				for (int i = 0; i < lineas->Length; i++) {
					array<String^>^ datos = lineas[i]->Split(',');

					if (datos->Length >= 3) {
						String^ nombre = datos[0];
						String^ password = datos[1];
						String^ rol = datos[2];
						String^ turno = (datos->Length > 3) ? datos[3] : "Mañana";

						if (rol->Trim()->Equals(rolFiltrar->Trim(), StringComparison::OrdinalIgnoreCase)) {
							String^ idSimulado = "U00" + (i + 1);
							this->dataGridView1->Rows->Add(idSimulado, nombre, password, turno);
						}
					}
				}
			}
		}
		catch (Exception^ ex) {
			MessageBox::Show("Error al filtrar la tabla de usuarios: " + ex->Message, "Error");
		}
	}

		   // === EVENTO: SELECCIONAR USUARIO DE LA TABLA CON UN CLIC ===
	private: System::Void dataGridView1_CellClick(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e) {
		if (e->RowIndex >= 0) {
			this->textBox1->Text = this->dataGridView1->Rows[e->RowIndex]->Cells[1]->Value->ToString();
			this->textBox2->Text = this->dataGridView1->Rows[e->RowIndex]->Cells[2]->Value->ToString();
			this->textBox3->Text = this->dataGridView1->Rows[e->RowIndex]->Cells[3]->Value->ToString();
		}
	}

		   // === BOTÓN 7: MODIFICAR SOLO NOMBRE ===
	private: System::Void button7_Click(System::Object^ sender, System::EventArgs^ e) {
		if (this->dataGridView1->CurrentRow == nullptr) {
			MessageBox::Show("Por favor, seleccione primero el usuario que desea modificar en la tabla.", "Aviso", MessageBoxButtons::OK, MessageBoxIcon::Warning);
			return;
		}

		String^ nombreViejo = this->dataGridView1->CurrentRow->Cells[1]->Value->ToString();
		String^ nombreNuevo = this->textBox1->Text->Trim();
		String^ turnoActual = this->textBox3->Text->Trim();

		if (nombreNuevo == "" || nombreNuevo->Length < 4 || nombreNuevo->Contains(",")) {
			MessageBox::Show("El nuevo nombre no es válido (mínimo 4 caracteres y sin comas).", "Error de Validación", MessageBoxButtons::OK, MessageBoxIcon::Warning);
			return;
		}

		try {
			String^ rutaUsuarios = "usuarios.txt";
			array<String^>^ lineas = System::IO::File::ReadAllLines(rutaUsuarios);
			bool modificado = false;

			for (int i = 0; i < lineas->Length; i++) {
				array<String^>^ datos = lineas[i]->Split(',');
				if (datos->Length >= 3 && datos[0]->Trim()->Equals(nombreViejo, StringComparison::OrdinalIgnoreCase)) {
					lineas[i] = nombreNuevo + "," + datos[1] + "," + datos[2] + "," + turnoActual;
					modificado = true;
					break;
				}
			}

			if (!modificado) {
				MessageBox::Show("No se pudo localizar el registro original en el archivo.", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
				return;
			}

			System::IO::File::WriteAllLines(rutaUsuarios, lineas);
			MessageBox::Show("Nombre actualizado correctamente de '" + nombreViejo + "' a '" + nombreNuevo + "'.", "Éxito", MessageBoxButtons::OK, MessageBoxIcon::Information);

			String^ rolActual = (this->button5->Tag != nullptr) ? this->button5->Tag->ToString() : "Admin";
			CargarUsuariosPorRol(rolActual);
		}
		catch (Exception^ ex) {
			MessageBox::Show("Error al modificar nombre: " + ex->Message, "Error");
		}
	}

		   // === BOTÓN 8: MODIFICAR SOLO CONTRASEÑA ===
	private: System::Void button8_Click(System::Object^ sender, System::EventArgs^ e) {
		String^ usuario = this->textBox1->Text->Trim();
		String^ nuevaPassword = this->textBox2->Text->Trim();

		if (usuario == "" || nuevaPassword == "" || nuevaPassword->Length < 4 || nuevaPassword->Contains(",")) {
			MessageBox::Show("La contraseña o el usuario no son válidos (mínimo 4 caracteres y sin comas).", "Error de Validación", MessageBoxButtons::OK, MessageBoxIcon::Warning);
			return;
		}

		try {
			String^ rutaUsuarios = "usuarios.txt";
			array<String^>^ lineas = System::IO::File::ReadAllLines(rutaUsuarios);
			bool encontrado = false;

			for (int i = 0; i < lineas->Length; i++) {
				array<String^>^ datos = lineas[i]->Split(',');
				if (datos->Length >= 3 && datos[0]->Trim()->Equals(usuario, StringComparison::OrdinalIgnoreCase)) {
					String^ turnoSeguro = (datos->Length > 3) ? datos[3] : "Mañana";
					lineas[i] = datos[0] + "," + nuevaPassword + "," + datos[2] + "," + turnoSeguro;
					encontrado = true;
					break;
				}
			}

			if (!encontrado) {
				MessageBox::Show("No se encontró ningún usuario con el nombre '" + usuario + "' para modificar su contraseña.", "Usuario No Encontrado", MessageBoxButtons::OK, MessageBoxIcon::Warning);
				return;
			}

			System::IO::File::WriteAllLines(rutaUsuarios, lineas);
			MessageBox::Show("Contraseña de '" + usuario + "' actualizada con éxito.", "Éxito", MessageBoxButtons::OK, MessageBoxIcon::Information);

			String^ rolActual = (this->button5->Tag != nullptr) ? this->button5->Tag->ToString() : "Admin";
			CargarUsuariosPorRol(rolActual);
		}
		catch (Exception^ ex) {
			MessageBox::Show("Error al modificar contraseña: " + ex->Message, "Error");
		}
	}

		   // === BOTÓN 6: ELIMINAR USUARIO ===
	private: System::Void button6_Click(System::Object^ sender, System::EventArgs^ e) {
		String^ usuarioAEliminar = this->textBox1->Text->Trim();

		if (usuarioAEliminar == "") {
			MessageBox::Show("Por favor, seleccione un usuario de la tabla o escriba el nombre para eliminar.",
				"Aviso", MessageBoxButtons::OK, MessageBoxIcon::Warning);
			return;
		}

		if (usuarioAEliminar->ToLower() == "admin") {
			MessageBox::Show("El administrador del sistema no puede ser eliminado a sí mismo.",
				"Acción Denegada", MessageBoxButtons::OK, MessageBoxIcon::Stop);
			return;
		}

		try {
			String^ rutaUsuarios = "usuarios.txt";

			if (!System::IO::File::Exists(rutaUsuarios)) {
				MessageBox::Show("El archivo de usuarios no existe.", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
				return;
			}

			array<String^>^ lineas = System::IO::File::ReadAllLines(rutaUsuarios);
			System::Collections::Generic::List<String^>^ lineasRestantes = gcnew System::Collections::Generic::List<String^>();
			bool usuarioExiste = false;

			for (int i = 0; i < lineas->Length; i++) {
				array<String^>^ datos = lineas[i]->Split(',');

				if (datos->Length > 0) {
					if (datos[0]->Trim()->Equals(usuarioAEliminar, StringComparison::OrdinalIgnoreCase)) {
						usuarioExiste = true;
					}
					else {
						lineasRestantes->Add(lineas[i]);
					}
				}
			}

			if (!usuarioExiste) {
				MessageBox::Show("El usuario '" + usuarioAEliminar + "' no se encuentra registrado en el sistema.",
					"Usuario No Encontrado", MessageBoxButtons::OK, MessageBoxIcon::Warning);
				return;
			}

			if (MessageBox::Show("¿Está seguro de que desea eliminar permanentemente al usuario '" + usuarioAEliminar + "'?",
				"Confirmar Eliminación", MessageBoxButtons::YesNo, MessageBoxIcon::Question) == System::Windows::Forms::DialogResult::Yes) {

				System::IO::File::WriteAllLines(rutaUsuarios, lineasRestantes->ToArray());

				MessageBox::Show("Usuario '" + usuarioAEliminar + "' eliminado correctamente.",
					"Éxito", MessageBoxButtons::OK, MessageBoxIcon::Information);

				this->textBox1->Clear();
				this->textBox2->Clear();
				this->textBox3->Clear();

				String^ rolActual = (this->button5->Tag != nullptr) ? this->button5->Tag->ToString() : "Admin";
				CargarUsuariosPorRol(rolActual);
			}
		}
		catch (Exception^ ex) {
			MessageBox::Show("Error al intentar eliminar el usuario: " + ex->Message, "Error Crítico");
		}
	}
};
}