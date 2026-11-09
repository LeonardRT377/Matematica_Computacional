// MateComputacional.cpp
// Punto de entrada del asistente (wizard) entre formularios.
//
// Cada formulario (UI/*.h) define sus metodos INLINE en su propio header,
// tal como los genera el disenador de Visual Studio. Esto es un requisito
// del parser CodeDOM del disenador de C++/CLI: los metodos del form deben
// estar definidos en el header, no en una unidad .cpp aparte.
//
// La logica matematica vive en Modelo/ y Algoritmos/ y NO depende de
// Windows Forms (se incluye via Controlador/Logica.h, solo como detalle
// de compilacion de los forms).

#include "ConfiguracionForm.h"
#include "EditorGrafoForm.h"
#include "SeleccionForm.h"
#include "EjecucionForm.h"
#include "ResultadoForm.h"

using namespace System;
using namespace System::Windows::Forms;

[STAThreadAttribute]
int main(array<String^>^ args)
{
    Application::EnableVisualStyles();
    Application::SetCompatibleTextRenderingDefault(false);

    EstadoGlobal::estado = gcnew AppState();

    int paso = 0; // 0=config 1=editor 2=seleccion 3=ejecucion 4=resultado
    while (paso >= 0) {
        if (paso == 0) {
            MateComputacional::ConfiguracionForm^ f = gcnew MateComputacional::ConfiguracionForm();
            System::Windows::Forms::DialogResult r = f->ShowDialog();
            if (r == System::Windows::Forms::DialogResult::OK) paso = EstadoGlobal::estado->esAleatorio ? 2 : 1;
            else paso = -1;
        }
        else if (paso == 1) {
            MateComputacional::EditorGrafoForm^ f = gcnew MateComputacional::EditorGrafoForm();
            System::Windows::Forms::DialogResult r = f->ShowDialog();
            if (r == System::Windows::Forms::DialogResult::OK) paso = 2;
            else paso = 0;
        }
        else if (paso == 2) {
            MateComputacional::SeleccionForm^ f = gcnew MateComputacional::SeleccionForm();
            System::Windows::Forms::DialogResult r = f->ShowDialog();
            if (r == System::Windows::Forms::DialogResult::OK) paso = 3;
            else paso = EstadoGlobal::estado->esAleatorio ? 0 : 1;
        }
        else if (paso == 3) {
            MateComputacional::EjecucionForm^ f = gcnew MateComputacional::EjecucionForm();
            System::Windows::Forms::DialogResult r = f->ShowDialog();
            if (r == System::Windows::Forms::DialogResult::OK) paso = 4;
            else if (r == System::Windows::Forms::DialogResult::Retry) { EstadoGlobal::estado = gcnew AppState(); paso = 0; }
            else paso = 2;
        }
        else if (paso == 4) {
            MateComputacional::ResultadoForm^ f = gcnew MateComputacional::ResultadoForm();
            System::Windows::Forms::DialogResult r = f->ShowDialog();
            if (r == System::Windows::Forms::DialogResult::Retry) { EstadoGlobal::estado = gcnew AppState(); paso = 0; }
            else if (r == System::Windows::Forms::DialogResult::Cancel) paso = 3;
            else paso = -1;
        }
    }

    return 0;
}
