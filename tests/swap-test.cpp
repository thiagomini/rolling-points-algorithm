//
// Created by Thiago on 21/03/2021.
//

#include <cassert>
#include "../neighborhoods/swap.h"
#include "test-logger.h"

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
    swap(solution, reinterpret_cast<const int *>(distance_matrix), 3);


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
    print_sub_test_begin("swap_opt", "Testando busca local SWAP-OPT (melhor melhora)");

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
    Solution best_solution = swap_opt(solution, reinterpret_cast<const int *>(distance_matrix), 3);


    // Assert
    assert(best_solution.objective_function == (CLASSICAL_PROBLEM ? 137 : 288));
    assert(best_solution.vertices[0] == 0);
    assert(best_solution.vertices[1] == 1);
    assert(best_solution.vertices[2] == 2);

    print_sub_test_end();

    return EXIT_SUCCESS;
}

int test_swap_opt_2() {
    print_sub_test_begin("swap_opt_2", "Testando busca local SWAP-OPT-2 (melhor melhora)");

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

    OptimizedMatrix optimized_matrix = build_opt_matrix(solution.vertices,
                                                        reinterpret_cast<const int *>(distance_matrix), 3);

    // Act
    Solution best_solution = swap_opt_2(solution, reinterpret_cast<const int *>(distance_matrix), optimized_matrix,3);


    // Assert
    assert(best_solution.objective_function == (CLASSICAL_PROBLEM ? 137 : 288));
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
    swap(solution, 1, 2, reinterpret_cast<const int *>(distance_matrix), 3);


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

int test_swap_opt_first_improvement() {
    print_sub_test_begin("swap_opt", "Testando busca local SWAP-OPT (primeira melhora)");

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
    Solution best_solution = swap_opt(solution, reinterpret_cast<const int *>(distance_matrix), 4, FIRST_IMPROVEMENT);


    // Assert
    assert(best_solution.objective_function == (CLASSICAL_PROBLEM ? 247 : 424));
    assert(best_solution.vertices[0] == 0);
    assert(best_solution.vertices[1] == 3);
    assert(best_solution.vertices[2] == 2);
    assert(best_solution.vertices[3] == 1);

    print_sub_test_end();

    return EXIT_SUCCESS;
}

int test_build_swap_opt_solution_1_and_2() {
    print_sub_test_begin("build_swap", "Criando vizinhanca swap para vertices 1 e 2 (OptimizedSolution)");

    // Arrange
    int distances[5][5] = {
            {0, 59, 73, 55, 33},
            {59, 0, 19, 9, 43},
            {73, 19, 0, 19, 49},
            { 55, 9, 19, 0, 35},
            {33, 43, 49, 35, 0},
    };

    int vertices[5] = {0, 1, 2, 3, 4};

    OptimizedMatrix opt_matrix = build_opt_matrix(vertices, reinterpret_cast<const int *>(distances), 5);

    // Act
    OptimizedSolution swapped_solution = build_swap(opt_matrix, 1, 2, reinterpret_cast<const int *>(distances));

    // Prepare-Response
    int result_array[5] = {0, 2, 1, 3, 4};

    // Assert
    assert(arrays_are_equal(swapped_solution.vertices, result_array, 5));
    assert(swapped_solution.C == (CLASSICAL_PROBLEM ? 402 : 571));
    assert(swapped_solution.T == (CLASSICAL_PROBLEM ? 136 : 169));
    assert(swapped_solution.W == (CLASSICAL_PROBLEM ? 4 : 5));

    print_sub_test_end();

    return EXIT_SUCCESS;
}

int test_build_swap_opt_solution_1_and_3() {
    print_sub_test_begin("build_swap", "Criando vizinhanca swap para vertices 1 e 3 (OptimizedSolution)");

    // Arrange
    int distances[5][5] = {
            {0, 59, 73, 55, 33},
            {59, 0, 19, 9, 43},
            {73, 19, 0, 19, 49},
            { 55, 9, 19, 0, 35},
            {33, 43, 49, 35, 0},
    };

    int vertices[5] = {0, 1, 2, 3, 4};

    OptimizedMatrix opt_matrix = build_opt_matrix(vertices, reinterpret_cast<const int *>(distances), 5);

    // Act
    OptimizedSolution swapped_solution = build_swap(opt_matrix, 1, 3, reinterpret_cast<const int *>(distances));

    // Prepare-Response
    int result_array[5] = {0, 3, 2, 1, 4};

    // Assert
    assert(arrays_are_equal(swapped_solution.vertices, result_array, 5));
    assert(swapped_solution.C == (CLASSICAL_PROBLEM ? 358 : 527));
    assert(swapped_solution.T == (CLASSICAL_PROBLEM ? 136 : 169));
    assert(swapped_solution.W == (CLASSICAL_PROBLEM ? 4 : 5));

    print_sub_test_end();

    return EXIT_SUCCESS;
}

int test_build_swap_opt_solution_1_and_4() {
    print_sub_test_begin("build_swap", "Criando vizinhanca swap para vertices 1 e 4 (OptimizedSolution)");

    // Arrange
    int distances[5][5] = {
            {0, 59, 73, 55, 33},
            {59, 0, 19, 9, 43},
            {73, 19, 0, 19, 49},
            { 55, 9, 19, 0, 35},
            {33, 43, 49, 35, 0},
    };

    int vertices[5] = {0, 1, 2, 3, 4};

    OptimizedMatrix opt_matrix = build_opt_matrix(vertices, reinterpret_cast<const int *>(distances), 5);

    // Act
    OptimizedSolution swapped_solution = build_swap(opt_matrix, 1, 4, reinterpret_cast<const int *>(distances));

    // Prepare-Response
    int result_array[5] = {0, 4, 2, 3, 1};

    // Assert
    assert(arrays_are_equal(swapped_solution.vertices, result_array, 5));
    assert(swapped_solution.C == (CLASSICAL_PROBLEM ? 326 : 495));
    assert(swapped_solution.T == (CLASSICAL_PROBLEM ? 110 : 169));
    assert(swapped_solution.W == (CLASSICAL_PROBLEM ? 4 : 5));

    print_sub_test_end();

    return EXIT_SUCCESS;
}

int test_build_swap_opt_solution_2_and_4() {
    print_sub_test_begin("build_swap", "Criando vizinhanca swap para vertices 2 e 4 (OptimizedSolution)");

    // Arrange
    int distances[5][5] = {
            {0, 59, 73, 55, 33},
            {59, 0, 19, 9, 43},
            {73, 19, 0, 19, 49},
            { 55, 9, 19, 0, 35},
            {33, 43, 49, 35, 0},
    };

    int vertices[5] = {0, 1, 2, 3, 4};

    OptimizedMatrix opt_matrix = build_opt_matrix(vertices, reinterpret_cast<const int *>(distances), 5);

    // Act
    OptimizedSolution swapped_solution = build_swap(opt_matrix, 2, 4, reinterpret_cast<const int *>(distances));

    // Prepare-Response
    int result_array[5] = {0, 1, 4, 3, 2};

    // Assert
    assert(arrays_are_equal(swapped_solution.vertices, result_array, 5));
    assert(swapped_solution.C == (CLASSICAL_PROBLEM ? 454 : 683));
    assert(swapped_solution.T == (CLASSICAL_PROBLEM ? 156 : 229));
    assert(swapped_solution.W == (CLASSICAL_PROBLEM ? 4 : 5));

    print_sub_test_end();

    return EXIT_SUCCESS;
}

int test_build_swap_opt_solution_2_and_3() {
    print_sub_test_begin("build_swap", "Criando vizinhanca swap para vertices 2 e 3 (OptimizedSolution)");

    // Arrange
    int distances[5][5] = {
            {0, 59, 73, 55, 33},
            {59, 0, 19, 9, 43},
            {73, 19, 0, 19, 49},
            { 55, 9, 19, 0, 35},
            {33, 43, 49, 35, 0},
    };

    int vertices[5] = {0, 1, 2, 3, 4};

    OptimizedMatrix opt_matrix = build_opt_matrix(vertices, reinterpret_cast<const int *>(distances), 5);

    // Act
    OptimizedSolution swapped_solution = build_swap(opt_matrix, 2, 3, reinterpret_cast<const int *>(distances));

    // Prepare-Response
    int result_array[5] = {0, 1, 3, 2, 4};

    // Assert
    assert(arrays_are_equal(swapped_solution.vertices, result_array, 5));
    assert(swapped_solution.C == (CLASSICAL_PROBLEM ? 350 : 519));
    assert(swapped_solution.T == (CLASSICAL_PROBLEM ? 136 : 169));
    assert(swapped_solution.W == (CLASSICAL_PROBLEM ? 4 : 5));

    print_sub_test_end();

    return EXIT_SUCCESS;
}

int test_build_swap_opt_solution_3_and_4() {
    print_sub_test_begin("build_swap", "Criando vizinhanca swap para vertices 3 e 4 (OptimizedSolution)");

    // Arrange
    int distances[5][5] = {
            {0, 59, 73, 55, 33},
            {59, 0, 19, 9, 43},
            {73, 19, 0, 19, 49},
            { 55, 9, 19, 0, 35},
            {33, 43, 49, 35, 0},
    };

    int vertices[5] = {0, 1, 2, 3, 4};

    OptimizedMatrix opt_matrix = build_opt_matrix(vertices, reinterpret_cast<const int *>(distances), 5);

    // Act
    OptimizedSolution swapped_solution = build_swap(opt_matrix, 3, 4, reinterpret_cast<const int *>(distances));

    // Prepare-Response
    int result_array[5] = {0, 1, 2, 4, 3};

    // Assert
    assert(arrays_are_equal(swapped_solution.vertices, result_array, 5));
    assert(swapped_solution.C == (CLASSICAL_PROBLEM ? 426 : 643));
    assert(swapped_solution.T == (CLASSICAL_PROBLEM ? 162 : 217));
    assert(swapped_solution.W == (CLASSICAL_PROBLEM ? 4 : 5));

    print_sub_test_end();

    return EXIT_SUCCESS;
}

int test_swap() {
    print_test_begin("swap.cpp");
    test_swap_random();
    test_swap_selected();
    test_swap_opt();
    test_swap_opt_first_improvement();
    test_build_swap_opt_solution_1_and_2();
    test_build_swap_opt_solution_1_and_3();
    test_build_swap_opt_solution_1_and_4();
    test_build_swap_opt_solution_2_and_3();
    test_build_swap_opt_solution_2_and_4();
    test_build_swap_opt_solution_3_and_4();
    test_swap_opt_2();
    print_test_end("swap.cpp");

    return EXIT_SUCCESS;
}



