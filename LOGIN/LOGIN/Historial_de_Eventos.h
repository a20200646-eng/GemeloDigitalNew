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

	/// <summary>
	/// Resumen de Historial_de_Eventos
	/// </summary>
	public ref class Historial_de_Eventos : public System::Windows::Forms::Form
	{
	public:
		Historial_de_Eventos(void)
		{
			InitializeComponent();
			//
			//TODO: agregar código de constructor aquí
			//
			ctrlEvTarea = gcnew EventoTareaController();
			ctrlEvAlerta = gcnew EventoAlertaController();
			ctrlEvError = gcnew EventoErrorController();
		}

	protected:
		/// <summary>
		/// Limpiar los recursos que se estén usando.
		/// </summary>
		~Historial_de_Eventos()
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
	private: System::Windows::Forms::DataGridView^ dataGridView1;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Column1;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Rol;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Column2;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Column3;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Column4;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Column5;
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
		EventoTareaController^ ctrlEvTarea;
		EventoAlertaController^ ctrlEvAlerta;
		EventoErrorController^ ctrlEvError;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Método necesario para admitir el Diseñador. No se puede modificar
		/// el contenido de este método con el editor de código.
		/// </summary>
		void InitializeComponent(void)
		{
			System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle1 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
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
			this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
			this->Column1 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Rol = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column2 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column3 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column4 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column5 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->panel7 = (gcnew System::Windows::Forms::Panel());
			this->panel8 = (gcnew System::Windows::Forms::Panel());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->panel5->SuspendLayout();
			this->panel3->SuspendLayout();
			this->panel6->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->BeginInit();
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
			this->panel5->Location = System::Drawing::Point(373, 77);
			this->panel5->Margin = System::Windows::Forms::Padding(2);
			this->panel5->Name = L"panel5";
			this->panel5->Size = System::Drawing::Size(156, 56);
			this->panel5->TabIndex = 26;
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
			this->label11->Size = System::Drawing::Size(41, 13);
			this->label11->TabIndex = 4;
			this->label11->Text = L"Errores";
			// 
			// label12
			// 
			this->label12->AutoSize = true;
			this->label12->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label12->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(239)), static_cast<System::Int32>(static_cast<System::Byte>(68)),
				static_cast<System::Int32>(static_cast<System::Byte>(68)));
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
			this->panel3->Location = System::Drawing::Point(206, 77);
			this->panel3->Margin = System::Windows::Forms::Padding(2);
			this->panel3->Name = L"panel3";
			this->panel3->Size = System::Drawing::Size(156, 56);
			this->panel3->TabIndex = 28;
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
			this->label9->Size = System::Drawing::Size(41, 13);
			this->label9->TabIndex = 4;
			this->label9->Text = L"Alertas";
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
			this->label10->Text = L"3";
			// 
			// panel9
			// 
			this->panel9->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(239)), static_cast<System::Int32>(static_cast<System::Byte>(68)),
				static_cast<System::Int32>(static_cast<System::Byte>(68)));
			this->panel9->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->panel9->ForeColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->panel9->Location = System::Drawing::Point(373, 67);
			this->panel9->Margin = System::Windows::Forms::Padding(2);
			this->panel9->Name = L"panel9";
			this->panel9->Size = System::Drawing::Size(156, 65);
			this->panel9->TabIndex = 25;
			// 
			// panel4
			// 
			this->panel4->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(217)), static_cast<System::Int32>(static_cast<System::Byte>(119)),
				static_cast<System::Int32>(static_cast<System::Byte>(6)));
			this->panel4->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->panel4->ForeColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->panel4->Location = System::Drawing::Point(206, 67);
			this->panel4->Margin = System::Windows::Forms::Padding(2);
			this->panel4->Name = L"panel4";
			this->panel4->Size = System::Drawing::Size(156, 65);
			this->panel4->TabIndex = 27;
			// 
			// panel6
			// 
			this->panel6->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(14)), static_cast<System::Int32>(static_cast<System::Byte>(22)),
				static_cast<System::Int32>(static_cast<System::Byte>(40)));
			this->panel6->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->panel6->Controls->Add(this->label2);
			this->panel6->Controls->Add(this->label6);
			this->panel6->ForeColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->panel6->Location = System::Drawing::Point(39, 77);
			this->panel6->Margin = System::Windows::Forms::Padding(2);
			this->panel6->Name = L"panel6";
			this->panel6->Size = System::Drawing::Size(156, 56);
			this->panel6->TabIndex = 24;
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
			this->label2->Size = System::Drawing::Size(68, 13);
			this->label2->TabIndex = 4;
			this->label2->Text = L"Eventos INFO";
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
			this->label6->Size = System::Drawing::Size(15, 16);
			this->label6->TabIndex = 11;
			this->label6->Text = L"9";
			// 
			// panel2
			// 
			this->panel2->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(22)), static_cast<System::Int32>(static_cast<System::Byte>(163)),
				static_cast<System::Int32>(static_cast<System::Byte>(74)));
			this->panel2->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->panel2->ForeColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->panel2->Location = System::Drawing::Point(39, 67);
			this->panel2->Margin = System::Windows::Forms::Padding(2);
			this->panel2->Name = L"panel2";
			this->panel2->Size = System::Drawing::Size(156, 65);
			this->panel2->TabIndex = 23;
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(245)), static_cast<System::Int32>(static_cast<System::Byte>(158)),
				static_cast<System::Int32>(static_cast<System::Byte>(11)));
			this->label5->Location = System::Drawing::Point(37, 156);
			this->label5->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(149, 13);
			this->label5->TabIndex = 29;
			this->label5->Text = L"Todos los eventos del sistema";
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
			this->dataGridView1->Location = System::Drawing::Point(39, 200);
			this->dataGridView1->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
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
			this->dataGridView1->Size = System::Drawing::Size(490, 141);
			this->dataGridView1->TabIndex = 30;
			// 
			// Column1
			// 
			this->Column1->HeaderText = L"Tipo";
			this->Column1->MinimumWidth = 6;
			this->Column1->Name = L"Column1";
			// 
			// Rol
			// 
			this->Rol->HeaderText = L"ID";
			this->Rol->MinimumWidth = 6;
			this->Rol->Name = L"Rol";
			// 
			// Column2
			// 
			this->Column2->HeaderText = L"Timestamp";
			this->Column2->MinimumWidth = 6;
			this->Column2->Name = L"Column2";
			// 
			// Column3
			// 
			this->Column3->HeaderText = L"Nivel";
			this->Column3->MinimumWidth = 6;
			this->Column3->Name = L"Column3";
			// 
			// Column4
			// 
			this->Column4->HeaderText = L"Descripción";
			this->Column4->MinimumWidth = 6;
			this->Column4->Name = L"Column4";
			// 
			// Column5
			// 
			this->Column5->HeaderText = L"Detalle";
			this->Column5->MinimumWidth = 6;
			this->Column5->Name = L"Column5";
			// 
			// panel7
			// 
			this->panel7->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(49)), static_cast<System::Int32>(static_cast<System::Byte>(108)),
				static_cast<System::Int32>(static_cast<System::Byte>(205)));
			this->panel7->Controls->Add(this->panel8);
			this->panel7->Location = System::Drawing::Point(39, 371);
			this->panel7->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->panel7->Name = L"panel7";
			this->panel7->Size = System::Drawing::Size(490, 38);
			this->panel7->TabIndex = 31;
			// 
			// panel8
			// 
			this->panel8->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(30)), static_cast<System::Int32>(static_cast<System::Byte>(40)),
				static_cast<System::Int32>(static_cast<System::Byte>(58)));
			this->panel8->Controls->Add(this->label7);
			this->panel8->Location = System::Drawing::Point(2, 2);
			this->panel8->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->panel8->Name = L"panel8";
			this->panel8->Size = System::Drawing::Size(485, 33);
			this->panel8->TabIndex = 30;
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(49)), static_cast<System::Int32>(static_cast<System::Byte>(108)),
				static_cast<System::Int32>(static_cast<System::Byte>(205)));
			this->label7->Location = System::Drawing::Point(10, 11);
			this->label7->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(416, 13);
			this->label7->TabIndex = 30;
			this->label7->Text = L"El Jefe solo puede leer los eventos. Para registrar nuevos eventos, use el rol Op"
				L"erador.";
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label8->ForeColor = System::Drawing::Color::White;
			this->label8->Location = System::Drawing::Point(38, 25);
			this->label8->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label8->Name = L"label8";
			this->label8->RightToLeft = System::Windows::Forms::RightToLeft::No;
			this->label8->Size = System::Drawing::Size(147, 16);
			this->label8->TabIndex = 32;
			this->label8->Text = L"Historial de Eventos";
			// 
			// Historial_de_Eventos
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(30)), static_cast<System::Int32>(static_cast<System::Byte>(40)),
				static_cast<System::Int32>(static_cast<System::Byte>(58)));
			this->ClientSize = System::Drawing::Size(575, 462);
			this->Controls->Add(this->label8);
			this->Controls->Add(this->panel7);
			this->Controls->Add(this->dataGridView1);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->panel5);
			this->Controls->Add(this->panel3);
			this->Controls->Add(this->panel9);
			this->Controls->Add(this->panel4);
			this->Controls->Add(this->panel6);
			this->Controls->Add(this->panel2);
			this->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->Name = L"Historial_de_Eventos";
			this->Text = L"Historial_de_Eventos";
			this->Load += gcnew System::EventHandler(this, &Historial_de_Eventos::Historial_de_Eventos_Load);
			this->panel5->ResumeLayout(false);
			this->panel5->PerformLayout();
			this->panel3->ResumeLayout(false);
			this->panel3->PerformLayout();
			this->panel6->ResumeLayout(false);
			this->panel6->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->EndInit();
			this->panel7->ResumeLayout(false);
			this->panel8->ResumeLayout(false);
			this->panel8->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void Historial_de_Eventos_Load(System::Object^ sender, System::EventArgs^ e) {
		CargarKPIs();
		CargarHistorial();
	}

		   void CargarKPIs()
		   {
			   label6->Text = ctrlEvTarea->obtenerTodos()->Count.ToString();
			   label10->Text = ctrlEvAlerta->obtenerTodos()->Count.ToString();
			   label12->Text = ctrlEvError->obtenerTodos()->Count.ToString();
		   }

		   void CargarHistorial()
		   {
			   dataGridView1->Rows->Clear();
			   dataGridView1->ReadOnly = true;

			   // EventoTarea — INFO
			   for each (EventoTareaModel ^ e in ctrlEvTarea->obtenerTodos())
			   {
				   String^ detalle = "TareaID=" + e->TareaId + " | " + e->Resultado;
				   int idx = dataGridView1->Rows->Add(
					   "EventoTarea", e->Id, e->Timestamp, "INFO", e->Descripcion, detalle);
				   dataGridView1->Rows[idx]->Cells[3]->Style->ForeColor =
					   Color::FromArgb(0, 200, 100); // verde INFO
			   }

			   // EventoAlerta — ALERTA
			   for each (EventoAlertaModel ^ e in ctrlEvAlerta->obtenerTodos())
			   {
				   String^ detalle = "BrazoID=" + e->BrazoId + " | " + e->TipoAlerta;
				   int idx = dataGridView1->Rows->Add(
					   "EventoAlerta", e->Id, e->Timestamp, "ALERTA", e->Descripcion, detalle);
				   dataGridView1->Rows[idx]->Cells[3]->Style->ForeColor =
					   Color::FromArgb(217, 119, 6); // naranja ALERTA
			   }

			   // EventoError — ERROR
			   for each (EventoErrorModel ^ e in ctrlEvError->obtenerTodos())
			   {
				   String^ detalle = e->CodigoError + " | Fase=" + e->Fase;
				   int idx = dataGridView1->Rows->Add(
					   "EventoError", e->Id, e->Timestamp, "ERROR", e->Descripcion, detalle);
				   dataGridView1->Rows[idx]->Cells[3]->Style->ForeColor =
					   Color::FromArgb(239, 68, 68); // rojo ERROR
			   }
		   }
};
}
