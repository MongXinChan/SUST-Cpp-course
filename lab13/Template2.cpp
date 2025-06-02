#include <iostream>
#include <string>

template <typename T>
class Print {
public:
    void print(T value) {
        std::cout << value << std::endl;
    }
};

// Full specialization
template <>
class Print<std::string> {
public:
    void print(const std::string& value) {
        std::cout << "\"" << value << "\"" << std::endl;
    }
};

int main() {
    Print<int> p1;
    p1.print(42);  // Calls the general template class

    Print<std::string> p2;
    p2.print("Hello, World!");  // Calls the fully specialized version
    return 0;
}