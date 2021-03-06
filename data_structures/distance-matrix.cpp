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

int get_distance(int vertex_1, int vertex_2, const int * distance_matrix, int size) {
    return distance_matrix[vertex_1 * size + vertex_2];
}