#include <stdio.h>
#include <stdlib.h>
#include <iostream>

using namespace std;


double calculateCivsInGalaxy(double fi, double L);
const double K = 0.0078;


int main() {
    cout << "Drake Equation\n";
    printf("fi: %d L: %e, N: %e\n", 1, 1e+09, calculateCivsInGalaxy(1, 1e+09));
    printf("fi: %e L: %d, N: %e\n", 1.0e-9, 304, calculateCivsInGalaxy(1.0e-9, 304));

}

double calculateCivsInGalaxy(double fi, double L) {
    return K * fi * L;
}
