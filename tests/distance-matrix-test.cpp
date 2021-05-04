//
// Created by Thiago on 21/03/2021.
//

#include <cassert>
#include "../data_structures/node.h"
#include "../data_structures/distance-matrix.h"
#include "test-logger.h"

int test_build_distance_matrix() {
    print_sub_test_begin("build_distance_matrix", "Testando construcao de matriz de distancias");

    node_2d nodes[3] = {
            {1, 64, 96},
            {2, 80, 39},
            {3, 69, 23},
    };

    int ** calculated_distance_matrix = build_distance_matrix(reinterpret_cast<node_2d *>(nodes), 3);

    int expected_distance_matrix[3][3] = {
            {0, 59, 73},
            {59, 0, 19},
            {73, 19, 0}
    };

    for (size_t row = 0; row < 3; row++) {
        for (size_t column = 0; column < 3; column++) {
            assert(calculated_distance_matrix[row][column] == expected_distance_matrix[row][column]);
        }
    }

    print_sub_test_end();

    return EXIT_SUCCESS;
}

int test_get_distance() {
    print_sub_test_begin("get_distance", "Testando encontrar a distancia entre dois vertices");

    // Arrange
    int distance_matrix[3][3] = {
            {0, 59, 73},
            {59, 0, 19},
            {73, 19, 0}
    };

    // Act
    int distance_0_0 = get_distance(0, 0, reinterpret_cast<const int *>(distance_matrix), 3);
    int distance_1_0 = get_distance(1, 0, reinterpret_cast<const int *>(distance_matrix), 3);
    int distance_2_1 = get_distance(2, 1, reinterpret_cast<const int *>(distance_matrix), 3);

    // Assert
    assert(distance_0_0 == 0);
    assert(distance_1_0 == 59);
    assert(distance_2_1 == 19);

    print_sub_test_end();
    return EXIT_SUCCESS;
}

int test_distance_matrix() {
    print_test_begin("distance-matrix.cpp");
    test_build_distance_matrix();
    test_get_distance();
    print_test_end("distance-matrix.cpp");

    return EXIT_SUCCESS;
}


