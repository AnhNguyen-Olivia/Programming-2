#include <iostream>
using namespace std;

int main(){
    int a, b, choice;
    cout << "Enter the first number: ";
    cin >> a;
    cout << "Enter the second number: ";
    cin >> b;
    cout << "Please select the operation you want to perform: \n";
    cout << "[1]. Addition\n";
    cout << "[2]. Subtraction\n";
    cout << "[3]. Multiplication\n";
    cout << "[4]. Division\n";
    cout << "[5]. Modulus\n";
    cout << "[6]. Exit\n";
    cout << "Enter your choice: ";
    cin >> choice;
    switch(choice){
        case 1:
            cout << "The sum of " << a << " and " << b << " is " << a+b << endl;
            break;
        case 2:
            cout << "The difference of " << a << " and " << b << " is " << a-b << endl;
            break;
        case 3:
            cout << "The product of " << a << " and " << b << " is " << a*b << endl;
            break;
        case 4:
            cout << "The division of " << a << " and " << b << " is " << a/b << endl;
            break;
        case 5:
            cout << "The modulus of " << a << " and " << b << " is " << a%b << endl;
            break;
        case 6:
            cout << "Exiting the program..." << endl;
            break;
        default:
            cout << "Invalid choice" << endl;
    }
    return 0;

}