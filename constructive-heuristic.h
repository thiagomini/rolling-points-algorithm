//
// Módulo para definição de estratégias de heurísticas construtivas
//

#ifndef ALGORITMO_TCC_CONSTRUCTIVE_HEURISTIC_H
#define ALGORITMO_TCC_CONSTRUCTIVE_HEURISTIC_H
#include "heuristic.h"

/**
 * Constrói uma solução aleatória de nós percorridos por movimento de "shuffle" da ordem dos elementos.
 * @param size - Tamanho da lista de vértices
 * @return Ponteiro para solução criada
 */
Solution build_random_solution(const int * distance_matrix, int size = SIZE);

/**
 * Constrói o array de vértices para a solução, sempre começando do vértice 0
 * @param size - Tamanho do array
 * @return
 */
vector<int> build_vertices_array(size_t size);

void calculate_build_random_solution_time(size_t size, const int * distance_matrix, int times);

int test_constructive_heuristic();


#endif //ALGORITMO_TCC_CONSTRUCTIVE_HEURISTIC_H
