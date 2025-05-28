#include "complex.h"
#include <iostream> // For Show, operator<<, operator>>
#include <cmath>    // For potential future use, e.g., abs value (sqrt)

using namespace std;


// Constructors
Complex::Complex(double r, double i) : real(r), imag(i) {}

// Member function to display complex number
void Complex::Show() const {
    std::cout << "(" << real << ", " << imag << "i)";
}

// Unary operator (conjugate)
// (a+bi)~ = (a-bi)
Complex Complex::operator~() const {
    return Complex(real, -imag);
}

// Binary arithmetic operators
// (a+bi) + (c+di) = (a+c) + (b+d)i
Complex Complex::operator+(const Complex& other) const {
    return Complex(real + other.real, imag + other.imag);
}

// (a+bi) - (c+di) = (a-c) + (b-d)i
Complex Complex::operator-(const Complex& other) const {
    return Complex(real - other.real, imag - other.imag);
}

// (a+bi) * (c+di) = (ac - bd) + (ad + bc)i
Complex Complex::operator*(const Complex& other) const {
    double r_part = real * other.real - imag * other.imag;
    double i_part = real * other.imag + imag * other.real;
    return Complex(r_part, i_part);
}

// Comparison operators
bool Complex::operator==(const Complex& other) const {
    // Consider using a small epsilon for floating-point comparison if exactness is an issue
    return (real == other.real) && (imag == other.imag);
}

bool Complex::operator!=(const Complex& other) const {
    return !(*this == other); // Delegate to operator==
}

// Friend functions for stream I/O
// Output: (real, imagi) e.g., (3, 4i) or (2, -6i)
std::ostream& operator<<(std::ostream& os, const Complex& c) {
    os << "(" << c.real;
    if (c.imag >= 0) {
        os << " + " << c.imag << "i)";
    } else {
        os << " - " << -c.imag << "i)";
    }
    return os;
}

// Input: expects two doubles, e.g., 3 4
std::istream& operator>>(std::istream& is, Complex& c) {
    double r_in, i_in;
    // Naive input, assumes correct format like "R I"
    // More robust parsing would check for parentheses, commas, 'i', etc.
    // For "Enter a complex number (real imag): " prompt, just reading two numbers is fine.
    is >> r_in >> i_in;
    if (is) { // Check if input operation was successful
        c.real = r_in;
        c.imag = i_in;
    }
    // Could add error handling here if is.fail()
    return is;
}

// Non-member operator for double * Complex
// d * (a+bi) = (da) + (db)i
Complex operator*(double lhs, const Complex& rhs) {
    return Complex(lhs * rhs.getReal(), lhs * rhs.getImag());
    // Alternatively, if Complex(double, double) is not explicit and Complex*Complex is defined:
    // return Complex(lhs, 0) * rhs; // but this might be less direct.
    // Using accessors or making it a friend if real/imag were strictly private to non-friends.
    // Here, rhs.real and rhs.imag would work if this was a friend,
    // but getReal()/getImag() is cleaner if they exist.
}

// If Complex * double was desired:
// Complex operator*(const Complex& lhs, double rhs) {
//     return Complex(lhs.getReal() * rhs, lhs.getImag() * rhs);
// }
// Or, as mentioned, `a * 2.0` works because `2.0` can be converted to `Complex(2.0, 0.0)`
// due to the `Complex(double r = 0.0, double i = 0.0)` constructor, and then
// `Complex::operator*(const Complex&)` is called.
int main() {
    Complex a(3, 4);
    Complex b(2, 6);

    cout << "a = " << a << endl;
    cout << "b = " << b << endl;

    cout << "~b = " << ~b << endl;             // Conjugate
    cout << "a + b = " << a + b << endl;
    cout << "a - b = " << a - b << endl;
    cout << "a - 2 = " << a - 2.0 << endl;     // Complex - double
    cout << "a * b = " << a * b << endl;
    cout << "2 * a = " << 2.0 * a << endl;     // double * Complex

    cout << "========================" << endl;
    Complex c = b;
    cout << "c = " << c << endl;
    cout << "b == c? " << boolalpha << (b == c) << endl;
    cout << "b != c? " << (b != c) << endl;
    cout << "a == b? " << (a == b) << endl;
    cout << "========================" << endl;

    Complex d;
    cout << "Enter a complex number (real imag): ";
    cin >> d; // Test operator>>
    cout << "Before assignment, d = " << d << endl;
    d=c;
    cout << "After assignment, d = "<< d << endl;


    return 0;
}