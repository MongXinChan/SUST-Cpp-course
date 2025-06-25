#include <iostream>
using namespace std;

class MathException {};
//Notice the inheritance hierarchy for exceptions 
class OverflowException : public MathException {};
class UnderflowException : public MathException {};
class ZeroDivideExeption : public MathException {};

double divide(int numerator, int denominator) {
    if (denominator == 0) {
        throw ZeroDivideExeption();
    }
    if (numerator > 1000000 || denominator > 1000000) {
        throw OverflowException();
    }
    if (numerator < -1000000 || denominator < -1000000) {
        throw UnderflowException();
    }
    return static_cast<double>(numerator) / denominator;
}

int main(){
    try{
        cout<<divide(6,0) << endl;
    }catch(ZeroDivideExeption& e){
        cerr << "Error: Division by zero!" << endl;
    }catch(OverflowException& e){
        cerr << "Error: Overflow occurred!" << endl;
    }catch(UnderflowException& e){
        cerr << "Error: Underflow occurred!" << endl;
    }catch(MathException& e){
        cerr << "Error: A math exception occurred!" << endl;
    }catch(...){
        cerr << "Error: An unknown exception occurred!" << endl;
    }
    return 0;
}