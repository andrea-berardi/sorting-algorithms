#include <stdio.h>
#include <stdlib.h>

#include "../headers/utils.h"
#include "../headers/sortingAlgorithms.h"

/* Insertion Sort */
// At each iteration Insertion Sort picks one element from the array,
// finds its correct location, and inserts it there. The remaining
// elements are arranged in the inner `while` loop, that moves them
// while positioning the "key".
void InsertionSort(int array[], ssize_t length) {
    for (ssize_t j = 1; j < length; ++j) {
        int key = array[j];
        ssize_t i = j - 1;

        while (i >= 0 && array[i] > key) {
            array[i + 1] = array[i];
            --i;
        }

        array[i + 1] = key;
    }
}

/* Merge procedure */
// This procedure merges to sorted sequences.
// We merge by calling this auxiliary procedure `Merge(A, l, c, r)`, where A is
// our array and l, c, and r are indices into the array such that l <= c < r.
// The procedure assumes that the sub-arrays A[l..c] and A[c+1..r] are in sorted order.
// It merges them to form a single sorted subarray that replaces the current subarray A[l..r].
// Since we're creating these auxiliary arrays, we can't consider Merge Sort to be "in place".
void Merge(int array[], size_t l, size_t c, size_t r) {
    size_t n1 = c - l + 1;
    size_t n2 = r - c;

    int *left = new_array(n1); // errors are handled by the new_array() function
    int *right = new_array(n2); // errors are handled by the new_array() function

    for (size_t i = 0; i < n1; ++i) left[i] = array[l + i];
    for (size_t j = 0; j < n2; ++j) right[j] = array[(c + 1) + j];

    size_t i = 0;
    size_t j = 0;
    for (size_t k = l; k <= r; ++k) {
        if (i < n1) {
            if (j < n2) {
                if (left[i] < right[j]) {
                    array[k] = left[i];
                    ++i;
                } else {
                    array[k] = right[j];
                    ++j;
                }
            } else {
                array[k] = left[i];
                ++i;
            }
        } else {
            array[k] = right[j];
            ++j;
        }
    }

    free(left); // it's necessary to give back to the OS the heap-memory we have allocated
    left = NULL;
    free(right); // it's necessary to give back to the OS the heap-memory we have allocated
    right = NULL;
}

/* Merge Sort (usage: MergeSort(A, left, right - 1)) */
// If the left index is smaller than the right one, we compute the
// element in between and use it as an index for the Merge procedure.
// Then we recursively call MergeSort() to further divide the sub-sequences
// until the initial `if` is no longer true. We then start merging these
// arrays using the Merge procedure.
// Merge Sort is a "divide-and-conquer" algorithm.
void MergeSort(int array[], ssize_t l, ssize_t r) {
    if (l < r) {
        ssize_t c = (l + r) / 2;

        MergeSort(array, l, c);
        MergeSort(array, c + 1, r);

        Merge(array, l, c, r);
    }
}

/* Adapted Insertion Sort */
// This procedure is an adapted version of Insertion Sort, that
// simply allows specifying which range of the array we want to sort.
void AdaptedInsertionSort(int array[], ssize_t l, ssize_t r) {
    for (ssize_t j = l + 1; j < r; ++j) {
        int key = array[j];
        ssize_t i = j - 1;

        while (i >= l && array[i] > key) {
            array[i + 1] = array[i];
            --i;
        }

        array[i + 1] = key;
    }
}

/* Hybrid Sort (usage: HybridSort(A, left, right - 1, threshold)) */
// This is an adapted version of Merge Sort that allows to use Insertion Sort
// on small arrays, in order to take advantage of the good performances of
// the latter on small sequences. This does not change the asymptotic behavior
// of the algorithm, but it's a very effective heuristic.
void HybridSort(int array[], ssize_t l, ssize_t r, const ssize_t THRESHOLD) {
    if (r - l > THRESHOLD) {
        ssize_t c = (l + r) / 2;

        HybridSort(array, l, c, THRESHOLD);
        HybridSort(array, c + 1, r, THRESHOLD);

        Merge(array, l, c, r);
    } else {
        AdaptedInsertionSort(array, l, r + 1); // `r+1` because HybridSort&MergeSort are instantiated with `length-1`
    }
}

