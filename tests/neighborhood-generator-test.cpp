//
// Created by Thiago on 27/03/2021.
//

#include <cassert>
#include <cstring>
#include "test-logger.h"
#include "../neighborhoods/neighborhood-generator.h"
#include "../utils/string-utils.h"

int test_generate_neighbor_swap() {
    print_sub_test_begin("generate_neighbor", "Testando a geracao de vizinho SWAP");

    // Arrange
    int distance_matrix[3][3] = {
            {0, 59, 73},
            {59, 0, 19},
            {73, 19, 0}
    };

    int objective_function = CLASSICAL_PROBLEM ? 137 : 288;

    Solution solution = {
            objective_function,
            3,
            {0, 1, 2}
    };

    // Act
    Solution neighbor = generate_neighbor(solution, reinterpret_cast<int *>(distance_matrix), SWAP, 3);

    // Prepare-Response
    bool same_order = neighbor.vertices[0] == 0 &&
            neighbor.vertices[1] == 1 &&
            neighbor.vertices[2] == 2;

    bool same_objective_function = neighbor.objective_function == objective_function;

    // Assert

    assert(same_order == false);
    assert(same_objective_function == false);
    assert(neighbor.vertices[0] == 0);
    print_sub_test_end();

    return EXIT_SUCCESS;
}

int test_generate_neighbor_reinsertion() {
    print_sub_test_begin("generate_neighbor", "Testando a geracao de vizinho REINSERT");

    // Arrange
    int distance_matrix[3][3] = {
            {0, 59, 73},
            {59, 0, 19},
            {73, 19, 0}
    };

    int objective_function = CLASSICAL_PROBLEM ? 137 : 288;

    Solution solution = {
            objective_function,
            3,
            {0, 1, 2}
    };

    // Act
    Solution neighbor = generate_neighbor(solution, reinterpret_cast<int *>(distance_matrix), REINSERTION, 3);

    // Prepare-Response
    bool same_order = neighbor.vertices[0] == 0 &&
                      neighbor.vertices[1] == 1 &&
                      neighbor.vertices[2] == 2;

    bool same_objective_function = neighbor.objective_function == objective_function;

    // Assert

    assert(same_order == false);
    assert(same_objective_function == false);
    assert(neighbor.vertices[0] == 0);
    print_sub_test_end();

    return EXIT_SUCCESS;
}

int test_generate_neighbor_or_opt2() {
    print_sub_test_begin("generate_neighbor", "Testando a geracao de vizinho OR_OPT2");

    // Arrange
    const int distance_matrix[5][5] = {
            {0, 59, 73, 30, 28},
            {59, 0, 19, 45, 32},
            {73, 19, 0, 69, 64},
            {30, 45, 69, 0, 20},
            {28, 32, 64, 20, 0},
    };

    Solution solution = {
            .objective_function = 0,
            .size_of_solution = 5,
            .vertices = {0, 1, 2, 3, 4}
    };

    int objective_function = solution.objective_function;

    // Act
    Solution neighbor = generate_neighbor(solution, reinterpret_cast<const int *>(distance_matrix), OR_OPT2, 5);

    // Prepare-Response
    bool same_order = neighbor.vertices[0] == 0 &&
                      neighbor.vertices[1] == 1 &&
                      neighbor.vertices[2] == 2 &&
                      neighbor.vertices[3] == 3 &&
                      neighbor.vertices[4] == 4;

    bool same_objective_function = neighbor.objective_function == objective_function;

    // Assert

    assert(same_order == false);
    assert(same_objective_function == false);
    assert(neighbor.vertices[0] == 0);
    print_sub_test_end();

    return EXIT_SUCCESS;
}

