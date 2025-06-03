#include <iostream>
#include <cassert>
#include <vector>

template <typename T>
class Matrix {
private:
    int mRows;
    int mCols;
    std::vector<T> mData;  // 1D contiguous storage

public:
    Matrix(int rows, int cols)
        : mRows(rows), mCols(cols), mData(rows * cols, T{}) {}

    T& at(int row, int col) {
        assert(row >= 0 && row < mRows && col >= 0 && col < mCols);
        return mData[row * mCols + col];
    }

    const T& at(int row, int col) const {
        assert(row >= 0 && row < mRows && col >= 0 && col < mCols);
        return mData[row * mCols + col];
    }

    Matrix<T> multiply(const Matrix<T>& other) const {
        assert(mCols == other.mRows);
        Matrix<T> result(mRows, other.mCols);

        for (int i = 0; i < mRows; ++i) {
            for (int j = 0; j < other.mCols; ++j) {
                T sum = T{};
                for (int k = 0; k < mCols; ++k) {
                    sum += this->at(i, k) * other.at(k, j);
                }
                result.at(i, j) = sum;
            }
        }

        return result;
    }

    void print() const {
        for (int i = 0; i < mRows; ++i) {
            for (int j = 0; j < mCols; ++j) {
                std::cout << at(i, j) << " ";
            }
            std::cout << "\n";
        }
    }
};

int main() {
    Matrix<int> mat1(2, 3);
    mat1.at(0, 0) = 1; mat1.at(0, 1) = 2; mat1.at(0, 2) = 3;
    mat1.at(1, 0) = 4; mat1.at(1, 1) = 5; mat1.at(1, 2) = 6;

    Matrix<int> mat2(3, 2);
    mat2.at(0, 0) = 7; mat2.at(0, 1) = 8;
    mat2.at(1, 0) = 9; mat2.at(1, 1) = 10;
    mat2.at(2, 0) = 11; mat2.at(2, 1) = 12;

    Matrix<int> result = mat1.multiply(mat2);

    result.print();

    return 0;
}
