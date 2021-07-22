//
// Created by Thiago on 11/05/2021.
//

#include <cassert>
#include "../data_structures/optmized-matrix.h"
#include "test-logger.h"

int test_build_opt_matrix() {
    print_sub_test_begin("build_opt_matrix", "Testando criacao de matriz otimizada");

    // Arrange
    int vertices[3] = {0, 1, 2};

    int distance_matrix[3][3] = {
            {0, 59, 73},
            {59, 0, 19},
            {73, 19, 0}
    };

    // Act
    OptimizedMatrix opt_matrix = build_opt_matrix(vertices, reinterpret_cast<const int *>(distance_matrix), 3);

    // Assert
    // Todo considerar quando o problema não é o clássico

    assert(opt_matrix.get_solution(0, 0).equals(0, 0, 0, 1, std::vector<int>{ 0 }));
    assert(opt_matrix.get_solution(1, 0).equals(0, 59, 1, 2, {1, 0}));
    assert(opt_matrix.get_solution(2, 0).equals(19, 78, 2, 3, {2, 1, 0}));

    assert(opt_matrix.get_solution(0, 1).equals(59, 59, 1, 2, {0, 1}));
    assert(opt_matrix.get_solution(1, 1).equals(0, 0, 1, 1, {1}));
    assert(opt_matrix.get_solution(2, 1).equals(19, 19, 2, 2, {2, 1}));

    assert(opt_matrix.get_solution(0, 2).equals(137, 78, 2, 3, {0, 1, 2}));
    assert(opt_matrix.get_solution(1, 2).equals(19, 19, 2, 2, {1, 2}));
    assert(opt_matrix.get_solution(2, 2).equals(0, 0, 1, 1, {2}));
    print_sub_test_end();

    return EXIT_SUCCESS;
}

int test_opt_matrix() {
    print_test_begin("optimized-matrix.cpp");
    test_build_opt_matrix();
//    test_get_full_solution();
    print_test_end("optimized-matrix.cpp");
    return EXIT_SUCCESS;
}