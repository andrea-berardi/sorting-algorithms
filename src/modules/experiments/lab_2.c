#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "../../headers/utils.h"
#include "../../headers/sortingAlgorithms.h"
#include "../../headers/experiments.h"

// Lab. 2A - Insertion Sort, Merge Sort
long double experiment_2A(ssize_t length, size_t max_instances, Algorithm algorithm, const unsigned DEBUG_MODE) {
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
            case IS: {
                t_start = clock(); // starting processor time stopwatch
                InsertionSort(array, length); // sorting the array
                t_end = clock();

                break;
            }

            case MS: {
                t_start = clock(); // starting processor time stopwatch
                MergeSort(array, 0, length - 1); // sorting the array
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

void lab_2A(char file[], Configuration conf, const bool DEBUG_MODE) {
    FILE *fp = fopen(file, "w+");
    if (fp == NULL) {
        fprintf(stderr, "Failed to open file `%s`\n", file);
        exit(EXIT_FAILURE);
    }

    fprintf(fp, "Dimension (n),Insertion Sort,Merge Sort\n");
    for (ssize_t length = conf.min_length; length <= conf.max_length; length += conf.step) {
        srand(conf.seed);
        long double time_IS = experiment_2A(length, conf.max_instances, IS, DEBUG_MODE);

        srand(conf.seed);
        long double time_MS = experiment_2A(length, conf.max_instances, MS, DEBUG_MODE);

        fprintf(fp, "%ld,%Lf,%Lf\n", length, time_IS, time_MS); // write to file

        ++conf.seed;
    }

    if (fclose(fp) == EOF)
        fprintf(stderr, "Failed to flush buffered data on `%s`\n", file);
}

// Final experiment (it runs all tests)
long double experiment_2B(ssize_t length, size_t max_instances, Algorithm algorithm, const ssize_t THRESHOLD,
                          const unsigned DEBUG_MODE) {
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
            case IS: {
                t_start = clock(); // starting processor time stopwatch
                InsertionSort(array, length); // sorting the array
                t_end = clock();

                break;
            }

            case MS: {
                t_start = clock(); // starting processor time stopwatch
                MergeSort(array, 0, length - 1); // sorting the array
                t_end = clock();

                break;
            }

            case HS: {
                t_start = clock(); // starting processor time stopwatch
                HybridSort(array, 0, length - 1, THRESHOLD); // sorting the array
                t_end = clock();

                break;
            }

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

            case TQS: {
                t_start = clock(); // starting processor time stopwatch
                TailQuickSort(array, 0, length - 1); // sorting the array
                t_end = clock();

                break;
            }

            case HPS: {
                t_start = clock(); // starting processor time stopwatch
                HeapSort(array, length); // sorting the array
                t_end = clock();

                break;
            }

            case MTTQS: {
                t_start = clock(); // starting processor time stopwatch
                MedianOfThreeTailQuickSort(array, 0, length - 1); // sorting the array
                t_end = clock();

                break;
            }

            case RWS: {
                t_start = clock(); // starting processor time stopwatch
                RealWorldSort(array, length - 1, THRESHOLD); // sorting the array
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

void lab_2B(char file[], Configuration conf, const bool DEBUG_MODE) {
    FILE *fp = fopen(file, "w+");
    if (fp == NULL) {
        fprintf(stderr, "Failed to open file `%s`\n", file);
        exit(EXIT_FAILURE);
    }

    fprintf(fp, "Dimension (n),Insertion Sort,Merge Sort,Hybrid Sort\n");
    for (ssize_t length = conf.min_length; length <= conf.max_length; length += conf.step) {
        srand(conf.seed);
        long double time_IS = experiment_2B(length, conf.max_instances, IS, conf.threshold, DEBUG_MODE);

        srand(conf.seed);
        long double time_MS = experiment_2B(length, conf.max_instances, MS, conf.threshold, DEBUG_MODE);

        srand(conf.seed);
        long double time_HS = experiment_2B(length, conf.max_instances, HS, conf.threshold, DEBUG_MODE);

        fprintf(fp, "%ld,%Lf,%Lf,%Lf\n", length, time_IS, time_MS, time_HS); // write to file

        ++conf.seed;
    }

    if (fclose(fp) == EOF)
        fprintf(stderr, "Failed to flush buffered data on `%s`\n", file);
}
