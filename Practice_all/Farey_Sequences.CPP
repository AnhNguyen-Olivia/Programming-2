#include <iostream> // Include the standard input/output stream library

using namespace std; // Use the standard namespace

const int MAX_FRACTIONS = 1000; // Maximum number of fractions to store in the sequence

// Function to compute the greatest common divisor (GCD) of two integers
int gcd(int a, int b) {
    while (b != 0) { // Continue until b becomes 0
        int tmp = b; // Store b in a temporary variable
        b = a % b;   // Set b to the remainder of a divided by b
        a = tmp;     // Set a to the previous value of b
    }
    return a; // Return the GCD
}

// Structure to represent a fraction
struct Fraction {
    int num, den; // Numerator and denominator

    // Default constructor: initializes fraction to 0/1
    Fraction() : num(0), den(1) {}

    // Constructor with numerator and denominator
    Fraction(int n, int d) {
        int g = gcd(n, d); // Reduce the fraction by dividing by GCD
        num = n / g;
        den = d / g;
    }

    // Operator overload for less-than comparison between fractions
    bool operator<(const Fraction& other) const {
        // Cross-multiply to compare fractions without floating point
        return num * other.den < other.num * den;
    }

    // Operator overload for equality comparison between fractions
    bool operator==(const Fraction& other) const {
        // Fractions are equal if numerators and denominators are equal
        return num == other.num && den == other.den;
    }
};

// Bubble sort function to sort an array of Fraction objects
void bubbleSort(Fraction seq[], int n) {
    for (int i = 0; i < n; ++i) { // Outer loop for passes
        for (int j = 0; j < n - 1 - i; ++j) { // Inner loop for comparisons
            if (seq[j + 1] < seq[j]) { // If next fraction is less than current
                Fraction temp = seq[j]; // Swap the two fractions
                seq[j] = seq[j + 1];
                seq[j + 1] = temp;
            }
        }
    }
}

// Function to remove duplicate fractions from a sorted array
int removeDuplicates(Fraction seq[], int n) {
    if (n == 0) return 0; // If array is empty, return 0
    int uniqueCount = 1; // At least one unique fraction
    for (int i = 1; i < n; ++i) { // Loop through the array
        if (!(seq[i] == seq[i - 1])) { // If current is not equal to previous
            seq[uniqueCount++] = seq[i]; // Add to unique list
        }
    }
    return uniqueCount; // Return the number of unique fractions
}

// Function to generate and print Farey sequences up to order N
void Farey(int N) {
    for (int n = 1; n <= N; ++n) { // For each order from 1 to N
        Fraction seq[MAX_FRACTIONS]; // Array to store fractions
        int count = 0; // Number of fractions found
        for (int q = 1; q <= n; ++q) { // Denominator from 1 to n
            for (int p = 0; p <= q; ++p) { // Numerator from 0 to q
                if (gcd(p, q) == 1) { // Only consider reduced fractions
                    if (count < MAX_FRACTIONS) { // Prevent overflow
                        seq[count++] = Fraction(p, q); // Store the fraction
                    }
                }
            }
        }

        bubbleSort(seq, count); // Sort the fractions
        count = removeDuplicates(seq, count); // Remove duplicates

        cout << "F" << n << " = ( "; // Print the sequence label
        for (int i = 0; i < count; ++i) { // Print all fractions
            cout << seq[i].num << "/" << seq[i].den;
            if (i != count - 1) cout << ", "; // Comma between fractions
        }
        cout << " )" << endl; // End of sequence
    }
}

int main() {
    int N; // Variable to store user input for order of Farey sequence
    cout << "Farey: "; // Prompt user
    cin >> N; // Read user input

    Farey(N); // Generate and print Farey sequences up to order N
    return 0; // End of program
}

