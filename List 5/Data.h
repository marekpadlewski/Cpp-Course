#ifndef LISTA_5_DATA_H
#define LISTA_5_DATA_H

class Data {

public:
    int getDzien() const;
    int getMiesiac() const;
    int getRok() const;

    Data();
    Data(int, int , int);
    Data(const Data &data1) = default;

    Data & operator=(const Data&) = default;

    Data operator ++ (int);
    Data operator -- (int);
    Data operator += (int);
    Data operator -= (int);
    virtual int operator - (const Data&);

protected:
    int dzien;
    int miesiac;
    int rok;

    static bool czyPrzestepny(int);

private:
    bool czyDataPoprawna();
    static int dniwmiesiacach[2][13];
    static int dniodpoczroku[2][13];
    int ileDniOdDaty(Data);
};


#endif //LISTA_5_DATA_H
