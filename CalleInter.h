#ifndef CALLEINTER_H
#define CALLEINTER_H

#include "Calle.h"

class CalleInter : public Calle
{
private:
    Calle* conex1; //derecha
    Calle* conex2; //izquierda
    Calle* conex3; //norte
    Calle* conex4; //sur
public:
    CalleInter();
    ~CalleInter();

    int getNumeroConexiones() const override;
    void setConexiones(Calle* c1, Calle* c2, Calle* c3, Calle* c4); // Configurar conexiones
};

#endif // CALLEINTER_H
