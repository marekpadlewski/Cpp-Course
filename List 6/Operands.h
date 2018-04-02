#ifndef LISTA_6_OPERANDY_H
#define LISTA_6_OPERANDY_H

#include <vector>
#include "Expression.h"

class Variable : public Expression {
public:
    std::string name;
    static void addVariable(std::string, double);
    static void delVariable(std::string);
    double count() override;
    std::string description() override;
    Variable(std::string);
    Variable() = default;
private:
    static std::vector<std::pair<std::string,double>> V;
};

class Number : public Expression{
public:
    const double value;
    double count() override;
    std::string description() override;
    Number(double v);
};

class Pi : public Expression{
public:
    const double value = 3.14;
    double count() override;
    std::string description() override;
    Pi() = default;
};

class Euler : public Expression{
public:
    const double value = 2.71;
    double count() override;
    std::string description() override;
    Euler() = default;
};

class Fi : public Expression{
public:
    const double value = 1.61;
    double count() override;
    std::string description() override;
    Fi() = default;
};

std::string twoDigitsAfterPoint(double);

#endif //LISTA_6_OPERANDY_H
