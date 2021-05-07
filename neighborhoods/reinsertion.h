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
void reinsert(Solution &solucao, const int * matriz_distancias, int size = SIZE);

/**
 * Reinsere um nó da solução um outra posição da solução, reajustando os demais nós "para trás"
 * @param solucao Ponteiro para a solução que deseja realizar o reinsertion
 * @param posicao_1 Posição do vértice que será reinserido
 * @param posicao_2 Posição que o vértice escolhido será inserido
 * @param matriz_distancias A matriz de distâncias do problema, usada para calcular a nova FO da solução
 */
void reinsert(Solution &solucao, size_t posicao_1, size_t posicao_2, const int * matriz_distancias, int size = SIZE);

/**
 * Constrói e retorna uma solução vizinha aplicando o movimento reinsertion em posições definidas
 * @param solucao Ponteiro para a solução que deseja realizar o reinsertion
 * @param posicao_1 Posição do vértice que será reinserido
 * @param posicao_2 Posição que o vértice escolhido será inserido
 * @param matriz_distancias A matriz de distâncias do problema, usada para calcular a nova FO da solução
 * @return Uma solução vizinha construída com o movimento reinsertion
 */
Solution build_reinsert(Solution solucao, size_t posicao_1, size_t posicao_2, const int * matriz_distancias, int size = SIZE);

/**
 * Constrói e retorna uma solução vizinha aplicando o movimento reinsertion em posições aleatórias
 * @param solucao Ponteiro para a solução que deseja realizar o reinsertion
 * @param posicao_1 Posição do vértice que será reinserido
 * @param posicao_2 Posição que o vértice escolhido será inserido
 * @param matriz_distancias A matriz de distâncias do problema, usada para calcular a nova FO da solução
 * @return Uma solução vizinha, construída com o movimento reinsertion
 */
Solution build_reinsert(Solution solucao, const int * matriz_distancias, int size = SIZE);

/**
 * Calcula a melhor solução após realizar a reinserção de um nó em todas as demais posições
 * @param solucao Solução que deseja realizar o swap_opt
 * @param matriz_distancias A matriz de distâncias do problema, usada para calcular a nova FO da solução
 * @returns A solução com melhor FO após realizar a busca local
 */
Solution reinsert_opt(Solution solucao, const int * matriz_distancias, int size = SIZE, int strategy = BEST_IMPROVEMENT);

int test_reinsert();


#endif //ALGORITMO_TCC_REINSERTION_H
