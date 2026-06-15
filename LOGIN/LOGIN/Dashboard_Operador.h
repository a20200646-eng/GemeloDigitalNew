#pragma once

using namespace GemeloDigitalController;
using namespace GemeloDigitalModel;

namespace LOGIN {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Dashboard del Operador.
	/// Muestra KPIs de tareas pendientes/completadas, tabla de tareas pendientes
	/// y tabla de referencia de estado de brazos.
	/// Controllers usados:
	///   - TareaPosicionarController, TareaSostenerController,
	///     TareaSoldarController, TareaCoordinadaController
	///   - BrazoRoboticoController
	/// </summary>
	public ref class Dashboard_Operador : public System::Windows::Forms::Form
	{
	public:
		Dashboard_Operador(void)
		{
			InitializeComponent();
			//
			//TODO: agregar código de constructor aquí
			//
			ctrlPosicionar = gcnew TareaPosicionarController();
			ctrlSostener = gcnew TareaSostenerController();
			ctrlSoldar = gcnew TareaSoldarController();
			ctrlCoordinada = gcnew TareaCoordinadaController();
			ctrlBrazo = gcnew BrazoRoboticoController();

			
			

		}

	protected:
		/// <summary>
		/// Limpiar los recursos que se estén usando.
		/// </summary>
		~Dashboard_Operador()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Panel^ panel5;
	protected:
	private: System::Windows::Forms::Label^ label11;
	private: System::Windows::Forms::Label^ label12;
	private: System::Windows::Forms::Panel^ panel3;
	private: System::Windows::Forms::Label^ label9;
	private: System::Windows::Forms::Label^ label10;
	private: System::Windows::Forms::Panel^ panel9;
	private: System::Windows::Forms::Panel^ panel4;
	private: System::Windows::Forms::Panel^ panel7;
	private: System::Windows::Forms::Label^ label7;
	private: System::Windows::Forms::Label^ label8;
	private: System::Windows::Forms::Panel^ panel8;




	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::DataGridView^ dataGridView2;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ dataGridViewTextBoxColumn1;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ dataGridViewTextBoxColumn2;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ dataGridViewTextBoxColumn3;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Column3;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::DataGridView^ dataGridView1;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ dataGridViewTextBoxColumn4;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ dataGridViewTextBoxColumn5;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ dataGridViewTextBoxColumn6;

	private:
		/// <summary>
		/// Variable del diseñador necesaria.
		/// </summary>
		System::ComponentModel::Container ^components;

		TareaPosicionarController^ ctrlPosicionar;
		TareaSostenerController^ ctrlSostener;
		TareaSoldarController^ ctrlSoldar;
		TareaCoordinadaController^ ctrlCoordinada;
		BrazoRoboticoController^ ctrlBrazo;

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
			this->panel7 = (gcnew System::Windows::Forms::Panel());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->panel8 = (gcnew System::Windows::Forms::Panel());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->dataGridView2 = (gcnew System::Windows::Forms::DataGridView());
			this->dataGridViewTextBoxColumn1 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->dataGridViewTextBoxColumn2 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->dataGridViewTextBoxColumn3 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column3 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
			this->dataGridViewTextBoxColumn4 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->dataGridViewTextBoxColumn5 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->dataGridViewTextBoxColumn6 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->panel5->SuspendLayout();
			this->panel3->SuspendLayout();
			this->panel7->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView2))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->BeginInit();
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
			this->panel5->Location = System::Drawing::Point(512, 74);
			this->panel5->Margin = System::Windows::Forms::Padding(2);
			this->panel5->Name = L"panel5";
			this->panel5->Size = System::Drawing::Size(173, 56);
			this->panel5->TabIndex = 19;
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
			this->label11->Size = System::Drawing::Size(88, 13);
			this->label11->TabIndex = 4;
			this->label11->Text = L"Brazos asignados";
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
			this->label12->Text = L"3";
			// 
			// panel3
			// 
			this->panel3->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(14)), static_cast<System::Int32>(static_cast<System::Byte>(22)),
				static_cast<System::Int32>(static_cast<System::Byte>(40)));
			this->panel3->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->panel3->Controls->Add(this->label9);
			this->panel3->Controls->Add(this->label10);
			this->panel3->ForeColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->panel3->Location = System::Drawing::Point(267, 74);
			this->panel3->Margin = System::Windows::Forms::Padding(2);
			this->panel3->Name = L"panel3";
			this->panel3->Size = System::Drawing::Size(173, 56);
			this->panel3->TabIndex = 23;
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
			this->label9->Size = System::Drawing::Size(102, 13);
			this->label9->TabIndex = 4;
			this->label9->Text = L"Tareas completadas";
			// 
			// label10
			// 
			this->label10->AutoSize = true;
			this->label10->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label10->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(192)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			this->label10->Location = System::Drawing::Point(8, 7);
			this->label10->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label10->Name = L"label10";
			this->label10->Size = System::Drawing::Size(23, 16);
			this->label10->TabIndex = 11;
			this->label10->Text = L"14";
			// 
			// panel9
			// 
			this->panel9->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(124)), static_cast<System::Int32>(static_cast<System::Byte>(58)),
				static_cast<System::Int32>(static_cast<System::Byte>(237)));
			this->panel9->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->panel9->ForeColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->panel9->Location = System::Drawing::Point(512, 64);
			this->panel9->Margin = System::Windows::Forms::Padding(2);
			this->panel9->Name = L"panel9";
			this->panel9->Size = System::Drawing::Size(173, 65);
			this->panel9->TabIndex = 18;
			// 
			// panel4
			// 
			this->panel4->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(0)), static_cast<System::Int32>(static_cast<System::Byte>(192)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			this->panel4->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->panel4->ForeColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->panel4->Location = System::Drawing::Point(267, 64);
			this->panel4->Margin = System::Windows::Forms::Padding(2);
			this->panel4->Name = L"panel4";
			this->panel4->Size = System::Drawing::Size(173, 65);
			this->panel4->TabIndex = 22;
			// 
			// panel7
			// 
			this->panel7->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(14)), static_cast<System::Int32>(static_cast<System::Byte>(22)),
				static_cast<System::Int32>(static_cast<System::Byte>(40)));
			this->panel7->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->panel7->Controls->Add(this->label7);
			this->panel7->Controls->Add(this->label8);
			this->panel7->ForeColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->panel7->Location = System::Drawing::Point(35, 74);
			this->panel7->Margin = System::Windows::Forms::Padding(2);
			this->panel7->Name = L"panel7";
			this->panel7->Size = System::Drawing::Size(173, 56);
			this->panel7->TabIndex = 21;
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Font = (gcnew System::Drawing::Font(L"Calibri", 7.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label7->ForeColor = System::Drawing::Color::White;
			this->label7->Location = System::Drawing::Point(2, 38);
			this->label7->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(94, 13);
			this->label7->TabIndex = 4;
			this->label7->Text = L"Tareas pendientes";
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label8->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(217)), static_cast<System::Int32>(static_cast<System::Byte>(119)),
				static_cast<System::Int32>(static_cast<System::Byte>(6)));
			this->label8->Location = System::Drawing::Point(5, 7);
			this->label8->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(15, 16);
			this->label8->TabIndex = 11;
			this->label8->Text = L"4";
			// 
			// panel8
			// 
			this->panel8->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(217)), static_cast<System::Int32>(static_cast<System::Byte>(119)),
				static_cast<System::Int32>(static_cast<System::Byte>(6)));
			this->panel8->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->panel8->ForeColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->panel8->Location = System::Drawing::Point(35, 64);
			this->panel8->Margin = System::Windows::Forms::Padding(2);
			this->panel8->Name = L"panel8";
			this->panel8->Size = System::Drawing::Size(173, 65);
			this->panel8->TabIndex = 20;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->ForeColor = System::Drawing::Color::White;
			this->label1->Location = System::Drawing::Point(27, 28);
			this->label1->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label1->Name = L"label1";
			this->label1->RightToLeft = System::Windows::Forms::RightToLeft::No;
			this->label1->Size = System::Drawing::Size(84, 16);
			this->label1->TabIndex = 15;
			this->label1->Text = L"Dashboard";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(245)), static_cast<System::Int32>(static_cast<System::Byte>(158)),
				static_cast<System::Int32>(static_cast<System::Byte>(11)));
			this->label5->Location = System::Drawing::Point(28, 158);
			this->label5->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(110, 13);
			this->label5->TabIndex = 30;
			this->label5->Text = L"Mis tareas pendientes";
			// 
			// dataGridView2
			// 
			this->dataGridView2->AutoSizeColumnsMode = System::Windows::Forms::DataGridViewAutoSizeColumnsMode::Fill;
			this->dataGridView2->BackgroundColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(15)),
				static_cast<System::Int32>(static_cast<System::Byte>(23)), static_cast<System::Int32>(static_cast<System::Byte>(42)));
			this->dataGridView2->ColumnHeadersBorderStyle = System::Windows::Forms::DataGridViewHeaderBorderStyle::Single;
			this->dataGridView2->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView2->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(4) {
				this->dataGridViewTextBoxColumn1,
					this->dataGridViewTextBoxColumn2, this->dataGridViewTextBoxColumn3, this->Column3
			});
			this->dataGridView2->Cursor = System::Windows::Forms::Cursors::Default;
			this->dataGridView2->EnableHeadersVisualStyles = false;
			this->dataGridView2->GridColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->dataGridView2->Location = System::Drawing::Point(30, 189);
			this->dataGridView2->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->dataGridView2->Name = L"dataGridView2";
			this->dataGridView2->RowHeadersBorderStyle = System::Windows::Forms::DataGridViewHeaderBorderStyle::Single;
			dataGridViewCellStyle1->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleLeft;
			dataGridViewCellStyle1->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(30)), static_cast<System::Int32>(static_cast<System::Byte>(58)),
				static_cast<System::Int32>(static_cast<System::Byte>(95)));
			dataGridViewCellStyle1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 7.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			dataGridViewCellStyle1->ForeColor = System::Drawing::SystemColors::WindowText;
			dataGridViewCellStyle1->SelectionBackColor = System::Drawing::SystemColors::Highlight;
			dataGridViewCellStyle1->SelectionForeColor = System::Drawing::SystemColors::HighlightText;
			dataGridViewCellStyle1->WrapMode = System::Windows::Forms::DataGridViewTriState::True;
			this->dataGridView2->RowHeadersDefaultCellStyle = dataGridViewCellStyle1;
			this->dataGridView2->RowHeadersVisible = false;
			//
			this->dataGridView2->ReadOnly = true;
			//
			this->dataGridView2->RowHeadersWidth = 51;
			this->dataGridView2->RowTemplate->Height = 24;
			this->dataGridView2->Size = System::Drawing::Size(654, 108);
			this->dataGridView2->TabIndex = 35;
			// 
			// dataGridViewTextBoxColumn1
			// 
			this->dataGridViewTextBoxColumn1->HeaderText = L"Tipo";
			this->dataGridViewTextBoxColumn1->MinimumWidth = 6;
			this->dataGridViewTextBoxColumn1->Name = L"dataGridViewTextBoxColumn1";
			// 
			// dataGridViewTextBoxColumn2
			// 
			this->dataGridViewTextBoxColumn2->HeaderText = L"ID";
			this->dataGridViewTextBoxColumn2->MinimumWidth = 6;
			this->dataGridViewTextBoxColumn2->Name = L"dataGridViewTextBoxColumn2";
			// 
			// dataGridViewTextBoxColumn3
			// 
			this->dataGridViewTextBoxColumn3->HeaderText = L"Estado";
			this->dataGridViewTextBoxColumn3->MinimumWidth = 6;
			this->dataGridViewTextBoxColumn3->Name = L"dataGridViewTextBoxColumn3";
			// 
			// Column3
			// 
			this->Column3->HeaderText = L"Detalle";
			this->Column3->MinimumWidth = 6;
			this->Column3->Name = L"Column3";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(245)), static_cast<System::Int32>(static_cast<System::Byte>(158)),
				static_cast<System::Int32>(static_cast<System::Byte>(11)));
			this->label2->Location = System::Drawing::Point(28, 318);
			this->label2->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(145, 13);
			this->label2->TabIndex = 36;
			this->label2->Text = L"Estado de brazos (referencia)";
			// 
			// dataGridView1
			// 
			this->dataGridView1->AutoSizeColumnsMode = System::Windows::Forms::DataGridViewAutoSizeColumnsMode::Fill;
			this->dataGridView1->BackgroundColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(15)),
				static_cast<System::Int32>(static_cast<System::Byte>(23)), static_cast<System::Int32>(static_cast<System::Byte>(42)));
			this->dataGridView1->ColumnHeadersBorderStyle = System::Windows::Forms::DataGridViewHeaderBorderStyle::Single;
			this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView1->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(3) {
				this->dataGridViewTextBoxColumn4,
					this->dataGridViewTextBoxColumn5, this->dataGridViewTextBoxColumn6
			});
			this->dataGridView1->Cursor = System::Windows::Forms::Cursors::Default;
			this->dataGridView1->EnableHeadersVisualStyles = false;
			this->dataGridView1->GridColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->dataGridView1->Location = System::Drawing::Point(30, 360);
			this->dataGridView1->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->dataGridView1->Name = L"dataGridView1";
			this->dataGridView1->RowHeadersBorderStyle = System::Windows::Forms::DataGridViewHeaderBorderStyle::Single;
			dataGridViewCellStyle2->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleLeft;
			dataGridViewCellStyle2->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(30)), static_cast<System::Int32>(static_cast<System::Byte>(58)),
				static_cast<System::Int32>(static_cast<System::Byte>(95)));
			dataGridViewCellStyle2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 7.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			dataGridViewCellStyle2->ForeColor = System::Drawing::SystemColors::WindowText;
			dataGridViewCellStyle2->SelectionBackColor = System::Drawing::SystemColors::Highlight;
			dataGridViewCellStyle2->SelectionForeColor = System::Drawing::SystemColors::HighlightText;
			dataGridViewCellStyle2->WrapMode = System::Windows::Forms::DataGridViewTriState::True;
			this->dataGridView1->RowHeadersDefaultCellStyle = dataGridViewCellStyle2;
			this->dataGridView1->RowHeadersVisible = false;
			// Solo lectura (referencia)
			this->dataGridView1->ReadOnly = true;
			// No permitir agregar/eliminar filas (referencia)
			this->dataGridView1->RowHeadersWidth = 51;
			this->dataGridView1->RowTemplate->Height = 24;
			this->dataGridView1->Size = System::Drawing::Size(654, 108);
			this->dataGridView1->TabIndex = 37;
			// 
			// dataGridViewTextBoxColumn4
			// 
			this->dataGridViewTextBoxColumn4->HeaderText = L"ID";
			this->dataGridViewTextBoxColumn4->MinimumWidth = 6;
			this->dataGridViewTextBoxColumn4->Name = L"dataGridViewTextBoxColumn4";
			// 
			// dataGridViewTextBoxColumn5
			// 
			this->dataGridViewTextBoxColumn5->HeaderText = L"Rol";
			this->dataGridViewTextBoxColumn5->MinimumWidth = 6;
			this->dataGridViewTextBoxColumn5->Name = L"dataGridViewTextBoxColumn5";
			// 
			// dataGridViewTextBoxColumn6
			// 
			this->dataGridViewTextBoxColumn6->HeaderText = L"Estado";
			this->dataGridViewTextBoxColumn6->MinimumWidth = 6;
			this->dataGridViewTextBoxColumn6->Name = L"dataGridViewTextBoxColumn6";
			// 
			// Dashboard_Operador
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(30)), static_cast<System::Int32>(static_cast<System::Byte>(40)),
				static_cast<System::Int32>(static_cast<System::Byte>(58)));
			this->ClientSize = System::Drawing::Size(752, 517);
			this->Controls->Add(this->dataGridView1);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->dataGridView2);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->panel5);
			this->Controls->Add(this->panel3);
			this->Controls->Add(this->panel9);
			this->Controls->Add(this->panel4);
			this->Controls->Add(this->panel7);
			this->Controls->Add(this->panel8);
			this->Controls->Add(this->label1);
			this->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->Name = L"Dashboard_Operador";
			this->Text = L"Dashboard_Operador";
			// Conectar evento Load
			this->Load += gcnew System::EventHandler(this, &Dashboard_Operador::Dashboard_Operador_Load);
			this->panel5->ResumeLayout(false);
			this->panel5->PerformLayout();
			this->panel3->ResumeLayout(false);
			this->panel3->PerformLayout();
			this->panel7->ResumeLayout(false);
			this->panel7->PerformLayout();


			
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView2))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

	void Cargar() {
			CargarKPIs();
			CargarTareasPendientes();
			CargarEstadoBrazos();
	}
	private: System::Void Dashboard_Operador_Load(System::Object^ sender, System::EventArgs^ e) {
		Cargar();
	}

		   void CargarKPIs()
		   {
			   int pendientes = 0;
			   int completadas = 0;
			   int totalBrazos = ctrlBrazo->obtenerTodos()->Count;

			   // Contar desde cada controller de tareas
			   for each(TareaPosicionarModel ^ t in ctrlPosicionar->obtenerTodos())
			   {
				   if (t->Estado == "PENDIENTE" || t->Estado == "EN CURSO") pendientes++;
				   else if (t->Estado == "COMPLETADA") completadas++;
			   }
			   for each(TareaSostenerModel ^ t in ctrlSostener->obtenerTodos())
			   {
				   if (t->Estado == "PENDIENTE" || t->Estado == "EN CURSO") pendientes++;
				   else if (t->Estado == "COMPLETADA") completadas++;
			   }
			   for each(TareaSoldarModel ^ t in ctrlSoldar->obtenerTodos())
			   {
				   if (t->Estado == "PENDIENTE" || t->Estado == "EN CURSO") pendientes++;
				   else if (t->Estado == "COMPLETADA") completadas++;
			   }
			   for each(TareaCoordinadaModel ^ t in ctrlCoordinada->obtenerTodos())
			   {
				   if (t->Estado == "PENDIENTE" || t->Estado == "EN CURSO") pendientes++;
				   else if (t->Estado == "COMPLETADA") completadas++;
			   }

			   label8->Text = pendientes.ToString();
			   label10->Text = completadas.ToString();
			   label12->Text = totalBrazos.ToString();
		   }

		   void CargarTareasPendientes()
		   {
			   dataGridView2->Rows->Clear();

			   // --- Posicionar ---
			   for each(TareaPosicionarModel ^ t in ctrlPosicionar->obtenerTodos())
			   {
				   if (t->Estado == "COMPLETADA") continue;
				   String^ detalle = "PosObj=" + t->PosicionObjetivo.ToString("F1")
					   + " Tol=" + t->Tolerancia.ToString("F1");
				   dataGridView2->Rows->Add("Posicionar", t->Id, t->Estado, detalle);
			   }

			   // --- Sostener ---
			   for each(TareaSostenerModel ^ t in ctrlSostener->obtenerTodos())
			   {
				   if (t->Estado == "COMPLETADA") continue;
				   String^ detalle = "Fuerza=" + t->FuerzaSosten.ToString("F1")
					   + " Dur=" + t->Duracion.ToString() + "s";
				   dataGridView2->Rows->Add("Sostener", t->Id, t->Estado, detalle);
			   }

			   // --- Soldar ---
			   for each(TareaSoldarModel ^ t in ctrlSoldar->obtenerTodos())
			   {
				   if (t->Estado == "COMPLETADA") continue;
				   String^ detalle = t->PuntosCompletados.ToString() + "/"
					   + t->PuntosObjetivo.ToString() + " puntos";
				   dataGridView2->Rows->Add("Soldar", t->Id, t->Estado, detalle);
			   }

			   // --- Coordinada ---
			   for each(TareaCoordinadaModel ^ t in ctrlCoordinada->obtenerTodos())
			   {
				   if (t->Estado == "COMPLETADA") continue;
				   String^ detalle = t->TotalConfirmado.ToString() + "/"
					   + t->TotalRequerido.ToString() + " confirmados";
				   dataGridView2->Rows->Add("Coordinada", t->Id, t->Estado, detalle);
			   }

			   // Colorear columna Estado
			   for each(DataGridViewRow ^ row in dataGridView2->Rows)
			   {
				   if (row->IsNewRow) continue;
				   String^ estado = row->Cells[2]->Value->ToString();
				   DataGridViewCell^ celda = row->Cells[2];
				   if (estado == "PENDIENTE")
					   celda->Style->ForeColor = Color::FromArgb(230, 160, 0);    // naranja
				   else if (estado == "EN CURSO")
					   celda->Style->ForeColor = Color::FromArgb(80, 160, 255);   // azul
				   else
					   celda->Style->ForeColor = Color::FromArgb(0, 200, 100);    // verde
			   }
		   }

		   void CargarEstadoBrazos()
		   {
			   dataGridView1->Rows->Clear();

			   for each(BrazoRoboticoModel ^ b in ctrlBrazo->obtenerTodos())
			   {
				   String^ rol;
				   switch (b->Rol)
				   {
				   case RolBrazo::LATERAL_IZQ:  rol = "Lateral Izquierdo"; break;
				   case RolBrazo::LATERAL_DER:  rol = "Lateral Derecho";   break;
				   case RolBrazo::CENTRAL_SUP:  rol = "Central Superior";  break;
				   default:                     rol = "Desconocido";        break;
				   }

				   String^ estado;
				   switch (b->Estado)
				   {
				   case EstadoBrazo::REPOSO:        estado = "REPOSO";        break;
				   case EstadoBrazo::CALIBRANDO:    estado = "CALIBRANDO";    break;
				   case EstadoBrazo::POSICIONANDO:  estado = "POSICIONANDO";  break;
				   case EstadoBrazo::SOLDANDO:      estado = "SOLDANDO";      break;
				   case EstadoBrazo::EN_ERROR:      estado = "EN ERROR";      break;
				   case EstadoBrazo::PAUSA:         estado = "PAUSA";         break;
				   default:                         estado = "DESCONOCIDO";   break;
				   }

				   dataGridView1->Rows->Add(b->Id, rol, estado);
			   }

			   // Colorear columna Estado
			   for each(DataGridViewRow ^ row in dataGridView1->Rows)
			   {
				   if (row->IsNewRow) continue;
				   String^ estado = row->Cells[2]->Value->ToString();
				   DataGridViewCell^ celda = row->Cells[2];
				   if (estado == "POSICIONANDO")
					   celda->Style->ForeColor = Color::FromArgb(80, 160, 255);   // azul
				   else if (estado == "SOLDANDO")
					   celda->Style->ForeColor = Color::FromArgb(230, 160, 0);    // naranja
				   else if (estado == "EN ERROR")
					   celda->Style->ForeColor = Color::FromArgb(200, 40, 40);    // rojo
				   else if (estado == "PAUSA")
					   celda->Style->ForeColor = Color::FromArgb(160, 80, 200);   // violeta
				   else
					   celda->Style->ForeColor = Color::Gray;                     // gris REPOSO
			   }
		   }


};
}
