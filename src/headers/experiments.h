// Header guards:
// patterns of preprocessor directives that protect a header from being included multiple times
#ifndef SORTING_ALGORITHMS_EXPERIMENTS_H
#define SORTING_ALGORITHMS_EXPERIMENTS_H

#include <stdlib.h>
#include <stdbool.h>

// Configuration
typedef struct {
    ssize_t min_length;
    ssize_t max_length;
    size_t max_instances;
    ssize_t step;
    ssize_t threshold;
    unsigned int seed;
} Configuration;

// Lab. 1 - Insertion Sort
void lab_1(char file[], Configuration conf, bool DEBUG_MODE);

// Lab. 2A - Insertion Sort, Merge Sort
void lab_2A(char file[], Configuration conf, bool DEBUG_MODE);

// Lab. 2B - Insertion Sort, Merge Sort, Hybrid Sort
void lab_2B(char file[], Configuration conf, bool DEBUG_MODE);

// Lab. 3 - Quick Sort, Median of Three Quick Sort
void lab_3(char file[], Configuration conf, bool DEBUG_MODE);

// Lab. 4 - Tail Recursive Quick Sort, Median of Three Tail Quick Sort, Real World Sort
void lab_4(char file[], Configuration conf, bool DEBUG_MODE);

// Final experiment (it runs all tests)
void lab_tot(char file[], Configuration, bool DEBUG_MODE);

#endif //SORTING_ALGORITHMS_EXPERIMENTS_H

// #pragma once
// an alternative to header guards
