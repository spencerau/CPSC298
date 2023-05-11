#include <iostream>

using namespace std;

void doSomethingRecursively(char currLetter) {
    if (currLetter == 'a') {
        cout << currLetter << endl;
    } else {
        cout << currLetter << " ";
        doSomethingRecursively(currLetter - 1);
    }
}

int main() {
    char cLetter = 'f';
    doSomethingRecursively(cLetter);

    return 0;
}