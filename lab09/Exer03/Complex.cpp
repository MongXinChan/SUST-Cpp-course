#include <iostream>
#include "Complex.h"
using namespace std;

Complex::Complex(double re, double im) : real(re), imag(im) {
    // Constructor with parameters
}

Complex Complex::add(const Complex& other) const {
    // Addition of two complex numbers
    return Complex(real + other.real, imag + other.imag);
}

Complex Complex::subtract(const Complex& other) const {
    // Subtraction of two complex numbers
    return Complex(real - other.real, imag - other.imag);
}

void Complex::display() const {
    // Display the complex number
    cout << real << " + " << imag << "i" << endl;
}
// Note: The display function is a const member function, meaning it does not modify the object.