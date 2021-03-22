//
// Módulo para definir métodos de busca local (vizinhança)
//

#ifndef ALGORITMO_TCC_NEIGHBORHOODS_H
#define ALGORITMO_TCC_NEIGHBORHOODS_H

#include "data_structures/solution.h"

/**
 * Troca aleatoriamente duas posições do vetor de solução
 * @param solucao Ponteiro para a solução que se deseja realizar o movimento SWAP
 * @param matriz_distancias A matriz de distâncias do problema, usada para calcular o novo FO da solução
 */
void swap(Solution  &solucao, const int * matriz_distancias);

int test_neighborhoods();

#endif //ALGORITMO_TCC_NEIGHBORHOODS_H
