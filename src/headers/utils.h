#include <stdlib.h> // in order to get the `size_t` type
#include <stdbool.h> // imports the boolean type for more idiomatic code

// Header guards:
// patterns of preprocessor directives that protect a header from being included multiple times
#ifndef SORTING_ALGORITHMS_UTILS_H
#define SORTING_ALGORITHMS_UTILS_H

// Generate a random array, given its length
int *gen_rnd_array(size_t length);

// Swap two integers of an array
void swap(int *a, int *b);

// Check if a given array is sorted (ascending order)
bool is_sorted(const int array[], size_t length);

// Prints to stdout a given array
void print_array(const int array[], size_t length);

#endif //SORTING_ALGORITHMS_UTILS_H

// #pragma once
// an alternative to header guards
