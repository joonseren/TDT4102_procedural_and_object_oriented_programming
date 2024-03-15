// TDT4102 Øving 8

#include "Matrix.h"



// 2b)
Matrix::Matrix(int nRows, int nColumns) : rows(nRows), columns(nColumns) {
    assert(rows >= 0 && columns >= 0);

    matrixData = new double*[rows];

    for (int i{0}; i < rows; i++) {
        matrixData[i] = new double[columns];

        for (int j{0}; j < columns; j++) {
            matrixData[i][j] = 0.0;
        }
    }

}

Matrix::Matrix(int nRows) : Matrix(nRows, nRows) {
    for (int i{0}; i < rows; i++) {

        for (int j{0}; j < rows; j++) {

            if (i == j) {
                matrixData[i][j] = 1.0;
            }
        }
    }
}

Matrix::~Matrix() {
    for (int i{0}; i < rows; i++) {
        delete[] matrixData[i];
    }
    delete[] matrixData;
    matrixData = nullptr;
}

// 2c)
double Matrix::get(int row, int col) const {
    return matrixData[row][col];
}

void Matrix::set(int row, int col, double value) {
    matrixData[row][col] = value;
}

// 2d)
// Valgfri, gidder ikke å svare #yolo #lol

// 2e)
int Matrix::getRows() const {
    return rows;
}

int Matrix::getColumns() const {
    return columns;
}

// 2f)
std::ostream& operator<<(std::ostream& os, const Matrix& mtrx) {
    for (int i{0}; i < mtrx.rows; i++) {
        for (int j{0}; j < mtrx.columns; j++) {
            os << mtrx.matrixData[i][j] << " ";
        } os << std::endl;
    }
    return os;
}


// 4a)
Matrix::Matrix(const Matrix& other) : rows(other.rows), columns(other.columns) {
    matrixData = new double*[rows];

    for (int i{0}; i < rows; i++) {
        matrixData[i] = new double[columns];
        for (int j{0}; j < columns; j++) {
            matrixData[i][j] = other.matrixData[i][j]; 
        }
    }
}

// 4b)
Matrix& Matrix::operator=(const Matrix rhs) {
    for (int i{0}; i < rows; i++) {
        for (int j{0}; j < columns; j++) {
            std::swap(matrixData[i][j],  rhs.matrixData[i][j]);
        }
    }
    return *this;
}

// 5a)
Matrix& Matrix::operator+=(const Matrix& rhs) {

    assert(this -> getRows() == rhs.getRows() && this -> getColumns() == rhs.getColumns()); 
    for (int i{0}; i < rows; i++) {
        for (int j{0}; j < columns; j++) {
            this -> matrixData[i][j] += rhs.matrixData[i][j];
        }
    
    }
    return *this;
}




