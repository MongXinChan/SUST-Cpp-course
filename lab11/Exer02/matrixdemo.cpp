#include <iostream>
#include <memory>
#include "matrix.h"

int main()
{
    Matrix m1(3,4);
    Matrix m2(2,3);

    std::cout << " m2 (Before) : "<< m2 << std::endl;

    m2 = m1;
    m1.setElement(1,2, 4.5f);
    std::cout << m2.getElement(1,2) << std::endl;

    std::cout << " m1= " <<m1 << std::endl;
    std::cout << " m2 (After) : " << m2 << std::endl;

    return 0;
}