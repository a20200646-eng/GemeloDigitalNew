#pragma once

namespace LOGIN {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Resumen de FormMenuJefe
	/// </summary>
	public ref class FormMenuJefe : public System::Windows::Forms::Form
	{
	public:
		FormMenuJefe(void)
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
		~FormMenuJefe()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Button^ btnAprobar;
	private: System::Windows::Forms::Button^ btnDetener;
	private: System::Windows::Forms::Button^ btnVerEstado;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Panel^ panel1;


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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(FormMenuJefe::typeid));
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->btnAprobar = (gcnew System::Windows::Forms::Button());
			this->btnDetener = (gcnew System::Windows::Forms::Button());
			this->btnVerEstado = (gcnew System::Windows::Forms::Button());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->panel1->SuspendLayout();
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"MS Reference Sans Serif", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(480, 91);
			this->label1->Name = L"label1";
			this->label1->RightToLeft = System::Windows::Forms::RightToLeft::No;
			this->label1->Size = System::Drawing::Size(223, 16);
			this->label1->TabIndex = 0;
			this->label1->Text = L"MENÚ JEFE DE OPERACIONES";
			// 
			// btnAprobar
			// 
			this->btnAprobar->Font = (gcnew System::Drawing::Font(L"MS Reference Sans Serif", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnAprobar->Location = System::Drawing::Point(0, 112);
			this->btnAprobar->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->btnAprobar->Name = L"btnAprobar";
			this->btnAprobar->Size = System::Drawing::Size(288, 48);
			this->btnAprobar->TabIndex = 1;
			this->btnAprobar->Text = L" Aprobar Secuencia";
			this->btnAprobar->UseVisualStyleBackColor = true;
			this->btnAprobar->Click += gcnew System::EventHandler(this, &FormMenuJefe::button1_Click);
			// 
			// btnDetener
			// 
			this->btnDetener->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Center;
			this->btnDetener->Font = (gcnew System::Drawing::Font(L"MS Reference Sans Serif", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnDetener->Location = System::Drawing::Point(0, 189);
			this->btnDetener->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->btnDetener->Name = L"btnDetener";
			this->btnDetener->Size = System::Drawing::Size(288, 47);
			this->btnDetener->TabIndex = 2;
			this->btnDetener->Text = L"Detener Línea";
			this->btnDetener->UseVisualStyleBackColor = true;
			this->btnDetener->Click += gcnew System::EventHandler(this, &FormMenuJefe::button1_Click_1);
			// 
			// btnVerEstado
			// 
			this->btnVerEstado->Font = (gcnew System::Drawing::Font(L"MS Reference Sans Serif", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnVerEstado->Location = System::Drawing::Point(0, 27);
			this->btnVerEstado->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->btnVerEstado->Name = L"btnVerEstado";
			this->btnVerEstado->Size = System::Drawing::Size(288, 50);
			this->btnVerEstado->TabIndex = 3;
			this->btnVerEstado->Text = L"Ver estado de línea";
			this->btnVerEstado->UseVisualStyleBackColor = true;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"MS Reference Sans Serif", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label2->Location = System::Drawing::Point(357, 173);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(156, 16);
			this->label2->TabIndex = 4;
			this->label2->Text = L"Estado del sistema:";
			this->label2->Click += gcnew System::EventHandler(this, &FormMenuJefe::label2_Click);
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"MS Reference Sans Serif", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label3->Location = System::Drawing::Point(669, 173);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(163, 16);
			this->label3->TabIndex = 5;
			this->label3->Text = L"Reporte del sistema:";
			this->label3->Click += gcnew System::EventHandler(this, &FormMenuJefe::label3_Click);
			// 
			// panel1
			// 
			this->panel1->BackColor = System::Drawing::SystemColors::ActiveCaption;
			this->panel1->Controls->Add(this->btnVerEstado);
			this->panel1->Controls->Add(this->btnDetener);
			this->panel1->Controls->Add(this->btnAprobar);
			this->panel1->Dock = System::Windows::Forms::DockStyle::Left;
			this->panel1->Location = System::Drawing::Point(0, 0);
			this->panel1->Margin = System::Windows::Forms::Padding(4, 4, 4, 4);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(288, 278);
			this->panel1->TabIndex = 6;
			// 
			// FormMenuJefe
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(9, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(908, 278);
			this->Controls->Add(this->panel1);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Font = (gcnew System::Drawing::Font(L"MS Reference Sans Serif", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->Margin = System::Windows::Forms::Padding(3, 2, 3, 2);
			this->Name = L"FormMenuJefe";
			this->Text = L"FormMenuJefe";
			this->panel1->ResumeLayout(false);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void button1_Click_1(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void label3_Click(System::Object^ sender, System::EventArgs^ e) {
	}
private: System::Void label2_Click(System::Object^ sender, System::EventArgs^ e) {
}
};
}
