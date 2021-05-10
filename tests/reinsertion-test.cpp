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

    Solution solution = {
            .objective_function = 0,
            .size_of_solution = 3,
            .vertices = {0, 1, 2}
    };

    // Act
    reinsert(solution, reinterpret_cast<const int *>(distance_matrix));


    // Prepare-Response
    bool same_order = solution.vertices[0] == 0 &&
                      solution.vertices[1] == 1 &&
                      solution.vertices[1] == 2;

    bool same_objective_function = solution.objective_function == 288;

    // Assert
    assert(same_order == false);
    assert(same_objective_function == false);
    assert(solution.vertices[0] == 0);
    print_sub_test_end();

    return EXIT_SUCCESS;
}

/**
 * Testa a vizinhança reinsert quando o primeiro índice é menor que o segundo
 * @return
 */
int test_reinserted_selected_is_smaller() {
    print_sub_test_begin("reinsert", "Testando vizinhanca REINSERT com o primeiro indice escolhido menor que o segundo");

    // Arrange
    const int distance_matrix[4][4] = {
            {0, 59, 73, 30},
            {59, 0, 19, 45},
            {73, 19, 0, 69},
            {30, 45, 69, 0},
    };

    Solution solution = {
            .objective_function = 0,
            .size_of_solution = 4,
            .vertices = {0, 1, 2, 3}
    };

    // Act
    reinsert(solution, 1, 3, reinterpret_cast<const int *>(distance_matrix), 4);

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

/**
 * Testa a vizinhança reinsert quando o primeiro índice é maior que o segundo
 * @return
 */
int test_reinserted_selected_is_greater()  {
    print_sub_test_begin("reinsert", "Testando vizinhanca REINSERT com o primeiro indice escolhido menor que o segundo");

    // Arrange
    const int distance_matrix[4][4] = {
            {0, 59, 73, 30},
            {59, 0, 19, 45},
            {73, 19, 0, 69},
            {30, 45, 69, 0},
    };

    Solution solution = {
            .objective_function = 0,
            .size_of_solution = 4,
            .vertices = {0, 1, 2, 3}
    };

    // Act
    reinsert(solution, 3, 1, reinterpret_cast<const int *>(distance_matrix), 4);

    // Prepare-Response
    int expected_fo = CLASSICAL_PROBLEM ? 199 : 366;

    // Assert
    assert(solution.vertices[0] == 0);
    assert(solution.vertices[1] == 3);
    assert(solution.vertices[2] == 1);
    assert(solution.vertices[3] == 2);
    assert(solution.objective_function == expected_fo);
    print_sub_test_end();

    return EXIT_SUCCESS;
}

/**
 * Testa a busca local reinserindo cada nó em uma nova posição
 * @return 0 se o teste passou
 * @throws assertion_failed caso o teste não passe
 */
int test_reinserted_opt() {
    print_sub_test_begin("reinsert_opt", "Testando busca local REINSERT_OPT");

    // Arrange
    const int distance_matrix[3][3] = {
            {0, 59, 73},
            {59, 0, 19},
            {73, 19, 0}
    };

    Solution solution = {
            .objective_function = CLASSICAL_PROBLEM ? 165 : 316,
            .size_of_solution = 3,
            .vertices = {0, 2, 1}
    };

    // Act
    Solution best_solution = reinsert_opt(solution, reinterpret_cast<const int *>(distance_matrix), 3);

    // Prepare-Response
    int expected_fo = CLASSICAL_PROBLEM ? 137 : 288;

    // Assert
    assert(best_solution.vertices[0] == 0);
    assert(best_solution.vertices[1] == 1);
    assert(best_solution.vertices[2] == 2);
    assert(best_solution.objective_function == expected_fo);
    print_sub_test_end();

    return EXIT_SUCCESS;
}


/**
 * Testa a busca local reinserindo cada nó em uma nova posição
 * @return 0 se o teste passou
 * @throws assertion_failed caso o teste não passe
 */
int test_reinserted_opt_first_improvement() {
    print_sub_test_begin("reinsert_opt", "Testando busca local REINSERT_OPT (primeira melhora)");

    // Arrange
    const int distance_matrix[4][4] = {
            {0, 59, 73, 30},
            {59, 0, 19, 45},
            {73, 19, 0, 69},
            {30, 45, 69, 0},
    };

    Solution solution = {
            .objective_function = CLASSICAL_PROBLEM ? 302 : 469,
            .size_of_solution = 4,
            .vertices = {0, 2, 1, 3}
    };


    // Act
    Solution best_solution = reinsert_opt(solution, reinterpret_cast<const int *>(distance_matrix), 4);

    // Prepare-Response
    int expected_fo = CLASSICAL_PROBLEM ? 284 : 461;

    // Assert
    assert(best_solution.vertices[0] == 0);
    assert(best_solution.vertices[1] == 1);
    assert(best_solution.vertices[2] == 2);
    assert(best_solution.vertices[3] == 3);
    assert(best_solution.objective_function == expected_fo);
    print_sub_test_end();

    return EXIT_SUCCESS;
}


int test_reinsert() {
    print_test_begin("reinsertion.cpp");
    test_reinserted_selected_is_smaller();
    test_reinserted_selected_is_greater();
    test_reinsert_random();
    test_reinserted_opt();
    test_reinserted_opt_first_improvement();
    print_test_end("reinsertion.cpp");

    return EXIT_SUCCESS;
}



