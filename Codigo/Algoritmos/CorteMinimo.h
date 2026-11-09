#pragma once
#include "Grafo.h"
#include "ResultadoCorte.h"
#include "AristaResidual.h"

using namespace System::Collections::Generic;

public ref class CorteMinimo {
private:
    List<AristaResidual^>^ construirRedResidual(Grafo^ grafo, Dictionary<int, int>^ flujos) {
        List<AristaResidual^>^ res = gcnew List<AristaResidual^>();
        for each (Arista^ a in grafo->getAristas()) {
            int id = a->getId();
            int o = a->getOrigen()->getId();
            int d = a->getDestino()->getId();
            int cap = a->getCapacidad();
            int fl = 0;
            if (flujos->ContainsKey(id)) fl = flujos[id];
            if (cap - fl > 0) res->Add(gcnew AristaResidual(o, d, cap - fl, false, id));
            if (fl > 0) res->Add(gcnew AristaResidual(d, o, fl, true, id));
        }
        return res;
    }

public:
    CorteMinimo() {}
    ~CorteMinimo() {}

    ResultadoCorte^ calcular(Grafo^ grafo, int fuente, int sumidero, Dictionary<int, int>^ flujosFinales) {
        if (grafo == nullptr || flujosFinales == nullptr)
            throw gcnew ArgumentException("Grafo y flujos no pueden ser null.");
        if (fuente == sumidero || grafo->obtenerVertice(fuente) == nullptr || grafo->obtenerVertice(sumidero) == nullptr)
            throw gcnew ArgumentException("Fuente o sumidero invalidos.");
        List<AristaResidual^>^ residual = construirRedResidual(grafo, flujosFinales);

        Dictionary<int, List<AristaResidual^>^>^ adj = gcnew Dictionary<int, List<AristaResidual^>^>();
        for each (Vertice^ v in grafo->getVertices()) adj[v->getId()] = gcnew List<AristaResidual^>();
        for each (AristaResidual^ r in residual) {
            int o = r->getIdOrigen();
            if (adj->ContainsKey(o)) adj[o]->Add(r);
        }

        Dictionary<int, bool>^ visitado = gcnew Dictionary<int, bool>();
        for each (Vertice^ v in grafo->getVertices()) visitado[v->getId()] = false;
        System::Collections::Generic::Queue<int>^ q = gcnew System::Collections::Generic::Queue<int>();
        q->Enqueue(fuente);
        visitado[fuente] = true;
        while (q->Count > 0) {
            int u = q->Dequeue();
            if (!adj->ContainsKey(u)) continue;
            for each (AristaResidual^ r in adj[u]) {
                int v = r->getIdDestino();
                if (!visitado->ContainsKey(v)) visitado[v] = false;
                if (!visitado[v] && r->getCapacidadResidual() > 0) { visitado[v] = true; q->Enqueue(v); }
            }
        }

        if (visitado[sumidero])
            throw gcnew InvalidOperationException("El corte minimo requiere un flujo maximo: aun existe un camino aumentante.");

        List<int>^ conjuntoS = gcnew List<int>();
        List<int>^ conjuntoT = gcnew List<int>();
        for each (Vertice^ v in grafo->getVertices()) {
            if (visitado[v->getId()]) conjuntoS->Add(v->getId());
            else conjuntoT->Add(v->getId());
        }

        List<Arista^>^ aristasCorte = gcnew List<Arista^>();
        int capTotal = 0;
        Dictionary<int, bool>^ enS = gcnew Dictionary<int, bool>();
        for each (int id in conjuntoS) enS[id] = true;
        for each (Arista^ a in grafo->getAristas()) {
            bool oEnS = enS->ContainsKey(a->getOrigen()->getId()) && enS[a->getOrigen()->getId()];
            bool dEnS = enS->ContainsKey(a->getDestino()->getId()) && enS[a->getDestino()->getId()];
            if (oEnS && !dEnS) {
                if (capTotal > Int32::MaxValue - a->getCapacidad())
                    throw gcnew OverflowException("La capacidad del corte supera el rango de Int32.");
                aristasCorte->Add(a); capTotal += a->getCapacidad();
            }
        }

        return gcnew ResultadoCorte(conjuntoS, conjuntoT, aristasCorte, capTotal);
    }
};
