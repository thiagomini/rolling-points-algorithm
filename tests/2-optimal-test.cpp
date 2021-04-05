//
// Created by Thiago on 03/04/2021.
//

#include <cassert>
#include "../neighborhoods/2-optimal.h"
#include "test-logger.h"

int test_two_optimal_move() {
    print_sub_test_begin("two_optimal_move", "Testando o movimento 2-Optimal de vertices escolhidos");

    // Arrange
    const int distance_matrix[6][6] = {
            {0, 59, 73, 30, 28, 61},
            {59, 0, 19, 45, 32, 42},
            {73, 19, 0, 69, 64, 24},
            {30, 45, 69, 0, 20, 39},
            {28, 32, 64, 20, 0, 87},
            {61, 42, 24, 39, 87, 0},
    };

    Solution solution = {
            .objective_function = 0,
            .size_of_solution = 6,
            .vertices = {0, 1, 2, 3, 4, 5}
    };

    // Act
    two_optimal_move(solution, reinterpret_cast<const int *>(distance_matrix), 0, 3);

    // Assert
    assert(solution.vertices.at(0) == 0);
    assert(solution.vertices.at(1) == 3);
    assert(solution.vertices.at(2) == 2);
    assert(solution.vertices.at(3) == 1);
    assert(solution.vertices.at(4) == 4);
    assert(solution.vertices.at(5) == 5);

    print_sub_test_end();
    return EXIT_SUCCESS;
}

int test_two_optimal_move_random() {
    print_sub_test_begin("two_optimal_move", "Testando o movimento 2-Optimal para vertices aleatorios");

    // Arrange
    const int distance_matrix[6][6] = {
            {0, 59, 73, 30, 28, 61},
            {59, 0, 19, 45, 32, 42},
            {73, 19, 0, 69, 64, 24},
            {30, 45, 69, 0, 20, 39},
            {28, 32, 64, 20, 0, 87},
            {61, 42, 24, 39, 87, 0},
    };

    Solution solution = {
            .objective_function = 0,
            .size_of_solution = 6,
            .vertices = {0, 1, 2, 3, 4, 5}
    };

    // Act
    two_optimal_move(solution, reinterpret_cast<const int *>(distance_matrix));

    // Prepare-Response
    bool has_same_order = solution.vertices.at(0) == 0 &&
            solution.vertices.at(1) == 1 &&
            solution.vertices.at(2) == 2 &&
            solution.vertices.at(3) == 3 &&
            solution.vertices.at(4) == 4 &&
            solution.vertices.at(5) == 5;

    // Assert
    assert(has_same_order == false);
    assert(solution.objective_function != 0);

    print_sub_test_end();
    return EXIT_SUCCESS;
}

int test_two_optimal_local_search() {
    print_sub_test_begin("two_optimal", "Testando a busca local 2-Optimal");

    // Arrange
    const int distance_matrix[4][4] = {
            {0, 59, 73, 30},
            {59, 0, 19, 45},
            {73, 19, 0, 69},
            {30, 45, 69, 0},
    };

    Solution solution = {
            .objective_function = CLASSICAL_PROBLEM ? 284 : 461,
            .size_of_solution = 4,
            .vertices = {0, 1, 2, 3}
    };

    // Act
    two_optimal(solution, reinterpret_cast<const int *>(distance_matrix));

    // Assert
    assert(solution.vertices[0] == 0);

    print_sub_test_end();
    return EXIT_SUCCESS;
}

int test_two_optimal() {
    print_test_begin("2-optimal.cpp");
    test_two_optimal_move();
    test_two_optimal_move_random();
    test_two_optimal_local_search();
    print_test_end("2-optimal.cpp");

    return EXIT_SUCCESS;
}