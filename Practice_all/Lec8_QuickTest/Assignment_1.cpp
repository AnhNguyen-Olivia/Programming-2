/*
Write a program with a mother class and an inherited
daughter class. Both of them should have a method void
display () that prints a message (different for mother and
daughter). In the main define a daughter and call the
display() method on it.
*/

#include <iostream>
using namespace std;

class Mother {
public:
    void display() {
        cout << "Hello, I'm the mother" << endl;
    }
};

class Daughter : public Mother {
public:
    void display() {
        cout << "Hello, I'm the daughter" << endl;
    }
};

int main() {
    Daughter girl_1;
    girl_1.display();
}
