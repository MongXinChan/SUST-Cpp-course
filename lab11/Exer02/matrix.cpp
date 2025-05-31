#include "matrix.h"
#include <iostream>


Matrix operator+(const Matrix& lhs, const Matrix& rhs) {
    // 1. 检查维度是否匹配
    if (lhs.getRows() != rhs.getRows() || lhs.getCols() != rhs.getCols()) {
        throw std::invalid_argument("Matrix dimensions must match for addition.");
    }

    // 2. 创建结果矩阵
    // 注意：您的 Matrix 构造函数 Matrix(size_t r, size_t c) 目前只分配内存，
    // 并没有将其初始化为0。这对于加法结果的存储没有问题，因为我们会逐个设置元素。
    Matrix result(lhs.getRows(), lhs.getCols());

    // 如果矩阵是空的 (0行或0列)，直接返回空的 result 矩阵
    if (result.getRows() == 0 || result.getCols() == 0) {
        return result;
    }
    
    // 3. 逐元素相加
    for (size_t r = 0; r < result.getRows(); ++r) {
        for (size_t c = 0; c < result.getCols(); ++c) {
            float sum = lhs.getElement(r, c) + rhs.getElement(r, c);
            result.setElement(r, c, sum);
        }
    }

    // 4. 返回结果矩阵
    return result; // C++ 会处理返回临时对象的效率问题 (通常通过 RVO/NRVO)
}