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
	/// Gestión de Tareas — Ciclo Activo.
	/// 4 tabs simulados (Posicionar / Sostener / Soldar / Coordinada).
	/// Cada tab muestra su DataGridView, panel de progreso y botones de acción.
	/// Controllers: TareaPosicionarController, TareaSostenerController,
	///              TareaSoldarController, TareaCoordinadaController,
	///              EventoTareaController
	/// </summary>
	public ref class FormMenuOperador : public System::Windows::Forms::Form
	{
	public:
		FormMenuOperador(void)
		{
			InitializeComponent();

			ctrlPosicionar = gcnew TareaPosicionarController();
			ctrlSostener = gcnew TareaSostenerController();
			ctrlSoldar = gcnew TareaSoldarController();
			ctrlCoordinada = gcnew TareaCoordinadaController();
			ctrlEvento = gcnew EventoTareaController();

			tabActivo = 0; // 0=Posicionar 1=Sostener 2=Soldar 3=Coordinada

			this->Load += gcnew EventHandler(this, &FormMenuOperador::FormMenuOperador_Load);
		}

	protected:
		~FormMenuOperador()
		{
			if (components)
				delete components;
		}

	private:
		// ---------------------------------------------------------------
		// Controllers
		// ---------------------------------------------------------------
		TareaPosicionarController^ ctrlPosicionar;
		TareaSostenerController^ ctrlSostener;
		TareaSoldarController^ ctrlSoldar;
		TareaCoordinadaController^ ctrlCoordinada;
		EventoTareaController^ ctrlEvento;

		int tabActivo; // tab actualmente seleccionado

		// ---------------------------------------------------------------
		// Colores constantes
		// ---------------------------------------------------------------
		static System::Drawing::Color FONDO_FORM = System::Drawing::Color::FromArgb(18, 26, 38);
		static System::Drawing::Color FONDO_PANEL = System::Drawing::Color::FromArgb(28, 38, 54);
		static System::Drawing::Color ACENTO = System::Drawing::Color::FromArgb(230, 160, 0);
		static System::Drawing::Color TEXTO_PRINC = System::Drawing::Color::White;
		static System::Drawing::Color TEXTO_SEC = System::Drawing::Color::FromArgb(160, 180, 210);
		static System::Drawing::Color AZUL_INFO = System::Drawing::Color::FromArgb(80, 160, 255);
		static System::Drawing::Color VERDE_OK = System::Drawing::Color::FromArgb(0, 200, 100);
		static System::Drawing::Color ROJO_ERR = System::Drawing::Color::FromArgb(200, 40, 40);

		// ---------------------------------------------------------------
		// Load
		// ---------------------------------------------------------------
		void FormMenuOperador_Load(System::Object^ sender, System::EventArgs^ e)
		{
			CambiarTab(0);
		}

		// ---------------------------------------------------------------
		// Cambiar tab activo
		// ---------------------------------------------------------------
		void CambiarTab(int nuevoTab)
		{
			tabActivo = nuevoTab;

			// Resetear estilo de todos los botones tab
			array<Button^>^ tabs = gcnew array<Button^>(4) {
				btnTabPosicionar, btnTabSostener, btnTabSoldar, btnTabCoordinada
			};
			for each (Button ^ btn in tabs)
			{
				btn->BackColor = FONDO_PANEL;
				btn->ForeColor = TEXTO_SEC;
				btn->FlatAppearance->BorderColor = System::Drawing::Color::FromArgb(50, 70, 100);
			}
			// Resaltar tab activo
			tabs[tabActivo]->BackColor = ACENTO;
			tabs[tabActivo]->ForeColor = System::Drawing::Color::Black;
			tabs[tabActivo]->FlatAppearance->BorderColor = ACENTO;

			// Cargar contenido del tab
			CargarGrid();
			LimpiarDetalle();
			ActualizarEtiquetasTab();
		}

		// ---------------------------------------------------------------
		// Cargar DataGridView según tab activo
		// ---------------------------------------------------------------
		void CargarGrid()
		{
			dataGridViewTareas->Rows->Clear();

			// Ajustar columnas según tab
			ConfigurarColumnasGrid();

			switch (tabActivo)
			{
			case 0: // Posicionar
				for each (TareaPosicionarModel ^ t in ctrlPosicionar->obtenerTodos())
				{
					dataGridViewTareas->Rows->Add(
						t->Id, t->Estado,
						t->PosicionObjetivo.ToString("F1"),
						t->Tolerancia.ToString("F1"));
				}
				break;

			case 1: // Sostener
				for each (TareaSostenerModel ^ t in ctrlSostener->obtenerTodos())
				{
					dataGridViewTareas->Rows->Add(
						t->Id, t->Estado,
						t->FuerzaSosten.ToString("F1"),
						t->Duracion.ToString());
				}
				break;

			case 2: // Soldar
				for each (TareaSoldarModel ^ t in ctrlSoldar->obtenerTodos())
				{
					dataGridViewTareas->Rows->Add(
						t->Id, t->Estado,
						t->PuntosObjetivo.ToString(),
						t->PuntosCompletados.ToString(),
						t->Temperatura.ToString("F1"));
				}
				break;

			case 3: // Coordinada
				for each (TareaCoordinadaModel ^ t in ctrlCoordinada->obtenerTodos())
				{
					dataGridViewTareas->Rows->Add(
						t->Id, t->Estado,
						t->TotalConfirmado.ToString(),
						t->TotalRequerido.ToString());
				}
				break;
			}

			ColorearColumnaEstado();
		}

		// ---------------------------------------------------------------
		// Configurar columnas del grid según el tab activo
		// ---------------------------------------------------------------
		void ConfigurarColumnasGrid()
		{
			dataGridViewTareas->Columns->Clear();

			// Columna ID siempre presente
			DataGridViewTextBoxColumn^ colId = gcnew DataGridViewTextBoxColumn();
			colId->HeaderText = L"ID";
			colId->Name = L"colId";
			colId->MinimumWidth = 50;

			DataGridViewTextBoxColumn^ colEstado = gcnew DataGridViewTextBoxColumn();
			colEstado->HeaderText = L"Estado";
			colEstado->Name = L"colEstado";
			colEstado->MinimumWidth = 90;

			dataGridViewTareas->Columns->Add(colId);
			dataGridViewTareas->Columns->Add(colEstado);

			switch (tabActivo)
			{
			case 0: // Posicionar
			{
				DataGridViewTextBoxColumn^ c1 = gcnew DataGridViewTextBoxColumn();
				c1->HeaderText = L"Pos Objetivo"; c1->Name = L"c1";
				DataGridViewTextBoxColumn^ c2 = gcnew DataGridViewTextBoxColumn();
				c2->HeaderText = L"Tolerancia"; c2->Name = L"c2";
				dataGridViewTareas->Columns->Add(c1);
				dataGridViewTareas->Columns->Add(c2);
				break;
			}
			case 1: // Sostener
			{
				DataGridViewTextBoxColumn^ c1 = gcnew DataGridViewTextBoxColumn();
				c1->HeaderText = L"Fuerza Sosten"; c1->Name = L"c1";
				DataGridViewTextBoxColumn^ c2 = gcnew DataGridViewTextBoxColumn();
				c2->HeaderText = L"Duración (s)"; c2->Name = L"c2";
				dataGridViewTareas->Columns->Add(c1);
				dataGridViewTareas->Columns->Add(c2);
				break;
			}
			case 2: // Soldar
			{
				DataGridViewTextBoxColumn^ c1 = gcnew DataGridViewTextBoxColumn();
				c1->HeaderText = L"Pts Objetivo"; c1->Name = L"c1";
				DataGridViewTextBoxColumn^ c2 = gcnew DataGridViewTextBoxColumn();
				c2->HeaderText = L"Pts Completados"; c2->Name = L"c2";
				DataGridViewTextBoxColumn^ c3 = gcnew DataGridViewTextBoxColumn();
				c3->HeaderText = L"Temperatura (°C)"; c3->Name = L"c3";
				dataGridViewTareas->Columns->Add(c1);
				dataGridViewTareas->Columns->Add(c2);
				dataGridViewTareas->Columns->Add(c3);
				break;
			}
			case 3: // Coordinada
			{
				DataGridViewTextBoxColumn^ c1 = gcnew DataGridViewTextBoxColumn();
				c1->HeaderText = L"Total Confirmado"; c1->Name = L"c1";
				DataGridViewTextBoxColumn^ c2 = gcnew DataGridViewTextBoxColumn();
				c2->HeaderText = L"Total Requerido"; c2->Name = L"c2";
				dataGridViewTareas->Columns->Add(c1);
				dataGridViewTareas->Columns->Add(c2);
				break;
			}
			}

			// Aplicar estilos de header después de agregar columnas
			AplicarEstiloHeader();
		}

		void AplicarEstiloHeader()
		{
			System::Windows::Forms::DataGridViewCellStyle^ estiloHeader =
				gcnew System::Windows::Forms::DataGridViewCellStyle();
			estiloHeader->BackColor = System::Drawing::Color::FromArgb(15, 22, 32);
			estiloHeader->ForeColor = ACENTO;
			estiloHeader->Font = gcnew System::Drawing::Font(L"Segoe UI", 9.0F,
				System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0));
			dataGridViewTareas->ColumnHeadersDefaultCellStyle = estiloHeader;
		}

		// ---------------------------------------------------------------
		// Colorear columna Estado (índice 1)
		// ---------------------------------------------------------------
		void ColorearColumnaEstado()
		{
			for each (DataGridViewRow ^ row in dataGridViewTareas->Rows)
			{
				if (row->IsNewRow) continue;
				String^ estado = row->Cells[1]->Value->ToString();
				DataGridViewCell^ celda = row->Cells[1];
				if (estado == "PENDIENTE")
					celda->Style->ForeColor = ACENTO;
				else if (estado == "EN CURSO")
					celda->Style->ForeColor = AZUL_INFO;
				else if (estado == "COMPLETADA")
					celda->Style->ForeColor = VERDE_OK;
				else
					celda->Style->ForeColor = TEXTO_SEC;
			}
		}

		// ---------------------------------------------------------------
		// Al seleccionar fila en el grid → actualizar detalle y progreso
		// ---------------------------------------------------------------
		void dataGridViewTareas_SelectionChanged(System::Object^ sender, System::EventArgs^ e)
		{
			if (dataGridViewTareas->SelectedRows->Count == 0) return;
			DataGridViewRow^ row = dataGridViewTareas->SelectedRows[0];
			if (row->IsNewRow) return;

			String^ id = row->Cells[0]->Value->ToString();
			MostrarDetalle(id);
			ActualizarProgreso(id);
		}

		// ---------------------------------------------------------------
		// Mostrar panel de detalle
		// ---------------------------------------------------------------
		void MostrarDetalle(String^ id)
		{
			switch (tabActivo)
			{
			case 0:
			{
				TareaPosicionarModel^ t = ctrlPosicionar->buscarPorId(id);
				if (t == nullptr) return;
				labelDetalleTitulo->Text = "Detalle — Tarea Posicionar #" + t->Id;
				labelDetalleC1Val->Text = t->Id;
				labelDetalleC2Val->Text = t->Estado;
				labelDetalleC3Val->Text = t->PosicionObjetivo.ToString("F1");
				labelDetalleC4Val->Text = t->Tolerancia.ToString("F1");
				labelDetalleC5Val->Text = "";
				labelDetalleC1Hdr->Text = "ID";
				labelDetalleC2Hdr->Text = "Estado";
				labelDetalleC3Hdr->Text = "Pos Objetivo";
				labelDetalleC4Hdr->Text = "Tolerancia";
				labelDetalleC5Hdr->Text = "";
				ColorearLabelEstado(labelDetalleC2Val, t->Estado);
				break;
			}
			case 1:
			{
				TareaSostenerModel^ t = ctrlSostener->buscarPorId(id);
				if (t == nullptr) return;
				labelDetalleTitulo->Text = "Detalle — Tarea Sostener #" + t->Id;
				labelDetalleC1Val->Text = t->Id;
				labelDetalleC2Val->Text = t->Estado;
				labelDetalleC3Val->Text = t->FuerzaSosten.ToString("F1") + " N";
				labelDetalleC4Val->Text = t->Duracion.ToString() + " s";
				labelDetalleC5Val->Text = "";
				labelDetalleC1Hdr->Text = "ID";
				labelDetalleC2Hdr->Text = "Estado";
				labelDetalleC3Hdr->Text = "Fuerza Sosten";
				labelDetalleC4Hdr->Text = "Duración";
				labelDetalleC5Hdr->Text = "";
				ColorearLabelEstado(labelDetalleC2Val, t->Estado);
				break;
			}
			case 2:
			{
				TareaSoldarModel^ t = ctrlSoldar->buscarPorId(id);
				if (t == nullptr) return;
				labelDetalleTitulo->Text = "Detalle — Tarea Soldar #" + t->Id;
				labelDetalleC1Val->Text = t->Id;
				labelDetalleC2Val->Text = t->Estado;
				labelDetalleC3Val->Text = t->PuntosObjetivo.ToString();
				labelDetalleC4Val->Text = t->PuntosCompletados.ToString();
				labelDetalleC5Val->Text = t->Temperatura.ToString("F1") + " °C";
				labelDetalleC1Hdr->Text = "ID";
				labelDetalleC2Hdr->Text = "Estado";
				labelDetalleC3Hdr->Text = "Pts Objetivo";
				labelDetalleC4Hdr->Text = "Pts Completados";
				labelDetalleC5Hdr->Text = "Temperatura";
				ColorearLabelEstado(labelDetalleC2Val, t->Estado);
				break;
			}
			case 3:
			{
				TareaCoordinadaModel^ t = ctrlCoordinada->buscarPorId(id);
				if (t == nullptr) return;
				labelDetalleTitulo->Text = "Detalle — Tarea Coordinada #" + t->Id;
				labelDetalleC1Val->Text = t->Id;
				labelDetalleC2Val->Text = t->Estado;
				labelDetalleC3Val->Text = t->TotalConfirmado.ToString();
				labelDetalleC4Val->Text = t->TotalRequerido.ToString();
				labelDetalleC5Val->Text = "";
				labelDetalleC1Hdr->Text = "ID";
				labelDetalleC2Hdr->Text = "Estado";
				labelDetalleC3Hdr->Text = "Total Confirmado";
				labelDetalleC4Hdr->Text = "Total Requerido";
				labelDetalleC5Hdr->Text = "";
				ColorearLabelEstado(labelDetalleC2Val, t->Estado);
				break;
			}
			}
		}

		void ColorearLabelEstado(Label^ lbl, String^ estado)
		{
			if (estado == "PENDIENTE")        lbl->ForeColor = ACENTO;
			else if (estado == "EN CURSO")    lbl->ForeColor = AZUL_INFO;
			else if (estado == "COMPLETADA")  lbl->ForeColor = VERDE_OK;
			else                              lbl->ForeColor = TEXTO_SEC;
		}

		void LimpiarDetalle()
		{
			labelDetalleTitulo->Text = "Detalle — selecciona una tarea";
			labelDetalleC1Val->Text = "—";
			labelDetalleC2Val->Text = "—";
			labelDetalleC3Val->Text = "—";
			labelDetalleC4Val->Text = "—";
			labelDetalleC5Val->Text = "—";
			labelDetalleC1Hdr->Text = "ID";
			labelDetalleC2Hdr->Text = "Estado";
			labelDetalleC3Hdr->Text = "—";
			labelDetalleC4Hdr->Text = "—";
			labelDetalleC5Hdr->Text = "—";
			labelProgreso->Text = "—";
			progressBarTarea->Value = 0;
		}

		// ---------------------------------------------------------------
		// Actualizar barra de progreso según tab y tarea seleccionada
		// ---------------------------------------------------------------
		void ActualizarProgreso(String^ id)
		{
			switch (tabActivo)
			{
			case 0: // Posicionar — progreso: estado (PENDIENTE=0% EN CURSO=50% COMPLETADA=100%)
			{
				TareaPosicionarModel^ t = ctrlPosicionar->buscarPorId(id);
				if (t == nullptr) return;
				int pct = (t->Estado == "COMPLETADA") ? 100 : (t->Estado == "EN CURSO") ? 50 : 0;
				progressBarTarea->Value = pct;
				labelProgreso->Text = "PosObj " + t->PosicionObjetivo.ToString("F1")
					+ " — Tol " + t->Tolerancia.ToString("F1")
					+ "  (" + pct.ToString() + "%)";
				break;
			}
			case 1: // Sostener — progreso: estado
			{
				TareaSostenerModel^ t = ctrlSostener->buscarPorId(id);
				if (t == nullptr) return;
				int pct = (t->Estado == "COMPLETADA") ? 100 : (t->Estado == "EN CURSO") ? 50 : 0;
				progressBarTarea->Value = pct;
				labelProgreso->Text = "Fuerza " + t->FuerzaSosten.ToString("F1")
					+ " N  — Dur " + t->Duracion.ToString() + " s"
					+ "  (" + pct.ToString() + "%)";
				break;
			}
			case 2: // Soldar — progreso real: puntosCompletados / puntosObjetivo
			{
				TareaSoldarModel^ t = ctrlSoldar->buscarPorId(id);
				if (t == nullptr) return;
				int obj = t->PuntosObjetivo;
				int comp = t->PuntosCompletados;
				int pct = (obj > 0) ? (int)((double)comp / obj * 100) : 0;
				if (pct > 100) pct = 100;
				progressBarTarea->Value = pct;
				labelProgreso->Text = comp.ToString() + " / " + obj.ToString()
					+ " puntos soldados (" + pct.ToString() + "%)";
				break;
			}
			case 3: // Coordinada — progreso: totalConfirmado / totalRequerido
			{
				TareaCoordinadaModel^ t = ctrlCoordinada->buscarPorId(id);
				if (t == nullptr) return;
				int req = t->TotalRequerido;
				int conf = t->TotalConfirmado;
				int pct = (req > 0) ? (int)((double)conf / req * 100) : 0;
				if (pct > 100) pct = 100;
				progressBarTarea->Value = pct;
				labelProgreso->Text = conf.ToString() + " / " + req.ToString()
					+ " confirmados (" + pct.ToString() + "%)";
				break;
			}
			}
		}

		// ---------------------------------------------------------------
		// Actualizar etiquetas y texto del botón de acción según tab
		// ---------------------------------------------------------------
		void ActualizarEtiquetasTab()
		{
			switch (tabActivo)
			{
			case 0:
				labelSeccionProgreso->Text = "Progreso — Tarea seleccionada";
				btnAccion1->Text = "+ Avanzar estado";
				break;
			case 1:
				labelSeccionProgreso->Text = "Progreso — Tarea seleccionada";
				btnAccion1->Text = "+ Confirmar sostén";
				break;
			case 2:
				labelSeccionProgreso->Text = "Progreso de soldadura — Tarea seleccionada (GDI+)";
				btnAccion1->Text = "+ Punto soldado";
				break;
			case 3:
				labelSeccionProgreso->Text = "Progreso — Tarea seleccionada";
				btnAccion1->Text = "+ Confirmar brazo";
				break;
			}
		}

		// ---------------------------------------------------------------
		// Obtener ID de la fila seleccionada (nullptr si no hay)
		// ---------------------------------------------------------------
		String^ ObtenerIdSeleccionado()
		{
			if (dataGridViewTareas->SelectedRows->Count == 0) return nullptr;
			DataGridViewRow^ row = dataGridViewTareas->SelectedRows[0];
			if (row->IsNewRow) return nullptr;
			return row->Cells[0]->Value->ToString();
		}

		// ---------------------------------------------------------------
		// Botón Acción 1: lógica específica por tab
		// ---------------------------------------------------------------
		void btnAccion1_Click(System::Object^ sender, System::EventArgs^ e)
		{
			String^ id = ObtenerIdSeleccionado();
			if (id == nullptr)
			{
				MessageBox::Show("Selecciona una tarea primero.", "Aviso",
					MessageBoxButtons::OK, MessageBoxIcon::Information);
				return;
			}

			switch (tabActivo)
			{
			case 0: // Posicionar — avanzar estado manualmente
			{
				TareaPosicionarModel^ t = ctrlPosicionar->buscarPorId(id);
				if (t == nullptr) return;
				String^ nuevoEstado = (t->Estado == "PENDIENTE") ? "EN CURSO" : "COMPLETADA";
				ctrlPosicionar->modificar(id, nuevoEstado, t->PosicionObjetivo, t->Tolerancia);
				break;
			}
			case 1: // Sostener — avanzar estado
			{
				TareaSostenerModel^ t = ctrlSostener->buscarPorId(id);
				if (t == nullptr) return;
				String^ nuevoEstado = (t->Estado == "PENDIENTE") ? "EN CURSO" : "COMPLETADA";
				ctrlSostener->modificar(id, nuevoEstado, t->FuerzaSosten, t->Duracion);
				break;
			}
			case 2: // Soldar — incrementar punto completado
			{
				TareaSoldarModel^ t = ctrlSoldar->buscarPorId(id);
				if (t == nullptr) return;
				if (t->PuntosCompletados >= t->PuntosObjetivo)
				{
					MessageBox::Show("Ya se alcanzaron todos los puntos objetivo.", "Aviso",
						MessageBoxButtons::OK, MessageBoxIcon::Information);
					return;
				}
				ctrlSoldar->modificar(id, "EN CURSO", t->PuntosObjetivo,
					t->PuntosCompletados + 1, t->Temperatura);
				break;
			}
			case 3: // Coordinada — incrementar confirmado
			{
				TareaCoordinadaModel^ t = ctrlCoordinada->buscarPorId(id);
				if (t == nullptr) return;
				if (t->TotalConfirmado >= t->TotalRequerido)
				{
					MessageBox::Show("Ya se confirmaron todos los brazos requeridos.", "Aviso",
						MessageBoxButtons::OK, MessageBoxIcon::Information);
					return;
				}
				ctrlCoordinada->modificar(id, "EN CURSO",
					t->TotalConfirmado + 1, t->TotalRequerido);
				break;
			}
			}

			CargarGrid();
			ActualizarProgreso(id);
			MostrarDetalle(id);
		}

		// ---------------------------------------------------------------
		// Botón Marcar COMPLETADA
		// ---------------------------------------------------------------
		void btnCompletada_Click(System::Object^ sender, System::EventArgs^ e)
		{
			String^ id = ObtenerIdSeleccionado();
			if (id == nullptr)
			{
				MessageBox::Show("Selecciona una tarea primero.", "Aviso",
					MessageBoxButtons::OK, MessageBoxIcon::Information);
				return;
			}

			System::Windows::Forms::DialogResult res = MessageBox::Show(
				"¿Marcar la tarea #" + id + " como COMPLETADA?",
				"Confirmar", MessageBoxButtons::YesNo, MessageBoxIcon::Question);

			if (res != System::Windows::Forms::DialogResult::Yes) return;

			switch (tabActivo)
			{
			case 0:
			{
				TareaPosicionarModel^ t = ctrlPosicionar->buscarPorId(id);
				if (t) ctrlPosicionar->modificar(id, "COMPLETADA", t->PosicionObjetivo, t->Tolerancia);
				break;
			}
			case 1:
			{
				TareaSostenerModel^ t = ctrlSostener->buscarPorId(id);
				if (t) ctrlSostener->modificar(id, "COMPLETADA", t->FuerzaSosten, t->Duracion);
				break;
			}
			case 2:
			{
				TareaSoldarModel^ t = ctrlSoldar->buscarPorId(id);
				if (t) ctrlSoldar->modificar(id, "COMPLETADA", t->PuntosObjetivo,
					t->PuntosCompletados, t->Temperatura);
				break;
			}
			case 3:
			{
				TareaCoordinadaModel^ t = ctrlCoordinada->buscarPorId(id);
				if (t) ctrlCoordinada->modificar(id, "COMPLETADA",
					t->TotalConfirmado, t->TotalRequerido);
				break;
			}
			}

			CargarGrid();
			LimpiarDetalle();
		}

		// ---------------------------------------------------------------
		// Botón Registrar evento
		// ---------------------------------------------------------------
		void btnRegistrarEvento_Click(System::Object^ sender, System::EventArgs^ e)
		{
			String^ id = ObtenerIdSeleccionado();
			if (id == nullptr)
			{
				MessageBox::Show("Selecciona una tarea primero.", "Aviso",
					MessageBoxButtons::OK, MessageBoxIcon::Information);
				return;
			}

			// Determinar tipo de tarea para la descripción
			String^ tipoTarea;
			switch (tabActivo)
			{
			case 0: tipoTarea = "Posicionar"; break;
			case 1: tipoTarea = "Sostener";   break;
			case 2: tipoTarea = "Soldar";     break;
			case 3: tipoTarea = "Coordinada"; break;
			default: tipoTarea = "Tarea";     break;
			}

			// Generar ID de evento y timestamp
			String^ eventoId = DateTime::Now.Ticks.ToString();
			String^ timestamp = DateTime::Now.ToString("yyyy-MM-dd HH:mm:ss");
			String^ descripcion = "Evento registrado por Operador — Tarea " + tipoTarea + " #" + id;
			String^ resultadoD = "EN PROCESO";

			ctrlEvento->agregar(eventoId, timestamp, descripcion, id, resultadoD);

			MessageBox::Show("Evento registrado correctamente para la tarea #" + id + ".",
				"Evento registrado", MessageBoxButtons::OK, MessageBoxIcon::Information);
		}

		// ---------------------------------------------------------------
		// Handlers de los botones tab
		// ---------------------------------------------------------------
		void btnTabPosicionar_Click(System::Object^ sender, System::EventArgs^ e) { CambiarTab(0); }
		void btnTabSostener_Click(System::Object^ sender, System::EventArgs^ e) { CambiarTab(1); }
		void btnTabSoldar_Click(System::Object^ sender, System::EventArgs^ e) { CambiarTab(2); }
		void btnTabCoordinada_Click(System::Object^ sender, System::EventArgs^ e) { CambiarTab(3); }

		// ---------------------------------------------------------------
		// InitializeComponent
		// ---------------------------------------------------------------
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		void InitializeComponent(void)
		{
			// Declarar controles
			this->btnTabPosicionar = gcnew System::Windows::Forms::Button();
			this->btnTabSostener = gcnew System::Windows::Forms::Button();
			this->btnTabSoldar = gcnew System::Windows::Forms::Button();
			this->btnTabCoordinada = gcnew System::Windows::Forms::Button();
			this->panelTabBar = gcnew System::Windows::Forms::Panel();
			this->dataGridViewTareas = gcnew System::Windows::Forms::DataGridView();
			this->labelSeccionProgreso = gcnew System::Windows::Forms::Label();
			this->panelProgreso = gcnew System::Windows::Forms::Panel();
			this->progressBarTarea = gcnew System::Windows::Forms::ProgressBar();
			this->labelProgreso = gcnew System::Windows::Forms::Label();
			this->btnAccion1 = gcnew System::Windows::Forms::Button();
			this->btnCompletada = gcnew System::Windows::Forms::Button();
			this->btnRegistrarEvento = gcnew System::Windows::Forms::Button();
			this->labelDetalleTitulo = gcnew System::Windows::Forms::Label();
			this->panelDetalle = gcnew System::Windows::Forms::Panel();
			this->labelDetalleC1Hdr = gcnew System::Windows::Forms::Label();
			this->labelDetalleC2Hdr = gcnew System::Windows::Forms::Label();
			this->labelDetalleC3Hdr = gcnew System::Windows::Forms::Label();
			this->labelDetalleC4Hdr = gcnew System::Windows::Forms::Label();
			this->labelDetalleC5Hdr = gcnew System::Windows::Forms::Label();
			this->labelDetalleC1Val = gcnew System::Windows::Forms::Label();
			this->labelDetalleC2Val = gcnew System::Windows::Forms::Label();
			this->labelDetalleC3Val = gcnew System::Windows::Forms::Label();
			this->labelDetalleC4Val = gcnew System::Windows::Forms::Label();
			this->labelDetalleC5Val = gcnew System::Windows::Forms::Label();
			this->labelTitulo = gcnew System::Windows::Forms::Label();

			this->panelTabBar->SuspendLayout();
			this->panelProgreso->SuspendLayout();
			this->panelDetalle->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridViewTareas))->BeginInit();
			this->SuspendLayout();

			// ---- labelTitulo ----
			this->labelTitulo->AutoSize = true;
			this->labelTitulo->Font = gcnew System::Drawing::Font(L"Segoe UI", 14.0F,
				System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0));
			this->labelTitulo->ForeColor = TEXTO_PRINC;
			this->labelTitulo->Location = System::Drawing::Point(20, 16);
			this->labelTitulo->Name = L"labelTitulo";
			this->labelTitulo->Text = L"Gestión de Tareas — Ciclo Activo";

			// ---- panelTabBar (fila de 4 botones tab) ----
			this->panelTabBar->BackColor = FONDO_PANEL;
			this->panelTabBar->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->panelTabBar->Location = System::Drawing::Point(20, 52);
			this->panelTabBar->Name = L"panelTabBar";
			this->panelTabBar->Size = System::Drawing::Size(1140, 40);

			// ---- Botones tab — Posicionar ----
			this->btnTabPosicionar->BackColor = FONDO_PANEL;
			this->btnTabPosicionar->ForeColor = TEXTO_SEC;
			this->btnTabPosicionar->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnTabPosicionar->FlatAppearance->BorderSize = 0;
			this->btnTabPosicionar->FlatAppearance->BorderColor = System::Drawing::Color::FromArgb(50, 70, 100);
			this->btnTabPosicionar->Font = gcnew System::Drawing::Font(L"Segoe UI", 9.0F,
				System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0));
			this->btnTabPosicionar->Location = System::Drawing::Point(0, 0);
			this->btnTabPosicionar->Size = System::Drawing::Size(284, 38);
			this->btnTabPosicionar->Text = L"Posicionar";
			this->btnTabPosicionar->UseVisualStyleBackColor = false;

			// ---- Botones tab — Sostener ----
			this->btnTabSostener->BackColor = FONDO_PANEL;
			this->btnTabSostener->ForeColor = TEXTO_SEC;
			this->btnTabSostener->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnTabSostener->FlatAppearance->BorderSize = 0;
			this->btnTabSostener->FlatAppearance->BorderColor = System::Drawing::Color::FromArgb(50, 70, 100);
			this->btnTabSostener->Font = gcnew System::Drawing::Font(L"Segoe UI", 9.0F,
				System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0));
			this->btnTabSostener->Location = System::Drawing::Point(285, 0);
			this->btnTabSostener->Size = System::Drawing::Size(284, 38);
			this->btnTabSostener->Text = L"Sostener";
			this->btnTabSostener->UseVisualStyleBackColor = false;

			// ---- Botones tab — Soldar ----
			this->btnTabSoldar->BackColor = FONDO_PANEL;
			this->btnTabSoldar->ForeColor = TEXTO_SEC;
			this->btnTabSoldar->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnTabSoldar->FlatAppearance->BorderSize = 0;
			this->btnTabSoldar->FlatAppearance->BorderColor = System::Drawing::Color::FromArgb(50, 70, 100);
			this->btnTabSoldar->Font = gcnew System::Drawing::Font(L"Segoe UI", 9.0F,
				System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0));
			this->btnTabSoldar->Location = System::Drawing::Point(570, 0);
			this->btnTabSoldar->Size = System::Drawing::Size(284, 38);
			this->btnTabSoldar->Text = L"Soldar";
			this->btnTabSoldar->UseVisualStyleBackColor = false;

			// ---- Botones tab — Coordinada ----
			this->btnTabCoordinada->BackColor = FONDO_PANEL;
			this->btnTabCoordinada->ForeColor = TEXTO_SEC;
			this->btnTabCoordinada->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnTabCoordinada->FlatAppearance->BorderSize = 0;
			this->btnTabCoordinada->FlatAppearance->BorderColor = System::Drawing::Color::FromArgb(50, 70, 100);
			this->btnTabCoordinada->Font = gcnew System::Drawing::Font(L"Segoe UI", 9.0F,
				System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0));
			this->btnTabCoordinada->Location = System::Drawing::Point(855, 0);
			this->btnTabCoordinada->Size = System::Drawing::Size(284, 38);
			this->btnTabCoordinada->Text = L"Coordinada";
			this->btnTabCoordinada->UseVisualStyleBackColor = false;

			btnTabPosicionar->Click += gcnew EventHandler(this, &FormMenuOperador::btnTabPosicionar_Click);
			btnTabSostener->Click += gcnew EventHandler(this, &FormMenuOperador::btnTabSostener_Click);
			btnTabSoldar->Click += gcnew EventHandler(this, &FormMenuOperador::btnTabSoldar_Click);
			btnTabCoordinada->Click += gcnew EventHandler(this, &FormMenuOperador::btnTabCoordinada_Click);

			this->panelTabBar->Controls->Add(btnTabPosicionar);
			this->panelTabBar->Controls->Add(btnTabSostener);
			this->panelTabBar->Controls->Add(btnTabSoldar);
			this->panelTabBar->Controls->Add(btnTabCoordinada);

			// ---- dataGridViewTareas ----
			System::Windows::Forms::DataGridViewCellStyle^ estiloCelda =
				gcnew System::Windows::Forms::DataGridViewCellStyle();
			estiloCelda->BackColor = FONDO_PANEL;
			estiloCelda->ForeColor = TEXTO_PRINC;
			estiloCelda->Font = gcnew System::Drawing::Font(L"Segoe UI", 9.0F,
				System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0));
			estiloCelda->SelectionBackColor = System::Drawing::Color::FromArgb(50, 80, 120);
			estiloCelda->SelectionForeColor = TEXTO_PRINC;

			this->dataGridViewTareas->BackgroundColor = FONDO_PANEL;
			this->dataGridViewTareas->GridColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->dataGridViewTareas->DefaultCellStyle = estiloCelda;
			this->dataGridViewTareas->ColumnHeadersBorderStyle = System::Windows::Forms::DataGridViewHeaderBorderStyle::Single;
			this->dataGridViewTareas->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridViewTareas->EnableHeadersVisualStyles = false;
			this->dataGridViewTareas->RowHeadersVisible = false;
			this->dataGridViewTareas->ReadOnly = true;
			this->dataGridViewTareas->AllowUserToAddRows = false;
			this->dataGridViewTareas->AutoSizeColumnsMode = System::Windows::Forms::DataGridViewAutoSizeColumnsMode::Fill;
			this->dataGridViewTareas->SelectionMode = System::Windows::Forms::DataGridViewSelectionMode::FullRowSelect;
			this->dataGridViewTareas->MultiSelect = false;
			this->dataGridViewTareas->Location = System::Drawing::Point(20, 98);
			this->dataGridViewTareas->Name = L"dataGridViewTareas";
			this->dataGridViewTareas->Size = System::Drawing::Size(1140, 170);
			this->dataGridViewTareas->RowTemplate->Height = 28;
			this->dataGridViewTareas->SelectionChanged += gcnew EventHandler(
				this, &FormMenuOperador::dataGridViewTareas_SelectionChanged);

			// ---- labelSeccionProgreso ----
			this->labelSeccionProgreso->AutoSize = true;
			this->labelSeccionProgreso->Font = gcnew System::Drawing::Font(L"Segoe UI", 9.0F,
				System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0));
			this->labelSeccionProgreso->ForeColor = ACENTO;
			this->labelSeccionProgreso->Location = System::Drawing::Point(20, 282);
			this->labelSeccionProgreso->Name = L"labelSeccionProgreso";
			this->labelSeccionProgreso->Text = L"Progreso — Tarea seleccionada";

			// ---- panelProgreso ----
			this->panelProgreso->BackColor = System::Drawing::Color::FromArgb(28, 38, 54);
			this->panelProgreso->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->panelProgreso->Location = System::Drawing::Point(20, 306);
			this->panelProgreso->Name = L"panelProgreso";
			this->panelProgreso->Size = System::Drawing::Size(900, 52);

			// ---- progressBarTarea ----
			this->progressBarTarea->Location = System::Drawing::Point(8, 8);
			this->progressBarTarea->Name = L"progressBarTarea";
			this->progressBarTarea->Size = System::Drawing::Size(660, 34);
			this->progressBarTarea->Maximum = 100;
			this->progressBarTarea->Value = 0;
			this->progressBarTarea->Style = System::Windows::Forms::ProgressBarStyle::Continuous;
			this->progressBarTarea->ForeColor = ACENTO;

			// ---- labelProgreso (texto encima de la barra) ----
			this->labelProgreso->AutoSize = false;
			this->labelProgreso->Font = gcnew System::Drawing::Font(L"Segoe UI", 10.0F,
				System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0));
			this->labelProgreso->ForeColor = System::Drawing::Color::Black;
			this->labelProgreso->BackColor = System::Drawing::Color::Transparent;
			this->labelProgreso->Location = System::Drawing::Point(8, 14);
			this->labelProgreso->Name = L"labelProgreso";
			this->labelProgreso->Size = System::Drawing::Size(650, 22);
			this->labelProgreso->Text = L"—";
			this->labelProgreso->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;

			this->panelProgreso->Controls->Add(this->progressBarTarea);
			this->panelProgreso->Controls->Add(this->labelProgreso);
			this->labelProgreso->BringToFront();

			// ---- Botón Acción 1 ----
			this->btnAccion1->BackColor = ACENTO;
			this->btnAccion1->ForeColor = System::Drawing::Color::Black;
			this->btnAccion1->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->btnAccion1->Font = gcnew System::Drawing::Font(L"Segoe UI", 9.0F,
				System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0));
			this->btnAccion1->Location = System::Drawing::Point(20, 370);
			this->btnAccion1->Size = System::Drawing::Size(206, 37);
			this->btnAccion1->Text = L"+ Punto soldado";
			this->btnAccion1->UseVisualStyleBackColor = false;

			// ---- Botón Marcar COMPLETADA ----
			this->btnCompletada->BackColor = ACENTO;
			this->btnCompletada->ForeColor = System::Drawing::Color::Black;
			this->btnCompletada->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->btnCompletada->Font = gcnew System::Drawing::Font(L"Segoe UI", 9.0F,
				System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0));
			this->btnCompletada->Location = System::Drawing::Point(236, 370);
			this->btnCompletada->Size = System::Drawing::Size(206, 37);
			this->btnCompletada->Text = L"Marcar COMPLETADA";
			this->btnCompletada->UseVisualStyleBackColor = false;

			// ---- Botón Registrar evento ----
			this->btnRegistrarEvento->BackColor = System::Drawing::Color::FromArgb(30, 58, 95);
			this->btnRegistrarEvento->ForeColor = TEXTO_PRINC;
			this->btnRegistrarEvento->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->btnRegistrarEvento->Font = gcnew System::Drawing::Font(L"Segoe UI", 9.0F,
				System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0));
			this->btnRegistrarEvento->Location = System::Drawing::Point(452, 370);
			this->btnRegistrarEvento->Size = System::Drawing::Size(206, 37);
			this->btnRegistrarEvento->Text = L"Registrar evento";
			this->btnRegistrarEvento->UseVisualStyleBackColor = false;

			btnAccion1->Click += gcnew EventHandler(this, &FormMenuOperador::btnAccion1_Click);
			btnCompletada->Click += gcnew EventHandler(this, &FormMenuOperador::btnCompletada_Click);
			btnRegistrarEvento->Click += gcnew EventHandler(this, &FormMenuOperador::btnRegistrarEvento_Click);

			// ---- labelDetalleTitulo ----
			this->labelDetalleTitulo->AutoSize = true;
			this->labelDetalleTitulo->Font = gcnew System::Drawing::Font(L"Segoe UI", 9.0F,
				System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0));
			this->labelDetalleTitulo->ForeColor = ACENTO;
			this->labelDetalleTitulo->Location = System::Drawing::Point(20, 422);
			this->labelDetalleTitulo->Name = L"labelDetalleTitulo";
			this->labelDetalleTitulo->Text = L"Detalle — selecciona una tarea";

			// ---- panelDetalle ----
			this->panelDetalle->BackColor = System::Drawing::Color::FromArgb(20, 30, 46);
			this->panelDetalle->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->panelDetalle->Location = System::Drawing::Point(20, 446);
			this->panelDetalle->Name = L"panelDetalle";
			this->panelDetalle->Size = System::Drawing::Size(1140, 80);

			// Headers del panel detalle
			int anchoCol = 220;

			this->labelDetalleC1Hdr->AutoSize = true;
			this->labelDetalleC1Hdr->Font = gcnew System::Drawing::Font(L"Segoe UI", 8.0F,
				System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0));
			this->labelDetalleC1Hdr->ForeColor = TEXTO_SEC;
			this->labelDetalleC1Hdr->Location = System::Drawing::Point(10, 10);
			this->labelDetalleC1Hdr->Text = L"ID";

			this->labelDetalleC2Hdr->AutoSize = true;
			this->labelDetalleC2Hdr->Font = gcnew System::Drawing::Font(L"Segoe UI", 8.0F,
				System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0));
			this->labelDetalleC2Hdr->ForeColor = TEXTO_SEC;
			this->labelDetalleC2Hdr->Location = System::Drawing::Point(10 + anchoCol, 10);
			this->labelDetalleC2Hdr->Text = L"Estado";

			this->labelDetalleC3Hdr->AutoSize = true;
			this->labelDetalleC3Hdr->Font = gcnew System::Drawing::Font(L"Segoe UI", 8.0F,
				System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0));
			this->labelDetalleC3Hdr->ForeColor = TEXTO_SEC;
			this->labelDetalleC3Hdr->Location = System::Drawing::Point(10 + anchoCol * 2, 10);
			this->labelDetalleC3Hdr->Text = L"—";

			this->labelDetalleC4Hdr->AutoSize = true;
			this->labelDetalleC4Hdr->Font = gcnew System::Drawing::Font(L"Segoe UI", 8.0F,
				System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0));
			this->labelDetalleC4Hdr->ForeColor = TEXTO_SEC;
			this->labelDetalleC4Hdr->Location = System::Drawing::Point(10 + anchoCol * 3, 10);
			this->labelDetalleC4Hdr->Text = L"—";

			this->labelDetalleC5Hdr->AutoSize = true;
			this->labelDetalleC5Hdr->Font = gcnew System::Drawing::Font(L"Segoe UI", 8.0F,
				System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0));
			this->labelDetalleC5Hdr->ForeColor = TEXTO_SEC;
			this->labelDetalleC5Hdr->Location = System::Drawing::Point(10 + anchoCol * 4, 10);
			this->labelDetalleC5Hdr->Text = L"—";

			// Valores del panel detalle
			this->labelDetalleC1Val->AutoSize = true;
			this->labelDetalleC1Val->Font = gcnew System::Drawing::Font(L"Segoe UI", 12.0F,
				System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0));
			this->labelDetalleC1Val->ForeColor = ACENTO;
			this->labelDetalleC1Val->Location = System::Drawing::Point(10, 34);
			this->labelDetalleC1Val->Text = L"—";

			this->labelDetalleC2Val->AutoSize = true;
			this->labelDetalleC2Val->Font = gcnew System::Drawing::Font(L"Segoe UI", 12.0F,
				System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0));
			this->labelDetalleC2Val->ForeColor = ACENTO;
			this->labelDetalleC2Val->Location = System::Drawing::Point(10 + anchoCol, 34);
			this->labelDetalleC2Val->Text = L"—";

			this->labelDetalleC3Val->AutoSize = true;
			this->labelDetalleC3Val->Font = gcnew System::Drawing::Font(L"Segoe UI", 12.0F,
				System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0));
			this->labelDetalleC3Val->ForeColor = ACENTO;
			this->labelDetalleC3Val->Location = System::Drawing::Point(10 + anchoCol * 2, 34);
			this->labelDetalleC3Val->Text = L"—";

			this->labelDetalleC4Val->AutoSize = true;
			this->labelDetalleC4Val->Font = gcnew System::Drawing::Font(L"Segoe UI", 12.0F,
				System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0));
			this->labelDetalleC4Val->ForeColor = ACENTO;
			this->labelDetalleC4Val->Location = System::Drawing::Point(10 + anchoCol * 3, 34);
			this->labelDetalleC4Val->Text = L"—";

			this->labelDetalleC5Val->AutoSize = true;
			this->labelDetalleC5Val->Font = gcnew System::Drawing::Font(L"Segoe UI", 12.0F,
				System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0));
			this->labelDetalleC5Val->ForeColor = ACENTO;
			this->labelDetalleC5Val->Location = System::Drawing::Point(10 + anchoCol * 4, 34);
			this->labelDetalleC5Val->Text = L"—";

			// labelDetalleC2Val es estado — color dinámico
			labelDetalleC2Val->ForeColor = ACENTO;

			this->panelDetalle->Controls->Add(labelDetalleC1Hdr);
			this->panelDetalle->Controls->Add(labelDetalleC2Hdr);
			this->panelDetalle->Controls->Add(labelDetalleC3Hdr);
			this->panelDetalle->Controls->Add(labelDetalleC4Hdr);
			this->panelDetalle->Controls->Add(labelDetalleC5Hdr);
			this->panelDetalle->Controls->Add(labelDetalleC1Val);
			this->panelDetalle->Controls->Add(labelDetalleC2Val);
			this->panelDetalle->Controls->Add(labelDetalleC3Val);
			this->panelDetalle->Controls->Add(labelDetalleC4Val);
			this->panelDetalle->Controls->Add(labelDetalleC5Val);

			// ---- Form ----
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = FONDO_FORM;
			this->ClientSize = System::Drawing::Size(1200, 560);
			this->Controls->Add(this->labelTitulo);
			this->Controls->Add(this->panelTabBar);
			this->Controls->Add(this->dataGridViewTareas);
			this->Controls->Add(this->labelSeccionProgreso);
			this->Controls->Add(this->panelProgreso);
			this->Controls->Add(this->btnAccion1);
			this->Controls->Add(this->btnCompletada);
			this->Controls->Add(this->btnRegistrarEvento);
			this->Controls->Add(this->labelDetalleTitulo);
			this->Controls->Add(this->panelDetalle);
			this->Name = L"FormMenuOperador";
			this->Text = L"FormMenuOperador";

			this->panelTabBar->ResumeLayout(false);
			this->panelProgreso->ResumeLayout(false);
			this->panelDetalle->ResumeLayout(false);
			this->panelDetalle->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridViewTareas))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();
		}
