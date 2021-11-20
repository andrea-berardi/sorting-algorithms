#include <stdbool.h>
#include <stdio.h>

#include "../headers/utils.h"

// Generate a new, uninitialized, array of integers, given its length
int *new_array(const size_t length) {
    int *array = malloc(length * sizeof(int));
    if (array == NULL) {
        fprintf(stderr, "Error: couldn't allocate %zu-cells array, size: %zu bytes).\n", length,
                length * sizeof(int));
        exit(EXIT_FAILURE);
    }

    return array;
}

// Generate a new random array, given its length
int *gen_rnd_array(const size_t length) {
    int *array = malloc(length * sizeof(int));
    if (array == NULL) {
        fprintf(stderr, "Error: couldn't allocate %zu-cells array, size: %zu bytes).\n", length,
                length * sizeof(int));
        exit(EXIT_FAILURE);
    }

    for (size_t index = 0; index < length; ++index)
        array[index] = rand() % (int) length; // random value between 0 and `length` (0 <= value < length)

    return array;
}

// Swap two integers of an array using pointers
void swap(int *a, int *b) {
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

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
