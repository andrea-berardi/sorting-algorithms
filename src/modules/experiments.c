#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "../headers/sortingAlgorithms.h"
#include "../headers/experiments.h"
#include "../headers/utils.h"

enum algorithm {
    IS, // Insertion Sort
    MS, // Merge Sort
    HS, // Hybrid Sort (Merge Sort + Adapted Insertion Sort)
};

// Experiment n.2 - Insertion Sort, Merge Sort, Hybrid Sort
double experiment_2(size_t length, size_t max_instances, unsigned algorithm, const size_t THRESHOLD,
                    const unsigned DEBUG_MODE) {
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

            default: {
                fprintf(stderr, "Unknown algorithm `%d`\n", algorithm);

                exit(EXIT_FAILURE);
            }
        }

        t_tot += t_end - t_start;

        if (DEBUG_MODE) {
            // if length is 1, then we've just modified it for the first run, reset it to 0
            if (is_sorted(array, length == 1 ? --length : length))
                printf("Array sorted successfully\n");
            else
                fprintf(stderr, "The array was not sorted correctly.\n"), print_array(array, length);
        }

        free(array); // deallocating the array
        array = NULL; // setting the pointer to NULL
    }

    return t_tot / (double) max_instances;
}

void lab_2(char file[], size_t min_length, size_t max_length, size_t max_instances, size_t step, const size_t THRESHOLD,
           const unsigned SEED,
           const unsigned DEBUG_MODE) {
    unsigned seed = SEED; // 'cause SEED is a constant

    FILE *fp = fopen(file, "w+");
    if (fp == NULL) {
        fprintf(stderr, "Failed to open file `%s`\n", file);
        exit(EXIT_FAILURE);
    }

    fprintf(fp, "Dimension (n),Insertion Sort,Merge Sort,Hybrid Sort\n");
    for (size_t length = min_length; length <= max_length; length += step) {
        srand(seed);
        double time_IS = experiment_2(length, max_instances, IS, THRESHOLD, DEBUG_MODE);

        srand(seed);
        double time_MS = experiment_2(length, max_instances, MS, THRESHOLD, DEBUG_MODE);

        srand(seed);
        double time_HS = experiment_2(length, max_instances, HS, THRESHOLD, DEBUG_MODE);

        fprintf(fp, "%zu,%lf,%lf,%lf\n", length, time_IS, time_MS, time_HS); // write to file

        ++seed;
    }

    if (fclose(fp) == EOF)
        fprintf(stderr, "Failed to flush buffered data on `%s`\n", file);
}

// Experiment n.2A - Merge Sort
double experiment_2A(size_t length, size_t max_instances, const unsigned DEBUG_MODE) {
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

        // If length is 0, and so, just for the first run of the experiment, we will raise it to 1, to avoid
        // "double free" errors. Why? Because MergeSort() is meant to be called with "length - 1" and using 0
        // as a starting point would make the first MergeSort() call with length equals to -1.
        // We don't need to restore length to the correct value because it is copied, not passed by reference.
        // The "real" value is unaffected.
        if (length == 0) ++length;

        clock_t t_start, t_end;

        t_start = clock(); // starting processor time stopwatch
        MergeSort(array, 0, length - 1); // sorting the array
        t_end = clock();

        t_tot += t_end - t_start;

        if (DEBUG_MODE) {
            // if length is 1, then we've just modified it for the first run, reset it to 0
            if (is_sorted(array, length == 1 ? --length : length))
                printf("Array sorted successfully\n");
            else
                fprintf(stderr, "The array was not sorted correctly.\n"), print_array(array, length);
        }

        free(array); // deallocating the array
        array = NULL; // setting the pointer to NULL
    }

    return t_tot / (double) max_instances;
}

