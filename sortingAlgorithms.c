#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#include "sortingAlgorithms.h"

// Insertion sort
void InsertionSort(int array[], size_t length) {
    size_t i;
    int key;

    for (size_t j = 1; j < length; ++j) {
        key = array[j];
        i = j - 1;

        while (i >= 0 && array[i] > key) {
            array[i + 1] = array[i];
            --i;
        }

        array[i + 1] = key;
    }
}

// Merge
void Merge(int array[], size_t p, size_t q, size_t r) {
    size_t n1 = q - p + 1;
    size_t n2 = r - q;

    int *left = malloc((n1 + 1) * sizeof(int));
    if (left == NULL) {
        fprintf(stderr, "Error: couldn't allocate %zu-cells array, size: %zu bytes).\n", n1 + 1,
                (n1 + 1) * sizeof(int));
        exit(EXIT_FAILURE);
    }

    int *right = malloc((n2 + 1) * sizeof(int));
    if (right == NULL) {
        fprintf(stderr, "Error: couldn't allocate %zu-cells array, size: %zu bytes).\n", n2 + 1,
                (n2 + 1) * sizeof(int));
        exit(EXIT_FAILURE);
    }

    for (size_t i = 0; i < n1; ++i) left[i] = array[p + i - 1];
    for (size_t j = 0; j < n2; ++j) right[j] = array[q + j];

    size_t i = 1;
    size_t j = 1;

    left[n1] = INT_MAX;
    right[n2] = INT_MAX;
    for (size_t k = p; k < r; ++k) {
        if (left[i] <= right[j]) {
            array[k] = left[i];
            ++i;
        } else {
            array[k] = right[j];
            ++j;
        }
    }
}

// Merge sort
void MergeSort(int array[], size_t p, size_t r) {
    if (p < r) {
        size_t q = (p + r) / 2;

        MergeSort(array, p, q);
        MergeSort(array, q + 1, r);

        Merge(array, p, q, r);
    }
}