#ifndef LINEARSYSTEM_HPP
#define LINEARSYSTEM_HPP

#include "Matrix.h"
#include "Vector.h"

class LinearSystem {
protected:
    int mSize;
    Matrix* mpA;
    Vector* mpb;

public:
    LinearSystem(const Matrix& A, const Vector& b);
    virtual ~LinearSystem();

    // Solve Ax = b using Gaussian elimination
    virtual Vector Solve();

private:
    LinearSystem(); // prevent default constructor
    LinearSystem(const LinearSystem& other); // prevent copy constructor
};

#endif