//
// Created by Thiago on 10/05/2021.
//

#ifndef ALGORITMO_TCC_OPTIMIZED_SOLUTION_H
#define ALGORITMO_TCC_OPTIMIZED_SOLUTION_H

#include <cstring>
#include "../configurations.h"
#include "../utils/array.h"

typedef struct OptimizedSolution {
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

    bool equals(int c, int t, int w, int total_size, int * array) {
        return c == C &&
        t == T &&
        w == W &&
        total_size == size &&
        arrays_are_equal(array, vertices, total_size);
    }

    bool equals(int c, int t, int w, int total_size, std::vector<int> array) {
        return c == C &&
               t == T &&
               w == W &&
               total_size == size &&
               arrays_are_equal(array.data(), vertices, total_size);
    }

    bool operator==(OptimizedSolution other_solution) {
        return equals(other_solution.C, other_solution.T, other_solution.W, other_solution.size, other_solution.vertices);
    }

} OptimizedSolution;

OptimizedSolution concatenate_solutions(OptimizedSolution solution_1, OptimizedSolution solution_2, const int * distance_matrix, int size = SIZE);

OptimizedSolution clone(OptimizedSolution &source);

int test_optimized_solution();

#endif //ALGORITMO_TCC_OPTIMIZED_SOLUTION_H
