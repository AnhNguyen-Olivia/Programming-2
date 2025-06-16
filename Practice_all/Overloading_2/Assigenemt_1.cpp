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

#include <iostream> // Include the standard input/output stream library

// Define a class named Time to represent a time value
class Time {
private:
    int hours;   // Stores the hour part (0-23)
    int minutes; // Stores the minute part (0-59)
    int seconds; // Stores the second part (0-59)

public:
    // Default constructor: sets time to 00:00:00
    Time() : hours(0), minutes(0), seconds(0) {}

    // Parameterized constructor: sets time to given h, m, s
    Time(int h, int m, int s) : hours(h), minutes(m), seconds(s) {}

    // Display the time in "Time: hh:mm:ss" format
    void display() const {
        std::cout << "Time: " << hours << ":" << minutes << ":" << seconds << std::endl;
    }

    // Overload the + operator to add two Time objects
    // Returns a new Time object representing the sum (24-hour wrap)
    Time operator+(const Time& t) {
        // Convert both times to total seconds, add, and wrap at 24 hours
        int totalSeconds = ((hours * 3600 + minutes * 60 + seconds) +
                            (t.hours * 3600 + t.minutes * 60 + t.seconds)) % (24 * 3600);
        // Convert total seconds back to hours, minutes, seconds
        return Time(
            totalSeconds / 3600,                // Extract hours
            (totalSeconds % 3600) / 60,         // Extract minutes
            totalSeconds % 60                   // Extract seconds
        );
    }

    // Overload the > operator to compare two Time objects
    // Returns true if this time is later than t
    bool operator>(const Time& t) {
        if (hours != t.hours) return hours > t.hours;         // Compare hours first
        if (minutes != t.minutes) return minutes > t.minutes; // If hours equal, compare minutes
        return seconds > t.seconds;                           // If minutes equal, compare seconds
    }

    // Overload the assignment operator to copy another Time object
    Time& operator=(const Time& t) {
        if (this != &t) { // Check for self-assignment
            hours = t.hours;       // Copy hours
            minutes = t.minutes;   // Copy minutes
            seconds = t.seconds;   // Copy seconds
        }
        return *this; // Return reference to this object
    }
};

int main() {
    // Create a Time object t1 with 10:30:45
    Time t1(10, 30, 45);
    // Create a Time object t2 with 5:45:15
    Time t2(5, 45, 15);

    // Display t1
    t1.display();
    // Display t2
    t2.display();

    // Add t1 and t2 using overloaded +, store in t3
    Time t3 = t1 + t2;
    // Display t3 (sum of t1 and t2)
    t3.display();

    // Compare t1 and t2 using overloaded >
    if (t1 > t2) {
        std::cout << "t1 is greater than t2" << std::endl;
    } else {
        std::cout << "t1 is not greater than t2" << std::endl;
    }
    
    // Assign t2 to t1 using overloaded =
    t1 = t2;
    std::cout << "After assignment, t1: ";
    t1.display();

    return 0; // End of program
}