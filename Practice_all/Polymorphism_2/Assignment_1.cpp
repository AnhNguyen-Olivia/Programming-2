/*
================================================================================
Assignment: Shape Area Calculation and Sorting using OOP in C++
================================================================================

Objective:
----------
- Read shape data from a text file.
- Each shape is described by its type and coordinates.
- Compute the area for each shape.
- Sort all shapes in descending order of area.
- Write the sorted shapes and their areas to an output file.
- Use object-oriented programming: inheritance and polymorphism.

Input File Format (input.txt):
------------------------------
- First line: Number of shapes (max 100).
- Each subsequent line: Shape type and coordinates.
    - 't' (triangle): t x1 y1 x2 y2 x3 y3
    - 'r' (rectangle): r x1 y1 x2 y2
    - 's' (square): s x1 y1 x2 y2 x3 y3 x4 y4
    - 'p' (parallelogram): p x1 y1 y2 y2 x3 y4

Example:
2
t 0 1 1 3 12 1
r 1 2 4 8

Output File Format (output.txt):
--------------------------------
- First line: Number of shapes.
- Each subsequent line: Shape data followed by "->" and its area, sorted by area (largest first).

Example:
2
r 1 2 4 8 -> 18
t 0 1 1 3 12 1 -> 12

================================================================================
Key Concepts Demonstrated:
--------------------------
- Abstract base class and pure virtual functions.
- Inheritance and polymorphism for shape types.
- File input/output and data parsing.
- Dynamic memory management.
- Manual sorting of objects by computed property (area).
- Clean code organization and commenting.

================================================================================
*/

#include <iostream>      // Standard input/output streams
#include <fstream>       // File input/output streams
#include <sstream>       // String stream for parsing lines
#include <string>        // String class
using namespace std;

// -----------------------------------------------------------------------------
// Abstract base class for all shapes
// -----------------------------------------------------------------------------
class Shape {
public:
    // Compute the area of the shape (must be implemented by derived classes)
    virtual double area() const = 0;
    // Print the shape's data in the required format
    virtual void print(ostream& out) const = 0;
    // Virtual destructor for proper cleanup of derived objects
    virtual ~Shape() {}
};

// -----------------------------------------------------------------------------
// Triangle class: represents a triangle defined by 3 points
// -----------------------------------------------------------------------------
class Triangle : public Shape {
    int x1, y1, x2, y2, x3, y3;
public:
    Triangle(int x1, int y1, int x2, int y2, int x3, int y3) 
        : x1(x1), y1(y1), x2(x2), y2(y2), x3(x3), y3(y3) {}
    // Area using the shoelace formula
    double area() const override {
        return 0.5 * abs(x1*(y2 - y3) + x2*(y3 - y1) + x3*(y1 - y2));
    }
    void print(ostream& out) const override {
        out << "t " << x1 << " " << y1 << " " << x2 << " " << y2 << " " << x3 << " " << y3;
    }
};

// -----------------------------------------------------------------------------
// Rectangle class: represents a rectangle defined by two opposite corners
// -----------------------------------------------------------------------------
class Rectangle : public Shape {
    int x1, y1, x2, y2;
public:
    Rectangle(int x1, int y1, int x2, int y2) 
        : x1(x1), y1(y1), x2(x2), y2(y2) {}
    // Area = width * height
    double area() const override {
        return abs((x2 - x1) * (y2 - y1));
    }
    void print(ostream& out) const override {
        out << "r " << x1 << " " << y1 << " " << x2 << " " << y2;
    }
};

// -----------------------------------------------------------------------------
// Square class: represents a square defined by 4 points
// -----------------------------------------------------------------------------
class Square : public Shape {
    int x1, y1, x2, y2, x3, y3, x4, y4;
public:
    Square(int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4) 
        : x1(x1), y1(y1), x2(x2), y2(y2), x3(x3), y3(y3), x4(x4), y4(y4) {}
    // Area using the shoelace formula for quadrilaterals
    double area() const override {
        return 0.5 * abs((x1*y2 + x2*y3 + x3*y4 + x4*y1) - (y1*x2 + y2*x3 + y3*x4 + y4*x1));
    }
    void print(ostream& out) const override {
        out << "s " << x1 << " " << y1 << " " << x2 << " " << y2 << " " 
            << x3 << " " << y3 << " " << x4 << " " << y4;
    }
};

