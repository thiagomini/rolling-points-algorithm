//
// Módulo para construção da matriz de distâncias de acordo com o vetor de nós passados
//

#ifndef ALGORITMO_TCC_DISTANCE_MATRIX_H
#define ALGORITMO_TCC_DISTANCE_MATRIX_H

#include <cstdio>
#include "node.h"

typedef struct {
    int * distances;
    int size;
} distance_matrix;

/**
 * Constrói a matriz de distâncias entre os nós, de acordo com o vetor de nós passado como parâmetro. cada célula
 * da matriz em uma linha "i" e coluna "j" representa a distância do nó "i" até o nó "j".
 * @example
 *  node_2d nodes[3] = {
 *           {1, 64, 96},
 *           {2, 80, 39},
 *           {3, 69, 23}
 *  };
 *
 *  int ** calculated_distance_matrix = build_distance_matrix(reinterpret_cast<node_2d *>(nodes), 3);
 * @param nodes A lista de nós que será utilizada para construir a matriz de distâncias
 * @param size O número de nós
 * @return
 */
int ** build_distance_matrix(node_2d * nodes, size_t size);

/**
 * Testa todas as funções do módulo <b>distance-matrix</b>
 */
int test_distance_matrix();

#endif //ALGORITMO_TCC_DISTANCE_MATRIX_H
