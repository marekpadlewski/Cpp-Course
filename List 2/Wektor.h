#ifndef LISTA_2_WEKTOR_H
#define LISTA_2_WEKTOR_H


class Wektor {
public:
    const double dx = 0;
    const double dy = 0;
    Wektor() = default;
    Wektor(double x1, double y1);
    Wektor (const Wektor &wektor);
    Wektor & operator=(const Wektor &) = delete;
};

Wektor *zlozenie(Wektor u, Wektor v);

#endif //LISTA_2_WEKTOR_H
