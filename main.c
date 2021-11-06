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

    srand(SEED); // fixed seed in order to get reproducible results

    // Experiment n.1 - Insertion Sort
    lab_1(fp, 0, 50000, 10, 1000, DEBUG_MODE);

    if (fclose(fp) == EOF)
        fprintf(stderr, "Failed to flush buffered data on `%s`\n", argv[1]);

    int A[] = {1, 3, 2, 0, 5, 6, 9, 11, 113, 112, 66, 77, 2, 11, 11, 11, 11, 8, 7, 54, 45};
    print_array(A, 21);
    is_sorted(A, 21) ? printf("sorted\n") : printf("not sorted\n");
    MergeSort(A, 0, 21 - 1);
    print_array(A, 21);
    is_sorted(A, 21) ? printf("sorted\n") : printf("not sorted\n");

    return EXIT_SUCCESS;
}
