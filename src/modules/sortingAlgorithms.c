#include <stdio.h>
#include <stdlib.h>

#include "../headers/utils.h"
#include "../headers/sortingAlgorithms.h"

// Insertion Sort
void InsertionSort(int array[], size_t length) {
    for (size_t j = 1; j < length; ++j) {
        int key = array[j];
        size_t i = j - 1;

        while (i >= 0 && array[i] > key) {
            array[i + 1] = array[i];
            --i;
        }

        array[i + 1] = key;
    }
}

// Merge procedure
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

// Merge Sort (usage: MergeSort(A, left, right - 1))
void MergeSort(int array[], size_t l, size_t r) {
    if (l < r) {
        size_t c = (l + r) / 2;

        MergeSort(array, l, c);
        MergeSort(array, c + 1, r);

        Merge(array, l, c, r);
    }
}

// Adapted Insertion Sort - FIXME
void AdaptedInsertionSort(int array[], size_t l, size_t r) {
    for (size_t j = l + 1; j < r; ++j) {
        int key = array[j];
        size_t i = j - 1;

        while (i >= l && array[i] > key) {
            array[i + 1] = array[i];
            --i;
        }

        array[i + 1] = key;
    }
}

// Hybrid Sort (usage: HybridSort(A, left, right - 1, threshold))
void HybridSort(int array[], size_t l, size_t r, const size_t THRESHOLD) {
    if (r - l > THRESHOLD) {
        size_t c = (l + r) / 2;

        HybridSort(array, l, c, THRESHOLD);
        HybridSort(array, c + 1, r, THRESHOLD);

        Merge(array, l, c, r);
    } else {
        AdaptedInsertionSort(array, l, r + 1); // `r+1` because HybridSort&MergeSort are instantiated with `length-1`
    }
}

// Partition
ssize_t Partition(int array[], ssize_t l, ssize_t r) {
    int x = array[r];
    ssize_t i = l - 1;

    for (ssize_t j = l; j < r; ++j) {
        if (array[j] <= x) {
            ++i;
            swap(&array[i], &array[j]);
        }
    }

    swap(&array[i + 1], &array[r]);

    return i + 1;
}

// Quick Sort (usage: QuickSort(A, left, right - 1))
void QuickSort(int array[], ssize_t l, ssize_t r) {
    if (l < r) {
        ssize_t q = Partition(array, l, r);

        QuickSort(array, l, q - 1);
        QuickSort(array, q + 1, r);
    }
}

// Median of Three: Hardcoded procedure to find the median of three array values
ssize_t MedianOfThree(const int array[], ssize_t i, ssize_t j, ssize_t k) {
    // ^ is the bitwise XOR operator
    if ((array[i] > array[j]) ^ (array[i] > array[k])) {
        return i;
    } else if ((array[j] < i) ^ (array[j] < array[k])) {
        return j;
    } else {
        return k;
    }
}

// Median of Three Partition
ssize_t MedianOfThreePartition(int array[], ssize_t l, ssize_t r) {
    ssize_t s = MedianOfThree(array, l, r, (l + r) / 2);
    swap(&array[s], &array[r]);

    int x = array[r];
    ssize_t i = l - 1;

    for (ssize_t j = l; j < r; ++j) {
        if (array[j] <= x) {
            ++i;
            swap(&array[i], &array[j]);
        }
    }

    swap(&array[i + 1], &array[r]);

    return i + 1;
}

// Median of Three Quick Sort (usage MedianOfThreeQuickSort(array, left, right - 1))
void MedianOfThreeQuickSort(int array[], ssize_t l, ssize_t r) {
    if (l < r) {
        ssize_t q = MedianOfThreePartition(array, l, r);

        MedianOfThreeQuickSort(array, l, q - 1);
        MedianOfThreeQuickSort(array, q + 1, r);
    }
}
