#include <iostream>
#include "rational.h"
// using namespace std; // Avoid in headers, consider in .cpp files

int main() {
    Rational r(1, 2);
    // double d_val = r; // ERROR! Cannot perform implicit conversion
    double d_explicit = static_cast<double>(r); // OK: Explicit conversion
    double d_direct = (double)r; // OK: Explicit conversion (C-style cast)
    return 0;
}