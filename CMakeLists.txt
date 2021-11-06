cmake_minimum_required(VERSION 3.20)
project(sorting_algorithms C)

set(CMAKE_C_STANDARD 11)

add_executable(sorting_algorithms src/main.c src/modules/utils.c src/headers/utils.h src/modules/sortingAlgorithms.c src/headers/sortingAlgorithms.h src/modules/experiments.c src/headers/experiments.h src/modules/experiments/lab_1.c src/modules/experiments/lab_1.h)
