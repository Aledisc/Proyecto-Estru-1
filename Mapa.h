#ifndef MAPA_H
#define MAPA_H

#include <vector>
#include "Calle.h"
#include "CalleSimple.h"
#include "CalleInter.h"
#include "callet.h"


class Mapa
{
private:
    //representacion del grafo bidimensional mediante un tablero de vectores, inicializado en 4x4
    std::vector<std::vector<Calle*>> tablero;
    int filas;
    int columnas;


public:
    Mapa(int filas, int columnas);
    ~Mapa();

    void inicializarTablero(); // Inicializa el tablero con nodos basados en la imagen
    Calle* obtenerNodo(int fila, int columna); // Devuelve el nodo en la posición dada
    void imprimirTablero();
};

#endif // MAPA_H
