//
// Created by Thiago on 21/03/2021.
//


#include "../data_structures/node.h"
#include "../utils/distance.h"
#include "test-logger.h"

using namespace std;

/**
 * Quando a distância entre 2 nós der um valor decimal abaixo de 0.5 (59.20304), deve arredondar para o inteiro abaixo
 * @return
 */
int test_calculate_euclidean_distance_2d_rounded_below() {
    print_sub_test_begin("calculate_euclidean_distance_2d", "Testando arredondamento para baixo");
    node_2d first_node2D = { 1, 64, 96 };
    node_2d second_node2D = { 2, 80, 39 };

    assert(calculate_euclidean_distance_2d(first_node2D, second_node2D) == 59);

    print_sub_test_end();

    return EXIT_SUCCESS;
}

/**
 * Quando a distância entre 2 nós der um valor decimal >= a 0.5 (54.589376), deve arredondar para o inteiro acima
 * @return
 */
int test_calculate_euclidean_distance_2d_rounded_above() {
    print_sub_test_begin("calculate_euclidean_distance_2d", "Testando arredondamento para cima");

    node_2d first_node2D = { 1, 64, 96 };
    node_2d second_node2D = { 2, 72, 42 };

    assert(calculate_euclidean_distance_2d(first_node2D, second_node2D) == 55);
    print_sub_test_end();

    return EXIT_SUCCESS;
}

int test_calculate_euclidean_distance_2d_simple() {
    print_sub_test_begin("calculate_euclidean_distance_2d", "Testando para valores simples");

    node_2d first_node2D = { 1, 0, 20 };
    node_2d second_node2D = { 2, 0, 25 };

    assert(calculate_euclidean_distance_2d(first_node2D, second_node2D) == 5);
    print_sub_test_end();

    return EXIT_SUCCESS;
}

int test_calculate_euclidean_distance_2d_zero_x() {
    print_sub_test_begin("calculate_euclidean_distance_2d", "Testando para valores de x zerados");

    node_2d first_node2D = { 1, 0, 20 };
    node_2d second_node2D = { 2, 0, 25 };

    assert(calculate_euclidean_distance_2d(first_node2D, second_node2D) == 5);
    print_sub_test_end();

    return EXIT_SUCCESS;
}

int test_calculate_euclidean_distance_2d_zero_y() {
    print_sub_test_begin("calculate_euclidean_distance_2d", "Testando para valores de y zerados");

    node_2d first_node2D = { 1, 10, 0 };
    node_2d second_node2D = { 2, 15, 0 };

    assert(calculate_euclidean_distance_2d(first_node2D, second_node2D) == 5);
    print_sub_test_end();

    return EXIT_SUCCESS;
}

int test_calculate_euclidean_both_zero() {
    print_sub_test_begin("calculate_euclidean_distance_2d", "Testando para ambos valores zerados");
    node_2d first_node2D = { 1, 0, 0 };
    node_2d second_node2D = { 2, 0, 0 };

    assert(calculate_euclidean_distance_2d(first_node2D, second_node2D) == 0);
    print_sub_test_end();

    return EXIT_SUCCESS;
}

int test_distance() {
    print_test_begin("distance.cpp");

    test_calculate_euclidean_distance_2d_simple();
    test_calculate_euclidean_distance_2d_rounded_below();
    test_calculate_euclidean_distance_2d_rounded_above();
    test_calculate_euclidean_distance_2d_zero_x();
    test_calculate_euclidean_distance_2d_zero_y();
    test_calculate_euclidean_both_zero();

    print_test_end("distance.cpp");

    return EXIT_SUCCESS;
}