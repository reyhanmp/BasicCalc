// Basic Calc.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

using namespace std;

void calc();
void poly();
void newdisp(int no);
int inputcheck();
int derive(int con, int pow);
int intcheck();

int main() {

    int mode, repeat = 1;
    string isRepeat;

    cout << "Basic Calc v1.0" << endl;

    while (repeat == 1) {
        while (1) {
            cout << "Mode:\n1.Simple Calculation\n2.Polynomial Derivation\nEnter the number: " << endl;
            cin >> mode;
            if (mode == 1) {
                newdisp(1);
                calc();
                break;
            }
            else if (mode == 2) {
                newdisp(2);
                poly();
                break;
            }
            else {
                cout << "Please enter the correct number: ";
                cin.clear();
                cin.ignore();
            }
        }

        cout << "\n\n\nReset(Y/N)?";
        while (1) {
            cin >> isRepeat;
            if (isRepeat == "Y" || isRepeat == "y") {
                repeat = 1;
                newdisp(0);
                break;
            }
            else if(isRepeat == "N" || isRepeat == "n"){
                repeat = 0;
                newdisp(0);
                cout << "\n\n\n\nThank you for using Basic Calculator v1.0.\nSee you next time!\n\n\n\n\n";
                break;
            }
            else {
                newdisp(0);
                cout << "\n\nERROR! Please enter Y/N: ";
                cin.clear();
                cin.ignore();

            }
        }
    }
    return 0;
}

void newdisp(int no) {
    system("cls");
    cout << "Basic Calc v1.0";
    if (no == 1) {
        cout << "\nSimple Calculator\n";
    }
    else if (no == 2) {
        cout << "\nPolynomial Derivation\n";
    }
    else if (no == 0) {
        cout << "\n";
    }
}

int intcheck(){
    int x;
    while (!(cin >> x)) {
        cout << "ERROR! Please enter an integer: ";
        cin.clear();
        cin.ignore();
    }
    return x;
}
void calc() {
    int a, b, result;
    char op;

    cout << "\nEnter the first number: ";
    a = intcheck();
 
    cout << "\nEnter the second number: ";
    cin >> b;
    
    cout << "\nEnter the operator (+,-,*,/,%): ";
    while (1) {
        cin >> op;
        if (op == '+') {
            result = a + b;
            break;
        }
        else if (op == '-') {
            result = a - b;
            break;
        }
        else if (op == '*') {
            result = a * b;
            break;
        }
        else if (op == '/') {
            result = a / b;
            break;
        }
        else if (op == '%') {
            result = a % b;
            break;
        }
        else {
            newdisp(1);
            cout << "\nFirst number : " << a << "\nSecond number : " << b;
            cout << "\nError: Enter a correct operator!\nEnter the operator (+,-,*,/,%): ";
            cin.clear();
            cin.ignore();
        }
    }
    cout << "\n" << a << op << b << "=" << result;
}

int derive(int con, int pow) {
    int result{ pow * con };
    return result;
}
void poly() {

    int arr[100],power;
    cout << "\nEnter the highest degree of the polynomial equation: ";
    cin >> power;
    power;

    for (int i = 0; i <= power; i++) {
        cout << "\nEnter the constant for x^" << i << " :";
        cin >> arr[i];
    }
    cout << "\nThis is your polynomial equation: ";
    for (int i = power; i >= 0; i--) {
        if (i == power) {
            cout << arr[i] << "x^" << i;
        }
        else if (i >= 0) {
            if (arr[i] >= 0) {
                cout << " + " << abs(arr[i]) << "x^" << i;
            }
            else if (arr[i] < 0) {
                cout << " - " << abs(arr[i]) << "x^" << i;
            }
        }
    }
    cout << "\n\nThe derivative of the equation is: ";
    for (int i = power; i > 0; --i) {
            if (i == power) {
                cout << derive(arr[i], i) << "x^" << i;
            }
            else if (i >= 0) {
                if (arr[i] >= 0) {
                    cout << " + " << abs(derive(arr[i], i)) << "x^" << i;
                }
                else if (arr[i] < 0) {
                    cout << " - " << abs(derive(arr[i], i)) << "x^" << i;
                }
            }
    }
}
// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
