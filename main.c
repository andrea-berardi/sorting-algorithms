#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

#include "sortingAlgorithms.h"
#include "experiments.h"
#include "utils.h"

const bool DEBUG_MODE = false;
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

    // Experiment n.1 - Insertion Sort
    srand(SEED); // Reset seed - a fixed seed ensures reproducible results
    lab_1(fp, 0, 50000, 10, 1000, DEBUG_MODE);

    // Experiment n.2 - Merge Sort and Hybrid Sort
    srand(SEED); // Reset seed - a fixed seed ensures reproducible results

    // Experiment n.3 - TODO
    srand(SEED); // Reset seed - a fixed seed ensures reproducible results

    // Experiment n.4 - TODO
    srand(SEED); // Reset seed - a fixed seed ensures reproducible results

    if (fclose(fp) == EOF)
        fprintf(stderr, "Failed to flush buffered data on `%s`\n", argv[1]);

    return EXIT_SUCCESS;
}
