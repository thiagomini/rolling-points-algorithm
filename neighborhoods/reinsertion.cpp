//
// Created by Thiago on 22/03/2021.
//

#include "reinsertion.h"
#include "../utils/randomizer.h"
#include "../utils/distance.h"


void reinsert(Solution &solucao, size_t posicao_1, size_t posicao_2, const int * matriz_distancias) {
    int selected_vertex = solucao.vertices.at(posicao_1);

    if (posicao_1 < posicao_2) {
        for (int i = posicao_1; i < posicao_2; i++) {
            solucao.vertices.at(i) = solucao.vertices.at(i + 1);
        }
    } else {
        for (int i = posicao_1; i > posicao_2; i--) {
            solucao.vertices.at(i) = solucao.vertices.at(i - 1);
        }
    }

    solucao.vertices.at(posicao_2) = selected_vertex;
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

Solution build_reinsert(Solution solucao, size_t posicao_1, size_t posicao_2, const int * matriz_distancias) {
    reinsert(solucao, posicao_1, posicao_2, matriz_distancias);
    return solucao;
}

Solution build_reinsert(Solution solucao, const int * matriz_distancias) {
    reinsert(solucao, matriz_distancias);
    return solucao;
}

Solution reinsert_opt(Solution solucao, const int * matriz_distancias) {
    Solution best_solution, new_solution;
    clone_solution(solucao, best_solution);
    clone_solution(solucao, new_solution);

    for (int i = 1; i < solucao.size_of_solution - 1; i++) {
        for (int j = i + 1; j < solucao.size_of_solution; j++) {
            new_solution = build_reinsert(solucao, i, j, matriz_distancias);

            if (new_solution.objective_function < best_solution.objective_function) {
                clone_solution(new_solution, best_solution);
            }
        }
    }

    return best_solution;
}