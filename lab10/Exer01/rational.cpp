#include <iostream>
#include "rational.h"
// using namespace std; // Avoid in headers, consider in .cpp files

int main() {
    Rational a = 10;     // int -> Rational (conversion constructor) -> Rational a (copy/move constructor)
    Rational b(1, 2);  // Direct construction
    Rational c = a * b;  // a*b calls operator*, returns temp Rational, then copy/move to c
    std::cout << "c = " << c << std::endl;

    Rational d = 2 * a;  // 2 (int) -> Rational (temp), then operator*, returns temp, copy/move to d
    std::cout << "d = " << d << std::endl;

    Rational e = b * 3;  // 3 (int) -> Rational (temp), then operator*, returns temp, copy/move to e
    std::cout << "e = " << e << std::endl;

    Rational f = 2 * 3;  // 2 (int) -> Rational (temp T1), 3 (int) -> Rational (temp T2)
                         // Then T1 * T2, returns temp, copy/move to f
    std::cout << "f = " << f << std::endl;
    return 0;
}