#include <iostream>
#include <stdexcept>
#include <stdio.h>
#include <string>

using namespace std;


/*
 For this Final Examination programming project, you'll write a function called sigma that accepts n, 
 an unsigned integer, as a parameter and computes the sum of the numbers from 1 to n. 
 n/2 * (n+1) is the formula for the sum of the numbers from 1 to n.
 */
unsigned long sigma(unsigned long n) {
    unsigned long sum = 0;
    string preCondition = "Error: n must be greater than 0; invalid arg for value n: " + to_string(n) 
    + " (Loc: " + __FILE__ + ", " + to_string(__LINE__) + ")";
    string postCondition = "Error: prereconditon of sum == n/2 * (n+1) is not met; sum: " + to_string(sum) 
    + ", n/2 * (n+1): " + to_string((n*(n+1))/2) + " (Loc: " + __FILE__ + ", " + to_string(__LINE__) + ")";
    try {
        if (n < 1) {
            throw std::runtime_error(preCondition);
        }
        // use a forloop to add up all the numbers from 1 to n
        for (int i = 1; i <= n; i++) {
            sum += i;
        }
        if (sum != (n*(n+1))/2) {
            throw runtime_error(postCondition);
        }
        //sum = n/2 * (n+1);
    } catch (runtime_error ex) {
        cout << "Exception: " << ex.what() << endl;
        cout << "Cannot compute sum; returning 0" << endl;
        sum = 0;
    }
    return sum;
}

int main() {
    int sum = sigma(5);
    printf("Sigma of 5 is %d\n", sum);
    sum = sigma(0);
    printf("Sigma of 0 is %d\n", sum);
    
    return 0;
}