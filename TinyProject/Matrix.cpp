// Matrix.cpp
#include "Vector.h"
#include "Matrix.h"

// Constructor
Matrix::Matrix(int numRows, int numCols) {
    assert(numRows > 0 && numCols > 0);
    mNumRows = numRows;
    mNumCols = numCols;

    mData = new double*[mNumRows];
    for (int i = 0; i < mNumRows; ++i) {
        mData[i] = new double[mNumCols];
        for (int j = 0; j < mNumCols; ++j) {
            mData[i][j] = 0.0;
        }
    }
}

// Copy constructor
Matrix::Matrix(const Matrix& other) {
    mNumRows = other.mNumRows;
    mNumCols = other.mNumCols;

    mData = new double*[mNumRows];
    for (int i = 0; i < mNumRows; ++i) {
        mData[i] = new double[mNumCols];
        for (int j = 0; j < mNumCols; ++j) {
            mData[i][j] = other.mData[i][j];
        }
    }
}

// Destructor
Matrix::~Matrix() {
    for (int i = 0; i < mNumRows; ++i) {
        delete[] mData[i];
    }
    delete[] mData;
}

// Assignment
Matrix& Matrix::operator=(const Matrix& other) {
    if (this == &other) return *this;

    // Clean up
    for (int i = 0; i < mNumRows; ++i)
        delete[] mData[i];
    delete[] mData;

    // Copy
    mNumRows = other.mNumRows;
    mNumCols = other.mNumCols;
    mData = new double*[mNumRows];
    for (int i = 0; i < mNumRows; ++i) {
        mData[i] = new double[mNumCols];
        for (int j = 0; j < mNumCols; ++j) {
            mData[i][j] = other.mData[i][j];
        }
    }

    return *this;
}

// Getters
int Matrix::GetNumRows() const { return mNumRows; }
int Matrix::GetNumCols() const { return mNumCols; }

// Access operator ()
double& Matrix::operator()(int i, int j) {
    assert(i >= 1 && i <= mNumRows && j >= 1 && j <= mNumCols);
    return mData[i - 1][j - 1];
}

const double& Matrix::operator()(int i, int j) const {
    assert(i >= 1 && i <= mNumRows && j >= 1 && j <= mNumCols);
    return mData[i - 1][j - 1];
}

// + operator
Matrix Matrix::operator+(const Matrix& other) const {
    assert(mNumRows == other.mNumRows && mNumCols == other.mNumCols);
    Matrix result(mNumRows, mNumCols);
    for (int i = 0; i < mNumRows; ++i)
        for (int j = 0; j < mNumCols; ++j)
            result.mData[i][j] = mData[i][j] + other.mData[i][j];
    return result;
}

// - operator
Matrix Matrix::operator-(const Matrix& other) const {
    assert(mNumRows == other.mNumRows && mNumCols == other.mNumCols);
    Matrix result(mNumRows, mNumCols);
    for (int i = 0; i < mNumRows; ++i)
        for (int j = 0; j < mNumCols; ++j)
            result.mData[i][j] = mData[i][j] - other.mData[i][j];
    return result;
}

// * scalar
Matrix Matrix::operator*(double scalar) const {
    Matrix result(mNumRows, mNumCols);
    for (int i = 0; i < mNumRows; ++i)
        for (int j = 0; j < mNumCols; ++j)
            result.mData[i][j] = mData[i][j] * scalar;
    return result;
}

// * vector
Vector Matrix::operator*(const Vector& vec) const {
    assert(mNumCols == vec.Size());
    Vector result(mNumRows);
    for (int i = 0; i < mNumRows; ++i) {
        result[i] = 0.0;
        for (int j = 0; j < mNumCols; ++j)
            result[i] += mData[i][j] * vec[j];
    }
    return result;
}

// * matrix
Matrix Matrix::operator*(const Matrix& other) const {
    assert(mNumCols == other.mNumRows);
    Matrix result(mNumRows, other.mNumCols);
    for (int i = 0; i < mNumRows; ++i)
        for (int j = 0; j < other.mNumCols; ++j) {
            result(i + 1, j + 1) = 0.0;
            for (int k = 0; k < mNumCols; ++k)
                result(i + 1, j + 1) += mData[i][k] * other.mData[k][j];
        }
    return result;
}

// Print
void Matrix::Print() const {
    for (int i = 0; i < mNumRows; ++i) {
        std::cout << "[ ";
        for (int j = 0; j < mNumCols; ++j) {
            std::cout << mData[i][j] << " ";
        }
        std::cout << "]\n";
    }
}
