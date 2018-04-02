#include <cmath>
#include "Operators.h"

Add::Add(Expression *x, Expression *y) {
    this->x = x;
    this->y = y;
}

double Add::count() {
    return x->count() + y->count();
}

std::string Add::description() {
    std::string str = "(";
    str += x->description();
    str += "+";
    str += y->description();
    str += ")";

    return str;
}

Sub::Sub(Expression *x, Expression *y) {
    this->x = x;
    this->y = y;
}

double Sub::count() {
    return x->count() - y->count();
}

std::string Sub::description() {
    std::string str = "(";
    str += x->description();
    str += "-";
    str += y->description();
    str += ")";

    return str;
}

Mult::Mult(Expression *x, Expression *y) {
    this->x = x;
    this->y = y;
}

double Mult::count() {
    return x->count() * y->count();
}

std::string Mult::description() {
    std::string str = "(";
    str += x->description();
    str += "*";
    str += y->description();
    str += ")";

    return str;
}

Div::Div(Expression *x, Expression *y) {
    this->x = x;
    this->y = y;
}

double Div::count() {
    return x->count() / y->count();
}

std::string Div::description() {
    std::string str = "(";
    str += x->description();
    str += "/";
    str += y->description();
    str += ")";

    return str;
}

Expt::Expt(Expression *x, Expression *y){
    this->x = x;
    this->y = y;
}

double Expt::count() {
    return pow(x->count(), y->count());
}

std::string Expt::description() {
    std::string str = "(";
    str += x->description();
    str += "^";
    str += y->description();
    str += ")";

    return str;
}

Opp::Opp(Expression *x){
    this->x = x;
}

double Opp::count() {
    return -1 * x->count();
}

std::string Opp::description() {
    std::string str = "(";
    str += "-";
    str += x->description();
    str += ")";

    return str;
}

Sin::Sin(Expression *x){
    this->x = x;
}

double Sin::count() {
    return sin(x->count());
}

std::string Sin::description() {
    std::string str = "sin";
    str += "(";
    str += x->description();
    str += ")";

    return str;
}

Cos::Cos(Expression *x){
    this->x = x;
}

double Cos::count() {
    return cos(x->count());
}

std::string Cos::description() {
    std::string str = "cos";
    str += "(";
    str += x->description();
    str += ")";

    return str;
}


Log::Log(Expression *x){
    this->x = x;
}

double Log::count() {
    return log(x->count());
}

std::string Log::description() {
    std::string str = "log";
    str += "(";
    str += x->description();
    str += ")";

    return str;
}
