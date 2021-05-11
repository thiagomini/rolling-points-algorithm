//
// Created by Thiago on 10/05/2021.
//

#ifndef ALGORITMO_TCC_OPTIMIZED_SOLUTION_H
#define ALGORITMO_TCC_OPTIMIZED_SOLUTION_H

#include "../configurations.h"

typedef struct {
    // Indica a soma da latência de cada vértice dessa solução
    int C;

    // Indica a soma do custo das arestas dessa solução
    int T;

    // Indica o tamanho da solução, descontando o V0
    int W;

    // Número de vértices nessa solução
    int size;

    // array de vértices da solução
    int vertices[SIZE];

    int last_vertex() {
        return vertices[size - 1];
    }

} OptimizedSolution;

OptimizedSolution concatenate_solutions(OptimizedSolution solution_1, OptimizedSolution solution_2, const int * distance_matrix, int size = SIZE);

int test_optimized_solution();

#endif //ALGORITMO_TCC_OPTIMIZED_SOLUTION_H
