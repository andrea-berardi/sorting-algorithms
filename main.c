#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "sortingAlgorithms.h"
#include "utils.h"

const bool DEBUG_MODE = false;
const unsigned SEED = 10;

double single_experiment(size_t length, size_t max_instances) {
    clock_t t_tot = 0;

    for (size_t instance = 1; instance <= max_instances; ++instance) {
        int *array = malloc(length * sizeof(int));
        if (array == NULL) {
            fprintf(stderr, "Error: couldn't allocate %zu-cells array, size: %zu bytes).\n", length,
                    length * sizeof(int));
            exit(EXIT_FAILURE);
        }

        for (size_t index = 0; index < length; ++index)
            array[index] = rand() % (int) length; // random value between 0 and `length` (0 <= value < length)

        clock_t t_start, t_end;

        t_start = clock(); // starting processor time stopwatch
        InsertionSort(array, length); // sorting the array
        t_end = clock();

        t_tot += t_end - t_start;

        if (DEBUG_MODE) {
            if (is_sorted(array, length))
                printf("Array sorted successfully\n");
            else
                fprintf(stderr, "The array was not sorted correctly.\n");
        }

        free(array); // deallocating the array
        array = NULL; // setting the pointer to NULL
    }

    return t_tot / (double) max_instances;
}

void experiment(FILE *fp, size_t min_length, size_t max_length, size_t max_instances, size_t step) {
    fprintf(fp, "Dimension: array length (n),Time (clock)\n");
    for (size_t length = min_length; length <= max_length; length += step)
        fprintf(fp, "%zu,%lf\n", length, single_experiment(length, max_instances));
}

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

    experiment(fp, 0, 50000, 1, 1000);

    if (fclose(fp) == EOF)
        fprintf(stderr, "Failed to flush buffered data on `%s`\n", argv[1]);

    int A[] = {1, 3, 2, 0, 5};
    print_array(A, 5);
    is_sorted(A, 5) ? printf("sorted\n") : printf("not sorted\n");
    MergeSort(A, 1, 4);
    print_array(A, 5);
    is_sorted(A, 5) ? printf("sorted\n") : printf("not sorted\n");

    return EXIT_SUCCESS;
}