int test_generate_neighbor_or_opt3() {
    print_sub_test_begin("generate_neighbor", "Testando a geracao de vizinho OR_OPT3");

    // Arrange
    const int distance_matrix[5][5] = {
            {0, 59, 73, 30, 28},
            {59, 0, 19, 45, 32},
            {73, 19, 0, 69, 64},
            {30, 45, 69, 0, 20},
            {28, 32, 64, 20, 0},
    };

    Solution solution = {
            .objective_function = 0,
            .size_of_solution = 5,
            .vertices = {0, 1, 2, 3, 4}
    };

    int objective_function = solution.objective_function;

    // Act
    Solution neighbor = generate_neighbor(solution, reinterpret_cast<const int *>(distance_matrix), OR_OPT3, 5);

    // Prepare-Response
    bool same_order = neighbor.vertices[0] == 0 &&
                      neighbor.vertices[1] == 1 &&
                      neighbor.vertices[2] == 2 &&
                      neighbor.vertices[3] == 3 &&
                      neighbor.vertices[4] == 4;

    bool same_objective_function = neighbor.objective_function == objective_function;

    // Assert

    assert(same_order == false);
    assert(same_objective_function == false);
    assert(neighbor.vertices[0] == 0);
    print_sub_test_end();

    return EXIT_SUCCESS;
}

int test_generate_neighbor_2_optimal() {
    print_sub_test_begin("generate_neighbor", "Testando a geracao de vizinho TWO_OPTIMAL");

    // Arrange
    const int distance_matrix[5][5] = {
            {0, 59, 73, 30, 28},
            {59, 0, 19, 45, 32},
            {73, 19, 0, 69, 64},
            {30, 45, 69, 0, 20},
            {28, 32, 64, 20, 0},
    };

    Solution solution = {
            .objective_function = 0,
            .size_of_solution = 5,
            .vertices = {0, 1, 2, 3, 4}
    };

    int objective_function = solution.objective_function;

    // Act
    Solution neighbor = generate_neighbor(solution, reinterpret_cast<const int *>(distance_matrix), TWO_OPTIMAL, 5);

    // Prepare-Response
    bool same_order = neighbor.vertices[0] == 0 &&
                      neighbor.vertices[1] == 1 &&
                      neighbor.vertices[2] == 2 &&
                      neighbor.vertices[3] == 3 &&
                      neighbor.vertices[4] == 4;

    bool same_objective_function = neighbor.objective_function == objective_function;

    // Assert

    assert(same_order == false);
    assert(same_objective_function == false);
    assert(neighbor.vertices[0] == 0);
    print_sub_test_end();

    return EXIT_SUCCESS;
}

int test_generate_neighbor_error() {
    print_sub_test_begin("generate_neighbor", "Testando o caso de erro para vizinhanca que nao existe");

    // Arrange
    int distance_matrix[3][3] = {
            {0, 59, 73},
            {59, 0, 19},
            {73, 19, 0}
    };

    int objective_function = CLASSICAL_PROBLEM ? 137 : 288;

    Solution solution = {
            objective_function,
            3,
            {0, 1, 2}
    };

    // Act
    try {
        Solution neighbor = generate_neighbor(solution, reinterpret_cast<int *>(distance_matrix), 10, 3);
    } catch (const char* msg) {
        assert(strcmp(msg, "neighborhood invalido!") == STRING_MATCH);
    }

    print_sub_test_end();
    return EXIT_SUCCESS;
}

int test_generate_random_neighbor() {
    print_sub_test_begin("generate_random_neighbor", "Testando a geracao de vizinho ALEATORIO");

    // Arrange
    const int distance_matrix[5][5] = {
            {0, 59, 73, 30, 28},
            {59, 0, 19, 45, 32},
            {73, 19, 0, 69, 64},
            {30, 45, 69, 0, 20},
            {28, 32, 64, 20, 0},
    };

    Solution solution = {
            .objective_function = 0,
            .size_of_solution = 5,
            .vertices = {0, 1, 2, 3, 4}
    };

    int objective_function = solution.objective_function;

    // Act
    Solution neighbor = generate_random_neighbor(solution, reinterpret_cast<const int *>(distance_matrix), 5);

    // Prepare-Response
    bool same_order = neighbor.vertices[0] == 0 &&
                      neighbor.vertices[1] == 1 &&
                      neighbor.vertices[2] == 2 &&
                      neighbor.vertices[3] == 3 &&
                      neighbor.vertices[4] == 4;

    bool same_objective_function = neighbor.objective_function == objective_function;

    // Assert

    assert(same_order == false);
    assert(same_objective_function == false);
    assert(neighbor.vertices[0] == 0);
    print_sub_test_end();

    return EXIT_SUCCESS;
}

