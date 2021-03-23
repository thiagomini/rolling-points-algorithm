//
// Módulo para definir métodos de busca local (vizinhança)
//

#ifndef ALGORITMO_TCC_SWAP_H
#define ALGORITMO_TCC_SWAP_H

#include "../data_structures/solution.h"

/**
 * Troca aleatoriamente duas posições do vetor de solução
 * @param solucao Ponteiro para a solução que se deseja realizar o movimento SWAP
 * @param matriz_distancias A matriz de distâncias do problema, usada para calcular a novo FO da solução
 */
void swap(Solution  &solucao, const int * matriz_distancias);

/**
 * Troca a posição de dois vértices na solução, recalculando a FO
 * @param solucao Ponteiro para a solução que se deseja realizar o movimento SWAP
 * @param posicao_1 Posição do primeiro vértice para realizar a troca
 * @param posicao_2 Posição do segundo vértice para realizar a troca
 * @param matriz_distancias A matriz de distâncias do problema, usada para calcular a novo FO da solução
 */
void swap(Solution  &solucao, size_t posicao_1, size_t posicao_2, const int * matriz_distancias);

/**
 * Calcula a melhor solução após realizar todas as possíveis trocas swap entre os pares da solução.
 * @param solucao Ponteiro para a solução que deseja realizar o swap_opt
 * @param matriz_distancias A matriz de distâncias do problema, usada para calcular a nova FO da solução
 */
void swap_opt(Solution &solucao, const int * matriz_distancias);

int test_swap();

#endif //ALGORITMO_TCC_SWAP_H
