#include <stdexcept>
#include "Stos.h"

Stos::Stos() {
    stos = new std::string[1];
    sizeOf = 1;
    howMany = 0;
}


Stos::Stos(int s){
    stos = new std::string[s];
    sizeOf = s;
    howMany = 0;
}


Stos::Stos(std::initializer_list<std::string> list) {
    stos = new std::string[list.size()];
    sizeOf = list.size();
    howMany = 0;

    for(auto x : list)
    {
        push(x);
    }
}

Stos::Stos(const Stos &stos1) : sizeOf(stos1.sizeOf), howMany(stos1.howMany){
    stos = new std::string[sizeOf];
    std::copy(stos1.stos, stos1.stos + stos1.howMany, stos);
}

Stos::Stos(Stos&& x) : sizeOf(x.sizeOf), howMany(x.howMany), stos(std::move(x.stos)){
    x.howMany = 0;
}

Stos::~Stos() {
    delete [] stos;
}

Stos & Stos::operator=(const Stos& x){
    sizeOf = x.sizeOf;
    howMany = x.howMany;
    delete [] stos;
    stos = new std::string[sizeOf];
    std::copy(x.stos, x.stos + x.howMany, stos);
    return *this;
}

Stos & Stos::operator=(Stos&& x){
    sizeOf = x.sizeOf;
    howMany = x.howMany;
    delete [] stos;
    stos = std::move(x.stos);
    return *this;
}

std::string Stos::top(){
    if (howMany == 0)
        std::__throw_invalid_argument("Stack is empty!");

    return stos[howMany-1];
}

int Stos::size() {
    return howMany;
}

void Stos::push(std::string x){
    if(sizeOf == howMany) throw std::range_error("Stack is full!");
    stos[howMany] = x;
    howMany++;

}

std::string Stos::pop(){
    if(howMany == 0) throw std::range_error("Stack is empty!");
    howMany--;
    return stos[howMany];
}

std::string* Stos::get_stos() {
    return stos;
}

