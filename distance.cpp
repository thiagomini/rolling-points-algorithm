//
// Created by Thiago on 13/03/2021.
//

#include "distance.h"
#include "iostream"

using namespace std;

int calculate_euclidean_distance_2d(node_2d node_1, node_2d node_2) {
    int distance_x = node_2.x - node_1.x;
    int distance_y = node_2.y - node_1.y;
    int teste = MAX(1, 2);
    int distance_of_nodes = lround(sqrt(distance_x*distance_x + distance_y*distance_y));
    return distance_of_nodes;
}


// Testes
int test_calculate_euclidean_distance_2d() {
    test_calculate_euclidean_distance_2d_simple();
    test_calculate_euclidean_distance_2d_zero_x();
    test_calculate_euclidean_distance_2d_zero_y();
    test_calculate_euclidean_distance_2d_zero_y();
    test_calculate_euclidean_both_zero();
    cout << "[distance.cpp] Todos os testes passaram com sucesso!";
}

int test_calculate_euclidean_distance_2d_simple() {
    node_2d first_node2D = { 0, 20 };
    node_2d second_node2D = { 0, 25 };

    assert(calculate_euclidean_distance_2d(first_node2D, second_node2D) == 5);

    return 1;
}

int test_calculate_euclidean_distance_2d_zero_x() {
    node_2d first_node2D = { 0, 20 };
    node_2d second_node2D = { 0, 25 };

    assert(calculate_euclidean_distance_2d(first_node2D, second_node2D) == 5);

    return 1;
}

int test_calculate_euclidean_distance_2d_zero_y() {
    node_2d first_node2D = { 10, 0 };
    node_2d second_node2D = { 15, 0 };

    assert(calculate_euclidean_distance_2d(first_node2D, second_node2D) == 5);

    return 1;
}

int test_calculate_euclidean_both_zero() {
    node_2d first_node2D = { 0, 0 };
    node_2d second_node2D = { 0, 0 };

    assert(calculate_euclidean_distance_2d(first_node2D, second_node2D) == 0);

    return 1;
}