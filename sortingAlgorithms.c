#include <stdio.h>
#include <stdlib.h>

#include "utils.h"
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
void Merge(int array[], size_t l, size_t c, size_t r) {
    size_t n1 = c - l + 1;
    size_t n2 = r - c;

    int *left = malloc(n1 * sizeof(int));
    if (left == NULL) {
        fprintf(stderr, "Error: couldn't allocate %zu-cells array, size: %zu bytes).\n", n1,
                n1 * sizeof(int));
        exit(EXIT_FAILURE);
    }

    int *right = malloc(n2 * sizeof(int));
    if (right == NULL) {
        fprintf(stderr, "Error: couldn't allocate %zu-cells array, size: %zu bytes).\n", n2,
                n2 * sizeof(int));
        exit(EXIT_FAILURE);
    }

    for (size_t i = 0; i < n1; ++i) left[i] = array[l + i];
    for (size_t j = 0; j < n2; ++j) right[j] = array[(c + 1) + j];

    size_t i = 0;
    size_t j = 0;
    for (size_t k = l; k <= r; ++k) {
        if (i < n1) {
            if (j < n2) {
                if (left[i] < right[j]) {
                    array[k] = left[i];
                    ++i;
                } else {
                    array[k] = right[j];
                    ++j;
                }
            } else {
                array[k] = left[i];
                ++i;
            }
        } else {
            array[k] = right[j];
            ++j;
        }
    }

    free(left);
    left = NULL;
    free(right);
    right = NULL;
}

// Merge sort
void MergeSort(int array[], size_t l, size_t r) {
    if (l < r) {
        size_t c = (l + r) / 2;

        MergeSort(array, l, c);
        MergeSort(array, c + 1, r);

        Merge(array, l, c, r);
    }
}
