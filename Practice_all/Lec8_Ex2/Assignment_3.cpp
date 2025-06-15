#include <iostream> // Provides input and output functionality

// Abstract base class representing a generic shape
class Shape {
public:
    // Pure virtual function: forces derived classes to implement their own displayArea method
    virtual void displayArea() = 0;
};

// Rectangle class inherits from Shape and represents a rectangle
class Rectangle : public Shape {
private:
    double width, height; // Dimensions of the rectangle
public:
    // Constructor initializes width and height
    Rectangle(double w, double h) : width(w), height(h) {}
    // Implementation of displayArea for Rectangle
    void displayArea() override {
        std::cout << "This is a rectangle." << std::endl;
    }
};

// Triangle class inherits from Shape and represents a triangle
class Triangle : public Shape {
private:
    double base, height; // Dimensions of the triangle
public:
    // Constructor initializes base and height
    Triangle(double b, double h) : base(b), height(h) {}
    // Implementation of displayArea for Triangle
    void displayArea() override {
        std::cout << "This is a triangle." << std::endl;
    }
};

int main() {
    // Create a Rectangle object with width 10 and height 5
    Rectangle rect(10, 5);
    // Create a Triangle object with base 8 and height 4
    Triangle tri(8, 4);
    // Call displayArea() for Rectangle (demonstrates polymorphism)
    rect.displayArea();
    // Call displayArea() for Triangle (demonstrates polymorphism)
    tri.displayArea();
    return 0; // Indicate successful program termination
}

/*
    This program demonstrates key object-oriented programming concepts in C++:

    1. Abstract Classes: The Shape class is abstract because it contains a pure virtual function.
       You cannot create objects of Shape directly; it serves as a blueprint for derived classes.

    2. Pure Virtual Functions: The displayArea function is pure virtual, requiring all derived
       classes to provide their own implementation. This enforces a consistent interface.

    3. Inheritance: Rectangle and Triangle both inherit from Shape, showing how different shapes
       can share a common interface while providing their own specific behavior.

    4. Polymorphism: Although not using pointers or references here, the structure allows you to
       treat all shapes uniformly through the Shape interface, enabling flexible and extensible code.

    Overall, the program teaches how to use abstract classes and pure virtual functions to design
    extensible and maintainable object-oriented programs in C++.
*/