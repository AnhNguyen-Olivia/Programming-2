/*#include <stdio.h>

int main() {
    int a, b, choice;
    printf("Enter the first number: ");
    scanf("%d", &a);
    printf("Enter the second number: ");
    scanf("%d", &b);
    printf("Please select the operation you want to perform: \n");
    printf("[1]. Addition\n");
    printf("[2]. Subtraction\n");
    printf("[3]. Multiplication\n");
    printf("[4]. Division\n");
    printf("[5]. Modulus\n");
    printf("[6]. Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);
    
    switch(choice) {
        case 1:
            printf("The sum of %d and %d is %d\n", a, b, a + b);
            break;
        case 2:
            printf("The difference of %d and %d is %d\n", a, b, a - b);
            break;
        case 3:
            printf("The product of %d and %d is %d\n", a, b, a * b);
            break;
        case 4:
            printf("The division of %d and %d is %d\n", a, b, a / b);
            break;
        case 5:
            printf("The modulus of %d and %d is %d\n", a, b, a % b);
            break;
        case 6:
            printf("Exiting the program...\n");
            break;
        default:
            printf("Invalid choice\n");
    }
    return 0;
}*/

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