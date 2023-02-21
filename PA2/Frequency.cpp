/*
* Frequency Program
* Finds the frequency and wavelength of six notes given an initial reference frequency
*
* @author: Spencer Au
*   Email: spau@chapman.edu
*   Student ID: 2385256
*   Date: 2/20/23
*   Class: CPSC 298
*   Assignment: PA2
*/



#include <iostream>
#include <string>
#include <cmath>

using namespace std;

class Frequency {
public:
    Frequency(double refFreq);
    void printFreq();

private:
    double troot = 1.059463094359;
    double refFreq;
    double findFreq(int v, int k);
    int nu[6] = {0, 0, 0, 4, 7, 8};
    int k[6] = {0, 1, 2, 0, 3, 0};
    string notes[6] = {"C0", "C#0", "D0", "C4", "D#7", "C8"};
    double c = 345;
};

Frequency::Frequency(double refFreq) {
    this->refFreq = refFreq;
}

double Frequency::findFreq(int v, int k) {
    return refFreq * pow(2, v) * pow(troot, k);
}

void Frequency::printFreq() {
    cout << "Reference Frequency: " << refFreq << " Hz" << endl;
    cout << "Speed of Sound: " << c << " m/s" << endl;
    for (int i = 0; i < 6; i++) {
        //temp = findFreq(nu[i], k[i]);
        cout << "Note: " << notes[i] << "; nu: " << nu[i] << "; k: " << k[i] << "; frequency: " << findFreq(nu[i], k[i])
            << " Hz; wavelength: " << (c*100)/findFreq(nu[i], k[i]) << " cm" << endl;
    }
}

int main() {
    Frequency *f = new Frequency(16.35);
    f->printFreq();
}