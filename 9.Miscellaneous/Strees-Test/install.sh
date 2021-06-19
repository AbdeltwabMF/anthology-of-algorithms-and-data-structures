#!/bin/bash


# Usage
# stress_test brute_force optimized
# pass the two solution as args

g++ -Wall -Wextra -Wshadow -Og -g -Ofast -std=c++17 -D_GLIBCXX_ASSERTIONS -DDEBUG -ggdb3 -fsanitize=address,undefined -fmax-errors=2 -o stress_test stress_test.cpp
sudo cp stress_test /usr/bin

