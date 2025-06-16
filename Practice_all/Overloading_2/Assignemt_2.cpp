/*
================================================================================
Comprehensive Documentation: Complex Numbers, Operator Overloading, and File I/O
================================================================================

PROGRAM OVERVIEW
--------------------------------------------------------------------------------
This C++ program is a practical demonstration of object-oriented programming
principles. It models complex numbers using a class, leverages operator
overloading for intuitive comparison and assignment, reads complex numbers from
a file, sorts them in descending order by their modulus (magnitude), and
displays the sorted results. The assignment is designed to strengthen your
understanding of C++ classes, file I/O, and custom sorting.

================================================================================
KEY CONCEPTS COVERED
--------------------------------------------------------------------------------
1. **Class Design & Encapsulation**
   - The `ComplexNumber` class encapsulates real and imaginary parts as private members.
   - Constructors: default, parameterized, and copy for flexible object creation.

2. **Operator Overloading**
   - Overloads '>' to compare complex numbers by modulus.
   - Overloads '=' for deep assignment between objects.

3. **File Input/Output**
   - Uses `ifstream` to read structured data (complex numbers) from a file.

4. **Arrays & Sorting**
   - Stores complex numbers in an array.
   - Implements bubble sort using the overloaded '>' operator for custom comparison.

5. **Mathematical Functions**
   - Utilizes `sqrt()` from `<cmath>` to compute the modulus of complex numbers.

================================================================================
LEARNING OBJECTIVES
--------------------------------------------------------------------------------
- Model mathematical objects using C++ classes.
- Extend C++ syntax for custom types via operator overloading.
- Read and process structured data from files.
- Apply sorting algorithms to arrays of objects.
- Practice encapsulation, modularity, and code readability.

================================================================================
STEP-BY-STEP GUIDE
--------------------------------------------------------------------------------
1. **Define the ComplexNumber Class**
   - Encapsulate real and imaginary parts.
   - Provide constructors for various initialization scenarios.
   - Implement display and modulus functions.
   - Overload '>' and '=' operators.

2. **Read Data from File**
   - Open the file and read the number of complex numbers.
   - Read each complex number and store it in an array.

3. **Sort the Array**
   - Use bubble sort to arrange complex numbers in descending order by modulus.

4. **Display Results**
   - Output the sorted list.
   - Demonstrate operator overloading with example objects.

================================================================================
SYNTAX & EXAMPLES
--------------------------------------------------------------------------------
- **Class Definition:**
    class ComplexNumber { ... };

- **Object Creation:**
    ComplexNumber c1;              // Default constructor
    ComplexNumber c2(3, 4);        // Parameterized constructor

- **Operator Overloading:**
    bool operator>(const ComplexNumber&) const;
    ComplexNumber& operator=(const ComplexNumber&);

- **File I/O:**
    std::ifstream infile("input.txt");
    infile >> x >> y;

- **Arrays:**
    ComplexNumber arr[10];

- **Bubble Sort:**
    for (...) for (...) if (...) swap(...);

- **Math Functions:**
    double m = sqrt(real*real + imaginary*imaginary);

================================================================================
BEST PRACTICES HIGHLIGHTED
--------------------------------------------------------------------------------
- Encapsulation: Keep data members private and expose only necessary methods.
- Operator Overloading: Make custom types behave like built-in types.
- Modular Design: Separate logic into clear, reusable components.
- Error Handling: Check for file opening errors and handle them gracefully.
- Code Readability: Use descriptive variable names and clear formatting.

================================================================================
EXTENSION IDEAS
--------------------------------------------------------------------------------
- Overload additional operators (e.g., +, -, *, /) for complex arithmetic.
- Use `std::vector` for dynamic storage instead of fixed-size arrays.
- Add exception handling for robust error management.
- Implement more efficient sorting algorithms (e.g., quicksort).
- Enhance the display function for better formatting (e.g., handle negative imaginary parts).

================================================================================
SUMMARY
--------------------------------------------------------------------------------
This program is a comprehensive example for learning and practicing C++ object-
oriented programming, operator overloading, file I/O, and sorting. By studying
and experimenting with this code, you will gain practical skills essential for
advanced C++ programming and real-world software development.

================================================================================
*/

#include <iostream>   // Provides standard input/output stream objects (cin, cout)
#include <fstream>    // Provides file stream classes for file I/O (ifstream)
#include <cmath>      // Provides mathematical functions (sqrt for modulus calculation)

