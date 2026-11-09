#pragma once
#include "Logica.h"
#include "TemaVisual.h"

namespace MateComputacional {

    using namespace System;
    using namespace System::ComponentModel;
    using namespace System::Collections;
    using namespace System::Windows::Forms;
    using namespace System::Data;
    using namespace System::Drawing;

    /// <summary>
    /// Pantalla 2: editor de grafo (agregar / eliminar aristas y validar ciclos).
    /// </summary>
    public ref class EditorGrafoForm : public System::Windows::Forms::Form
    {
    public:
        EditorGrafoForm(void) { InitializeComponent(); if (System::ComponentModel::LicenseManager::UsageMode != System::ComponentModel::LicenseUsageMode::Designtime) TemaVisual::aplicar(this, 2, "Editor del grafo"); }

    protected:
        ~EditorGrafoForm() { if (components) delete components; }

    private:
        System::ComponentModel::Container ^components;
        System::Windows::Forms::GroupBox^ gbAgregar;
        System::Windows::Forms::Label^ lblOrigen;
        System::Windows::Forms::ComboBox^ cbOrigen;
        System::Windows::Forms::Label^ lblDestino;
        System::Windows::Forms::ComboBox^ cbDestino;
        System::Windows::Forms::Label^ lblCapacidad;
        System::Windows::Forms::NumericUpDown^ numCapacidad;
        System::Windows::Forms::Button^ btnAgregar;
        System::Windows::Forms::GroupBox^ gbLista;
        System::Windows::Forms::ListBox^ lstAristas;
        System::Windows::Forms::Button^ btnEliminar;
        System::Windows::Forms::Button^ btnValidar;
        System::Windows::Forms::Label^ lblEstado;
        System::Windows::Forms::Panel^ panelGrafo;
        System::Windows::Forms::Button^ btnVolver;
        System::Windows::Forms::Button^ btnContinuar;

#pragma region Windows Form Designer generated code
        void InitializeComponent(void)
        {
            this->gbAgregar = (gcnew System::Windows::Forms::GroupBox());
            this->lblOrigen = (gcnew System::Windows::Forms::Label());
            this->cbOrigen = (gcnew System::Windows::Forms::ComboBox());
            this->lblDestino = (gcnew System::Windows::Forms::Label());
            this->cbDestino = (gcnew System::Windows::Forms::ComboBox());
            this->lblCapacidad = (gcnew System::Windows::Forms::Label());
            this->numCapacidad = (gcnew System::Windows::Forms::NumericUpDown());
            this->btnAgregar = (gcnew System::Windows::Forms::Button());
            this->gbLista = (gcnew System::Windows::Forms::GroupBox());
            this->lstAristas = (gcnew System::Windows::Forms::ListBox());
            this->btnEliminar = (gcnew System::Windows::Forms::Button());
            this->btnValidar = (gcnew System::Windows::Forms::Button());
            this->lblEstado = (gcnew System::Windows::Forms::Label());
            this->panelGrafo = (gcnew System::Windows::Forms::Panel());
            this->btnVolver = (gcnew System::Windows::Forms::Button());
            this->btnContinuar = (gcnew System::Windows::Forms::Button());
            this->components = (gcnew System::ComponentModel::Container());
            this->gbAgregar->SuspendLayout();
            this->gbLista->SuspendLayout();
            (safe_cast<System::ComponentModel::ISupportInitialize^>(this->numCapacidad))->BeginInit();
            this->SuspendLayout();
            // 
            // gbAgregar
            // 
            this->gbAgregar->Controls->Add(this->lblOrigen);
            this->gbAgregar->Controls->Add(this->cbOrigen);
            this->gbAgregar->Controls->Add(this->lblDestino);
            this->gbAgregar->Controls->Add(this->cbDestino);
            this->gbAgregar->Controls->Add(this->lblCapacidad);
            this->gbAgregar->Controls->Add(this->numCapacidad);
            this->gbAgregar->Controls->Add(this->btnAgregar);
            this->gbAgregar->Location = System::Drawing::Point(15, 15);
            this->gbAgregar->Name = L"gbAgregar";
            this->gbAgregar->Size = System::Drawing::Size(360, 140);
            this->gbAgregar->TabIndex = 0;
            this->gbAgregar->TabStop = false;
            this->gbAgregar->Text = L"Agregar arista";
            // 
            // lblOrigen
            // 
            this->lblOrigen->Location = System::Drawing::Point(15, 30);
            this->lblOrigen->Name = L"lblOrigen";
            this->lblOrigen->Size = System::Drawing::Size(60, 23);
            this->lblOrigen->TabIndex = 0;
            this->lblOrigen->Text = L"Origen:";
            // 
            // cbOrigen
            // 
            this->cbOrigen->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
            this->cbOrigen->Location = System::Drawing::Point(80, 28);
            this->cbOrigen->Name = L"cbOrigen";
            this->cbOrigen->Size = System::Drawing::Size(90, 21);
            this->cbOrigen->TabIndex = 1;
            // 
            // lblDestino
            // 
            this->lblDestino->Location = System::Drawing::Point(185, 30);
            this->lblDestino->Name = L"lblDestino";
            this->lblDestino->Size = System::Drawing::Size(60, 23);
            this->lblDestino->TabIndex = 2;
            this->lblDestino->Text = L"Destino:";
            // 
            // cbDestino
            // 
            this->cbDestino->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
            this->cbDestino->Location = System::Drawing::Point(250, 28);
            this->cbDestino->Name = L"cbDestino";
            this->cbDestino->Size = System::Drawing::Size(90, 21);
            this->cbDestino->TabIndex = 3;
            // 
            // lblCapacidad
            // 
            this->lblCapacidad->Location = System::Drawing::Point(15, 70);
            this->lblCapacidad->Name = L"lblCapacidad";
            this->lblCapacidad->Size = System::Drawing::Size(70, 23);
            this->lblCapacidad->TabIndex = 4;
            this->lblCapacidad->Text = L"Capacidad:";
            // 
            // numCapacidad
            // 
            this->numCapacidad->Location = System::Drawing::Point(90, 68);
            this->numCapacidad->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4){ 999999, 0, 0, 0 });
            this->numCapacidad->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4){ 1, 0, 0, 0 });
            this->numCapacidad->Name = L"numCapacidad";
            this->numCapacidad->Size = System::Drawing::Size(80, 20);
            this->numCapacidad->TabIndex = 5;
            this->numCapacidad->Value = System::Decimal(gcnew cli::array< System::Int32 >(4){ 5, 0, 0, 0 });
            // 
            // btnAgregar
            // 
            this->btnAgregar->BackColor = System::Drawing::Color::FromArgb(40, 140, 80);
            this->btnAgregar->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
            this->btnAgregar->ForeColor = System::Drawing::Color::White;
            this->btnAgregar->Location = System::Drawing::Point(200, 65);
            this->btnAgregar->Name = L"btnAgregar";
            this->btnAgregar->Size = System::Drawing::Size(130, 30);
            this->btnAgregar->TabIndex = 6;
            this->btnAgregar->Text = L"Agregar arista";
            this->btnAgregar->UseVisualStyleBackColor = false;
            this->btnAgregar->Click += gcnew System::EventHandler(this, &EditorGrafoForm::btnAgregar_Click);
            // 
            // gbLista
            // 
            this->gbLista->Controls->Add(this->lstAristas);
            this->gbLista->Controls->Add(this->btnEliminar);
            this->gbLista->Location = System::Drawing::Point(15, 165);
            this->gbLista->Name = L"gbLista";
            this->gbLista->Size = System::Drawing::Size(360, 260);
            this->gbLista->TabIndex = 1;
            this->gbLista->TabStop = false;
            this->gbLista->Text = L"Aristas actuales";
            // 
            // lstAristas
            // 
            this->lstAristas->Font = (gcnew System::Drawing::Font(L"Consolas", 9));
            this->lstAristas->FormattingEnabled = true;
            this->lstAristas->Location = System::Drawing::Point(15, 25);
            this->lstAristas->Name = L"lstAristas";
            this->lstAristas->Size = System::Drawing::Size(330, 199);
            this->lstAristas->TabIndex = 0;
            // 
            // btnEliminar
            // 
            this->btnEliminar->Location = System::Drawing::Point(15, 228);
            this->btnEliminar->Name = L"btnEliminar";
            this->btnEliminar->Size = System::Drawing::Size(150, 25);
            this->btnEliminar->TabIndex = 1;
            this->btnEliminar->Text = L"Eliminar seleccionada";
            this->btnEliminar->UseVisualStyleBackColor = true;
            this->btnEliminar->Click += gcnew System::EventHandler(this, &EditorGrafoForm::btnEliminar_Click);
            // 
            // btnValidar
            // 
            this->btnValidar->BackColor = System::Drawing::Color::FromArgb(200, 120, 30);
            this->btnValidar->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
            this->btnValidar->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9, System::Drawing::FontStyle::Bold));
            this->btnValidar->ForeColor = System::Drawing::Color::White;
            this->btnValidar->Location = System::Drawing::Point(15, 432);
            this->btnValidar->Name = L"btnValidar";
            this->btnValidar->Size = System::Drawing::Size(360, 32);
            this->btnValidar->TabIndex = 2;
            this->btnValidar->Text = L"Validar grafo";
            this->btnValidar->UseVisualStyleBackColor = false;
            this->btnValidar->Click += gcnew System::EventHandler(this, &EditorGrafoForm::btnValidar_Click);
            // 
            // lblEstado
            // 
            this->lblEstado->ForeColor = System::Drawing::Color::DarkRed;
            this->lblEstado->Location = System::Drawing::Point(15, 470);
            this->lblEstado->Name = L"lblEstado";
            this->lblEstado->Size = System::Drawing::Size(360, 40);
            this->lblEstado->TabIndex = 3;
            // 
            // panelGrafo
            // 
            this->panelGrafo->BackColor = System::Drawing::Color::White;
            this->panelGrafo->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
            this->panelGrafo->Location = System::Drawing::Point(390, 15);
            this->panelGrafo->Name = L"panelGrafo";
            this->panelGrafo->Size = System::Drawing::Size(620, 520);
            this->panelGrafo->TabIndex = 4;
            this->panelGrafo->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &EditorGrafoForm::panelGrafo_Paint);
            // 
            // btnVolver
            // 
            this->btnVolver->Location = System::Drawing::Point(390, 545);
            this->btnVolver->Name = L"btnVolver";
            this->btnVolver->Size = System::Drawing::Size(120, 32);
            this->btnVolver->TabIndex = 5;
            this->btnVolver->Text = L"Volver";
            this->btnVolver->UseVisualStyleBackColor = true;
            this->btnVolver->Click += gcnew System::EventHandler(this, &EditorGrafoForm::btnVolver_Click);
            // 
            // btnContinuar
            // 
            this->btnContinuar->BackColor = System::Drawing::Color::FromArgb(30, 100, 180);
            this->btnContinuar->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
            this->btnContinuar->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9, System::Drawing::FontStyle::Bold));
            this->btnContinuar->ForeColor = System::Drawing::Color::White;
            this->btnContinuar->Location = System::Drawing::Point(830, 545);
            this->btnContinuar->Name = L"btnContinuar";
            this->btnContinuar->Size = System::Drawing::Size(180, 32);
            this->btnContinuar->TabIndex = 6;
            this->btnContinuar->Text = L"Continuar";
            this->btnContinuar->UseVisualStyleBackColor = false;
            this->btnContinuar->Click += gcnew System::EventHandler(this, &EditorGrafoForm::btnContinuar_Click);
            // 
            // EditorGrafoForm
            // 
            this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
            this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
            this->BackColor = System::Drawing::Color::FromArgb(245, 245, 245);
            this->ClientSize = System::Drawing::Size(1030, 595);
            this->Controls->Add(this->gbAgregar);
            this->Controls->Add(this->gbLista);
            this->Controls->Add(this->btnValidar);
            this->Controls->Add(this->lblEstado);
            this->Controls->Add(this->panelGrafo);
            this->Controls->Add(this->btnVolver);
            this->Controls->Add(this->btnContinuar);
            this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
            this->MaximizeBox = false;
            this->Name = L"EditorGrafoForm";
            this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
            this->Text = L"Flujo Maximo - Editor de grafo";
            this->Load += gcnew System::EventHandler(this, &EditorGrafoForm::EditorGrafoForm_Load);
            this->gbAgregar->ResumeLayout(false);
            this->gbLista->ResumeLayout(false);
            (safe_cast<System::ComponentModel::ISupportInitialize^>(this->numCapacidad))->EndInit();
            this->ResumeLayout(false);
        }
