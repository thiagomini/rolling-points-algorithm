//
// Created by Thiago on 03/04/2021.
//

#include <cassert>
#include "../neighborhoods/2-optimal.h"
#include "test-logger.h"
#include "../utils/string-utils.h"

/**
 * Estrutura utilizada para testar a função build_two_optimal
 */
typedef struct {
    int vertex_1;
    int vertex_2;
    int expected_C;
    int expected_T;
    int expected_W;
    int expected_size;
    vector<int> expected_vertices;
} BuildTwoOptimalTest;

/**
 * Função genérica para testar o método <b>build_two_optimal</b>. Basta mudar os parâmetros de entrada e o resultado
 * esperado para realizar novos testes
 * @param test_parameters
 * @return
 */
int test_build_two_optimal(BuildTwoOptimalTest test_parameters) {
    // Arrange
    const int distance_matrix[6][6] = {
            {0, 59, 73, 30, 28, 61},
            {59, 0, 19, 45, 32, 42},
            {73, 19, 0, 69, 64, 24},
            {30, 45, 69, 0, 20, 39},
            {28, 32, 64, 20, 0, 87},
            {61, 42, 24, 39, 87, 0},
    };

    int * vertices = build_crescent_array(test_parameters.expected_size);
    OptimizedMatrix opt_matrix = build_opt_matrix(vertices, reinterpret_cast<const int *>(distance_matrix), test_parameters.expected_size);

    // Act
    OptimizedSolution final_solution = build_two_optimal(
            opt_matrix, reinterpret_cast<const int *>(distance_matrix),
            test_parameters.vertex_1,
            test_parameters.vertex_2
    );

    // Assert
    assert(arrays_are_equal(test_parameters.expected_vertices.data(), final_solution.vertices, test_parameters.expected_size));
    assert(final_solution.C == test_parameters.expected_C);
    assert(final_solution.T == test_parameters.expected_T);
    assert(final_solution.W == test_parameters.expected_W);
    assert(final_solution.size == test_parameters.expected_size);

    print_sub_test_end();
    return EXIT_SUCCESS;
}

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
    two_optimal_move(solution, reinterpret_cast<const int *>(distance_matrix), 0, 3, 6);

    // Assert
    assert(solution.vertices[0] == 0);
    assert(solution.vertices[1] == 3);
    assert(solution.vertices[2] == 2);
    assert(solution.vertices[3] == 1);
    assert(solution.vertices[4] == 4);
    assert(solution.vertices[5] == 5);

    print_sub_test_end();
    return EXIT_SUCCESS;
}

int test_build_two_optimal_first_and_last() {
    print_sub_test_begin(
            "build_two_optimal",
            "Construcao de solucao 2-Optimal para primeiro e ultimo vertices (OptimizedSolution)"
    );

    return test_build_two_optimal({
        0,
        4,
        CLASSICAL_PROBLEM ? 507 : 756,
        CLASSICAL_PROBLEM ? 178 : 239,
        CLASSICAL_PROBLEM ? 5 : 6,
        6,
        {0, 4, 3, 2, 1, 5}
    });
}

int test_build_two_optimal_first_and_middle() {
    print_sub_test_begin(
            "build_two_optimal",
            "Construcao de solucao 2-Optimal para vertice inicial e um do meio (OptimizedSolution)"
    );

    return test_build_two_optimal({
                                          0,
                                          3,
                                          CLASSICAL_PROBLEM ? 634 : 932,
                                          CLASSICAL_PROBLEM ? 237 : 298,
                                          CLASSICAL_PROBLEM ? 5 : 6,
                                          6,
                                          {0, 3, 2, 1, 4, 5}
                                  });
}

int test_build_two_optimal_two_in_middle() {
    print_sub_test_begin(
            "build_two_optimal",
            "Construcao de solucao 2-Optimal para dois vertices do meio (OptimizedSolution)"
    );

    return test_build_two_optimal({
                                          1,
                                          3,
                                          CLASSICAL_PROBLEM ? 897 : 1282,
                                          CLASSICAL_PROBLEM ? 324 : 385,
                                          CLASSICAL_PROBLEM ? 5 : 6,
                                          6,
                                          {0, 1, 3, 2, 4, 5}
                                  });
}

int test_build_two_optimal_middle_and_last() {
    print_sub_test_begin(
            "build_two_optimal",
            "Construcao de solucao 2-Optimal para um vertice do meio e o final (OptimizedSolution)"
    );

    return test_build_two_optimal({
                                          1,
                                          5,
                                          CLASSICAL_PROBLEM ? 833 : 1183,
                                          CLASSICAL_PROBLEM ? 277 : 338,
                                          CLASSICAL_PROBLEM ? 5 : 6,
                                          6,
                                          {0, 1, 5, 4, 3, 2}
                                  });
}

