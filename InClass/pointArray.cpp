#include <iostream>
#include <stdlib.h>


using namespace std;

int main() {
    char **pp_c = new char * [3];
    for (int i = 0; i < 3; i++) {
        // allocate an array of 4 chars
        pp_c[i] = new char[4];
    }

    char c = 'A';
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 4; j++) {
            pp_c[i][j] = c++;
        }
    }

    //print the 2d array
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 4; j++) {
            cout << pp_c[i][j] << " ";
        }
        cout << endl;
    }

    //delete the 2d array
    for (int i = 0; i < 3; i++) {
        delete [] pp_c[i];
    }
    delete [] pp_c;
    pp_c = nullptr;

    return 0;
}
