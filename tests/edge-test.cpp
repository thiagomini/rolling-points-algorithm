//
// Created by Thiago on 03/04/2021.
//

#include <cassert>
#include "../data_structures/edge.h"
#include "test-logger.h"
#include "../utils/string-utils.h"

int test_extract_edges() {
    print_sub_test_begin("extract_edges", "Testando extracao de arestas de uma solucao");

    // Arrange
    Solution solution = {
            .objective_function = 288,
            .size_of_solution = 3,
            .vertices = {0, 1, 2}
    };

    // Act
    std::vector<edge> extracted_edges = extract_edges(solution);

    // Assert
    assert(extracted_edges.size() == 3);

    assert(extracted_edges.at(0).first_node == 0);
    assert(extracted_edges.at(0).second_node == 1);

    assert(extracted_edges.at(1).first_node == 1);
    assert(extracted_edges.at(1).second_node == 2);

    assert(extracted_edges.at(2).first_node == 2);
    assert(extracted_edges.at(2).second_node == 0);

    print_sub_test_end();
    return EXIT_SUCCESS;
}

int test_edges_are_equal_same_edges() {
    print_sub_test_begin("edges_are_equal", "Testando a igualdade entre duas arestas identicas");

    // Arrange
    edge edge1 = {1, 2};
    edge edge2 = {1, 2};

    // Act
    bool equal = edges_are_equal(edge1, edge2);

    // Assert
    assert(equal == true);
    print_sub_test_end();

    return EXIT_SUCCESS;
}

int test_edges_are_equal_different_edges() {
    print_sub_test_begin("edges_are_equal", "Testando a igualdade entre duas arestas diferentes");

    // Arrange
    edge edge1 = {1, 2};
    edge edge2 = {2, 3};

    // Act
    bool equal = edges_are_equal(edge1, edge2);

    // Assert
    assert(equal == false);
    print_sub_test_end();

    return EXIT_SUCCESS;
}

int test_edges_are_equal_same_vertices() {
    print_sub_test_begin("edges_are_equal", "Testando para duas arestas com mesmos vertices em posicoes diferentes");

    // Arrange
    edge edge1 = {1, 2};
    edge edge2 = {2, 1};

    // Act
    bool equal = edges_are_equal(edge1, edge2);

    // Assert
    assert(equal == false);
    print_sub_test_end();

    return EXIT_SUCCESS;
}

int test_has_consecutive_edge_all_true() {
    print_sub_test_begin("has_consecutive_edge", "Testando quando todas as arestas sao consecutivas");

    // Arrange
    int edges[3] = {1, 2, 3};

    // Act
    bool has_consecutive = has_consecutive_edge(edges, 3);

    // Assert
    assert(has_consecutive == true);
    print_sub_test_end();

    return EXIT_SUCCESS;
}

int test_has_consecutive_edge_one_true() {
    print_sub_test_begin("has_consecutive_edge", "Testando para apenas uma aresta consecutiva");

    // Arrange
    int edges[4] = {1, 3, 5, 6};

    // Act
    bool has_consecutive = has_consecutive_edge(edges, 4);

    // Assert
    assert(has_consecutive == true);
    print_sub_test_end();

    return EXIT_SUCCESS;
}

int test_get_first_edge() {
    print_sub_test_begin("get_edge", "Testando recuperar primeira aresta da solucao");

    Solution solution = {
            .objective_function = 0,
            .size_of_solution = 3,
            .vertices = {1, 2, 3}
    };

    edge first_edge = get_edge(0, solution);

    assert(first_edge.first_node == 1);
    assert(first_edge.second_node == 2);

    print_sub_test_end();
    return EXIT_SUCCESS;
}

int test_get_last_edge() {
    print_sub_test_begin("get_edge", "Testando recuperar ultima aresta da solucao");

    Solution solution = {
            .objective_function = 0,
            .size_of_solution = 3,
            .vertices = {1, 2, 3}
    };

    edge first_edge = get_edge(2, solution);

    assert(first_edge.first_node == 3);
    assert(first_edge.second_node == 1);

    print_sub_test_end();
    return EXIT_SUCCESS;
}

int test_get_incorrect_index_edge() {
    print_sub_test_begin("get_edge", "Testando recuperar aresta de posicao inexistente");

    Solution solution = {
            .objective_function = 0,
            .size_of_solution = 3,
            .vertices = {1, 2, 3}
    };

    try {
        get_edge(3, solution);
    } catch (const char * error) {
        assert(strings_are_equal(error, "Aresta inexistente"));
        print_sub_test_end();
        return EXIT_SUCCESS;
    }

    throw "Teste Falhou";
}

int test_has_consecutive_edge_false() {
    print_sub_test_begin("has_consecutive_edge", "Testando para apenas uma aresta consecutiva");

    // Arrange
    int edges[4] = {1, 3, 5, 7};

    // Act
    bool has_consecutive = has_consecutive_edge(edges, 4);

    // Assert
    assert(has_consecutive == false);
    print_sub_test_end();

    return EXIT_SUCCESS;
}

int test_get_edges() {
    print_sub_test_begin("get_edges", "Testando a recuperacao de arestas especificas de uma solucao");

    // Arrange
    int positions[3] = {0, 1, 2};
    Solution solution = {
            .objective_function = 0,
            .size_of_solution = 4,
            .vertices = {0, 4, 2, 1}
    };


    // Act
    vector<edge> edges = get_edges(positions, 3, solution);

    // Assert
    assert(edges.at(0).first_node == 0);
    assert(edges.at(0).second_node == 4);

    assert(edges.at(1).first_node == 4);
    assert(edges.at(1).second_node == 2);

    assert(edges.at(2).first_node == 2);
    assert(edges.at(2).second_node == 1);

    print_sub_test_end();

    return EXIT_SUCCESS;
}

int test_swap_edge() {
    print_sub_test_begin("swap_edge", "Testando a inversao do direcionamento da aresta");

    // Arrange
    edge edge = {1, 2};

    // Act
    swap_edge(edge);

    // Assert
    assert(edge.first_node == 2);
    assert(edge.second_node == 1);
    print_sub_test_end();

    return EXIT_SUCCESS;
}

int test_edge() {
    print_test_begin("edge.cpp");
    test_extract_edges();
    test_edges_are_equal_same_edges();
    test_edges_are_equal_different_edges();
    test_edges_are_equal_same_vertices();
    test_swap_edge();
    test_has_consecutive_edge_all_true();
    test_has_consecutive_edge_one_true();
    test_has_consecutive_edge_false();
    test_get_first_edge();
    test_get_last_edge();
    test_get_incorrect_index_edge();
    test_get_edges();
    print_test_end("edge.cpp");

    return EXIT_SUCCESS;
}