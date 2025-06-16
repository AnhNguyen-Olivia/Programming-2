/*
Implement a function to multiply two matrices of the same data type.
*/

#include <iostream>   // Include for input/output stream operations (std::cout, std::endl)
#include <cassert>    // Include for runtime assertions (assert)

// Template class for a generic Matrix
template <typename T> // Allow the Matrix to store any data type (int, float, etc.)
class Matrix {
private:
    int mRows;      // Number of rows in the matrix
    int mCols;      // Number of columns in the matrix
    T* mData;       // Pointer to a dynamically allocated array holding matrix data

public:
    // Constructor: initializes matrix with given rows and columns, allocates memory, zero-initializes
    Matrix(int rows, int cols)
        : mRows(rows), mCols(cols), mData(new T[rows * cols]{}) {} // Allocate memory for rows*cols elements, zero-initialize

    // Copy constructor: creates a deep copy of another matrix
    Matrix(const Matrix& other)
        : mRows(other.mRows), mCols(other.mCols), mData(new T[other.mRows * other.mCols]) { // Allocate memory for the copy
        for (int i = 0; i < mRows * mCols; ++i) // Loop through all elements
            mData[i] = other.mData[i]; // Copy each element from the other matrix
    }

    // Assignment operator: assigns another matrix to this one (deep copy)
    Matrix& operator=(const Matrix& other) {
        if (this != &other) { // Check for self-assignment
            delete[] mData;   // Free old memory
            mRows = other.mRows; // Copy number of rows
            mCols = other.mCols; // Copy number of columns
            mData = new T[mRows * mCols]; // Allocate new memory
            for (int i = 0; i < mRows * mCols; ++i) // Loop through all elements
                mData[i] = other.mData[i]; // Copy each element
        }
        return *this; // Return reference to this object
    }

    // Destructor: releases allocated memory
    ~Matrix() {
        delete[] mData; // Free the dynamically allocated memory
    }

    // Access element at (row, col) with bounds checking (modifiable)
    T& at(int row, int col) {
        assert(row >= 0 && row < mRows && col >= 0 && col < mCols); // Check that indices are valid
        return mData[row * mCols + col]; // Return reference to the element at (row, col) in row-major order
    }

    // Access element at (row, col) with bounds checking (read-only)
    const T& at(int row, int col) const {
        assert(row >= 0 && row < mRows && col >= 0 && col < mCols); // Check that indices are valid
        return mData[row * mCols + col]; // Return const reference to the element at (row, col)
    }

    // Multiply this matrix by another, return the result as a new matrix
    Matrix<T> multiply(const Matrix<T>& other) const {
        assert(mCols == other.mRows); // Ensure matrices can be multiplied (columns of first == rows of second)
        Matrix<T> result(mRows, other.mCols); // Create result matrix with appropriate dimensions

        // Standard matrix multiplication algorithm
        for (int i = 0; i < mRows; ++i) { // For each row of the first matrix
            for (int j = 0; j < other.mCols; ++j) { // For each column of the second matrix
                T sum = T{}; // Initialize sum to zero (default value for type T)
                for (int k = 0; k < mCols; ++k) { // For each element in the row/column
                    sum += this->at(i, k) * other.at(k, j); // Multiply and accumulate
                }
                result.at(i, j) = sum; // Store the computed value in the result matrix
            }
        }

        return result; // Return the resulting matrix
    }

    // Print the matrix to standard output
    void print() const {
        for (int i = 0; i < mRows; ++i) { // For each row
            for (int j = 0; j < mCols; ++j) { // For each column
                std::cout << at(i, j) << " "; // Print the element followed by a space
            }
            std::cout << "\n"; // Print newline after each row
        }
    }
};

