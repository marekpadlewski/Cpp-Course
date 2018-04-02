#include "Data.h"
#include <ctime>
#include <iostream>

Data::Data() {
    std::time_t t = std::time(0);
    std::tm* now = std::localtime(&t);

    dzien = now->tm_mday;
    miesiac = now->tm_mon + 1;
    rok = now->tm_year + 1900;
}


Data::Data(int d, int m, int r) {
    dzien = d;
    miesiac = m;
    rok = r;

    if(!czyDataPoprawna())
        std::__throw_invalid_argument("Wpisano niepoprawną datę");
}

int Data::getDzien() const{
    return dzien;
}

int Data::getMiesiac() const {
    return miesiac;
}

int Data::getRok() const {
    return rok;
}

bool Data::czyPrzestepny(int r) {
    return r%400 == 0 || (r%4 == 0 && r%100 != 0);
}

bool Data::czyDataPoprawna() {

    if (rok < 0 || miesiac < 1 || miesiac > 12)
        return false;

    int i = 0;

    if (czyPrzestepny(rok))
        i = 1;

    int dwm = dniwmiesiacach[i][miesiac];
    return (dzien > 0 && dzien <= dwm);
}

int Data::dniwmiesiacach[2][13] = {
        {0,31,28,31,30,31,30,31,31,30,31,30,31}, // lata zwykłe
        {0,31,29,31,30,31,30,31,31,30,31,30,31} // lata przestępne
};

int Data::dniodpoczroku[2][13] = {
        {0,31,59,90,120,151,181,212,243,273,304,334,365}, // lata zwykłe
        {0,31,60,91,121,152,182,213,244,274,305,335,366} // lata przestępne
};

int Data::ileDniOdDaty(Data data) {

    int count = 0;
    if (czyPrzestepny(data.rok)){

        count = dniodpoczroku[1][data.miesiac-1] + data.dzien;
    }

    else
        count = dniodpoczroku[0][data.miesiac-1] + data.dzien;


    int extra = (((data.rok/4)-(data.rok/100)) + (data.rok/400));
    count += (extra * 366) + ((data.rok - extra) * 365);

    return count;
}

int Data::operator-(const Data &d1) {
    return abs(ileDniOdDaty(Data(dzien,miesiac,rok)) - ileDniOdDaty(d1));
}


Data Data::operator++(int) {
    Data d(dzien,miesiac,rok);

    int i = 0;

    if (czyPrzestepny(rok))
        i = 1;

    if (dzien < dniwmiesiacach[i][miesiac])
        dzien++;

    else {
        dzien = 1;

        if (miesiac < 12)
            miesiac++;

        else{
            miesiac = 1;
            rok++;
        }
    }

    return d;
}

Data Data::operator--(int) {

    Data d(dzien,miesiac,rok);

    if (dzien > 1)
        dzien--;

    else {

        if (miesiac > 1)
            miesiac--;

        else{
            miesiac = 12;
            rok--;
        }

        const int i = czyPrzestepny(rok) ? 1 : 0;

        dzien = dniwmiesiacach[i][miesiac];
    }

    return d;
}

Data Data::operator+=(int n) {

    Data d(dzien,miesiac,rok);

    while (n --> 0){
        int i = 0;

        if (czyPrzestepny(rok))
            i = 1;

        if (dzien < dniwmiesiacach[i][miesiac])
            dzien++;

        else {
            dzien = 1;

            if (miesiac < 12)
                miesiac++;

            else{
                miesiac = 1;
                rok++;
            }
        }
    }

    return d;
}

Data Data::operator-=(int n) {
    Data d(dzien,miesiac,rok);

    while (n --> 0){
        if (dzien > 1)
            dzien--;

        else {

            if (miesiac > 1)
                miesiac--;

            else{
                miesiac = 12;
                rok--;
            }

            int i = 0;

            if (czyPrzestepny(rok))
                i = 1;

            dzien = dniwmiesiacach[i][miesiac];
        }
    }

    return d;
}