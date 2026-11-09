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
    /// Pantalla 1: configuracion inicial (cantidad de vertices y modo de creacion).
    /// </summary>
    public ref class ConfiguracionForm : public System::Windows::Forms::Form
    {
    public:
        ConfiguracionForm(void) { InitializeComponent(); if (System::ComponentModel::LicenseManager::UsageMode != System::ComponentModel::LicenseUsageMode::Designtime) TemaVisual::aplicar(this, 1, "Configuracion"); }

    protected:
        ~ConfiguracionForm() { if (components) delete components; }

    private:
        System::ComponentModel::Container ^components;
        System::Windows::Forms::Label^ lblTitulo;
        System::Windows::Forms::Label^ lblSubtitulo;
        System::Windows::Forms::GroupBox^ gbConfig;
        System::Windows::Forms::Label^ lblCantidad;
        System::Windows::Forms::NumericUpDown^ numVertices;
        System::Windows::Forms::RadioButton^ rbManual;
        System::Windows::Forms::RadioButton^ rbAleatorio;
        System::Windows::Forms::Button^ btnCrear;
        System::Windows::Forms::Button^ btnSalir;

#pragma region Windows Form Designer generated code
        void InitializeComponent(void)
        {
            this->lblTitulo = (gcnew System::Windows::Forms::Label());
            this->lblSubtitulo = (gcnew System::Windows::Forms::Label());
            this->gbConfig = (gcnew System::Windows::Forms::GroupBox());
            this->lblCantidad = (gcnew System::Windows::Forms::Label());
            this->numVertices = (gcnew System::Windows::Forms::NumericUpDown());
            this->rbManual = (gcnew System::Windows::Forms::RadioButton());
            this->rbAleatorio = (gcnew System::Windows::Forms::RadioButton());
            this->btnCrear = (gcnew System::Windows::Forms::Button());
            this->btnSalir = (gcnew System::Windows::Forms::Button());
            this->components = (gcnew System::ComponentModel::Container());
            this->gbConfig->SuspendLayout();
            (safe_cast<System::ComponentModel::ISupportInitialize^>(this->numVertices))->BeginInit();
            this->SuspendLayout();
            // 
            // lblTitulo
            // 
            this->lblTitulo->Font = (gcnew System::Drawing::Font(L"Segoe UI", 18, System::Drawing::FontStyle::Bold));
            this->lblTitulo->ForeColor = System::Drawing::Color::FromArgb(30, 60, 120);
            this->lblTitulo->Location = System::Drawing::Point(120, 30);
            this->lblTitulo->Name = L"lblTitulo";
            this->lblTitulo->Size = System::Drawing::Size(480, 40);
            this->lblTitulo->TabIndex = 0;
            this->lblTitulo->Text = L"FLUJO MAXIMO - Ford-Fulkerson";
            this->lblTitulo->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
            // 
            // lblSubtitulo
            // 
            this->lblSubtitulo->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9, System::Drawing::FontStyle::Italic));
            this->lblSubtitulo->ForeColor = System::Drawing::Color::DimGray;
            this->lblSubtitulo->Location = System::Drawing::Point(160, 75);
            this->lblSubtitulo->Name = L"lblSubtitulo";
            this->lblSubtitulo->Size = System::Drawing::Size(400, 20);
            this->lblSubtitulo->TabIndex = 1;
            this->lblSubtitulo->Text = L"Aplicacion interactiva  |  7 <= n <= 16";
            this->lblSubtitulo->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
            // 
            // gbConfig
            // 
            this->gbConfig->Controls->Add(this->lblCantidad);
            this->gbConfig->Controls->Add(this->numVertices);
            this->gbConfig->Controls->Add(this->rbManual);
            this->gbConfig->Controls->Add(this->rbAleatorio);
            this->gbConfig->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10, System::Drawing::FontStyle::Bold));
            this->gbConfig->Location = System::Drawing::Point(150, 115);
            this->gbConfig->Name = L"gbConfig";
            this->gbConfig->Size = System::Drawing::Size(420, 180);
            this->gbConfig->TabIndex = 2;
            this->gbConfig->TabStop = false;
            this->gbConfig->Text = L"Configuracion del grafo";
            // 
            // lblCantidad
            // 
            this->lblCantidad->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9, System::Drawing::FontStyle::Regular));
            this->lblCantidad->Location = System::Drawing::Point(25, 40);
            this->lblCantidad->Name = L"lblCantidad";
            this->lblCantidad->Size = System::Drawing::Size(160, 23);
            this->lblCantidad->TabIndex = 0;
            this->lblCantidad->Text = L"Cantidad de vertices:";
            // 
            // numVertices
            // 
            this->numVertices->Font = (gcnew System::Drawing::Font(L"Segoe UI", 10));
            this->numVertices->Location = System::Drawing::Point(200, 38);
            this->numVertices->Maximum = System::Decimal(gcnew cli::array< System::Int32 >(4){ 16, 0, 0, 0 });
            this->numVertices->Minimum = System::Decimal(gcnew cli::array< System::Int32 >(4){ 7, 0, 0, 0 });
            this->numVertices->Name = L"numVertices";
            this->numVertices->Size = System::Drawing::Size(80, 25);
            this->numVertices->TabIndex = 1;
            this->numVertices->Value = System::Decimal(gcnew cli::array< System::Int32 >(4){ 7, 0, 0, 0 });
            // 
            // rbManual
            // 
            this->rbManual->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9, System::Drawing::FontStyle::Regular));
            this->rbManual->Location = System::Drawing::Point(25, 80);
            this->rbManual->Name = L"rbManual";
            this->rbManual->Size = System::Drawing::Size(180, 24);
            this->rbManual->TabIndex = 2;
            this->rbManual->TabStop = true;
            this->rbManual->Text = L"Grafo manual";
            this->rbManual->Checked = true;
            // 
            // rbAleatorio
            // 
            this->rbAleatorio->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9, System::Drawing::FontStyle::Regular));
            this->rbAleatorio->Location = System::Drawing::Point(210, 80);
            this->rbAleatorio->Name = L"rbAleatorio";
            this->rbAleatorio->Size = System::Drawing::Size(180, 24);
            this->rbAleatorio->TabIndex = 3;
            this->rbAleatorio->Text = L"Grafo aleatorio";
            // 
            // btnCrear
            // 
            this->btnCrear->BackColor = System::Drawing::Color::FromArgb(30, 100, 180);
            this->btnCrear->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
            this->btnCrear->Font = (gcnew System::Drawing::Font(L"Segoe UI", 11, System::Drawing::FontStyle::Bold));
            this->btnCrear->ForeColor = System::Drawing::Color::White;
            this->btnCrear->Location = System::Drawing::Point(150, 320);
            this->btnCrear->Name = L"btnCrear";
            this->btnCrear->Size = System::Drawing::Size(200, 45);
            this->btnCrear->TabIndex = 3;
            this->btnCrear->Text = L"Crear grafo";
            this->btnCrear->UseVisualStyleBackColor = false;
            this->btnCrear->Click += gcnew System::EventHandler(this, &ConfiguracionForm::btnCrear_Click);
            // 
            // btnSalir
            // 
            this->btnSalir->Location = System::Drawing::Point(370, 320);
            this->btnSalir->Name = L"btnSalir";
            this->btnSalir->Size = System::Drawing::Size(200, 45);
            this->btnSalir->TabIndex = 4;
            this->btnSalir->Text = L"Salir";
            this->btnSalir->UseVisualStyleBackColor = true;
            this->btnSalir->Click += gcnew System::EventHandler(this, &ConfiguracionForm::btnSalir_Click);
            // 
            // ConfiguracionForm
            // 
            this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
            this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
            this->BackColor = System::Drawing::Color::FromArgb(245, 245, 245);
            this->ClientSize = System::Drawing::Size(720, 420);
            this->Controls->Add(this->lblTitulo);
            this->Controls->Add(this->lblSubtitulo);
            this->Controls->Add(this->gbConfig);
            this->Controls->Add(this->btnCrear);
            this->Controls->Add(this->btnSalir);
            this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
            this->MaximizeBox = false;
            this->Name = L"ConfiguracionForm";
            this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
            this->Text = L"Flujo Maximo - Configuracion";
            this->Load += gcnew System::EventHandler(this, &ConfiguracionForm::ConfiguracionForm_Load);
            this->gbConfig->ResumeLayout(false);
            (safe_cast<System::ComponentModel::ISupportInitialize^>(this->numVertices))->EndInit();
            this->ResumeLayout(false);
        }
