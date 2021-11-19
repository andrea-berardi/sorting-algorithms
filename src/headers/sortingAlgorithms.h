// Header guards:
// patterns of preprocessor directives that protect a header from being included multiple times
#ifndef SORTING_ALGORITHMS_SORTINGALGORITHMS_H
#define SORTING_ALGORITHMS_SORTINGALGORITHMS_H

// Enumeration of the available algorithms
typedef enum algorithm {
    IS, // Insertion Sort
    MS, // Merge Sort
    HS, // Hybrid Sort (Merge Sort + Adapted Insertion Sort)
    QS, // Quick Sort
    MTQS, // Median of Three Quick Sort
    TQS, // Tail Recursive Quick Sort
    HPS, // Heap Sort
    MTTQS, // Median of Three Tail Quick Sort
    RWS, // Real World Sort (Heap Sort, Tail Recursive Quick Sort, Median of Three Quick Sort)
} Algorithm;

// IS - Insertion Sort
void InsertionSort(int array[], size_t length);

// MS - Merge Sort
void MergeSort(int array[], size_t l, size_t r);

// HS - Hybrid Sort
void HybridSort(int array[], ssize_t l, ssize_t r, size_t THRESHOLD);

// QS - Quick Sort
void QuickSort(int array[], ssize_t l, ssize_t r);

// MTQS - Median of Three Quick Sort
void MedianOfThreeQuickSort(int array[], ssize_t l, ssize_t r);

// TQS - Tail Recursive Quick Sort
void TailQuickSort(int array[], ssize_t l, ssize_t r);

// HPS - Heap Sort
void HeapSort(int array[], ssize_t length);

// MTTQS - Median of Three Tail Quick Sort
void MedianOfThreeTailQuickSort(int array[], ssize_t l, ssize_t r);

// RWS - Real World Sort
void RealWorldSort(int array[], ssize_t length, size_t THRESHOLD);

#endif //SORTING_ALGORITHMS_SORTINGALGORITHMS_H

// #pragma once
// an alternative to header guards
