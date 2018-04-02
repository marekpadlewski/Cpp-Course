#include "Wektor.h"

Wektor::Wektor(double x1, double y1) : dx(x1), dy(y1) {
}

Wektor::Wektor(const Wektor &wektor) : dx(wektor.dx), dy(wektor.dy){
}

Wektor *zlozenie(Wektor u, Wektor v) {
    return new Wektor(u.dx + v.dx, u.dy + v.dy);
}