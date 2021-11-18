#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "headers/experiments.h"
#include "headers/utils.h"

const bool DEBUG_MODE = false; // this flag toggles debug checks (e.g. it checks if the algorithms sort correctly)
const size_t THRESHOLD = 199; // it used to be 340, but it varies... for some reasons ¯\_(ツ)_/¯
const unsigned int SEED = 10; // srand()'s starting seed

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Wrong number of arguments supplied.\n");
        fprintf(stderr, "Usage: `.%s <file>`.\n", argv[0]);
        fprintf(stdout, "Defaulting to `../results/results_total.csv`\n");
    }

    /* Configurations */
    ssize_t min_length = 0; // minimum length of the arrays
    ssize_t max_length = 1000; // maximum length of the arrays
    size_t max_instances = 1; // how many times to repeat the same test
    ssize_t step = 1; // the arrays will grow this much at each test

    /* Final Experiment (it runs all tests) */
    // Insertion Sort, Merge Sort, Hybrid Sort, Quick Sort, Median of Three Quick Sort,
    // Tail Recursive Quick Sort, Heap Sort, Median of Three Tail Quick Sort, Real World Sort
    lab_tot(argc != 2 ? "../results/results_total.csv" : argv[1], min_length, max_length, max_instances, step, THRESHOLD, SEED, DEBUG_MODE);

    return EXIT_SUCCESS;
}