#pragma endregion

    private:
        System::Void EditorGrafoForm_Load(System::Object^ sender, System::EventArgs^ e)
        {
            Grafo^ g = EstadoGlobal::estado->grafo;
            cbOrigen->Items->Clear();
            cbDestino->Items->Clear();
            if (g != nullptr) {
                for each (Vertice^ v in g->getVertices()) { cbOrigen->Items->Add(v); cbDestino->Items->Add(v); }
            }
            if (cbOrigen->Items->Count > 0) cbOrigen->SelectedIndex = 0;
            if (cbDestino->Items->Count > 1) cbDestino->SelectedIndex = 1;
            lstAristas->Items->Clear();
            if (g != nullptr) {
                for each (Arista^ a in g->getAristas())
                    lstAristas->Items->Add(a->getOrigen()->getNombre() + " -> " + a->getDestino()->getNombre() + "   cap=" + a->getCapacidad());
            }
            lblEstado->Text = "";
            if (g != nullptr) EstadoGlobal::estado->grafoVisual->calcularPosiciones(g, panelGrafo->Width, panelGrafo->Height);
            panelGrafo->Invalidate();
        }

        System::Void btnAgregar_Click(System::Object^ sender, System::EventArgs^ e)
        {
            Grafo^ g = EstadoGlobal::estado->grafo;
            if (g == nullptr) return;
            if (cbOrigen->SelectedItem == nullptr || cbDestino->SelectedItem == nullptr) {
                lblEstado->ForeColor = System::Drawing::Color::Red;
                lblEstado->Text = "Seleccione origen y destino.";
                return;
            }
            Vertice^ o = (Vertice^)cbOrigen->SelectedItem;
            Vertice^ d = (Vertice^)cbDestino->SelectedItem;
            if (o->getId() == d->getId()) { lblEstado->ForeColor = System::Drawing::Color::Red; lblEstado->Text = "Origen y destino no pueden ser iguales."; return; }
            if (g->existeArista(o->getId(), d->getId())) { lblEstado->ForeColor = System::Drawing::Color::Red; lblEstado->Text = "Ya existe esa arista dirigida."; return; }
            int cap = (int)numCapacidad->Value;
            if (cap <= 0) { lblEstado->ForeColor = System::Drawing::Color::Red; lblEstado->Text = "La capacidad debe ser > 0."; return; }
            try {
                g->agregarArista(o->getId(), d->getId(), cap);
                lstAristas->Items->Add(o->getNombre() + " -> " + d->getNombre() + "   cap=" + cap);
                EstadoGlobal::estado->grafoValidado = false;
                lblEstado->ForeColor = System::Drawing::Color::DarkOrange;
                lblEstado->Text = "Cambios pendientes de validar.";
                panelGrafo->Invalidate();
            }
            catch (Exception^ ex) {
                lblEstado->ForeColor = System::Drawing::Color::Red;
                lblEstado->Text = ex->Message;
            }
        }

        System::Void btnEliminar_Click(System::Object^ sender, System::EventArgs^ e)
        {
            Grafo^ g = EstadoGlobal::estado->grafo;
            if (g == nullptr || lstAristas->SelectedIndex < 0) return;
            int idx = lstAristas->SelectedIndex;
            if (idx < g->getAristas()->Count) {
                g->eliminarArista(g->getAristas()[idx]->getId());
                lstAristas->Items->RemoveAt(idx);
                EstadoGlobal::estado->grafoValidado = false;
                lblEstado->ForeColor = System::Drawing::Color::DarkOrange;
                lblEstado->Text = "Cambios pendientes de validar.";
                panelGrafo->Invalidate();
            }
        }

        System::Void btnValidar_Click(System::Object^ sender, System::EventArgs^ e)
        {
            Grafo^ g = EstadoGlobal::estado->grafo;
            if (g == nullptr) return;
            ValidadorGrafo^ val = gcnew ValidadorGrafo();
            List<int>^ ciclo = val->obtenerCiclo(g);
            if (ciclo != nullptr) {
                EstadoGlobal::estado->grafoValidado = false;
                lblEstado->ForeColor = System::Drawing::Color::Red;
                lblEstado->Text = "Ciclo detectado:\n" + val->obtenerCicloTexto(g);
                MessageBox::Show("Se detecto un ciclo:\n" + val->obtenerCicloTexto(g) + "\n\nCorrija el grafo antes de continuar.", "Grafo invalido", MessageBoxButtons::OK, MessageBoxIcon::Error);
            }
            else {
                EstadoGlobal::estado->grafoValidado = true;
                lblEstado->ForeColor = System::Drawing::Color::FromArgb(30, 120, 60);
                lblEstado->Text = "Grafo validado.";
            }
        }

        System::Void btnVolver_Click(System::Object^ sender, System::EventArgs^ e)
        {
            this->DialogResult = System::Windows::Forms::DialogResult::Cancel;
        }

        System::Void btnContinuar_Click(System::Object^ sender, System::EventArgs^ e)
        {
            if (!EstadoGlobal::estado->grafoValidado) {
                MessageBox::Show("Debe validar el grafo (sin ciclos) antes de continuar.", "Validacion requerida", MessageBoxButtons::OK, MessageBoxIcon::Warning);
                return;
            }
            this->DialogResult = System::Windows::Forms::DialogResult::OK;
        }

        System::Void panelGrafo_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e)
        {
            Grafo^ g = EstadoGlobal::estado->grafo;
            if (g == nullptr) return;
            for each (Arista^ a in g->getAristas()) a->setFlujo(0);
            EstadoGlobal::estado->grafoVisual->dibujar(e->Graphics, g);
        }
    };

}
