#ifndef Complex_H
#define Complex_H
#include <iostream>

class Complex {
private:
    double real;
    double imag;
public:
    // Constructor (with default arguments)
    Complex(double re = 0.0, double im = 0.0);

    // Addition
    Complex add(const Complex& other) const;

    // Subtraction
    Complex subtract(const Complex& other) const;

    // Display (const member function)
    void display() const;
};


#endif // Complex_H