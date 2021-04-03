//
// Created by Thiago on 02/04/2021.
//

#include "or-opt2.h"
#include "../utils/randomizer.h"

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

void or_switch(Solution &solution, const int * matriz_distancias) {
    size_t random_vertex = RANDOM_BETWEEN(1, solution.size_of_solution - 2);
    size_t random_new_position = RANDOM_BETWEEN(1, solution.size_of_solution - 2);

    while (random_new_position == random_vertex) {
        random_new_position = RANDOM_BETWEEN(1, solution.size_of_solution - 2);
    }

    or_switch(solution, random_vertex, random_new_position, matriz_distancias);
}

Solution or_opt2(Solution &solution, const int * matriz_distancias) {
    int best_value = solution.objective_function;

    Solution best_solution;

    for (int i = 1; i < solution.size_of_solution - 2; i++) {
        for (int j = i + 1; j < solution.size_of_solution - 1; j++) {
            or_switch(solution, i, j, matriz_distancias);

            if (solution.objective_function < best_value) {
                best_value = solution.objective_function;
                clone_solution(solution, best_solution);
            }
        }
    }

    return best_solution;
}