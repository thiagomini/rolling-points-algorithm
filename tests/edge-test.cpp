//
// Created by Thiago on 03/04/2021.
//

#include <cassert>
#include "../data_structures/edge.h"
#include "test-logger.h"

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
    print_test_end("edge.cpp");

    return EXIT_SUCCESS;
}