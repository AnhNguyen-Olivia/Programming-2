/*
Assignment:
1. Create a class with an overloaded increment operator (both prefix and postfix).
2. Create a class with an int, overload operator+ as a member function.
3. Add operator- as a member function and show complex expressions.
4. Add prefix and postfix operator++ and operator--, returning the incremented/decremented object.
5. Prefix should return non-const reference, postfix should return const object.
*/

#include <iostream>

// Exercise 1: Counter class with overloaded increment operators
class Counter {
    int count; // Internal counter value
public:
    Counter() : count(0) {} // Constructor initializes count to 0

    // Prefix increment: ++c
    Counter& operator++() {
        ++count;            // Increment count
        return *this;       // Return reference to current object
    }

    // Postfix increment: c++
    Counter operator++(int) {
        Counter temp = *this; // Save current state
        ++count;              // Increment count
        return temp;          // Return old state (before increment)
    }

    int getCount() const { return count; } // Getter for count
};

// Exercises 2-5: Number class with overloaded arithmetic and increment/decrement operators
class Number {
    int value; // Internal integer value
public:
    Number(int v = 0) : value(v) {} // Constructor with default value 0

    // Exercise 2: Addition operator (member function)
    Number operator+(const Number& other) const {
        return Number(value + other.value); // Add values, return new Number
    }

    // Exercise 3: Subtraction operator (member function)
    Number operator-(const Number& other) const {
        return Number(value - other.value); // Subtract values, return new Number
    }

    // Exercise 4 & 5: Prefix increment: ++x
    Number& operator++() {
        ++value;            // Increment value
        return *this;       // Return reference to current object (non-const)
    }

    // Postfix increment: x++
    const Number operator++(int) {
        Number temp = *this; // Save current state
        ++value;             // Increment value
        return temp;         // Return old state (const object)
    }

    // Prefix decrement: --x
    Number& operator--() {
        --value;            // Decrement value
        return *this;       // Return reference to current object (non-const)
    }

    // Postfix decrement: x--
    const Number operator--(int) {
        Number temp = *this; // Save current state
        --value;             // Decrement value
        return temp;         // Return old state (const object)
    }

    int getValue() const { return value; } // Getter for value
};

int main() {
    // Exercise 1 Test: Counter increment
    Counter c;
    ++c;    // Prefix increment: count becomes 1
    c++;    // Postfix increment: count becomes 2
    std::cout << "Count: " << c.getCount() << std::endl;  // Output: 2

    // Exercise 2 Test: Addition
    Number a(5), b(3);
    Number sumResult = a + b; // Uses overloaded operator+
    std::cout << "Sum: " << sumResult.getValue() << std::endl;  // Output: 8

    // Exercise 3 Test: Complex expression with + and -
    Number d(10), f(4), g(3);
    Number result = d + f - g;  // (10 + 4) - 3 = 11
    std::cout << "Result: " << result.getValue() << std::endl;  // Output: 11

    // Exercise 4 Test: Prefix and postfix increment
    Number x(5);
    Number y = x++;  // Postfix: y = 5, x = 6
    Number z = ++x;  // Prefix: x = 7, z = 7
    std::cout << "x: " << x.getValue()   // Output: 7
              << ", y: " << y.getValue() // Output: 5
              << ", z: " << z.getValue() // Output: 7
              << std::endl;

    // Exercise 5 Test: Chaining prefix, postfix returns const
    ++(++x);        // Valid: prefix returns non-const reference, x = 9
    // (x++)++;     // Invalid: postfix returns const object, cannot increment
    std::cout << "Final x: " << x.getValue() << std::endl;  // Output: 9
}

/*
Why should prefix return a non-const reference and postfix return a const object?

- Prefix (++x/--x) returns a non-const reference so you can chain operations and modify the original object directly.
  Example: ++(++x); // Valid, both increments apply to x.

- Postfix (x++/x--) returns a const object to prevent accidental modification of the temporary result.
  Example: (x++)++; // Invalid, because the result of x++ is a const temporary and should not be modified.

This design follows C++ best practices, avoids unnecessary copying, and prevents subtle bugs from modifying temporaries.
*/

/*
    PROGRAM PURPOSE AND LESSON

    This program is designed to teach and demonstrate the correct way to overload
    increment (++) and decrement (--) operators in C++ for user-defined classes.

    In C++, operator overloading allows you to define how operators like +, -, ++, and --
    behave when used with objects of your own classes. This makes your classes easier to use
    and more intuitive, behaving like built-in types.

    The program focuses on the following key concepts:

    1. **Prefix vs. Postfix Operators:**
       - Prefix (++x or --x): The operator is applied before the value is used in an expression.
       - Postfix (x++ or x--): The operator is applied after the value is used in an expression.
       - The compiler distinguishes between them by the presence of an unused int parameter in the postfix version.

    2. **Return Types and Chaining:**
       - Prefix versions should return a non-const reference to the object. This allows chaining (e.g., ++(++x)),
         so multiple operations can be performed in a single statement, directly modifying the original object.
       - Postfix versions should return a const object (a copy of the original value before increment/decrement).
         This prevents accidental modification of the temporary result (e.g., (x++)++ is not allowed), which could
         lead to subtle bugs if allowed.

    3. **Best Practices:**
       - Returning a non-const reference from prefix avoids unnecessary copying and enables efficient chaining.
       - Returning a const object from postfix protects against modifying temporaries and enforces correct usage.

    4. **Operator Overloading for Arithmetic:**
       - The program also shows how to overload + and - operators so that objects can be added and subtracted
         just like built-in types.

    5. **Practical Demonstration:**
       - The main function demonstrates the use of these overloaded operators, showing how prefix and postfix
         increment/decrement work, how chaining is allowed or disallowed, and how arithmetic operators can be used.

    By studying this program, you will learn:

    - The syntax for overloading prefix and postfix increment/decrement operators:
        This program shows how to write special member functions in your class to define how
        the ++ and -- operators work for both prefix (e.g., ++x) and postfix (e.g., x++) forms.
        Example: The prefix version (++x or --x) is declared as:
            Number& operator++();   // Prefix increment
            Number& operator--();   // Prefix decrement

        The prefix version is written as operator++() or operator--(), while the postfix version
        is written as operator++(int) or operator--(int), where the int parameter is only used
        to distinguish postfix from prefix.
        Example: The postfix version (x++ or x--) is declared with an unused int parameter to distinguish it:
            Number operator++(int);   // Postfix increment
            Number operator--(int);   // Postfix decrement    

    - The importance of correct return types for these operators:
        The program demonstrates that prefix operators should return a non-const reference to the
        object, allowing you to chain operations like ++(++x) and directly modify the original object.
        Postfix operators should return a const object (a copy of the original value before the
        increment or decrement), which prevents accidental modification of temporary objects and
        avoids subtle bugs, such as trying to do (x++)++.

    - How to make your classes behave like built-in types for arithmetic and increment/decrement operations:
        By overloading operators such as +, -, ++, and --, your class objects can be used in expressions
        just like built-in types (e.g., int or double). This makes your classes more intuitive and easier
        to use, especially for mathematical or counter-like objects.

    - How to write safer, more intuitive, and more maintainable C++ code:
        Using the correct operator overloading techniques and return types helps prevent bugs and
        makes your code easier to read and maintain. It ensures that your classes are robust, efficient,
        and behave as expected, making them safer for you and others to use in larger projects.
*/