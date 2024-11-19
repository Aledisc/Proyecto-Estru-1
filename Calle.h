#ifndef CALLE_H
#define CALLE_H


#include <queue>
#include "Vehiculo.h"

class Calle {
protected:
    std::queue<Vehiculo> cola1; // Cola para gestionar tráfico en un sentido
    std::queue<Vehiculo> cola2;

public:
    Calle() = default; // Constructor por defecto
    virtual ~Calle() = default; // Destructor virtual

    virtual int getNumeroConexiones() const = 0; // Método virtual puro
};

#endif // CALLE_H
