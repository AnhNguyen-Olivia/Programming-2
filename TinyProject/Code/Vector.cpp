// Vector.cpp
#include "Vector.h"
#include "Matrix.h"
#include <iostream>
#include <cassert>

// Constructor
Vector::Vector(int size) {
    assert(size > 0);          // size must be positive
    mSize = size;
    mData = new double[mSize]; // allocate memory
    for (int i = 0; i < mSize; ++i) {
        mData[i] = 0.0;        // initialize with zeros
    }
}

// Copy constructor
Vector::Vector(const Vector& other) {
    mSize = other.mSize;
    mData = new double[mSize];
    for (int i = 0; i < mSize; ++i) {
        mData[i] = other.mData[i];
    }
}

Matrix Vector::ToMatrix() const {
    Matrix mat(mSize, 1);
    for (int i = 1; i <= mSize; ++i) {
        mat(i, 1) = (*this)(i);
    }
    return mat;
}

// Destructor
Vector::~Vector() {
    delete[] mData; // free memory
}

// Assignment operator
Vector& Vector::operator=(const Vector& other) {
    if (this == &other) return *this; // self-assignment check

    delete[] mData; // free old memory

    mSize = other.mSize;
    mData = new double[mSize];
    for (int i = 0; i < mSize; ++i) {
        mData[i] = other.mData[i];
    }
    return *this;
}

// [] operator (0-based)
double& Vector::operator[](int index) {
    assert(index >= 0 && index < mSize);
    return mData[index];
}

// Const version of [] operator (0-based)
const double& Vector::operator[](int index) const {
    assert(index >= 0 && index < mSize);
    return mData[index];
}   

// () operator (1-based)
double& Vector::operator()(int index) {
    assert(index >= 1 && index <= mSize);
    return mData[index - 1];
}

// Const version (1-based)
const double& Vector::operator()(int index) const {
    assert(index >= 1 && index <= mSize);
    return mData[index - 1];
}

// + operator
Vector Vector::operator+(const Vector& other) const {
    assert(mSize == other.mSize);
    Vector result(mSize);
    for (int i = 0; i < mSize; ++i) {
        result.mData[i] = mData[i] + other.mData[i];
    }
    return result;
}

// - operator
Vector Vector::operator-(const Vector& other) const {
    assert(mSize == other.mSize);
    Vector result(mSize);
    for (int i = 0; i < mSize; ++i) {
        result.mData[i] = mData[i] - other.mData[i];
    }
    return result;
}

// * scalar multiplication
Vector Vector::operator*(double scalar) const {
    Vector result(mSize);
    for (int i = 0; i < mSize; ++i) {
        result.mData[i] = mData[i] * scalar;
    }
    return result;
}

// Return size
int Vector::Size() const {
    return mSize;
}

// Print vector (for debugging/testing)
void Vector::Print() const {
    std::cout << "[ ";
    for (int i = 0; i < mSize; ++i) {
        std::cout << mData[i] << " ";
    }
    std::cout << "]\n";
}