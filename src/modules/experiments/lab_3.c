#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "../../headers/utils.h"
#include "../../headers/experiments.h"
#include "../../headers/sortingAlgorithms.h"

// Lab. 3 - Quick Sort, Median of Three Quick Sort
long double experiment_3(ssize_t length, size_t max_instances, Algorithm algorithm, const unsigned DEBUG_MODE) {
    clock_t t_tot = 0;

    for (size_t instance = 1; instance <= max_instances; ++instance) {
        int *array = gen_rnd_array(length);

        // If length is 0 and the algorithm is NOT Insertion Sort, and so, just for the first run of the experiment,
        // we will raise it to 1, to avoid "double free" errors. Why? Because sorting algorithms are meant to be called
        // with "length - 1" and using 0 as a starting point would make the first MergeSort() or HybridSort() call
        // with length equals to - 1.
        // We don't need to restore length to the correct value because it's copied, not passed by reference.
        // The "real" value is unaffected.
        if (length == 0 && algorithm != IS) ++length;

        clock_t t_start, t_end;

        switch (algorithm) {
            case QS: {
                t_start = clock(); // starting processor time stopwatch
                QuickSort(array, 0, length - 1); // sorting the array
                t_end = clock();

                break;
            }

            case MTQS: {
                t_start = clock(); // starting processor time stopwatch
                MedianOfThreeQuickSort(array, 0, length - 1); // sorting the array
                t_end = clock();

                break;
            }

            default: {
                fprintf(stderr, "Unknown algorithm `%d`\n", algorithm);

                exit(EXIT_FAILURE);
            }
        }

        t_tot += t_end - t_start;

        if (DEBUG_MODE) {
            //printf("%zu = %zu - %zu\n", t_end - t_start, t_end, t_start);
            //printf("%zu / %zu = %Lf\n", t_tot, max_instances, (long double) t_tot / (long double) max_instances);

            // if length is 1, then we've just modified it for the first run, reset it to 0
            if (is_sorted(array, length == 1 ? --length : length))
                printf("Array sorted successfully (length: %ld)\n", length);
            else
                fprintf(stderr, "The array was not sorted correctly (%d).\n", algorithm), print_array(array, length);
        }

        free(array); // deallocating the array
        array = NULL; // setting the pointer to NULL
    }

    return (long double) t_tot / (long double) max_instances;
}

void lab_3(char file[], Configuration conf, const bool DEBUG_MODE) {
    FILE *fp = fopen(file, "w+");
    if (fp == NULL) {
        fprintf(stderr, "Failed to open file `%s`\n", file);
        exit(EXIT_FAILURE);
    }

    fprintf(fp, "Dimension (n),Quick Sort,Median of Three Quick Sort\n");
    for (ssize_t length = conf.min_length; length <= conf.max_length; length += conf.step) {
        srand(conf.seed);
        long double time_QS = experiment_3(length, conf.max_instances, QS, DEBUG_MODE);

        srand(conf.seed);
        long double time_MTQS = experiment_3(length, conf.max_instances, MTQS, DEBUG_MODE);

        fprintf(fp, "%ld,%Lf,%Lf\n", length, time_QS, time_MTQS); // write to file

        ++conf.seed;
    }

    if (fclose(fp) == EOF)
        fprintf(stderr, "Failed to flush buffered data on `%s`\n", file);
}
