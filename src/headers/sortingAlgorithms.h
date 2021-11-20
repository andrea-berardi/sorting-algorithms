// Header guards:
// patterns of preprocessor directives that protect a header from being included multiple times
#ifndef SORTING_ALGORITHMS_SORTINGALGORITHMS_H
#define SORTING_ALGORITHMS_SORTINGALGORITHMS_H

// Enumeration of the available algorithms
typedef enum algorithms {
    IS = 0, // Insertion Sort (0)
    MS = 1, // Merge Sort (1)
    HS = 2, // Hybrid Sort (Merge Sort + Adapted Insertion Sort) (2)
    QS = 3, // Quick Sort (3)
    MTQS = 4, // Median of Three Quick Sort (4)
    TQS = 5, // Tail Recursive Quick Sort (5)
    HPS = 6, // Heap Sort (6)
    MTTQS = 7, // Median of Three Tail Quick Sort (7)
    RWS = 8, // Real World Sort (Heap Sort, Tail Recursive Quick Sort, Median of Three Quick Sort) (8)
} Algorithm;

// IS - Insertion Sort
void InsertionSort(int array[], ssize_t length);

// MS - Merge Sort
void MergeSort(int array[], ssize_t l, ssize_t r);

// HS - Hybrid Sort
void HybridSort(int array[], ssize_t l, ssize_t r, ssize_t THRESHOLD);

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
void RealWorldSort(int array[], ssize_t length, ssize_t THRESHOLD);

#endif //SORTING_ALGORITHMS_SORTINGALGORITHMS_H

// #pragma once
// an alternative to header guards
