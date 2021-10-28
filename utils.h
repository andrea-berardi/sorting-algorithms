#include <stdlib.h> // in order to get the `size_t` type
#include <stdbool.h> // imports the boolean type for more idiomatic code

// Header guards:
// patterns of preprocessor directives that protect a header from being included multiple times
#ifndef SORTING_ALGORITHMS_UTILS_H
#define SORTING_ALGORITHMS_UTILS_H

bool is_sorted(const int array[], size_t length); // Check if a given array is sorted (ascending order)

#endif //SORTING_ALGORITHMS_UTILS_H
