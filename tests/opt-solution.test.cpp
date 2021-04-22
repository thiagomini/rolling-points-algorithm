//
// Created by Thiago on 18/04/2021.
//


#include <cassert>
#include "test-logger.h"
#include "../data_structures/OptSolution.h"

int test_opt_solution_clone() {
    print_sub_test_begin("clone", "Testando clonagem de solucao");

    // Arrange
    OptSolution solution_1 =  OptSolution(65, 2, 45, {0, 1, 2});

    // Act
    OptSolution solution_2 = solution_1.clone();

    // Assert
    assert(solution_2.C == solution_1.C);
    assert(solution_2.T == solution_1.T);
    assert(solution_2.W == solution_1.W);
    assert(solution_2.vertices == solution_1.vertices);

    print_sub_test_end();

    return EXIT_SUCCESS;
}

int test_opt_solution_clone_different_reference() {
    print_sub_test_begin("clone", "Testando se clonagem de solucao nao reutiliza ponteiro de vertices");

    // Arrange
    OptSolution solution_1 =  OptSolution(65, 2, 45, {0, 1, 2});
    OptSolution solution_2 = solution_1.clone();

    // Act
    solution_2.vertices.at(0) = 10;

    // Assert
    assert(solution_1.vertices.at(0) != 10);

    print_sub_test_end();

    return EXIT_SUCCESS;
}


int test_opt_solution_concatenate() {
    print_sub_test_begin("concatenate_solutions", "Testando concatenacao de solucoes");

    // Arrange
    OptSolution solution_1 = OptSolution(65, 2, 45, {0, 1, 2});
    OptSolution solution_2 = OptSolution(50, 3, 40, {3, 4, 5});

    int matrix[6][6] = {
            {0, 20, 0, 0, 0, 0},
            {20, 0, 25, 0, 0, 0},
            {0, 25, 0, 17, 0, 0},
            {0, 0, 17, 0, 30, 0},
            {0, 0, 0, 30, 0, 10},
            {0, 0, 0, 0, 10, 0},
    };

    distance_matrix distance_matrix = {
            .distances = reinterpret_cast<int *>(matrix),
            .size = 6
    };

    // Act
    OptSolution concatenated_solution = concatenate_solutions(solution_1, solution_2, distance_matrix);


    // Assert
    assert(concatenated_solution.C == 301);
    print_sub_test_end();

    return EXIT_SUCCESS;

}


int test_opt_solution() {
    print_test_begin("opt-solution.cpp");
    test_opt_solution_concatenate();
    test_opt_solution_clone();
    test_opt_solution_clone_different_reference();
    print_test_end("opt-solution.cpp");
    return EXIT_SUCCESS;
}