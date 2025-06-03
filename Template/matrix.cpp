#include <iostream>
using namespace std;

// This is a template class for a matrix that can hold elements of any type T
template <typename T>
class norm {
    private:
        T matrix [100][100];           // Assuming a maximum size of 100x100
        int n;

        // Functions to calculaate the absolute value of T
        T abs(T x) { 
            return x < 0 ? -x : x;     // if x is negative, return -x, else return x  
        }

        // Function to calculate square root
        double sqrtManual(double x) {   
            double guess = x / 2.0;                     // Initial guess
            for (int i = 0; i < 10; ++i) {              // Iterate to improve the guess
                guess = (guess + x / guess) / 2.0;      // Update guess using the Babylonian method
            }
            return guess;
        };

    public:

        // Function to input the matrix elements
        void input(){ 
            cout << "Enter the size of the matrix (n x n): ";
            cin >> n;
            cout << "Enter the elements of the matrix:\n";
            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < n; ++j) {
                    cin >> matrix[i][j];                    //matrix of ith row and jth column
                }
            }
        }

        // Function to display the matrix
        void display() {
            cout << "Matrix (" << n << "x" << n << "):\n";
            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < n; ++j) {
                    cout << matrix[i][j] << " ";            // Print each element in the row
                }
                cout << endl;                               // New line after each row
            }
        }

        // Function to calculate the Frobenius norm of the matrix
        double frobeniusNorm() {
            double sum = 0.0;                                       // Initialize sum to zero
            for (int i = 0; i < n; ++i) {                           // Iterate through each row
                for (int j = 0; j < n; ++j) {
                    sum += abs(matrix[i][j]) * abs(matrix[i][j]);   // Square each element and add to sum
                }
            }
            return sqrtManual(sum);                                 // Return the square root of the sum
        }

        T rowSumNorm(){
            T maxRowSum = 0;                        // Initialize maximum row sum to zero
            for (int i = 0; i < n; ++i) {           // Iterate through each row
                T rowSum = 0;                       // Initialize row sum for the current row
                for (int j = 0; j < n; ++j) {       // Iterate through each column in the current row
                    rowSum += abs(matrix[i][j]);    // Calculate the absolute sum of the current row
                }
                if (rowSum > maxRowSum) {           // Update maximum row sum if current row sum is greater
                    maxRowSum = rowSum;             
                }
            }
            return maxRowSum;                       // Return the maximum row sum
        }

        T totalNorm() {                             // Calculate the total norm of the matrix
        T maxVal = 0;                               // Initialize maximum value to zero
        for (int i = 0; i < n; ++i)                 // Iterate through each row
            for (int j = 0; j < n; ++j)             // Iterate through each column
                if (abs(matrix[i][j]) > maxVal)     // Update maxVal if current element is greater
                    maxVal = abs(matrix[i][j]);   
        return n * maxVal;                          // Return the total norm, which is n times the maximum absolute value found
    }

    void printNorms() {
        cout << "Frobenius Norm: " << frobeniusNorm() << endl;
        cout << "Row Sum Norm: " << rowSumNorm() << endl;
        cout << "Total Norm: " << totalNorm() << endl;
    }
};

int main() {
    norm<int> matrixInt;           // Create an instance of the norm class for integers
    matrixInt.input();             // Input the matrix elements
    matrixInt.display();           // Display the matrix
    matrixInt.printNorms();        // Print the norms of the matrix

    norm<double> matrixDouble;     // Create an instance of the norm class for doubles
    matrixDouble.input();          // Input the matrix elements
    matrixDouble.display();        // Display the matrix
    matrixDouble.printNorms();     // Print the norms of the matrix

    return 0;                      // Return success
}