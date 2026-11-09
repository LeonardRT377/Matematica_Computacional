#pragma once

using namespace System;

public ref class Vertice {
private:
    int id;
    String^ nombre;

public:
    Vertice(int id, String^ nombre) {
        this->id = id;
        this->nombre = nombre;
    }

    Vertice() {
        id = -1;
        nombre = "";
    }

    ~Vertice() {}

    int getId() { return id; }
    String^ getNombre() { return nombre; }
    void setNombre(String^ nombre) { this->nombre = nombre; }

    virtual String^ ToString() override { return nombre; }
};
