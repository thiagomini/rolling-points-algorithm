//
// Created by Thiago on 21/03/2021.
//

#include "neighborhoods.h"
#include "utils/randomizer.h"


void swap(Solution &solucao, const int * matriz_distancias) {
    size_t random_index_1 = RANDOM_BETWEEN(1, solucao.size_of_solution - 1);
    size_t random_index_2 = RANDOM_BETWEEN(1, solucao.size_of_solution - 1);

    while (random_index_2 == random_index_1) {
        random_index_2 = RANDOM_BETWEEN(1, solucao.size_of_solution - 1);
    }

    int aux = solucao.vertices[random_index_1];
    solucao.vertices[random_index_1] = solucao.vertices[random_index_2];
    solucao.vertices[random_index_2] = aux;

    calculate_objective_function(&solucao, matriz_distancias);
}