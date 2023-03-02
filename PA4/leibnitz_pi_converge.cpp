/**
 * @author Spencer Au
 * ID: 2385256
 * spau@chapman.edu
 * CPSC 298 - Section 1
 * PA4
 * 
 * Calculates the value of pi using the Leibnitz Formula
 * It uses an initial value 2 as the upper bound, and doubles it until it reaches 2^20,
 * approaching closer to the actual value of pi as n increases
 **/

#include <iostream>
#include <string>
#include <stdlib.h>
#include <cmath>
#include <cfloat>
#include <iomanip>

using namespace std;

const int n = 1048576;

int main() {
    double piOver4 = 0;
    cout << fixed;
    cout << setprecision(DBL_DIG);

    for (int i = 2; i <= n; i *= 2) {
        piOver4 = 0;
        for (int j = 0; j <= i; j++) {
            piOver4 += (pow(-1.0, j))/(2*j+1);
        }
        piOver4 *= 4;
        cout << "PI: " << piOver4 << "; n: " << i << endl; 
    }
}