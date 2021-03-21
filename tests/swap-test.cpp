//
// Created by Thiago on 21/03/2021.
//

#include <cassert>
#include "../neighborhoods/swap.h"
#include "test-logger.h"

int test_swap() {
    print_test_begin("swap.cpp");

    const int distance_matrix[3][3] = {
            {0, 59, 73},
            {59, 0, 19},
            {73, 19, 0}
    };

    int vertices[] = {0, 1, 2};

    Solution solution = {
            .objective_function = 288,
            .size_of_solution = 3,
            .vertices = vertices
    };

    swap(solution, reinterpret_cast<const int *>(distance_matrix));

    bool same_order = solution.vertices[0] == 0 &&
            solution.vertices[1] == 1 &&
            solution.vertices[2] == 2;

    bool same_objective_function = solution.objective_function == 288;

    assert(same_order == false);
    assert(same_objective_function == false);

    print_test_end("swap.cpp");

    return EXIT_SUCCESS;
}



