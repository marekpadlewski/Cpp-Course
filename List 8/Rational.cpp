#include "Rational.h"
#include <algorithm>

Exception_rational::Exception_rational(const std::string &err) : error_info("Exception:" + err) {}

const char* Exception_rational::what() const throw() {
    return error_info.c_str();
}

Division_by_zero::Division_by_zero(const std::string &error) : Exception_rational("Division_by_zero" + error) {}

const char* Division_by_zero::what() const throw() {
    return error_info.c_str();
}

Bad_conversion::Bad_conversion(const std::string &error) : Exception_rational("Bad_conversion" + error) {}

const char* Bad_conversion::what() const throw() {
    return error_info.c_str();
}

Out_of_range::Out_of_range(const std::string &error) : Exception_rational("Out_of_range" + error) {}

const char* Out_of_range::what() const throw() {
    return error_info.c_str();
}

namespace obliczenia {

    Rational::Rational(int num, int den = 1) {

        if (den == 0)
            throw Division_by_zero("");

        int gcd = std::__gcd(num, den);
        numerator = num / gcd;
        denominator = den / gcd;
        if (num < 0) {
            numerator *= -1;
            denominator *= -1;
        }

    }

    Rational operator+(const Rational &x, const Rational &y) {
        return {x.numerator * y.denominator + y.numerator * x.denominator, x.denominator * y.denominator};
    }

    Rational &Rational::operator+=(const Rational &x) {
        return *this = *this + x;
    }

    Rational operator-(const Rational &x) {
        return {x.numerator, -x.denominator};
    }

    Rational operator-(const Rational &x, const Rational &y) {
        return x + (-y);
    }

    Rational &Rational::operator-=(const Rational &x) {
        return *this = *this - x;
    }

    Rational operator*(const Rational &x, const Rational &y) {
        long long new_num = (long long)x.numerator * y.numerator;
        long long new_den = (long long)x.denominator * y.denominator;

        long long gcd = std::__gcd(new_num, new_den);
        new_num /= gcd;
        new_den /= gcd;


        if (new_num > INT32_MAX || new_den > INT32_MAX || new_num < INT32_MIN || new_den < INT32_MIN)
        {
            throw Out_of_range("");
        }

        return {x.numerator * y.numerator, x.denominator * y.denominator};
    }

    Rational &Rational::operator*=(const Rational &x) {
        return *this = *this * x;
    }

    Rational operator!(const Rational &x) {
        if (x.numerator == 0)
        {
            throw Division_by_zero("");
        }

        return {x.denominator, x.numerator};

    }

    Rational operator/(const Rational &a, const Rational &b) {
        return a * (!b);
    }

    Rational &Rational::operator/=(const Rational &a) {
        return *this = *this / a;
    }

    int Rational::get_nominator() const {
        return numerator;
    }

    int Rational::get_denominator() const {
        return denominator;
    }

    bool Rational::is_integer() const {
        return denominator == 1 || denominator == -1;
    }

    Rational::operator double() const {
        return numerator / (double) denominator;
    }

    Rational::operator int() const {
        if (!is_integer())
            throw Bad_conversion("Fraction is not a integer.");
        return numerator * denominator;
    }

    std::ostream &operator<<(std::ostream &stream, const Rational &x) {
        stream << x.numerator << " / " << x.denominator;
        return stream;
    }

    std::istream &operator>>(std::istream &stream, Rational &y) {
        int x, d;
        stream >> x >> d;
        y = Rational(x, d);
        return stream;
    }
}