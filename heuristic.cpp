//
// Created by Thiago on 20/03/2021.
//

#define MAX_ITERATIONS 1
#define NUMBER_OF_SOLUTIONS 50

#include <memory>
#include "heuristic.h"
#include "constructive-heuristic.h"

Solution * random_iterative_heuristic(int * distance_matrix, size_t number_of_vertices) {
    int epoch = 0;
    auto * solucoes = new Solution[NUMBER_OF_SOLUTIONS];
    int i = 0;
    Solution * best_solution = nullptr;
    Solution * best_solution_of_iteration;

    while (epoch < MAX_ITERATIONS) {
        for (; i < NUMBER_OF_SOLUTIONS; i++) {
            Solution random_solution = build_random_solution(number_of_vertices, distance_matrix);
            solucoes[i] = random_solution;
        }
        qsort(solucoes, NUMBER_OF_SOLUTIONS, sizeof(Solution),
              reinterpret_cast<int (*)(const void *, const void *)>(compare));

        best_solution_of_iteration = &solucoes[0];

        if (best_solution == nullptr) {
            best_solution = best_solution_of_iteration;
        } else {
            if (compare(best_solution_of_iteration, best_solution) > 0) {
                best_solution = best_solution_of_iteration;
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
