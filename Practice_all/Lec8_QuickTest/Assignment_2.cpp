/*
Write a probram with a mother class animal. Inside it
define a name and an age variables, and set_value()
function.Then create two bases variables Zebra and
Dolphin which write a message telling the age, the name
and giving some extra information (e.g. place of origin)
*/

#include <iostream>
using namespace std;

class Animal {
private:
    string name;
    int age;
public:
    void set_value(string n, int a) { //this is just a constructor
        name = n;
        age = a;
    }
    string get_name() {
        return name;
    }
    int get_age() {
        return age;
    }
};

class Zebra : public Animal {
public:
    void display() {
        cout << "Zebra Name: " << get_name() << endl;
        cout << "Zebra Age: " << get_age() << endl;
        cout << "Extra Info: Zebras are native to Africa." << endl;
    }
};

class Dolphin : public Animal {
public:
    void display() {
        cout << "Dolphin Name: " << get_name() << endl;
        cout << "Dolphin Age: " << get_age() << endl;
        cout << "Extra Info: Dolphins are found in oceans worldwide." << endl;
    }
};

int main() {
    Zebra z;
    Dolphin d;

    z.set_value("Marty", 5);
    d.set_value("Flipper", 8);

    cout << "Zebra Info:" << endl;
    z.display();
    cout << endl;

    cout << "Dolphin Info:" << endl;
    d.display();

    return 0;
}