//
// Created by Thiago on 10/05/2021.
//

#include <algorithm>
#include "optimized-solution.h"
#include "distance-matrix.h"


/**
 * Calcula a nova aresta adicionada quando 2 sub-soluções são concatenadas
 * @param solution_1
 * @param solution_2
 * @param distance_matrix
 * @param size - Tamanho da matriz de distâncias
 * @return A distância entre o último nó da solution_1 e o primeiro nó da solution_2
 */
int calculate_new_edge_distance(OptimizedSolution solution_1, OptimizedSolution solution_2, const int * distance_matrix, int size = SIZE) {
    int solution_1_last_vertex = solution_1.last_vertex();
    int solution_2_first_vertex = solution_2.vertices[0];
    return get_distance(solution_1_last_vertex, solution_2_first_vertex, distance_matrix, size);
}

/**
 * Concatena o valor de T (Soma dos custos das arestas) de duas soluções
 * @param solution_1
 * @param solution_2
 * @param distance_matrix
 * @param size
 * @return O valor concatenado de T
 */
int concatenate_T(OptimizedSolution solution_1, OptimizedSolution solution_2, const int * distance_matrix, int size = SIZE) {
    int new_vertex_distance = calculate_new_edge_distance(solution_1, solution_2, distance_matrix, size);
    return solution_1.T + new_vertex_distance + solution_2.T;
}

/**
 * Concatena o valor de C (Soma das latências dos vértices) de duas soluções
 * @param solution_1
 * @param solution_2
 * @param distance_matrix
 * @param size
 * @return O valor concatenado de C
 */
int concatenate_C(OptimizedSolution solution_1, OptimizedSolution solution_2, const int * distance_matrix, int size = SIZE) {
    int new_vertex_distance = calculate_new_edge_distance(solution_1, solution_2, distance_matrix, size);

    return solution_1.C + solution_2.W * (solution_1.T + new_vertex_distance) + solution_2.C;
}

/**
 * Concatena duas soluções otimizadas, reaproveitando dos valores de C, T e W para realizar o cálculo mais facilmente
 * @param solution_1 - Primeira solução a ser concatenada
 * @param solution_2 - Segunda solução a ser concatenada
 * @param distance_matrix - Matriz de distâncias
 * @param size - dimensão da matriz (tamanho do problema)
 * @return Uma nova solução, obtida pela concatenação das soluções passadas como parâmetro
 */
OptimizedSolution concatenate_solutions(OptimizedSolution solution_1, OptimizedSolution solution_2, const int * distance_matrix, int size) {
    int new_T = concatenate_T(solution_1, solution_2, distance_matrix, size);
    int new_C = concatenate_C(solution_1, solution_2, distance_matrix, size);
    int new_W = solution_1.W + solution_2.W;

    OptimizedSolution new_solution = {
      .C = new_C,
      .T = new_T,
      .W = new_W,
      .size = solution_1.size + solution_2.size
    };

    std::copy(solution_1.vertices, solution_1.vertices + solution_1.size, new_solution.vertices);
    std::copy(solution_2.vertices, solution_2.vertices + solution_2.size, new_solution.vertices + solution_1.size);

    return new_solution;
}
