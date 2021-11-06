#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "sortingAlgorithms.h"
#include "experiments.h"
#include "utils.h"

// Experiment n.1 - Insertion Sort
double single_experiment(size_t length, size_t max_instances, const unsigned DEBUG_MODE) {
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

// Experiment n.1 - Insertion Sort
void lab_1(FILE *fp, size_t min_length, size_t max_length, size_t max_instances, size_t step, const unsigned DEBUG_MODE) {
    fprintf(fp, "Dimension: array length (n),Time (clock)\n");
    for (size_t length = min_length; length <= max_length; length += step)
        fprintf(fp, "%zu,%lf\n", length, single_experiment(length, max_instances, DEBUG_MODE));
}