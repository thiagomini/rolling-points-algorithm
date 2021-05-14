//
// Created by Thiago on 13/03/2021.
//

//
// Arquivo contendo funções para calcular a distância entre 2 nós de um grafo
//

#include "../data_structures/node.h"
#include <cmath>
#include <cassert>
#include <cmath>

#define MAX(X, Y) ((X) > (Y) ? (X) : (Y))
#define MIN(X, Y) ((X) < (Y) ? (X) : (Y))

/**
 * Retorna a diferença absoluta entre dois valores
 * @example
 * DIFF(1, 2) // => 1 <br>
 * DIFF(0, 0) // => 0 <br>
 * DIFF(4, 2) // => 2 <br>
 */
#define DIFF(X, Y) ((X) > (Y) ? (X) - (Y) : (Y) - X)

#ifndef ALGORITMO_TCC_DISTANCE_H
#define ALGORITMO_TCC_DISTANCE_H

/**
 * Calcula a distância euclidiana entre 2 pontos, considerando um plano cartesiano 2d
 * @param node_1 - Coordenadas do ponto 1
 * @param node_2 - Coordenadas do ponto 2
 * @return
 */
int calculate_euclidean_distance_2d(node_2d node_1, node_2d node_2);

/**
 * Testa todas as funções do módulo distance
 * @return 0 se todos os testes passaram com sucesso, 1 do contrário
 */
int test_distance();

#endif //ALGORITMO_TCC_DISTANCE_H
