// Header guards:
// patterns of preprocessor directives that protect a header from being included multiple times
#ifndef SORTING_ALGORITHMS_SORTINGALGORITHMS_H
#define SORTING_ALGORITHMS_SORTINGALGORITHMS_H

void InsertionSort(int array[], size_t length);

void MergeSort(int array[], size_t l, size_t r);

void HybridSort(int array[], size_t l, size_t r, size_t THRESHOLD);

#endif //SORTING_ALGORITHMS_SORTINGALGORITHMS_H

// #pragma once
// an alternative to header guards
