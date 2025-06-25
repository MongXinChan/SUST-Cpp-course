#include<iostream>
using namespace std;

// Function prototype for Quotient
double Quotient(int a, int b);


int main(){
    int a,b;
    double d;
    a = 5;
    b = 0;

    try {
        d = Quotient(a, b);
        cout << "The quotient of " << a << "/" << b << " is: " << d << endl;
    } catch (const char* p_error) {
        cerr << p_error << endl;
    } catch (int error_code) { // Matches the thrown int type exception
        cerr << "Exception code: " << error_code << endl;
    }
    return 0;
}

double Quotient(int a, int b) {
    if (b == 0) {
        throw "404"; // Throwing a C-style string
    }
    return static_cast<double>(a) / b;
}