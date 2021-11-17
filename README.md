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

## Project Structure

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
