// rational.h
#pragma once  
#include <iostream>
class Rational{
private:
    staticint id;
    int numerator;
    int denominator;
public:
    Rational(int n=0, int d=1): numerator(n), denominator(d){
        std::cout<<"Construct_"<<id<<", n:"<<numerator<<" , d:"<<denominator<<std::endl;
    }

    int getN() const { return numerator; }
    int getD() const { return denominator; }
    friend std::ostream & operator<<(std::ostream& os, const Rational&rhs){
        os<<rhs.numerator<<"/"<<rhs.denominator;
        returnos;
    }
};
int Rational::id=0;
const Rational operator*(constRational&lhs, const Rational&rhs){
        return Rational(lhs.getN()*rhs.getN(), lhs.getD()*rhs.getD() );
}