// -----------------------------------------------------------------------------
// Parallelogram class: represents a parallelogram as described in the assignment
// -----------------------------------------------------------------------------
class Parallelogram : public Shape {
    int x1, y1, y2, x2, y3, y4;
public:
    Parallelogram(int x1, int y1, int y2, int x2, int y3, int y4) 
        : x1(x1), y1(y1), y2(y2), x2(x2), y3(y3), y4(y4) {}
    // Area calculation (assumes axis-aligned parallelogram)
    double area() const override {
        return abs((y2 - y1) * (x2 - x1));
    }
    void print(ostream& out) const override {
        out << "p " << x1 << " " << y1 << " " << y2 << " " << x2 << " " << y3 << " " << y4;
    }
};

int main() {
    // -------------------------------------------------------------------------
    // Step 1: Open and validate the input file
    // -------------------------------------------------------------------------
    ifstream infile("E:/Programming-2/Practice_all/Polymorphism_2/input.txt");
    if (!infile) {
        cerr << "Error opening input file." << endl;
        return 1;
    }

    int n; // Number of shapes to read
    infile >> n;
    infile.ignore(); // Skip the newline after the number
    Shape* shapes[100]; // Array to store pointers to shape objects
    int shape_count = 0; // Actual number of shapes read

    // -------------------------------------------------------------------------
    // Step 2: Read and parse each shape from the file
    // -------------------------------------------------------------------------
    for (int i = 0; i < n && shape_count < 100; ++i) {
        string line;
        if (!getline(infile, line)) {
            cerr << "Error reading line for shape " << i << endl;
            break;
        }

        stringstream ss(line);
        char type;
        ss >> type;

        Shape* shape = nullptr;
        switch (type) {
            case 't': { // Triangle
                int x1, y1, x2, y2, x3, y3;
                if (ss >> x1 >> y1 >> x2 >> y2 >> x3 >> y3) {
                    shape = new Triangle(x1, y1, x2, y2, x3, y3);
                } else {
                    cerr << "Invalid triangle coordinates." << endl;
                }
                break;
            }
            case 'r': { // Rectangle
                int x1, y1, x2, y2;
                if (ss >> x1 >> y1 >> x2 >> y2) {
                    shape = new Rectangle(x1, y1, x2, y2);
                } else {
                    cerr << "Invalid rectangle coordinates." << endl;
                }
                break;
            }
            case 's': { // Square
                int x1, y1, x2, y2, x3, y3, x4, y4;
                if (ss >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4) {
                    shape = new Square(x1, y1, x2, y2, x3, y3, x4, y4);
                } else {
                    cerr << "Invalid square coordinates." << endl;
                }
                break;
            }
            case 'p': { // Parallelogram
                int x1, y1, y2, x2, y3, y4;
                if (ss >> x1 >> y1 >> y2 >> x2 >> y3 >> y4) {
                    shape = new Parallelogram(x1, y1, y2, x2, y3, y4);
                } else {
                    cerr << "Invalid parallelogram coordinates." << endl;
                }
                break;
            }
            default: {
                cerr << "Unknown shape type: " << type << endl;
                break;
            }
        }

        if (shape != nullptr) {
            shapes[shape_count++] = shape;
        }
    }

    // -------------------------------------------------------------------------
    // Step 3: Sort shapes in descending order of area using bubble sort
    // -------------------------------------------------------------------------
    for (int i = 0; i < shape_count - 1; ++i) {
        for (int j = 0; j < shape_count - i - 1; ++j) {
            if (shapes[j]->area() < shapes[j + 1]->area()) {
                Shape* temp = shapes[j];
                shapes[j] = shapes[j + 1];
                shapes[j + 1] = temp;
            }
        }
    }

    // -------------------------------------------------------------------------
    // Step 4: Write sorted shapes and their areas to the output file
    // -------------------------------------------------------------------------
    ofstream outfile("output.txt");
    if (!outfile) {
        cerr << "Error opening output file." << endl;
        return 1;
    }

    outfile << shape_count << endl; // Write the number of shapes
    for (int i = 0; i < shape_count; ++i) {
        shapes[i]->print(outfile);
        outfile << " -> " << shapes[i]->area() << endl;
    }

    // -------------------------------------------------------------------------
    // Step 5: Clean up dynamically allocated memory
    // -------------------------------------------------------------------------
    for (int i = 0; i < shape_count; ++i) {
        delete shapes[i];
    }

    return 0;
}

