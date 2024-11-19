#include "CalleInter.h"

CalleInter::CalleInter() :conex1(nullptr), conex2(nullptr), conex3(nullptr), conex4(nullptr) {}

CalleInter::~CalleInter() {}

int CalleInter::getNumeroConexiones() const {
    return 4; //tiene 4 conexiones por ser una interseccion
}

void CalleInter::setConexiones(Calle* c1, Calle* c2, Calle* c3, Calle* c4){
    conex1 = c1;
    conex2 = c2;
    conex3 = c3;
    conex4 = c4;
}
