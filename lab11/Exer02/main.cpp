#include <iostream>
#include "matrix.h" // 假设 Matrix 类在 matrix.h 中

int main() {
    /** 
    try {
        Matrix m1(2, 2);
        m1.setElement(0, 0, 1.0f); m1.setElement(0, 1, 2.0f);
        m1.setElement(1, 0, 3.0f); m1.setElement(1, 1, 4.0f);

        Matrix m2(2, 2);
        m2.setElement(0, 0, 0.5f); m2.setElement(0, 1, 1.0f);
        m2.setElement(1, 0, 1.5f); m2.setElement(1, 1, 2.0f);

        std::cout << "Matrix m1:" << std::endl << m1 << std::endl;
        std::cout << "Matrix m2:" << std::endl << m2 << std::endl;

        Matrix m3 = m1 + m2; // 使用重载的 operator+
        std::cout << "Matrix m3 = m1 + m2:" << std::endl << m3 << std::endl;

        Matrix m4(2, 3); // 不同维度
        // Matrix m5 = m1 + m4; // 这行会抛出 std::invalid_argument 异常

    } catch (const std::exception& e) {
        std::cerr << "Exception: " << e.what() << std::endl;
    }
    */

    Matrix a(3,4);
    a.setElement(1,2,3);
    std::cout<< "a "<< a<< std::endl;
    Matrix b(3,4);
    b.setElement(2,3,4); // rows&cols start from 0
    std::cout<< "b "<< b<< std::endl;
    Matrix c = a + b;
    std::cout<< "c "<< c<< std::endl;
    Matrix d = c;
    std::cout<< "Before assignment,d "<< d<< std::endl;
    d = b;
    std::cout<< "After assignment,d "<< d<< std::endl;

    return 0;
}