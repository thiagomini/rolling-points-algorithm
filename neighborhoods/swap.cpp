//
// Created by Thiago on 21/03/2021.
//

#include "swap.h"
#include "../utils/randomizer.h"


void swap(Solution &solucao, const int * matriz_distancias) {
    size_t random_index_1 = RANDOM_BETWEEN(1, solucao.size_of_solution - 1);
    size_t random_index_2 = RANDOM_BETWEEN(1, solucao.size_of_solution - 1);

    while (random_index_2 == random_index_1) {
        random_index_2 = RANDOM_BETWEEN(1, solucao.size_of_solution - 1);
    }

    swap(solucao, random_index_1, random_index_2, matriz_distancias);
}

void swap(Solution  &solucao, size_t posicao_1, size_t posicao_2, const int * matriz_distancias) {
    int aux = solucao.vertices[posicao_1];
    solucao.vertices[posicao_1] = solucao.vertices[posicao_2];
    solucao.vertices[posicao_2] = aux;
    calculate_objective_function(&solucao, matriz_distancias);
}

Solution swap_opt(Solution solucao, const int * matriz_distancias) {
    int best_value = solucao.objective_function;

    Solution best_solution;

    for (int i = 1; i < solucao.size_of_solution - 1; i++) {
        for (int j = i + 1; j < solucao.size_of_solution; j++) {
            swap(solucao, i, j, matriz_distancias);

            if (solucao.objective_function < best_value) {
                best_value = solucao.objective_function;
                clone_solution(solucao, best_solution);
            }
        }
    }

    return best_solution;
}