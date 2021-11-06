cmake_minimum_required(VERSION 3.20)
project(sorting_algorithms C)

set(CMAKE_C_STANDARD 11)

add_executable(sorting_algorithms main.c utils.c utils.h sortingAlgorithms.c sortingAlgorithms.h experiments.c experiments.h)
