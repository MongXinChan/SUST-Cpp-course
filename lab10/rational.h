// rational.h
#pragma once
#include <iostream>

class Rational {
private:
    static int id_counter; // To track constructor calls
    int id_instance;       // ID for each instance
    int numerator;
    int denominator;
public:
    Rational(int n = 0, int d = 1) : numerator(n), denominator(d) {
        id_instance = ++id_counter; // Assign instance ID
        std::cout << "Construct_" << id_instance << ", n:" << numerator << " , d:" << denominator << std::endl;
    }

    // Copy constructor (should also print info if tracking is needed)
    Rational(const Rational& other) : numerator(other.numerator), denominator(other.denominator) {
        id_instance = ++id_counter;
        std::cout << "CopyConstruct_" << id_instance << " from " << other.id_instance
                  << ", n:" << numerator << " , d:" << denominator << std::endl;
    }

    explicit operator double()const{
        return static_cast<double>(numerator)/denominator;
    }

    int getN() const { return numerator; }
    int getD() const { return denominator; }

    friend std::ostream& operator<<(std::ostream& os, const Rational& rhs) {
        os << rhs.numerator << "/" << rhs.denominator;
        return os;
    }
};

// Initialize static member
int Rational::id_counter = 0;

// Global operator*
const Rational operator*(const Rational& lhs, const Rational& rhs) {
    // Note: This creates a temporary Rational object and returns it.
    // This return process itself might involve construction (depending on RVO).
    return Rational(lhs.getN() * rhs.getN(), lhs.getD() * rhs.getD());
}