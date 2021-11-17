#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "headers/experiments.h"
#include "headers/utils.h"

const bool DEBUG_MODE = false;
const size_t THRESHOLD = 199;
const unsigned SEED = 10;

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Not enough arguments. Usage: `./%s <file>`\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    FILE *fp = fopen(argv[1], "w+");
    if (fp == NULL) {
        fprintf(stderr, "Failed to open file `%s`\n", argv[1]);
        exit(EXIT_FAILURE);
    }

    /* Experiment n.1 - Insertion Sort
    lab_1("../results/lab_1.csv", 0, 50000, 50, 1000, SEED, DEBUG_MODE);
    // Experiment n.2A - Merge Sort
    lab_2A("../results/lab_2A.csv", 1, 50000, 50, 1000, SEED, DEBUG_MODE);
    // Experiment n.2B - Find T (threshold) for Merge Sort and Insertion Sort
    lab_1("../results/lab_2B-1.csv", 1, 5000, 100, 1, SEED, DEBUG_MODE); // finding the threshold
    lab_2A("../results/lab_2B-2.csv", 1, 5000, 100, 1, SEED, DEBUG_MODE); // finding the threshold
    lab_2B("../results/lab_2B.csv", 1, 50000, 50, 1000, THRESHOLD, SEED, DEBUG_MODE);*/
    // Experiment n.2 - Insertion Sort, Merge Sort, Hybrid Sort
    //lab_2("../results/lab_2.csv", 1, 50000, 50, 1000, THRESHOLD, SEED, DEBUG_MODE);
    // Experiment n.3 - Median of Three Quick Sort
    //lab_3("../results/lab_3.csv", 0, 50000, 100, 1000, THRESHOLD, SEED, DEBUG_MODE);

    // Experiment n.4 - Real World Sorting Algorithm(s)
    lab_4("../results/lab_4D.csv", 0, 10000, 100, 50, THRESHOLD, SEED, DEBUG_MODE);

    if (fclose(fp) == EOF)
        fprintf(stderr, "Failed to flush buffered data on `%s`\n", argv[1]);

    return EXIT_SUCCESS;
}
