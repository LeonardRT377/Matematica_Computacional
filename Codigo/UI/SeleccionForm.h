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
    /// Pantalla 3: seleccion de fuente y sumidero (simple o multiples).
    /// </summary>
    public ref class SeleccionForm : public System::Windows::Forms::Form
    {
    public:
        SeleccionForm(void) { InitializeComponent(); if (System::ComponentModel::LicenseManager::UsageMode != System::ComponentModel::LicenseUsageMode::Designtime) TemaVisual::aplicar(this, 3, "Fuente y sumidero"); }

    protected:
        ~SeleccionForm() { if (components) delete components; }

    private:
        System::ComponentModel::Container ^components;
        System::Windows::Forms::GroupBox^ gbSimple;
        System::Windows::Forms::Label^ lblFuente;
        System::Windows::Forms::ComboBox^ cbFuente;
        System::Windows::Forms::Label^ lblSumidero;
        System::Windows::Forms::ComboBox^ cbSumidero;
        System::Windows::Forms::GroupBox^ gbMulti;
        System::Windows::Forms::CheckBox^ chkMultiFuente;
        System::Windows::Forms::ListBox^ lstFuentes;
        System::Windows::Forms::CheckBox^ chkMultiSumidero;
        System::Windows::Forms::ListBox^ lstSumideros;
        System::Windows::Forms::Label^ lblEstado;
        System::Windows::Forms::Panel^ panelGrafo;
        System::Windows::Forms::Button^ btnVolver;
        System::Windows::Forms::Button^ btnEjecutar;

#pragma region Windows Form Designer generated code
        void InitializeComponent(void)
        {
            this->gbSimple = (gcnew System::Windows::Forms::GroupBox());
            this->lblFuente = (gcnew System::Windows::Forms::Label());
            this->cbFuente = (gcnew System::Windows::Forms::ComboBox());
            this->lblSumidero = (gcnew System::Windows::Forms::Label());
            this->cbSumidero = (gcnew System::Windows::Forms::ComboBox());
            this->gbMulti = (gcnew System::Windows::Forms::GroupBox());
            this->chkMultiFuente = (gcnew System::Windows::Forms::CheckBox());
            this->lstFuentes = (gcnew System::Windows::Forms::ListBox());
            this->chkMultiSumidero = (gcnew System::Windows::Forms::CheckBox());
            this->lstSumideros = (gcnew System::Windows::Forms::ListBox());
            this->lblEstado = (gcnew System::Windows::Forms::Label());
            this->panelGrafo = (gcnew System::Windows::Forms::Panel());
            this->btnVolver = (gcnew System::Windows::Forms::Button());
            this->btnEjecutar = (gcnew System::Windows::Forms::Button());
            this->components = (gcnew System::ComponentModel::Container());
            this->gbSimple->SuspendLayout();
            this->gbMulti->SuspendLayout();
            this->SuspendLayout();
            // 
            // gbSimple
            // 
            this->gbSimple->Controls->Add(this->lblFuente);
            this->gbSimple->Controls->Add(this->cbFuente);
            this->gbSimple->Controls->Add(this->lblSumidero);
            this->gbSimple->Controls->Add(this->cbSumidero);
            this->gbSimple->Location = System::Drawing::Point(15, 15);
            this->gbSimple->Name = L"gbSimple";
            this->gbSimple->Size = System::Drawing::Size(360, 85);
            this->gbSimple->TabIndex = 0;
            this->gbSimple->TabStop = false;
            this->gbSimple->Text = L"Fuente y sumidero";
            // 
            // lblFuente
            // 
            this->lblFuente->Location = System::Drawing::Point(15, 30);
            this->lblFuente->Name = L"lblFuente";
            this->lblFuente->Size = System::Drawing::Size(55, 23);
            this->lblFuente->TabIndex = 0;
            this->lblFuente->Text = L"Fuente:";
            // 
            // cbFuente
            // 
            this->cbFuente->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
            this->cbFuente->Location = System::Drawing::Point(75, 28);
            this->cbFuente->Name = L"cbFuente";
            this->cbFuente->Size = System::Drawing::Size(100, 21);
            this->cbFuente->TabIndex = 1;
            // 
            // lblSumidero
            // 
            this->lblSumidero->Location = System::Drawing::Point(185, 30);
            this->lblSumidero->Name = L"lblSumidero";
            this->lblSumidero->Size = System::Drawing::Size(70, 23);
            this->lblSumidero->TabIndex = 2;
            this->lblSumidero->Text = L"Sumidero:";
            // 
            // cbSumidero
            // 
            this->cbSumidero->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
            this->cbSumidero->Location = System::Drawing::Point(255, 28);
            this->cbSumidero->Name = L"cbSumidero";
            this->cbSumidero->Size = System::Drawing::Size(90, 21);
            this->cbSumidero->TabIndex = 3;
            // 
            // gbMulti
            // 
            this->gbMulti->Controls->Add(this->chkMultiFuente);
            this->gbMulti->Controls->Add(this->lstFuentes);
            this->gbMulti->Controls->Add(this->chkMultiSumidero);
            this->gbMulti->Controls->Add(this->lstSumideros);
            this->gbMulti->Location = System::Drawing::Point(15, 110);
            this->gbMulti->Name = L"gbMulti";
            this->gbMulti->Size = System::Drawing::Size(360, 320);
            this->gbMulti->TabIndex = 1;
            this->gbMulti->TabStop = false;
            this->gbMulti->Text = L"Seleccion multiple";
            // 
            // chkMultiFuente
            // 
            this->chkMultiFuente->Location = System::Drawing::Point(15, 25);
            this->chkMultiFuente->Name = L"chkMultiFuente";
            this->chkMultiFuente->Size = System::Drawing::Size(160, 24);
            this->chkMultiFuente->TabIndex = 0;
            this->chkMultiFuente->Text = L"Multiples fuentes";
            this->chkMultiFuente->CheckedChanged += gcnew System::EventHandler(this, &SeleccionForm::chkMultiFuente_CheckedChanged);
            // 
            // lstFuentes
            // 
            this->lstFuentes->FormattingEnabled = true;
            this->lstFuentes->Location = System::Drawing::Point(15, 55);
            this->lstFuentes->Name = L"lstFuentes";
            this->lstFuentes->SelectionMode = System::Windows::Forms::SelectionMode::MultiExtended;
            this->lstFuentes->Size = System::Drawing::Size(160, 244);
            this->lstFuentes->TabIndex = 1;
            // 
            // chkMultiSumidero
            // 
            this->chkMultiSumidero->Location = System::Drawing::Point(190, 25);
            this->chkMultiSumidero->Name = L"chkMultiSumidero";
            this->chkMultiSumidero->Size = System::Drawing::Size(160, 24);
            this->chkMultiSumidero->TabIndex = 2;
            this->chkMultiSumidero->Text = L"Multiples sumideros";
            this->chkMultiSumidero->CheckedChanged += gcnew System::EventHandler(this, &SeleccionForm::chkMultiSumidero_CheckedChanged);
            // 
            // lstSumideros
            // 
            this->lstSumideros->FormattingEnabled = true;
            this->lstSumideros->Location = System::Drawing::Point(190, 55);
            this->lstSumideros->Name = L"lstSumideros";
            this->lstSumideros->SelectionMode = System::Windows::Forms::SelectionMode::MultiExtended;
            this->lstSumideros->Size = System::Drawing::Size(160, 244);
            this->lstSumideros->TabIndex = 3;
            // 
            // lblEstado
            // 
            this->lblEstado->ForeColor = System::Drawing::Color::DarkRed;
            this->lblEstado->Location = System::Drawing::Point(15, 440);
            this->lblEstado->Name = L"lblEstado";
            this->lblEstado->Size = System::Drawing::Size(360, 25);
            this->lblEstado->TabIndex = 2;
            // 
            // panelGrafo
            // 
            this->panelGrafo->BackColor = System::Drawing::Color::White;
            this->panelGrafo->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
            this->panelGrafo->Location = System::Drawing::Point(390, 15);
            this->panelGrafo->Name = L"panelGrafo";
            this->panelGrafo->Size = System::Drawing::Size(620, 445);
            this->panelGrafo->TabIndex = 3;
            this->panelGrafo->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &SeleccionForm::panelGrafo_Paint);
            // 
            // btnVolver
            // 
            this->btnVolver->Location = System::Drawing::Point(390, 470);
            this->btnVolver->Name = L"btnVolver";
            this->btnVolver->Size = System::Drawing::Size(120, 32);
            this->btnVolver->TabIndex = 4;
            this->btnVolver->Text = L"Volver";
            this->btnVolver->UseVisualStyleBackColor = true;
            this->btnVolver->Click += gcnew System::EventHandler(this, &SeleccionForm::btnVolver_Click);
            // 
            // btnEjecutar
            // 
            this->btnEjecutar->BackColor = System::Drawing::Color::FromArgb(30, 120, 60);
            this->btnEjecutar->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
            this->btnEjecutar->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Bold));
            this->btnEjecutar->ForeColor = System::Drawing::Color::White;
            this->btnEjecutar->Location = System::Drawing::Point(730, 470);
            this->btnEjecutar->Name = L"btnEjecutar";
            this->btnEjecutar->Size = System::Drawing::Size(280, 38);
            this->btnEjecutar->TabIndex = 5;
            this->btnEjecutar->Text = L"Ejecutar Ford-Fulkerson";
            this->btnEjecutar->UseVisualStyleBackColor = false;
            this->btnEjecutar->Click += gcnew System::EventHandler(this, &SeleccionForm::btnEjecutar_Click);
            // 
            // SeleccionForm
            // 
            this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
            this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
            this->BackColor = System::Drawing::Color::FromArgb(245, 245, 245);
            this->ClientSize = System::Drawing::Size(1030, 520);
            this->Controls->Add(this->gbSimple);
            this->Controls->Add(this->gbMulti);
            this->Controls->Add(this->lblEstado);
            this->Controls->Add(this->panelGrafo);
            this->Controls->Add(this->btnVolver);
            this->Controls->Add(this->btnEjecutar);
            this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
            this->MaximizeBox = false;
            this->Name = L"SeleccionForm";
            this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
            this->Text = L"Flujo Maximo - Fuente y sumidero";
            this->Load += gcnew System::EventHandler(this, &SeleccionForm::SeleccionForm_Load);
            this->gbSimple->ResumeLayout(false);
            this->gbMulti->ResumeLayout(false);
            this->ResumeLayout(false);
        }
