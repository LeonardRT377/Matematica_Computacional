#pragma once
#include "Grafo.h"

using namespace System::Collections::Generic;

public ref class ValidadorGrafo {
private:
    bool dfs(int u, Dictionary<int, int>^ estado, Dictionary<int, List<int>^>^ adj,
        List<int>^ pila, List<int>^% ciclo) {
        estado[u] = 1;
        pila->Add(u);
        if (adj->ContainsKey(u)) {
            for each (int v in adj[u]) {
                if (!estado->ContainsKey(v)) estado[v] = 0;
                if (estado[v] == 0) {
                    if (dfs(v, estado, adj, pila, ciclo)) return true;
                }
                else if (estado[v] == 1) {
                    ciclo = gcnew List<int>();
                    bool grabar = false;
                    for each (int x in pila) {
                        if (x == v) grabar = true;
                        if (grabar) ciclo->Add(x);
                    }
                    ciclo->Add(v);
                    return true;
                }
            }
        }
        pila->RemoveAt(pila->Count - 1);
        estado[u] = 2;
        return false;
    }

public:
    ValidadorGrafo() {}
    ~ValidadorGrafo() {}

    bool tieneCiclos(Grafo^ grafo) { return obtenerCiclo(grafo) != nullptr; }

    List<int>^ obtenerCiclo(Grafo^ grafo) {
        if (grafo == nullptr) return nullptr;
        Dictionary<int, List<int>^>^ adj = gcnew Dictionary<int, List<int>^>();
        Dictionary<int, int>^ estado = gcnew Dictionary<int, int>();
        for each (Vertice^ v in grafo->getVertices()) { adj[v->getId()] = gcnew List<int>(); estado[v->getId()] = 0; }
        for each (Arista^ a in grafo->getAristas()) {
            int o = a->getOrigen()->getId();
            int d = a->getDestino()->getId();
            if (adj->ContainsKey(o)) adj[o]->Add(d);
        }
        for each (Vertice^ v in grafo->getVertices()) {
            int id = v->getId();
            if (estado[id] == 0) {
                List<int>^ pila = gcnew List<int>();
                List<int>^ ciclo = nullptr;
                if (dfs(id, estado, adj, pila, ciclo)) return ciclo;
            }
        }
        return nullptr;
    }

    String^ obtenerCicloTexto(Grafo^ grafo) {
        List<int>^ ciclo = obtenerCiclo(grafo);
        if (ciclo == nullptr) return "";
        Dictionary<int, String^>^ nombres = gcnew Dictionary<int, String^>();
        for each (Vertice^ v in grafo->getVertices()) nombres[v->getId()] = v->getNombre();
        String^ s = "";
        for (int i = 0; i < ciclo->Count; i++) {
            if (i > 0) s += " -> ";
            int id = ciclo[i];
            if (nombres->ContainsKey(id)) s += nombres[id];
            else s += id.ToString();
        }
        return s;
    }
};
