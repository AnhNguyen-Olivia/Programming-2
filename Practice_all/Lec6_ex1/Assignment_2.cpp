/*
A class for rational numbers, the number should always be represented as a
fully reduced fraction of the form numerator/denominator where denominator>0
    a. Write a class Rational, which represents a rational number. The constructor
    should have the numerator and the denominator as arguments. Be sure to check
    for valid input. In addition, the class has two functions numerator() and
    denominator() that return the values of the numerator and denominator. The
    class should have three constructors:
        • a default constructor that initializes the fraction with 1,
        • a constructor that initializes the fraction with a given numerator and
        denominator and
        • a constructor that initializes the fraction with a given whole number.
    b. Writing a function int gcd(int,int) (greatest common divisor), you will need it
    to reduce fractions.
*/

#include <iostream> // Include the input/output stream library
using namespace std; // Use the standard namespace

class Rational{
    private:
        int numerator;   // Stores the numerator of the rational number
        int denominator; // Stores the denominator of the rational number

        // Reduces the fraction to its simplest form
        // This method finds the greatest common divisor (GCD) of the numerator and denominator,
        // then divides both by the GCD to simplify the fraction.
        // It also ensures that the denominator is always positive by flipping the signs if needed.
        void reduce() {
            int g = gcd(abs(numerator), abs(denominator)); // Find GCD of numerator and denominator
            numerator /= g;    // Divide numerator by GCD to reduce
            denominator /= g;  // Divide denominator by GCD to reduce
            if (denominator < 0) { // Ensure denominator is always positive
                numerator = -numerator;   // Flip sign of numerator
                denominator = -denominator; // Flip sign of denominator
            }
        }

        // Helper function to compute the greatest common divisor (GCD)
        // This function uses the Euclidean algorithm:
        // It repeatedly replaces the larger number with the remainder of dividing the larger by the smaller,
        // until the remainder is zero. The last non-zero value is the GCD.
        int gcd(int a, int b) {
            while (b != 0) { // Repeat until b is zero
                int t = b;   // Store current b
                b = a % b;   // Set b to remainder of a divided by b
                a = t;       // Set a to previous b
            }
            return a; // Return GCD
        }

    public:
        // Default constructor: initializes to 1/1
        Rational() : numerator(1), denominator(1) {}

        // Constructor with numerator and denominator
        Rational(int num, int denom) {
            if (denom == 0) { // Check for zero denominator
                throw invalid_argument("Denominator cannot be zero.");
            }
            numerator = num;      // Set numerator
            denominator = denom;  // Set denominator
            reduce();             // Reduce the fraction
        }

        // Constructor with whole number (whole_number/1)
        Rational(int whole_number) : numerator(whole_number), denominator(1) {}

        // Getter for numerator
        int getNumerator() const { return numerator; }

        // Getter for denominator
        int getDenominator() const { return denominator; }
};

/*
// This version uses a brute-force approach: it checks all numbers from min(a, b) down to 1.
        int gcd(int a, int b) {
            a = abs(a);
            b = abs(b);
            int minVal = (a < b) ? a : b;
            for (int i = minVal; i >= 1; --i) {
                if (a % i == 0 && b % i == 0) {
                    return i; // Return the largest i that divides both a and b
                }
            }
            return 1; // If no greater common divisor is found, return 1
        }
*/