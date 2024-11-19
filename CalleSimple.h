#ifndef CALLESIMPLE_H
#define CALLESIMPLE_H

#include "Calle.h"

class CalleSimple : public Calle{
public:
    CalleSimple() : Calle() {}
    ~CalleSimple() override = default;

    int getNumeroConexiones() const override {
        return 2; //las calles simples tienen solamente 2 conexiones
    }
};

#endif // CALLESIMPLE_H
