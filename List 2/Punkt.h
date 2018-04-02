#ifndef LISTA_2_PUNKT_H
#define LISTA_2_PUNKT_H


#include "Wektor.h"

class Punkt {
public:
    const double x = 0;
    const double y = 0;

    Punkt() = default;
    Punkt(double x, double y);
    Punkt(Wektor v, Punkt p);
    Punkt(const Punkt &punkt);
    Punkt & operator=(const Punkt &) = delete;
};


#endif //LISTA_2_PUNKT_H
