#include <iostream>                  // Includes the standard input/output stream library.
using namespace std;                 // Uses the standard namespace to avoid prefixing std::.

class Quadrilateral {                // Defines a base class for all quadrilaterals.
private:
    double width;                    // Private member variable for width.
    double height;                   // Private member variable for height.
public:
    Quadrilateral(double w, double h) : width(w), height(h) {} // Constructor with parameters.
    Quadrilateral() : width(1), height(1) {}                   // Default constructor (width=1, height=1).
    virtual ~Quadrilateral() {}                                // Virtual destructor for proper cleanup.

    void setHeight(double h) { height = h; }                   // Setter for height.
    void setWidth(double w) { width = w; }                     // Setter for width.
    double getWidth() const { return width; }                  // Getter for width.
    double getHeight() const { return height; }                // Getter for height.

    virtual double area() const { return 0; }                  // Virtual method to compute area (default 0).
    virtual void printArea() const {                           // Virtual method to print area.
        cout << "Area: " << area();
    }
};

class Rectangle : public Quadrilateral {                       // Rectangle class inherits from Quadrilateral.
public:
    Rectangle(double w, double h) : Quadrilateral(w, h) {}     // Constructor.
    double area() const override {                             // Override area calculation.
        return getWidth() * getHeight();
    }
    void printArea() const override {                          // Override printArea.
        cout << "Rectangle ";
        Quadrilateral::printArea();
    }
};

class Parallelogram : public Quadrilateral {                   // Parallelogram class inherits from Quadrilateral.
public:
    Parallelogram(double w, double h) : Quadrilateral(w, h) {} // Constructor.
    double area() const override {                             // Override area calculation.
        return getWidth() * getHeight();
    }
    void printArea() const override {                          // Override printArea.
        cout << "Parallelogram ";
        Quadrilateral::printArea();
    }
};

class Trapezium : public Quadrilateral {                       // Trapezium class inherits from Quadrilateral.
private:
    double base;                                               // Additional base member for Trapezium.
public:
    Trapezium(double w, double h, double b) : Quadrilateral(w, h), base(b) {} // Constructor.
    double area() const override {                             // Override area calculation.
        return (getWidth() + base) / 2 * getHeight();
    }
    void printArea() const override {                          // Override printArea.
        cout << "Trapezium ";
        Quadrilateral::printArea();
    }
};

int main() {
    const int N = 3;                                           // Number of quadrilaterals.
    Quadrilateral* quads[N];                                   // Array of pointers to Quadrilateral.

    quads[0] = new Rectangle(3, 4);                            // Create a Rectangle (width=3, height=4).
    quads[1] = new Parallelogram(5, 6);                        // Create a Parallelogram (width=5, height=6).
    quads[2] = new Trapezium(2, 3, 4);                         // Create a Trapezium (width=2, height=3, base=4).

    for (int i = 0; i < N; i++) {                              // Loop through each quadrilateral.
        quads[i]->printArea();                                 // Print its area.
        cout << endl;                                          // Print a newline.
        delete quads[i]; // Free memory                        // Delete the object to free memory.
    }
    return 0;                                                  // End of program.
}


