#include <iostream>
#include "Stos.h"

int main() {

    int siz;
    std::cout << "Podaj rozmiar stosu: ";
    std::cin >> siz;
    Stos *stos = new Stos(siz);

    while(true){
        std::string opr;
        std::cout << "Podaj operację na stosie: ";
        std::cin >> opr;


        if (opr == "push"){
            std::string word;
            std::cin.ignore();
            std::getline(std::cin, word);
            stos->push(word);
        }

        if (opr == "pop"){
            stos->pop();
        }

        if (opr == "top"){
            std::cout << stos->top() << std::endl;
        }

        if (opr == "size"){
            std::cout << stos->size() << std::endl;
        }

        if (opr == "write"){

            int len = stos->size();

            if (len == 0){
                std::cout << "Stack is empty!" << std::endl;
            }

            else{

                for (int i = 0 ; i<=len-1 ; i++){
                    std::cout << *(stos->get_stos()+i) << std::endl;
                }
            }
        }

        if (opr == "end"){
            delete stos;
            break;
        }
    }

    return 0;
}