int test_apply_local_search_swap() {
    print_sub_test_begin("apply_local_search", "Testando a geracao de busca local SWAP (primeira melhora)");

    // Arrange
    const int distance_matrix[5][5] = {
            {0, 59, 73, 30, 28},
            {59, 0, 19, 45, 32},
            {73, 19, 0, 69, 64},
            {30, 45, 69, 0, 20},
            {28, 32, 64, 20, 0},
    };

    Solution solution = {
            .objective_function = 0,
            .size_of_solution = 5,
            .vertices = {0, 1, 2, 3, 4}
    };

    calculate_objective_function(&solution, reinterpret_cast<const int *>(distance_matrix), 5);
    int previous_fo = solution.objective_function;

    // Act
    Solution first_improvement = apply_local_search(solution, reinterpret_cast<const int *>(distance_matrix), SWAP, 5, FIRST_IMPROVEMENT);

    // Prepare-Response
    bool same_order = first_improvement.vertices[0] == 0 &&
            first_improvement.vertices[1] == 1 &&
            first_improvement.vertices[2] == 2 &&
            first_improvement.vertices[3] == 3 &&
            first_improvement.vertices[4] == 4;

    assert(same_order == false);
    assert(first_improvement.objective_function < previous_fo);

    print_sub_test_end();
    return EXIT_SUCCESS;
}

int test_apply_local_search_reinsert() {
    print_sub_test_begin("apply_local_search", "Testando a geracao de busca local REINSERT (primeira melhora)");

    // Arrange
    const int distance_matrix[5][5] = {
            {0, 59, 73, 30, 28},
            {59, 0, 19, 45, 32},
            {73, 19, 0, 69, 64},
            {30, 45, 69, 0, 20},
            {28, 32, 64, 20, 0},
    };

    Solution solution = {
            .objective_function = 0,
            .size_of_solution = 5,
            .vertices = {0, 1, 2, 3, 4}
    };

    calculate_objective_function(&solution, reinterpret_cast<const int *>(distance_matrix), 5);
    int previous_fo = solution.objective_function;

    // Act
    Solution first_improvement = apply_local_search(solution, reinterpret_cast<const int *>(distance_matrix), REINSERTION, 5, FIRST_IMPROVEMENT);

    // Prepare-Response
    bool same_order = first_improvement.vertices[0] == 0 &&
                      first_improvement.vertices[1] == 1 &&
                      first_improvement.vertices[2] == 2 &&
                      first_improvement.vertices[3] == 3 &&
                      first_improvement.vertices[4] == 4;

    assert(same_order == false);
    assert(first_improvement.objective_function < previous_fo);

    print_sub_test_end();
    return EXIT_SUCCESS;
}

int test_apply_local_search_or_opt2() {
    print_sub_test_begin("apply_local_search", "Testando a geracao de busca local OR_OPT2 (primeira melhora)");

    // Arrange
    const int distance_matrix[5][5] = {
            {0, 59, 73, 30, 28},
            {59, 0, 19, 45, 32},
            {73, 19, 0, 69, 64},
            {30, 45, 69, 0, 20},
            {28, 32, 64, 20, 0},
    };

    Solution solution = {
            .objective_function = 0,
            .size_of_solution = 5,
            .vertices = {0, 1, 2, 3, 4}
    };

    calculate_objective_function(&solution, reinterpret_cast<const int *>(distance_matrix), 5);
    int previous_fo = solution.objective_function;

    // Act
    Solution first_improvement = apply_local_search(solution, reinterpret_cast<const int *>(distance_matrix), OR_OPT2, 5, FIRST_IMPROVEMENT);

    // Prepare-Response
    bool same_order = first_improvement.vertices[0] == 0 &&
                      first_improvement.vertices[1] == 1 &&
                      first_improvement.vertices[2] == 2 &&
                      first_improvement.vertices[3] == 3 &&
                      first_improvement.vertices[4] == 4;

    assert(same_order == false);
    assert(first_improvement.objective_function < previous_fo);

    print_sub_test_end();
    return EXIT_SUCCESS;
}

