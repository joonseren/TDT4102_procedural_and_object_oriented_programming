// TDT4102 Øving 8

#pragma once
#include <iostream>
#include <cassert>
#include <utility>


// 2, 4, 5
class Matrix {
private:
    double** matrixData;
    int rows;
    int columns;

public:
    Matrix(int nRows, int nColumns);
    explicit Matrix(int nRows);
    ~Matrix();
    double get(int row, int col) const;
    void set(int row, int col, double value);
    int getRows() const;
    int getColumns() const;
    friend std::ostream& operator<<(std::ostream& os, const Matrix& mtrx);
    Matrix(const Matrix& other);
    Matrix& operator=(const Matrix rhs);
    Matrix& operator+=(const Matrix& rhs);
};