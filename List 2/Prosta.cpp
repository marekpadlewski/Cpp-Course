#include "Prosta.h"
#include <iostream>
#include <cmath>

Prosta::Prosta(Punkt a, Punkt b) {
    A = b.y - a.y;
    B = a.x - b.x;
    C = b.x*a.y - a.x*b.y;

    normalizacjaProstej();
}

Prosta::Prosta(Wektor v) {
    A = v.dx;
    B = v.dy;
    C = -A*A -B*B;

    normalizacjaProstej();
}

Prosta::Prosta(double A, double B, double C) {
    if (A == 0 && B == 0)
        throw std::invalid_argument("Oba współczynniki A i B nie mogą być zerami!");
    else{
        this->A = A;
        this->B = B;
        this->C = C;

        normalizacjaProstej();
    }
}

Prosta::Prosta(Prosta y, Wektor v) {
    this->A = y.A + v.dy;
    this->B = -(-y.B + v.dx);
    this->C = y.C;

    normalizacjaProstej();
}


const bool Prosta::czyWektorProstopadly(Wektor v, Prosta y) {

    return v.dx * y.A == v.dy * y.B;
}

const bool Prosta::czyWektorRownolegly(Wektor v, Prosta y){

    return v.dx * y.A ==  v.dy * -y.B;
}

const bool Prosta::czyPunktNaProstej(Punkt a, Prosta y){

    return y.A*a.x + y.B*a.y + y.C == 0;
}

const void Prosta::normalizacjaProstej() {
    double expr = sqrt(A*A + B*B);
    A = A/expr;
    B = B/expr;
    C = C/expr;

}

const double Prosta::get_A() {
    return A;
}

const double Prosta::get_B() {
    return B;
}

const double Prosta::get_C(){
    return C;
}

bool czyProsteProstopadle(Prosta y, Prosta z){

    return y.get_A() * z.get_B() == -y.get_B() * z.get_B();

}

bool czyProsteRownolegle(Prosta y, Prosta z){

    return y.get_A() * z.get_B() == y.get_B() * z.get_C();
}

Punkt *punktPrzeciecia(Prosta y, Prosta z){
    if (czyProsteRownolegle(y, z))
        throw std::invalid_argument("Proste równoległe nie mają punktu przecięcia.");

    double D = y.get_A()*z.get_B() - z.get_A()*y.get_B();
    double x1 = (y.get_B()*z.get_C()-z.get_B()*y.get_C())/D;
    double y1 = -(y.get_A()*z.get_C()-z.get_A()*y.get_C())/D;

    return new Punkt(x1, y1);
}