//
// Created by Thiago on 20/03/2021.
//

#include "distance-matrix.h"
#include "../utils/distance.h"
#include "iostream"

using namespace std;


int ** build_distance_matrix(node_2d * nodes, size_t size) {

    // Cria as linhas
    static auto ** distance_matrix = new int * [size];
    for (size_t i = 0; i < size; i++) {
        distance_matrix[i] = new int [size];
    }

    // Preenche as células
    for (size_t row = 0; row < size; row++) {
        for (size_t column = 0; column < size; column++) {
            distance_matrix[row][column] = calculate_euclidean_distance_2d(nodes[row], nodes[column]);
        }
    }

    return distance_matrix;
}

void test_build_distance_matrix() {
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
}

void test_distance_matrix() {
    test_build_distance_matrix();
    cout << "[distance-matrix.cpp] Todos os testes passaram com sucesso!" << endl;
}