/* Partition */
// Partition selects a pivot that is typically the last element in the array (`x = A[r]`).
// The algorithm maintains an index `i` as it scans the array using another index `j`
// such that the elements at `l` through `i-1` (inclusive) are smaller than the pivot, and the elements
// at `i` through `j` (inclusive) are equal to or greater than the pivot.
ssize_t Partition(int array[], ssize_t l, ssize_t r) {
    int x = array[r];
    ssize_t i = l - 1;

    for (ssize_t j = l; j < r; ++j) {
        if (array[j] <= x) {
            ++i;
            swap(&array[i], &array[j]);
        }
    }

    swap(&array[i + 1], &array[r]);

    return i + 1;
}

/* Quick Sort (usage: QuickSort(A, left, right - 1)) */
// Firstly, the Partition procedure divides the array into two consecutive non-empty
// sub-ranges, so that no element of the first sub-range is greater than any element
// of the second sub-range. After applying this partition, Quick Sort recursively
// sorts the sub-ranges, after excluding from them an element at the point of
// division that is known to be already in its correct location.
// Quick Sort is a "divide-and-conquer" algorithm.
void QuickSort(int array[], ssize_t l, ssize_t r) {
    if (l < r) {
        ssize_t c = Partition(array, l, r);

        QuickSort(array, l, c - 1);
        QuickSort(array, c + 1, r);
    }
}

/* Median of Three */
// Hardcoded procedure to find the median of three (array) values.
// We're doing this in order to get a better balanced Partition,
// instead of selecting the last element (r) no matter what.
ssize_t MedianOfThree(const int array[], ssize_t i, ssize_t j, ssize_t k) {
    // ^ is the bitwise XOR (exclusive or) operator
    // It is true only if its arguments differ.
    if ((array[i] > array[j]) ^ (array[i] > array[k])) {
        return i;
    } else if ((array[j] < i) ^ (array[j] < array[k])) {
        return j;
    } else {
        return k;
    }
}

/* Median of Three Partition */
// Adapted version of Partition, that simply selects the median of three
// elements instead of choosing the rightest one no matter what.
// This should give better performances because it creates a generally
// better balanced partition.
ssize_t MedianOfThreePartition(int array[], ssize_t l, ssize_t r) {
    ssize_t s = MedianOfThree(array, l, r, (l + r) / 2);
    swap(&array[s], &array[r]);

    return Partition(array, l, r);
}

/* Median of Three Quick Sort (usage MedianOfThreeQuickSort(array, left, right - 1)) */
// Adapted version of Quick Sort that takes advantage of the
// "Median of Three Partition" optimization. At this point, there
// are no practical differences from the standard Quick Sort.
void MedianOfThreeQuickSort(int array[], ssize_t l, ssize_t r) {
    if (l < r) {
        ssize_t c = MedianOfThreePartition(array, l, r);

        MedianOfThreeQuickSort(array, l, c - 1);
        MedianOfThreeQuickSort(array, c + 1, r);
    }
}

/* Tail Recursive Quick Sort */
// This alternative version of Quick Sort places the recursive
// call at the end of the procedure, hinting the compiler to
// optimize the generated machine-code into an iteration, rather than
// a recursive call. This prevents stack's overflows and gives better
// performances. Unfortunately, at this point, the compilers are so smart
// that this does not seem to be necessary, as this basically produces (almost)
// the same machine-code as the recursive version and there aren't big
// performance improvements.
void TailQuickSort(int array[], ssize_t l, ssize_t r) {
    while (l < r) {
        ssize_t c = Partition(array, l, r);

        TailQuickSort(array, l, c - 1);

        l = c + 1;
    }
}

