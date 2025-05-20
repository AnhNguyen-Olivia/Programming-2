#include <iostream>
#include <fstream>
#include <cmath>

class ComplexNumber {
private:
    double real;
    double imaginary;

public:
    ComplexNumber() : real(0), imaginary(0) {}
    ComplexNumber(double r, double i) : real(r), imaginary(i) {}
    ComplexNumber(const ComplexNumber& other) : real(other.real), imaginary(other.imaginary) {}

    void display() const {
        std::cout << real << " + " << imaginary << "i\n";
    }

    double modulus() const {
        return std::sqrt(real * real + imaginary * imaginary);
    }

    bool operator>(const ComplexNumber& c) const {
        return this->modulus() > c.modulus();
    }

    ComplexNumber& operator=(const ComplexNumber& c) {
        if (this != &c) {
            real = c.real;
            imaginary = c.imaginary;
        }
        return *this;
    }
};

int main() {
    ComplexNumber list[100];
    int n = 0;

    std::ifstream infile("input.txt");
    if (!infile) {
        std::cout << "Could not open input.txt file.\n";
        return 1;
    }

    infile >> n;  // read number of complex numbers
    for (int i = 0; i < n; ++i) {
        double r, im;
        infile >> r >> im;
        list[i] = ComplexNumber(r, im);
    }
    infile.close();

    // Bubble sort in descending order
    for (int i = 0; i < n - 1; ++i) {
        for (int j = 0; j < n - i - 1; ++j) {
            if (!(list[j] > list[j + 1])) {
                ComplexNumber temp = list[j];
                list[j] = list[j + 1];
                list[j + 1] = temp;
            }
        }
    }

    std::cout << "\nSorted complex numbers by modulus (descending):\n";
    for (int i = 0; i < n; ++i) {
        list[i].display();
    }

    return 0;
}