/*
    This program is designed to teach the concept of Farey sequences in mathematics, 
    as well as demonstrate several important C++ programming techniques.

    **Mathematical Concept:**
    - A Farey sequence of order n is the ascending sequence of completely reduced fractions 
      between 0 and 1, whose denominators do not exceed n.
    - The program generates and prints all Farey sequences from order 1 up to a user-specified order N.
    - It shows how to generate reduced fractions, sort them, and remove duplicates.

    **Programming Concepts and Syntax Demonstrated:**
    - Use of C++ structures (`struct`) to represent mathematical objects (fractions).
    - Operator overloading (`operator<` and `operator==`) for custom comparison of objects.
    - Implementation of the Euclidean algorithm to compute the greatest common divisor (GCD).
    - Use of arrays to store and manipulate collections of objects.
    - Implementation of sorting algorithms (bubble sort) and duplicate removal.
    - Use of nested loops for combinatorial generation (all possible numerators and denominators).
    - Input/output operations using `cin` and `cout`.
    - Function definition and usage for modular code.
    - Use of constants (`const int`) for fixed-size arrays and program limits.
    - Basic error checking (array bounds).
    - Code commenting and documentation for clarity.

    Overall, the program is a practical example of combining mathematical logic with C++ syntax 
    and features to solve a problem and present the results in a user-friendly way.

    =========================
    C++ Syntax Explanation
    =========================

    1. #include <iostream>
       - Preprocessor directive that includes the standard input/output stream library, 
         allowing the use of 'cin' and 'cout' for input and output.

    2. using namespace std;
       - Brings all symbols in the 'std' namespace into the current scope, 
         so you can write 'cout' instead of 'std::cout'.

    3. const int MAX_FRACTIONS = 1000;
       - Declares a constant integer named MAX_FRACTIONS with value 1000.
       - 'const' means the value cannot be changed after initialization.

    4. int gcd(int a, int b) { ... }
       - Function definition for 'gcd' (greatest common divisor).
       - Takes two integer parameters and returns an integer.
       - Uses a while loop and modulo operator (%) to compute the GCD.

    5. struct Fraction { ... };
       - Defines a structure named 'Fraction' to group related data (numerator and denominator).
       - Contains:
         - Data members: 'int num, den;'
         - Constructors: special functions to initialize objects.
         - Operator overloads: 'operator<' and 'operator==' to compare Fraction objects.

    6. Fraction() : num(0), den(1) {}
       - Default constructor using an initializer list to set num=0, den=1.

    7. Fraction(int n, int d) { ... }
       - Parameterized constructor to initialize a Fraction with numerator n and denominator d.
       - Reduces the fraction using the gcd function.

    8. bool operator<(const Fraction& other) const { ... }
       - Overloads the '<' operator to compare two Fraction objects.
       - 'const' at the end means this function does not modify the object.

    9. bool operator==(const Fraction& other) const { ... }
       - Overloads the '==' operator to check if two Fraction objects are equal.

    10. void bubbleSort(Fraction seq[], int n) { ... }
        - Function to sort an array of Fraction objects using the bubble sort algorithm.
        - 'Fraction seq[]' is an array parameter, 'int n' is the number of elements.

    11. int removeDuplicates(Fraction seq[], int n) { ... }
        - Function to remove duplicate fractions from a sorted array.
        - Returns the new count of unique fractions.

    12. void Farey(int N) { ... }
        - Function to generate and print Farey sequences up to order N.
        - Uses nested loops to generate all possible reduced fractions.

    13. int main() { ... }
        - The main function: program execution starts here.
        - Declares an integer N, prompts the user, reads input, and calls Farey(N).
        - Returns 0 to indicate successful execution.

    14. Comments:
        - Single-line comments use '//'
        - Multi-line comments use '/* ... '

    15. cout << ...;
        - Outputs data to the console.

    16. cin >> ...;
        - Reads data from the console.

    17. Arrays:
        - 'Fraction seq[MAX_FRACTIONS];' declares an array of Fraction objects.

    18. for (int i = 0; i < n; ++i) { ... }
        - For loop: repeats code block with index variable i from 0 to n-1.

    19. if (condition) { ... }
        - Conditional statement: executes code block if condition is true.

    20. return value;
        - Returns a value from a function.

    This program demonstrates the use of C++ syntax for functions, structures, arrays, loops, 
    conditionals, operator overloading, input/output, and code documentation.
*/