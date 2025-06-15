/*
Port your favorite small- to medium-sized programs. Here Im going to impliment a simple calculate then print out
*/
#include <iostream>
using namespace std;

// Base class
class Calculate {
//Encapsulation
private:
    double num_1;
    double num_2;
public:
    Calculate() : num_1(0), num_2(0) {}
    Calculate(double num1, double num2) : num_1(num1), num_2(num2) {}
    Calculate(const Calculate& other) : num_1(other.num_1), num_2(other.num_2) {}
    virtual ~Calculate() {}

    void setNum_1(double num1) { num_1 = num1; }
    void setNum_2(double num2) { num_2 = num2; }
    double getNum_1() const { return num_1; }
    double getNum_2() const { return num_2; }

    // Abstraction & Polymorphism
    virtual void printCalculation() const {
        cout << num_1 << " + " << num_2 << " = " << num_1 + num_2 << "\n"
             << num_1 << " - " << num_2 << " = " << num_1 - num_2 << "\n"
             << num_1 << " * " << num_2 << " = " << num_1 * num_2 << "\n";
        if (num_2 != 0)
            cout << num_1 << " / " << num_2 << " = " << num_1 / num_2 << endl;
        else
            cout << "Division by zero error!" << endl;
    }
};

// Derived class (Inheritance & Polymorphism)
class AdvancedCalculate : public Calculate {
public:
    AdvancedCalculate(double num1, double num2) : Calculate(num1, num2) {}
    void printCalculation() const override {
        Calculate::printCalculation();
        cout << "Power: " << getNum_1() << "^" << getNum_2() << " = " << pow(getNum_1(), getNum_2()) << endl;
    }
};

int main() {
    Calculate cal1(10, 4);
    cal1.printCalculation();

    AdvancedCalculate cal2(2, 3);
    cal2.printCalculation();

    return 0;
}