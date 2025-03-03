#include <iostream>
#include <vector>
#include <string>
using namespace std;

// Address Class
class Address {
public:
    string streetName;
    int houseNumber;
    string cityName;

    Address(string street, int number, string city)
        : streetName(street), houseNumber(number), cityName(city) {}
};

// Dog Class
class Dog {
public:
    string name;
    int code;
    Address* house;  // Pointer to the dog's house

    Dog(string name, int code) : name(name), code(code), house(nullptr) {}

    void makeNoise() {
        cout << name << " is barking!" << endl;
    }
};

// House Class
class House {
private:
    Address address;
    vector<Dog*> dogs;  // Collection of dogs in the house

public:
    // Constructor
    House(Address addr) : address(addr) {}

    // Function to add a dog
    void addDog(Dog* dog) {
        dog->house = &address;  // Set the dog's house
        dogs.push_back(dog);
        cout << dog->name << " has been added to the house!" << endl;
    }

    // Function to remove a dog
    void removeDog(Dog* dog) {
        for (auto it = dogs.begin(); it != dogs.end(); ++it) {
            if (*it == dog) {
                dog->house = nullptr;  // Remove the house association
                dogs.erase(it);
                cout << dog->name << " has been removed from the house!" << endl;
                return;
            }
        }
        cout << dog->name << " is not in the house!" << endl;
    }

    // Function to count the number of dogs
    int countDogs() {
        return dogs.size();
    }
};

// Main Function to Test the Classes
int main() {
    Address address("Maple Street", 123, "Dogville");
    House myHouse(address);

    Dog dog1("Buddy", 101);
    Dog dog2("Max", 102);

    myHouse.addDog(&dog1);
    myHouse.addDog(&dog2);

    cout << "Number of dogs in the house: " << myHouse.countDogs() << endl;

    dog1.makeNoise();
    dog2.makeNoise();

    myHouse.removeDog(&dog1);
    cout << "Number of dogs in the house: " << myHouse.countDogs() << endl;

    return 0;
}
