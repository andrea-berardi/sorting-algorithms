#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "headers/experiments.h"
#include "headers/utils.h"

const bool DEBUG_MODE = false;
const unsigned SEED = 10;

int main(int argc, char *argv[]) {
    /*
    if (argc != 2) {
        fprintf(stderr, "Not enough arguments. Usage: `./%s <file>`\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    FILE *fp = fopen(argv[1], "w+");
    if (fp == NULL) {
        fprintf(stderr, "Failed to open file `%s`\n", argv[1]);
        exit(EXIT_FAILURE);
    }
     */

    // Experiment n.1 - Insertion Sort
    lab_1("lab_1.txt", 0, 50000, 50, 1000, SEED, DEBUG_MODE);

    // Experiment n.2 - Merge Sort and Hybrid Sort
    lab_2A("lab_2A.txt", 0, 50000, 50, 1000, SEED, DEBUG_MODE);

    // Experiment n.3 - TODO

    // Experiment n.4 - TODO

    /*
    if (fclose(fp) == EOF)
        fprintf(stderr, "Failed to flush buffered data on `%s`\n", argv[1]);
    */

    return EXIT_SUCCESS;
}
