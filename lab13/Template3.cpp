#include <iostream>
#include <string>

template <typename T, typename U>
class Pair {
public:
    T first;
    U second;

    void print() {
        std::cout << first << ", " << second << std::endl;
    }
};

// Partial specialization
template <typename T>
class Pair<T, int> {
public:
    T first;
    int second;

    void print() {
        std::cout << first << " (int) " << second << std::endl;
    }
};

int main() {
    Pair<std::string, double> p1{"Hello", 3.14};
    p1.print();  // Calls the general template class

    Pair<std::string, int> p2{"World", 42};
    p2.print();  // Calls the partially specialized version
    return 0;
}