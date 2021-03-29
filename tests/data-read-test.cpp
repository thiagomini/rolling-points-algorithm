//
// Created by Thiago on 21/03/2021.
//

#include <cassert>
#include "../data_structures/node.h"
#include "../data_structures/data-read.h"
#include "test-logger.h"

int test_read_nodes_euc_2d() {
    print_sub_test_begin("read_nodes_euc_2d", "Testando leitura de arquivo .tsp do tipo EUC_2D");

    // Arrange
    char arquivo[] = "../instances/test_tsp_euc_2d.tsp";

    // Act
    node_2d * read_nodes = read_nodes_euc_2d(arquivo);

    // Prepare-Response
    int expected_nodes[3][3] = {
            {1, 64, 96},
            {2, 80, 39},
            {3, 69, 23},
    };

    // Assert
    assert(read_nodes != nullptr);

    for (int i = 0; i < 3; ++i) {
        assert(read_nodes[i].number == expected_nodes[i][0]);
        assert(read_nodes[i].x == expected_nodes[i][1]);
        assert(read_nodes[i].y == expected_nodes[i][2]);
    }

    print_sub_test_end();

    return EXIT_SUCCESS;
}

int test_data_read() {
    print_test_begin("data-read.cpp");
    test_read_nodes_euc_2d();
    print_test_end("data-read.cpp");

    return EXIT_SUCCESS;
}

