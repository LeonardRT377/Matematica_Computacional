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
    /// Pantalla 4: ejecucion paso a paso de Ford-Fulkerson.
    /// </summary>
    public ref class EjecucionForm : public System::Windows::Forms::Form
    {
    public:
        EjecucionForm(void) { InitializeComponent(); if (System::ComponentModel::LicenseManager::UsageMode != System::ComponentModel::LicenseUsageMode::Designtime) TemaVisual::aplicar(this, 4, "Ejecucion"); }

    protected:
        ~EjecucionForm() { if (components) delete components; }

    private:
        System::ComponentModel::Container ^components;
        System::Windows::Forms::Panel^ panelGrafo;
        System::Windows::Forms::GroupBox^ gbInfo;
        System::Windows::Forms::Label^ lblIteracion;
        System::Windows::Forms::Label^ lblCamino;
        System::Windows::Forms::Label^ lblResidual;
        System::Windows::Forms::Label^ lblFlujoAgregado;
        System::Windows::Forms::Label^ lblFlujoTotal;
        System::Windows::Forms::CheckBox^ chkResidual;
        System::Windows::Forms::CheckBox^ chkCorte;
        System::Windows::Forms::Button^ btnAnterior;
        System::Windows::Forms::Button^ btnSiguiente;
        System::Windows::Forms::Button^ btnResultado;
        System::Windows::Forms::Button^ btnReiniciar;

#pragma region Windows Form Designer generated code
        void InitializeComponent(void)
        {
            this->panelGrafo = (gcnew System::Windows::Forms::Panel());
            this->gbInfo = (gcnew System::Windows::Forms::GroupBox());
            this->lblIteracion = (gcnew System::Windows::Forms::Label());
            this->lblCamino = (gcnew System::Windows::Forms::Label());
            this->lblResidual = (gcnew System::Windows::Forms::Label());
            this->lblFlujoAgregado = (gcnew System::Windows::Forms::Label());
            this->lblFlujoTotal = (gcnew System::Windows::Forms::Label());
            this->chkResidual = (gcnew System::Windows::Forms::CheckBox());
            this->chkCorte = (gcnew System::Windows::Forms::CheckBox());
            this->btnAnterior = (gcnew System::Windows::Forms::Button());
            this->btnSiguiente = (gcnew System::Windows::Forms::Button());
            this->btnResultado = (gcnew System::Windows::Forms::Button());
            this->btnReiniciar = (gcnew System::Windows::Forms::Button());
            this->components = (gcnew System::ComponentModel::Container());
            this->gbInfo->SuspendLayout();
            this->SuspendLayout();
            // 
            // panelGrafo
            // 
            this->panelGrafo->BackColor = System::Drawing::Color::White;
            this->panelGrafo->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
            this->panelGrafo->Location = System::Drawing::Point(15, 15);
            this->panelGrafo->Name = L"panelGrafo";
            this->panelGrafo->Size = System::Drawing::Size(760, 560);
            this->panelGrafo->TabIndex = 0;
            this->panelGrafo->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &EjecucionForm::panelGrafo_Paint);
            // 
            // gbInfo
            // 
            this->gbInfo->Controls->Add(this->lblIteracion);
            this->gbInfo->Controls->Add(this->lblCamino);
            this->gbInfo->Controls->Add(this->lblResidual);
            this->gbInfo->Controls->Add(this->lblFlujoAgregado);
            this->gbInfo->Controls->Add(this->lblFlujoTotal);
            this->gbInfo->Controls->Add(this->chkResidual);
            this->gbInfo->Controls->Add(this->chkCorte);
            this->gbInfo->Location = System::Drawing::Point(790, 15);
            this->gbInfo->Name = L"gbInfo";
            this->gbInfo->Size = System::Drawing::Size(300, 260);
            this->gbInfo->TabIndex = 1;
            this->gbInfo->TabStop = false;
            this->gbInfo->Text = L"Estado del paso";
            // 
            // lblIteracion
            // 
            this->lblIteracion->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9, System::Drawing::FontStyle::Bold));
            this->lblIteracion->Location = System::Drawing::Point(12, 25);
            this->lblIteracion->Name = L"lblIteracion";
            this->lblIteracion->Size = System::Drawing::Size(275, 20);
            this->lblIteracion->TabIndex = 0;
            this->lblIteracion->Text = L"Iteracion: - / -";
            // 
            // lblCamino
            // 
            this->lblCamino->Location = System::Drawing::Point(12, 50);
            this->lblCamino->Name = L"lblCamino";
            this->lblCamino->Size = System::Drawing::Size(275, 45);
            this->lblCamino->TabIndex = 1;
            this->lblCamino->Text = L"Camino: -";
            // 
            // lblResidual
            // 
            this->lblResidual->Location = System::Drawing::Point(12, 100);
            this->lblResidual->Name = L"lblResidual";
            this->lblResidual->Size = System::Drawing::Size(275, 20);
            this->lblResidual->TabIndex = 2;
            this->lblResidual->Text = L"Cuello de botella: -";
            // 
            // lblFlujoAgregado
            // 
            this->lblFlujoAgregado->Location = System::Drawing::Point(12, 125);
            this->lblFlujoAgregado->Name = L"lblFlujoAgregado";
            this->lblFlujoAgregado->Size = System::Drawing::Size(275, 20);
            this->lblFlujoAgregado->TabIndex = 3;
            this->lblFlujoAgregado->Text = L"Flujo agregado: -";
            // 
            // lblFlujoTotal
            // 
            this->lblFlujoTotal->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Bold));
            this->lblFlujoTotal->ForeColor = System::Drawing::Color::FromArgb(30, 100, 60);
            this->lblFlujoTotal->Location = System::Drawing::Point(12, 150);
            this->lblFlujoTotal->Name = L"lblFlujoTotal";
            this->lblFlujoTotal->Size = System::Drawing::Size(275, 25);
            this->lblFlujoTotal->TabIndex = 4;
            this->lblFlujoTotal->Text = L"Flujo total: -";
            // 
            // chkResidual
            // 
            this->chkResidual->Location = System::Drawing::Point(12, 185);
            this->chkResidual->Name = L"chkResidual";
            this->chkResidual->Size = System::Drawing::Size(200, 24);
            this->chkResidual->TabIndex = 5;
            this->chkResidual->Text = L"Mostrar red residual";
            this->chkResidual->CheckedChanged += gcnew System::EventHandler(this, &EjecucionForm::chkResidual_CheckedChanged);
            // 
            // chkCorte
            // 
            this->chkCorte->Location = System::Drawing::Point(12, 212);
            this->chkCorte->Name = L"chkCorte";
            this->chkCorte->Size = System::Drawing::Size(220, 24);
            this->chkCorte->TabIndex = 6;
            this->chkCorte->Text = L"Resaltar corte minimo";
            this->chkCorte->CheckedChanged += gcnew System::EventHandler(this, &EjecucionForm::chkCorte_CheckedChanged);
            // 
            // btnAnterior
            // 
            this->btnAnterior->Location = System::Drawing::Point(790, 290);
            this->btnAnterior->Name = L"btnAnterior";
            this->btnAnterior->Size = System::Drawing::Size(140, 38);
            this->btnAnterior->TabIndex = 2;
            this->btnAnterior->Text = L"< Anterior";
            this->btnAnterior->UseVisualStyleBackColor = true;
            this->btnAnterior->Click += gcnew System::EventHandler(this, &EjecucionForm::btnAnterior_Click);
            // 
            // btnSiguiente
            // 
            this->btnSiguiente->BackColor = System::Drawing::Color::FromArgb(30, 100, 180);
            this->btnSiguiente->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
            this->btnSiguiente->ForeColor = System::Drawing::Color::White;
            this->btnSiguiente->Location = System::Drawing::Point(950, 290);
            this->btnSiguiente->Name = L"btnSiguiente";
            this->btnSiguiente->Size = System::Drawing::Size(140, 38);
            this->btnSiguiente->TabIndex = 3;
            this->btnSiguiente->Text = L"Siguiente >";
            this->btnSiguiente->UseVisualStyleBackColor = false;
            this->btnSiguiente->Click += gcnew System::EventHandler(this, &EjecucionForm::btnSiguiente_Click);
            // 
            // btnResultado
            // 
            this->btnResultado->BackColor = System::Drawing::Color::FromArgb(120, 80, 160);
            this->btnResultado->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
            this->btnResultado->ForeColor = System::Drawing::Color::White;
            this->btnResultado->Location = System::Drawing::Point(790, 345);
            this->btnResultado->Name = L"btnResultado";
            this->btnResultado->Size = System::Drawing::Size(300, 38);
            this->btnResultado->TabIndex = 4;
            this->btnResultado->Text = L"Ver resultados";
            this->btnResultado->UseVisualStyleBackColor = false;
            this->btnResultado->Click += gcnew System::EventHandler(this, &EjecucionForm::btnResultado_Click);
            // 
            // btnReiniciar
            // 
            this->btnReiniciar->Location = System::Drawing::Point(790, 400);
            this->btnReiniciar->Name = L"btnReiniciar";
            this->btnReiniciar->Size = System::Drawing::Size(300, 32);
            this->btnReiniciar->TabIndex = 5;
            this->btnReiniciar->Text = L"Reiniciar";
            this->btnReiniciar->UseVisualStyleBackColor = true;
            this->btnReiniciar->Click += gcnew System::EventHandler(this, &EjecucionForm::btnReiniciar_Click);
            // 
            // EjecucionForm
            // 
            this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
            this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
            this->BackColor = System::Drawing::Color::FromArgb(245, 245, 245);
            this->ClientSize = System::Drawing::Size(1105, 595);
            this->Controls->Add(this->panelGrafo);
            this->Controls->Add(this->gbInfo);
            this->Controls->Add(this->btnAnterior);
            this->Controls->Add(this->btnSiguiente);
            this->Controls->Add(this->btnResultado);
            this->Controls->Add(this->btnReiniciar);
            this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
            this->MaximizeBox = false;
            this->Name = L"EjecucionForm";
            this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
            this->Text = L"Flujo Maximo - Ejecucion paso a paso";
            this->Load += gcnew System::EventHandler(this, &EjecucionForm::EjecucionForm_Load);
            this->gbInfo->ResumeLayout(false);
            this->ResumeLayout(false);
        }
