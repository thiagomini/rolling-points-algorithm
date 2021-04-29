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
    Solution best_solution = swap_opt(solution, reinterpret_cast<const int *>(distance_matrix));


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
    Solution best_solution = swap_opt(solution, reinterpret_cast<const int *>(distance_matrix), FIRST_IMPROVEMENT);


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
    print_sub_test_begin("build_swap", "Criando vizinhanca swap para vertices 1 e 2 (OptSolution)");

    // Arrange
    int distances[5][5] = {
            {0, 59, 73, 55, 33},
            {59, 0, 19, 9, 43},
            {73, 19, 0, 19, 49},
            { 55, 9, 19, 0, 35},
            {33, 43, 49, 35, 0},
    };

    distance_matrix distance_matrix ={
            .distances = reinterpret_cast<int *>(distances),
            .size = 5
    };

    OptMatrix opt_matrix = OptMatrix(5, {0, 1, 2, 3, 4}, distance_matrix);

    // Act
    OptSolution swapped_solution = build_swap(opt_matrix, 1, 2, distance_matrix);

    // Assert
    assert(swapped_solution.vertices == std::vector<int>({0, 2, 1, 3, 4}));
    assert(swapped_solution.C == (CLASSICAL_PROBLEM ? 402 : 571));
    assert(swapped_solution.T == (CLASSICAL_PROBLEM ? 136 : 169));
    assert(swapped_solution.W == (CLASSICAL_PROBLEM ? 4 : 5));

    print_sub_test_end();

    return EXIT_SUCCESS;
}

int test_build_swap_opt_solution_1_and_3() {
    print_sub_test_begin("build_swap", "Criando vizinhanca swap para vertices 1 e 3 (OptSolution)");

    // Arrange
    int distances[5][5] = {
            {0, 59, 73, 55, 33},
            {59, 0, 19, 9, 43},
            {73, 19, 0, 19, 49},
            { 55, 9, 19, 0, 35},
            {33, 43, 49, 35, 0},
    };

    distance_matrix distance_matrix ={
            .distances = reinterpret_cast<int *>(distances),
            .size = 5
    };

//    OptSolution solution = OptSolution(724, 4, 132, {0, 1, 2, 3, 4});
    OptMatrix opt_matrix = OptMatrix(5, {0, 1, 2, 3, 4}, distance_matrix);

    // Act
    OptSolution swapped_solution = build_swap(opt_matrix, 1, 3, distance_matrix);

    // Assert
    assert(swapped_solution.vertices == std::vector<int>({0, 3, 2, 1, 4}));
    assert(swapped_solution.C == (CLASSICAL_PROBLEM ? 358 : 527));
    assert(swapped_solution.T == (CLASSICAL_PROBLEM ? 136 : 169));
    assert(swapped_solution.W == (CLASSICAL_PROBLEM ? 4 : 5));

    print_sub_test_end();

    return EXIT_SUCCESS;
}

int test_build_swap_opt_solution_1_and_4() {
    print_sub_test_begin("build_swap", "Criando vizinhanca swap para vertices 1 e 4 (OptSolution)");

    // Arrange
    int distances[5][5] = {
            {0, 59, 73, 55, 33},
            {59, 0, 19, 9, 43},
            {73, 19, 0, 19, 49},
            { 55, 9, 19, 0, 35},
            {33, 43, 49, 35, 0},
    };

    distance_matrix distance_matrix ={
            .distances = reinterpret_cast<int *>(distances),
            .size = 5
    };


    OptMatrix opt_matrix = OptMatrix(5, {0, 1, 2, 3, 4}, distance_matrix);

    // Act
    OptSolution swapped_solution = build_swap(opt_matrix, 1, 4, distance_matrix);

    // Assert
    assert(swapped_solution.vertices == std::vector<int>({0, 4, 2, 3, 1}));
    assert(swapped_solution.C == (CLASSICAL_PROBLEM ? 326 : 495));
    assert(swapped_solution.T == (CLASSICAL_PROBLEM ? 110 : 169));
    assert(swapped_solution.W == (CLASSICAL_PROBLEM ? 4 : 5));

    print_sub_test_end();

    return EXIT_SUCCESS;
}

int test_build_swap_opt_solution_2_and_4() {
    print_sub_test_begin("build_swap", "Criando vizinhanca swap para vertices 2 e 4 (OptSolution)");

    // Arrange
    int distances[5][5] = {
            {0, 59, 73, 55, 33},
            {59, 0, 19, 9, 43},
            {73, 19, 0, 19, 49},
            { 55, 9, 19, 0, 35},
            {33, 43, 49, 35, 0},
    };

    distance_matrix distance_matrix ={
            .distances = reinterpret_cast<int *>(distances),
            .size = 5
    };


    OptMatrix opt_matrix = OptMatrix(5, {0, 1, 2, 3, 4}, distance_matrix);

    // Act
    OptSolution swapped_solution = build_swap(opt_matrix, 2, 4, distance_matrix);

    // Assert
    assert(swapped_solution.vertices == std::vector<int>({0, 1, 4, 3, 2}));
    assert(swapped_solution.C == (CLASSICAL_PROBLEM ? 454 : 683));
    assert(swapped_solution.T == (CLASSICAL_PROBLEM ? 156 : 229));
    assert(swapped_solution.W == (CLASSICAL_PROBLEM ? 4 : 5));

    print_sub_test_end();

    return EXIT_SUCCESS;
}


int test_build_swap_opt_solution_3_and_4() {
    print_sub_test_begin("build_swap", "Criando vizinhanca swap para vertices 3 e 4 (OptSolution)");

    // Arrange
    int distances[5][5] = {
            {0, 59, 73, 55, 33},
            {59, 0, 19, 9, 43},
            {73, 19, 0, 19, 49},
            { 55, 9, 19, 0, 35},
            {33, 43, 49, 35, 0},
    };

    distance_matrix distance_matrix ={
            .distances = reinterpret_cast<int *>(distances),
            .size = 5
    };


    OptMatrix opt_matrix = OptMatrix(5, {0, 1, 2, 3, 4}, distance_matrix);

    // Act
    OptSolution swapped_solution = build_swap(opt_matrix, 3, 4, distance_matrix);

    // Assert
    assert(swapped_solution.vertices == std::vector<int>({0, 1, 2, 4, 3}));
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
    test_build_swap_opt_solution_2_and_4();
    test_build_swap_opt_solution_3_and_4();
    print_test_end("swap.cpp");

    return EXIT_SUCCESS;
}



