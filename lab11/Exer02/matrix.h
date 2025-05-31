#pragma once

#include <cstddef>
#include <memory>
#include <iostream>
#include <stdexcept> 

class Matrix{
  private:
    size_t rows;
    size_t cols;
    std::shared_ptr<float[]> data;
  public:
    Matrix(size_t r, size_t c)
    {
        if ( r * c == 0)
        {
            rows = 0;
            cols = 0;
            data = nullptr;
        }
        else{
            rows = r;
            cols = c;
            data = std::shared_ptr<float[]>(new float[r * c]);
        }
    }

    // Accessor for rows
    size_t getRows() const {
        return rows;
    }

    // Accessor for columns
    size_t getCols() const {
        return cols;
    }

    float getElement(size_t r,size_t c) const{ // 不修改矩阵的内容
        if (r >= rows || c>=cols || !data){
            throw std::out_of_range("Matrix::getElement: Index out of range or data is null.");
        }
        return data[r * cols +c];
    }

    void setElement(size_t r, size_t c, float value) {
        if (r >= rows || c >= cols || !data) {
            throw std::out_of_range("Matrix::setElement: Index out of range or data is null.");
        }
        data[r * cols + c] = value; // Corrected indexing
    }

    Matrix(const Matrix & m): rows(m.rows), cols(m.cols), data(m.data){}
    friend std::ostream & operator<<(std::ostream & os, const Matrix & m)
    {
        os << "(" << m.rows << "x" << m.cols << ") is" << std::endl;
        os << "[" << std::endl;
        for (size_t r = 0; r < m.rows; r++)
        {
            for(size_t c = 0; c < m.cols; c++)
                os << m.data[r * m.cols + c] << " ";
            os << std::endl;
        }
        os << "]";
        return os;
    }

    //out-class implement of the friend function 
    friend Matrix operator+(const Matrix& lhs, const Matrix& rhs);
};