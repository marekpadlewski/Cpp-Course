#include "DataGodz.h"
#include <ctime>
#include <vector>
#include <iostream>

DataGodz::DataGodz() {
    std::time_t t = std::time(0);
    std::tm* now = std::localtime(&t);

    dzien = now->tm_mday;
    miesiac = now->tm_mon + 1;
    rok = now->tm_year + 1900;
    godzina = now->tm_hour;
    minuta = now->tm_min;
    sekunda = now->tm_sec;
}

DataGodz::DataGodz(int dz, int mie, int r, int g, int m, int s) {
    godzina = g;
    minuta = m;
    sekunda = s;
    dzien = dz;
    miesiac = mie;
    rok = r;
}

int DataGodz::getGodzina() const {
    return godzina;
}

int DataGodz::getMinuta() const {
    return minuta;
}

int DataGodz::getSekunda() const {
    return sekunda;
}

DataGodz DataGodz::operator++(int) {

    DataGodz dg(dzien, miesiac, rok, godzina, minuta, sekunda);

    if (sekunda < 59)
        sekunda++;

    else {
        sekunda = 0;

        if (minuta < 59)
            minuta++;

        else{

            minuta = 0;

            if (godzina < 23)
                godzina++;
            else
            {
                Data::operator++(0);
                godzina = 0;
            }

        }
    }

    return dg;
}

DataGodz DataGodz::operator--(int) {
    DataGodz dg(dzien, miesiac, rok, godzina, minuta, sekunda);

    if (sekunda > 0)
        sekunda--;

    else {
        sekunda = 59;

        if (minuta > 0)
            minuta--;

        else{
            minuta = 59;

            if (godzina > 0)
                godzina--;
            else
            {
                Data::operator--(0);
                godzina = 23;
            }
        }
    }

    return dg;
}

DataGodz DataGodz::operator+=(int n) {

    DataGodz dg(dzien, miesiac, rok, godzina, minuta, sekunda);

    while (n --> 0){

        if (sekunda < 59)
            sekunda++;

        else {
            sekunda = 0;

            if (minuta < 59)
                minuta++;

            else{
                minuta = 0;

                if (godzina < 23)
                    godzina++;
                else
                {
                    Data::operator++(0);
                    godzina = 0;
                }

            }
        }
    }

    return dg;
}

DataGodz DataGodz::operator-=(int n) {
    DataGodz dg(dzien, miesiac, rok, godzina, minuta, sekunda);

    while (n --> 0){

        if (sekunda > 0)
            sekunda--;

        else {
            sekunda = 59;

            if (minuta > 0)
                minuta--;

            else{
                minuta = 59;

                if (godzina > 0)
                    godzina--;
                else
                {
                    Data::operator--(0);
                    godzina = 23;
                }
            }
        }
    }

    return dg;
}

bool DataGodz::operator==(const DataGodz &dg) {

    return dzien == dg.dzien && miesiac == dg.miesiac && rok == dg.rok
            && godzina == dg.godzina && minuta == dg.minuta && sekunda == dg.sekunda;
}

bool DataGodz::operator<(const DataGodz &dg) {

    std::vector<int> v1={rok,miesiac,dzien,godzina,minuta,sekunda};
    std::vector<int> v2={dg.rok,dg.miesiac,dg.dzien,dg.godzina,dg.minuta,dg.sekunda};

    return std::lexicographical_compare(v1.begin(),v1.end(), v2.begin(), v2.end());
}

long long int operator - (const DataGodz &dg, const DataGodz &dg2){

    int howManyDays = Data(dg.getDzien(),dg.getMiesiac(),dg.getRok())-Data(dg2.getDzien(),dg2.getMiesiac(),dg2.getRok());
    int howManyHours = abs(dg.getGodzina()-dg2.getGodzina());
    int howManyMinutes = abs(dg.getMinuta()-dg2.getMinuta());
    int howManySeconds = abs(dg.getSekunda()-dg2.getSekunda());

    long long int result = 86400*howManyDays + 3600*howManyHours + 60*howManyMinutes + howManySeconds;

    return result;
}