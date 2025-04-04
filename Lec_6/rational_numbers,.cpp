#include <iostream>
#include <string>
#include <cmath>
#include <cstdlib>
#include <iomanip>
#include <limits>0
using namespace std;

class RationalNumber {
private:
    int numerator;
    int denominator;

    void simplify() {
        int gcd = findGCD(abs(numerator), abs(denominator));
        numerator /= gcd;
        denominator /= gcd;
        if (denominator < 0) { // Ensure the denominator is positive
            numerator = -numerator;
            denominator = -denominator;
        }
    }

    int findGCD(int a, int b) {
        while (b != 0) {
            int t = b;
            b = a % b;
            a = t;
        }
        return a;
    }

public:
    // Default constructor
    RationalNumber() : numerator(1), denominator(1) {}

    // Constructor with numerator and denominator
    RationalNumber(int num, int denom) : numerator(num), denominator(denom) {
        if (denominator == 0) {
            cout << "Denominator cannot be zero. Setting to 1." << endl;
            denominator = 1;
        }
        simplify();
    }

    // Constructor with a whole number
    RationalNumber(int wholeNumber) : numerator(wholeNumber), denominator(1) {}

    // Accessor for numerator
    int getNumerator() const {
        return numerator;
    }

    // Accessor for denominator
    int getDenominator() const {
        return denominator;
    }

    // Overloaded addition operator
    RationalNumber operator+(const RationalNumber& other) const {
        return RationalNumber(numerator * other.denominator + other.numerator * denominator,
                              denominator * other.denominator);
    }

    // Overloaded subtraction operator
    RationalNumber operator-(const RationalNumber& other) const {
        return RationalNumber(numerator * other.denominator - other.numerator * denominator,
                              denominator * other.denominator);
    }

    // Overloaded multiplication operator
    RationalNumber operator*(const RationalNumber& other) const {
        return RationalNumber(numerator * other.numerator, denominator * other.denominator);
    }

    // Overloaded division operator
    RationalNumber operator/(const RationalNumber& other) const {
        if (other.numerator == 0) {
            throw invalid_argument("Division by zero is not allowed.");
        }
        return RationalNumber(numerator * other.denominator, denominator * other.numerator);
    }

    // Display function
    void display() const {
        cout << numerator << "/" << denominator << endl;
    }
};

int main() {
    // Test cases
    RationalNumber r1(3, 4); // 3/4
    RationalNumber r2(2, 5); // 2/5
    RationalNumber r3 = r1 + r2; // Addition
    RationalNumber r4 = r1 - r2; // Subtraction
    RationalNumber r5 = r1 * r2; // Multiplication
    RationalNumber r6 = r1 / r2; // Division

    cout << "r1: ";
    r1.display();
    cout << "r2: ";
    r2.display();
    cout << "r1 + r2: ";
    r3.display();
    cout << "r1 - r2: ";
    r4.display();
    cout << "r1 * r2: ";
    r5.display();
    cout << "r1 / r2: ";
    r6.display();

    return 0;
}
