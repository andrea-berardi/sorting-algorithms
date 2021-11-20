cmake_minimum_required(VERSION 3.20)
project(sorting_algorithms C)

set(CMAKE_C_STANDARD 11)

add_executable(sorting_algorithms src/main.c src/modules/utils.c src/headers/utils.h src/modules/sortingAlgorithms.c src/headers/sortingAlgorithms.h src/modules/experiments/experiments.c src/headers/experiments.h src/modules/experiments/lab_1.c src/modules/experiments/lab_2.c src/modules/experiments/lab_3.c src/modules/experiments/lab_4.c)

# This enables runtime sanity checks (this will slow down the executable by a lot!)
# Currently it is enabled only for debug builds.
# Why? It is mandatory to ensure that the executables are free from bugs and Undefined Behaviors
set(CMAKE_C_FLAGS_DEBUG "${CMAKE_C_FLAGS} -fsanitize=address -fsanitize=undefined -fsanitize=leak -g")