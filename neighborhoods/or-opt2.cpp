//
// Created by Thiago on 02/04/2021.
//

#include "or-opt2.h"

void or_switch(Solution &solution, size_t vertex_1, size_t new_position, const int * matriz_distancias) {
    if (solution.size_of_solution <= 3 ||
    new_position == vertex_1 ||
    vertex_1 == 0 ||
    new_position == 0 ||
    new_position >= solution.size_of_solution - 1
    ) {
        throw "Vertice invalido escolhido para troca";
    }
    int vertex_in_initial_position = solution.vertices.at(vertex_1);
    int adjacent_vertex = solution.vertices.at(vertex_1 + 1);

    if (new_position > vertex_1) {
        for (int i = (int) vertex_1; i < new_position; i++)
            solution.vertices.at(i) = solution.vertices.at(i + 2);

    } else {
        for (int i = (int) vertex_1 + 1; i > new_position + 1; i--)
            solution.vertices.at(i) = solution.vertices.at(i - 2);

    }

    solution.vertices.at(new_position) = vertex_in_initial_position;
    solution.vertices.at(new_position + 1) = adjacent_vertex;

    calculate_objective_function(&solution, matriz_distancias);
}