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
    /// Pantalla 5: resultado final (flujo maximo, tabla, caminos y corte minimo).
    /// </summary>
    public ref class ResultadoForm : public System::Windows::Forms::Form
    {
    public:
        ResultadoForm(void) { InitializeComponent(); if (System::ComponentModel::LicenseManager::UsageMode != System::ComponentModel::LicenseUsageMode::Designtime) TemaVisual::aplicar(this, 5, "Resultados"); }

    protected:
        ~ResultadoForm() { if (components) delete components; }

    private:
        System::ComponentModel::Container ^components;
        System::Windows::Forms::Label^ lblFlujoMaximo;
        System::Windows::Forms::GroupBox^ gbTabla;
        System::Windows::Forms::ListBox^ lstTabla;
        System::Windows::Forms::GroupBox^ gbCaminos;
        System::Windows::Forms::ListBox^ lstCaminos;
        System::Windows::Forms::GroupBox^ gbCorte;
        System::Windows::Forms::Label^ lblS;
        System::Windows::Forms::Label^ lblT;
        System::Windows::Forms::ListBox^ lstCorte;
        System::Windows::Forms::Label^ lblCapacidad;
        System::Windows::Forms::Label^ lblVerificacion;
        System::Windows::Forms::Panel^ panelGrafo;
        System::Windows::Forms::Button^ btnVolver;
        System::Windows::Forms::Button^ btnReiniciar;

#pragma region Windows Form Designer generated code
        void InitializeComponent(void)
        {
            this->lblFlujoMaximo = (gcnew System::Windows::Forms::Label());
            this->gbTabla = (gcnew System::Windows::Forms::GroupBox());
            this->lstTabla = (gcnew System::Windows::Forms::ListBox());
            this->gbCaminos = (gcnew System::Windows::Forms::GroupBox());
            this->lstCaminos = (gcnew System::Windows::Forms::ListBox());
            this->gbCorte = (gcnew System::Windows::Forms::GroupBox());
            this->lblS = (gcnew System::Windows::Forms::Label());
            this->lblT = (gcnew System::Windows::Forms::Label());
            this->lstCorte = (gcnew System::Windows::Forms::ListBox());
            this->lblCapacidad = (gcnew System::Windows::Forms::Label());
            this->lblVerificacion = (gcnew System::Windows::Forms::Label());
            this->panelGrafo = (gcnew System::Windows::Forms::Panel());
            this->btnVolver = (gcnew System::Windows::Forms::Button());
            this->btnReiniciar = (gcnew System::Windows::Forms::Button());
            this->components = (gcnew System::ComponentModel::Container());
            this->gbTabla->SuspendLayout();
            this->gbCaminos->SuspendLayout();
            this->gbCorte->SuspendLayout();
            this->SuspendLayout();
            // 
            // lblFlujoMaximo
            // 
            this->lblFlujoMaximo->Font = (gcnew System::Drawing::Font(L"Segoe UI", 14, System::Drawing::FontStyle::Bold));
            this->lblFlujoMaximo->ForeColor = System::Drawing::Color::FromArgb(30, 100, 60);
            this->lblFlujoMaximo->Location = System::Drawing::Point(15, 12);
            this->lblFlujoMaximo->Name = L"lblFlujoMaximo";
            this->lblFlujoMaximo->Size = System::Drawing::Size(400, 30);
            this->lblFlujoMaximo->TabIndex = 0;
            this->lblFlujoMaximo->Text = L"FLUJO MAXIMO: -";
            // 
            // gbTabla
            // 
            this->gbTabla->Controls->Add(this->lstTabla);
            this->gbTabla->Location = System::Drawing::Point(15, 50);
            this->gbTabla->Name = L"gbTabla";
            this->gbTabla->Size = System::Drawing::Size(340, 260);
            this->gbTabla->TabIndex = 1;
            this->gbTabla->TabStop = false;
            this->gbTabla->Text = L"Flujo por arista";
            // 
            // lstTabla
            // 
            this->lstTabla->Font = (gcnew System::Drawing::Font(L"Consolas", 9));
            this->lstTabla->FormattingEnabled = true;
            this->lstTabla->Location = System::Drawing::Point(12, 22);
            this->lstTabla->Name = L"lstTabla";
            this->lstTabla->Size = System::Drawing::Size(315, 225);
            this->lstTabla->TabIndex = 0;
            // 
            // gbCaminos
            // 
            this->gbCaminos->Controls->Add(this->lstCaminos);
            this->gbCaminos->Location = System::Drawing::Point(15, 320);
            this->gbCaminos->Name = L"gbCaminos";
            this->gbCaminos->Size = System::Drawing::Size(340, 190);
            this->gbCaminos->TabIndex = 2;
            this->gbCaminos->TabStop = false;
            this->gbCaminos->Text = L"Caminos aumentantes";
            // 
            // lstCaminos
            // 
            this->lstCaminos->Font = (gcnew System::Drawing::Font(L"Consolas", 8));
            this->lstCaminos->FormattingEnabled = true;
            this->lstCaminos->Location = System::Drawing::Point(12, 22);
            this->lstCaminos->Name = L"lstCaminos";
            this->lstCaminos->Size = System::Drawing::Size(315, 155);
            this->lstCaminos->TabIndex = 0;
            // 
            // gbCorte
            // 
            this->gbCorte->Controls->Add(this->lblS);
            this->gbCorte->Controls->Add(this->lblT);
            this->gbCorte->Controls->Add(this->lstCorte);
            this->gbCorte->Controls->Add(this->lblCapacidad);
            this->gbCorte->Controls->Add(this->lblVerificacion);
            this->gbCorte->Location = System::Drawing::Point(370, 50);
            this->gbCorte->Name = L"gbCorte";
            this->gbCorte->Size = System::Drawing::Size(340, 460);
            this->gbCorte->TabIndex = 3;
            this->gbCorte->TabStop = false;
            this->gbCorte->Text = L"Corte minimo ( S / T )";
            // 
            // lblS
            // 
            this->lblS->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9, System::Drawing::FontStyle::Bold));
            this->lblS->Location = System::Drawing::Point(12, 25);
            this->lblS->Name = L"lblS";
            this->lblS->Size = System::Drawing::Size(315, 40);
            this->lblS->TabIndex = 0;
            this->lblS->Text = L"S = {}";
            // 
            // lblT
            // 
            this->lblT->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9, System::Drawing::FontStyle::Bold));
            this->lblT->Location = System::Drawing::Point(12, 70);
            this->lblT->Name = L"lblT";
            this->lblT->Size = System::Drawing::Size(315, 40);
            this->lblT->TabIndex = 1;
            this->lblT->Text = L"T = {}";
            // 
            // lstCorte
            // 
            this->lstCorte->Font = (gcnew System::Drawing::Font(L"Consolas", 8));
            this->lstCorte->FormattingEnabled = true;
            this->lstCorte->Location = System::Drawing::Point(12, 115);
            this->lstCorte->Name = L"lstCorte";
            this->lstCorte->Size = System::Drawing::Size(315, 155);
            this->lstCorte->TabIndex = 2;
            // 
            // lblCapacidad
            // 
            this->lblCapacidad->Location = System::Drawing::Point(12, 285);
            this->lblCapacidad->Name = L"lblCapacidad";
            this->lblCapacidad->Size = System::Drawing::Size(315, 40);
            this->lblCapacidad->TabIndex = 3;
            this->lblCapacidad->Text = L"Capacidad del corte: -";
            // 
            // lblVerificacion
            // 
            this->lblVerificacion->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Bold));
            this->lblVerificacion->Location = System::Drawing::Point(12, 340);
            this->lblVerificacion->Name = L"lblVerificacion";
            this->lblVerificacion->Size = System::Drawing::Size(315, 90);
            this->lblVerificacion->TabIndex = 4;
            // 
            // panelGrafo
            // 
            this->panelGrafo->BackColor = System::Drawing::Color::White;
            this->panelGrafo->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
            this->panelGrafo->Location = System::Drawing::Point(730, 50);
            this->panelGrafo->Name = L"panelGrafo";
            this->panelGrafo->Size = System::Drawing::Size(560, 460);
            this->panelGrafo->TabIndex = 4;
            this->panelGrafo->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &ResultadoForm::panelGrafo_Paint);
            // 
            // btnVolver
            // 
            this->btnVolver->Location = System::Drawing::Point(370, 520);
            this->btnVolver->Name = L"btnVolver";
            this->btnVolver->Size = System::Drawing::Size(160, 32);
            this->btnVolver->TabIndex = 5;
            this->btnVolver->Text = L"Volver a ejecucion";
            this->btnVolver->UseVisualStyleBackColor = true;
            this->btnVolver->Click += gcnew System::EventHandler(this, &ResultadoForm::btnVolver_Click);
            // 
            // btnReiniciar
            // 
            this->btnReiniciar->Location = System::Drawing::Point(550, 520);
            this->btnReiniciar->Name = L"btnReiniciar";
            this->btnReiniciar->Size = System::Drawing::Size(160, 32);
            this->btnReiniciar->TabIndex = 6;
            this->btnReiniciar->Text = L"Reiniciar";
            this->btnReiniciar->UseVisualStyleBackColor = true;
            this->btnReiniciar->Click += gcnew System::EventHandler(this, &ResultadoForm::btnReiniciar_Click);
            // 
            // ResultadoForm
            // 
            this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
            this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
            this->BackColor = System::Drawing::Color::FromArgb(245, 245, 245);
            this->ClientSize = System::Drawing::Size(1305, 570);
            this->Controls->Add(this->lblFlujoMaximo);
            this->Controls->Add(this->gbTabla);
            this->Controls->Add(this->gbCaminos);
            this->Controls->Add(this->gbCorte);
            this->Controls->Add(this->panelGrafo);
            this->Controls->Add(this->btnVolver);
            this->Controls->Add(this->btnReiniciar);
            this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
            this->MaximizeBox = false;
            this->Name = L"ResultadoForm";
            this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
            this->Text = L"Flujo Maximo - Resultado final";
            this->Load += gcnew System::EventHandler(this, &ResultadoForm::ResultadoForm_Load);
            this->gbTabla->ResumeLayout(false);
            this->gbCaminos->ResumeLayout(false);
            this->gbCorte->ResumeLayout(false);
            this->ResumeLayout(false);
        }
