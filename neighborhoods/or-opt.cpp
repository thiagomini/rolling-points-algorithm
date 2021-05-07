//
// Created by Thiago on 02/04/2021.
//

#include "or-opt.h"
#include "../utils/randomizer.h"

void
or_switch(Solution &solution, size_t vertex_1, size_t new_position, const int *matriz_distancias, int n, int size) {
    if (size <= n + 1 ||
    new_position == vertex_1 ||
    vertex_1 == 0 ||
    new_position == 0 ||
    new_position >= (size - (n - 1))
    ) {
        throw "Vertice invalido escolhido para troca";
    }
    int vertex_in_initial_position = solution.vertices[vertex_1];
    vector<int> adjacent_vertices = slice(solution.vertices,(int) vertex_1 + 1, (int) vertex_1 + (n - 1));

    if (new_position > vertex_1) {
        for (int i = (int) vertex_1; i < new_position; i++)
            solution.vertices[i] = solution.vertices[i + n];

    } else {
        for (int i = (int) vertex_1 + 1; i > new_position + 1; i--)
            solution.vertices[i] = solution.vertices[i - n];

    }

    solution.vertices[new_position] = vertex_in_initial_position;

    for (int i = new_position; i < new_position + (n - 1); i++) {
        solution.vertices[i + 1] = adjacent_vertices.front();
        adjacent_vertices.erase(adjacent_vertices.cbegin());
    }

    calculate_objective_function(&solution, matriz_distancias, size);
}

void or_switch(Solution &solution, const int *matriz_distancias, int n, int size) {
    size_t random_vertex = RANDOM_BETWEEN(1, size - n);
    size_t random_new_position = RANDOM_BETWEEN(1, size - n);

    while (random_new_position == random_vertex) {
        random_new_position = RANDOM_BETWEEN(1, size - n);
    }

    or_switch(solution, random_vertex, random_new_position, matriz_distancias, n, size);
}

Solution build_or_opt_n(Solution solution, size_t vertex_1, size_t new_position, const int * matriz_distancias, int n, int size) {
    or_switch(solution, vertex_1, new_position, matriz_distancias, n, size);
    return solution;
}

Solution build_or_opt_n(Solution solution, const int * matriz_distancias, int n, int size) {
    or_switch(solution, matriz_distancias, n, size);
    return solution;
}

Solution or_opt_n(Solution &solution, const int * matriz_distancias, int n, int size, int strategy) {
    #ifdef VERBOSE
        cout << "[or_opt_n] Realizando Busca Local or_opt" << n << "..." << endl;
    #endif
    Solution best_solution, new_solution;
    clone_solution(solution, best_solution);
    clone_solution(solution, new_solution);

    for (int i = 1; i < size - n; i++) {
        for (int j = i + 1; j < size - (n - 1); j++) {
            new_solution = build_or_opt_n(solution, i, j, matriz_distancias, n, size);

            if (new_solution.objective_function < best_solution.objective_function) {
                clone_solution(new_solution, best_solution);
                if (strategy == FIRST_IMPROVEMENT) goto END_OF_LOOP;
            }
        }
    }
    END_OF_LOOP:
        return best_solution;
}