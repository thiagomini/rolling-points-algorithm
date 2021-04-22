//
// Created by Thiago on 21/04/2021.
//

#include <cassert>
#include "../data_structures/OptMatrix.h"
#include "test-logger.h"

int test_opt_matrix_construction() {
    print_sub_test_begin("OptMatrix", "Testando criação de matriz otimizada");

    // Arrange
    vector<int> vertices = {0, 1, 2};

    int distances[3][3] = {
            {0, 59, 73},
            {59, 0, 19},
            {73, 19, 0}
    };

    distance_matrix distance_matrix = {
            .distances = reinterpret_cast<int *>(distances),
            .size = 3
    };

    // Act
    OptMatrix opt_matrix = OptMatrix(3, vertices, distance_matrix);

    // Assert
    // Todo considerar quando o problema não é o clássico

    assert(opt_matrix.get_solution(0, 0).equals(OptSolution(0, 0, 0, {0})));
    assert(opt_matrix.get_solution(1, 0).equals(OptSolution(0, 1, 59, {1, 0})));
    assert(opt_matrix.get_solution(2, 0).equals(OptSolution(19, 2, 78, {2, 1, 0})));

    assert(opt_matrix.get_solution(0, 1).equals(OptSolution(59, 1, 59, {0, 1})));
    assert(opt_matrix.get_solution(1, 1).equals(OptSolution(0, 1, 0, {1})));
    assert(opt_matrix.get_solution(2, 1).equals(OptSolution(19, 2, 19, {2, 1})));

    assert(opt_matrix.get_solution(0, 2).equals(OptSolution(137, 2, 78, {0, 1, 2})));
    assert(opt_matrix.get_solution(1, 2).equals(OptSolution(19, 2, 19, {1, 2})));
    assert(opt_matrix.get_solution(2, 2).equals(OptSolution(0, 1, 0, {2})));
    print_sub_test_end();

    return EXIT_SUCCESS;
    }


int test_opt_matrix() {
    print_test_begin("OptMatrix.cpp");
    test_opt_matrix_construction();
    print_test_end("OptMatrix.cpp");
    return EXIT_SUCCESS;
}