#pragma endregion

    private:
        System::Void SeleccionForm_Load(System::Object^ sender, System::EventArgs^ e)
        {
            Grafo^ g = EstadoGlobal::estado->grafo;
            cbFuente->Items->Clear(); cbSumidero->Items->Clear();
            lstFuentes->Items->Clear(); lstSumideros->Items->Clear();
            if (g != nullptr) {
                for each (Vertice^ v in g->getVertices()) {
                    cbFuente->Items->Add(v);
                    cbSumidero->Items->Add(v);
                    lstFuentes->Items->Add(v);
                    lstSumideros->Items->Add(v);
                }
            }
            if (cbFuente->Items->Count > 0) cbFuente->SelectedIndex = 0;
            if (cbSumidero->Items->Count > 1) cbSumidero->SelectedIndex = cbSumidero->Items->Count - 1;
            lstFuentes->Enabled = chkMultiFuente->Checked;
            lstSumideros->Enabled = chkMultiSumidero->Checked;
            lblEstado->Text = "";
            if (g != nullptr) EstadoGlobal::estado->grafoVisual->calcularPosiciones(g, panelGrafo->Width, panelGrafo->Height);
            panelGrafo->Invalidate();
        }

        System::Void chkMultiFuente_CheckedChanged(System::Object^ sender, System::EventArgs^ e)
        {
            lstFuentes->Enabled = chkMultiFuente->Checked;
        }

        System::Void chkMultiSumidero_CheckedChanged(System::Object^ sender, System::EventArgs^ e)
        {
            lstSumideros->Enabled = chkMultiSumidero->Checked;
        }

        System::Void btnVolver_Click(System::Object^ sender, System::EventArgs^ e)
        {
            this->DialogResult = System::Windows::Forms::DialogResult::Cancel;
        }

        System::Void btnEjecutar_Click(System::Object^ sender, System::EventArgs^ e)
        {
            Grafo^ g = EstadoGlobal::estado->grafo;
            if (g == nullptr) return;

            List<int>^ fuentes = gcnew List<int>();
            List<int>^ sumideros = gcnew List<int>();

            if (chkMultiFuente->Checked) {
                for each (Object^ o in lstFuentes->SelectedItems) fuentes->Add(((Vertice^)o)->getId());
                if (fuentes->Count == 0) { lblEstado->Text = "Seleccione al menos una fuente."; return; }
            }
            else {
                if (cbFuente->SelectedItem == nullptr) { lblEstado->Text = "Seleccione una fuente."; return; }
                fuentes->Add(((Vertice^)cbFuente->SelectedItem)->getId());
            }

            if (chkMultiSumidero->Checked) {
                for each (Object^ o in lstSumideros->SelectedItems) sumideros->Add(((Vertice^)o)->getId());
                if (sumideros->Count == 0) { lblEstado->Text = "Seleccione al menos un sumidero."; return; }
            }
            else {
                if (cbSumidero->SelectedItem == nullptr) { lblEstado->Text = "Seleccione un sumidero."; return; }
                sumideros->Add(((Vertice^)cbSumidero->SelectedItem)->getId());
            }

            if (fuentes->Count == 1 && sumideros->Count == 1 && fuentes[0] == sumideros[0]) {
                lblEstado->Text = "Fuente y sumidero no pueden ser iguales.";
                MessageBox::Show("Fuente y sumidero no pueden ser iguales.", "Error", MessageBoxButtons::OK, MessageBoxIcon::Warning);
                return;
            }
            for each (int f in fuentes) {
                if (sumideros->Contains(f)) {
                    lblEstado->Text = "Un vertice no puede ser fuente y sumidero a la vez.";
                    MessageBox::Show("Un vertice no puede ser fuente y sumidero a la vez.", "Error", MessageBoxButtons::OK, MessageBoxIcon::Warning);
                    return;
                }
            }

            TransformadorFlujo^ tf = gcnew TransformadorFlujo();
            int sf = -1, st = -1;
            try {
            Grafo^ gTrabajo = tf->transformar(g, fuentes, sumideros, sf, st);
            EstadoGlobal::estado->grafoTransformado = gTrabajo;
            EstadoGlobal::estado->superFuenteId = sf;
            EstadoGlobal::estado->superSumideroId = st;
            EstadoGlobal::estado->fuenteEfectiva = (fuentes->Count > 1) ? sf : fuentes[0];
            EstadoGlobal::estado->sumideroEfectivo = (sumideros->Count > 1) ? st : sumideros[0];

                FordFulkerson^ ff = gcnew FordFulkerson();
                EstadoGlobal::estado->pasos = ff->ejecutar(gTrabajo, EstadoGlobal::estado->fuenteEfectiva, EstadoGlobal::estado->sumideroEfectivo);
                EstadoGlobal::estado->pasoActual = 0;
                EstadoGlobal::estado->corte = nullptr;
                this->DialogResult = System::Windows::Forms::DialogResult::OK;
            }
            catch (Exception^ ex) {
                MessageBox::Show("Error al ejecutar Ford-Fulkerson:\n" + ex->Message, "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
            }
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