/*
================================================================================
Learning Outcomes:
------------------
- Practice OOP: inheritance, polymorphism, and virtual functions.
- Parse and process structured data from files.
- Implement geometric algorithms for area calculation.
- Sort objects based on computed properties.
- Manage dynamic memory safely in C++.
- Organize and document code for clarity and maintainability.
================================================================================
*/

/*
================================================================================
Step-by-Step Guide to Solving the Assignment
================================================================================

1. Read and Analyze the Assignment
----------------------------------
Goal: Understand what is being asked.
Key Points:
- Read shape data from a file.
- Each shape has a type and coordinates.
- Calculate the area for each shape.
- Sort shapes by area (largest to smallest).
- Write the sorted shapes and their areas to an output file.
- Use OOP: inheritance and polymorphism.

2. Design Your Classes
----------------------
a. Base Class: Shape
- Make it abstract (at least one pure virtual function).
- Functions:
    - virtual double area() const = 0;
    - virtual void print(ostream&) const = 0;
    - Virtual destructor.

b. Derived Classes
- Triangle: Store 3 points.
- Rectangle: Store 2 points (lower-left and upper-right).
- Square: Store 4 points.
- Parallelogram: Store 4 points as described.

Tip:
- Write down the data members and constructors for each class.

3. Implement Area Calculations
------------------------------
- Triangle: Use the shoelace formula.
- Rectangle: (x2 - x1) * (y2 - y1)
- Square: Shoelace formula or side squared.
- Parallelogram: Shoelace formula for 4 points or base × height if axis-aligned.

Tip:
- Test each formula with sample values to ensure correctness.

4. Plan File Input
------------------
- Open the input file.
- Read the first line (number of shapes).
- For each subsequent line:
    - Read the shape type.
    - Read the correct number of coordinates.
    - Create the appropriate shape object using new and store a pointer to it.

Tip:
- Use stringstream to parse each line.

5. Store Shapes
---------------
- Use an array or std::vector of Shape* to store all shapes.
- Keep track of how many shapes you have.

6. Sort the Shapes
------------------
- Sort the array/vector of pointers by the area, descending.
- If not using <algorithm>, implement bubble sort or selection sort manually.

7. Write Output File
--------------------
- Open the output file.
- Write the number of shapes.
- For each shape:
    - Use the print() method to write its data.
    - Write " -> " and the area.

8. Memory Management
--------------------
- After writing the output, delete all dynamically allocated shapes to prevent memory leaks.

9. Test Your Program
--------------------
- Use the sample input and output.
- Try with different shapes and values.
- Check for edge cases (e.g., invalid input, zero area).

10. Comment and Clean Up
------------------------
- Add comments explaining each part of your code.
- Make sure your code is readable and well-organized.

Example Workflow
----------------
- Write the Shape base class.
- Write the Triangle, Rectangle, Square, and Parallelogram classes.
- Implement area and print methods for each.
- Write code to open and read the input file.
- Parse each line and create the correct shape object.
- Store all shapes in an array/vector.
- Sort the shapes by area.
- Write the sorted shapes to the output file.
- Delete all shape objects.
- Test and debug.

Extra Tips
----------
- If you’re unsure about parsing, print out the data as you read it.
- If you’re unsure about area formulas, test them in a small, separate program.
- Use functions to keep your main() short and organized.

By following these steps, you’ll build your solution incrementally and understand each part of the process.
================================================================================
*/