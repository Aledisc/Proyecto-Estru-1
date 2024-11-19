#include "CalleT.h"

CalleT::CalleT() : conex1(nullptr), conex2(nullptr), conex3(nullptr) {}

CalleT::~CalleT() {}

int CalleT::getNumeroConexiones() const {
    return 3; // Intersección en T tiene 3 conexiones
}

void CalleT::setConexiones(Calle* c1, Calle* c2, Calle* c3) {
    conex1 = c1;
    conex2 = c2;
    conex3 = c3;
}
