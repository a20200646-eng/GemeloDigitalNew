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

		//
		LineaEnsamblajeModel^ lineaActual;
		String^ brazoActual;

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
	private: System::Windows::Forms::Panel^ panelLineaActiva;

	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ labelProgresoCola;
	private: System::Windows::Forms::Label^ labelPiezaActual;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ labelLineaActiva;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Label^ labelBrazoActual;

	private: System::Windows::Forms::Label^ label4;
		   static System::Drawing::Color ROJO_ERR = System::Drawing::Color::FromArgb(200, 40, 40);

		// ---------------------------------------------------------------
		// Load
		// ---------------------------------------------------------------
		void FormMenuOperador_Load(System::Object^ sender, System::EventArgs^ e)
		{
			dataGridViewTareas->SelectionChanged -= gcnew EventHandler(
				this, &FormMenuOperador::dataGridViewTareas_SelectionChanged);

			CambiarTab(0);

			dataGridViewTareas->SelectionChanged += gcnew EventHandler(
				this, &FormMenuOperador::dataGridViewTareas_SelectionChanged);

			ActualizarPanelLinea();
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

			//Desconectar evento antes de cargar
			dataGridViewTareas->SelectionChanged -= gcnew EventHandler(
				this, &FormMenuOperador::dataGridViewTareas_SelectionChanged);

			// Cargar contenido del tab
			CargarGrid();
			LimpiarDetalle();
			ActualizarEtiquetasTab();

			//Reconectar evento después de cargar
			dataGridViewTareas->SelectionChanged += gcnew EventHandler(
				this, &FormMenuOperador::dataGridViewTareas_SelectionChanged);


			// Seleccionar primera fila automáticamente
			if (dataGridViewTareas->Rows->Count > 0)
				dataGridViewTareas->Rows[0]->Selected = true;

		}

		// ---------------------------------------------------------------
		// Cargar DataGridView según tab activo
		// ---------------------------------------------------------------
		void CargarGrid()
		{
			dataGridViewTareas->Rows->Clear();
			ConfigurarColumnasGrid();

			switch (tabActivo)
			{
			case 0:
				for each(TareaPosicionarModel ^ t in ctrlPosicionar->obtenerTodos())
				{
					if (brazoActual != nullptr && !t->Id->Contains(brazoActual)) continue;
					dataGridViewTareas->Rows->Add(
						t->Id, t->Estado,
						t->PosicionObjetivo.ToString("F1"),
						t->Tolerancia.ToString("F1"));
				}
				break;

			case 1:
				for each(TareaSostenerModel ^ t in ctrlSostener->obtenerTodos())
				{
					if (brazoActual != nullptr && !t->Id->Contains(brazoActual)) continue;
					dataGridViewTareas->Rows->Add(
						t->Id, t->Estado,
						t->FuerzaSosten.ToString("F1"),
						t->Duracion.ToString());
				}
				break;

			case 2:
				for each(TareaSoldarModel ^ t in ctrlSoldar->obtenerTodos())
				{
					if (brazoActual != nullptr && !t->Id->Contains(brazoActual)) continue;
					dataGridViewTareas->Rows->Add(
						t->Id, t->Estado,
						t->PuntosObjetivo.ToString(),
						t->PuntosCompletados.ToString(),
						t->Temperatura.ToString("F1"));
				}
				break;

			case 3:
				for each(TareaCoordinadaModel ^ t in ctrlCoordinada->obtenerTodos())
				{
					if (brazoActual != nullptr && !t->Id->Contains(brazoActual)) continue;
					dataGridViewTareas->Rows->Add(
						t->Id, t->Estado,
						t->TotalConfirmado.ToString(),
						t->TotalRequerido.ToString());
				}
				break;
			}

			ColorearColumnaEstado();
			// Al final de CargarGrid(), después de ColorearColumnaEstado()
			if (tabActivo == 3 && dataGridViewTareas->SelectedRows->Count > 0)
			{
				String^ idSel = ObtenerIdSeleccionado();
				if (idSel != nullptr)
				{
					TareaCoordinadaModel^ t = ctrlCoordinada->buscarPorId(idSel);
					if (t != nullptr)
						btnAccion1->Enabled = (t->TotalConfirmado < t->TotalRequerido);
				}
			}
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
			if (row->Cells[0]->Value == nullptr) return;

			String^ id = row->Cells[0]->Value->ToString();

			try {
				MostrarDetalle(id);
				ActualizarProgreso(id);

			}
			catch (Exception^)
			{
				LimpiarDetalle();
			}

			// Controlar btnAccion1 para tab Coordinada
			if (tabActivo == 3)
			{
				TareaCoordinadaModel^ t = ctrlCoordinada->buscarPorId(id);
				if (t != nullptr)
					btnAccion1->Enabled = (t->TotalConfirmado < t->TotalRequerido);
			}
			
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
			case 0: // Posicionar — avanzar estado, COMPLETADA automática
			{
				TareaPosicionarModel^ t = ctrlPosicionar->buscarPorId(id);
				if (t == nullptr) return;
				if (t->Estado == "COMPLETADA")
				{
					MessageBox::Show("Esta tarea ya está completada.", "Aviso",
						MessageBoxButtons::OK, MessageBoxIcon::Information);
					return;
				}
				String^ nuevoEstado = (t->Estado == "PENDIENTE") ? "EN CURSO" : "COMPLETADA";
				ctrlPosicionar->modificar(id, nuevoEstado, t->PosicionObjetivo, t->Tolerancia);
				break;
			}
			case 1: // Sostener — avanzar estado, COMPLETADA automática
			{
				TareaSostenerModel^ t = ctrlSostener->buscarPorId(id);
				if (t == nullptr) return;
				if (t->Estado == "COMPLETADA")
				{
					MessageBox::Show("Esta tarea ya está completada.", "Aviso",
						MessageBoxButtons::OK, MessageBoxIcon::Information);
					return;
				}
				String^ nuevoEstado = (t->Estado == "PENDIENTE") ? "EN CURSO" : "COMPLETADA";
				ctrlSostener->modificar(id, nuevoEstado, t->FuerzaSosten, t->Duracion);
				break;
			}
			case 2: // Soldar — incrementar punto, COMPLETADA automática al llegar al objetivo
			{
				TareaSoldarModel^ t = ctrlSoldar->buscarPorId(id);
				if (t == nullptr) return;
				if (t->Estado == "COMPLETADA")
				{
					MessageBox::Show("Esta tarea ya está completada.", "Aviso",
						MessageBoxButtons::OK, MessageBoxIcon::Information);
					return;
				}
				int nuevosPuntos = t->PuntosCompletados + 1;
				String^ nuevoEstado = (nuevosPuntos >= t->PuntosObjetivo) ? "COMPLETADA" : "EN CURSO";
				ctrlSoldar->modificar(id, nuevoEstado, t->PuntosObjetivo, nuevosPuntos, t->Temperatura);
				break;
			}
			case 3: // Coordinada — confirmar, COMPLETADA automática + lógica pieza ensamblada
			{
				TareaCoordinadaModel^ t = ctrlCoordinada->buscarPorId(id);
				if (t == nullptr) return;
				if (t->Estado == "COMPLETADA")
				{
					MessageBox::Show("Esta tarea ya está completada.", "Aviso",
						MessageBoxButtons::OK, MessageBoxIcon::Information);
					return;
				}
				if (t->TotalConfirmado >= t->TotalRequerido)
				{
					MessageBox::Show("Ya se confirmaron todos los brazos requeridos.", "Aviso",
						MessageBoxButtons::OK, MessageBoxIcon::Information);
					return;
				}
				int nuevoConfirmado = t->TotalConfirmado + 1;
				String^ nuevoEstado = (nuevoConfirmado >= t->TotalRequerido) ? "COMPLETADA" : "EN CURSO";
				ctrlCoordinada->modificar(id, nuevoEstado, nuevoConfirmado, t->TotalRequerido);

				if (nuevoEstado == "COMPLETADA")
				{
					// Verificar si todas las COO están completadas
					int completadas = 0;
					for each (TareaCoordinadaModel ^ tc in ctrlCoordinada->obtenerTodos())
						if (tc->Estado == "COMPLETADA") completadas++;
					if (completadas == ctrlCoordinada->obtenerTodos()->Count)
						MessageBox::Show("¡Todos los brazos coordinados! Proceso de coordinación completo.",
							"Coordinación completa", MessageBoxButtons::OK, MessageBoxIcon::Information);

					// Marcar pieza actual como ENSAMBLADA
					if (lineaActual != nullptr && lineaActual->IndiceActual < lineaActual->ColaPiezas->Count)
					{
						PiezaModel^ pieza = lineaActual->ColaPiezas[lineaActual->IndiceActual];
						PanelLateralController^ ctrlPanel = gcnew PanelLateralController();
						EstructuraTechoController^ ctrlTecho = gcnew EstructuraTechoController();
						EstacionTrabajoController^ ctrlEstacion = gcnew EstacionTrabajoController();

						PanelLateralModel^ pl = dynamic_cast<PanelLateralModel^>(pieza);
						if (pl != nullptr)
						{
							EstacionTrabajoModel^ est = ctrlEstacion->buscarPorId(pl->EstacionId);
							if (est != nullptr)
								ctrlEstacion->modificar(est->Id, est->Tipo, est->CantidadPiezas - 1);
							ctrlPanel->modificar(pl->Id, pl->Material, pl->Peso,
								EstadoPieza::ENSAMBLADA, pl->PuntosAnclaje, pl->EstacionId);
						}
						else
						{
							EstructuraTechoModel^ et = dynamic_cast<EstructuraTechoModel^>(pieza);
							if (et != nullptr)
							{
								EstacionTrabajoModel^ est = ctrlEstacion->buscarPorId(et->EstacionId);
								if (est != nullptr)
									ctrlEstacion->modificar(est->Id, est->Tipo, est->CantidadPiezas - 1);
								ctrlTecho->modificar(et->Id, et->Material, et->Peso,
									EstadoPieza::ENSAMBLADA, et->PuntosUnion, et->Anchura, et->EstacionId);
							}
						}

						// Avanzar índice en la línea
						LineaEnsamblajeController^ ctrlLinea = gcnew LineaEnsamblajeController();
						PanelLateralController^ ctrlPanelAux = gcnew PanelLateralController();
						EstructuraTechoController^ ctrlTechoAux = gcnew EstructuraTechoController();
						ctrlLinea->cargarArchivo(ctrlPanelAux, ctrlTechoAux);
						LineaEnsamblajeModel^ linea = ctrlLinea->buscarPorId(lineaActual->Id);
						if (linea != nullptr)
						{
							int nuevoIndice = linea->IndiceActual + 1;
							bool sigueActiva = (nuevoIndice < lineaActual->ColaPiezas->Count);
							ctrlLinea->modificar(linea->Id, nuevoIndice, sigueActiva);
						}

					
						// Registrar evento automáticamente
						String^ eventoId = DateTime::Now.Ticks.ToString();
						String^ timestamp = DateTime::Now.ToString("yyyy-MM-dd HH:mm:ss");
						String^ descripcion = "Brazo coordinado — Tarea " + id + " completada automáticamente";
						ctrlEvento->agregar(eventoId, timestamp, descripcion, id, "COMPLETADA");

						ActualizarPanelLinea();
					}
				}

				// Deshabilitar botón si ya se completó
				TareaCoordinadaModel^ actualizado = ctrlCoordinada->buscarPorId(id);
				if (actualizado != nullptr && actualizado->TotalConfirmado >= actualizado->TotalRequerido)
					btnAccion1->Enabled = false;
				break;
			}
			}

			CargarGrid();
			ActualizarProgreso(id);
			MostrarDetalle(id);
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
			String^ resultadoD = "EN PROCESO"; // default
			// Obtener estado actual de la tarea para registrar en el evento
			switch (tabActivo)
			{
			case 0:
			{
				TareaPosicionarModel^ t = ctrlPosicionar->buscarPorId(id);
				if (t != nullptr) resultadoD = t->Estado;
				break;
			}
			case 1:
			{
				TareaSostenerModel^ t = ctrlSostener->buscarPorId(id);
				if (t != nullptr) resultadoD = t->Estado;
				break;
			}
			case 2:
			{
				TareaSoldarModel^ t = ctrlSoldar->buscarPorId(id);
				if (t != nullptr) resultadoD = t->Estado;
				break;
			}
			case 3:
			{
				TareaCoordinadaModel^ t = ctrlCoordinada->buscarPorId(id);
				if (t != nullptr) resultadoD = t->Estado;
				break;
			}
			}

			ctrlEvento->agregar(eventoId, timestamp, descripcion, id, resultadoD);

			MessageBox::Show("Evento registrado correctamente para la tarea #" + id + ".",
				"Evento registrado", MessageBoxButtons::OK, MessageBoxIcon::Information);
		}

	

		// ---------------------------------------------------------------
		// InitializeComponent
		// ---------------------------------------------------------------
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		void InitializeComponent(void)
		{
			System::Windows::Forms::DataGridViewCellStyle^ dataGridViewCellStyle1 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			this->btnTabPosicionar = (gcnew System::Windows::Forms::Button());
			this->btnTabSostener = (gcnew System::Windows::Forms::Button());
			this->btnTabSoldar = (gcnew System::Windows::Forms::Button());
			this->btnTabCoordinada = (gcnew System::Windows::Forms::Button());
			this->panelTabBar = (gcnew System::Windows::Forms::Panel());
			this->dataGridViewTareas = (gcnew System::Windows::Forms::DataGridView());
			this->labelSeccionProgreso = (gcnew System::Windows::Forms::Label());
			this->panelProgreso = (gcnew System::Windows::Forms::Panel());
			this->labelProgreso = (gcnew System::Windows::Forms::Label());
			this->progressBarTarea = (gcnew System::Windows::Forms::ProgressBar());
			this->btnAccion1 = (gcnew System::Windows::Forms::Button());
			this->btnRegistrarEvento = (gcnew System::Windows::Forms::Button());
			this->labelDetalleTitulo = (gcnew System::Windows::Forms::Label());
			this->panelDetalle = (gcnew System::Windows::Forms::Panel());
			this->labelDetalleC1Hdr = (gcnew System::Windows::Forms::Label());
			this->labelDetalleC2Hdr = (gcnew System::Windows::Forms::Label());
			this->labelDetalleC3Hdr = (gcnew System::Windows::Forms::Label());
			this->labelDetalleC4Hdr = (gcnew System::Windows::Forms::Label());
			this->labelDetalleC5Hdr = (gcnew System::Windows::Forms::Label());
			this->labelDetalleC1Val = (gcnew System::Windows::Forms::Label());
			this->labelDetalleC2Val = (gcnew System::Windows::Forms::Label());
			this->labelDetalleC3Val = (gcnew System::Windows::Forms::Label());
			this->labelDetalleC4Val = (gcnew System::Windows::Forms::Label());
			this->labelDetalleC5Val = (gcnew System::Windows::Forms::Label());
			this->labelTitulo = (gcnew System::Windows::Forms::Label());
			this->panelLineaActiva = (gcnew System::Windows::Forms::Panel());
			this->labelBrazoActual = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->labelProgresoCola = (gcnew System::Windows::Forms::Label());
			this->labelPiezaActual = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->labelLineaActiva = (gcnew System::Windows::Forms::Label());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->panelTabBar->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridViewTareas))->BeginInit();
			this->panelProgreso->SuspendLayout();
			this->panelDetalle->SuspendLayout();
			this->panelLineaActiva->SuspendLayout();
			this->SuspendLayout();
			// 
			// btnTabPosicionar
			// 
			this->btnTabPosicionar->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(28)), static_cast<System::Int32>(static_cast<System::Byte>(38)),
				static_cast<System::Int32>(static_cast<System::Byte>(54)));
			this->btnTabPosicionar->FlatAppearance->BorderSize = 0;
			this->btnTabPosicionar->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnTabPosicionar->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnTabPosicionar->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(160)),
				static_cast<System::Int32>(static_cast<System::Byte>(180)), static_cast<System::Int32>(static_cast<System::Byte>(210)));
			this->btnTabPosicionar->Location = System::Drawing::Point(-1, 1);
			this->btnTabPosicionar->Name = L"btnTabPosicionar";
			this->btnTabPosicionar->Size = System::Drawing::Size(284, 38);
			this->btnTabPosicionar->TabIndex = 0;
			this->btnTabPosicionar->Text = L"Posicionar";
			this->btnTabPosicionar->UseVisualStyleBackColor = false;
			this->btnTabPosicionar->Click += gcnew System::EventHandler(this, &FormMenuOperador::btnTabPosicionar_Click_1);
			// 
			// btnTabSostener
			// 
			this->btnTabSostener->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(28)), static_cast<System::Int32>(static_cast<System::Byte>(38)),
				static_cast<System::Int32>(static_cast<System::Byte>(54)));
			this->btnTabSostener->FlatAppearance->BorderSize = 0;
			this->btnTabSostener->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnTabSostener->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnTabSostener->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(160)), static_cast<System::Int32>(static_cast<System::Byte>(180)),
				static_cast<System::Int32>(static_cast<System::Byte>(210)));
			this->btnTabSostener->Location = System::Drawing::Point(284, 1);
			this->btnTabSostener->Name = L"btnTabSostener";
			this->btnTabSostener->Size = System::Drawing::Size(284, 38);
			this->btnTabSostener->TabIndex = 1;
			this->btnTabSostener->Text = L"Sostener";
			this->btnTabSostener->UseVisualStyleBackColor = false;
			this->btnTabSostener->Click += gcnew System::EventHandler(this, &FormMenuOperador::btnTabSostener_Click_1);
			// 
			// btnTabSoldar
			// 
			this->btnTabSoldar->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(28)), static_cast<System::Int32>(static_cast<System::Byte>(38)),
				static_cast<System::Int32>(static_cast<System::Byte>(54)));
			this->btnTabSoldar->FlatAppearance->BorderSize = 0;
			this->btnTabSoldar->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnTabSoldar->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnTabSoldar->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(160)), static_cast<System::Int32>(static_cast<System::Byte>(180)),
				static_cast<System::Int32>(static_cast<System::Byte>(210)));
			this->btnTabSoldar->Location = System::Drawing::Point(569, 1);
			this->btnTabSoldar->Name = L"btnTabSoldar";
			this->btnTabSoldar->Size = System::Drawing::Size(284, 38);
			this->btnTabSoldar->TabIndex = 2;
			this->btnTabSoldar->Text = L"Soldar";
			this->btnTabSoldar->UseVisualStyleBackColor = false;
			this->btnTabSoldar->Click += gcnew System::EventHandler(this, &FormMenuOperador::btnTabSoldar_Click_1);
			// 
			// btnTabCoordinada
			// 
			this->btnTabCoordinada->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(28)), static_cast<System::Int32>(static_cast<System::Byte>(38)),
				static_cast<System::Int32>(static_cast<System::Byte>(54)));
			this->btnTabCoordinada->FlatAppearance->BorderSize = 0;
			this->btnTabCoordinada->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btnTabCoordinada->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnTabCoordinada->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(160)),
				static_cast<System::Int32>(static_cast<System::Byte>(180)), static_cast<System::Int32>(static_cast<System::Byte>(210)));
			this->btnTabCoordinada->Location = System::Drawing::Point(854, 1);
			this->btnTabCoordinada->Name = L"btnTabCoordinada";
			this->btnTabCoordinada->Size = System::Drawing::Size(284, 38);
			this->btnTabCoordinada->TabIndex = 3;
			this->btnTabCoordinada->Text = L"Coordinada";
			this->btnTabCoordinada->UseVisualStyleBackColor = false;
			this->btnTabCoordinada->Click += gcnew System::EventHandler(this, &FormMenuOperador::btnTabCoordinada_Click_1);
			// 
			// panelTabBar
			// 
			this->panelTabBar->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(28)), static_cast<System::Int32>(static_cast<System::Byte>(38)),
				static_cast<System::Int32>(static_cast<System::Byte>(54)));
			this->panelTabBar->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->panelTabBar->Controls->Add(this->btnTabPosicionar);
			this->panelTabBar->Controls->Add(this->btnTabCoordinada);
			this->panelTabBar->Controls->Add(this->btnTabSoldar);
			this->panelTabBar->Controls->Add(this->btnTabSostener);
			this->panelTabBar->Location = System::Drawing::Point(21, 210);
			this->panelTabBar->Name = L"panelTabBar";
			this->panelTabBar->Size = System::Drawing::Size(1135, 40);
			this->panelTabBar->TabIndex = 1;
			this->panelTabBar->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &FormMenuOperador::panelTabBar_Paint);
			// 
			// dataGridViewTareas
			// 
			this->dataGridViewTareas->AllowUserToAddRows = false;
			this->dataGridViewTareas->AutoSizeColumnsMode = System::Windows::Forms::DataGridViewAutoSizeColumnsMode::Fill;
			this->dataGridViewTareas->BackgroundColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(28)),
				static_cast<System::Int32>(static_cast<System::Byte>(38)), static_cast<System::Int32>(static_cast<System::Byte>(54)));
			this->dataGridViewTareas->ColumnHeadersBorderStyle = System::Windows::Forms::DataGridViewHeaderBorderStyle::Single;
			this->dataGridViewTareas->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			dataGridViewCellStyle1->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleLeft;
			dataGridViewCellStyle1->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(28)), static_cast<System::Int32>(static_cast<System::Byte>(38)),
				static_cast<System::Int32>(static_cast<System::Byte>(54)));
			dataGridViewCellStyle1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			dataGridViewCellStyle1->ForeColor = System::Drawing::Color::White;
			dataGridViewCellStyle1->SelectionBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(50)),
				static_cast<System::Int32>(static_cast<System::Byte>(80)), static_cast<System::Int32>(static_cast<System::Byte>(120)));
			dataGridViewCellStyle1->SelectionForeColor = System::Drawing::Color::White;
			dataGridViewCellStyle1->WrapMode = System::Windows::Forms::DataGridViewTriState::False;
			this->dataGridViewTareas->DefaultCellStyle = dataGridViewCellStyle1;
			this->dataGridViewTareas->EnableHeadersVisualStyles = false;
			this->dataGridViewTareas->GridColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->dataGridViewTareas->Location = System::Drawing::Point(21, 256);
			this->dataGridViewTareas->MultiSelect = false;
			this->dataGridViewTareas->Name = L"dataGridViewTareas";
			this->dataGridViewTareas->ReadOnly = true;
			this->dataGridViewTareas->RowHeadersVisible = false;
			this->dataGridViewTareas->RowTemplate->Height = 28;
			this->dataGridViewTareas->SelectionMode = System::Windows::Forms::DataGridViewSelectionMode::FullRowSelect;
			this->dataGridViewTareas->Size = System::Drawing::Size(1140, 170);
			this->dataGridViewTareas->TabIndex = 2;
			this->dataGridViewTareas->SelectionChanged += gcnew System::EventHandler(this, &FormMenuOperador::dataGridViewTareas_SelectionChanged);
			// 
			// labelSeccionProgreso
			// 
			this->labelSeccionProgreso->AutoSize = true;
			this->labelSeccionProgreso->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->labelSeccionProgreso->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(230)),
				static_cast<System::Int32>(static_cast<System::Byte>(160)), static_cast<System::Int32>(static_cast<System::Byte>(0)));
			this->labelSeccionProgreso->Location = System::Drawing::Point(20, 433);
			this->labelSeccionProgreso->Name = L"labelSeccionProgreso";
			this->labelSeccionProgreso->Size = System::Drawing::Size(178, 15);
			this->labelSeccionProgreso->TabIndex = 3;
			this->labelSeccionProgreso->Text = L"Progreso — Tarea seleccionada";
			// 
			// panelProgreso
			// 
			this->panelProgreso->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(28)), static_cast<System::Int32>(static_cast<System::Byte>(38)),
				static_cast<System::Int32>(static_cast<System::Byte>(54)));
			this->panelProgreso->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->panelProgreso->Controls->Add(this->labelProgreso);
			this->panelProgreso->Controls->Add(this->progressBarTarea);
			this->panelProgreso->Location = System::Drawing::Point(20, 457);
			this->panelProgreso->Name = L"panelProgreso";
			this->panelProgreso->Size = System::Drawing::Size(900, 52);
			this->panelProgreso->TabIndex = 4;
			// 
			// labelProgreso
			// 
			this->labelProgreso->BackColor = System::Drawing::Color::Transparent;
			this->labelProgreso->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->labelProgreso->ForeColor = System::Drawing::Color::White;
			this->labelProgreso->Location = System::Drawing::Point(16, 14);
			this->labelProgreso->Name = L"labelProgreso";
			this->labelProgreso->Size = System::Drawing::Size(650, 22);
			this->labelProgreso->TabIndex = 1;
			this->labelProgreso->Text = L"—";
			this->labelProgreso->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			// 
			// progressBarTarea
			// 
			this->progressBarTarea->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(230)),
				static_cast<System::Int32>(static_cast<System::Byte>(160)), static_cast<System::Int32>(static_cast<System::Byte>(0)));
			this->progressBarTarea->Location = System::Drawing::Point(11, 8);
			this->progressBarTarea->Name = L"progressBarTarea";
			this->progressBarTarea->Size = System::Drawing::Size(660, 34);
			this->progressBarTarea->Style = System::Windows::Forms::ProgressBarStyle::Continuous;
			this->progressBarTarea->TabIndex = 0;
			// 
			// btnAccion1
			// 
			this->btnAccion1->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(230)), static_cast<System::Int32>(static_cast<System::Byte>(160)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			this->btnAccion1->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->btnAccion1->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnAccion1->ForeColor = System::Drawing::Color::Black;
			this->btnAccion1->Location = System::Drawing::Point(20, 523);
			this->btnAccion1->Name = L"btnAccion1";
			this->btnAccion1->Size = System::Drawing::Size(206, 37);
			this->btnAccion1->TabIndex = 5;
			this->btnAccion1->Text = L"+ Punto soldado";
			this->btnAccion1->UseVisualStyleBackColor = false;
			this->btnAccion1->Click += gcnew System::EventHandler(this, &FormMenuOperador::btnAccion1_Click);
			// 
			// btnRegistrarEvento
			// 
			this->btnRegistrarEvento->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(30)),
				static_cast<System::Int32>(static_cast<System::Byte>(58)), static_cast<System::Int32>(static_cast<System::Byte>(95)));
			this->btnRegistrarEvento->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->btnRegistrarEvento->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btnRegistrarEvento->ForeColor = System::Drawing::Color::White;
			this->btnRegistrarEvento->Location = System::Drawing::Point(452, 523);
			this->btnRegistrarEvento->Name = L"btnRegistrarEvento";
			this->btnRegistrarEvento->Size = System::Drawing::Size(206, 37);
			this->btnRegistrarEvento->TabIndex = 7;
			this->btnRegistrarEvento->Text = L"Registrar evento";
			this->btnRegistrarEvento->UseVisualStyleBackColor = false;
			this->btnRegistrarEvento->Click += gcnew System::EventHandler(this, &FormMenuOperador::btnRegistrarEvento_Click);
			// 
			// labelDetalleTitulo
			// 
			this->labelDetalleTitulo->AutoSize = true;
			this->labelDetalleTitulo->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->labelDetalleTitulo->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(230)),
				static_cast<System::Int32>(static_cast<System::Byte>(160)), static_cast<System::Int32>(static_cast<System::Byte>(0)));
			this->labelDetalleTitulo->Location = System::Drawing::Point(18, 569);
			this->labelDetalleTitulo->Name = L"labelDetalleTitulo";
			this->labelDetalleTitulo->Size = System::Drawing::Size(177, 15);
			this->labelDetalleTitulo->TabIndex = 8;
			this->labelDetalleTitulo->Text = L"Detalle — selecciona una tarea";
			// 
			// panelDetalle
			// 
			this->panelDetalle->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(20)), static_cast<System::Int32>(static_cast<System::Byte>(30)),
				static_cast<System::Int32>(static_cast<System::Byte>(46)));
			this->panelDetalle->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->panelDetalle->Controls->Add(this->labelDetalleC1Hdr);
			this->panelDetalle->Controls->Add(this->labelDetalleC2Hdr);
			this->panelDetalle->Controls->Add(this->labelDetalleC3Hdr);
			this->panelDetalle->Controls->Add(this->labelDetalleC4Hdr);
			this->panelDetalle->Controls->Add(this->labelDetalleC5Hdr);
			this->panelDetalle->Controls->Add(this->labelDetalleC1Val);
			this->panelDetalle->Controls->Add(this->labelDetalleC2Val);
			this->panelDetalle->Controls->Add(this->labelDetalleC3Val);
			this->panelDetalle->Controls->Add(this->labelDetalleC4Val);
			this->panelDetalle->Controls->Add(this->labelDetalleC5Val);
			this->panelDetalle->Location = System::Drawing::Point(18, 593);
			this->panelDetalle->Name = L"panelDetalle";
			this->panelDetalle->Size = System::Drawing::Size(1140, 80);
			this->panelDetalle->TabIndex = 9;
			// 
			// labelDetalleC1Hdr
			// 
			this->labelDetalleC1Hdr->AutoSize = true;
			this->labelDetalleC1Hdr->Font = (gcnew System::Drawing::Font(L"Segoe UI", 8, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->labelDetalleC1Hdr->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(160)),
				static_cast<System::Int32>(static_cast<System::Byte>(180)), static_cast<System::Int32>(static_cast<System::Byte>(210)));
			this->labelDetalleC1Hdr->Location = System::Drawing::Point(10, 10);
			this->labelDetalleC1Hdr->Name = L"labelDetalleC1Hdr";
			this->labelDetalleC1Hdr->Size = System::Drawing::Size(18, 13);
			this->labelDetalleC1Hdr->TabIndex = 0;
			this->labelDetalleC1Hdr->Text = L"ID";
			// 
			// labelDetalleC2Hdr
			// 
			this->labelDetalleC2Hdr->AutoSize = true;
			this->labelDetalleC2Hdr->Font = (gcnew System::Drawing::Font(L"Segoe UI", 8, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->labelDetalleC2Hdr->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(160)),
				static_cast<System::Int32>(static_cast<System::Byte>(180)), static_cast<System::Int32>(static_cast<System::Byte>(210)));
			this->labelDetalleC2Hdr->Location = System::Drawing::Point(230, 10);
			this->labelDetalleC2Hdr->Name = L"labelDetalleC2Hdr";
			this->labelDetalleC2Hdr->Size = System::Drawing::Size(42, 13);
			this->labelDetalleC2Hdr->TabIndex = 1;
			this->labelDetalleC2Hdr->Text = L"Estado";
			// 
			// labelDetalleC3Hdr
			// 
			this->labelDetalleC3Hdr->AutoSize = true;
			this->labelDetalleC3Hdr->Font = (gcnew System::Drawing::Font(L"Segoe UI", 8, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->labelDetalleC3Hdr->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(160)),
				static_cast<System::Int32>(static_cast<System::Byte>(180)), static_cast<System::Int32>(static_cast<System::Byte>(210)));
			this->labelDetalleC3Hdr->Location = System::Drawing::Point(450, 10);
			this->labelDetalleC3Hdr->Name = L"labelDetalleC3Hdr";
			this->labelDetalleC3Hdr->Size = System::Drawing::Size(18, 13);
			this->labelDetalleC3Hdr->TabIndex = 2;
			this->labelDetalleC3Hdr->Text = L"—";
			// 
			// labelDetalleC4Hdr
			// 
			this->labelDetalleC4Hdr->AutoSize = true;
			this->labelDetalleC4Hdr->Font = (gcnew System::Drawing::Font(L"Segoe UI", 8, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->labelDetalleC4Hdr->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(160)),
				static_cast<System::Int32>(static_cast<System::Byte>(180)), static_cast<System::Int32>(static_cast<System::Byte>(210)));
			this->labelDetalleC4Hdr->Location = System::Drawing::Point(670, 10);
			this->labelDetalleC4Hdr->Name = L"labelDetalleC4Hdr";
			this->labelDetalleC4Hdr->Size = System::Drawing::Size(18, 13);
			this->labelDetalleC4Hdr->TabIndex = 3;
			this->labelDetalleC4Hdr->Text = L"—";
			// 
			// labelDetalleC5Hdr
			// 
			this->labelDetalleC5Hdr->AutoSize = true;
			this->labelDetalleC5Hdr->Font = (gcnew System::Drawing::Font(L"Segoe UI", 8, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->labelDetalleC5Hdr->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(160)),
				static_cast<System::Int32>(static_cast<System::Byte>(180)), static_cast<System::Int32>(static_cast<System::Byte>(210)));
			this->labelDetalleC5Hdr->Location = System::Drawing::Point(890, 10);
			this->labelDetalleC5Hdr->Name = L"labelDetalleC5Hdr";
			this->labelDetalleC5Hdr->Size = System::Drawing::Size(18, 13);
			this->labelDetalleC5Hdr->TabIndex = 4;
			this->labelDetalleC5Hdr->Text = L"—";
			// 
			// labelDetalleC1Val
			// 
			this->labelDetalleC1Val->AutoSize = true;
			this->labelDetalleC1Val->Font = (gcnew System::Drawing::Font(L"Segoe UI", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->labelDetalleC1Val->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(230)),
				static_cast<System::Int32>(static_cast<System::Byte>(160)), static_cast<System::Int32>(static_cast<System::Byte>(0)));
			this->labelDetalleC1Val->Location = System::Drawing::Point(10, 34);
			this->labelDetalleC1Val->Name = L"labelDetalleC1Val";
			this->labelDetalleC1Val->Size = System::Drawing::Size(26, 21);
			this->labelDetalleC1Val->TabIndex = 5;
			this->labelDetalleC1Val->Text = L"—";
			// 
			// labelDetalleC2Val
			// 
			this->labelDetalleC2Val->AutoSize = true;
			this->labelDetalleC2Val->Font = (gcnew System::Drawing::Font(L"Segoe UI", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->labelDetalleC2Val->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(230)),
				static_cast<System::Int32>(static_cast<System::Byte>(160)), static_cast<System::Int32>(static_cast<System::Byte>(0)));
			this->labelDetalleC2Val->Location = System::Drawing::Point(230, 34);
			this->labelDetalleC2Val->Name = L"labelDetalleC2Val";
			this->labelDetalleC2Val->Size = System::Drawing::Size(26, 21);
			this->labelDetalleC2Val->TabIndex = 6;
			this->labelDetalleC2Val->Text = L"—";
			// 
			// labelDetalleC3Val
			// 
			this->labelDetalleC3Val->AutoSize = true;
			this->labelDetalleC3Val->Font = (gcnew System::Drawing::Font(L"Segoe UI", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->labelDetalleC3Val->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(230)),
				static_cast<System::Int32>(static_cast<System::Byte>(160)), static_cast<System::Int32>(static_cast<System::Byte>(0)));
			this->labelDetalleC3Val->Location = System::Drawing::Point(450, 34);
			this->labelDetalleC3Val->Name = L"labelDetalleC3Val";
			this->labelDetalleC3Val->Size = System::Drawing::Size(26, 21);
			this->labelDetalleC3Val->TabIndex = 7;
			this->labelDetalleC3Val->Text = L"—";
			// 
			// labelDetalleC4Val
			// 
			this->labelDetalleC4Val->AutoSize = true;
			this->labelDetalleC4Val->Font = (gcnew System::Drawing::Font(L"Segoe UI", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->labelDetalleC4Val->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(230)),
				static_cast<System::Int32>(static_cast<System::Byte>(160)), static_cast<System::Int32>(static_cast<System::Byte>(0)));
			this->labelDetalleC4Val->Location = System::Drawing::Point(670, 34);
			this->labelDetalleC4Val->Name = L"labelDetalleC4Val";
			this->labelDetalleC4Val->Size = System::Drawing::Size(26, 21);
			this->labelDetalleC4Val->TabIndex = 8;
			this->labelDetalleC4Val->Text = L"—";
			// 
			// labelDetalleC5Val
			// 
			this->labelDetalleC5Val->AutoSize = true;
			this->labelDetalleC5Val->Font = (gcnew System::Drawing::Font(L"Segoe UI", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->labelDetalleC5Val->ForeColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(230)),
				static_cast<System::Int32>(static_cast<System::Byte>(160)), static_cast<System::Int32>(static_cast<System::Byte>(0)));
			this->labelDetalleC5Val->Location = System::Drawing::Point(890, 34);
			this->labelDetalleC5Val->Name = L"labelDetalleC5Val";
			this->labelDetalleC5Val->Size = System::Drawing::Size(26, 21);
			this->labelDetalleC5Val->TabIndex = 9;
			this->labelDetalleC5Val->Text = L"—";
			// 
			// labelTitulo
			// 
			this->labelTitulo->AutoSize = true;
			this->labelTitulo->Font = (gcnew System::Drawing::Font(L"Segoe UI", 14, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->labelTitulo->ForeColor = System::Drawing::Color::White;
			this->labelTitulo->Location = System::Drawing::Point(20, 16);
			this->labelTitulo->Name = L"labelTitulo";
			this->labelTitulo->Size = System::Drawing::Size(300, 25);
			this->labelTitulo->TabIndex = 0;
			this->labelTitulo->Text = L"Gestión de Tareas — Ciclo Activo";
			// 
			// panelLineaActiva
			// 
			this->panelLineaActiva->Controls->Add(this->labelBrazoActual);
			this->panelLineaActiva->Controls->Add(this->label4);
			this->panelLineaActiva->Controls->Add(this->label3);
			this->panelLineaActiva->Controls->Add(this->labelProgresoCola);
			this->panelLineaActiva->Controls->Add(this->labelPiezaActual);
			this->panelLineaActiva->Controls->Add(this->label2);
			this->panelLineaActiva->Controls->Add(this->labelLineaActiva);
			this->panelLineaActiva->Controls->Add(this->label1);
			this->panelLineaActiva->Location = System::Drawing::Point(23, 56);
			this->panelLineaActiva->Name = L"panelLineaActiva";
			this->panelLineaActiva->Size = System::Drawing::Size(1138, 88);
			this->panelLineaActiva->TabIndex = 10;
			// 
			// labelBrazoActual
			// 
			this->labelBrazoActual->AutoSize = true;
			this->labelBrazoActual->ForeColor = System::Drawing::Color::White;
			this->labelBrazoActual->Location = System::Drawing::Point(591, 49);
			this->labelBrazoActual->Name = L"labelBrazoActual";
			this->labelBrazoActual->Size = System::Drawing::Size(0, 13);
			this->labelBrazoActual->TabIndex = 7;
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->ForeColor = System::Drawing::Color::White;
			this->label4->Location = System::Drawing::Point(591, 10);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(37, 13);
			this->label4->TabIndex = 6;
			this->label4->Text = L"Brazo:";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->ForeColor = System::Drawing::Color::White;
			this->label3->Location = System::Drawing::Point(350, 10);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(79, 13);
			this->label3->TabIndex = 5;
			this->label3->Text = L"Progreso Cola: ";
			// 
			// labelProgresoCola
			// 
			this->labelProgresoCola->AutoSize = true;
			this->labelProgresoCola->ForeColor = System::Drawing::Color::White;
			this->labelProgresoCola->Location = System::Drawing::Point(350, 49);
			this->labelProgresoCola->Name = L"labelProgresoCola";
			this->labelProgresoCola->Size = System::Drawing::Size(0, 13);
			this->labelProgresoCola->TabIndex = 4;
			// 
			// labelPiezaActual
			// 
			this->labelPiezaActual->AutoSize = true;
			this->labelPiezaActual->ForeColor = System::Drawing::Color::White;
			this->labelPiezaActual->Location = System::Drawing::Point(113, 49);
			this->labelPiezaActual->Name = L"labelPiezaActual";
			this->labelPiezaActual->Size = System::Drawing::Size(0, 13);
			this->labelPiezaActual->TabIndex = 3;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->ForeColor = System::Drawing::Color::White;
			this->label2->Location = System::Drawing::Point(113, 10);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(71, 13);
			this->label2->TabIndex = 2;
			this->label2->Text = L"Pieza actual: ";
			// 
			// labelLineaActiva
			// 
			this->labelLineaActiva->AutoSize = true;
			this->labelLineaActiva->ForeColor = System::Drawing::Color::White;
			this->labelLineaActiva->Location = System::Drawing::Point(13, 49);
			this->labelLineaActiva->Name = L"labelLineaActiva";
			this->labelLineaActiva->Size = System::Drawing::Size(0, 13);
			this->labelLineaActiva->TabIndex = 1;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->ForeColor = System::Drawing::Color::White;
			this->label1->Location = System::Drawing::Point(13, 10);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(71, 13);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Linea activa: ";
			// 
			// FormMenuOperador
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(18)), static_cast<System::Int32>(static_cast<System::Byte>(26)),
				static_cast<System::Int32>(static_cast<System::Byte>(38)));
			this->ClientSize = System::Drawing::Size(1229, 681);
			this->Controls->Add(this->panelLineaActiva);
			this->Controls->Add(this->labelTitulo);
			this->Controls->Add(this->panelTabBar);
			this->Controls->Add(this->dataGridViewTareas);
			this->Controls->Add(this->labelSeccionProgreso);
			this->Controls->Add(this->panelProgreso);
			this->Controls->Add(this->btnAccion1);
			this->Controls->Add(this->btnRegistrarEvento);
			this->Controls->Add(this->labelDetalleTitulo);
			this->Controls->Add(this->panelDetalle);
			this->Name = L"FormMenuOperador";
			this->Text = L"FormMenuOperador";
			this->Load += gcnew System::EventHandler(this, &FormMenuOperador::FormMenuOperador_Load);
			this->panelTabBar->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridViewTareas))->EndInit();
			this->panelProgreso->ResumeLayout(false);
			this->panelDetalle->ResumeLayout(false);
			this->panelDetalle->PerformLayout();
			this->panelLineaActiva->ResumeLayout(false);
			this->panelLineaActiva->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
		// Carga datos de la línea activa en el panel superior
		void ActualizarPanelLinea()
		{
			lineaActual = nullptr;
			brazoActual = nullptr;

			LineaEnsamblajeController^ ctrlLinea = gcnew LineaEnsamblajeController();
			PanelLateralController^ ctrlPanel = gcnew PanelLateralController();
			EstructuraTechoController^ ctrlTecho = gcnew EstructuraTechoController();
			ctrlLinea->cargarArchivo(ctrlPanel, ctrlTecho);

			for each(LineaEnsamblajeModel ^ l in ctrlLinea->obtenerTodos())
				if (l->SecuenciaAprobada) { lineaActual = l; break; }

			if (lineaActual == nullptr) {
				labelLineaActiva->Text = "Sin línea aprobada";
				labelPiezaActual->Text = "—";
				labelProgresoCola->Text = "0 / 0 piezas";
				labelBrazoActual->Text = "—";
				btnAccion1->Enabled = false;
				btnRegistrarEvento->Enabled = false;
				return;
			}

			btnAccion1->Enabled = true;
			
			btnRegistrarEvento->Enabled = true;

			labelLineaActiva->Text = lineaActual->Id;

			int total = lineaActual->ColaPiezas->Count;
			int indice = lineaActual->IndiceActual;
			labelProgresoCola->Text = indice.ToString() + " / " + total.ToString() + " piezas";

			if (indice < total) {
				PiezaModel^ pieza = lineaActual->ColaPiezas[indice];
				PanelLateralModel^ pl = dynamic_cast<PanelLateralModel^>(pieza);
				if (pl != nullptr) {
					if (pl->Lado == LadoPanel::IZQUIERDO) {
						brazoActual = "LATERAL_IZQ";
						labelPiezaActual->Text = pieza->Id + " — Panel IZQ";
					}
					else {
						brazoActual = "LATERAL_DER";
						labelPiezaActual->Text = pieza->Id + " — Panel DER";
					}
				}
				else {
					brazoActual = "CENTRAL_SUP";
					labelPiezaActual->Text = pieza->Id + " — Estructura Techo";
				}
				labelBrazoActual->Text = brazoActual;
			}
			else {
				labelPiezaActual->Text = "Todas las piezas completadas";
				labelBrazoActual->Text = "—";
				brazoActual = nullptr;
				btnAccion1->Enabled = false;
				
				btnRegistrarEvento->Enabled = false;
			}
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
	private: System::Void btnTabPosicionar_Click_1(System::Object^ sender, System::EventArgs^ e) {

		CambiarTab(0);
	}
private: System::Void btnTabSostener_Click_1(System::Object^ sender, System::EventArgs^ e) {
		CambiarTab(1);
}
private: System::Void btnTabCoordinada_Click_1(System::Object^ sender, System::EventArgs^ e) {

	CambiarTab(3);
}
private: System::Void panelTabBar_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
	}
private: System::Void btnTabSoldar_Click_1(System::Object^ sender, System::EventArgs^ e) {

	CambiarTab(2);

}
};
}