#pragma endregion

    private:
        System::Void ResultadoForm_Load(System::Object^ sender, System::EventArgs^ e)
        {
            if (EstadoGlobal::estado->pasos == nullptr || EstadoGlobal::estado->pasos->Count == 0) return;
            Grafo^ g = (EstadoGlobal::estado->grafoTransformado != nullptr) ? EstadoGlobal::estado->grafoTransformado : EstadoGlobal::estado->grafo;
            PasoAlgoritmo^ ultimo = EstadoGlobal::estado->pasos[EstadoGlobal::estado->pasos->Count - 1];
            int flujoMax = ultimo->getFlujoTotal();
            lblFlujoMaximo->Text = "FLUJO MAXIMO: " + flujoMax;

            Dictionary<int, int>^ flujos = ultimo->getFlujosAristas();
            for each (Arista^ a in g->getAristas())
                a->setFlujo(flujos->ContainsKey(a->getId()) ? flujos[a->getId()] : 0);

            lstTabla->Items->Clear();
            lstTabla->Items->Add(String::Format("{0,-12}{1,10}{2,8}", "Arista", "Cap.", "Flujo"));
            lstTabla->Items->Add("-------------------------------");
            for each (Arista^ a in g->getAristas()) {
                int fl = flujos->ContainsKey(a->getId()) ? flujos[a->getId()] : 0;
                String^ capStr = (a->getOrigen()->getNombre() == "SUPER_FUENTE" || a->getDestino()->getNombre() == "SUPER_SUMIDERO") ? L"\u221E" : a->getCapacidad().ToString();
                lstTabla->Items->Add(String::Format("{0,-12}{1,10}{2,8}", a->getOrigen()->getNombre() + "->" + a->getDestino()->getNombre(), capStr, fl));
            }

            Dictionary<int, String^>^ nombres = EstadoGlobal::estado->nombres(g);
            lstCaminos->Items->Clear();
            for (int i = 0; i < EstadoGlobal::estado->pasos->Count; i++) {
                PasoAlgoritmo^ p = EstadoGlobal::estado->pasos[i];
                if (p->getEsFinal()) continue;
                lstCaminos->Items->Add((i + 1) + ". " + p->getCaminoTextoConNombres(nombres) + "   +" + p->getFlujoAgregado());
            }

            CorteMinimo^ cm = gcnew CorteMinimo();
            EstadoGlobal::estado->corte = cm->calcular(g, EstadoGlobal::estado->fuenteEfectiva, EstadoGlobal::estado->sumideroEfectivo, flujos);
            lblS->Text = "S = " + EstadoGlobal::estado->corte->getDescripcionS(nombres);
            lblT->Text = "T = " + EstadoGlobal::estado->corte->getDescripcionT(nombres);
            lstCorte->Items->Clear();
            for each (Arista^ a in EstadoGlobal::estado->corte->getAristasCorte()) {
                String^ capStr = (a->getOrigen()->getNombre() == "SUPER_FUENTE" || a->getDestino()->getNombre() == "SUPER_SUMIDERO") ? L"\u221E" : a->getCapacidad().ToString();
                lstCorte->Items->Add(a->getOrigen()->getNombre() + " -> " + a->getDestino()->getNombre() + "   " + capStr);
            }
            lblCapacidad->Text = "Capacidad del corte: " + EstadoGlobal::estado->corte->getCapacidadTotal();
            if (EstadoGlobal::estado->corte->coincideConFlujo(flujoMax)) {
                lblVerificacion->ForeColor = System::Drawing::Color::FromArgb(30, 120, 60);
                lblVerificacion->Text = L"\u2713 Flujo y corte coinciden";
            }
            else {
                lblVerificacion->ForeColor = System::Drawing::Color::Red;
                lblVerificacion->Text = L"\u2717 Flujo y corte no coinciden";
            }

            if (g != nullptr) EstadoGlobal::estado->grafoVisual->calcularPosiciones(g, panelGrafo->Width, panelGrafo->Height);
            panelGrafo->Invalidate();
        }

        System::Void btnVolver_Click(System::Object^ sender, System::EventArgs^ e)
        {
            this->DialogResult = System::Windows::Forms::DialogResult::Cancel;
        }

        System::Void btnReiniciar_Click(System::Object^ sender, System::EventArgs^ e)
        {
            this->DialogResult = System::Windows::Forms::DialogResult::Retry;
        }

        System::Void panelGrafo_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e)
        {
            if (EstadoGlobal::estado->grafoTransformado == nullptr && EstadoGlobal::estado->grafo == nullptr) return;
            Grafo^ g = (EstadoGlobal::estado->grafoTransformado != nullptr) ? EstadoGlobal::estado->grafoTransformado : EstadoGlobal::estado->grafo;
            if (EstadoGlobal::estado->corte == nullptr || EstadoGlobal::estado->pasos == nullptr) return;
            PasoAlgoritmo^ ultimo = EstadoGlobal::estado->pasos[EstadoGlobal::estado->pasos->Count - 1];
            EstadoGlobal::estado->grafoVisual->dibujarCorte(e->Graphics, g, EstadoGlobal::estado->corte, ultimo->getFlujosAristas());
        }
    };

}
