#pragma once

using namespace System;

public ref class AristaResidual {
private:
    int idOrigen;
    int idDestino;
    int capacidadResidual;
    bool esInversa;
    int idAristaOriginal;

public:
    AristaResidual(int idOrigen, int idDestino, int capacidadResidual, bool esInversa, int idAristaOriginal) {
        this->idOrigen = idOrigen;
        this->idDestino = idDestino;
        this->capacidadResidual = capacidadResidual;
        this->esInversa = esInversa;
        this->idAristaOriginal = idAristaOriginal;
    }

    AristaResidual() {
        idOrigen = -1;
        idDestino = -1;
        capacidadResidual = 0;
        esInversa = false;
        idAristaOriginal = -1;
    }

    ~AristaResidual() {}

    int getIdOrigen() { return idOrigen; }
    int getIdDestino() { return idDestino; }
    int getCapacidadResidual() { return capacidadResidual; }
    bool getEsInversa() { return esInversa; }
    int getIdAristaOriginal() { return idAristaOriginal; }

    String^ getDescripcion() {
        String^ tipo = esInversa ? " (inv)" : "";
        return idOrigen + " -> " + idDestino + " [" + capacidadResidual + "]" + tipo;
    }
};
