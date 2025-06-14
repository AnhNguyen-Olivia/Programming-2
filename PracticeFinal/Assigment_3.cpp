#include <iostream>      // For input and output streams
#include <cmath>         // For mathematical functions like sqrt
#include <fstream>       // For file input/output
using namespace std;     // Use the standard namespace

class Complex {
private:
    double real;         // Real part of the complex number
    double imaginary;    // Imaginary part of the complex number
public:
    // Default constructor (leaves members uninitialized)
    Complex() {}

    // Constructor with parameters to initialize real and imaginary parts
    Complex(double r, double imag) {
        real = r;
        imaginary = imag;
    }

    // Explicit copy constructor
    Complex(const Complex& other) : real(other.real), imaginary(other.imaginary) {}

    // Calculate the modulus (magnitude) of the complex number
    double modulus() {
        return sqrt(real * real + imaginary * imaginary);
    }

    // Overloaded assignment operator
    Complex& operator = (const Complex& other) {
        if (this != &other) {             // Check for self-assignment
            real = other.real;            // Copy real part
            imaginary = other.imaginary;  // Copy imaginary part
        }
        return *this;                     // Return reference to current object
    }

    // Overloaded comparison operator '>' to compare modulus
    bool operator > (Complex& other) {
        return modulus() > other.modulus();
    }

    // Print the complex number in a+bi format
    void print() {
        cout << real << " + " << imaginary << "i" << endl;
    }

    // Swap function to exchange two Complex objects
    void swap(Complex& a, Complex& b) {
        Complex temp = a;
        a = b;
        b = temp;
    }
};

int main() {
    // Open the input file containing complex numbers
    ifstream fin("E:/Programming-2/PracticeFinal/complex.txt");
    if (!fin) { // Check if file opened successfully
        std::cout << "Cannot open input file.\n";
        return 1; // Exit if file cannot be opened
    }

    int n;
    fin >> n; // Read the number of complex numbers from the file
    Complex* arr = new Complex[n]; // Dynamically allocate array for complex numbers

    // Read each complex number from the file
    for (int i = 0; i < n; ++i) {
        double r, im;
        fin >> r >> im;           // Read real and imaginary parts
        arr[i] = Complex(r, im);  // Store in array
    }
    fin.close(); // Close the file

    // Sort the array in decreasing order of modulus using bubble sort
    for (int i = 0; i < n - 1; ++i) {
        for (int j = 0; j < n - i - 1; ++j) {
            if (!(arr[j] > arr[j + 1])) { // If arr[j] has smaller modulus than arr[j+1]
                swap(arr[j], arr[j + 1]); // Swap them
            }
        }
    }

    // Print the sorted complex numbers and their modulus
    cout << "Complex numbers in decreasing order of modulus:\n";
    for (int i = 0; i < n; ++i) {
        arr[i].print();
        cout << " |modulus| = " << arr[i].modulus() << endl;
    }

    delete[] arr; // Free dynamically allocated memory
    return 0;     // End of program
}

