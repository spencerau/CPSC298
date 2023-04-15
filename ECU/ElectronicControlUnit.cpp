#include <iostream>
#include <string>
#include <stdlib.h>

using namespace std;

class ElectronicControlUnit 
{
public:
    ElectronicControlUnit();
    ~ElectronicControlUnit();
    void handleCommand(char cComannnd);

private:
    // Button A
    bool m_bActivateHydraulicJacks;
    void actuateHydraulicJacks();
    // Button B
    bool m_bActivateBeltTires;
    void actuateBeltTires();
    // Button E
    bool m_bActivateIRIllumination;
    void actuateIRIllumination();
};

ElectronicControlUnit::ElectronicControlUnit() {
    m_bActivateHydraulicJacks = false;
    m_bActivateBeltTires = false;
    m_bActivateIRIllumination = false;
}

ElectronicControlUnit::~ElectronicControlUnit() {
    printf("Destructor called\n");
}

int main() {
    ElectronicControlUnit ecu;
    char cCommand;

    printf("Press X to turn off ignition or enter a steering wheel button (A, B, E)\n");
    while (true) {
        cout << "(A) (B) (C) (D) (E) (F) (G)" << endl;
        cin >> cCommand;
        ecu.handleCommand(cCommand);
    }

    return 0;
}

void ElectronicControlUnit::handleCommand(char cCommand) {
    switch (cCommand) {
        case 'a':
        case 'A':
            actuateHydraulicJacks();
            break;
        case 'b':
        case 'B':
            actuateBeltTires();
            break;
        case 'e':
        case 'E':
            actuateIRIllumination();
            break;
        case 'x':
        case 'X':
            cout << "Ignition turned off" << endl;
            exit(0);
            break;
        default:
            cout << "Invalid command" << endl;
            break;
    }
}

void ElectronicControlUnit::actuateHydraulicJacks() {
    if (m_bActivateHydraulicJacks) {
        m_bActivateHydraulicJacks = false;
        cout << "Hydraulic jacks deactivated" << endl;
    } else {
        m_bActivateHydraulicJacks = true;
        cout << "Hydraulic jacks activated" << endl;
        // Activating the Auto-Jack automatically deactivates the Special Grip (or "Belt") Tire
        // feature.
        if (m_bActivateBeltTires) {
            m_bActivateBeltTires = false;
            cout << "Belt tires deactivated due to Hydraulic Jacks" << endl;
        }
    }
}

void ElectronicControlUnit::actuateBeltTires() {
    if (m_bActivateBeltTires) {
        m_bActivateBeltTires = false;
        cout << "Belt tires deactivated" << endl;
    } else {
        m_bActivateBeltTires = true;
        cout << "Belt tires activated" << endl;
    }
}

void ElectronicControlUnit::actuateIRIllumination() {
    if (m_bActivateIRIllumination) {
        m_bActivateIRIllumination = false;
        cout << "IR illumination deactivated" << endl;
    } else {
        m_bActivateIRIllumination = true;
        cout << "IR illumination activated" << endl;
    }
}