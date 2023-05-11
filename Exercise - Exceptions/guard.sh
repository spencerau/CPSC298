#!/bin/bash

clear

# compile all .cpp files
g++ -std=c++11 -Wall -Wextra -Wpedantic *.cpp -o guard

# run the compiled executable
./guard

# remove the compiled executable
rm guard