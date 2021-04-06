//
// Created by Thiago on 20/03/2021.
//

#define MAX_ITERATIONS 1
#define NUMBER_OF_SOLUTIONS 10

#include <memory>
#include "heuristic.h"
#include "constructive-heuristic.h"
#include "neighborhoods/neighborhood-generator.h"
#include "neighborhoods/swap.h"
#include "neighborhoods/reinsertion.h"
#include "neighborhoods/or-opt.h"
#include "neighborhoods/2-optimal.h"

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
        print_solution(&best_solution);
    #endif

    return best_solution;
}

Solution rolling_points_heuristic(const int *distance_matrix, size_t number_of_vertices, size_t population) {
    Solution solucoes[population];

    solucoes[0] = build_random_solution(number_of_vertices, distance_matrix);
    Solution best_solution;

    // Fase Exploratória
    for (int i = 1; i < population; i++) {
        solucoes[i] = build_random_solution(number_of_vertices, distance_matrix);
    }

    // Busca Local Simples
    Solution neighbor;
    for (int i = 0; i < population; i++) {
        try {
            neighbor = generate_random_neighbor(solucoes[i], distance_matrix);
        } catch (const char * error) {
            cerr << error << endl;
            exit(EXIT_FAILURE);
        }

        if (compare(solucoes[i], neighbor) > 0) {
            solucoes[i] = neighbor;
        }
    }

    // Busca a melhor solução
    qsort(solucoes, population, sizeof(Solution), reinterpret_cast<int (*)(const void *, const void *)>(compare));
    clone_solution(solucoes[0], best_solution);

    // Busca local profunda
    best_solution = swap_opt(best_solution, distance_matrix);
    best_solution = reinsert_opt(best_solution, distance_matrix);
    best_solution = or_opt_n(best_solution, distance_matrix);
    best_solution = two_optimal(best_solution, distance_matrix);

    #ifdef VERBOSE
        cout << "Melhor Solucao Encontrada: " << endl;
        print_solution(&best_solution);
    #endif

    return best_solution;
}
