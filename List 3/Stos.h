#ifndef LISTA_3_STOS_H
#define LISTA_3_STOS_H

#include <string>

class Stos {
public:
    Stos();
    Stos(int);
    Stos(std::initializer_list<std::string>);
    Stos(const Stos&);
    Stos(Stos&&);
    ~Stos();

    Stos & operator=(const Stos&); //przypisanie kopiujace
    Stos & operator=(Stos&&); //przypisanie przenoszace

    void push(std::string); //wloz
    std::string pop(); //sciagnij
    std::string top(); //sprawdz wierzch
    int size(); //rozmiar

    std::string *get_stos();

private:
    int sizeOf; //pojemnosc
    int howMany; //rozmiar akt
    std::string* stos;
};


#endif //LISTA_3_STOS_H
