#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#include "headers/experiments.h"
#include "headers/utils.h"

const bool DEBUG_MODE = false; // this flag toggles debug checks (e.g. it checks if the algorithms sort correctly)

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Wrong number of arguments supplied.\n");
        fprintf(stderr, "Usage: `.%s <1-5>`.\n", argv[0]);
        fprintf(stderr, "Please specify which test you want to run:\n");
        fprintf(stderr, "1) Lab. 1\n2) Lab. 2\n3) Lab. 3\n4) Lab. 4\n5) Everything\n");

        exit(EXIT_FAILURE);
    }

    /* Lab. 1 configurations */
    Configuration lab1_conf;
    lab1_conf.min_length = 0; // minimum length of the arrays
    lab1_conf.max_length = 50000; // maximum length of the arrays
    lab1_conf.max_instances = 50; // how many times to repeat the same test
    lab1_conf.step = 1000; // the arrays will grow this much at each test
    lab1_conf.threshold = 199; // threshold after which the sorting algorithm changes
    lab1_conf.seed = 10; // srand()'s starting seed

    /* Lab. 2 configurations */
    Configuration lab2_conf;
    lab2_conf.min_length = 0; // minimum length of the arrays
    lab2_conf.max_length = 50000; // maximum length of the arrays
    lab2_conf.max_instances = 100; // how many times to repeat the same test
    lab2_conf.step = 1000; // the arrays will grow this much at each test
    lab2_conf.threshold = 199; // threshold after which the sorting algorithm changes
    lab2_conf.seed = 10; // srand()'s starting seed

    /* Lab. 3 configurations */
    Configuration lab3_conf;
    lab3_conf.min_length = 0; // minimum length of the arrays
    lab3_conf.max_length = 50000; // maximum length of the arrays
    lab3_conf.max_instances = 100; // how many times to repeat the same test
    lab3_conf.step = 1000; // the arrays will grow this much at each test
    lab3_conf.threshold = 199; // threshold after which the sorting algorithm changes
    lab3_conf.seed = 10; // srand()'s starting seed

    /* Lab. 4 configurations */
    Configuration lab4_conf;
    lab4_conf.min_length = 0; // minimum length of the arrays
    lab4_conf.max_length = 50000; // maximum length of the arrays
    lab4_conf.max_instances = 100; // how many times to repeat the same test
    lab4_conf.step = 1000; // the arrays will grow this much at each test
    lab4_conf.threshold = 199; // threshold after which the sorting algorithm changes
    lab4_conf.seed = 10; // srand()'s starting seed

    /* Final experiment configurations */
    Configuration final_exp_conf;
    final_exp_conf.min_length = 0; // minimum length of the arrays
    final_exp_conf.max_length = 10000; // maximum length of the arrays
    final_exp_conf.max_instances = 10; // how many times to repeat the same test
    final_exp_conf.step = 100; // the arrays will grow this much at each test
    final_exp_conf.threshold = 199; // threshold after which the sorting algorithm changes
    final_exp_conf.seed = 1; // srand()'s starting seed

    if (strcmp(argv[1], "1") == 0) {
        /* Lab. 1 - Insertion Sort */
        lab_1("../results/lab_1/lab_1.csv", lab1_conf, DEBUG_MODE);
    } else if (strcmp(argv[1], "2") == 0) {
        /* Lab. 2 - Merge Sort, Hybrid Sort */
    } else if (strcmp(argv[1], "3") == 0) {
        /* Lab. 3 */
    } else if (strcmp(argv[1], "4") == 0) {
        /* Lab. 4 */
    } else if (strcmp(argv[1], "5") == 0) {
        /* Final Experiment that runs all algorithms */
        // Insertion Sort, Merge Sort, Hybrid Sort, Quick Sort, Median of Three Quick Sort,
        // Tail Recursive Quick Sort, Heap Sort, Median of Three Tail Quick Sort, Real World Sort
        lab_tot("../results/results_total.csv", final_exp_conf, DEBUG_MODE);
    } else {
        fprintf(stderr, "Invalid argument supplied\n");
        fprintf(stderr, "Usage: `.%s <1-5>`.\n", argv[0]);
        fprintf(stderr, "Please specify which test you want to run:\n");
        fprintf(stderr, "1) Lab. 1\n2) Lab. 2\n3) Lab. 3\n4) Lab. 4\n5) Everything\n");

        exit(EXIT_FAILURE);
    }

    return EXIT_SUCCESS;
}
