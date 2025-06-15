/*
Create a simple “shape” hierarchy: a base class called Shape and derived
classes called Circle, Square, and Triangle. In the base class, make a
virtual function called draw( ), and override this in the derived classes.
Make an array of pointers to Shape objects while each element is either
a Circle, a Square, or a Triangle (and thus perform upcasting of the
pointers), then call draw() through the base-class pointers, to verify the
behavior of the virtual function. (This is similar to the example presented
in the lecture note.)
*/
#include <iostream> // Include the input/output stream library

// Base class
class Shape {
public:
    virtual void draw() = 0; // Pure virtual function, makes Shape an abstract class
    virtual ~Shape() {}      // Virtual destructor for safe cleanup of derived objects
};

// Derived class: Circle
class Circle : public Shape {
public:
    void draw() override { // Override the draw() function for Circle
        std::cout << "Drawing a Circle." << std::endl;
    }
};

// Derived class: Square
class Square : public Shape {
public:
    void draw() override { // Override the draw() function for Square
        std::cout << "Drawing a Square." << std::endl;
    }
};

// Derived class: Triangle
class Triangle : public Shape {
public:
    void draw() override { // Override the draw() function for Triangle
        std::cout << "Drawing a Triangle." << std::endl;
    }
};

int main() {
    // Array of Shape pointers (performing upcasting)
    Shape* shapes[3]; // Create an array of pointers to Shape

    shapes[0] = new Circle();   // Assign a Circle object to the first element
    shapes[1] = new Square();   // Assign a Square object to the second element
    shapes[2] = new Triangle(); // Assign a Triangle object to the third element

    // Calling draw() through base class pointers
    for (int i = 0; i < 3; ++i) {
        shapes[i]->draw(); // Polymorphic call to the appropriate draw() function
    }

    // Cleaning up allocated memory
    for (int i = 0; i < 3; ++i) {
        delete shapes[i]; // Delete each dynamically allocated object
    }

    return 0; // Indicate successful program termination
}

/*
This program demonstrates the core principles of object-oriented programming in C++:
- **Abstraction**: The base class `Shape` defines a common interface with a pure virtual function `draw()`, making it an abstract class. This means you cannot create objects of `Shape` directly, only of its derived classes.
- **Inheritance**: The classes `Circle`, `Square`, and `Triangle` inherit from `Shape` and provide their own specific implementations of the `draw()` function.
- **Polymorphism**: By creating an array of `Shape*` pointers and assigning each to a different derived object (`Circle`, `Square`, or `Triangle`), the program demonstrates upcasting. When `draw()` is called through these base class pointers, C++ uses dynamic binding to invoke the correct overridden function in the derived class at runtime.
- **Dynamic Memory Management**: The program uses `new` to allocate memory for each shape object and `delete` to free that memory, ensuring proper resource management.

Overall, this code teaches how to design flexible and reusable code using virtual functions and inheritance, allowing you to work with different types of shapes through a unified interface and enabling runtime selection of the appropriate function implementation.
*/