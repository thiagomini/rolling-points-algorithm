//
// Created by Thiago on 10/05/2021.
//

#include <cassert>
#include "../data_structures/optimized-solution.h"
#include "test-logger.h"
#include "../utils/array.h"

int test_opt_solution_concatenate() {
    print_sub_test_begin("concatenate_solutions", "Testando concatenacao de solucoes");
    // Todo: Corrigir Teste
    // Arrange
    OptimizedSolution solution_1 = {
            .C = 65,
            .T = 45,
            .W = 2,
            .size = 3,
            .vertices = {0, 1, 2}
    };

    OptimizedSolution solution_2 = {
            .C = 70,
            .T = 40,
            .W = 3,
            .size = 3,
            .vertices = {3, 4, 5}
    };
    ;

    int matrix[6][6] = {
            {0, 20, 0, 0, 0, 0},
            {20, 0, 25, 0, 0, 0},
            {0, 25, 0, 17, 0, 0},
            {0, 0, 17, 0, 30, 0},
            {0, 0, 0, 30, 0, 10},
            {0, 0, 0, 0, 10, 0},
    };


    // Act
    OptimizedSolution concatenated_solution = concatenate_solutions(solution_1, solution_2,
                                                                    reinterpret_cast<const int *>(matrix), 6);

    // Prepare-Response
    int full_array[6] = {0, 1, 2, 3, 4, 5};

    // Assert
    assert(concatenated_solution.C == 321);
    assert(concatenated_solution.W == 5);
    assert(concatenated_solution.size == 6);
    assert(arrays_are_equal(concatenated_solution.vertices, full_array, 6));
    print_sub_test_end();

    return EXIT_SUCCESS;

}

int test_get_last_vertex() {
    print_sub_test_begin("get_last_vertex", "Testando a recuperacao do ultimo vertice");

    // Arrange
    OptimizedSolution solution = {
            .size = 3,
            .vertices = {1, 2, 3},
    };

    // Act
    int last_vertex = solution.last_vertex();

    // Assert
    assert(last_vertex == 3);
    print_sub_test_end();

    return EXIT_SUCCESS;
}

int test_equals_array_true() {
    print_sub_test_begin("equals", "Testando igualdade com array_initializer");

    // Arrange
    OptimizedSolution solution = {
            .C = 10,
            .T = 20,
            .W = 3,
            .size = 3,
            .vertices = {1, 2, 3},
    };


    // Act
    bool are_equal = solution.equals(10, 20, 3, 3, {1, 2, 3});

    // Assert
    assert(are_equal == true);
    print_sub_test_end();
    return EXIT_SUCCESS;
}

int test_equals_array_false() {
    print_sub_test_begin("equals", "Testando desigualdade com array_initializer");

    // Arrange
    OptimizedSolution solution = {
            .C = 10,
            .T = 20,
            .W = 3,
            .size = 3,
            .vertices = {1, 2, 3},
    };


    // Act
    bool are_equal = solution.equals(10, 20, 3, 3, {1, 2, 4});

    // Assert
    assert(are_equal == false);
    print_sub_test_end();
    return EXIT_SUCCESS;
}

int test_equals_vector_true() {
    print_sub_test_begin("equals", "Testando igualdade com vector");

    // Arrange
    OptimizedSolution solution = {
            .C = 10,
            .T = 20,
            .W = 3,
            .size = 3,
            .vertices = {1, 2, 3},
    };


    // Act
    bool are_equal = solution.equals(10, 20, 3, 3, std::vector<int>{1, 2, 3});

    // Assert
    assert(are_equal == true);
    print_sub_test_end();
    return EXIT_SUCCESS;
}

int test_equals_vector_false() {
    print_sub_test_begin("equals", "Testando desigualdade com vector");

    // Arrange
    OptimizedSolution solution = {
            .C = 10,
            .T = 20,
            .W = 3,
            .size = 3,
            .vertices = {1, 2, 3},
    };


    // Act
    bool are_equal = solution.equals(10, 20, 3, 3, std::vector<int>{1, 2, 4});

    // Assert
    assert(are_equal == false);
    print_sub_test_end();
    return EXIT_SUCCESS;
}

int test_equals_solution_true() {
    print_sub_test_begin("equals", "Testando igualdade com outra solucao");

    // Arrange
    OptimizedSolution solution = {
            .C = 10,
            .T = 20,
            .W = 3,
            .size = 3,
            .vertices = {1, 2, 3},
    };

    OptimizedSolution other_solution = {
            .C = 10,
            .T = 20,
            .W = 3,
            .size = 3,
            .vertices = {1, 2, 3},
    };

    // Act
    bool are_equal = solution == other_solution;

    // Assert
    assert(are_equal == true);
    print_sub_test_end();
    return EXIT_SUCCESS;
}

int test_equals_solution_false() {
    print_sub_test_begin("equals", "Testando desigualdade com outra solucao");

    // Arrange
    OptimizedSolution solution = {
            .C = 10,
            .T = 20,
            .W = 3,
            .size = 3,
            .vertices = {1, 2, 3},
    };

    OptimizedSolution other_solution = {
            .C = 10,
            .T = 20,
            .W = 3,
            .size = 3,
            .vertices = {1, 2, 5},
    };

    // Act
    bool are_equal = solution == other_solution;

    // Assert
    assert(are_equal == false);
    print_sub_test_end();
    return EXIT_SUCCESS;
}


int test_optimized_solution() {
    print_test_begin("optimized-solution.cpp");
    test_opt_solution_concatenate();
    test_get_last_vertex();
    test_equals_array_true();
    test_equals_array_false();
    test_equals_vector_true();
    test_equals_vector_false();
    test_equals_solution_true();
    test_equals_solution_false();
    print_test_end("optimized-solution.cpp");
    return EXIT_SUCCESS;
}

OptimizedSolution clone(OptimizedSolution &source) {
    OptimizedSolution destination;
    memcpy(&destination, &source, sizeof(source));
    return destination;
}