#pragma endregion

    private:
        System::Void ConfiguracionForm_Load(System::Object^ sender, System::EventArgs^ e)
        {
            numVertices->Value = 7;
            rbManual->Checked = true;
        }

        System::Void btnCrear_Click(System::Object^ sender, System::EventArgs^ e)
        {
            int n = (int)numVertices->Value;
            EstadoGlobal::estado->esAleatorio = rbAleatorio->Checked;
            if (EstadoGlobal::estado->esAleatorio) {
                GeneradorGrafo^ gen = gcnew GeneradorGrafo();
                EstadoGlobal::estado->grafo = gen->generar(n);
                EstadoGlobal::estado->grafoValidado = true;
            }
            else {
                Grafo^ g = gcnew Grafo();
                for (int i = 0; i < n; i++) {
                    String^ nombre;
                    if (i < 26) { wchar_t c = L'A' + i; nombre = c.ToString(); }
                    else nombre = "V" + i;
                    g->agregarVertice(gcnew Vertice(i, nombre));
                }
                EstadoGlobal::estado->grafo = g;
                EstadoGlobal::estado->grafoValidado = false;
            }
            this->DialogResult = System::Windows::Forms::DialogResult::OK;
        }

        System::Void btnSalir_Click(System::Object^ sender, System::EventArgs^ e)
        {
            this->DialogResult = System::Windows::Forms::DialogResult::Cancel;
        }
    };

}
