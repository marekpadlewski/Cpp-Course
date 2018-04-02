#ifndef LISTA_6_WYRAZENIE_H
#define LISTA_6_WYRAZENIE_H

#include <iostream>

class Expression {

public:
    virtual double count()=0;
    virtual std::string description()=0;
};


#endif //LISTA_6_WYRAZENIE_H
