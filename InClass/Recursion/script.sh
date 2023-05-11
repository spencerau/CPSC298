#!/bin/bash

clear

# compile all .cpp files
g++ -std=c++11 -Wall -Wextra -Wpedantic *.cpp -o recursion

# run the compiled executable
./recursion

# remove the compiled executable
rm recursion