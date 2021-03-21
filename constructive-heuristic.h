//
// Created by Thiago on 11/03/2021.
//

#ifndef ALGORITMO_TCC_CONSTRUCTIVE_HEURISTIC_H
#define ALGORITMO_TCC_CONSTRUCTIVE_HEURISTIC_H
#include "heuristic.h"

/**
 * Constrói uma solução aleatória de nós percorridos por movimento de "shuffle" da ordem dos elementos.
 * @param size - Tamanho da lista de vértices
 * @return Ponteiro para solução criada
 */
Solution build_random_solution(size_t size, const int * distance_matrix);

void test_constructive_heuristic();


#endif //ALGORITMO_TCC_CONSTRUCTIVE_HEURISTIC_H