int main() {
    // Create a 2x3 matrix and set its elements
    Matrix<int> mat1(2, 3); // Declare a 2-row, 3-column matrix of integers
    mat1.at(0, 0) = 1; mat1.at(0, 1) = 2; mat1.at(0, 2) = 3; // Set first row
    mat1.at(1, 0) = 4; mat1.at(1, 1) = 5; mat1.at(1, 2) = 6; // Set second row

    // Create a 3x2 matrix and set its elements
    Matrix<int> mat2(3, 2); // Declare a 3-row, 2-column matrix of integers
    mat2.at(0, 0) = 7; mat2.at(0, 1) = 8;   // Set first row
    mat2.at(1, 0) = 9; mat2.at(1, 1) = 10;  // Set second row
    mat2.at(2, 0) = 11; mat2.at(2, 1) = 12; // Set third row

    // Multiply mat1 and mat2, store the result
    Matrix<int> result = mat1.multiply(mat2); // Multiply the two matrices

    // Print the resulting matrix
    result.print(); // Output the result to the console

    return 0; // Indicate successful execution
}

/*
This program demonstrates how to implement a generic Matrix class in C++ using templates and dynamic memory allocation.

**What does the program do?**
- It defines a Matrix class template that can store elements of any data type (e.g., int, float, double).
- It allows you to create matrices of any size, set and get their elements, and multiply two matrices together using standard matrix multiplication rules.
- It manages memory manually (without using std::vector), showing how to safely allocate, copy, and free resources.

**Key C++ Concepts Demonstrated:**

1. **Templates**  
   Templates allow you to write generic code that works with any data type.  
   **Syntax Example:**  
   ```cpp
   template <typename T>
   class Matrix { ... };
   Matrix<int> m1(2, 3);    // Matrix of integers
   Matrix<double> m2(3, 2); // Matrix of doubles
   ```

2. **Dynamic Memory Management**  
   The program uses `new` and `delete[]` to allocate and free memory for the matrix data.  
   **Syntax Example:**  
   ```cpp
   mData = new T[rows * cols]; // Allocate memory for matrix elements
   delete[] mData;             // Free memory in destructor
   ```

3. **The Rule of Three**  
   When a class manages resources, you must define:
   - A destructor to free resources
   - A copy constructor to copy resources
   - An assignment operator to assign resources  
   **Syntax Example:**  
   ```cpp
   ~Matrix() { delete[] mData; }
   Matrix(const Matrix& other) { ... }
   Matrix& operator=(const Matrix& other) { ... }
   ```

4. **Matrix Multiplication**  
   The program multiplies two matrices using the standard algorithm:  
   If A is m×n and B is n×p, then C = A × B is m×p, and  
   `C[i][j] = sum(A[i][k] * B[k][j]) for k = 0 to n-1`  
   **Syntax Example:**  
   ```cpp
   for (int i = 0; i < mRows; ++i)
       for (int j = 0; j < other.mCols; ++j)
           for (int k = 0; k < mCols; ++k)
               result.at(i, j) += this->at(i, k) * other.at(k, j);
   ```

5. **Bounds Checking**  
   The `at(row, col)` function uses `assert` to ensure indices are valid, preventing out-of-bounds access.

**Example Usage:**

```cpp
Matrix<int> mat1(2, 3); // 2 rows, 3 columns
mat1.at(0, 0) = 1; mat1.at(0, 1) = 2; mat1.at(0, 2) = 3;
mat1.at(1, 0) = 4; mat1.at(1, 1) = 5; mat1.at(1, 2) = 6;

Matrix<int> mat2(3, 2); // 3 rows, 2 columns
mat2.at(0, 0) = 7; mat2.at(0, 1) = 8;
mat2.at(1, 0) = 9; mat2.at(1, 1) = 10;
mat2.at(2, 0) = 11; mat2.at(2, 1) = 12;

Matrix<int> result = mat1.multiply(mat2); // Multiply the matrices
result.print(); // Output:
               // 58  64
               // 139 154
```

**Lessons Learned:**
- How to use C++ templates for generic programming.
- How to manage dynamic memory safely (constructor, destructor, copy constructor, assignment operator).
- How to implement matrix multiplication manually.
- How to encapsulate data and operations in a class.
- The importance of bounds checking and resource management in C++.
*/
