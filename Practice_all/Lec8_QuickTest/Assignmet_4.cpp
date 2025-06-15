/*
Assignment 4: Inheritance and Classes

- Create a base class "Person".
- Create two derived classes: "Student" and "Teacher", both inheriting from "Person".

Requirements:
1. The "Student" class should have a public method "GoToClasses" that prints:
   "I'm going to class."
2. The "Teacher" class should have:
   - A private string attribute "subject".
   - A public method "Explain" that prints: "Explanation begins."
3. The "Person" class must have a method "SetAge(int n)" to set the person's age.
4. The "Student" class should have a public method "ShowAge" that prints:
   "My age is: 20 years old" (or the corresponding age).
5. Create a test class "StudentAndTeacherTest" with a static "Main" method that:
   - Creates a Person and makes them say hello.
   - Creates a Student, sets their age to 21, greets, and displays their age.
   - Creates a Teacher, sets their age to 30, greets, and explains.
*/



#include <iostream>
#include <string>
using namespace std;

// Base class: Person
class Person {
protected:
    int age;

public:
    void SetAge(int n) {
        age = n;
    }

    void Greet() {
        cout << "Hello!" << endl;
    }
};

// Derived class: Student
class Student : public Person {
public:
    void GoToClasses() {
        cout << "I'm going to class." << endl;
    }

    void ShowAge() {
        cout << "My age is: " << age << " years old." << endl;
    }
};

// Derived class: Teacher
class Teacher : public Person {
private:
    string subject;

public:
    void SetSubject(string s) {
        subject = s;
    }

    void Explain() {
        cout << "Explanation begins." << endl;
    }
};

// Test class
class StudentAndTeacherTest {
public:
    static void Main() {
        // Create a Person and make it say hello
        Person person;
        person.Greet();

        cout << endl;

        // Create a Student, set age, greet, and show age
        Student student;
        student.SetAge(21);
        student.Greet();
        student.ShowAge();
        student.GoToClasses();

        cout << endl;

        // Create a Teacher, set age, greet, and explain
        Teacher teacher;
        teacher.SetAge(30);
        teacher.Greet();
        teacher.Explain();
    }
};

// Main function
int main() {
    StudentAndTeacherTest::Main();
    return 0;
}
