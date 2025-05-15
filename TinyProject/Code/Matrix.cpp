// Matrix.cpp
    #include "Vector.h"
    #include "Matrix.h"
    #include "LinearSystem.h"

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

    Matrix Matrix::IdentityMatrix(int size) {
        Matrix I(size, size);
        for (int i = 1; i <= size; ++i) {
            I(i, i) = 1.0; // Diagonal entries set to 1.0
        }
        return I;
    }

    Matrix Matrix::PseudoInverse() const {
        if (mNumRows >= mNumCols) {
            // Over-determined: (A^T A)^-1 A^T
            Matrix A_T = this->Transpose();
            Matrix ATA = A_T * (*this);

            // Invert ATA
            Matrix ATA_inv(mNumCols, mNumCols);
            for (int i = 1; i <= mNumCols; ++i) {
                Vector e(mNumCols);
                e(i) = 1.0;
                LinearSystem ls(ATA, e);
                Vector col = ls.Solve();
                for (int j = 1; j <= mNumCols; ++j) {
                    ATA_inv(j, i) = col(j);
                }
            }
            return ATA_inv * A_T;
        } else {
            // Under-determined: A^T (A A^T)^-1
            Matrix A_T = this->Transpose();
            Matrix AAT = (*this) * A_T;

            // Invert AAT
            Matrix AAT_inv(mNumRows, mNumRows);
            for (int i = 1; i <= mNumRows; ++i) {
                Vector e(mNumRows);
                e(i) = 1.0;
                LinearSystem ls(AAT, e);
                Vector col = ls.Solve();
                for (int j = 1; j <= mNumRows; ++j) {
                    AAT_inv(j, i) = col(j);
                }
            }
            return A_T * AAT_inv;
        }
    }

    Matrix Matrix::Transpose() const {
        Matrix result(mNumCols, mNumRows); // Swap rows and columns
        for (int i = 1; i <= mNumRows; ++i) {
            for (int j = 1; j <= mNumCols; ++j) {
                result(j, i) = (*this)(i, j); // Use 1-based indexing
            }
        }
        return result;
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
