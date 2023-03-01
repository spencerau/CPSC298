/*
* Authenticator Program
* Prompts for 3 char values
* Checks if it matches a hardcoded code of ECA
* Checks individual chars, total string, and also checksum of ASCII values
*
* @author: Spencer Au
*   Email: spau@chapman.edu
*   Student ID: 2385256
*   Date: 2/20/23
*   Class: CPSC 298
*   Assignment: PA3
*/

#include <stdlib.h>
#include <stdio.h>
#include <string>
#include <iostream>

using namespace std;

class authenticator {
public:
    authenticator();
    void compareChar();
    void compareString();
    void promptUser();
    void checksum();
    void characterize();
private:
    const char authChar1 = 'E';
    const char authChar2 = 'C';
    const char authChar3 = 'A';
    const int validChecksum = 5;
    string auth = "ECA";

    char inChar1;
    char inChar2;
    char inChar3;
    string input;
};

authenticator::authenticator() {

}

int main() {
    authenticator *auth = new authenticator();
    auth->promptUser();
    auth->compareChar();
    auth->compareString();
    auth->characterize();

}

void authenticator::characterize() {
    cout << "Characterization of Message Code" << endl;
    cout << "-----------------------------------" << endl;
    int ascii1 = int(inChar1);
    int ascii2 = int(inChar2);
    int ascii3 = int(inChar3);
    cout << "ASCII Values of Message Characters: " << ascii1 << ", " << ascii2 << ", " << ascii3 << endl;
    cout << "Sum of ASCII Values: " << ascii1 + ascii2 + ascii3 << endl;
    if (authChar1 != inChar1) {
        cout << "First Characters do not match: Message: " << inChar1 << "; Authenticator: " << authChar1 << endl;
    }
    if (authChar2 != inChar2) {
        cout << "Second Characters do not match: Message: " << inChar2 << "; Authenticator: " << authChar2 << endl;
    }
    if (authChar3 != inChar3) {
        cout << "Third Characters do not match: Message: " << inChar3 << "; Authenticator: " << authChar3 << endl;
    }
    checksum();
}

void authenticator::checksum() {
    int checksum = (int(inChar1) + int(inChar2) + int(inChar3)) % 7;
    if (checksum == validChecksum) {
        cout << "Message Code Checksum is Valid: " << validChecksum << endl;
    }
    else {
        cout << "Message Code Checksum is Invalid: " << checksum << "; ";
        cout << "Expected: " << validChecksum << endl;
    }
    if (input != auth) {
        cout << "Message Code (" << input << ") is lexographically ";
        if (checksum < validChecksum) {
            cout << "greater ";
        } else {
            cout << "less ";
        }
        cout << "than Auth Code (" << authChar1 << authChar2 << authChar3 << ")" << endl;
    }
}

void authenticator::compareChar() {
    if (authChar1 == inChar1 && authChar2 == inChar2 && authChar3 == inChar3) {
        cout << "Message is authentic." << endl;
    }
    else cout << "Message is invalid." << endl;
    cout << endl;
}

void authenticator::compareString() {
    string code;
    code += authChar1;
    code += authChar2;
    code += authChar3;
    if (code == input) {
        cout << "Concurrence: Message is authentic." << endl;
    }
    else cout << "Concurrence: Message is invalid." << endl;
    cout << endl;
}

void authenticator::promptUser() {
    cout << "Enter the first character of the code" << endl;
    cin >> inChar1;
    input += inChar1;
    cout << "Enter the second character of the code" << endl;
    cin >> inChar2;
    input += inChar2;
    cout << "Enter the third character of the code" << endl;
    cin >> inChar3;
    input += inChar3;
    cout << "Authenticator Code: " << authChar1 << authChar2 << authChar3 << endl;
    cout << "Message Code: " << input << endl;
    cout << endl;
}