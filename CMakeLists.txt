cmake_minimum_required(VERSION 3.17)
project(algoritmo_tcc)

set(CMAKE_CXX_STANDARD 14)

add_executable(algoritmo_tcc main.cpp data_structures/array.cpp data_structures/array.h constructive-heuristic.cpp constructive-heuristic.h utils/distance.cpp utils/distance.h data_structures/node.cpp data_structures/node.h data_structures/data-read.cpp data_structures/data-read.h utils/string-utils.cpp utils/string-utils.h data_structures/solution.cpp data_structures/solution.h data_structures/distance-matrix.h data_structures/distance-matrix.cpp)