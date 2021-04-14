//
// Created by Thiago on 13/04/2021.
//

#include "double-bridge.h"
#include "../data_structures/edge.h"


Solution generate_double_bridge(Solution solution, const int * distance_matrix, int edge_1, int edge_2, int edge_3, int edge_4) {
    Solution new_solution;
    clone_solution(solution, new_solution);

    int edges[4] = {edge_1, edge_2, edge_3, edge_4};
    if (has_consecutive_edge(edges, 4)) {
        throw "Arestas nao podem ser consecutivas!";
    }

    vector<edge> edges_of_solution = extract_edges(solution);
    vector<edge> excluded_edges = get_edges(edges, 4, solution);

    // Movimento AcbD


}

void execute_double_bridge(Solution &solution, const int * distance_matrix) {

}
