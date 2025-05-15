// Matrix.h
#ifndef MATRIX_H
#define MATRIX_H

#include <cassert>
#include <iostream>

class Vector; // ✅ Forward declaration

class Matrix {
private:
    int mNumRows;
    int mNumCols;
    double** mData;

public:
    Matrix(int numRows, int numCols);
    Matrix(const Matrix& other);
    ~Matrix();

    Matrix& operator=(const Matrix& other);

    int GetNumRows() const;
    int GetNumCols() const;

    double& operator()(int i, int j);
    const double& operator()(int i, int j) const;

    Matrix operator+(const Matrix& other) const;
    Matrix operator-(const Matrix& other) const;
    Matrix operator*(double scalar) const;
    Vector operator*(const Vector& vec) const; // ✅ Only declared here
    Matrix operator*(const Matrix& other) const;

    Matrix Transpose() const;
    Matrix PseudoInverse() const;
    static Matrix IdentityMatrix(int size);

    void Print() const;
};

#endif