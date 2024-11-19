#include "Mapa.h"
#include <QDebug>

Mapa::Mapa(int filas, int columnas) : filas(filas), columnas(columnas) {
    // Inicializar el vector bidimensional con nullptr
    tablero.resize(filas, std::vector<Calle*>(columnas, nullptr));
}

Mapa::~Mapa() {
    // Liberar la memoria de los nodos
    for (int fila = 0; fila < filas; ++fila) {
        for (int col = 0; col < columnas; ++col) {
            delete tablero[fila][col];
        }
    }
}

void Mapa::inicializarTablero() {
    for (int fila = 0; fila < filas; ++fila) {
        for (int col = 0; col < columnas; ++col) {
            if ((fila == 0 || fila == filas - 1) && (col == 0 || col == columnas - 1)) {
                // Esquinas
                tablero[fila][col] = new CalleSimple();
            } else if (fila == 0 || fila == filas - 1 || col == 0 || col == columnas - 1) {
                // Intersecciones en T (bordes)
                tablero[fila][col] = new CalleT();
            } else {
                // Intersecciones normales
                tablero[fila][col] = new CalleInter();
            }
        }
    }
}

Calle* Mapa::obtenerNodo(int fila, int columna) {
    if (fila < 0 || fila >= filas || columna < 0 || columna >= columnas) {
        qDebug() << "Coordenadas fuera de rango: (" << fila << "," << columna << ")";
        return nullptr;
    }
    return tablero[fila][columna];
}

void Mapa::imprimirTablero() {
    for (int fila = 0; fila < filas; ++fila) {
        QString linea;
        for (int col = 0; col < columnas; ++col) {
            if (dynamic_cast<CalleSimple*>(tablero[fila][col])) {
                linea += "S "; // Esquina
            } else if (dynamic_cast<CalleT*>(tablero[fila][col])) {
                linea += "T "; // Intersección en T
            } else if (dynamic_cast<CalleInter*>(tablero[fila][col])) {
                linea += "I "; // Intersección normal
            } else {
                linea += "X "; // Espacio no inicializado
            }
        }
        qDebug() << linea;
    }
}
