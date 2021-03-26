//
// Created by Thiago on 20/03/2021.
//

#define MAX_ITERATIONS 1
#define NUMBER_OF_SOLUTIONS 10

#include <memory>
#include "heuristic.h"
#include "constructive-heuristic.h"
#include "configurations.h"

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

Solution * rolling_points_heuristic(int * distance_matrix, size_t number_of_vertices) {
    Solution solucoes[NUMBER_OF_SOLUTIONS];
    Solution best_solution, best_solution_of_iteration;


}
