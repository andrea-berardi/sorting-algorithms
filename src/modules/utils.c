#include <stdbool.h>
#include <stdio.h>

#include "../../headers/utils.h"

// Check if a given array is sorted (ascending order)
bool is_sorted(const int array[], size_t length) {
    for (size_t i = 1; i < length; ++i)
        if (array[i - 1] > array[i])
            return false;

    return true;
}

// Prints to stdout a given array
void print_array(const int array[], size_t length) {
    for (size_t i = 0; i < length; ++i)
        printf("%s%d%s", i == 0 ? "[" : "", array[i], i < length - 1 ? ", " : "]\n");
}
