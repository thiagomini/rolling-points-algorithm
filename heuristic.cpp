//
// Created by Thiago on 20/03/2021.
//

#define MAX_ITERATIONS 1
#define NUMBER_OF_SOLUTIONS 50

#include <memory>
#include "heuristic.h"
#include "data_structures/solution.h"
#include "utils/array.h"
#include "constructive-heuristic.h"

Solution * random_iterative_heuristic(int * distance_matrix, size_t number_of_vertices) {
    int epoch = 0;
    Solution * solucoes = new Solution[NUMBER_OF_SOLUTIONS];
    int i = 0;

    while (epoch < MAX_ITERATIONS) {
        for (; i < NUMBER_OF_SOLUTIONS; i++) {
            Solution * random_solution = build_random_solution(number_of_vertices, distance_matrix);
            solucoes[i] = random_solution;
        }


    }

    return nullptr;
}
