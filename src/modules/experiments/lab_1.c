#include <time.h>
#include <stdio.h>
#include <stdlib.h>

#include "../../headers/utils.h"
#include "../../headers/sortingAlgorithms.h"
#include "../../headers/experiments_headers/total.h"

// Lab. 1 - Insertion Sort
long double experiment_1(ssize_t length, size_t max_instances, const unsigned DEBUG_MODE) {
    clock_t t_tot = 0;

    for (size_t instance = 1; instance <= max_instances; ++instance) {
        int *array = gen_rnd_array(length);

        clock_t t_start, t_end;

        t_start = clock(); // starting processor time stopwatch
        InsertionSort(array, length); // sorting the array
        t_end = clock();

        t_tot += t_end - t_start;

        if (DEBUG_MODE) {
            //printf("%zu = %zu - %zu\n", t_end - t_start, t_end, t_start);
            //printf("%zu / %zu = %Lf\n", t_tot, max_instances, (long double) t_tot / (long double) max_instances);

            if (is_sorted(array, length))
                printf("Array sorted successfully (length: %ld)\n", length);
            else
                fprintf(stderr, "The array was not sorted correctly.\n"), print_array(array, length);
        }

        free(array); // deallocating the array
        array = NULL; // setting the pointer to NULL
    }

    return (long double) t_tot / (long double) max_instances;
}

void lab_1(char file[], Configuration conf, const bool DEBUG_MODE) {
    FILE *fp = fopen(file, "w+");
    if (fp == NULL) {
        fprintf(stderr, "Failed to open file `%s`\n", file);
        exit(EXIT_FAILURE);
    }

    fprintf(fp, "Dimension (n),Insertion Sort\n");
    for (ssize_t length = conf.min_length; length <= conf.max_length; length += conf.step) {
        srand(conf.seed);
        long double time_IS = experiment_1(length, conf.max_instances, DEBUG_MODE);

        fprintf(fp, "%ld,%Lf\n", length, time_IS); // write to file

        ++conf.seed;
    }

    if (fclose(fp) == EOF)
        fprintf(stderr, "Failed to flush buffered data on `%s`\n", file);
}
