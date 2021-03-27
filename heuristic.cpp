//
// Created by Thiago on 20/03/2021.
//

#define MAX_ITERATIONS 1
#define NUMBER_OF_SOLUTIONS 10

#include <memory>
#include "heuristic.h"
#include "constructive-heuristic.h"

Solution random_iterative_heuristic(int * distance_matrix, size_t number_of_vertices) {
    int epoch = 0;
    int i = 0;

    static Solution best_solution;
    Solution random_solution = build_random_solution(number_of_vertices, distance_matrix);

    clone_solution(random_solution, best_solution);

    while (epoch < MAX_ITERATIONS) {
        for (; i < NUMBER_OF_SOLUTIONS; i++) {
             random_solution = build_random_solution(number_of_vertices, distance_matrix);
            if (compare(best_solution, random_solution) > 0) {
                clone_solution(random_solution, best_solution);
            }
        }
        epoch++;
    }

    #ifdef VERBOSE
        cout << "Melhor Solucao Encontrada: " << endl;
        print_solution(best_solution);
    #endif

    return best_solution;
}

Solution rolling_points_heuristic(int * distance_matrix, size_t number_of_vertices, size_t population) {
    Solution solucoes[population];

    solucoes[0] = build_random_solution(number_of_vertices, distance_matrix);
    Solution best_solution;

    clone_solution(solucoes[0], best_solution);

    // Fase Exploratória
    for (int i = 1; i < population; i++) {
        solucoes[i] = build_random_solution(number_of_vertices, distance_matrix);
        if (compare(best_solution, solucoes[i]) > 0) {
            clone_solution(solucoes[i], best_solution);
        }
    }

    // Busca Local Simples
}
