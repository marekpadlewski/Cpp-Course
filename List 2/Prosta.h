#ifndef LISTA_2_PROSTA_H
#define LISTA_2_PROSTA_H

#include "Punkt.h"

class Prosta {
private:
    double A;
    double B;
    double C;

public:
    Prosta() = default;
    Prosta(Punkt a, Punkt b);
    Prosta(Wektor v);
    Prosta(double A, double B, double C);
    Prosta(Prosta y, Wektor v);
    Prosta & operator=(const Prosta &) = delete;

    const bool czyWektorProstopadly(Wektor v, Prosta y);
    const bool czyWektorRownolegly(Wektor v, Prosta y);
    const bool czyPunktNaProstej(Punkt a, Prosta y);
    const void normalizacjaProstej();

    const double get_A();
    const double get_B();
    const double get_C();
};

bool czyProsteProstopadle(Prosta y, Prosta z);
bool czyProsteRownolegle(Prosta y, Prosta z);
Punkt *punktPrzeciecia(Prosta y, Prosta z);

#endif //LISTA_2_PROSTA_H
