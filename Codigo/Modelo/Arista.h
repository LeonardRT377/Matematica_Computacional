#pragma once
#include "Vertice.h"

public ref class Arista {
private:
    int id;
    Vertice^ origen;
    Vertice^ destino;
    int capacidad;
    int flujo;

public:
    Arista(int id, Vertice^ origen, Vertice^ destino, int capacidad) {
        if (capacidad <= 0) throw gcnew ArgumentException("La capacidad debe ser mayor que 0");
        if (origen == nullptr || destino == nullptr) throw gcnew ArgumentException("Origen y destino no pueden ser null");
        this->id = id;
        this->origen = origen;
        this->destino = destino;
        this->capacidad = capacidad;
        this->flujo = 0;
    }

    Arista() {
        id = -1;
        origen = nullptr;
        destino = nullptr;
        capacidad = 0;
        flujo = 0;
    }

    ~Arista() {}

    int getId() { return id; }
    Vertice^ getOrigen() { return origen; }
    Vertice^ getDestino() { return destino; }
    int getCapacidad() { return capacidad; }
    int getFlujo() { return flujo; }
    int getCapacidadResidual() { return capacidad - flujo; }

    void aumentarFlujo(int cantidad) { flujo += cantidad; }
    void disminuirFlujo(int cantidad) { flujo -= cantidad; }
    void setFlujo(int nuevoFlujo) { flujo = nuevoFlujo; }

    String^ getDescripcion() {
        return origen->getNombre() + " -> " + destino->getNombre() + " (" + flujo + "/" + capacidad + ")";
    }
};
