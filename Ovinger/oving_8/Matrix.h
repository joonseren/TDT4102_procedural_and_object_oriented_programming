// TDT4102 Øving 8

#pragma once
#include <iostream>
#include <cassert>


// 2a), b), c), d), e), f), g)
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
    std::string getRows() const;
    std::string getColumns() const;
    friend std::ostream& operator<<(std::ostream& os, const Matrix& mtrx);
};