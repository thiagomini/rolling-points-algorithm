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

int test_build_reinsert_solution_1_and_2() {
    print_sub_test_begin("build_reinsert", "Criando vizinhanca reinsert para vertices 1 e 2 (OptimizedSolution)");

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
    OptimizedSolution reinserted_solution = build_reinsert(opt_matrix, 1, 2, reinterpret_cast<const int *>(distances));

    // Prepare-Response
    int result_array[5] = {0, 2, 1, 3, 4};

    // Assert
    assert(arrays_are_equal(reinserted_solution.vertices, result_array, 5));
    assert(reinserted_solution.C == (CLASSICAL_PROBLEM ? 402 : 571));
    assert(reinserted_solution.T == (CLASSICAL_PROBLEM ? 136 : 169));
    assert(reinserted_solution.W == (CLASSICAL_PROBLEM ? 4 : 5));

    print_sub_test_end();
    return EXIT_SUCCESS;
}

int test_build_reinsert_solution_1_and_3() {
    print_sub_test_begin("build_reinsert", "Criando vizinhanca reinsert para vertices 1 e 3 (OptimizedSolution)");

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
    OptimizedSolution reinserted_solution = build_reinsert(opt_matrix, 1, 3, reinterpret_cast<const int *>(distances));

    // Prepare-Response
    int result_array[5] = {0, 2, 3, 1, 4};

    // Assert
    assert(arrays_are_equal(reinserted_solution.vertices, result_array, 5));
    assert(reinserted_solution.C == (CLASSICAL_PROBLEM ? 410 : 587));
    assert(reinserted_solution.T == (CLASSICAL_PROBLEM ? 144 : 177));
    assert(reinserted_solution.W == (CLASSICAL_PROBLEM ? 4 : 5));

    print_sub_test_end();
    return EXIT_SUCCESS;
}

int test_build_reinsert_solution_1_and_4() {
    print_sub_test_begin("build_reinsert", "Criando vizinhanca reinsert para vertices 1 e 4 (OptimizedSolution)");

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
    OptimizedSolution reinserted_solution = build_reinsert(opt_matrix, 1, 4, reinterpret_cast<const int *>(distances));

    // Prepare-Response
    int result_array[5] = {0, 2, 3, 4, 1};

    // Assert
    assert(arrays_are_equal(reinserted_solution.vertices, result_array, 5));
    assert(reinserted_solution.C == (CLASSICAL_PROBLEM ? 462 : 691));
    assert(reinserted_solution.T == (CLASSICAL_PROBLEM ? 170 : 203));
    assert(reinserted_solution.W == (CLASSICAL_PROBLEM ? 4 : 5));

    print_sub_test_end();
    return EXIT_SUCCESS;
}

int test_build_reinsert_solution_2_and_3() {
    print_sub_test_begin("build_reinsert", "Criando vizinhanca reinsert para vertices 2 e 3 (OptimizedSolution)");

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
    OptimizedSolution reinserted_solution = build_reinsert(opt_matrix, 2, 3, reinterpret_cast<const int *>(distances));

    // Prepare-Response
    int result_array[5] = {0, 1, 3, 2, 4};

    // Assert
    assert(arrays_are_equal(reinserted_solution.vertices, result_array, 5));
    assert(reinserted_solution.C == (CLASSICAL_PROBLEM ? 350 : 519));
    assert(reinserted_solution.T == (CLASSICAL_PROBLEM ? 136 : 169));
    assert(reinserted_solution.W == (CLASSICAL_PROBLEM ? 4 : 5));

    print_sub_test_end();
    return EXIT_SUCCESS;
}

int test_build_reinsert_solution_2_and_4() {
    print_sub_test_begin("build_reinsert", "Criando vizinhanca reinsert para vertices 2 e 4 (OptimizedSolution)");

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
    OptimizedSolution reinserted_solution = build_reinsert(opt_matrix, 2, 4, reinterpret_cast<const int *>(distances));

    // Prepare-Response
    int result_array[5] = {0, 1, 3, 4, 2};

    // Assert
    assert(arrays_are_equal(reinserted_solution.vertices, result_array, 5));
    assert(reinserted_solution.C == (CLASSICAL_PROBLEM ? 382 : 607));
    assert(reinserted_solution.T == (CLASSICAL_PROBLEM ? 152 : 185));
    assert(reinserted_solution.W == (CLASSICAL_PROBLEM ? 4 : 5));

    print_sub_test_end();
    return EXIT_SUCCESS;
}