void lab_2A(char file[], size_t min_length, size_t max_length, size_t max_instances, size_t step, const unsigned SEED,
            const unsigned DEBUG_MODE) {
    srand(SEED); // Reset seed - a fixed seed ensures reproducible results

    FILE *fp = fopen(file, "w+");
    if (fp == NULL) {
        fprintf(stderr, "Failed to open file `%s`\n", file);
        exit(EXIT_FAILURE);
    }

    fprintf(fp, "Dimension: array length (n),Time (clock)\n");
    for (size_t length = min_length; length <= max_length; length += step)
        fprintf(fp, "%zu,%lf\n", length, experiment_2A(length, max_instances, DEBUG_MODE));

    if (fclose(fp) == EOF)
        fprintf(stderr, "Failed to flush buffered data on `%s`\n", file);
}

// Experiment n.2B - Hybrid Sort
double experiment_2B(size_t length, size_t max_instances, size_t THRESHOLD, const unsigned DEBUG_MODE) {
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

        // If length is 0, and so, just for the first run of the experiment, we will raise it to 1, to avoid
        // "double free" errors. Why? Because HybridSort() is meant to be called with "length - 1" and using 0
        // as a starting point would make the first HybridSort() call with length equals to -1.
        // We don't need to restore length to the correct value because it is copied, not passed by reference.
        // The "real" value is unaffected.
        if (length == 0) ++length;

        clock_t t_start, t_end;

        t_start = clock(); // starting processor time stopwatch
        HybridSort(array, 0, length - 1, THRESHOLD); // sorting the array
        t_end = clock();

        t_tot += t_end - t_start;

        if (DEBUG_MODE) {
            // if length is 1, then we've just modified it for the first run, reset it to 0
            if (is_sorted(array, length == 1 ? --length : length))
                printf("Array sorted successfully\n");
            else
                fprintf(stderr, "The array was not sorted correctly.\n"), print_array(array, length);
        }

        free(array); // deallocating the array
        array = NULL; // setting the pointer to NULL
    }

    return t_tot / (double) max_instances;
}

void
lab_2B(char file[], size_t min_length, size_t max_length, size_t max_instances, size_t step, const size_t THRESHOLD,
       const unsigned SEED,
       const unsigned DEBUG_MODE) {
    srand(SEED); // Reset seed - a fixed seed ensures reproducible results

    FILE *fp = fopen(file, "w+");
    if (fp == NULL) {
        fprintf(stderr, "Failed to open file `%s`\n", file);
        exit(EXIT_FAILURE);
    }

    fprintf(fp, "Dimension: array length (n),Time (clock)\n");
    for (size_t length = min_length; length <= max_length; length += step)
        fprintf(fp, "%zu,%lf\n", length, experiment_2B(length, max_instances, THRESHOLD, DEBUG_MODE));

    if (fclose(fp) == EOF)
        fprintf(stderr, "Failed to flush buffered data on `%s`\n", file);
}

// Experiment n.1 - Insertion Sort
double experiment_1(size_t length, size_t max_instances, const unsigned DEBUG_MODE) {
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
                fprintf(stderr, "The array was not sorted correctly.\n"), print_array(array, length);
        }

        free(array); // deallocating the array
        array = NULL; // setting the pointer to NULL
    }

    return t_tot / (double) max_instances;
}

void lab_1(char file[], size_t min_length, size_t max_length, size_t max_instances, size_t step, const unsigned SEED,
           const unsigned DEBUG_MODE) {
    srand(SEED); // Reset seed - a fixed seed ensures reproducible results

    FILE *fp = fopen(file, "w+");
    if (fp == NULL) {
        fprintf(stderr, "Failed to open file `%s`\n", file);
        exit(EXIT_FAILURE);
    }

    fprintf(fp, "Dimension: array length (n),Time (clock)\n");
    for (size_t length = min_length; length <= max_length; length += step)
        fprintf(fp, "%zu,%lf\n", length, experiment_1(length, max_instances, DEBUG_MODE));

    if (fclose(fp) == EOF)
        fprintf(stderr, "Failed to flush buffered data on `%s`\n", file);
}