// Class representing a complex number and related operations
class ComplexNumber {
private:
    double real;         // Stores the real part of the complex number
    double imaginary;    // Stores the imaginary part of the complex number

public:
    // Default constructor: initializes both real and imaginary parts to 0
    ComplexNumber() : real(0), imaginary(0) {}

    // Parameterized constructor: initializes with specified real and imaginary values
    ComplexNumber(double r, double i) : real(r), imaginary(i) {}

    // Copy constructor: creates a new ComplexNumber as a copy of another
    ComplexNumber(const ComplexNumber& other) : real(other.real), imaginary(other.imaginary) {}

    // Displays the complex number in the format "a + bi"
    void display() const {
        std::cout << real << " + " << imaginary << "i\n";
    }

    // Calculates and returns the modulus (magnitude) of the complex number
    double modulus() const {
        return std::sqrt(real * real + imaginary * imaginary);
    }

    // Overloads the '>' operator to compare two complex numbers by their modulus
    bool operator>(const ComplexNumber& c) const {
        return this->modulus() > c.modulus();
    }

    // Overloads the assignment operator to copy values from another ComplexNumber
    ComplexNumber& operator=(const ComplexNumber& c) {
        if (this != &c) {           // Prevents self-assignment
            real = c.real;
            imaginary = c.imaginary;
        }
        return *this;               // Returns reference to the current object
    }
};

int main() {
    ComplexNumber list[100];    // Array to hold up to 100 complex numbers
    int n = 0;                  // Number of complex numbers to read from file

    // Open the input file containing complex numbers
    std::ifstream infile("E://Programming-2//overloading_2//input.txt");
    if (!infile) {              // Check if the file opened successfully
        std::cout << "Could not open input.txt file.\n";
        return 1;               // Exit if file could not be opened
    }

    infile >> n;  // Read the number of complex numbers to process
    for (int i = 0; i < n; ++i) {
        double r, im;
        infile >> r >> im;                  // Read real and imaginary parts from file
        list[i] = ComplexNumber(r, im);     // Construct and assign to array
    }
    infile.close();     // Close the input file after reading

    // Sort the array in descending order of modulus using bubble sort
    for (int i = 0; i < n - 1; ++i) {
        for (int j = 0; j < n - i - 1; ++j) {
            // If the current element's modulus is less than or equal to the next, swap them
            if (!(list[j] > list[j + 1])) {
                ComplexNumber temp = list[j];
                list[j] = list[j + 1];
                list[j + 1] = temp;
            }
        }
    }

    // Output the sorted complex numbers
    std::cout << "\nSorted complex numbers by modulus (descending):\n";
    for (int i = 0; i < n; ++i) {
        list[i].display();
    }

    // Demonstrate the overloaded '>' operator
    ComplexNumber c1(3, 4);     // c1 = 3 + 4i (modulus = 5)
    ComplexNumber c2(1, 2);     // c2 = 1 + 2i (modulus ≈ 2.236)
    if (c1 > c2) {
        std::cout << "c1 is greater than c2\n";
    } else {
        std::cout << "c1 is not greater than c2\n";
    }

    // Demonstrate the overloaded assignment operator '='
    ComplexNumber c3;       // Default constructor (0 + 0i)
    c3 = c1;                // Assign c1 to c3
    std::cout << "c3 after assignment from c1: ";
    c3.display();           // Should display 3 + 4i
    std::cout << "c1 after assignment: ";
    c1.display();           // Should still display 3 + 4i

    return 0;   // Indicate successful program termination
}

