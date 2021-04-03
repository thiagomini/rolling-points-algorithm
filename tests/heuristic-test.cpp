//
// Created by Thiago on 21/03/2021.
//

#include <cassert>
#include "../heuristic.h"
#include "test-logger.h"
#include "../configurations.h"


int test_random_iterative_heuristic() {
    print_sub_test_begin("random_iterative_heuristic", "Testando execucao de Heuristica Aleatoria");
    int distance_matrix[3][3] = {
            {0, 59, 73},
            {59, 0, 19},
            {73, 19, 0}
    };

    int best_fo = CLASSICAL_PROBLEM ? 137 : 288;

    Solution best_solution = random_iterative_heuristic(reinterpret_cast<int *>(distance_matrix), 3);
    assert(best_solution.objective_function == best_fo);
    assert(best_solution.vertices[0] == 0);
    assert(best_solution.vertices[1] == 1);
    assert(best_solution.vertices[2] == 2);

    print_sub_test_end();
    return EXIT_SUCCESS;
}

int test_rolling_points_heuristic() {
    print_sub_test_begin("rolling_points_heuristic", "Testando execucao da Rolling Points Heiristic");
    int distance_matrix[3][3] = {
            {0, 59, 73},
            {59, 0, 19},
            {73, 19, 0}
    };

    int best_fo = CLASSICAL_PROBLEM ? 137 : 288;

    Solution best_solution = rolling_points_heuristic(reinterpret_cast<int *>(distance_matrix), 3);
    assert(best_solution.objective_function == best_fo);
    assert(best_solution.vertices[0] == 0);
    assert(best_solution.vertices[1] == 1);
    assert(best_solution.vertices[2] == 2);

    print_sub_test_end();
    return EXIT_SUCCESS;
}

int test_heuristic() {
    print_test_begin("heuristic.cpp");
    test_random_iterative_heuristic();
//    test_rolling_points_heuristic();
    print_test_end("heuristic.cpp");
    return EXIT_SUCCESS;
}

