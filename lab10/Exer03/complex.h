#ifndef _MYCOMPLEX_H
#define _MYCOMPLEX_H

#include <iostream>

class Complex {
private:
    double real;
    double imag;

public:
    Complex(double r=0.0,double i=0.0); // Default constructor

    // Member function to display complex number (as requested in original H file)
    void Show() const; // Function to display complex number

    // Accessors (optional, but good practice if direct access to real/imag is needed outside friends)
    double getReal() const { return real; }
    double getImag() const { return imag; }

    // Unary operator (conjugate)
    Complex operator~() const;

    // Binary arithmetic operators (member functions)
    Complex operator+(const Complex& other) const;
    Complex operator-(const Complex& other) const;
    Complex operator*(const Complex& other) const;
    // Division operator could be added here if needed: Complex operator/(const Complex& other) const;

    // Comparison operators (member functions)
    bool operator==(const Complex& other) const;
    bool operator!=(const Complex& other) const;

    // Friend functions for stream I/O
    friend std::ostream& operator<<(std::ostream& os, const Complex& c);
    friend std::istream& operator>>(std::istream& is, Complex& c);

};

#endif //_MYCOMPLEX_H