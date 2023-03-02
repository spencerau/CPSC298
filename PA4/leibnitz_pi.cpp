/**
 * @author Spencer Au
 * ID: 2385256
 * spau@chapman.edu
 * CPSC 298 - Section 1
 * PA4
 * 
 * Calculates the value of pi using the Leibnitz Formula
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

    for (int i = 0; i <= n; i++) {
        piOver4 += (pow(-1.0, i))/(2*i+1);
    }

    piOver4 *= 4;
    /*
    printf("n = %d\n", n);
    printf("Pi (Approx): %15f\n", piOver4);
    printf("Pi (Actual): %15f\n", M_PI);
    */
    cout << fixed;
    cout << setprecision(DBL_DIG);
    cout << "PI (approx): " << piOver4 << "; n: " << setw(7) << n << endl; 
    cout << "PI (actual): " << "3.141592653589793" << endl;
    cout << "Decimal digits of precision: " << DBL_DIG << endl;
    cout << "Number of base 2 mantissa digits of double precision floating point value: " << DBL_MANT_DIG << endl;
    cout << "Next representable number from 3.141592653589793: " << nextafter(3.141592653589793, 3.14) << endl;

}