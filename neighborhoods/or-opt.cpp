//
// Created by Thiago on 02/04/2021.
//

#include "or-opt.h"
#include "../utils/randomizer.h"
#include "../utils/distance.h"

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

OptimizedSolution build_or_opt_n(OptimizedMatrix optimized_matrix, int vertex_1, int new_position, const int * matriz_distancias, int n) {
    int size_of_solution = optimized_matrix.size;
    if ( size_of_solution <= n + 1 ||
        new_position == vertex_1 ||
        vertex_1 == 0 ||
        new_position <= 0 ||
        new_position >= (size_of_solution - (n - 1))
            ) {
        throw "Vertice invalido escolhido para troca";
    }

    int difference = DIFF(new_position, vertex_1);
    int greater_index, lower_index;

    int position_after_tuple = vertex_1 + n; // Posição logo após a tupla selecionada

    if (new_position > vertex_1) {
        greater_index = new_position;
        lower_index = vertex_1;
    } else {
        greater_index = vertex_1;
        lower_index = new_position;
    }

    std::vector<OptimizedSolution> sub_solutions;
    sub_solutions.reserve(5);

    sub_solutions.push_back(optimized_matrix.get_solution(0, lower_index - 1));

    if (new_position == greater_index) {
        sub_solutions.push_back(optimized_matrix.get_solution(position_after_tuple, position_after_tuple + difference - 1));
        sub_solutions.push_back(optimized_matrix.get_solution(lower_index, lower_index + n - 1));
        if (greater_index + n <= size_of_solution - 1) {
            sub_solutions.push_back(optimized_matrix.get_solution(greater_index + n, size_of_solution - 1));
        }
    } else {
        sub_solutions.push_back(optimized_matrix.get_solution(vertex_1, vertex_1 + n - 1));
        sub_solutions.push_back(optimized_matrix.get_solution(new_position, new_position + difference - 1));
        if (lower_index + n + difference <= size_of_solution - 1) {
            sub_solutions.push_back(optimized_matrix.get_solution(lower_index + n + difference, size_of_solution - 1));
        }
    }

    return concatenate_solutions(sub_solutions, matriz_distancias, size_of_solution);
}

Solution build_or_opt_n(Solution solution, const int * matriz_distancias, int n, int size) {
    or_switch(solution, matriz_distancias, n, size);
    return solution;
}

Solution or_opt_n(Solution &solution, const int * matriz_distancias, int n, int size, int strategy) {
    #ifdef VERBOSE
        cout << "[or_opt_n] Realizando Busca Local or_opt" << n << "..." << endl;
    #endif
    Solution best_solution, new_solution_1;
    clone_solution(solution, best_solution);

    for (int i = 1; i < size - n; i++) {
        for (int j = i + 1; j < size - (n - 1); j++) {
            new_solution_1 = build_or_opt_n(solution, i, j, matriz_distancias, n, size);

            if (new_solution_1.objective_function < best_solution.objective_function) {
                clone_solution(new_solution_1, best_solution);
                if (strategy == FIRST_IMPROVEMENT) goto END_OF_LOOP;
            }

        }
    }
    END_OF_LOOP:
    return best_solution;
}

Solution or_opt_n_2(const int * matriz_distancias, OptimizedMatrix &optimized_matrix, int n, int strategy) {
#ifdef VERBOSE
    cout << "[or_opt_n_2] Realizando Busca Local or_opt" << n << "..." << endl;
#endif
    Solution
    best_solution,
    solution = optimized_matrix
        .get_full_solution()
        .to_normal_solution();

    int size = optimized_matrix.size;

    clone_solution(solution, best_solution);

    for (int i = 1; i < size - n; i++) {
        for (int j = i + 1; j < size - (n - 1); j++) {
            OptimizedSolution opt_new_solution_1 = build_or_opt_n(optimized_matrix, i, j, matriz_distancias, n);
            OptimizedSolution opt_new_solution_2 = build_or_opt_n(optimized_matrix, j, i, matriz_distancias, n);

            if (opt_new_solution_1.C < best_solution.objective_function) {
                best_solution = opt_new_solution_1.to_normal_solution();
                if (strategy == FIRST_IMPROVEMENT) goto END_OF_LOOP;
            } else if (opt_new_solution_2.C < best_solution.objective_function) {
                best_solution = opt_new_solution_2.to_normal_solution();
                if (strategy == FIRST_IMPROVEMENT) goto END_OF_LOOP;
            }
        }
    }
    END_OF_LOOP:
    return best_solution;
}

