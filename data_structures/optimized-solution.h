//
// Created by Thiago on 10/05/2021.
//

#ifndef ALGORITMO_TCC_OPTIMIZED_SOLUTION_H
#define ALGORITMO_TCC_OPTIMIZED_SOLUTION_H

#include <cstring>
#include "../configurations.h"
#include "../utils/array.h"
#include "solution.h"

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

    /**
     * Retorna uma <b>Solution</b> à partir dessa solução otimizada
     * @return
     */
    Solution to_normal_solution() {
        Solution cloned_solution = {
                .objective_function = C,
                .size_of_solution = static_cast<size_t>(size)
        };

        memcpy(cloned_solution.vertices, vertices, sizeof(int) * size);
        return cloned_solution;
    }

} OptimizedSolution;

/**
 * Concatena duas soluções do tipo OPT, utilizando os valores calculados de C, T e W
 * @param solution_1
 * @param solution_2
 * @param distance_matrix
 * @param size - Tamanho da matriz de distâncias
 * @return Uma nova solução, resultado da concatenação das duas sub-soluções passadas como parâmetro
 */
OptimizedSolution concatenate_solutions(OptimizedSolution solution_1, OptimizedSolution solution_2, const int * distance_matrix, int size = SIZE);

/**
 * Concatena uma lista de soluções do tipo OPT, utilizando os valores calculados de C, T e W
 * @param solutions - Lista de soluções
 * @param distance_matrix
 * @param number_of_solutions - Número de soluções na lista
 * @param size - Tamanho da matriz de distâncias
 * @return Uma nova solução, resultado da concatenação das sub-soluções da lista
 */
OptimizedSolution concatenate_solutions(OptimizedSolution solutions[], const int * distance_matrix, int number_of_solutions, int size = SIZE);

/**
 * Concatena um <b>vector</b> de soluções do tipo OPT, utilizando os valores calculados de C, T e W
 * @param solutions - O vector contendo as soluções
 * @param distance_matrix
 * @param size - Tamanho das soluções
 * @return Uma nova solução, resultado da concatenação das sub-soluções do vector
 */
OptimizedSolution concatenate_solutions(std::vector<OptimizedSolution> solutions, const int * distance_matrix, int size = SIZE);

/**
 * Clona uma solução do tipo OPT
 * @param source - Solução original
 * @return Clone da solução original
 */
OptimizedSolution clone(OptimizedSolution &source);

int test_optimized_solution();

#endif //ALGORITMO_TCC_OPTIMIZED_SOLUTION_H
