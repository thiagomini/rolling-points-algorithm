//
// Created by Thiago on 22/03/2021.
//


#include <cassert>
#include "../neighborhoods/reinsertion.h"
#include "test-logger.h"

/**
 * Testa a função reinsert com posições aleatórias
 * @return
 */
int test_reinsert_random() {
    print_sub_test_begin("reinsert", "Testando vizinhanca REINSERT com indices aleatorios");

    // Arrange
    const int distance_matrix[3][3] = {
            {0, 59, 73},
            {59, 0, 19},
            {73, 19, 0}
    };

    int vertices[] = {0, 1, 2};

    Solution solution = {
            .objective_function = 0,
            .size_of_solution = 3,
            .vertices = vertices
    };

    // Act
    reinsert(solution, reinterpret_cast<const int *>(distance_matrix));


    // Prepare-Response
    bool same_order = solution.vertices[0] == 0 &&
                      solution.vertices[1] == 1 &&
                      solution.vertices[2] == 2;

    bool same_objective_function = solution.objective_function == 288;

    // Assert
    assert(same_order == false);
    assert(same_objective_function == false);
    assert(solution.vertices[0] == 0);
    print_sub_test_end();

    return EXIT_SUCCESS;
}

/**
 * Testa a função reinsert com posições passadas como parâmetro
 * @return
 */
int test_reinserted_selected() {
    print_sub_test_begin("reinsert", "Testando vizinhanca REINSERT com indices escolhidos");

    // Arrange
    const int distance_matrix[4][4] = {
            {0, 59, 73, 30},
            {59, 0, 19, 45},
            {73, 19, 0, 69},
            {30, 45, 69, 0},
    };

    int vertices[] = {0, 1, 2, 3};

    Solution solution = {
            .objective_function = 0,
            .size_of_solution = 4,
            .vertices = vertices
    };

    // Act
    reinsert(solution, 1, 3, reinterpret_cast<const int *>(distance_matrix));

    // Prepare-Response
    int expected_fo = CLASSICAL_PROBLEM ? 402 : 648;

    // Assert
    assert(solution.vertices[0] == 0);
    assert(solution.vertices[1] == 2);
    assert(solution.vertices[2] == 3);
    assert(solution.vertices[3] == 1);
    assert(solution.objective_function == expected_fo);
    print_sub_test_end();

    return EXIT_SUCCESS;
}

int test_reinsert() {
    print_test_begin("reinsertion.cpp");
    test_reinsert_random();
    test_reinserted_selected();
    print_test_end("reinsertion.cpp");

    return EXIT_SUCCESS;
}



