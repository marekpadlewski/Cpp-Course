#pragma once

#include <iostream>

class Exception_rational : public std::exception{
protected:
    std::string error_info = "Error";
public:
    Exception_rational() = default;
    Exception_rational(const std::string &);
    virtual const char * what() const throw();
};

class Division_by_zero : Exception_rational{
public:
    Division_by_zero() = default;
    Division_by_zero(const std::string &);
    virtual const char * what() const throw();
};

class Bad_conversion : Exception_rational{
public:
    Bad_conversion() = default;
    Bad_conversion(const std::string &);
    virtual const char * what() const throw();
};

class Out_of_range : Exception_rational{
public:
    Out_of_range() = default;
    Out_of_range(const std::string &);
    virtual const char * what() const throw();
};

namespace obliczenia {
    class Rational {
    private:
        int numerator;
        int denominator;

    public:
        Rational() = default;

        Rational(int, int);

        friend Rational operator+(const Rational &, const Rational &);

        friend Rational operator-(const Rational &, const Rational &);

        friend Rational operator-(const Rational &);

        friend Rational operator*(const Rational &, const Rational &);

        friend Rational operator/(const Rational &, const Rational &);

        friend Rational operator!(const Rational &);

        friend std::ostream &operator<<(std::ostream &, const Rational &);

        friend std::istream &operator>>(std::istream &, Rational &);

        Rational &operator+=(const Rational &);

        Rational &operator-=(const Rational &);

        Rational &operator*=(const Rational &);

        Rational &operator/=(const Rational &);

        int get_nominator() const;

        int get_denominator() const;

        bool is_integer() const;

        operator int() const;

        operator double() const;


    };
}

