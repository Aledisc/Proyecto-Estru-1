#ifndef CALLET_H
#define CALLET_H

#include "Calle.h"

//Clase de la calle que es interseccion en T
class CalleT : public Calle
{
private:
    Calle* conex1;
    Calle* conex2;//calle externa que conecta
    Calle* conex3;
public:
    CalleT();
    ~CalleT();

    int getNumeroConexiones() const override;
    void setConexiones(Calle* c1, Calle* c2, Calle* c3); // Configurar conexiones
};

#endif // CALLET_H
