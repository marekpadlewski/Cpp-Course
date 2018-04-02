#include "Punkt.h"

Punkt::Punkt(double x1, double y1) : x(x1), y(y1){
}

Punkt::Punkt(Wektor v, Punkt p) : x(p.x + v.dx), y(p.y + v.dy){
}

Punkt::Punkt(const Punkt &punkt) : x(punkt.x), y(punkt.y) {
}