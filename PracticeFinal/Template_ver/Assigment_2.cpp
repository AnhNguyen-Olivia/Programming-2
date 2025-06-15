#include <iostream> // Standard input/output stream library
using namespace std;

// The following line makes the class a template, so it can use any type T (e.g., int, float, double)
template <typename T>
class Quadrilateral {
private:
    T width;  // width is now of type T, not fixed (e.g., could be int, float, double)
    T height; // height is also of type T
public:
    // Constructor with parameters of type T
    Quadrilateral(T w, T h) : width(w), height(h) {}
    // Default constructor sets width and height to 1 of type T
    Quadrilateral() : width(1), height(1) {}
    // Virtual destructor for proper cleanup in inheritance
    virtual ~Quadrilateral() {}

    // Setters and getters use type T
    void setHeight(T h) { height = h; }
    void setWidth(T w) { width = w; }
    T getWidth() const { return width; }
    T getHeight() const { return height; }

    // Virtual area method returns type T (default 0)
    virtual T area() const { return 0; }
    // Virtual printArea method prints the area
    virtual void printArea() const {
        cout << "Area: " << area();
    }
};

// Rectangle class is also a template, inherits from Quadrilateral<T>
template <typename T>
class Rectangle : public Quadrilateral<T> {
public:
    // Constructor passes parameters to base class
    Rectangle(T w, T h) : Quadrilateral<T>(w, h) {}
    // area() uses type T for calculation
    T area() const override {
        return this->getWidth() * this->getHeight();
    }
    // printArea() prints the shape type and area
    void printArea() const override {
        cout << "Rectangle ";
        Quadrilateral<T>::printArea();
    }
};

// Parallelogram class is a template, inherits from Quadrilateral<T>
template <typename T>
class Parallelogram : public Quadrilateral<T> {
public:
    Parallelogram(T w, T h) : Quadrilateral<T>(w, h) {}
    T area() const override {
        return this->getWidth() * this->getHeight();
    }
    void printArea() const override {
        cout << "Parallelogram ";
        Quadrilateral<T>::printArea();
    }
};

// Trapezium class is a template, inherits from Quadrilateral<T>
template <typename T>
class Trapezium : public Quadrilateral<T> {
private:
    T base; // base is also of type T
public:
    // Constructor takes width, height, and base of type T
    Trapezium(T w, T h, T b) : Quadrilateral<T>(w, h), base(b) {}
    // area() uses type T for calculation
    T area() const override {
        return (this->getWidth() + base) / 2 * this->getHeight();
    }
    void printArea() const override {
        cout << "Trapezium ";
        Quadrilateral<T>::printArea();
    }
};

int main() {
    const int N = 3; // Number of shapes

    // Array of pointers to Quadrilateral<double>
    // In a non-template version, this would be Quadrilateral* (fixed type, e.g., double)
    Quadrilateral<double>* quads[N];

    // Create objects using double type
    quads[0] = new Rectangle<double>(3, 4);        // Rectangle with double values
    quads[1] = new Parallelogram<double>(5, 6);    // Parallelogram with double values
    quads[2] = new Trapezium<double>(2, 3, 4);     // Trapezium with double values

    // Loop through and print area for each shape
    for (int i = 0; i < N; i++) {
        quads[i]->printArea();
        cout << endl;
        delete quads[i]; // Free memory
    }
    return 0;
}

/*
==========================
Summary of Program Functionality and Concepts Demonstrated
==========================

This program uses C++ class templates to model various quadrilaterals (Rectangle, Parallelogram, Trapezium) that can operate with any numeric type (such as int, float, or double). The base template class Quadrilateral<T> provides a flexible foundation, and each specific shape is implemented as a derived template class.

Key Concepts Demonstrated:

- **Class Templates:**  
  Using `template <typename T>` allows all classes to work with any numeric type, making the code generic and reusable.

- **Template Inheritance:**  
  Derived classes (Rectangle, Parallelogram, Trapezium) inherit from the template base class, demonstrating how templates can be used in class hierarchies.

- **Polymorphism:**  
  Virtual functions (`area()` and `printArea()`) and an array of base class pointers enable runtime polymorphism, so different shapes can be handled uniformly.

- **Dynamic Memory Management:**  
  Objects are created with `new` and deleted with `delete`, illustrating manual memory management.

- **Encapsulation:**  
  Member variables are private, with public getter and setter functions for controlled access.

Program Flow:

1. An array of pointers to `Quadrilateral<double>` is created, each pointing to a different derived shape.
2. The program calculates and prints the area of each shape using the correct formula.
3. Templates allow the same code to be reused for different numeric types, increasing flexibility.

==========================
Assignment Guide: Step-by-Step Solution Approach
==========================

1. **Understand the Requirements:**  
   - Model different quadrilaterals (Rectangle, Parallelogram, Trapezium) in C++.
   - Ensure the program works with various numeric types (int, float, double).

2. **Design the Base Template Class:**  
   - Create `Quadrilateral<T>` with private width and height members of type T.
   - Provide constructors, getters, setters, and virtual functions for area calculation and printing.

3. **Implement Derived Template Classes:**  
   - Create `Rectangle<T>`, `Parallelogram<T>`, and `Trapezium<T>` inheriting from `Quadrilateral<T>`.
   - Override `area()` and `printArea()` in each derived class.
   - For `Trapezium<T>`, add an extra member for the second base.

4. **Apply Polymorphism:**  
   - Use an array of `Quadrilateral<T>*` pointers to store different shapes.
   - This enables uniform handling and dynamic dispatch via virtual functions.

5. **Create and Manage Objects in `main()`:**  
   - Instantiate each derived class using the desired numeric type (e.g., double).
   - Store them in the array of base class pointers.
   - Loop through the array to print each shape’s area.
   - Delete the objects to free memory.

6. **(Optional) Test with Different Numeric Types:**  
   - Repeat the process with other types like int or float to demonstrate template flexibility.

7. **Comment and Document Your Code:**  
   - Clearly explain the purpose of each class, function, and important code section.
   - Summarize the demonstrated concepts at the end of your code.

**Tips:**
- Always use `template <typename T>` before class definitions.
- Specify the template parameter when inheriting (e.g., `public Quadrilateral<T>`).
- Use `override` for overridden virtual functions.
- Always delete dynamically allocated objects to prevent memory leaks.
*/