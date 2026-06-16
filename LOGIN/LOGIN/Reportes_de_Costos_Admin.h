#pragma once

namespace LOGIN {
	using namespace GemeloDigitalController;
	using namespace GemeloDigitalModel;
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Collections::Generic;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Resumen de Reportes_de_Costos_Admin
	/// </summary>
	public ref class Reportes_de_Costos_Admin : public System::Windows::Forms::Form
	{
	public:
		Reportes_de_Costos_Admin(void)
		{
			InitializeComponent();
			//
			//TODO: agregar cÃ³digo de constructor aquÃ­
			//
			ctrlReporte = gcnew ReporteController();
		}

	protected:
		/// <summary>
		/// Limpiar los recursos que se estÃ©n usando.
		/// </summary>
		~Reportes_de_Costos_Admin()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::DataVisualization::Charting::Chart^ chart1;
	protected:
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::DataGridView^ dataGridView2;





	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::Label^ label8;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Panel^ panel1;
	private: System::Windows::Forms::TextBox^ textBoxCosto;

	private: System::Windows::Forms::TextBox^ textBoxHoras;
	private: System::Windows::Forms::TextBox^ textBoxCiclos;
	private: System::Windows::Forms::Button^ buttonGenerarReporte;



	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Label^ label6;
	private: System::Windows::Forms::Label^ label7;

	private:
		/// <summary>
		/// Variable del diseÃ±ador necesaria.
		/// </summary>
		System::ComponentModel::Container ^components;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ colCicloId;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ colCicloHoras;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ colCicloEstado;
	private: System::Windows::Forms::DataGridView^ dataGridView1;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ colReporteId;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ colReporteTurno;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ colReporteCiclos;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ colReporteHoras;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ colReporteCosto;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ colReporteTotal;
	private: System::Windows::Forms::Label^ labelSugerencia;










		   ReporteController^ ctrlReporte;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// MÃ©todo necesario para admitir el DiseÃ±ador. No se puede modificar
		/// el contenido de este mÃ©todo con el editor de cÃ³digo.
		/// </summary>
		void InitializeComponent(void)
		{
			System::Windows::Forms::DataVisualization::Charting::ChartArea^ chartArea2 = (gcnew System::Windows::Forms::DataVisualization::Charting::ChartArea());
			System::Windows::Forms::DataVisualization::Charting::Legend^ legend2 = (gcnew System::Windows::Forms::DataVisualization::Charting::Legend());
			System::Windows::Forms::DataVisualization::Charting::Series^ series2 = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
			System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle2 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			this->chart1 = (gcnew System::Windows::Forms::DataVisualization::Charting::Chart());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->dataGridView2 = (gcnew System::Windows::Forms::DataGridView());
			this->colCicloId = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->colCicloHoras = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->colCicloEstado = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->textBoxCosto = (gcnew System::Windows::Forms::TextBox());
			this->textBoxHoras = (gcnew System::Windows::Forms::TextBox());
			this->textBoxCiclos = (gcnew System::Windows::Forms::TextBox());
			this->buttonGenerarReporte = (gcnew System::Windows::Forms::Button());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
			this->colReporteId = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->colReporteTurno = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->colReporteCiclos = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->colReporteHoras = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->colReporteCosto = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->colReporteTotal = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->labelSugerencia = (gcnew System::Windows::Forms::Label());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chart1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView2))->BeginInit();
			this->panel1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->BeginInit();
			this->SuspendLayout();
			// 
			// chart1
			// 
			chartArea2->Name = L"ChartArea1";
			this->chart1->ChartAreas->Add(chartArea2);
			legend2->Name = L"Legend1";
			this->chart1->Legends->Add(legend2);
			this->chart1->Location = System::Drawing::Point(78, 473);
			this->chart1->Margin = System::Windows::Forms::Padding(2);
			this->chart1->Name = L"chart1";
			series2->ChartArea = L"ChartArea1";
			series2->Legend = L"Legend1";
			series2->Name = L"Series1";
			this->chart1->Series->Add(series2);
			this->chart1->Size = System::Drawing::Size(654, 253);
			this->chart1->TabIndex = 42;
			this->chart1->Text = L"chart1";
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(245)), static_cast<System::Int32>(static_cast<System::Byte>(158)),
				static_cast<System::Int32>(static_cast<System::Byte>(11)));
			this->label1->Location = System::Drawing::Point(75, 447);
			this->label1->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(167, 13);
			this->label1->TabIndex = 41;
			this->label1->Text = L"Grafico de costos por ciclo (GDI+)";
			// 
			// dataGridView2
			// 
			this->dataGridView2->AutoSizeColumnsMode = System::Windows::Forms::DataGridViewAutoSizeColumnsMode::Fill;
			this->dataGridView2->BackgroundColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(15)),
				static_cast<System::Int32>(static_cast<System::Byte>(23)), static_cast<System::Int32>(static_cast<System::Byte>(42)));
			this->dataGridView2->ColumnHeadersBorderStyle = System::Windows::Forms::DataGridViewHeaderBorderStyle::Single;
			this->dataGridView2->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView2->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(3) {
				this->colCicloId,
					this->colCicloHoras, this->colCicloEstado
			});
			this->dataGridView2->Cursor = System::Windows::Forms::Cursors::Default;
			this->dataGridView2->EnableHeadersVisualStyles = false;
			this->dataGridView2->GridColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->dataGridView2->Location = System::Drawing::Point(78, 61);
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
			this->dataGridView2->Size = System::Drawing::Size(654, 93);
			this->dataGridView2->TabIndex = 40;
			// 
			// colCicloId
			// 
			this->colCicloId->HeaderText = L"N° Ciclo";
			this->colCicloId->MinimumWidth = 6;
			this->colCicloId->Name = L"colCicloId";
			// 
			// colCicloHoras
			// 
			this->colCicloHoras->HeaderText = L"Horas Trabajadas";
			this->colCicloHoras->MinimumWidth = 6;
			this->colCicloHoras->Name = L"colCicloHoras";
			// 
			// colCicloEstado
			// 
			this->colCicloEstado->HeaderText = L"Estado";
			this->colCicloEstado->MinimumWidth = 6;
			this->colCicloEstado->Name = L"colCicloEstado";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(245)), static_cast<System::Int32>(static_cast<System::Byte>(158)),
				static_cast<System::Int32>(static_cast<System::Byte>(11)));
			this->label5->Location = System::Drawing::Point(75, 168);
			this->label5->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(109, 13);
			this->label5->TabIndex = 39;
			this->label5->Text = L"Reportes Registrados";
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label8->ForeColor = System::Drawing::Color::White;
			this->label8->Location = System::Drawing::Point(75, 19);
			this->label8->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label8->Name = L"label8";
			this->label8->RightToLeft = System::Windows::Forms::RightToLeft::No;
			this->label8->Size = System::Drawing::Size(145, 16);
			this->label8->TabIndex = 37;
			this->label8->Text = L"Reportes de Costos";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Calibri", 7.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label2->ForeColor = System::Drawing::Color::White;
			this->label2->Location = System::Drawing::Point(75, 35);
			this->label2->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(257, 13);
			this->label2->TabIndex = 43;
			this->label2->Text = L"El Administrador genera y gestiona todos los reportes";
			// 
			// panel1
			// 
			this->panel1->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(22)), static_cast<System::Int32>(static_cast<System::Byte>(32)),
				static_cast<System::Int32>(static_cast<System::Byte>(50)));
			this->panel1->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->panel1->Controls->Add(this->textBoxCosto);
			this->panel1->Controls->Add(this->textBoxHoras);
			this->panel1->Controls->Add(this->textBoxCiclos);
			this->panel1->Controls->Add(this->buttonGenerarReporte);
			this->panel1->Controls->Add(this->label4);
			this->panel1->Controls->Add(this->label3);
			this->panel1->Controls->Add(this->label6);
			this->panel1->Controls->Add(this->label7);
			this->panel1->Location = System::Drawing::Point(78, 302);
			this->panel1->Margin = System::Windows::Forms::Padding(2);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(702, 112);
			this->panel1->TabIndex = 44;
			this->panel1->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &Reportes_de_Costos_Admin::panel1_Paint);
			// 
			// textBoxCosto
			// 
			this->textBoxCosto->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(30)), static_cast<System::Int32>(static_cast<System::Byte>(41)),
				static_cast<System::Int32>(static_cast<System::Byte>(59)));
			this->textBoxCosto->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->textBoxCosto->ForeColor = System::Drawing::Color::White;
			this->textBoxCosto->Location = System::Drawing::Point(368, 65);
			this->textBoxCosto->Margin = System::Windows::Forms::Padding(2);
			this->textBoxCosto->Name = L"textBoxCosto";
			this->textBoxCosto->Size = System::Drawing::Size(152, 20);
			this->textBoxCosto->TabIndex = 26;
			// 
			// textBoxHoras
			// 
			this->textBoxHoras->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(30)), static_cast<System::Int32>(static_cast<System::Byte>(41)),
				static_cast<System::Int32>(static_cast<System::Byte>(59)));
			this->textBoxHoras->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->textBoxHoras->ForeColor = System::Drawing::Color::White;
			this->textBoxHoras->Location = System::Drawing::Point(201, 65);
			this->textBoxHoras->Margin = System::Windows::Forms::Padding(2);
			this->textBoxHoras->Name = L"textBoxHoras";
			this->textBoxHoras->Size = System::Drawing::Size(152, 20);
			this->textBoxHoras->TabIndex = 25;
			// 
			// textBoxCiclos
			// 
			this->textBoxCiclos->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(30)), static_cast<System::Int32>(static_cast<System::Byte>(41)),
				static_cast<System::Int32>(static_cast<System::Byte>(59)));
			this->textBoxCiclos->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->textBoxCiclos->ForeColor = System::Drawing::Color::White;
			this->textBoxCiclos->Location = System::Drawing::Point(32, 65);
			this->textBoxCiclos->Margin = System::Windows::Forms::Padding(2);
			this->textBoxCiclos->Name = L"textBoxCiclos";
			this->textBoxCiclos->Size = System::Drawing::Size(150, 20);
			this->textBoxCiclos->TabIndex = 24;
			// 
			// buttonGenerarReporte
			// 
			this->buttonGenerarReporte->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(245)),
				static_cast<System::Int32>(static_cast<System::Byte>(158)), static_cast<System::Int32>(static_cast<System::Byte>(11)));
			this->buttonGenerarReporte->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->buttonGenerarReporte->FlatAppearance->BorderColor = System::Drawing::Color::White;
			this->buttonGenerarReporte->FlatAppearance->BorderSize = 0;
			this->buttonGenerarReporte->FlatAppearance->MouseDownBackColor = System::Drawing::Color::MintCream;
			this->buttonGenerarReporte->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->buttonGenerarReporte->ForeColor = System::Drawing::Color::Black;
			this->buttonGenerarReporte->Location = System::Drawing::Point(532, 53);
			this->buttonGenerarReporte->Margin = System::Windows::Forms::Padding(2);
			this->buttonGenerarReporte->Name = L"buttonGenerarReporte";
			this->buttonGenerarReporte->Size = System::Drawing::Size(154, 41);
			this->buttonGenerarReporte->TabIndex = 21;
			this->buttonGenerarReporte->Text = L"Agregar";
			this->buttonGenerarReporte->UseVisualStyleBackColor = false;
			this->buttonGenerarReporte->Click += gcnew System::EventHandler(this, &Reportes_de_Costos_Admin::buttonGenerarReporte_Click);
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 7.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label4->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(142)), static_cast<System::Int32>(static_cast<System::Byte>(157)),
				static_cast<System::Int32>(static_cast<System::Byte>(177)));
			this->label4->Location = System::Drawing::Point(365, 39);
			this->label4->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(92, 13);
			this->label4->TabIndex = 22;
			this->label4->Text = L"Costo por ciclo ($)";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 7.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label3->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(142)), static_cast<System::Int32>(static_cast<System::Byte>(157)),
				static_cast<System::Int32>(static_cast<System::Byte>(177)));
			this->label3->Location = System::Drawing::Point(199, 39);
			this->label3->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(87, 13);
			this->label3->TabIndex = 21;
			this->label3->Text = L"Horas trabajadas";
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 7.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label6->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(142)), static_cast<System::Int32>(static_cast<System::Byte>(157)),
				static_cast<System::Int32>(static_cast<System::Byte>(177)));
			this->label6->Location = System::Drawing::Point(29, 39);
			this->label6->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(45, 13);
			this->label6->TabIndex = 20;
			this->label6->Text = L"N° Ciclo";
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 7.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label7->ForeColor = System::Drawing::Color::White;
			this->label7->Location = System::Drawing::Point(14, 16);
			this->label7->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(113, 13);
			this->label7->TabIndex = 19;
			this->label7->Text = L"Agregar nuevo reporte";
			// 
			// dataGridView1
			// 
			this->dataGridView1->BackgroundColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView1->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(6) {
				this->colReporteId,
					this->colReporteTurno, this->colReporteCiclos, this->colReporteHoras, this->colReporteCosto, this->colReporteTotal
			});
			this->dataGridView1->Location = System::Drawing::Point(78, 184);
			this->dataGridView1->Name = L"dataGridView1";
			this->dataGridView1->Size = System::Drawing::Size(654, 113);
			this->dataGridView1->TabIndex = 45;
			// 
			// colReporteId
			// 
			this->colReporteId->HeaderText = L"ID Reporte";
			this->colReporteId->Name = L"colReporteId";
			// 
			// colReporteTurno
			// 
			this->colReporteTurno->HeaderText = L"Turno";
			this->colReporteTurno->Name = L"colReporteTurno";
			// 
			// colReporteCiclos
			// 
			this->colReporteCiclos->HeaderText = L"Ciclos";
			this->colReporteCiclos->Name = L"colReporteCiclos";
			// 
			// colReporteHoras
			// 
			this->colReporteHoras->HeaderText = L"Horas Totales";
			this->colReporteHoras->Name = L"colReporteHoras";
			// 
			// colReporteCosto
			// 
			this->colReporteCosto->HeaderText = L"Costo/Hora";
			this->colReporteCosto->Name = L"colReporteCosto";
			// 
			// colReporteTotal
			// 
			this->colReporteTotal->HeaderText = L"Costo Total";
			this->colReporteTotal->Name = L"colReporteTotal";
			// 
			// labelSugerencia
			// 
			this->labelSugerencia->AutoSize = true;
			this->labelSugerencia->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
			this->labelSugerencia->Location = System::Drawing::Point(76, 425);
			this->labelSugerencia->Name = L"labelSugerencia";
			this->labelSugerencia->Size = System::Drawing::Size(35, 13);
			this->labelSugerencia->TabIndex = 46;
			this->labelSugerencia->Text = L"label9";
			// 
			// Reportes_de_Costos_Admin
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(30)), static_cast<System::Int32>(static_cast<System::Byte>(40)),
				static_cast<System::Int32>(static_cast<System::Byte>(58)));
			this->ClientSize = System::Drawing::Size(850, 752);
			this->Controls->Add(this->labelSugerencia);
			this->Controls->Add(this->dataGridView1);
			this->Controls->Add(this->panel1);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->chart1);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->dataGridView2);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->label8);
			this->Margin = System::Windows::Forms::Padding(2);
			this->Name = L"Reportes_de_Costos_Admin";
			this->Text = L"Reportes_de_Costos_Admin";
			this->Load += gcnew System::EventHandler(this, &Reportes_de_Costos_Admin::Reportes_de_Costos_Admin_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chart1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView2))->EndInit();
			this->panel1->ResumeLayout(false);
			this->panel1->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void Reportes_de_Costos_Admin_Load(System::Object^ sender, System::EventArgs^ e) {
		dataGridView1->ReadOnly = true;
		dataGridView2->ReadOnly = true;
		textBoxCiclos->ReadOnly = true;
		textBoxHoras->ReadOnly = false; // editable por el admin
		labelSugerencia->Text = L"Sugerencia: agregue un 10-15% al total de horas por tiempos muertos.";
		CargarCiclosPendientes();
		CargarReportes();
	}

		   void CargarCiclosPendientes() {
			   dataGridView2->Rows->Clear();
			   CicloController^ ctrlCiclo = gcnew CicloController();
			   List<CicloModel^>^ pendientes = ctrlCiclo->obtenerPendientes();

			   for each (CicloModel ^ c in pendientes) {
				   dataGridView2->Rows->Add(c->Id, c->HorasTrabajadas.ToString("F1"), c->Estado);
			   }

			   // Llenar textboxes automáticamente
			   int    totalCiclos = pendientes->Count;
			   double totalHoras = totalCiclos * 0.5;
			   textBoxCiclos->Text = totalCiclos.ToString();
			   textBoxHoras->Text = totalHoras.ToString("F1");
		   }

		   void CargarReportes() {
			   dataGridView1->Rows->Clear();
			   ReporteController^ ctrlReporte = gcnew ReporteController();

			   for each (ReporteCostos ^ r in ctrlReporte->obtenerTodos()) {
				   dataGridView1->Rows->Add(
					   r->Id,
					   r->CiclosIncluidos.ToString(),
					   r->HorasTotales.ToString("F1") + " hrs",
					   "$" + r->CostoPorHora.ToString("F2"),
					   "$" + r->calcularCostoTotal().ToString("F2")
				   );
				   int idx = dataGridView1->Rows->Count - 1;
				   dataGridView1->Rows[idx]->Cells[4]->Style->ForeColor =
					   Drawing::Color::FromArgb(230, 160, 0);
			   }

			   // Actualizar chart
			   chart1->Series->Clear();
			   chart1->Titles->Clear();
			   chart1->Titles->Add("Costo Total por Reporte ($)");
			   String^ serie = "Costos";
			   chart1->Series->Add(serie);
			   chart1->Series[serie]->ChartType =
				   System::Windows::Forms::DataVisualization::Charting::SeriesChartType::Column;
			   chart1->Series[serie]->Color = System::Drawing::Color::Orange;
			   chart1->Series[serie]->IsValueShownAsLabel = true;
			   chart1->Series[serie]->LabelFormat = "$#,##0.00";

			   for each (ReporteCostos ^ r in ctrlReporte->obtenerTodos())
				   chart1->Series[serie]->Points->AddXY("REP" + r->Id, r->calcularCostoTotal());

			   chart1->BackColor = Drawing::Color::FromArgb(22, 32, 50);
			   chart1->ChartAreas[0]->BackColor = Drawing::Color::FromArgb(30, 40, 58);
			   chart1->ChartAreas[0]->AxisX->LabelStyle->ForeColor = Drawing::Color::White;
			   chart1->ChartAreas[0]->AxisY->LabelStyle->ForeColor = Drawing::Color::White;
			   chart1->ChartAreas[0]->AxisX->LineColor = Drawing::Color::FromArgb(60, 70, 90);
			   chart1->ChartAreas[0]->AxisY->LineColor = Drawing::Color::FromArgb(60, 70, 90);
			   chart1->ChartAreas[0]->AxisY->Title = "Costo ($)";
			   chart1->ChartAreas[0]->AxisY->TitleForeColor = Drawing::Color::White;
			   if (chart1->Legends->Count > 0)
				   chart1->Legends[0]->Enabled = false;
		   }



