#include <iostream>

int main() {
    int a = 5, b = 0;
    double d;
    try {
        if (b == 0) {
            throw "The divisor can not be zero!"; // Throwing a C-style string
        }
        d = static_cast<double>(a) / b;
        std::cout << "The quotient of " << a << "/" << b << " is: " << d << std::endl;
    } catch (const char* p_error) { // Catches const char* type exceptions
        std::cerr << p_error << std::endl;
    } catch (int error_code) { // Catches int type exceptions (won't match here)
        std::cerr << "Exception code: " << error_code << std::endl;
    }
    return 0;
}