#pragma once
#include "Grafo.h"
#include "PasoAlgoritmo.h"
#include "AristaResidual.h"

using namespace System::Collections::Generic;

public ref class FordFulkerson {
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
            int directa = cap - fl;
            int inversa = fl;
            if (directa > 0) res->Add(gcnew AristaResidual(o, d, directa, false, id));
            if (inversa > 0) res->Add(gcnew AristaResidual(d, o, inversa, true, id));
        }
        return res;
    }

    List<AristaResidual^>^ buscarCamino(Grafo^ grafo, int fuente, int sumidero, Dictionary<int, int>^ flujos) {
        List<AristaResidual^>^ residual = construirRedResidual(grafo, flujos);

        Dictionary<int, List<AristaResidual^>^>^ adj = gcnew Dictionary<int, List<AristaResidual^>^>();
        for each (Vertice^ v in grafo->getVertices()) adj[v->getId()] = gcnew List<AristaResidual^>();
        for each (AristaResidual^ r in residual) {
            int o = r->getIdOrigen();
            if (adj->ContainsKey(o)) adj[o]->Add(r);
        }

        Dictionary<int, bool>^ visitado = gcnew Dictionary<int, bool>();
        Dictionary<int, AristaResidual^>^ padre = gcnew Dictionary<int, AristaResidual^>();
        Dictionary<int, int>^ padreNodo = gcnew Dictionary<int, int>();
        for each (Vertice^ v in grafo->getVertices()) visitado[v->getId()] = false;

        System::Collections::Generic::Queue<int>^ q = gcnew System::Collections::Generic::Queue<int>();
        q->Enqueue(fuente);
        visitado[fuente] = true;

        while (q->Count > 0) {
            int u = q->Dequeue();
            if (u == sumidero) break;
            if (!adj->ContainsKey(u)) continue;
            for each (AristaResidual^ r in adj[u]) {
                int v = r->getIdDestino();
                if (!visitado->ContainsKey(v)) visitado[v] = false;
                if (!visitado[v] && r->getCapacidadResidual() > 0) {
                    visitado[v] = true;
                    padre[v] = r;
                    padreNodo[v] = u;
                    q->Enqueue(v);
                }
            }
        }

        if (!visitado->ContainsKey(sumidero) || !visitado[sumidero]) return nullptr;

        List<AristaResidual^>^ camino = gcnew List<AristaResidual^>();
        int cur = sumidero;
        while (cur != fuente) {
            AristaResidual^ r = padre[cur];
            camino->Insert(0, r);
            cur = padreNodo[cur];
        }
        return camino;
    }

public:
    FordFulkerson() {}
    ~FordFulkerson() {}

    List<PasoAlgoritmo^>^ ejecutar(Grafo^ grafo, int fuente, int sumidero) {
        if (grafo == nullptr) throw gcnew ArgumentException("Grafo no puede ser null");
        if (fuente == sumidero) throw gcnew ArgumentException("Fuente y sumidero no pueden ser iguales");
        if (grafo->obtenerVertice(fuente) == nullptr) throw gcnew ArgumentException("Fuente no existe");
        if (grafo->obtenerVertice(sumidero) == nullptr) throw gcnew ArgumentException("Sumidero no existe");

        Dictionary<int, int>^ flujos = gcnew Dictionary<int, int>();
        for each (Arista^ a in grafo->getAristas()) flujos[a->getId()] = 0;

        List<PasoAlgoritmo^>^ pasos = gcnew List<PasoAlgoritmo^>();
        int flujoTotal = 0;
        int iter = 1;

        while (true) {
            List<AristaResidual^>^ caminoRes = buscarCamino(grafo, fuente, sumidero, flujos);
            if (caminoRes == nullptr || caminoRes->Count == 0) {
                List<int>^ caminoVacio = gcnew List<int>();
                List<AristaResidual^>^ caminoResVacio = gcnew List<AristaResidual^>();
                Dictionary<int, int>^ copiaFlujos = gcnew Dictionary<int, int>(flujos);
                List<AristaResidual^>^ red = construirRedResidual(grafo, flujos);
                pasos->Add(gcnew PasoAlgoritmo(iter, caminoVacio, caminoResVacio, 0, 0, flujoTotal, copiaFlujos, red, true));
                break;
            }

            int botella = Int32::MaxValue;
            for each (AristaResidual^ r in caminoRes) if (r->getCapacidadResidual() < botella) botella = r->getCapacidadResidual();

            List<int>^ caminoVertices = gcnew List<int>();
            caminoVertices->Add(fuente);
            for each (AristaResidual^ r in caminoRes) caminoVertices->Add(r->getIdDestino());

            if (flujoTotal > Int32::MaxValue - botella)
                throw gcnew OverflowException("El flujo total supera el rango de Int32.");
            List<AristaResidual^>^ redAnterior = construirRedResidual(grafo, flujos);
            for each (AristaResidual^ r in caminoRes) {
                int idArista = r->getIdAristaOriginal();
                if (r->getEsInversa()) flujos[idArista] = flujos[idArista] - botella;
                else flujos[idArista] = flujos[idArista] + botella;
            }
            flujoTotal += botella;

            Dictionary<int, int>^ copiaFlujos = gcnew Dictionary<int, int>(flujos);
            List<AristaResidual^>^ red = construirRedResidual(grafo, flujos);
            List<AristaResidual^>^ copiaCaminoRes = gcnew List<AristaResidual^>();
            for each (AristaResidual^ r in caminoRes)
                copiaCaminoRes->Add(gcnew AristaResidual(r->getIdOrigen(), r->getIdDestino(), r->getCapacidadResidual(), r->getEsInversa(), r->getIdAristaOriginal()));

            pasos->Add(gcnew PasoAlgoritmo(iter, caminoVertices, copiaCaminoRes, botella, botella, flujoTotal, copiaFlujos, red, false));
            pasos[pasos->Count - 1]->setRedResidualAnterior(redAnterior);
            iter++;
        }

        return pasos;
    }
};
