# Sorting Algorithms

This repository contains a bunch of sorting algorithms and allows to easily test them.

## Algorithms currently implemented:

- Insertion Sort
- Merge Sort
- Hybrid Sort _(Merge Sort + Insertion Sort)_
- Quick Sort
- Median of Three Quick Sort
- Tail Recursive Quick Sort
- Heap Sort
- Median of Three Tail Quick Sort
- Real World Sort _(Median of Three Tail Quick Sort + Heap Sort)_

## Project Structure

```
sorting-algorithms
├── CMakeLists.txt
├── docs
│  ├── Laboratorio 01 - Insertion Sort e struttura esperimenti.pdf
│  ├── Laboratorio 02 - Merge Sort e Hybrid Sort.pdf
│  ├── Laboratorio 03 - Quick Sort con Mediana di Tre.pdf
│  └── Laboratorio 04 - Quick Sort con Tail Recursion ottimizzato.pdf
├── README.md
├── results
│  ├── results.csv
│  └── results.ods
└── src
   ├── headers
   │  ├── experiments.h
   │  ├── sortingAlgorithms.h
   │  └── utils.h
   ├── main.c
   └── modules
      ├── experiments.c
      ├── sortingAlgorithms.c
      └── utils.c
```

## Notes

At the moment, as far as I can tell, the project is 100% bug-free and undefined behavior-free.

The `CMakeLists.txt` (build file) ensures that debug builds have runtime sanity checks (provided by Clang) and the absence of warnings\* hints that there aren't weird things going on. The `DEBUG_MODE` flag on the code even allows to perform additional correctness checks (it ensures the algorithms sort correctly). I have decided to keep it as a `const` flag to allow the compiler to better optimize the code when it is set to `false`.

I'm planning to add more specific directions on how to run the project, but afaik it should be already out-of-the-box.

I use CLion as my IDE and Clang as my compiler. The project manager is CMake.

_\*: Unfortunately there's a tiny warning due to my use of `rand()` in the `gen_rand_array()` function. Basically, the IDE is saying that it has limited randomness, which is fine and totally expected. Please ignore._
