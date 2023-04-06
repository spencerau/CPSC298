#include <iostream>


using namespace std;


int main() {
    char *ptr_array = new char[2];
    //ptr_array[0] = 'A';
    //ptr_array[1] = '#';

    *(ptr_array + 0) = 'A';
    *(ptr_array + 1) = '#';

    for (int i = 0; i < 2; i++) {
        cout << ptr_array[i] << endl;
    }
}