//
// Created by Thiago on 10/05/2021.
//

#include <cassert>
#include "../data_structures/optimized-solution.h"
#include "test-logger.h"
#include "../utils/array.h"
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

int test_opt_solution_concatenate() {
    print_sub_test_begin("concatenate_solutions", "Testando concatenacao de solucoes");

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
    assert(concatenated_solution.T == 102);
    assert(concatenated_solution.W == 5);
    assert(concatenated_solution.size == 6);
    assert(arrays_are_equal(concatenated_solution.vertices, full_array, 6));
    print_sub_test_end();

    return EXIT_SUCCESS;

}

int test_opt_single_vertex_solution_concatenate() {
    print_sub_test_begin("concatenate_solutions", "Testando concatenacao de solucoes com um vertice");
    // Arrange
    OptimizedSolution solution_1 = {
            .C = 0,
            .T = 0,
            .W = 1,
            .size = 1,
            .vertices = {1}
    };

    OptimizedSolution solution_2 = {
            .C = 0,
            .T = 0,
            .W = 1,
            .size = 1,
            .vertices = {2}
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
    int full_array[6] = {1, 2};

    // Assert
    assert(concatenated_solution.C == 25);
    assert(concatenated_solution.W == 2);
    assert(concatenated_solution.T == 25);
    assert(concatenated_solution.size == 2);
    assert(arrays_are_equal(concatenated_solution.vertices, full_array, 2));
    print_sub_test_end();

    return EXIT_SUCCESS;

}

int test_opt_solution_concatenate_array() {
    print_sub_test_begin("concatenate_solutions", "Testando concatenacao de solucoes em array");

    // Arrange
    int distances[3][3] = {
            {0, 59, 73},
            {59, 0, 19},
            {73, 19, 0}
    };


    OptimizedSolution solutions[3] = {
            { .C = 0, .T = 0, .W = 0, .size = 1, .vertices = {0} },
            { .C = 0, .T = 0, .W = 1, .size = 1, .vertices = {1} },
            { .C = 0, .T = 0, .W = 1, .size = 1, .vertices = {2} },
    };

    // Act
    OptimizedSolution concatenated_solution = concatenate_solutions(solutions, reinterpret_cast<const int *>(distances), 3, 3);

    // Prepare-Response
    int full_array[3] = {0, 1, 2};

    // Assert
    assert(concatenated_solution.C == 137);
    assert(concatenated_solution.T == 78);
    assert(concatenated_solution.W == 2);
    assert(arrays_are_equal(concatenated_solution.vertices, full_array, 3));

    print_sub_test_end();

    return EXIT_SUCCESS;
}

int test_opt_solution_concatenate_vector() {
    print_sub_test_begin("concatenate_solutions", "Testando concatenacao de solucoes em array");

    // Arrange
    int distances[3][3] = {
            {0, 59, 73},
            {59, 0, 19},
            {73, 19, 0}
    };


    vector<OptimizedSolution> solutions = {
            { .C = 0, .T = 0, .W = 0, .size = 1, .vertices = {0} },
            { .C = 0, .T = 0, .W = 1, .size = 1, .vertices = {1} },
            { .C = 0, .T = 0, .W = 1, .size = 1, .vertices = {2} },
    };

    // Act
    OptimizedSolution concatenated_solution = concatenate_solutions(solutions, reinterpret_cast<const int *>(distances), 3);

    // Prepare-Response
    int full_array[3] = {0, 1, 2};

    // Assert
    assert(concatenated_solution.C == 137);
    assert(concatenated_solution.T == 78);
    assert(concatenated_solution.W == 2);
    assert(arrays_are_equal(concatenated_solution.vertices, full_array, 3));

    print_sub_test_end();

    return EXIT_SUCCESS;
}

int test_to_normal_solution() {
    print_sub_test_begin("to_normal_solution", "Testando a transformacao para uma Solution");

    // Arrange
    OptimizedSolution opt_solution = {
            .C = 100,
            .T = 50,
            .size = 3,
            .vertices = {1, 2, 3}
    };

    // Act
    Solution solution = opt_solution.to_normal_solution();

    // Prepare-Response
    int expected_array[3] = {1, 2, 3};

    // Assert
    assert(arrays_are_equal(expected_array, solution.vertices, 3));
    assert(solution.objective_function == 100);
    assert(solution.size_of_solution == 3);

    print_sub_test_end();

    return EXIT_SUCCESS;
}

int test_optimized_solution() {
    print_test_begin("optimized-solution.cpp");
    test_get_last_vertex();
    test_equals_array_true();
    test_equals_array_false();
    test_equals_vector_true();
    test_equals_vector_false();
    test_equals_solution_true();
    test_equals_solution_false();
    test_opt_solution_concatenate();
    test_opt_single_vertex_solution_concatenate();
    test_opt_solution_concatenate_array();
    test_opt_solution_concatenate_vector();
    test_to_normal_solution();
    print_test_end("optimized-solution.cpp");
    return EXIT_SUCCESS;
}