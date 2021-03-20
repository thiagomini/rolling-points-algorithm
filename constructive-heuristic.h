//
// Created by Thiago on 11/03/2021.
//

#ifndef ALGORITMO_TCC_CONSTRUCTIVE_HEURISTIC_H
#define ALGORITMO_TCC_CONSTRUCTIVE_HEURISTIC_H

/**
 * Constrói uma solução aleatória de nós percorridos por movimento de "shuffle" da ordem dos elementos.
 * @param vertices - Ponteiro para lista de vértices que serão reorganizados
 * @param size - Tamanho da lista de vértices
 * @return
 */
unsigned int * build_random_solution(unsigned int * vertices, size_t size);

#endif //ALGORITMO_TCC_CONSTRUCTIVE_HEURISTIC_H
