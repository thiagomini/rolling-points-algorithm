//
// Created by Thiago on 02/04/2021.
//

#include "or-opt.h"
#include "../utils/randomizer.h"

void or_switch(Solution &solution, size_t vertex_1, size_t new_position, const int * matriz_distancias, int n) {
    if (solution.size_of_solution <= n + 1 ||
    new_position == vertex_1 ||
    vertex_1 == 0 ||
    new_position == 0 ||
    new_position >= (solution.size_of_solution - (n - 1))
    ) {
        throw "Vertice invalido escolhido para troca";
    }
    int vertex_in_initial_position = solution.vertices.at(vertex_1);
    vector<int> adjacent_vertices = slice(solution.vertices,(int) vertex_1 + 1, (int) vertex_1 + (n - 1));

    if (new_position > vertex_1) {
        for (int i = (int) vertex_1; i < new_position; i++)
            solution.vertices.at(i) = solution.vertices.at(i + n);

    } else {
        for (int i = (int) vertex_1 + 1; i > new_position + 1; i--)
            solution.vertices.at(i) = solution.vertices.at(i - n);

    }

    solution.vertices.at(new_position) = vertex_in_initial_position;

    for (int i = new_position; i < new_position + (n - 1); i++) {
        solution.vertices.at(i + 1) = adjacent_vertices.front();
        adjacent_vertices.erase(adjacent_vertices.cbegin());
    }

    calculate_objective_function(&solution, matriz_distancias);
}

void or_switch(Solution &solution, const int * matriz_distancias, int n) {
    size_t random_vertex = RANDOM_BETWEEN(1, solution.size_of_solution - n);
    size_t random_new_position = RANDOM_BETWEEN(1, solution.size_of_solution - n);

    while (random_new_position == random_vertex) {
        random_new_position = RANDOM_BETWEEN(1, solution.size_of_solution - n);
    }

    or_switch(solution, random_vertex, random_new_position, matriz_distancias, n);
}

Solution build_or_opt_n(Solution solution, size_t vertex_1, size_t new_position, const int * matriz_distancias, int n) {
    or_switch(solution, vertex_1, new_position, matriz_distancias, n);
    return solution;
}

Solution build_or_opt_n(Solution solution, const int * matriz_distancias, int n) {
    or_switch(solution, matriz_distancias, n);
    return solution;
}

Solution or_opt_n(Solution &solution, const int * matriz_distancias, int n) {
    #ifdef VERBOSE
        cout << "[or_opt_n] Realizando Busca Local or_opt" << n << "..." << endl;
    #endif
    Solution best_solution, new_solution;
    clone_solution(solution, best_solution);
    clone_solution(solution, new_solution);

    for (int i = 1; i < solution.size_of_solution - n; i++) {
        for (int j = i + 1; j < solution.size_of_solution - (n - 1); j++) {
            new_solution = build_or_opt_n(solution, i, j, matriz_distancias, n);

            if (new_solution.objective_function < best_solution.objective_function) {
                clone_solution(new_solution, best_solution);
            }
        }
    }

    return best_solution;
}