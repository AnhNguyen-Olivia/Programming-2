#include "Matrix.h"
#include "Vector.h"
#include "LinearSystem.h"

class NonSquareLinearSystem {
private:
    Matrix _A;
    Vector _b;

public:
    NonSquareLinearSystem(const Matrix& A, const Vector& b);
    Vector SolveWithPseudoInverse() const;
    Vector SolveWithTikhonov(double lambda) const;
};