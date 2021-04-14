//
// Created by Thiago on 03/04/2021.
//

#include "edge.h"

std::vector<edge> extract_edges(Solution &solution) {
    std::vector<edge> extracted_edges(solution.size_of_solution);
    for (int i = 0; i < solution.size_of_solution; i ++) {
        extracted_edges.at(i).first_node = solution.vertices.at(i);
        extracted_edges.at(i).second_node = i == solution.size_of_solution - 1 ? 0 : solution.vertices.at(i+1);
    }

    return extracted_edges;
}

bool edges_are_equal(edge edge_1, edge edge_2) {
    return edge_1.first_node == edge_2.first_node &&
            edge_1.second_node == edge_2.second_node;
}

bool has_consecutive_edge(int *edges, int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = i + 1; j < size; j++) {
            if (abs(edges[i] - edges[j]) <= 1)
                return true;
        }
    }
    return false;
}

edge get_edge(int initial_position, Solution solution) {
    int first_node_position = initial_position;

    if (first_node_position >= solution.size_of_solution) {
        throw "Aresta inexistente";
    }

    int second_node_position = initial_position == solution.size_of_solution - 1
            ? 0
            : initial_position + 1;

    return {
        .first_node = solution.vertices.at(first_node_position),
        .second_node = solution.vertices.at(second_node_position)
    };
}

vector<edge> get_edges(int positions[], int size, const Solution& solution) {
    vector<edge> edges = vector<edge>(size);

    for (int i = 0; i < size; i ++) {
        edges.at(i) = get_edge(positions[i], solution);
    }

    return edges;
}

void swap_edge(edge &edge) {
    int aux = edge.second_node;
    edge.second_node = edge.first_node;
    edge.first_node = aux;
}