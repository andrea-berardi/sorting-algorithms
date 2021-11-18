cmake_minimum_required(VERSION 3.20)
project(sorting_algorithms C)

set(CMAKE_C_STANDARD 11)

add_executable(sorting_algorithms src/main.c src/modules/utils.c src/headers/utils.h src/modules/sortingAlgorithms.c src/headers/sortingAlgorithms.h src/modules/experiments.c src/headers/experiments.h)

# Uncomment to enable runtime sanity checks (this will slow down the executable by a lot!)
# Currently it is enabled only for debug builds
set(CMAKE_C_FLAGS_DEBUG "${CMAKE_C_FLAGS} -fsanitize=address -fsanitize=undefined -fsanitize=leak -g")