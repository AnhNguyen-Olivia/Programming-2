/*
Write a recursive function to find the factorial of a given number
(n! where n is a non-negative integer).
*/

#include <iostream>
using namespace std;

class Factorial {
private:
    int num;
public:
    Factorial(int n) : num(n) {}
    ~Factorial() {}
    Factorial(const Factorial &other) : num(other.num) {}

    void setNum(int n) { num = n; }
    int getNum() const { return num; }

    // Recursive factorial calculation
    int calculateFact(int n) const {
        if (n <= 1) return 1;
        return n * calculateFact(n - 1);
    }

    int calculateFact() const {
        return calculateFact(num);
    }

    void printFact() const {
        cout << num << "! = " << calculateFact() << endl;
    }
};

int main() {
    Factorial fact_1(5);
    fact_1.printFact();
    return 0;
}