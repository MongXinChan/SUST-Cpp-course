#include <iostream>
#include <vector>

template <typename T>
void print(T value) {
    std::cout << value << std::endl;
}

// Function template specialization
template <>
void print<std::vector<int>>(const std::vector<int>& value) {
    for (int v : value) {
        std::cout << v << " ";
    }
    std::cout << std::endl;
}

int main() {
    int a = 42;
    print(a);  // Calls the general template function

    std::vector<int> vec = {1, 2, 3, 4, 5};
    print(vec);  // Calls the specialized function
    return 0;
}