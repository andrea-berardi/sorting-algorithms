#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "../headers/sortingAlgorithms.h"
#include "../headers/experiments.h"
#include "../headers/utils.h"

// Experiment n.4 - Tail Recursive Quick Sort, Median of Three Quick Sort, Heap Sort
long double experiment_tot(ssize_t length, size_t max_instances, unsigned algorithm, const size_t THRESHOLD,
                         const unsigned DEBUG_MODE) {
    clock_t t_tot = 0;

    for (size_t instance = 1; instance <= max_instances; ++instance) {
        int *array = gen_rnd_array(length);

        // If length is 0 and the algorithm is NOT Insertion Sort, and so, just for the first run of the experiment,
        // we will raise it to 1, to avoid "double free" errors. Why? Because MergeSort() is meant to be called
        // with "length - 1" and using 0 as a starting point would make the first MergeSort() or HybridSort() call
        // with length equals to -1.
        // We don't need to restore length to the correct value because it is copied, not passed by reference.
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
                fprintf(stderr, "Unknown algorithm `%u`\n", algorithm);

                exit(EXIT_FAILURE);
            }
        }

        t_tot += t_end - t_start;

        if (DEBUG_MODE) {
            //printf("%zu = %zu - %zu\n", t_end - t_start, t_end, t_start);
            //printf("%zu / %zu = %Lf\n", t_tot, max_instances, (long double) t_tot / (long double) max_instances);

            // if length is 1, then we've just modified it for the first run, reset it to 0
            if (is_sorted(array, length == 1 ? --length : length))
                printf("Array sorted successfully (d: %ld)\n", length);
            else
                fprintf(stderr, "The array was not sorted correctly.\n"), print_array(array, length);
        }

        free(array); // deallocating the array
        array = NULL; // setting the pointer to NULL
    }

    return (long double) t_tot / (long double) max_instances;
}

void
lab_tot(char file[], ssize_t min_length, ssize_t max_length, size_t max_instances, ssize_t step, const size_t THRESHOLD,
      unsigned seed,
      const bool DEBUG_MODE) {

    FILE *fp = fopen(file, "w+");
    if (fp == NULL) {
        fprintf(stderr, "Failed to open file `%s`\n", file);
        exit(EXIT_FAILURE);
    }

    fprintf(fp,
            "Dimension (n),Insertion Sort,Merge Sort,Hybrid Sort,Quick Sort,Median of Three Quick Sort,Tail Recursive Quick Sort,Heap Sort,Median of Three Tail Quick Sort,Real World Sort\n");
    for (ssize_t length = min_length; length <= max_length; length += step) {
        srand(seed);
        long double time_IS = experiment_tot(length, max_instances, IS, THRESHOLD, DEBUG_MODE);

        srand(seed);
        long double time_MS = experiment_tot(length, max_instances, MS, THRESHOLD, DEBUG_MODE);

        srand(seed);
        long double time_HS = experiment_tot(length, max_instances, HS, THRESHOLD, DEBUG_MODE);

        srand(seed);
        long double time_QS = experiment_tot(length, max_instances, QS, THRESHOLD, DEBUG_MODE);

        srand(seed);
        long double time_MTQS = experiment_tot(length, max_instances, MTQS, THRESHOLD, DEBUG_MODE);

        srand(seed);
        long double time_TQS = experiment_tot(length, max_instances, TQS, THRESHOLD, DEBUG_MODE);

        srand(seed);
        long double time_HPS = experiment_tot(length, max_instances, HPS, THRESHOLD, DEBUG_MODE);

        srand(seed);
        long double time_MTTQS = experiment_tot(length, max_instances, MTTQS, THRESHOLD, DEBUG_MODE);

        srand(seed);
        long double time_RWS = experiment_tot(length, max_instances, RWS, THRESHOLD, DEBUG_MODE);

        fprintf(fp, "%ld,%Lf,%Lf,%Lf,%Lf,%Lf,%Lf,%Lf,%Lf,%Lf\n", length, time_IS, time_MS, time_HS, time_QS,
                time_MTQS, time_TQS, time_HPS, time_MTTQS, time_RWS); // write to file

        ++seed;
    }

    if (fclose(fp) == EOF)
        fprintf(stderr, "Failed to flush buffered data on `%s`\n", file);
}
