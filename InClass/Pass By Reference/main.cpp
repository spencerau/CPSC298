#include <iostream>

using namespace std;

void incrementValue(int n)
{
        cout << "n: " << ++n << "; Line: " << __LINE__ << endl;
}

int main()
{
    int val = 2;
    std::cout << "val: " << val << "; Line: " << __LINE__ << std::endl;
    incrementValue(val);
    std::cout << "val: " << val << "; Line: " << __LINE__ << std::endl;
    return 0;
}
