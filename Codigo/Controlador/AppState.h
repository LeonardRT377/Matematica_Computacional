#pragma once
#include "Vertice.h"
#include "Arista.h"
#include "AristaResidual.h"
#include "Grafo.h"
#include "PasoAlgoritmo.h"
#include "ResultadoCorte.h"
#include "GrafoVisual.h"

using namespace System::Collections::Generic;

/// <summary>
/// Estado compartido de la aplicacion (modelo + resultados del algoritmo).
/// No conoce Windows Forms: es el puente entre la UI y la logica.
/// </summary>
public ref class AppState {
public:
    Grafo^ grafo;
    Grafo^ grafoTransformado;
    GrafoVisual^ grafoVisual;
    List<PasoAlgoritmo^>^ pasos;
    int pasoActual;
    ResultadoCorte^ corte;
    bool grafoValidado;
    bool esAleatorio;
    int superFuenteId;
    int superSumideroId;
    int fuenteEfectiva;
    int sumideroEfectivo;

    AppState() {
        grafo = nullptr;
        grafoTransformado = nullptr;
        grafoVisual = gcnew GrafoVisual();
        pasos = nullptr;
        pasoActual = 0;
        corte = nullptr;
        grafoValidado = false;
        esAleatorio = false;
        superFuenteId = -1;
        superSumideroId = -1;
        fuenteEfectiva = -1;
        sumideroEfectivo = -1;
    }

    Dictionary<int, String^>^ nombres(Grafo^ g) {
        Dictionary<int, String^>^ m = gcnew Dictionary<int, String^>();
        if (g != nullptr) for each (Vertice^ v in g->getVertices()) m[v->getId()] = v->getNombre();
        return m;
    }
};

/// <summary>
/// Punto de acceso al estado compartido. Es una ref class porque un
/// campo static de tipo administrado no puede vivir en una variable
/// global/estatica nativa (error C3145).
/// </summary>
public ref class EstadoGlobal abstract sealed {
public:
    static AppState^ estado;
};
