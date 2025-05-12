#include "vabs.h"
#include <iostream>
#include <vector>

int main() {
    std::vector<int> int_vec = {-1, -2, -3};
    std::vector<float> float_vec = {-1.1f, -2.2f, -3.3f};
    std::vector<double> double_vec = {-1.1, -2.2, -3.3};

    vabs(int_vec.data(), int_vec.size());
    vabs(float_vec.data(), float_vec.size());
    vabs(double_vec.data(), double_vec.size());

    for (int v : int_vec) std::cout << v << " ";
    std::cout << std::endl;

    for (float v : float_vec) std::cout << v << " ";
    std::cout << std::endl;

    for (double v : double_vec) std::cout << v << " ";
    std::cout << std::endl;

    return 0;
}