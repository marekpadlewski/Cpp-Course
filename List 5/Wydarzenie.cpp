#include "Wydarzenie.h"

Wydarzenie::Wydarzenie(DataGodz dg, std::string s) {
    punktczasowy = dg;
    opis = s;
}

bool Wydarzenie::operator<(const Wydarzenie &wyd) {

    return punktczasowy<wyd.punktczasowy;
}