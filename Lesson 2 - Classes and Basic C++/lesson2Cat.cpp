#include <iostream>
#include <string>
using namespace std;

class Cat {
    public:
    string Name;
    string Color;
    int Age;
    //...

    /*The instructor wrote "Problem?" in the slide so wild guess is Encapsulation.*/
    public:
    //getters
    string getName(){ //removed string Name
        return Name;
    };
    string getColor(string Color){
        return Color;
    };
    int getAge(int Age){
        return Age;
    };

    //setters
    void setName(string name){
        Name = name;
    };
    void setColor(string color){
        Color = color;
    };

    void setAge(int age){
        Age = age;
    };


};

int main(){
    //create an object of Cat
    Cat aConcreteCat;

    //using getters and setters
    aConcreteCat.setName("Calico");
    string name = aConcreteCat.getName();
    //cout << aConcreteCat.getName("Calico") << endl;

    // access attributes and set values
    // aConcreteCat.Name = "Calico";
    // aConcreteCat.Color = "black, white, and brown";
    // aConcreteCat.Age = 2;

    //print attributes values
    cout << aConcreteCat.Name << endl;
    cout << name << endl;
    // cout << aConcreteCat.Color << endl;
    // cout << aConcreteCat.Age << endl;

    //print addresses
    cout << "------------------------------------------------------------" << endl;
    cout << &aConcreteCat.Name << endl;
    cout << &name << endl;
    // cout << &aConcreteCat.Color << endl;   
    // cout << &aConcreteCat.Age << endl;

    return 0;
}