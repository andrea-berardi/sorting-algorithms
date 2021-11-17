#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "headers/experiments.h"
#include "headers/utils.h"

const bool DEBUG_MODE = false; // this flag toggles debug checks (e.g. it checks if the algorithms sort correctly)
const size_t THRESHOLD = 340; // 199, it varies... for some reasons ¯\_(ツ)_/¯
const unsigned SEED = 10; // srand()'s starting seed

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Not enough arguments has been supplied.\n");
        fprintf(stderr, "Usage: `./%s <file>`.\nDefaulting to `../results/results.csv\n", argv[0]);
    }

    // Experiment n.4 - Real World Sorting Algorithm(s)
    lab_4(argc != 2 ? "../results/results.csv" : argv[1], 0, 10000, 100, 100, THRESHOLD, SEED, DEBUG_MODE);

    return EXIT_SUCCESS;
}
