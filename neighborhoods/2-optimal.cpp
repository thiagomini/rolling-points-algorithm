//
// Created by Thiago on 03/04/2021.
//

#include "2-optimal.h"
#include "../data_structures/edge.h"
#include "../utils/randomizer.h"
#include <memory.h>

/**
 * Encontra a posição no vector de arestas que contenha o nó informado. Caso nenhuma aresta possua esse nó, a função
 * retorna -1
 * @param edges - Vector de arestas
 * @param node - O nó a ser encontrado
 * @return O índice do vector que contém o nó informado, ou <b>-1</b> caso não encontre
 */
int find_edge_containing_node(const std::vector<edge>& edges, int node) {
    int max_iterations = (int) edges.size();
    for (int i = 0; i < max_iterations; i++) {
        if (edges[i].first_node == node ||
            edges[i].second_node == node)
            return i;
    }

    return -1;
}

void two_optimal_move(Solution &solution, const int * distance_matrix, size_t edge_1, size_t edge_2, int size) {
    if (abs(int(edge_1 - edge_2)) <= 1)
        throw "Vertice escolhidos nao podem ser adjacentes";

    int greater_index = MAX(edge_1, edge_2);
    int lower_index = MIN(edge_1, edge_2);

    vector<int> new_vertices;
    new_vertices.reserve(size);
    new_vertices.push_back(0);

    for (int i = 1; i <= lower_index; i++) {
        new_vertices.push_back(solution.vertices[i]);
    }

    for (int i = greater_index; i > lower_index; i--) {
        new_vertices.push_back(solution.vertices[i]);
    }

    for (int i = greater_index + 1; i < size; i++) {
        new_vertices.push_back(solution.vertices[i]);
    }

    memcpy(solution.vertices, new_vertices.data(), sizeof(int) * size);
    calculate_objective_function(&solution, distance_matrix, size);

}

void two_optimal_move(Solution &solution, const int * distance_matrix, int size) {
    size_t random_edge_1 = RANDOM_BETWEEN(1, size - 1);
    size_t random_edge_2 = RANDOM_BETWEEN(1, size - 1);

    while (random_edge_2 == random_edge_1 || (abs(int(random_edge_1 - random_edge_2)) <= 1)) {
        random_edge_2 = RANDOM_BETWEEN(1, size - 1);
    }

    two_optimal_move(solution, distance_matrix, random_edge_1, random_edge_2, size);
}

Solution build_two_optimal(Solution solution, const int * distance_matrix, size_t edge_1, size_t edge_2, int size) {
    two_optimal_move(solution, distance_matrix, edge_1, edge_2, size);
    return solution;
}

OptimizedSolution build_two_optimal(OptimizedMatrix optimized_matrix, const int * distance_matrix, int vertex_1, int vertex_2) {
    if (DIFF(vertex_1, vertex_2) == 1) {
        throw "Arestas não podem ser ajacentes!";
    }

    int matrixSize = optimized_matrix.size;
    int greater_index, lower_index;
    greater_index = MAX(vertex_1, vertex_2);
    lower_index = MIN(vertex_1, vertex_2);

    if (greater_index >= matrixSize) {
        throw "Índices inválidos para o movimento 2-OPT";
    }

    std::vector<OptimizedSolution> sub_solutions;
    sub_solutions.reserve(5);

    sub_solutions.push_back(optimized_matrix.get_solution(0, lower_index));
    sub_solutions.push_back(optimized_matrix.get_solution(greater_index, lower_index + 1));

    if (greater_index + 1 < matrixSize) {
        sub_solutions.push_back(optimized_matrix.get_solution(greater_index + 1, matrixSize - 1));
    }

    return concatenate_solutions(sub_solutions, distance_matrix, matrixSize);
}

Solution build_two_optimal(Solution solution, const int * distance_matrix, int size) {
    two_optimal_move(solution, distance_matrix, size);
    return solution;
}

Solution two_optimal(Solution &solution, const int * distance_matrix, int size, int strategy) {
    #ifdef VERBOSE
    cout << "[two_optimal] Realizando Busca Local 2-Optimal..." << endl;
    #endif

    Solution best_solution, new_solution;
    clone_solution(solution, best_solution);
    clone_solution(solution, new_solution);
    for (int i = 1; i < size - 1; i++) {
        for (int j = i + 2; j < size; ++j) {
            new_solution = build_two_optimal(solution, distance_matrix, i, j, size);
            if (new_solution.objective_function < best_solution.objective_function) {
                clone_solution(new_solution, best_solution);
                if (strategy == FIRST_IMPROVEMENT) goto END_OF_LOOP;
            }
        }
    }

    END_OF_LOOP:
        return best_solution;
}

Solution two_optimal_2(const int * matriz_distancias, OptimizedMatrix &optimized_matrix, int strategy) {
#ifdef VERBOSE
    cout << "[two_optimal] Realizando Busca Local 2-Optimal_2..." << endl;
#endif

    Solution best_solution = optimized_matrix.get_full_solution().to_normal_solution();
    OptimizedSolution opt_new_solution;

    int size = optimized_matrix.size;

    for (int i = 0; i < size - 1; i++) {
        for (int j = i + 2; j < size; ++j) {
            opt_new_solution = build_two_optimal(optimized_matrix, matriz_distancias, i, j);
            if (opt_new_solution.C < best_solution.objective_function) {
                best_solution = opt_new_solution.to_normal_solution();
                if (strategy == FIRST_IMPROVEMENT) goto END_OF_LOOP;
            }
        }
    }

    END_OF_LOOP:
    return best_solution;
}