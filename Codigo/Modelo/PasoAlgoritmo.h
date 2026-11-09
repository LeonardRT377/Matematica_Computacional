#pragma once
#include "AristaResidual.h"

using namespace System::Collections::Generic;

public ref class PasoAlgoritmo {
private:
    int numeroIteracion;
    List<int>^ camino;
    List<AristaResidual^>^ caminoResidual;
    int capacidadAumentante;
    int flujoAgregado;
    int flujoTotal;
    Dictionary<int, int>^ flujosAristas;
    List<AristaResidual^>^ redResidual;
    List<AristaResidual^>^ redResidualAnterior;
    bool esFinal;

public:
    PasoAlgoritmo(int numeroIteracion, List<int>^ camino, List<AristaResidual^>^ caminoResidual,
        int capacidadAumentante, int flujoAgregado, int flujoTotal,
        Dictionary<int, int>^ flujosAristas, List<AristaResidual^>^ redResidual, bool esFinal) {
        this->numeroIteracion = numeroIteracion;
        this->camino = camino;
        this->caminoResidual = caminoResidual;
        this->capacidadAumentante = capacidadAumentante;
        this->flujoAgregado = flujoAgregado;
        this->flujoTotal = flujoTotal;
        this->flujosAristas = flujosAristas;
        this->redResidual = redResidual;
        this->redResidualAnterior = redResidual;
        this->esFinal = esFinal;
    }

    PasoAlgoritmo() {
        numeroIteracion = 0;
        camino = gcnew List<int>();
        caminoResidual = gcnew List<AristaResidual^>();
        capacidadAumentante = 0;
        flujoAgregado = 0;
        flujoTotal = 0;
        flujosAristas = gcnew Dictionary<int, int>();
        redResidual = gcnew List<AristaResidual^>();
        redResidualAnterior = redResidual;
        esFinal = false;
    }

    ~PasoAlgoritmo() {}

    int getNumeroIteracion() { return numeroIteracion; }
    List<int>^ getCamino() { return camino; }
    List<AristaResidual^>^ getCaminoResidual() { return caminoResidual; }
    int getCapacidadAumentante() { return capacidadAumentante; }
    int getFlujoAgregado() { return flujoAgregado; }
    int getFlujoTotal() { return flujoTotal; }
    Dictionary<int, int>^ getFlujosAristas() { return flujosAristas; }
    List<AristaResidual^>^ getRedResidual() { return redResidual; }
    List<AristaResidual^>^ getRedResidualAnterior() { return redResidualAnterior; }
    void setRedResidualAnterior(List<AristaResidual^>^ red) { redResidualAnterior = red; }
    bool getEsFinal() { return esFinal; }

    String^ getCaminoTexto() {
        if (camino->Count == 0) return "(sin camino)";
        String^ s = "";
        for (int i = 0; i < camino->Count; i++) { if (i > 0) s += " -> "; s += camino[i].ToString(); }
        return s;
    }

    String^ getCaminoTextoConNombres(Dictionary<int, String^>^ nombres) {
        if (camino->Count == 0) return "(sin camino)";
        String^ s = "";
        for (int i = 0; i < camino->Count; i++) {
            if (i > 0) s += " -> ";
            int id = camino[i];
            if (nombres != nullptr && nombres->ContainsKey(id)) s += nombres[id];
            else s += id.ToString();
        }
        return s;
    }
};
