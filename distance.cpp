//
// Created by Thiago on 13/03/2021.
//

#include "distance.h"
#include "iostream"

using namespace std;

int calculate_euclidean_distance_2d(node_2d node_1, node_2d node_2) {
    int distance_x = node_2.x - node_1.x;
    int distance_y = node_2.y - node_1.y;
    int distance_of_nodes = lround(sqrt(distance_x*distance_x + distance_y*distance_y));
    return distance_of_nodes;
}



// Testes


/**
 * Quando a distância entre 2 nós der um valor decimal abaixo de 0.5 (59.20304), deve arredondar para o inteiro abaixo
 * @return
 */
int test_calculate_euclidean_distance_2d_rounded_below() {
    node_2d first_node2D = { 1, 64, 96 };
    node_2d second_node2D = { 2, 80, 39 };

    assert(calculate_euclidean_distance_2d(first_node2D, second_node2D) == 59);
    return 1;
}


/**
 * Quando a distância entre 2 nós der um valor decimal >= a 0.5 (54.589376), deve arredondar para o inteiro acima
 * @return
 */
int test_calculate_euclidean_distance_2d_rounded_above() {
    node_2d first_node2D = { 1, 64, 96 };
    node_2d second_node2D = { 2, 72, 42 };

    assert(calculate_euclidean_distance_2d(first_node2D, second_node2D) == 55);

    return 1;
}



int test_calculate_euclidean_distance_2d() {
    test_calculate_euclidean_distance_2d_simple();
    test_calculate_euclidean_distance_2d_rounded_below();
    test_calculate_euclidean_distance_2d_rounded_above();
    test_calculate_euclidean_distance_2d_zero_x();
    test_calculate_euclidean_distance_2d_zero_y();
    test_calculate_euclidean_distance_2d_zero_y();
    test_calculate_euclidean_both_zero();
    cout << "\n[distance.cpp] Todos os testes passaram com sucesso!\n";
    return 1;
}

int test_calculate_euclidean_distance_2d_simple() {
    node_2d first_node2D = { 1, 0, 20 };
    node_2d second_node2D = { 2, 0, 25 };

    assert(calculate_euclidean_distance_2d(first_node2D, second_node2D) == 5);

    return 1;
}

int test_calculate_euclidean_distance_2d_zero_x() {
    node_2d first_node2D = { 1, 0, 20 };
    node_2d second_node2D = { 2, 0, 25 };

    assert(calculate_euclidean_distance_2d(first_node2D, second_node2D) == 5);

    return 1;
}

int test_calculate_euclidean_distance_2d_zero_y() {
    node_2d first_node2D = { 1, 10, 0 };
    node_2d second_node2D = { 2, 15, 0 };

    assert(calculate_euclidean_distance_2d(first_node2D, second_node2D) == 5);

    return 1;
}

int test_calculate_euclidean_both_zero() {
    node_2d first_node2D = { 1, 0, 0 };
    node_2d second_node2D = { 2, 0, 0 };

    assert(calculate_euclidean_distance_2d(first_node2D, second_node2D) == 0);

    return 1;
}