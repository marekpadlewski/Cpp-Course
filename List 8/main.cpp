#include "Rational.h"
using namespace obliczenia;

int main()
{

    Rational r1, r2;
    try
    {
        std::cin >> r1;
        std::cin >> r2;
        std::cout << "r1 = " << r1 << std::endl;
        std::cout << "r2 = " << r2 << std::endl;
        std::cout << "r1 + r2 = " << r1 + r2 << std::endl;
        std::cout << "r1 - r2 = " << r1 - r2 << std::endl;
        std::cout << "r1 * r2 = " << r1 * r2 << std::endl;
        std::cout << "r1 / r2 = " << r1 / r2 << std::endl;
        std::cout << "1 / r1 = " << !r1 << std::endl;
        std::cout << "Rzutowanie r1 na double = " << (double)r1 << std::endl;
        std::cout << "Rzutowanie r1 na int = " << (int)r1 << std::endl;
    }

    catch(const Bad_conversion & error){
        std::cout << error.what() << std::endl;
    }

    catch(const Out_of_range & error){
        std::cout << error.what() << std::endl;
    }

    catch(const Division_by_zero & error){
        std::cout << error.what() << std::endl;
    }

    return 0;
}