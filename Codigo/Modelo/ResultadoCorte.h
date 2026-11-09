#pragma once
#include "Arista.h"

using namespace System::Collections::Generic;

public ref class ResultadoCorte {
private:
    List<int>^ conjuntoS;
    List<int>^ conjuntoT;
    List<Arista^>^ aristasCorte;
    int capacidadTotal;

public:
    ResultadoCorte(List<int>^ conjuntoS, List<int>^ conjuntoT, List<Arista^>^ aristasCorte, int capacidadTotal) {
        this->conjuntoS = conjuntoS;
        this->conjuntoT = conjuntoT;
        this->aristasCorte = aristasCorte;
        this->capacidadTotal = capacidadTotal;
    }

    ResultadoCorte() {
        conjuntoS = gcnew List<int>();
        conjuntoT = gcnew List<int>();
        aristasCorte = gcnew List<Arista^>();
        capacidadTotal = 0;
    }

    ~ResultadoCorte() {}

    List<int>^ getConjuntoS() { return conjuntoS; }
    List<int>^ getConjuntoT() { return conjuntoT; }
    List<Arista^>^ getAristasCorte() { return aristasCorte; }
    int getCapacidadTotal() { return capacidadTotal; }

    bool coincideConFlujo(int flujoMaximo) { return capacidadTotal == flujoMaximo; }

    String^ getDescripcionS(Dictionary<int, String^>^ nombres) {
        String^ s = "{";
        for (int i = 0; i < conjuntoS->Count; i++) {
            if (i > 0) s += ", ";
            int id = conjuntoS[i];
            if (nombres != nullptr && nombres->ContainsKey(id)) s += nombres[id];
            else s += id.ToString();
        }
        return s + "}";
    }

    String^ getDescripcionT(Dictionary<int, String^>^ nombres) {
        String^ s = "{";
        for (int i = 0; i < conjuntoT->Count; i++) {
            if (i > 0) s += ", ";
            int id = conjuntoT[i];
            if (nombres != nullptr && nombres->ContainsKey(id)) s += nombres[id];
            else s += id.ToString();
        }
        return s + "}";
    }
};
