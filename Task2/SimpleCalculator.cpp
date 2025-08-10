#include <iostream>
using namespace std;

int main() {
    // Internship Project: Simple Calculator
    // Author: Shivanshu Tiwari
    // Date: Aug 2025

    double num1, num2;
    char operation;

    cout << "--------------------------------------\n";
    cout << "         SIMPLE CALCULATOR\n";
    cout << "--------------------------------------\n";
    cout << "Available operations: +  -  *  /\n";
    
    // Taking user inputs
    cout << "Enter first number: ";
    cin >> num1;

    cout << "Enter second number: ";
    cin >> num2;

    cout << "Choose an operation (+, -, *, /): ";
    cin >> operation;

    cout << "\nResult: ";
    
    // Performing chosen operation
    switch (operation) {
        case '+':
            cout << num1 << " + " << num2 << " = " << (num1 + num2);
            break;

        case '-':
            cout << num1 << " - " << num2 << " = " << (num1 - num2);
            break;

        case '*':
            cout << num1 << " * " << num2 << " = " << (num1 * num2);
            break;

        case '/':
            if (num2 != 0) {
                cout << num1 << " / " << num2 << " = " << (num1 / num2);
            } else {
                cout << "Error! Division by zero is not allowed.";
            }
            break;

        default:
            cout << "Invalid operation entered!";
            break;
    }

    cout << "\n--------------------------------------\n";
    cout << "Thank you for using the calculator!\n";

    return 0;
}