private: System::Void buttonGenerarReporte_Click(System::Object^ sender, System::EventArgs^ e) {

	// Validar que haya ciclos pendientes
	CicloController^ ctrlCiclo = gcnew CicloController();
	List<CicloModel^>^ pendientes = ctrlCiclo->obtenerPendientes();

	if (pendientes->Count == 0) {
		MessageBox::Show("No hay ciclos pendientes para reportar.",
			"Sin ciclos", MessageBoxButtons::OK, MessageBoxIcon::Warning);
		return;
	}

	// Validar campos
	String^ horasStr = textBoxHoras->Text->Trim();
	String^ costoStr = textBoxCosto->Text->Trim();

	double horas, costo;
	if (!Double::TryParse(horasStr, horas) || horas <= 0) {
		MessageBox::Show("Ingresa un valor válido de horas.",
			"Error", MessageBoxButtons::OK, MessageBoxIcon::Warning);
		return;
	}
	if (!Double::TryParse(costoStr, costo) || costo <= 0) {
		MessageBox::Show("Ingresa un costo por hora válido.",
			"Error", MessageBoxButtons::OK, MessageBoxIcon::Warning);
		return;
	}

	// Confirmar
	String^ resumen = "Ciclos: " + pendientes->Count.ToString() +
		"\nHoras: " + horas.ToString("F1") +
		"\nCosto/hora: $" + costo.ToString("F2") +
		"\nTotal: $" + (horas * costo).ToString("F2") +
		"\n\n¿Generar reporte?";
	if (MessageBox::Show(resumen, "Confirmar reporte",
		MessageBoxButtons::YesNo, MessageBoxIcon::Question)
		!= System::Windows::Forms::DialogResult::Yes) return;

	// Crear reporte
	ReporteController^ ctrlReporte = gcnew ReporteController();
	String^ nuevoId = "REP" + (ctrlReporte->obtenerTodos()->Count + 1).ToString();
	ctrlReporte->agregar(nuevoId, pendientes->Count, horas, costo);

	// Marcar todos los ciclos pendientes como REPORTADO
	for each (CicloModel ^ c in pendientes)
		ctrlCiclo->marcarReportado(c->Id);

	// Limpiar y recargar
	textBoxCosto->Text = "";
	CargarCiclosPendientes();
	CargarReportes();

	MessageBox::Show("Reporte REP" + nuevoId + " generado correctamente.",
		"Éxito", MessageBoxButtons::OK, MessageBoxIcon::Information);





}
private: System::Void panel1_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
}
};
}