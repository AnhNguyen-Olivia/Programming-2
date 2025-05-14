// Matrix.h
#ifndef MATRIX_H
#define MATRIX_H

#include <cassert>
#include <iostream>
#include "Vector.h"

class Matrix {
private:
    int mNumRows;
    int mNumCols;
    double** mData;  // 2D array

public:
    // Constructor
    Matrix(int numRows, int numCols);

    // Copy constructor
    Matrix(const Matrix& other);

    // Destructor
    ~Matrix();

    // Assignment operator
    Matrix& operator=(const Matrix& other);

    // Accessors
    int GetNumRows() const;
    int GetNumCols() const;

    // Access operator ()
    double& operator()(int i, int j);       // 1-based
    const double& operator()(int i, int j) const;

    // Operators
    Matrix operator+(const Matrix& other) const;
    Matrix operator-(const Matrix& other) const;
    Matrix operator*(double scalar) const;
    Vector operator*(const Vector& vec) const;
    Matrix operator*(const Matrix& other) const;

    // For now we’ll skip determinant/inverse (we’ll do them next step)

    // Print (for testing)
    void Print() const;
};

#endif
