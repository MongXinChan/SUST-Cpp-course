// src/test_programer.cpp
#include <cstdio>       // For printf
#include "swap_lib.h"   // Needs to find swap_lib.h in the 'include' folder

int main() {
    int num1 = 10;
    int num2 = 20;

    printf("Original values: num1 = %d, num2 = %d\n", num1, num2);

    // Call the swap function from the library
    swap_integers(num1, num2);

    printf("After swap_integers (from libswap.a): num1 = %d, num2 = %d\n", num1, num2);

    return 0;
}