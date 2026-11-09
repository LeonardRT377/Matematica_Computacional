#pragma once
#include "Grafo.h"

using namespace System::Collections::Generic;

public ref class TransformadorFlujo {
public:

    TransformadorFlujo() {}
    ~TransformadorFlujo() {}

    Grafo^ transformar(Grafo^ grafo, List<int>^ fuentes, List<int>^ sumideros, int% superFuenteId, int% superSumideroId) {
        superFuenteId = -1;
        superSumideroId = -1;
        if (grafo == nullptr) return nullptr;
        if (fuentes == nullptr) fuentes = gcnew List<int>();
        if (sumideros == nullptr) sumideros = gcnew List<int>();

        if (fuentes->Count == 0 || sumideros->Count == 0)
            throw gcnew ArgumentException("Seleccione al menos una fuente y un sumidero.");
        for each (int f in fuentes) {
            if (grafo->obtenerVertice(f) == nullptr || sumideros->Contains(f))
                throw gcnew ArgumentException("Fuente inexistente o tambien seleccionada como sumidero.");
        }
        for each (int t in sumideros)
            if (grafo->obtenerVertice(t) == nullptr)
                throw gcnew ArgumentException("Sumidero inexistente.");

        if (fuentes->Count == 1 && sumideros->Count == 1) {
            superFuenteId = fuentes[0];
            superSumideroId = sumideros[0];
            return grafo;
        }

        // Una cota estrictamente mayor al total de capacidades originales
        // evita que las conexiones artificiales limiten el flujo o el corte.
        Int64 capacidadSuper = 1;
        for each (Arista^ a in grafo->getAristas()) capacidadSuper += a->getCapacidad();
        if (capacidadSuper > Int32::MaxValue)
            throw gcnew OverflowException("El grafo supera el rango admitido para la transformacion.");
        int capacidadConexion = (int)capacidadSuper;

        Grafo^ nuevo = gcnew Grafo();
        for each (Vertice^ v in grafo->getVertices()) nuevo->agregarVertice(gcnew Vertice(v->getId(), v->getNombre()));
        for each (Arista^ a in grafo->getAristas())
            nuevo->agregarArista(gcnew Arista(a->getId(), nuevo->obtenerVertice(a->getOrigen()->getId()), nuevo->obtenerVertice(a->getDestino()->getId()), a->getCapacidad()));

        int maxId = -1;
        for each (Vertice^ v in nuevo->getVertices()) if (v->getId() > maxId) maxId = v->getId();

        if (fuentes->Count > 1) {
            int idSuper = maxId + 1;
            maxId++;
            nuevo->agregarVertice(gcnew Vertice(idSuper, "SUPER_FUENTE"));
            superFuenteId = idSuper;
            for each (int f in fuentes) nuevo->agregarArista(idSuper, f, capacidadConexion);
        }
        else if (fuentes->Count == 1) superFuenteId = fuentes[0];

        if (sumideros->Count > 1) {
            int idSuper = maxId + 1;
            nuevo->agregarVertice(gcnew Vertice(idSuper, "SUPER_SUMIDERO"));
            superSumideroId = idSuper;
            for each (int t in sumideros) nuevo->agregarArista(t, idSuper, capacidadConexion);
        }
        else if (sumideros->Count == 1) superSumideroId = sumideros[0];

        return nuevo;
    }

    bool esVerticeFicticio(Vertice^ v) {
        if (v == nullptr) return false;
        String^ n = v->getNombre();
        return n == "SUPER_FUENTE" || n == "SUPER_SUMIDERO";
    }
};
