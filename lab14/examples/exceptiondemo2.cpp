#include <iostream>

double Quotient(int a, int b) {
    if (b == 0) {
        throw 404; // Throwing an int type exception
    }
    return static_cast<double>(a) / b;
}

int main() {
    int a = 5, b = 0;
    double d;
    try {
        d = Quotient(a, b);
        std::cout << "The quotient of " << a << "/" << b << " is: " << d << std::endl;
    } catch (const char* p_error) {
        std::cerr << p_error << std::endl;
    } catch (int error_code) { // Matches the thrown int type exception
        std::cerr << "Exception code: " << error_code << std::endl;
    }
    return 0;
}