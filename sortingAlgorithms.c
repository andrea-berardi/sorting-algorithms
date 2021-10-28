#include <stdlib.h>

#include "sortingAlgorithms.h"

// Insertion sort
void insertionSort(int *array, size_t length) {
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