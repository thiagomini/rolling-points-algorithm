//
// Módulo para definir métodos de busca local (vizinhança)
//

#ifndef ALGORITMO_TCC_SWAP_H
#define ALGORITMO_TCC_SWAP_H

#include "../data_structures/solution.h"
#include "../data_structures/optmized-matrix.h"

/**
 * Troca aleatoriamente duas posições do vetor de solução
 * @param solucao Ponteiro para a solução que se deseja realizar o movimento SWAP
 * @param matriz_distancias A matriz de distâncias do problema, usada para calcular a novo FO da solução
 */
void swap(Solution  &solucao, const int * matriz_distancias, int size = SIZE);

/**
 * Troca a posição de dois vértices na solução, recalculando a FO
 * @param solucao Ponteiro para a solução que se deseja realizar o movimento SWAP
 * @param posicao_1 Posição do primeiro vértice para realizar a troca
 * @param posicao_2 Posição do segundo vértice para realizar a troca
 * @param matriz_distancias A matriz de distâncias do problema, usada para calcular a novo FO da solução
 */
void swap(Solution  &solucao, size_t posicao_1, size_t posicao_2, const int * matriz_distancias, int size = SIZE);

/**
 * Constrói e retorna uma solução vizinha aplicando o movimento swap em posições definidas
 * @param solution
 * @param posicao_1 Posição do primeiro vértice para realizar a troca
 * @param posicao_2 Posição do segundo vértice para realizar a troca
 * @param matriz_distancias A matriz de distâncias do problema, usada para calcular a novo FO da solução
 * @return Uma solução vizinha, construída com o movimento swap
 */
Solution build_swap(Solution solution, size_t posicao_1, size_t posicao_2, const int * matriz_distancias, int size = SIZE);

/**
 * Constrói uma solução do tipo Optimized aplicando o movimento swap nos índices definidos
 * @param opt_matrix - Estrutura otimizada em matriz com as sub-soluções
 * @param index_1 - Primeiro índice que será utilizado para o swap
 * @param index_2 - segundo índice que será utilizado para o swap
 * @param distance_matrix - A matriz de distâncias
 * @return Uma solução vizinha, construída com o movimento swap
 */
OptimizedSolution build_swap(OptimizedMatrix &opt_matrix, int index_1, int index_2, const int * distance_matrix);

/**
 * Constrói uma solução do tipo Optimized aplicando o movimento swap em índices aleatórios
 * @param opt_matrix - Estrutura otimizada em matriz com as sub-soluções
 * @param distance_matrix - A matriz de distâncias
 * @return Uma solução vizinha, construída com o movimento swap
 */
OptimizedSolution build_swap(OptimizedMatrix &opt_matrix, const int * distance_matrix);

/**
 * Constrói e retorna uma solução vizinha aplicando o movimento swap em posições aleatórias
 * @param solution Ponteiro para a solução que se deseja realizar o movimento SWAP
 * @param posicao_1 Posição do primeiro vértice para realizar a troca
 * @param posicao_2 Posição do segundo vértice para realizar a troca
 * @param matriz_distancias A matriz de distâncias do problema, usada para calcular a novo FO da solução
 * @return Uma solução vizinha, construída com o movimento swap
 */
Solution build_swap(Solution solution, const int * matriz_distancias);

/**
 * Calcula a melhor solução após realizar todas as possíveis trocas swap entre os pares da solução.
 * @param solucao Solução que deseja realizar o swap_opt
 * @param matriz_distancias A matriz de distâncias do problema, usada para calcular a nova FO da solução
 */
Solution swap_opt(Solution solucao, const int * matriz_distancias, int size = SIZE, int strategy = BEST_IMPROVEMENT);

int test_swap();

#endif //ALGORITMO_TCC_SWAP_H
