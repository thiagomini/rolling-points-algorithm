//
// Created by Thiago on 13/03/2021.
//

//
// Arquivo contendo funções para calcular a distância entre 2 nós de um grafo
//

#include "node.h"
#include <cmath>
#include <cassert>

#define MAX(X, Y) ((X) > (Y) ? (X) : (Y))

#ifndef ALGORITMO_TCC_DISTANCE_H
#define ALGORITMO_TCC_DISTANCE_H

/**
 * Calcula a distância euclidiana entre 2 pontos, considerando um plano cartesiano 2d
 * @param node_1 - Coordenadas do ponto 1
 * @param node_2 - Coordenadas do ponto 2
 * @return
 */
int calculate_euclidean_distance_2d(node_2d node_1, node_2d node_2);


// Testes
int test_calculate_euclidean_distance_2d();
int test_calculate_euclidean_distance_2d_simple();
int test_calculate_euclidean_distance_2d_zero_x();
int test_calculate_euclidean_distance_2d_zero_y();
int test_calculate_euclidean_both_zero();

#endif //ALGORITMO_TCC_DISTANCE_H