/*
================================================================================
Lesson: Mastering Complex Numbers, Operator Overloading, and File I/O in C++
================================================================================

Lesson Objectives:
--------------------------------------------------------------------------------
By the end of this lesson, you will be able to:
- Define and use classes to represent complex numbers in C++.
- Overload operators for comparison and assignment of complex numbers.
- Read and process data from files using streams.
- Sort objects using custom comparison logic.
- Appreciate the importance of encapsulation and modular code design.

--------------------------------------------------------------------------------
1. Introduction
--------------------------------------------------------------------------------
This lesson guides you through building a C++ program to manage a list of complex
numbers. You'll learn to encapsulate data and behavior in a class, overload
operators for intuitive usage, read data from a file, and sort complex numbers
by their modulus.

--------------------------------------------------------------------------------
2. Key Concepts to Review
--------------------------------------------------------------------------------
- **Classes and Objects:** Defining classes, creating objects, and using constructors.
- **Operator Overloading:** Customizing operators like `>`, `=`, etc., for your class.
- **File Input/Output:** Reading from and writing to files using streams.
- **Arrays:** Storing and manipulating collections of objects.
- **Sorting Algorithms:** Implementing simple sorting methods like bubble sort.
- **Mathematical Functions:** Using functions like `sqrt()` from `<cmath>`.

--------------------------------------------------------------------------------
3. Step-by-Step Walkthrough
--------------------------------------------------------------------------------
A. **Defining the ComplexNumber Class**
   - *Encapsulation:* Store real and imaginary parts as private members.
   - *Constructors:* Provide default, parameterized, and copy constructors.
   - *Display Function:* Print the complex number in a readable format.
   - *Modulus Function:* Calculate the magnitude of the complex number.
   - *Operator Overloading:*
     - `>` to compare two complex numbers by modulus.
     - `=` to assign one complex number to another.

B. **Reading Data from a File**
   - Use `ifstream` to open and read data from a file.
   - Read the number of complex numbers and their values.
   - Store each complex number in an array.

C. **Sorting the Complex Numbers**
   - Use bubble sort to arrange the complex numbers in descending order by modulus.
   - Use the overloaded `>` operator for comparison.

D. **Displaying Results**
   - Print the sorted list of complex numbers.
   - Demonstrate the use of overloaded operators with example objects.

--------------------------------------------------------------------------------
4. Hands-On Practice
--------------------------------------------------------------------------------
- Modify the input file and observe how the output changes.
- Add new operator overloads (like `+` or `-`) for extended functionality.
- Replace bubble sort with a more efficient sorting algorithm.
- Improve output formatting for better readability.

--------------------------------------------------------------------------------
5. What You Should Learn
--------------------------------------------------------------------------------
- How to design a class that models real-world concepts (complex numbers).
- How operator overloading makes your classes more intuitive and powerful.
- How to read and process structured data from files in C++.
- How to sort objects using custom comparison logic.
- How to test and debug your code for correctness.

--------------------------------------------------------------------------------
6. Reflection and Extension
--------------------------------------------------------------------------------
- Can you add more features, like adding or subtracting complex numbers?
- How would you handle errors or invalid data in the input file?
- Can you use vectors instead of arrays for more flexibility?
- What other operators could you overload for the ComplexNumber class?

--------------------------------------------------------------------------------
7. Syntax Reference and Examples
--------------------------------------------------------------------------------
- **Class Definition:**
    class ClassName {
        // members and methods
    };

- **Object Creation and Constructors:**
    ClassName obj;                  // Default constructor
    ClassName obj(params);          // Parameterized constructor

- **Operator Overloading:**
    bool operator>(const ClassName&) const;
    ClassName& operator=(const ClassName&);

- **File I/O:**
    #include <fstream>
    std::ifstream infile("input.txt");
    infile >> x >> y;

- **Arrays:**
    Type arrayName[size];
    ComplexNumber arr[10];

- **Bubble Sort:**
    for (int i = 0; i < n - 1; ++i)
        for (int j = 0; j < n - i - 1; ++j)
            if (arr[j] > arr[j + 1])
                swap(arr[j], arr[j + 1]);

- **Math Functions:**
    #include <cmath>
    double modulus = sqrt(real * real + imaginary * imaginary);

--------------------------------------------------------------------------------
8. Summary Table
--------------------------------------------------------------------------------
| Concept             | Syntax Example                        | Usage Example                                 |
|---------------------|---------------------------------------|-----------------------------------------------|
| Class Definition    | class MyClass { ... };                | class ComplexNumber { ... };                  |
| Object Creation     | MyClass obj;                          | ComplexNumber c1(3, 4);                       |
| Operator Overload   | bool operator>(const MyClass&);       | bool operator>(const ComplexNumber& c) const; |
| File I/O            | std::ifstream infile("file.txt");     | infile >> x;                                  |
| Arrays              | Type arr[size];                       | ComplexNumber arr[10];                        |
| Bubble Sort         | for(...) for(...) if(...) swap(...)   | See sorting example above                     |
| Math Functions      | sqrt(x)                               | sqrt(real*real + imaginary*imaginary)         |

--------------------------------------------------------------------------------
9. Conclusion
--------------------------------------------------------------------------------
This lesson provides a comprehensive, hands-on introduction to C++ classes,
operator overloading, file I/O, and sorting. By completing the assignment and
exploring the examples, you will build a strong foundation in object-oriented
programming and practical C++ development.

================================================================================
*/