int test_build_reinsert_solution_3_and_4() {
    print_sub_test_begin("build_reinsert", "Criando vizinhanca reinsert para vertices 3 e 4 (OptimizedSolution)");

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
    OptimizedSolution reinserted_solution = build_reinsert(opt_matrix, 3, 4, reinterpret_cast<const int *>(distances));

    // Prepare-Response
    int result_array[5] = {0, 1, 2, 4, 3};

    // Assert
    assert(arrays_are_equal(reinserted_solution.vertices, result_array, 5));
    assert(reinserted_solution.C == (CLASSICAL_PROBLEM ? 426 : 643));
    assert(reinserted_solution.T == (CLASSICAL_PROBLEM ? 162 : 195));
    assert(reinserted_solution.W == (CLASSICAL_PROBLEM ? 4 : 5));

    print_sub_test_end();
    return EXIT_SUCCESS;
}

int test_build_reinsert_solution_4_and_1() {
    print_sub_test_begin("build_reinsert", "Criando vizinhanca reinsert para vertices 4 e 1 (OptimizedSolution)");

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
    OptimizedSolution reinserted_solution = build_reinsert(opt_matrix, 4, 1, reinterpret_cast<const int *>(distances));

    // Prepare-Response
    int result_array[5] = {0, 4, 1, 2, 3};

    // Assert
    assert(arrays_are_equal(reinserted_solution.vertices, result_array, 5));
    assert(reinserted_solution.C == (CLASSICAL_PROBLEM ? 318 : 487));
    assert(reinserted_solution.T == (CLASSICAL_PROBLEM ? 114 : 147));
    assert(reinserted_solution.W == (CLASSICAL_PROBLEM ? 4 : 5));

    print_sub_test_end();
    return EXIT_SUCCESS;
}

int test_build_reinsert_solution_3_and_2() {
    print_sub_test_begin("build_reinsert", "Criando vizinhanca reinsert para vertices 3 e 2 (OptimizedSolution)");

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
    OptimizedSolution reinserted_solution = build_reinsert(opt_matrix, 3, 2, reinterpret_cast<const int *>(distances));

    // Prepare-Response
    int result_array[5] = {0, 1, 3, 2, 4};

    // Assert
    assert(arrays_are_equal(reinserted_solution.vertices, result_array, 5));
    assert(reinserted_solution.C == (CLASSICAL_PROBLEM ? 350 : 519));
    assert(reinserted_solution.T == (CLASSICAL_PROBLEM ? 136 : 169));
    assert(reinserted_solution.W == (CLASSICAL_PROBLEM ? 4 : 5));

    print_sub_test_end();
    return EXIT_SUCCESS;
}

int test_build_reinsert_solution_3_and_1() {
    print_sub_test_begin("build_reinsert", "Criando vizinhanca reinsert para vertices 3 e 1 (OptimizedSolution)");

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
    OptimizedSolution reinserted_solution = build_reinsert(opt_matrix, 3, 1, reinterpret_cast<const int *>(distances));

    // Prepare-Response
    int result_array[5] = {0, 3, 1, 2, 4};

    // Assert
    assert(arrays_are_equal(reinserted_solution.vertices, result_array, 5));
    assert(reinserted_solution.C == (CLASSICAL_PROBLEM ? 334 : 499));
    assert(reinserted_solution.T == (CLASSICAL_PROBLEM ? 132 : 165));
    assert(reinserted_solution.W == (CLASSICAL_PROBLEM ? 4 : 5));

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
    int expected_fo = CLASSICAL_PROBLEM ? 247 : 424;

    // Assert
    assert(best_solution.vertices[0] == 0);
    assert(best_solution.vertices[1] == 3);
    assert(best_solution.vertices[2] == 2);
    assert(best_solution.vertices[3] == 1);
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
    test_build_reinsert_solution_1_and_2();
    test_build_reinsert_solution_1_and_3();
    test_build_reinsert_solution_1_and_4();
    test_build_reinsert_solution_2_and_3();
    test_build_reinsert_solution_2_and_4();
    test_build_reinsert_solution_3_and_4();
    test_build_reinsert_solution_4_and_1();
    test_build_reinsert_solution_3_and_2();
    test_build_reinsert_solution_3_and_1();
    print_test_end("reinsertion.cpp");

    return EXIT_SUCCESS;
}



