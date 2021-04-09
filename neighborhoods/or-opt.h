//
// Created by Thiago on 02/04/2021.
//

#ifndef ALGORITMO_TCC_OR_OPT_H
#define ALGORITMO_TCC_OR_OPT_H

#include "../data_structures/solution.h"

/**
 * Realiza um movimento do tipo Or-Opt(n), que reinsere <b>n</b> vértices adjacentes em uma nova posição na solução
 * @param solution - Ponteiro para a solução que será utilizada para o movimento
 * @param vertex_1 - Posição do primeiro vértice que será utilizado no movimento. Os vértices adjacentes serão considerados
 * os vértices logo a seguir na solução. Caso o vértice indicado aqui seja o último do ciclo, antes do V0, o V0 será considerado
 * seu adjacente.
 * @param new_position - A nova posição onde o par de vértices adjacente será realocado
 * @param matriz_distancias
 * @param n - O número de vértices adjacentes que serão realocados. O padrão é 2 (Or-Opt2)
 */
void or_switch(Solution &solution, size_t vertex_1, size_t new_position, const int * matriz_distancias, int n = 2);

/**
 * Realiza um movimento do tipo Or-Opt(n), que reinsere <b>n</b> vértices adjacentes em uma nova posição <b>aleatória</b> na solução
 * @param solution - Ponteiro para a solução que será utilizada para o movimento
 * @param vertex_1 - Posição do primeiro vértice que será utilizado no movimento. O vértice adjacente será considerado
 * o vértice logo a seguir na solução. Caso o vértice indicado aqui seja o último do ciclo, antes do V0, o V0 será considerado
 * seu adjacente.
 * @param matriz_distancias
 * @param n - O número de vértices adjacentes que serão realocados. O padrão é 2 (Or-Opt2)
 */
void or_switch(Solution &solution, const int * matriz_distancias, int n = 2);

/**
 * Realiza uma busca local do tipo Or-Opt(n) considerando todas as trocas adjacentes possíveis
 * @param solution - Ponteiro para a solução que será utilizada para o movimento
 * @param matriz_distancias
 * @return Melhor Solução encontrada pelo movimento de vizinhança
 * @param n - O número de vértices adjacentes que serão realocados. O padrão é 2 (Or-Opt2)
 */
Solution or_opt_n(Solution &solution, const int * matriz_distancias, int n = 2, int strategy = BEST_IMPROVEMENT);

/**
 * Constrói e retorna uma solução vizinha aplicando o movimento or-opt(n) em posições escolhidas
 * @param solution - Ponteiro para a solução que será utilizada para o movimento
 * @param vertex_1 Posição do primeiro vértice que será utilizado no movimento. O vértice adjacente será considerado
 * @param new_position A nova posição onde o par de vértices adjacente será realocado
 * @param matriz_distancias
 * @param n - O número de vértices adjacentes que serão realocados. O padrão é 2 (Or-Opt2)
 * @return
 */
Solution build_or_opt_n(Solution solution, size_t vertex_1, size_t new_position, const int * matriz_distancias, int n = 2);


/**
 * Constrói e retorna uma solução vizinha aplicando o movimento or-opt(n) em posições aleatórias
 * @param solution - Ponteiro para a solução que será utilizada para o movimento
 * @param matriz_distancias - A nova posição onde o par de vértices adjacente será realocado
 * @param n - O número de vértices adjacentes que serão realocados. O padrão é 2 (Or-Opt2)
 * @return
 */
Solution build_or_opt_n(Solution solution, const int * matriz_distancias, int n = 2);

int test_or_opt();

#endif //ALGORITMO_TCC_OR_OPT_H
