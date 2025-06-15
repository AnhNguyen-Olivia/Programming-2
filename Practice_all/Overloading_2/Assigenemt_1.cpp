/*
Assignment:
    1. Write a program to create a class called Time which is
    used to represent time. The class should have three fields
    for hours, minutes and seconds. Add the following
    member methods:
        • a default constructor;
        • a constructor with parameters;
        • overloaded plus operator (+) (add two time objects
            based on 24 hour clock);
        • overloaded comparison operator (>) (compare two
            time objects);
        • overloaded assignment operator (=).
*/

#include <iostream> // Provides input/output stream objects

// Time class definition for representing and manipulating time values
class Time {
private:
    int hours;   // Holds the hour component (0-23)
    int minutes; // Holds the minute component (0-59)
    int seconds; // Holds the second component (0-59)

public:
    // Default constructor: initializes time to midnight (00:00:00)
    Time() : hours(0), minutes(0), seconds(0) {}

    // Parameterized constructor: initializes time to given hours, minutes, and seconds
    Time(int h, int m, int s) : hours(h), minutes(m), seconds(s) {}

    // Displays the time in "Time: hh:mm:ss" format
    void display() const {
        std::cout << "Time: " << hours << ":" << minutes << ":" << seconds << std::endl;
    }

    // Overloads the + operator to add two Time objects
    // The result wraps around after 24 hours (24-hour clock)
    Time operator+(const Time& t) {
        // Convert both times to total seconds, add, and wrap around 24 hours
        int totalSeconds = ((hours * 3600 + minutes * 60 + seconds) +
                            (t.hours * 3600 + t.minutes * 60 + t.seconds)) % (24 * 3600);
        // Convert total seconds back to hours, minutes, and seconds
        return Time(
            totalSeconds / 3600,                // Calculate hours
            (totalSeconds % 3600) / 60,         // Calculate minutes
            totalSeconds % 60                   // Calculate seconds
        );
    }

    // Overloads the > operator to compare two Time objects
    // Returns true if the current object is later than the argument
    bool operator>(const Time& t) {
        if (hours != t.hours) return hours > t.hours;         // Compare hours first
        if (minutes != t.minutes) return minutes > t.minutes; // If hours are equal, compare minutes
        return seconds > t.seconds;                           // If minutes are equal, compare seconds
    }

    // Overloads the assignment operator to copy values from another Time object
    Time& operator=(const Time& t) {
        if (this != &t) { // Prevent self-assignment
            hours = t.hours;
            minutes = t.minutes;
            seconds = t.seconds;
        }
        return *this; // Return reference to the current object for chaining
    }
};

int main() {
    // Create a Time object t1 with 10 hours, 30 minutes, 45 seconds
    Time t1(10, 30, 45);
    // Create a Time object t2 with 5 hours, 45 minutes, 15 seconds
    Time t2(5, 45, 15);

    // Display the initial values of t1 and t2
    t1.display();
    t2.display();

    // Add t1 and t2 using the overloaded + operator, store result in t3
    Time t3 = t1 + t2;
    // Display the result of the addition
    t3.display();

    // Compare t1 and t2 using the overloaded > operator
    if (t1 > t2) {
        std::cout << "t1 is greater than t2" << std::endl;
    } else {
        std::cout << "t1 is not greater than t2" << std::endl;
    }
    
    // Assign t2 to t1 using the overloaded assignment operator
    t1 = t2;
    std::cout << "After assignment, t1: ";
    t1.display();

    return 0; // Indicate successful program termination