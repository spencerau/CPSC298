// SomePointers.cpp Project
// Code is incomplete but will run
//

#include <iostream>

int main()
{
    const int ARRAY_SIZE = 10;
    const int LAST_ARRAY_ELEM_INDEX = 9;
   
    char* p_aChars = new char[ARRAY_SIZE];
    int* p_aIntegers = new int[ARRAY_SIZE];

    std::cout << "Pointer Project\n";

    // TODO: Comment out the code that initializes the character and 
    //       integer arrays using #if 0 ... #endif
    //       Here is an example of using #if 0 to comment out code:
#if 0
    BAD_CODE - BUT - IT - IS - COMMENTED - OUT THANKS TO if 0
#endif

#if 0 // TODO: Change the 1 to a 0 to comment out
    // Initialize character array
    p_aChars[0] = 'A';
    p_aChars[1] = 'B';
    p_aChars[2] = 'C';
    p_aChars[3] = 'C';
    p_aChars[4] = 'E';
    p_aChars[5] = 'F';
    p_aChars[6] = 'G';
    p_aChars[7] = 'G';
    p_aChars[8] = 'I';
    p_aChars[9] = 'J';
    
    // Initialize character array
    p_aIntegers[0] = 100;
    p_aIntegers[1] = 101;
    p_aIntegers[2] = 102;
    p_aIntegers[3] = 103;
    p_aIntegers[4] = 104;
    p_aIntegers[5] = 105;
    p_aIntegers[6] = 106;
    p_aIntegers[7] = 107;
    p_aIntegers[8] = 108;
    p_aIntegers[9] = 109;

#endif


    // ////////////////////////////////////////////////////////////////////////////
    // Character Pointer Code
    // ////////////////////////////////////////////////////////////////////////////

    char* p_c = p_aChars;  // Same as p_c = &(p_aChars[0]);

    // TODO: Write a while loop that initializes the values of the array pointed to by p_aChars
    //       Use pointer p_c. In the loop use *p_c = value
    //       You may need to introduce additional variables such as char c = 'A' 

    // INSERT YOUR WHILE LOOP HERE
    char c = 'A';
    while (p_c <= &(p_aChars[LAST_ARRAY_ELEM_INDEX])) {
        *p_c = c++;
        p_c++;  // Increment the pointer (to point to next array element)
    }

    // Display Character Array
    std::cout << "Char Array" << std::endl;
    std::cout << "Address of last element &(p_aChars[LAST_ARRAY_ELEM_INDEX]): " << static_cast<void*>(&(p_aChars[LAST_ARRAY_ELEM_INDEX])) << std::endl;

    p_c = p_aChars;

    while (p_c <= &(p_aChars[LAST_ARRAY_ELEM_INDEX])) {

        std::cout << "p_c: " << static_cast<void*>(p_c) << ":  *p_c: " << *p_c << std::endl;

        p_c++;  // Increment the pointer (to point to next array element)
    }

    // ////////////////////////////////////////////////////////////////////////////
    // Integer Pointer Code
    // ////////////////////////////////////////////////////////////////////////////

    int* p_i = p_aIntegers;  // Same as p_i = &(p_aOrdinals[0]);

    // TODO: Write a while loop that initializes the values of the array pointed to by p_aIntegers
    //       Use pointer p_i.In the loop use *p_i = value where value is 'A', 'B', etc.
    //       You may need to introduce additional variables such as int i = 100. 

    // INSERT YOUR WHILE LOOP HERE
    int i = 100;
    while (p_i <= &(p_aIntegers[LAST_ARRAY_ELEM_INDEX])) {
        *p_i = i++;
        p_i++;  // Increment the pointer (to point to next array element)
    }

    // Display Integer Array

    std::cout << "Integer Array" << std::endl;
    std::cout << "Address of last element: &(p_aIntegers[LAST_ARRAY_ELEM_INDEX]): " << &(p_aIntegers[LAST_ARRAY_ELEM_INDEX]) << std::endl;

    p_i = p_aIntegers;

    while (p_i <= &(p_aIntegers[LAST_ARRAY_ELEM_INDEX])) {

        std::cout << "p_i: " << p_i << ":  *p_i: " << *p_i << std::endl;

        p_i++;  // Increment the pointer (to point to next array element)
    }


    return 0;
   
}

