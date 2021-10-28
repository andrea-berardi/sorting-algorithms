#include <stdbool.h>

#include "utils.h"

// Check if a given array is sorted (ascending order)
bool is_sorted(const int array[], size_t length) {
    for (size_t i = 1; i < length; ++i) {
        if (array[i - 1] > array[i])
            return false;
    }

    return true;
}
