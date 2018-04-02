#ifndef LISTA_5_DATAGODZ_H
#define LISTA_5_DATAGODZ_H

#include "Data.h"

class DataGodz final : public Data {
public:
    int getGodzina() const;
    int getMinuta() const;
    int getSekunda() const;

    DataGodz();
    DataGodz(int dz, int mie, int r, int g, int m, int s);
    DataGodz(const DataGodz &dg) = default;

    DataGodz operator ++ (int);
    DataGodz operator -- (int);
    DataGodz operator += (int);
    DataGodz operator -= (int);
    bool operator == (const DataGodz&);
    bool operator < (const DataGodz&);

protected:
    int godzina;
    int minuta;
    int sekunda;
};

long long int operator - (const DataGodz&, const DataGodz&);

#endif //LISTA_5_DATAGODZ_H
