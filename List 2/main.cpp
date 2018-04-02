#include <iostream>
#include "Wektor.h"
#include "Punkt.h"
#include "Prosta.h"

using namespace std;

int main() {

    Punkt p1(1, 4), p2(17, 42);
    Wektor v(p2.x-p1.x, p2.y-p1.x), u(v);
    Prosta y1(p1, p2), y2(v), y3(3,4,1), y4(y1, u);

    Wektor *s = zlozenie(u, v);

    if (czyProsteProstopadle(y3, y4)){
        cout << "Proste y3 i y4 są prostopadłe." << endl;
    }

    else{
        cout << "Proste y3 i y4 nie są prostopadłe." << endl;
    }

    Punkt *p3 = punktPrzeciecia(y3, y1);
    cout << "Punkt przecięcia y3 i y1: " << p3->x << " " << p3->y << endl;

    if (y2.czyWektorRownolegly(v, y2))
        cout << "Wektor v równoległy do prostej y2." << endl;

    else
        cout << "Wektor v nie równoległy do prostej y2." << endl;


    if(y1.czyWektorProstopadly(*s, y1))
        cout << "Wektor s prostopadły do prostej y1." << endl;

    else
        cout << "Wektor s nie prostopadły do prostej y1." << endl;

    Punkt w(0,0);
    Prosta y5(3,4,0);

    if (y5.czyPunktNaProstej(w, y5))
        cout << "Punkt w jest na prostej y5." << endl;

    delete(p3);
    delete(s);

    return 0;
}