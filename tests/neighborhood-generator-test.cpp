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
    Solution neighbor = generate_neighbor(solution, reinterpret_cast<int *>(distance_matrix), SWAP);

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
    Solution neighbor = generate_neighbor(solution, reinterpret_cast<int *>(distance_matrix), REINSERTION);

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
        Solution neighbor = generate_neighbor(solution, reinterpret_cast<int *>(distance_matrix), 10);
    } catch (const char* msg) {
        assert(strcmp(msg, "neighborhood invalido!") == STRING_MATCH);
    }

    print_sub_test_end();
    return EXIT_SUCCESS;
}

int test_generate_random_neighbor() {
    print_sub_test_begin("generate_random_neighbor", "Testando a geracao de vizinho ALEATORIO");

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
    Solution neighbor = generate_random_neighbor(solution, reinterpret_cast<int *>(distance_matrix));

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

int test_neighborhood_generator() {
    print_test_begin("neighborhood-generator.cpp");
    test_generate_neighbor_swap();
    test_generate_neighbor_reinsertion();
    test_generate_neighbor_error();
    test_generate_random_neighbor();
    print_test_end("neighborhood-generator.cpp");
    return EXIT_SUCCESS;
}