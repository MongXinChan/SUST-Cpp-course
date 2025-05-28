#ifndef _MYCOMPLEX_H
#define _MYCOMPLEX_H

class Complex {
private:
    double real;
    double imag;

public:
    Complex(); // Default constructor
    Complex(double r, double i); // Constructor with parameters
    Complex Add(const Complex& c); // Function to add two complex numbers
    Complex operator+(const Complex &rhs)const;
    void Show() const; // Function to display complex number
};

#endif //_MYCOMPLEX_H