#pragma endregion

    private:
        System::Void EjecucionForm_Load(System::Object^ sender, System::EventArgs^ e)
        {
            Grafo^ g = (EstadoGlobal::estado->grafoTransformado != nullptr) ? EstadoGlobal::estado->grafoTransformado : EstadoGlobal::estado->grafo;
            if (g != nullptr) EstadoGlobal::estado->grafoVisual->calcularPosiciones(g, panelGrafo->Width, panelGrafo->Height);
            actualizarVista();
        }

        System::Void actualizarVista()
        {
            if (EstadoGlobal::estado->pasos == nullptr || EstadoGlobal::estado->pasos->Count == 0) return;
            if (EstadoGlobal::estado->pasoActual < 0) EstadoGlobal::estado->pasoActual = 0;
            if (EstadoGlobal::estado->pasoActual >= EstadoGlobal::estado->pasos->Count) EstadoGlobal::estado->pasoActual = EstadoGlobal::estado->pasos->Count - 1;
            PasoAlgoritmo^ paso = EstadoGlobal::estado->pasos[EstadoGlobal::estado->pasoActual];
            Grafo^ g = (EstadoGlobal::estado->grafoTransformado != nullptr) ? EstadoGlobal::estado->grafoTransformado : EstadoGlobal::estado->grafo;

            Dictionary<int, int>^ flujos = paso->getFlujosAristas();
            for each (Arista^ a in g->getAristas())
                a->setFlujo(flujos->ContainsKey(a->getId()) ? flujos[a->getId()] : 0);
            EstadoGlobal::estado->grafoVisual->calcularPosiciones(g, panelGrafo->Width, panelGrafo->Height);

            Dictionary<int, String^>^ nombres = EstadoGlobal::estado->nombres(g);
            lblIteracion->Text = "Iteracion: " + (EstadoGlobal::estado->pasoActual + 1) + " / " + EstadoGlobal::estado->pasos->Count + (paso->getEsFinal() ? "  (final)" : "");
            if (paso->getEsFinal()) {
                lblCamino->Text = "Camino: (flujo maximo alcanzado)";
                lblResidual->Text = "Cuello de botella: -";
                lblFlujoAgregado->Text = "Flujo agregado: 0";
            }
            else {
                lblCamino->Text = "Camino: " + paso->getCaminoTextoConNombres(nombres);
                lblResidual->Text = "Cuello de botella: " + paso->getCapacidadAumentante();
                lblFlujoAgregado->Text = "Flujo agregado: +" + paso->getFlujoAgregado();
            }
            lblFlujoTotal->Text = "Flujo total: " + paso->getFlujoTotal();

            btnAnterior->Enabled = (EstadoGlobal::estado->pasoActual > 0);
            btnSiguiente->Enabled = (EstadoGlobal::estado->pasoActual < EstadoGlobal::estado->pasos->Count - 1);
            chkCorte->Enabled = paso->getEsFinal();
            if (!paso->getEsFinal()) chkCorte->Checked = false;
            panelGrafo->Invalidate();
        }

        System::Void btnAnterior_Click(System::Object^ sender, System::EventArgs^ e)
        {
            if (EstadoGlobal::estado->pasoActual > 0) { EstadoGlobal::estado->pasoActual--; actualizarVista(); }
        }

        System::Void btnSiguiente_Click(System::Object^ sender, System::EventArgs^ e)
        {
            if (EstadoGlobal::estado->pasos != nullptr && EstadoGlobal::estado->pasoActual < EstadoGlobal::estado->pasos->Count - 1) { EstadoGlobal::estado->pasoActual++; actualizarVista(); }
        }

        System::Void chkResidual_CheckedChanged(System::Object^ sender, System::EventArgs^ e)
        {
            panelGrafo->Invalidate();
        }

        System::Void chkCorte_CheckedChanged(System::Object^ sender, System::EventArgs^ e)
        {
            panelGrafo->Invalidate();
        }

        System::Void btnResultado_Click(System::Object^ sender, System::EventArgs^ e)
        {
            this->DialogResult = System::Windows::Forms::DialogResult::OK;
        }

        System::Void btnReiniciar_Click(System::Object^ sender, System::EventArgs^ e)
        {
            this->DialogResult = System::Windows::Forms::DialogResult::Retry;
        }

        System::Void panelGrafo_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e)
        {
            if (EstadoGlobal::estado->pasos == nullptr || EstadoGlobal::estado->pasos->Count == 0) return;
            Grafo^ g = (EstadoGlobal::estado->grafoTransformado != nullptr) ? EstadoGlobal::estado->grafoTransformado : EstadoGlobal::estado->grafo;
            PasoAlgoritmo^ paso = EstadoGlobal::estado->pasos[EstadoGlobal::estado->pasoActual];
            if (chkCorte->Checked && paso->getEsFinal()) {
                CorteMinimo^ cm = gcnew CorteMinimo();
                ResultadoCorte^ c = cm->calcular(g, EstadoGlobal::estado->fuenteEfectiva, EstadoGlobal::estado->sumideroEfectivo, paso->getFlujosAristas());
                EstadoGlobal::estado->grafoVisual->dibujarCorte(e->Graphics, g, c, paso->getFlujosAristas());
            }
            else if (chkResidual->Checked) {
                EstadoGlobal::estado->grafoVisual->dibujarResidual(e->Graphics, g, paso);
            }
            else {
                EstadoGlobal::estado->grafoVisual->dibujarPaso(e->Graphics, g, paso);
            }
        }
    };

}
