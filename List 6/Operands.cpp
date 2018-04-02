#include <algorithm>
#include "Operands.h"

std::string twoDigitsAfterPoint(double val){
    std::string str = std::to_string(val);
    int i=0;
    while (str[i]!='.'){
        i++;
    }

    return str.substr(0,i+=3);
}


Number::Number(double v) : value(v){}

double Number::count() {return value;}

std::string Number::description() {
    return twoDigitsAfterPoint(value);
}

std::vector<std::pair<std::string,double>> Variable::V;

Variable::Variable(std::string name) {this->name = name;}

void Variable::addVariable(std::string name, double value) {
    V.emplace_back(std::make_pair(name, value));
}

void Variable::delVariable(std::string name) {
    V.erase(std::remove_if(V.begin(),
                              V.end(),
                              [&name](std::pair<std::string, double> p){return p.first == name;}));
}

double Variable::count() {
    for (auto elem : V) {
        if (elem.first == name)
            return elem.second;
    }
    std::__throw_invalid_argument("Variable doesn't exist in set.");
}

std::string Variable::description() {
    return name;
}

double Pi::count() {return value;}

std::string Pi::description() {
    return twoDigitsAfterPoint(value);
}

double Euler::count() {return value;}

std::string Euler::description() {
    return twoDigitsAfterPoint(value);
}

double Fi::count() {return value;}

std::string Fi::description() {
    return twoDigitsAfterPoint(value);
}
