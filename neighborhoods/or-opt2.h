//
// Created by Thiago on 02/04/2021.
//

#ifndef ALGORITMO_TCC_OR_OPT2_H
#define ALGORITMO_TCC_OR_OPT2_H

#include "../data_structures/solution.h"

/**
 * Realiza um movimento do tipo Or-Opt2, que reinsere dois vértices adjacentes em uma nova posição na solução
 * @param solution - Ponteiro para a solução que será utilizada para o movimento
 * @param vertex_1 - Posição do primeiro vértice que será utilizado no movimento. O vértice adjacente será considerado
 * o vértice logo a seguir na solução. Caso o vértice indicado aqui seja o último do ciclo, antes do V0, o V0 será considerado
 * seu adjacente.
 * @param matriz_distancias
 * @param new_position - A nova posição onde o par de vértices adjacente será realocado
 */
void or_switch(Solution &solution, size_t vertex_1, size_t new_position, const int * matriz_distancias);

/**
 * Realiza um movimento do tipo Or-Opt2, que reinsere dois vértices adjacentes em uma nova posição <b>aleatória</b> na solução
 * @param solution - Ponteiro para a solução que será utilizada para o movimento
 * @param vertex_1 - Posição do primeiro vértice que será utilizado no movimento. O vértice adjacente será considerado
 * o vértice logo a seguir na solução. Caso o vértice indicado aqui seja o último do ciclo, antes do V0, o V0 será considerado
 * seu adjacente.
 * @param matriz_distancias
 */
void or_switch(Solution &solution, const int * matriz_distancias);

/**
 * Realiza uma busca local do tipo Or-Opt2 considerando todas as trocas adjacentes possíveis
 * @param solution Ponteiro para a solução que será utilizada para o movimento
 * @param matriz_distancias
 * @return Melhor Solução encontrada pelo movimento de vizinhança
 */
Solution or_opt2(Solution &solution, const int * matriz_distancias);

int test_or_opt2();

#endif //ALGORITMO_TCC_OR_OPT2_H
