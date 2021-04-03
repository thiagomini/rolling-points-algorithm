//
// Created by Thiago on 03/04/2021.
//

#ifndef ALGORITMO_TCC_2_OPTIMAL_H
#define ALGORITMO_TCC_2_OPTIMAL_H

#include "../data_structures/solution.h"

/**
 * Realiza o movimento 2-Optimal em uma solução, que consiste em retirar duas arestas não-adjacentes do grafo e
 * reconstruir o ciclo hamiltoniano novamente. Uma aresta A, indicado por um número inteiro N, liga os vértices N e N+1
 * @param solution - Ponteiro para a Solução
 * @param distance_matrix - Ponteiro para a matriz de distâncias.
 * @param edge_1 - Primeira aresta do grafo.
 * @param edge_2 - Segunda aresta do grafo.
 * @throws Erro caso as arestas sejam adjacentes (exemplo: 0 e 1)
 * @example
 *  two_optimal_move(solution, distance_matrix, 0, 2) // Remove as arestas que ligam o vértice 0 ao 1, e a aresta que
 *  liga o vértice 2 ao 3
 */
void two_optimal_move(Solution &solution, const int * distance_matrix, size_t edge_1, size_t edge_2);

void two_optimal_move(Solution &solution, const int * distance_matrix);

Solution two_optimal(Solution &solution, const int * distance_matrix);

int test_two_optimal();

#endif //ALGORITMO_TCC_2_OPTIMAL_H