/*
==========================
About the Warning:
==========================
You may see a warning about the "implicitly-declared 'constexpr Complex::Complex(const Complex&)'" being deprecated.
This occurs because you defined a custom copy assignment operator (operator=), but did not explicitly define a copy constructor.
In C++, when you define one of the "big five" (copy constructor, copy assignment operator, move constructor, move assignment operator, destructor),
it is good practice to define the others as needed. This ensures your class behaves correctly and avoids compiler warnings.

How to Fix:
-----------
Add an explicit copy constructor to your Complex class, like this:

class Complex {
    double real, imaginary;
public:
    Complex(double r = 0, double i = 0) : real(r), imaginary(i) {}

    // Explicit copy constructor
    Complex(const Complex& other) : real(other.real), imaginary(other.imaginary) {}

    // ...other member functions...
};

Why Do This?
-------------
For simple classes like this, the compiler-generated copy constructor would work fine,
but adding it explicitly removes the warning and makes your intent clear to anyone reading your code.

==========================
About the Program:
==========================
This program demonstrates how to create and use a custom Complex class in C++ to represent complex numbers,
and how to compare, sort, and print them based on their modulus (magnitude).

What the Assignment Teaches:
----------------------------
1. **Class Design:**  
   - How to encapsulate data (real and imaginary parts) and behavior (modulus calculation, comparison, assignment, printing) in a class.

2. **Operator Overloading:**  
   - How to overload operators (=, >) to make your class behave like built-in types.

3. **File I/O:**  
   - How to read data from a file using ifstream.

4. **Sorting Custom Objects:**  
   - How to sort an array of custom objects (here, using bubble sort and the overloaded > operator).

5. **Memory Management:**  
   - How to use dynamic memory allocation (new and delete[]) for arrays of objects.

How the Code Works:
-------------------
1. **Class Definition**
   - Private Members: `real` and `imaginary` store the real and imaginary parts of the complex number.
   - Constructors:
     - Default constructor: Initializes an empty complex number.
     - Parameterized constructor: Initializes with given real and imaginary values.
     - Copy constructor: Allows copying of complex numbers.
   - Member Functions:
     - `modulus()`: Calculates the magnitude using the formula √(real² + imaginary²).
     - `operator=`: Allows assignment between complex numbers.
     - `operator>`: Compares two complex numbers by their modulus.
     - `print()`: Prints the complex number in a + bi format.
     - `swap()`: Swaps two complex numbers (used in sorting).

2. **Main Function**
   - File Input: Opens a file and reads the number of complex numbers, then reads each complex number’s real and imaginary parts into an array.
   - Sorting: Uses bubble sort to arrange the complex numbers in decreasing order of their modulus, using the overloaded > operator.
   - Output: Prints each complex number and its modulus in sorted order.
   - Cleanup: Frees the dynamically allocated memory.

What You Learn:
---------------
- How to design a class with encapsulation and operator overloading.
- How to use file input to populate objects.
- How to sort objects using custom comparison logic.
- How to print and manage objects in C++.

Summary:
--------
This assignment gives you hands-on practice with C++ classes, 
operator overloading, file I/O, sorting, and dynamic memory—all essential skills for 
object-oriented programming in C++.
*/


/*

==========================================================
Assignment Guidance: Complex Number Class & Sorting in C++
==========================================================

Overview:
---------
This assignment teaches you how to design a C++ class for complex numbers, 
overload operators, perform file I/O, sort custom objects, and manage dynamic memory. 
By following a structured approach, you will gain practical experience with essential 
object-oriented programming concepts in C++.

Step-by-Step Approach:
----------------------
1. **Understand the Problem**
   - You need to create a `Complex` class to represent complex numbers.
   - Implement constructors, assignment, and comparison operators.
   - Read a list of complex numbers from a file.
   - Sort them in decreasing order of their modulus (magnitude).
   - Print the sorted list.

2. **Plan the Class Design**
   - **Data members:**  
     - `real` (double): the real part.
     - `imaginary` (double): the imaginary part.
   - **Member functions:**  
     - Constructors (default, parameterized, copy).
     - Assignment operator (`operator=`).
     - Comparison operator (`operator>`).
     - A function to compute the modulus.
     - A function to print the number.

3. **Write the Class**
   - Define your class with private data members and public member functions.
   - Implement each function step by step:
     - Constructors: initialize the data members.
     - Assignment operator: copy values from another object.
     - Comparison operator: compare modulus values.
     - Modulus function: use `sqrt(real*real + imaginary*imaginary)`.
     - Print function: output in `a + bi` format.

4. **File Input**
   - Use `ifstream` to open and read from the file.
   - The first value in the file is the number of complex numbers.
   - For each number, read the real and imaginary parts and store them in an array of `Complex` objects.

5. **Sorting**
   - Use a simple sorting algorithm (like bubble sort) to sort the array.
   - Use your overloaded `>` operator to compare objects by modulus.

6. **Output**
   - Loop through the sorted array.
   - Print each complex number and its modulus.

7. **Clean Up**
   - Release any dynamically allocated memory with `delete[]`.

8. **Test Your Program**
   - Create a sample input file with several complex numbers.
   - Run your program and check if the output is correct and sorted by modulus.

What You Learn:
---------------
- How to design and implement a class in C++.
- How to overload operators for custom behavior.
- How to read and process data from files.
- How to sort objects using custom logic.
- How to manage memory in C++.

Summary:
--------
By breaking the assignment into clear steps, you make the problem manageable and easier to debug. 
This approach builds strong habits for tackling more complex programming challenges in the future.

==========================================================
*/