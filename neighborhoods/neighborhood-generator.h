//
// Created by Thiago on 27/03/2021.
//

#ifndef ALGORITMO_TCC_NEIGHBORHOOD_GENERATOR_H
#define ALGORITMO_TCC_NEIGHBORHOOD_GENERATOR_H

#define REINSERTION 0
#define SWAP 1
#define OR_OPT2 2
#define OR_OPT3 3
#define TWO_OPTIMAL 4

#include "../data_structures/solution.h"

/**
 * Gera uma solução vizinha, utilizando a estratégia passada como parâmetro
 * @param solution Ponteiro para a solução que deseja encontrar a vizinhança
 * @param distance_matrix A matriz de distâncias
 * @param neighborhood - Um número indicando qual vizinhança deve ser aplicada (Verificar possibilidades no header do arquivo)
 * @throws errno 1 caso a vizinhança passada como parâmetro não exista
 * @returns O vizinho gerado
 */
Solution generate_neighbor(Solution &solution, const int *distance_matrix, int neighborhood, int size = SIZE);

/**
 * Gera uma solução vizinha utilizando uma estratégia aleatória
 * @param solution - Ponteiro para a solução que deseja encontrar a vizinhança
 * @param distance_matrix - A matriz de distâncias
 * @returs O vizinho gerado
 */
Solution generate_random_neighbor(Solution &solution, const int *distance_matrix, int size = SIZE);


/**
 * Aplica uma busca local em uma solução de acordo acordo com o parâmetro passado
 * @param solution - Ponteiro para a solução que deseja encontrar a vizinhança
 * @param distance_matrix -  A matriz de distâncias
 * @param neighborhood - Um número indicando qual vizinhança deve ser aplicada ((Verificar possibilidades no header do arquivo)
 * @param strategy - A estratégia da busca local, pode ser 0 (primeira melhora) ou 1 (melhor melhora)
 * @return O vizinho gerado pela busca local
 */
Solution apply_local_search(Solution &solution, const int *distance_matrix, int neighborhood, int size = SIZE, int strategy = FIRST_IMPROVEMENT);

/**
 * Aplica uma busca local aleatória, escolhendo dentre as buscas locais disponíveis
 * @param solution - Ponteiro para a solução que deseja encontrar a vizinhança
 * @param distance_matrix - A matriz de distâncias
 * @param strategy - A estratégia da busca local, pode ser 0 (primeira melhora) ou 1 (melhor melhora)
 * @return O vizinho gerado pela busca local
 */
Solution random_local_search(Solution &solution, const int *distance_matrix, int size = SIZE, int strategy = FIRST_IMPROVEMENT);

/**
 * Retorna a melhor solução obtida por meio do algoritmo RVND, que funciona realizando uma busca local em uma vizinhança
 * aleatória. Quando a busca local termina nessa vizinhança, o algoritmo parte para a próxima.
 * @param solution
 * @param distance_matrix
 * @return
 */
Solution random_variable_neighborhood_descent(Solution &solution, const int *distance_matrix, int size = SIZE);

int test_neighborhood_generator();


#endif //ALGORITMO_TCC_NEIGHBORHOOD_GENERATOR_H
