#ifndef LISTA_6_OPERATORY_H
#define LISTA_6_OPERATORY_H


#include "Expression.h"

class Add : public Expression {
public:
    Expression *x;
    Expression *y;

    Add(Expression*, Expression*);
    double count() override;
    std::string description() override;
};

class Sub : public Expression {
public:
    Expression *x;
    Expression *y;

    Sub(Expression*, Expression*);
    double count() override;
    std::string description() override;
};

class Mult : public Expression {
public:
    Expression *x;
    Expression *y;

    Mult(Expression*, Expression*);
    double count() override;
    std::string description() override;
};

class Div : public Expression {
public:
    Expression *x;
    Expression *y;

    Div(Expression*, Expression*);
    double count() override;
    std::string description() override;
};

class Expt : public Expression {
public:
    Expression *x;
    Expression *y;

    Expt(Expression*, Expression*);
    double count() override;
    std::string description() override;
};

class Opp : public Expression {
public:
    Expression *x;

    Opp(Expression*);
    double count() override;
    std::string description() override;
};

class Sin : public Expression {
public:
    Expression *x;

    Sin(Expression*);
    double count() override;
    std::string description() override;
};

class Cos : public Expression {
public:
    Expression *x;

    Cos(Expression*);
    double count() override;
    std::string description() override;
};

class Log : public Expression {
public:
    Expression *x;

    Log(Expression*);
    double count() override;
    std::string description() override;
};



#endif //LISTA_6_OPERATORY_H
