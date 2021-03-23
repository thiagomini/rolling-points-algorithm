//
// Created by Thiago on 22/03/2021.
//

#include "reinsertion.h"
#include "../utils/randomizer.h"


void reinsert(Solution &solucao, size_t posicao_1, size_t posicao_2, const int * matriz_distancias) {
    int selected_vertex = solucao.vertices[posicao_1];

    for (int i = posicao_1; i < posicao_2; i++) {
        solucao.vertices[i] = solucao.vertices[i + 1];
    }
    solucao.vertices[posicao_2] = selected_vertex;
    calculate_objective_function(&solucao, matriz_distancias);
}

void reinsert(Solution &solucao, const int * matriz_distancias) {
    size_t random_index_1 = RANDOM_BETWEEN(1, solucao.size_of_solution - 1);
    size_t random_index_2 = RANDOM_BETWEEN(1, solucao.size_of_solution - 1);

    while (random_index_2 == random_index_1) {
        random_index_2 = RANDOM_BETWEEN(1, solucao.size_of_solution - 1);
    }

    reinsert(solucao, random_index_1, random_index_2, matriz_distancias);
}