int test_apply_local_search_or_opt3() {
    print_sub_test_begin("apply_local_search", "Testando a geracao de busca local OR_OPT3 (primeira melhora)");

    // Arrange
    const int distance_matrix[5][5] = {
            {0, 59, 73, 30, 28},
            {59, 0, 19, 45, 32},
            {73, 19, 0, 69, 64},
            {30, 45, 69, 0, 20},
            {28, 32, 64, 20, 0},
    };

    Solution solution = {
            .objective_function = 0,
            .size_of_solution = 5,
            .vertices = {0, 1, 2, 3, 4}
    };

    calculate_objective_function(&solution, reinterpret_cast<const int *>(distance_matrix), 5);
    int previous_fo = solution.objective_function;

    // Act
    Solution first_improvement = apply_local_search(solution, reinterpret_cast<const int *>(distance_matrix), OR_OPT3, 5, FIRST_IMPROVEMENT);

    // Prepare-Response
    bool same_order = first_improvement.vertices[0] == 0 &&
                      first_improvement.vertices[1] == 1 &&
                      first_improvement.vertices[2] == 2 &&
                      first_improvement.vertices[3] == 3 &&
                      first_improvement.vertices[4] == 4;

    assert(same_order == false);
    assert(first_improvement.objective_function < previous_fo);

    print_sub_test_end();
    return EXIT_SUCCESS;
}

int test_apply_local_search_two_optimal() {
    print_sub_test_begin("apply_local_search", "Testando a geracao de busca local OPT_2 (primeira melhora)");

    // Arrange
    const int distance_matrix[5][5] = {
            {0, 59, 73, 30, 28},
            {59, 0, 19, 45, 32},
            {73, 19, 0, 69, 64},
            {30, 45, 69, 0, 20},
            {28, 32, 64, 20, 0},
    };

    Solution solution = {
            .objective_function = 0,
            .size_of_solution = 5,
            .vertices = {0, 1, 2, 3, 4}
    };

    calculate_objective_function(&solution, reinterpret_cast<const int *>(distance_matrix), 5);
    int previous_fo = solution.objective_function;

    // Act
    Solution first_improvement = apply_local_search(solution, reinterpret_cast<const int *>(distance_matrix), TWO_OPTIMAL, 5, FIRST_IMPROVEMENT);

    // Prepare-Response
    bool same_order = first_improvement.vertices[0] == 0 &&
                      first_improvement.vertices[1] == 1 &&
                      first_improvement.vertices[2] == 2 &&
                      first_improvement.vertices[3] == 3 &&
                      first_improvement.vertices[4] == 4;

    assert(same_order == false);
    assert(first_improvement.objective_function < previous_fo);

    print_sub_test_end();
    return EXIT_SUCCESS;
}

int test_neighborhood_generator() {
    print_test_begin("neighborhood-generator.cpp");
    test_generate_neighbor_swap();
    test_generate_neighbor_reinsertion();
    test_generate_neighbor_or_opt2();
    test_generate_neighbor_error();
    test_generate_neighbor_2_optimal();
    test_generate_random_neighbor();
    test_generate_neighbor_or_opt3();
    test_apply_local_search_swap();
    test_apply_local_search_reinsert();
    test_apply_local_search_or_opt2();
    test_apply_local_search_or_opt3();
    test_apply_local_search_two_optimal();
    print_test_end("neighborhood-generator.cpp");
    return EXIT_SUCCESS;
}