/*
------------------------------------------------------------
Summary of Program Functionality and Concepts Demonstrated
------------------------------------------------------------

1. Class Structure
------------------
- Quadrilateral (Base Class)
  - Represents a generic four-sided shape.
  - Stores width and height as private members.
  - Provides constructors (default and parameterized).
  - Includes setter and getter methods for width and height.
  - Declares virtual methods: area() (default returns 0) and printArea().

- Rectangle, Parallelogram, Trapezium (Derived Classes)
  - Inherit from Quadrilateral.
  - Each overrides area() to provide the correct formula:
      * Rectangle: width × height
      * Parallelogram: width × height
      * Trapezium: ((width + base) / 2) × height (with an extra base member)
  - Each overrides printArea() to display its type and area.

2. Main Function Logic
----------------------
- Creates an array of pointers to Quadrilateral.
- Each element is assigned a dynamically allocated object (Rectangle, Parallelogram, or Trapezium) with specific dimensions.
- Iterates through the array:
    * Calls printArea() for each shape.
    * Demonstrates polymorphism: the correct derived class method is called via the base class pointer.
    * Deletes each object to free memory and prevent leaks.

3. Object-Oriented Programming Concepts Illustrated
---------------------------------------------------
- Inheritance: Derived classes extend the base class.
- Polymorphism: Virtual functions enable dynamic binding and correct method calls at runtime.
- Encapsulation: Data members are private and accessed through public methods.
- Dynamic Memory Management: Objects are created with new and destroyed with delete.

4. Assignment Requirements Addressed
------------------------------------
a. Defines a Quadrilateral class with constructors and a print method for area.
b. Implements three subclasses (Rectangle, Parallelogram, Trapezium) with their own area calculations.
c. Creates an array of quadrilaterals, sets their sizes, and prints their areas.

------------------------------------------------------------
This program models different types of quadrilaterals using OOP principles, stores them in an array, and prints their areas. It demonstrates inheritance, polymorphism, encapsulation, and dynamic memory management—core concepts in C++ programming.
------------------------------------------------------------
*/

/*
------------------------------------------------------------
Assignment Guide: Step-by-Step Solution Approach
------------------------------------------------------------

Step 1: Understand the Assignment Requirements
----------------------------------------------
- The assignment asks you to:
  * Create a base class Quadrilateral with width, height, and area, including constructors and a print method.
  * Create three subclasses: Rectangle, Parallelogram, and Trapezium, each with its own area calculation.
  * Make an array of these shapes, set their sizes, and print their areas.

Step 2: Design the Base Class (Quadrilateral)
---------------------------------------------
- Data Members:
    - width and height (private for encapsulation).
- Constructors:
    - One that takes width and height as parameters.
    - One default constructor (sets width and height to 1).
- Member Functions:
    - Setters and getters for width and height.
    - A virtual area() function (returns 0 by default).
    - A virtual printArea() function to print the area.
- Why?
    - This sets up a general template for all four-sided shapes.

Step 3: Create Derived Classes
-----------------------------
- Rectangle:
    - Inherits from Quadrilateral.
    - Overrides area() to return width * height.
    - Overrides printArea() to print "Rectangle Area: ...".
- Parallelogram:
    - Inherits from Quadrilateral.
    - Overrides area() to return width * height.
    - Overrides printArea() to print "Parallelogram Area: ...".
- Trapezium:
    - Inherits from Quadrilateral.
    - Adds a new member: base (the second base).
    - Overrides area() to return ((width + base) / 2) * height.
    - Overrides printArea() to print "Trapezium Area: ...".
- Why?
    - Each shape has a different formula for area, so we override the base class method.

Step 4: Use Polymorphism and Dynamic Memory
-------------------------------------------
- Create an array of pointers to Quadrilateral.
- Assign each pointer to a new object:
    - One Rectangle, one Parallelogram, one Trapezium, each with specific sizes.
- Loop through the array:
    - Call printArea() for each shape.
    - Because of virtual functions, the correct version is called for each shape.
    - Delete each object after use to free memory.
- Why?
    - This demonstrates polymorphism: the ability to treat different shapes as the same type (Quadrilateral) and still get the correct behavior.

Step 5: Review and Test
-----------------------
- Make sure each class is implemented correctly.
- Check that the output matches the expected area for each shape.
- Ensure there are no memory leaks (delete what you new).

Summary
-------
By following these steps, you:
- Practice encapsulation (private data, public methods).
- Use inheritance (base and derived classes).
- Apply polymorphism (virtual functions).
- Manage dynamic memory (new/delete).

This is a classic OOP exercise that helps you understand how to design flexible, reusable code in C++.
------------------------------------------------------------
*/