// Vector.h
#ifndef VECTOR_H
#define VECTOR_H

#include <cassert>
#include <iostream>

class Vector {
private:
    int mSize;
    double* mData;

public:
    // Constructor
    Vector(int size);

    // Copy constructor
    Vector(const Vector& other);

    // Destructor
    ~Vector();

    // Assignment operator
    Vector& operator=(const Vector& other);

    // Overload [] (0-based indexing)
    double& operator[](int index);             // Non-const version
    const double& operator[](int index) const; // Const version

    // Overload () (1-based indexing)
    double& operator()(int index);             // Non-const version

    // Vector operations
    Vector operator+(const Vector& other) const;
    Vector operator-(const Vector& other) const;
    Vector operator*(double scalar) const;

    // Getter for size
    int Size() const;
    

    // Print
    void Print() const;
};

#endif