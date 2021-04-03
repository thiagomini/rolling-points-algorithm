//
// Created by Thiago on 27/03/2021.
//

#ifndef ALGORITMO_TCC_NEIGHBORHOOD_GENERATOR_H
#define ALGORITMO_TCC_NEIGHBORHOOD_GENERATOR_H

#define REINSERTION 0
#define SWAP 1
#define OR_OPT2 2

#include "../data_structures/solution.h"

/**
 * Gera uma solução vizinha, utilizando a estratégia passada como parâmetro
 * @param solution Ponteiro para a solução que deseja encontrar a vizinhança
 * @param distance_matrix A matriz de distâncias
 * @param neighborhood 0 para Reinsertion, 1 para SWAP
 * @throws errno 1 caso a vizinhança passada como parâmetro não exista
 * @returns O vizinho gerado
 */
Solution generate_neighbor(Solution &solution, const int *distance_matrix, int neighborhood);

/**
 * Gera uma solução vizinha utilizando uma estratégia aleatória
 * @param solution Ponteiro para a solução que deseja encontrar a vizinhança
 * @param distance_matrix A matriz de distâncias
 * @returs O vizinho gerado
 */
Solution generate_random_neighbor(Solution &solution, const int *distance_matrix);

int test_neighborhood_generator();


#endif //ALGORITMO_TCC_NEIGHBORHOOD_GENERATOR_H
