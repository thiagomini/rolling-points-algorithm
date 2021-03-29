//
// Created by Thiago on 22/03/2021.
//

#ifndef ALGORITMO_TCC_REINSERTION_H
#define ALGORITMO_TCC_REINSERTION_H

#include "../data_structures/solution.h"

/**
 * Reinsere um nó da solução em uma posição aleatória diferente
 * @param solucao Ponteiro para a solução que deseja realizar o swap_opt
 * @param matriz_distancias A matriz de distâncias do problema, usada para calcular a nova FO da solução
 */
void reinsert(Solution &solucao, const int * matriz_distancias);

/**
 * Reinsere um nó da solução um outra posição da solução, reajustando os demais nós "para trás"
 * @param solucao Ponteiro para a solução que deseja realizar o swap_opt
 * @param posicao_1 Posição do vértice que será reinserido
 * @param posicao_2 Posição que o vértice escolhido será inserido
 * @param matriz_distancias
 */
void reinsert(Solution &solucao, size_t posicao_1, size_t posicao_2, const int * matriz_distancias);

/**
 * Calcula a melhor solução após realizar a reinserção de um nó em todas as demais posições
 * @param solucao Solução que deseja realizar o swap_opt
 * @param matriz_distancias A matriz de distâncias do problema, usada para calcular a nova FO da solução
 * @returns A solução com melhor FO após realizar a busca local
 */
Solution reinsert_opt(Solution solucao, const int * matriz_distancias);

int test_reinsert();


#endif //ALGORITMO_TCC_REINSERTION_H
