#include "Complex.h"

using namespace std;

int main() {

    float imag,real;
    cout << "Enter the real and imaginary parts of the first complex number: ";
    cin>> real>> imag;
    Complex c1(real, imag);

    cout << "Enter the real and imaginary parts of the second complex number: ";
    cin>> real >> imag;
    Complex c2(real, imag);
    
    Complex sum = c1.add(c2);
    Complex diff = c1.subtract(c2);
    
    cout << "Sum: ";
    sum.display();
    
    cout << "Difference: ";
    diff.display();
    
    return 0;
}