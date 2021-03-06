//
// Created by Thiago on 20/03/2021.
//

#define MAX_ITERATIONS 1
#define NUMBER_OF_SOLUTIONS 10

#include "heuristic.h"
#include "constructive-heuristic.h"
#include "neighborhoods/neighborhood-generator.h"
#include "neighborhoods/2-optimal.h"
#include "utils/energy.h"

Solution random_iterative_heuristic(int * distance_matrix, size_t number_of_vertices) {
    int epoch = 0;
    int i = 0;

    static Solution best_solution;
    Solution random_solution = build_random_solution(distance_matrix, number_of_vertices);

    clone_solution(random_solution, best_solution);

    while (epoch < MAX_ITERATIONS) {
        for (; i < NUMBER_OF_SOLUTIONS; i++) {
             random_solution = build_random_solution(distance_matrix, number_of_vertices);
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

    solucoes[0] = build_random_solution(distance_matrix, (int) number_of_vertices);
    Solution best_solution;

    #ifdef VERBOSE
        cout << "[rolling_points_heuristic] Construindo Solucoes Aleatorias..." << endl;
    #endif

    // Fase Exploratória
    for (int i = 1; i < population; i++) {
        solucoes[i] = build_random_solution(distance_matrix, (int) number_of_vertices);
    }

    #ifdef VERBOSE
        cout << "[rolling_points_heuristic] Buscando Vizinhancas..." << endl;
    #endif
    // Busca Local Simples
    Solution neighbor;
    double energy = INITIAL_VELOCITY * DEFAULT_MASS;
    for (int i = 0; i < population; i++) {
        while (energy > 0) {
            double last_fo = solucoes[i].objective_function;
            neighbor = random_local_search(solucoes[i], distance_matrix, (int) number_of_vertices);
            double current_fo = neighbor.objective_function;
            if (compare(solucoes[i], neighbor) > 0) {
                clone_solution(neighbor, solucoes[i]);
            }
            energy += calculate_energy(DEFAULT_MASS, current_fo, last_fo);
//            cout << "Novo valor de energia: " << energy << endl;
        }

    }

    #ifdef VERBOSE
        cout << "[rolling_points_heuristic] Ordenando as solucoes encontradas..." << endl;
    #endif
    // Busca a melhor solução
    qsort(solucoes, population, sizeof(Solution), reinterpret_cast<int (*)(const void *, const void *)>(compare));
    clone_solution(solucoes[0], best_solution);


    #ifdef VERBOSE
        cout << "[rolling_points_heuristic] Realizando busca local profunda..." << endl;
    #endif

    // Busca local profunda
    best_solution = random_variable_neighborhood_descent(best_solution, distance_matrix, (int) number_of_vertices);

    #ifdef VERBOSE
        cout << "Melhor Solucao Encontrada: " << endl;
        print_solution(&best_solution);
    #endif

    return best_solution;
}
