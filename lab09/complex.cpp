//implementing Complex methods

#include <iostream>
#include "complex.h"

Complex::Complex() :real(0),imag(0)// Default constructor
{ 
}
Complex::Complex(double re, double im) :real(re),imag(im)// Constructor with parameters
{
}

void Complex::Show() const { // Define const member function
     std::cout << real << " + " << imag << "i" << std::endl;
}

Complex Complex::Add(const Complex& c) { // Function to add two complex numbers
    Complex result;
    result.real = this->real + c.real;
    result.imag = this->imag + c.imag;
    return result;
}

int main() {
    Complex c1(3.0, 4.0); // Create a complex number
    Complex c2(1.0, 2.0); // Create another complex number
    Complex c3 = c1.Add(c2); // Add the two complex numbers
    c3.Show(); // Display the result
    return 0;
}