#pragma once
#include "Vertice.h"
#include "Arista.h"

using namespace System::Collections::Generic;

public ref class Grafo {
private:
    List<Vertice^>^ vertices;
    List<Arista^>^ aristas;
    int siguienteIdArista;

public:
    Grafo() {
        vertices = gcnew List<Vertice^>();
        aristas = gcnew List<Arista^>();
        siguienteIdArista = 1;
    }

    ~Grafo() {}

    void agregarVertice(Vertice^ vertice) { vertices->Add(vertice); }

    void agregarArista(Arista^ arista) {
        aristas->Add(arista);
        if (arista->getId() >= siguienteIdArista) siguienteIdArista = arista->getId() + 1;
    }

    Arista^ agregarArista(int idOrigen, int idDestino, int capacidad) {
        Vertice^ o = obtenerVertice(idOrigen);
        Vertice^ d = obtenerVertice(idDestino);
        if (o == nullptr || d == nullptr) throw gcnew ArgumentException("Vertice origen o destino no existe");
        if (idOrigen == idDestino) throw gcnew ArgumentException("Origen y destino no pueden ser iguales");
        Arista^ a = gcnew Arista(siguienteIdArista, o, d, capacidad);
        aristas->Add(a);
        siguienteIdArista++;
        return a;
    }

    List<Vertice^>^ getVertices() { return vertices; }
    List<Arista^>^ getAristas() { return aristas; }

    Vertice^ obtenerVertice(int id) {
        for each (Vertice^ v in vertices) if (v->getId() == id) return v;
        return nullptr;
    }

    Arista^ obtenerArista(int id) {
        for each (Arista^ a in aristas) if (a->getId() == id) return a;
        return nullptr;
    }

    bool existeArista(int idOrigen, int idDestino) {
        for each (Arista^ a in aristas)
            if (a->getOrigen()->getId() == idOrigen && a->getDestino()->getId() == idDestino) return true;
        return false;
    }

    void eliminarArista(int id) {
        for (int i = 0; i < aristas->Count; i++) if (aristas[i]->getId() == id) { aristas->RemoveAt(i); return; }
    }

    void eliminarArista(Arista^ arista) { aristas->Remove(arista); }

    void limpiar() { vertices->Clear(); aristas->Clear(); siguienteIdArista = 1; }

    int getSiguienteIdArista() { return siguienteIdArista; }
    int getCantidadVertices() { return vertices->Count; }
    int getCantidadAristas() { return aristas->Count; }
};
