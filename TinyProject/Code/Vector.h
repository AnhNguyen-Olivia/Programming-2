#ifndef VECTOR_H
#define VECTOR_H

#include <cassert>
#include <iostream>

class Matrix; // ✅ Forward declaration only — don't include Matrix.h

class Vector {
private:
    int mSize;
    double* mData;

public:
    Vector(int size);
    Vector(int size, double initialValue);
    Vector(const Vector& other);
    ~Vector();

    Vector& operator=(const Vector& other);

    double& operator[](int index);
    const double& operator[](int index) const;

    double& operator()(int index);             
    const double& operator()(int index) const;

    Vector operator+(const Vector& other) const;
    Vector operator-(const Vector& other) const;
    Vector operator*(double scalar) const;

    int Size() const;
    void Print() const;

    Matrix ToMatrix() const; // ✅ Still valid with forward declaration
};

#endif
