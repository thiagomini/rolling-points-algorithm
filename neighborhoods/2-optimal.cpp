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

    std::vector<edge> edges_of_solution = extract_edges(solution);

    // Define as arestas que serão removidas
    edge first_removed_edge = edges_of_solution[edge_1];
    edge second_removed_edge = edges_of_solution[edge_2];

    // Define as novas arestas que serão inseridas
    edge new_inserted_edge = {
            first_removed_edge.first_node,
            second_removed_edge.first_node
    };

    edge another_inserted_edge = {
            first_removed_edge.second_node,
            second_removed_edge.second_node
    };

    // Adiciona as novas arestas no vetor de arestas da solução
    edges_of_solution[edge_1] = new_inserted_edge;
    edges_of_solution[edge_2] = another_inserted_edge;

    std::vector<int> new_solution_vertices(size);
    new_solution_vertices.push_back(0);

    int index_of_array = 0,
    max_iterations = (int) edges_of_solution.size();
    edge next_selected_edge;

    // Monta o novo vetor de vértices da solução de acordo com as arestas
    for (int i = 0; i < max_iterations; i++) {
        next_selected_edge = edges_of_solution[index_of_array];

        // Caso a próxima aresta não possua o first_node = ao último vértice adicionado na lista de vértices,
        // é necessário trocar a posição dos nós dessa aresta
        if (i > 0 &&
            next_selected_edge.first_node != new_solution_vertices[i])
        {
            swap_edge(next_selected_edge);
        }

        new_solution_vertices[i + 1] = next_selected_edge.second_node;

        edges_of_solution.erase(edges_of_solution.begin() + index_of_array);
        index_of_array = find_edge_containing_node(edges_of_solution, next_selected_edge.second_node);
        if (index_of_array == -1) break;
    }

    new_solution_vertices.pop_back(); // Remove o vértice "0" do final do vetor de vértices
    memcpy(solution.vertices, new_solution_vertices.data(), sizeof(int) * size);
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