#pragma endregion

		// Controles
		System::Windows::Forms::Button^ btnTabPosicionar;
		System::Windows::Forms::Button^ btnTabSostener;
		System::Windows::Forms::Button^ btnTabSoldar;
		System::Windows::Forms::Button^ btnTabCoordinada;
		System::Windows::Forms::Panel^ panelTabBar;
		System::Windows::Forms::DataGridView^ dataGridViewTareas;
		System::Windows::Forms::Label^ labelSeccionProgreso;
		System::Windows::Forms::Panel^ panelProgreso;
		System::Windows::Forms::ProgressBar^ progressBarTarea;
		System::Windows::Forms::Label^ labelProgreso;
		System::Windows::Forms::Button^ btnAccion1;
		System::Windows::Forms::Button^ btnCompletada;
		System::Windows::Forms::Button^ btnRegistrarEvento;
		System::Windows::Forms::Label^ labelDetalleTitulo;
		System::Windows::Forms::Panel^ panelDetalle;
		System::Windows::Forms::Label^ labelDetalleC1Hdr;
		System::Windows::Forms::Label^ labelDetalleC2Hdr;
		System::Windows::Forms::Label^ labelDetalleC3Hdr;
		System::Windows::Forms::Label^ labelDetalleC4Hdr;
		System::Windows::Forms::Label^ labelDetalleC5Hdr;
		System::Windows::Forms::Label^ labelDetalleC1Val;
		System::Windows::Forms::Label^ labelDetalleC2Val;
		System::Windows::Forms::Label^ labelDetalleC3Val;
		System::Windows::Forms::Label^ labelDetalleC4Val;
		System::Windows::Forms::Label^ labelDetalleC5Val;
		System::Windows::Forms::Label^ labelTitulo;
	};
}