int test_build_two_optimal_two_consecutive() {
    print_sub_test_begin(
            "build_two_optimal",
            "Testando erro ao crair 2-Optimal com 2 vertices consecutivos (OptimizedSolution)"
    );

    try {
        test_build_two_optimal({
                                       1,
                                       2,
                                       0,
                                       0,
                                       0,
                                       6,
                                       {0, 1, 2, 3, 4, 5, 6}
                               });
    } catch (const char * error) {
        assert(strings_are_equal(error, "Arestas não podem ser ajacentes!"));
        print_sub_test_end();
        return EXIT_SUCCESS;
    }

    return EXIT_FAILURE;
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
            .size_of_solution = 6,
            .vertices = {0, 1, 2, 3, 4, 5}
    };

    calculate_objective_function(&solution, reinterpret_cast<const int *>(distance_matrix), 6);

    // Act
    two_optimal_move(solution, reinterpret_cast<const int *>(distance_matrix), 6);

    // Prepare-Response
    bool has_same_order = solution.vertices[0] == 0 &&
            solution.vertices[1] == 1 &&
            solution.vertices[2] == 2 &&
            solution.vertices[3] == 3 &&
            solution.vertices[4] == 4 &&
            solution.vertices[5] == 5;

    // Assert
    assert(has_same_order == false);

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
    two_optimal(solution, reinterpret_cast<const int *>(distance_matrix), 4);

    // Assert
    assert(solution.vertices[0] == 0);

    print_sub_test_end();
    return EXIT_SUCCESS;
}

int test_two_optimal_2_local_search() {
    print_sub_test_begin("two_optimal_2", "Testando a busca local 2-Optimal (OptimizedSolution)");

    // Arrange
    const int distance_matrix[4][4] = {
            {0, 59, 73, 30},
            {59, 0, 19, 45},
            {73, 19, 0, 69},
            {30, 45, 69, 0},
    };
    int vertices[4] = {0, 1, 2, 3};
    OptimizedMatrix opt_matrix = build_opt_matrix(vertices, reinterpret_cast<const int *>(distance_matrix), 4);

    // Act
    Solution optimal_solution = two_optimal_2(reinterpret_cast<const int *>(distance_matrix), opt_matrix, BEST_IMPROVEMENT);

    // Prepare-Response
    int expected_vertices[4] = {0, 3, 2, 1};
    // Assert
    assert(arrays_are_equal(expected_vertices, optimal_solution.vertices, 4));
    assert(optimal_solution.objective_function == (CLASSICAL_PROBLEM ? 247 : 424));

    print_sub_test_end();
    return EXIT_SUCCESS;
}

int test_two_optimal_2_first_improvement() {
    print_sub_test_begin("two_optimal_2", "Testando a busca local (primeira melhora) 2-Optimal (OptimizedSolution)");

    // Arrange
    const int distance_matrix[4][4] = {
            {0, 59, 73, 30},
            {59, 0, 19, 45},
            {73, 19, 0, 69},
            {30, 45, 69, 0},
    };
    int vertices[4] = {0, 1, 2, 3};
    OptimizedMatrix opt_matrix = build_opt_matrix(vertices, reinterpret_cast<const int *>(distance_matrix), 4);

    // Act
    Solution optimal_solution = two_optimal_2(reinterpret_cast<const int *>(distance_matrix), opt_matrix, FIRST_IMPROVEMENT);

    // Prepare-Response
    int expected_vertices[4] = {0, 3, 2, 1};
    // Assert
    assert(arrays_are_equal(expected_vertices, optimal_solution.vertices, 4));
    assert(optimal_solution.objective_function == (CLASSICAL_PROBLEM ? 247 : 424));

    print_sub_test_end();
    return EXIT_SUCCESS;
}


int test_two_optimal_local_search_first_improvement() {
    print_sub_test_begin("two_optimal", "Testando a busca local 2-Optimal (primeira melhora)");

    // Arrange
    const int distance_matrix[4][4] = {
            {0, 59, 73, 30},
            {59, 0, 19, 45},
            {73, 19, 0, 69},
            {30, 45, 69, 0},
    };

    Solution solution = {
            .size_of_solution = 4,
            .vertices = {0, 3, 2, 1}
    };

    calculate_objective_function(&solution, reinterpret_cast<const int *>(distance_matrix), 6);

    // Act
    solution = two_optimal(solution, reinterpret_cast<const int *>(distance_matrix), 6, FIRST_IMPROVEMENT);

    // Assert
    assert(solution.vertices[0] == 0);
    assert(solution.vertices[1] == 3);
    assert(solution.vertices[2] == 1);
    assert(solution.vertices[3] == 2);

    print_sub_test_end();
    return EXIT_SUCCESS;
}

int test_two_optimal() {
    print_test_begin("2-optimal.cpp");
    test_two_optimal_move();
    test_two_optimal_move_random();
    test_two_optimal_local_search();
    test_two_optimal_local_search_first_improvement();

    // OptimizedSolution
    test_build_two_optimal_first_and_last();
    test_build_two_optimal_first_and_middle();
    test_build_two_optimal_two_in_middle();
    test_build_two_optimal_middle_and_last();
    test_build_two_optimal_two_consecutive();
    test_two_optimal_2_local_search();
    test_two_optimal_2_first_improvement();
    print_test_end("2-optimal.cpp");

    return EXIT_SUCCESS;
}