//
// Created by Thiago on 03/04/2021.
//

#include "edge.h"

std::vector<edge> extract_edges(Solution &solution) {
    std::vector<edge> extracted_edges;
    for (int i = 0; i < solution.size_of_solution; i ++) {
        edge new_edge = {
                .first_node = solution.vertices.at(i),
                .second_node = i == solution.size_of_solution - 1 ? 0 : solution.vertices.at(i+1)
        };
        extracted_edges.push_back(new_edge);
    }

    return extracted_edges;
}

bool edges_are_equal(edge edge_1, edge edge_2) {
    return edge_1.first_node == edge_2.first_node &&
            edge_1.second_node == edge_2.second_node;
}