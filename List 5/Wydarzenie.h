#ifndef LISTA_5_WYDARZENIE_H
#define LISTA_5_WYDARZENIE_H

#include "DataGodz.h"
#include <iostream>

class Wydarzenie {
public:
    DataGodz punktczasowy;
    std::string opis;

    Wydarzenie(DataGodz, std::string);

    bool operator < (const Wydarzenie&);
};


#endif //LISTA_5_WYDARZENIE_H
