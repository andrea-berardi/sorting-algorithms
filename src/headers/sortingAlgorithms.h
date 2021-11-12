// Header guards:
// patterns of preprocessor directives that protect a header from being included multiple times
#ifndef SORTING_ALGORITHMS_SORTINGALGORITHMS_H
#define SORTING_ALGORITHMS_SORTINGALGORITHMS_H

// Enumeration of the available algorithms
enum algorithm {
    IS, // Insertion Sort
    MS, // Merge Sort
    HS, // Hybrid Sort (Merge Sort + Adapted Insertion Sort)
    QS, // Quick Sort
    MTQS, // Median of Three Quick Sort
    TQS, // Tail Recursive Quick Sort
    HPS, // Heap Sort
    RWS, // Real World Sort (Heap Sort, Tail Recursive Quick Sort, Median of Three Quick Sort)
};

void InsertionSort(int array[], size_t length);

void MergeSort(int array[], size_t l, size_t r);

void HybridSort(int array[], size_t l, size_t r, size_t THRESHOLD);

void QuickSort(int array[], ssize_t l, ssize_t r);

void MedianOfThreeQuickSort(int array[], ssize_t l, ssize_t r);

void TailQuickSort(int array[], ssize_t l, ssize_t r);

#endif //SORTING_ALGORITHMS_SORTINGALGORITHMS_H

// #pragma once
// an alternative to header guards
