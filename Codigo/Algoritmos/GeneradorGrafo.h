#pragma once
#include "Grafo.h"

public ref class GeneradorGrafo {
public:
    GeneradorGrafo() {}
    ~GeneradorGrafo() {}

    Grafo^ generar(int n) {
        if (n < 7) n = 7;
        if (n > 16) n = 16;
        Grafo^ g = gcnew Grafo();
        Random^ rnd = gcnew Random();

        for (int i = 0; i < n; i++) {
            String^ nombre = "";
            if (i < 26) { wchar_t c = L'A' + i; nombre = c.ToString(); }
            else nombre = "V" + i;
            g->agregarVertice(gcnew Vertice(i, nombre));
        }

        // Cadena obligatoria 0->1->...->n-1 para garantizar flujo
        for (int i = 0; i < n - 1; i++) g->agregarArista(i, i + 1, rnd->Next(4, 16));

        // Aristas aleatorias adicionales solo hacia adelante (DAG)
        for (int i = 0; i < n; i++) {
            for (int j = i + 2; j < n; j++) {
                if (rnd->NextDouble() < 0.30) {
                    if (!g->existeArista(i, j)) g->agregarArista(i, j, rnd->Next(2, 21));
                }
            }
        }

        return g;
    }
};
