#pragma once
// Umbrella de la capa logica (modelo + algoritmos + estado).
// Los formularios lo incluyen para poder definir sus metodos inline,
// tal como los genera el disenador de Visual Studio, sin exponer cada
// header por separado.

#include "AppState.h"
#include "ValidadorGrafo.h"
#include "GeneradorGrafo.h"
#include "FordFulkerson.h"
#include "CorteMinimo.h"
#include "TransformadorFlujo.h"
