#include <iostream>      // For input/output stream operations
#include <cmath>         // For mathematical functions like sqrt
#include <fstream>       // For file input/output
using namespace std;     // Use the standard namespace

// Template swap function to swap two variables of any type
template<typename T>
void mySwap(T& a, T& b) {
    T temp = a;          // Store value of a in temp
    a = b;               // Assign value of b to a
    b = temp;            // Assign value of temp (original a) to b
}

// Template bubble sort function to sort an array of any type
template<typename T>
void bubbleSort(T* arr, int n) {
    for (int i = 0; i < n - 1; ++i) {            // Outer loop for passes
        for (int j = 0; j < n - i - 1; ++j) {    // Inner loop for comparisons
            if (!(arr[j] > arr[j + 1])) {        // If arr[j] is not greater than arr[j+1]
                mySwap(arr[j], arr[j + 1]);      // Swap them to sort in decreasing order
            }
        }
    }
}

// Class to represent complex numbers
class Complex {
private:
    double real;         // Real part of the complex number
    double imaginary;    // Imaginary part of the complex number
public:
    Complex() {}         // Default constructor
    Complex(double r, double imag) : real(r), imaginary(imag) {} // Parameterized constructor
    Complex(const Complex& other) : real(other.real), imaginary(other.imaginary) {} // Copy constructor

    // Function to calculate the modulus of the complex number
    double modulus() const {
        return sqrt(real * real + imaginary * imaginary);
    }

    // Assignment operator overload
    Complex& operator = (const Complex& other) {
        if (this != &other) {        // Check for self-assignment
            real = other.real;
            imaginary = other.imaginary;
        }
        return *this;
    }

    // Greater-than operator overload to compare by modulus
    bool operator > (const Complex& other) const {
        return modulus() > other.modulus();
    }

    // Function to print the complex number
    void print() const {
        cout << real << " + " << imaginary << "i" << endl;
    }
};

int main() {
    // Open the input file containing complex numbers
    ifstream fin("E:/Programming-2/PracticeFinal/complex.txt");
    if (!fin) {      // Check if file opened successfully
        cout << "Cannot open input file.\n";
        return 1;    // Exit if file cannot be opened
    }

    int n;           // Number of complex numbers
    fin >> n;        // Read the number of complex numbers from file
    Complex* arr = new Complex[n];   // Dynamically allocate array of Complex

    // Read each complex number from file
    for (int i = 0; i < n; ++i) {
        double r, im;
        fin >> r >> im;              // Read real and imaginary parts
        arr[i] = Complex(r, im);     // Assign to array
    }
    fin.close();                     // Close the file

    // Sort the array in decreasing order of modulus using template bubble sort
    bubbleSort(arr, n);

    cout << "Complex numbers in decreasing order of modulus:\n";
    // Print each complex number and its modulus
    for (int i = 0; i < n; ++i) {
        arr[i].print();
        cout << " |modulus| = " << arr[i].modulus() << endl;
    }

    delete[] arr;    // Free dynamically allocated memory
    return 0;        // End of program
}

/*
    Summary of Program Functionality and Concepts Demonstrated

    This program reads a list of complex numbers from a file, sorts them in decreasing order based on their modulus (magnitude), 
    and displays the sorted list along with each number’s modulus.

    Concepts demonstrated:
    - Templates: Uses function templates (mySwap and bubbleSort) to create generic functions for any data type.
    - Operator Overloading: The Complex class overloads the '>' operator to compare complex numbers by their modulus.
    - Dynamic Memory Allocation: Dynamically allocates an array of Complex objects based on the input file.
    - File Input/Output: Reads complex numbers from a file, demonstrating file handling in C++.
    - Object-Oriented Programming: The Complex class encapsulates properties and behaviors of complex numbers.
    - Const-Correctness: Member functions that do not modify the object are marked as const.

    Overall, the program showcases generic programming, object-oriented design, and file handling in C++.
*/

/*
    Assignment Guide: Step-by-Step Solution Approach

    1. **Define a Complex Number Class**
       - Create a class `Complex` to represent complex numbers.
       - Include member variables for the real and imaginary parts.
       - Implement constructors, a function to compute the modulus, and overload the `>` operator for comparison.

    2. **Implement Template Functions**
       - Write a template `mySwap` function to swap two variables of any type.
       - Write a template `bubbleSort` function to sort an array of any type in decreasing order using the overloaded `>` operator.

    3. **Read Input from File**
       - Open the input file containing the number of complex numbers and their values.
       - Dynamically allocate an array of `Complex` objects.
       - Read the real and imaginary parts from the file and store them in the array.

    4. **Sort the Array**
       - Use the template `bubbleSort` function to sort the array of complex numbers in decreasing order of their modulus.

    5. **Display the Results**
       - Print each complex number and its modulus in the sorted order.

    6. **Clean Up**
       - Release any dynamically allocated memory before program termination.

    This approach ensures the program is modular, reusable, and demonstrates key C++ concepts such as templates, operator overloading, file I/O, and object-oriented programming.
*/