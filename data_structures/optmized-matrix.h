//
// Created by Thiago on 11/05/2021.
//

#ifndef ALGORITMO_TCC_OPTMIZED_MATRIX_H
#define ALGORITMO_TCC_OPTMIZED_MATRIX_H

#include "../configurations.h"
#include "optimized-solution.h"

typedef struct OptimizedMatrix {
    int size;
    OptimizedSolution sub_solutions [SIZE][SIZE];

    OptimizedSolution get_solution (int row, int column) {
        return sub_solutions[row][column];
    }

    OptimizedSolution get_full_solution() {
        return sub_solutions[0][size];
    }

} OptimizedMatrix;

OptimizedMatrix build_opt_matrix(int vertices[], const int * distance_matrix, int size = SIZE);

int test_opt_matrix();

#endif //ALGORITMO_TCC_OPTMIZED_MATRIX_H
