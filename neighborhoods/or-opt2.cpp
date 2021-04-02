//
// Created by Thiago on 02/04/2021.
//

#include "or-opt2.h"

void or_switch(Solution &solution, size_t vertex_1, size_t new_position, const int * matriz_distancias) {
    if (solution.size_of_solution <= 3 || new_position == vertex_1 || vertex_1 == 0 || new_position == 0)
        throw "Vertice invalido escolhido para troca";

    size_t next_vertex_position = vertex_1 == solution.size_of_solution - 1 ? 0 : vertex_1 + 1;
    size_t reallocated_vertex_position = next_vertex_position == solution.size_of_solution - 1 ? 0 : next_vertex_position + 1;
    int selected_position_vertex = solution.vertices.at(new_position);

    solution.vertices.at(new_position) = solution.vertices.at(vertex_1);
    solution.vertices.at(new_position + 1) = solution.vertices.at(next_vertex_position);
    solution.vertices.at(reallocated_vertex_position) = selected_position_vertex;

    calculate_objective_function(&solution, matriz_distancias);
}


// Caso 1
// 0, 1, 2, 3, 4
// 1, 2 -> 2

// 0, 3, 1, 2, 4

// Caso 2
// 0, 1, 2, 3, 4
// 3, 4 -> 1

// 0, 3, 4, 1, 2

// Caso 3
// 0, 1, 2, 3, 4
// 1, 2 -> 4

// erro

// Caso 4
// 0, 1, 2, 3, 4
// 0, 1 -> 2

// erro

// Caso 5
// 0, 1, 2, 3, 4
// 3, 4 -> 0

// erro

// Caso 6
// 0, 1, 2, 3, 4, 5
// 1, 2 -> 2

// 0, 3, 1, 2, 4, 5

// Caso 7
// 0, 1, 2, 3, 4, 5
// 4, 5 -> 1

// 0, 4, 5, 1, 2, 3