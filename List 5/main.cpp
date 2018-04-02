#include <iostream>
#include <vector>
#include <algorithm>
#include "Data.h"
#include "DataGodz.h"
#include "Wydarzenie.h"

int main() {
    Data date(1,1,2002);
    Data date1(28,12,2014);

    DataGodz dg(1,1,2002, 23,59, 55);
    DataGodz dg2(13,12,2014, 6,54,51);
    DataGodz dg3(1,1,2002, 20,17,42);
    DataGodz dg4(19,10,1990, 10,55,20);

    dg+=10;
    std::cout<< dg.getDzien() << " " << dg.getMiesiac() << std::endl;


    std::cout << "Data przed zmianą:" << std::endl;
    std::cout << date1.getDzien() << " " << date1.getMiesiac() << " " << date1.getRok() << std::endl;
    std::cout << "Data po dodaniu 5 dni:" << std::endl;
    date1+=5;
    std::cout << date1.getDzien() << " " << date1.getMiesiac() << " " << date1.getRok() << std::endl;

    Data date3 = date1-=5;
    std::cout << "Ilość dni pomiedzy tymi datami: " << date3-date1 << std::endl;

    std::cout << std::endl <<  "Czy dwa punkty czasowe równe? ";
    if (dg==dg2)
        std::cout << "Tak" << std::endl;
    else
        std::cout << "Nie" << std::endl;

    std::cout << "Czy pierwszy punkt wcześniejszy? ";
    if (dg4<dg3)
        std::cout << "Tak" << std::endl;
    else
        std::cout << "Nie" << std::endl;

    dg++;
    dg2-=3;


    std::vector<Wydarzenie> V;
    Wydarzenie w(dg,"Opis wydarzenia 1");
    V.push_back(w);
    Wydarzenie w1(dg2,"Opis wydarzenia 2");
    V.push_back(w1);
    Wydarzenie w2(dg3,"Opis wydarzenia 3");
    V.push_back(w2);
    Wydarzenie w3(dg4,"Opis wydarzenia 4");
    V.push_back(w3);

    sort(V.begin(), V.end());

    std::cout << std::endl <<  "Wydarzenia posortowane chronologicznie: " << std::endl;

    for (const auto &w : V){
        std::cout << w.punktczasowy.getDzien() << " " << w.punktczasowy.getMiesiac() << " " << w.punktczasowy.getRok() << " "
                  << w.punktczasowy.getGodzina() << " " << w.punktczasowy.getMinuta() << " " << w.punktczasowy.getSekunda()
                  << " | " << w.opis << std::endl;
    }


    return 0;
}