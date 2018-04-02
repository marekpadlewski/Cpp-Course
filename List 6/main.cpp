#include <iostream>
#include <algorithm>
#include "Expression.h"
#include "Operators.h"
#include "Operands.h"

int main() {

    for (double i = 0 ; i <= 1 ; i += 0.01){
        Variable *v;
        v->addVariable("x", i);
        v->addVariable("y", 2);
        std::cout << "x = " << i << std::endl;
        Expression *w = new Div(new Mult(new Sub(new Variable("x"), new Number(1)), new Variable("x")), new Number(2));
        Expression *e = new Div(new Add(new Number(3), new Number(5)), new Add(new Number(2), new Mult(new Variable("x"), new Number(7))));
        Expression *r = new Sub(new Add(new Number(2), new Mult(new Variable("x"), new Number(7))),new Add(new Mult(new Variable("y"), new Number(3)), new Number(5)));
        Expression *t = new Div(new Cos(new Mult(new Add(new Variable("x"), new Number(1)), new Variable("x"))), new Expt(new Euler(), new Expt(new Variable("x"), new Number(2))));
        std::cout<< w->description() << " = " << w->count() << std::endl;
        std::cout<< e->description() << " = " << e->count() << std::endl;
        std::cout<< r->description() << " = " << r->count() << std::endl;
        std::cout<< t->description() << " = " << t->count() << std::endl;
        v->delVariable("x");
    }


    return 0;
}