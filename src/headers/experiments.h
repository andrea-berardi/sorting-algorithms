// Header guards:
// patterns of preprocessor directives that protect a header from being included multiple times
#ifndef SORTING_ALGORITHMS_EXPERIMENTS_H
#define SORTING_ALGORITHMS_EXPERIMENTS_H

#include <stdbool.h>

// Configuration
typedef struct {
    ssize_t min_length;
    ssize_t max_length;
    size_t max_instances;
    ssize_t step;
    size_t threshold;
    unsigned int seed;
} Configuration;

// Final experiment (it runs all tests)
void lab_tot(char file[], Configuration, bool DEBUG_MODE);

#endif //SORTING_ALGORITHMS_EXPERIMENTS_H

// #pragma once
// an alternative to header guards
