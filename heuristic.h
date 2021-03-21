//
// Created by Thiago on 20/03/2021.
//

#ifndef ALGORITMO_TCC_HEURISTIC_H
#define ALGORITMO_TCC_HEURISTIC_H

#include <cstdio>
#include "data_structures/solution.h"

/**
 * Heurística iterativa aleatória, funciona com base na criação de várias soluções aleatórias e comparando
 * os valores de suas FOs. O algoritmo para ao fim de um número de iterações definido.
 *
 * @param distance_matrix A matriz de distâncias entre os vértices do grafo
 * @param number_of_vertices O número de vértices contidos no grafo
 * @return Ponteiro para a melhor solução
 */
Solution * random_iterative_heuristic(int * distance_matrix, size_t number_of_vertices);

int test_heuristic();

#endif //ALGORITMO_TCC_HEURISTIC_H
