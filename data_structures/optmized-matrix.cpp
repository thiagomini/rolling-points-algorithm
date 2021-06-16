//
// Created by Thiago on 11/05/2021.
//

#include <valarray>
#include "optmized-matrix.h"
#include "../utils/distance.h"

/**
 * Preenche uma sub-solução com os vértices referentes à solução inteira
 * @param solution - Solução de referência
 * @param vertices - vértices da solução de referência
 * @param begin - Posição inicial de onde os vértices serão copiados
 * @param end - Posição final de onde vértices serão copiados. Caso seja menor que a posição inicial, a cópia acontece
 * de trás para frente
 */
void fill_sub_solution(OptimizedSolution &solution, const int vertices[], int begin, int end) {
    int bigger = MAX(begin, end);

    if (end == bigger) {
        for (int i = 0; i < solution.size; ++i) {
            solution.vertices[i] = vertices[begin + i];
        }
    } else {
        for (int i = 0; i < solution.size; ++i) {
            solution.vertices[i] = vertices[end - i];
        }
    }
}

/**
 * Inicializa os vértices e os valores das sub-soluções da matriz
 * @param optimized_matrix
 * @param vertices
 */
void initialize_vertices(OptimizedMatrix &optimized_matrix) {
    for (int i = 0; i < optimized_matrix.size; ++i) {
        for (int j = 0; j < optimized_matrix.size; ++j) {
            optimized_matrix.sub_solutions[i][j].C = 0;
            optimized_matrix.sub_solutions[i][j].T = 0;
            optimized_matrix.sub_solutions[i][j].W = 0;
            optimized_matrix.sub_solutions[i][j].size = (DIFF(i, j)) + 1;
        }
    }
}

/**
 * Inicializa os valores da diagonal principal da matriz otimizada
 * @param optimized_matrix
 * @param size
 */
void initialize_primary_diagonal(OptimizedMatrix &optimized_matrix, int size, int *vertices) {
    for (int i = 1; i < size; ++i) {
        optimized_matrix.sub_solutions[i][i].W = 1;
        optimized_matrix.sub_solutions[i][i].vertices[0] = vertices[i];
    }
}

/**
 * Constrói a estrutura em matriz otimizada de uma solução
 * @param vertices - Os vértices da solução de referência
 * @param distance_matrix - A matriz de distância, usada para calcular as sub-soluções
 * @param size - A dimensão do problema (número de vértices)
 * @return A matriz otimizada
 */
OptimizedMatrix build_opt_matrix(int *vertices, const int * distance_matrix, int size) {
    OptimizedMatrix optimizedMatrix = {
            .size = size
    };

    initialize_vertices(optimizedMatrix);
    initialize_primary_diagonal(optimizedMatrix, size, vertices);

    for (int i = 2; i <= size; i++) {
        for (int row = 0; row <= size - i; row++) {
            int column = row + (i - 1);
            OptimizedSolution previous_solution =  optimizedMatrix.sub_solutions[row][column - 1];
            OptimizedSolution current_solution = optimizedMatrix.sub_solutions[column][column];
            optimizedMatrix.sub_solutions[row][column] = concatenate_solutions(previous_solution, current_solution, distance_matrix, size);
        }
    }

    for (int i = 2; i <= size; i++) {
        for (int row = i - 1; row <= size - 1; row++) {
            int column = row - (i - 1);
            OptimizedSolution current_solution =  optimizedMatrix.sub_solutions[row][row];
            OptimizedSolution above_solution = optimizedMatrix.sub_solutions[row - 1][column];
            optimizedMatrix.sub_solutions[row][column] = concatenate_solutions(current_solution, above_solution, distance_matrix, size);
        }
    }

    return optimizedMatrix;
}
