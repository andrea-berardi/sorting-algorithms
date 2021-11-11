// Header guards:
// patterns of preprocessor directives that protect a header from being included multiple times
#ifndef SORTING_ALGORITHMS_EXPERIMENTS_H
#define SORTING_ALGORITHMS_EXPERIMENTS_H

// Experiment n.1 - Insertion Sort
void lab_1(char file[], size_t min_length, size_t max_length, size_t max_instances, size_t step, unsigned SEED,
           unsigned DEBUG_MODE);

// Experiment n.2A - Merge Sort
void lab_2A(char file[], size_t min_length, size_t max_length, size_t max_instances, size_t step, unsigned SEED,
            unsigned DEBUG_MODE);

// Experiment n.2B - Hybrid Sort
void lab_2B(char file[], size_t min_length, size_t max_length, size_t max_instances, size_t step, size_t THRESHOLD,
            unsigned SEED,
            unsigned DEBUG_MODE);

// Experiment n.2 - Insertion Sort, Merge Sort, Hybrid Sort
void lab_2(char file[], size_t min_length, size_t max_length, size_t max_instances, size_t step, size_t THRESHOLD,
           unsigned SEED,
           unsigned DEBUG_MODE);

// Experiment n.3 - (Insertion Sort, Merge Sort, Hybrid Sort) Quick Sort, Median of Three Quick Sort
void lab_3(char file[], ssize_t min_length, ssize_t max_length, size_t max_instances, ssize_t step, size_t THRESHOLD,
           unsigned SEED,
           unsigned DEBUG_MODE);

#endif //SORTING_ALGORITHMS_EXPERIMENTS_H

// #pragma once
// an alternative to header guards
