#include <iostream>
#include <string>
#include <stdlib.h>
#include <stdio.h>

using namespace std;

class CUltimateMachine {

public:
  CUltimateMachine() : m_bState(false) {
    cout << "CUltimateMachine constructor (ctor) called" << endl;
  }
  ~CUltimateMachine() {
    cout << "CUltimateMachine destructor (dtor) called" << endl;
  }

  void displayState() {
    switch (m_bState) {
        case true:
            cout << "ON" << endl;
            break;
        case false:
            cout << "OFF" << endl;
            break;
    }
  }

  void turnOn() {
    m_bState = true;
    displayState();
    if (m_bState == true) {
        m_bState = false;
    }
    displayState();
  }

private:
    bool m_bState; // true (ON), false (Off)
  
};

int main() {
    CUltimateMachine um;
    um.displayState();
    um.turnOn();
    return 0;
}