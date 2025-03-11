#include <iostream>
#include <fstream>
#include <cmath>
#include <algorithm>
using namespace std;

struct Complex_nums {
    float real;
    float imag;
    float mag; 
};

int main() {
    ifstream inputFile("E:\\C++ OOP\\In.txt");

    if (!inputFile) {
        cerr << "Unable to open file complex_nums.txt";
        exit(1);
    }

    int count;
    inputFile >> count; 

    Complex_nums* complexNumbers = new Complex_nums[count];

    for (int i = 0; i < count; ++i) {
        inputFile >> complexNumbers[i].real >> complexNumbers[i].imag;
        complexNumbers[i].mag = sqrt(complexNumbers[i].real * complexNumbers[i].real + complexNumbers[i].imag * complexNumbers[i].imag);
    }

    for (int i = 0; i < count - 1; ++i) {
        for (int j = 0; j < count - i - 1; ++j) {
            if (complexNumbers[j].mag < complexNumbers[j + 1].mag) {
                Complex_nums temp = complexNumbers[j];
                complexNumbers[j] = complexNumbers[j + 1];
                complexNumbers[j + 1] = temp;
            }
        }
    }

    cout << "The 5 numbers with the largest magnitude:" << endl;
    for (int i = 0; i < 5 && i < count; ++i) {
        cout << "Complex number " << i + 1 << ": "
             << complexNumbers[i].real << " + " << complexNumbers[i].imag << "i, "
             << "Magnitude: " << complexNumbers[i].mag << endl;
    }

    delete[] complexNumbers;

    return 0;
}