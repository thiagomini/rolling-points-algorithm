//
// Created by Thiago on 21/03/2021.
//

#include <cassert>
#include "../neighborhoods/swap.h"
#include "test-logger.h"
#include "../configurations.h"

/**
 * Testa a função swap com posições aleatórias
 * @return
 */
int test_swap_random() {
    print_sub_test_begin("swap", "Testando vizinhanca SWAP com indices aleatorios");

    // Arrange
    const int distance_matrix[3][3] = {
            {0, 59, 73},
            {59, 0, 19},
            {73, 19, 0}
    };

    Solution solution = {
            .objective_function = 288,
            .size_of_solution = 3,
            .vertices = {0, 1, 2}
    };

    // Act
    swap(solution, reinterpret_cast<const int *>(distance_matrix));


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

int test_swap_opt() {
    print_sub_test_begin("swap_opt", "Testando busca local SWAP-OPT");

    // Arrange
    const int distance_matrix[3][3] = {
            {0, 59, 73},
            {59, 0, 19},
            {73, 19, 0}
    };

    Solution solution = {
            .objective_function = 165,
            .size_of_solution = 3,
            .vertices = {0, 2, 1}
    };

    // Act
    Solution best_solution = swap_opt(solution, reinterpret_cast<const int *>(distance_matrix));


    // Assert
    assert(best_solution.objective_function == 137);
    assert(best_solution.vertices[0] == 0);
    assert(best_solution.vertices[1] == 1);
    assert(best_solution.vertices[2] == 2);

    print_sub_test_end();

    return EXIT_SUCCESS;
}

/**
 * Testa a função swap com posições passadas como parâmetro
 * @return
 */
int test_swap_selected() {
    print_sub_test_begin("swap", "Testando vizinhanca SWAP com indices escolhidos");

    // Arrange
    const int distance_matrix[3][3] = {
            {0, 59, 73},
            {59, 0, 19},
            {73, 19, 0}
    };

    Solution solution = {
            .objective_function = 288,
            .size_of_solution = 3,
            .vertices = {0, 1, 2}
    };

    // Act
    swap(solution, 1, 2, reinterpret_cast<const int *>(distance_matrix));


    // Prepare-Response
    int expected_fo = CLASSICAL_PROBLEM ? 165 : 316;

    // Assert
    assert(solution.objective_function == expected_fo);
    assert(solution.vertices[0] == 0);
    assert(solution.vertices[1] == 2);
    assert(solution.vertices[2] == 1);
    print_sub_test_end();

    return EXIT_SUCCESS;
}

int test_swap() {
    print_test_begin("swap.cpp");
    test_swap_random();
    test_swap_selected();
    test_swap_opt();
    print_test_end("swap.cpp");

    return EXIT_SUCCESS;
}



