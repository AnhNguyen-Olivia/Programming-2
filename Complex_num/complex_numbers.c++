#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
using namespace std;

struct ComplexNumber {
    double real;
    double imag;
    double magnitude() const {
        return sqrt(real * real + imag * imag);
    }
};

int main() {
    ifstream file("E:\\C++ OOP\\In.txt");
    if (!file) {
        cerr << "Unable to open file In.txt";
        return 1; 
    }

    int numCount;
    file >> numCount;

    if (numCount <= 0) {
        cerr << "Invalid number count in the file.";
        return 1;
    }

    ComplexNumber* numbers = new ComplexNumber[numCount]; 
    int count = 0;
    double real, imag;

    while (file >> real >> imag && count < numCount) { 
        numbers[count].real = real;
        numbers[count].imag = imag;
        count++;
    }
    file.close();

    // Sort the numbers based on their magnitude
    for (int i = 0; i < count - 1; ++i) {
        for (int j = 0; j < count - i - 1; ++j) {
            if (numbers[j].magnitude() < numbers[j + 1].magnitude()) {
                ComplexNumber temp = numbers[j];
                numbers[j] = numbers[j + 1];
                numbers[j + 1] = temp;
            }
        }
    }
    
    cout << "The 5 complex numbers with the largest magnitude are:" << endl;
    for (int i = 0; i < 5 && i < count; ++i) {
        cout << numbers[i].real << " + " << numbers[i].imag << "i (Magnitude: " << numbers[i].magnitude() << ")" << endl;
    }

    delete[] numbers;

    return 0;
}