/* Heap - Parent */
// This simple function returns the index of the parent of
// `i`. This is possible because we see heaps as binary trees.
// Since this function is unused it's commented out.
// size_t Parent(size_t i) {
//     return i / 2;
// }

/* Heap - Left branch */
// This procedure returns the index of the left "son" (branch)
// of a given heap with root `i`.
ssize_t Left(ssize_t i) {
    return 2 * i;
}

/* Heap - Right branch */
// This procedure returns the index of the right "son" (branch)
// of a given heap with root `i`.
ssize_t Right(ssize_t i) {
    return 2 * i + 1;
}

/* Heap - Max-Heapify */
// This procedure is meant to maintain the "max-heap" property.
// It assumes that the binary trees rooted at Left(i) and Right(i)
// are max-heaps, but that A[i] might be smaller than its children,
// thus violating the max-heap property.
// MaxHeapify() lets the value at A[i] move down in the heap, in
// order to get a subtree, rooted at index `i`, that follows
// the max-heap property.
void MaxHeapify(int array[], ssize_t i, ssize_t HeapSize, ssize_t length) {
    ssize_t l = Left(i);
    ssize_t r = Right(i);

    ssize_t largest;

    if (l < HeapSize && array[l] > array[i]) {
        largest = l;
    } else {
        largest = i;
    }

    if (r < HeapSize && array[r] > array[largest]) {
        largest = r;
    }

    if (largest != i) {
        swap(&array[i], &array[largest]);

        MaxHeapify(array, largest, HeapSize, length);
    }
}

/* Heap - Build-Max-Heap */
// This procedure goes through the remaining nodes of the binary
// tree and applies MaxHeapify() on each one.
void BuildMaxHeap(int array[], ssize_t length) {
    ssize_t HeapSize = length;
    for (ssize_t i = length / 2; i >= 0; --i) {
        MaxHeapify(array, i, HeapSize, length);
    }
}

/* HeapSort */
// This procedure starts by using BuildMaxHeap() to... build a max-heap
// on the input array. The maximum element of the array is stored at the root
// A[0] and can be placed in its correct position by swapping it with A[i].
// Unfortunately, even if the children of the root are still a max-heap, the new
// root might not maintain that property. In order to restore this property
// we simply need to call MaxHeapify().
void HeapSort(int array[], ssize_t length) {
    if (length < 2) return; // there's no reason to sort an empty or single-element array

    ssize_t HeapSize = length;
    BuildMaxHeap(array, length);

    for (ssize_t i = length - 1; i > 0; --i) {
        swap(&array[0], &array[i]);
        --HeapSize;
        MaxHeapify(array, 0, HeapSize, length);
    }
}

/* Median of Three Tail Quick Sort */
// This variation of Quick Sort implements two different optimizations:
// the median of three partition and the tail-recursive call to itself, in
// order to get both better balanced partitions and better optimized code.
void MedianOfThreeTailQuickSort(int array[], ssize_t l, ssize_t r) {
    while (l < r) {
        ssize_t c = MedianOfThreePartition(array, l, r);

        MedianOfThreeTailQuickSort(array, l, c - 1);

        l = c + 1;
    }
}

/* Hybrid Tail Recursive Median of Three Quick Sort (Median Of Three Tail Quick Sort, Insertion Sort) */
// This made-up algorithm uses a particular version of Quick Sort for
// arrays longer than a given value, and uses Insertion Sort for arrays
// shorter than that, to take advantage of Insertion Sort's good performance
// with relatively short arrays.
void HybridTailMedianOfThreeQuickSort(int array[], ssize_t l, ssize_t r, const ssize_t THRESHOLD) {
    if (r - l + 1 <= THRESHOLD) {
        AdaptedInsertionSort(array, l, r + 1);
    } else {
        while (l < r) {
            ssize_t c = MedianOfThreePartition(array, l, r);

            MedianOfThreeTailQuickSort(array, l, c - 1);

            l = c + 1;
        }
    }
}
