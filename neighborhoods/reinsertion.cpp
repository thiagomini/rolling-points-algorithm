//
// Created by Thiago on 22/03/2021.
//

#include "reinsertion.h"
#include "../utils/randomizer.h"
#include "../utils/distance.h"


void reinsert(Solution &solucao, size_t posicao_1, size_t posicao_2, const int * matriz_distancias, int size) {
    int selected_vertex = solucao.vertices[posicao_1];

    if (posicao_1 < posicao_2) {
        for (int i = posicao_1; i < posicao_2; i++) {
            solucao.vertices[i] = solucao.vertices[i + 1];
        }
    } else {
        for (int i = posicao_1; i > posicao_2; i--) {
            solucao.vertices[i] = solucao.vertices[i - 1];
        }
    }

    solucao.vertices[posicao_2] = selected_vertex;
    calculate_objective_function(&solucao, matriz_distancias, size);
}

void reinsert(Solution &solucao, const int * matriz_distancias, int size) {
    size_t random_index_1 = RANDOM_BETWEEN(1, size - 1);
    size_t random_index_2 = RANDOM_BETWEEN(1, size - 1);

    while (random_index_2 == random_index_1) {
        random_index_2 = RANDOM_BETWEEN(1, size - 1);
    }

    reinsert(solucao, random_index_1, random_index_2, matriz_distancias, size);
}

Solution build_reinsert(Solution solucao, size_t posicao_1, size_t posicao_2, const int * matriz_distancias, int size) {
    reinsert(solucao, posicao_1, posicao_2, matriz_distancias, size);
    return solucao;
}

Solution build_reinsert(Solution solucao, const int * matriz_distancias, int size) {
    reinsert(solucao, matriz_distancias, size);
    return solucao;
}

Solution reinsert_opt(Solution solucao, const int * matriz_distancias, int size, int strategy) {
    #ifdef VERBOSE
        cout << "[reinsert_opt] Realizando Busca Local Reinsert..." << endl;
    #endif
    Solution best_solution, new_solution;
    clone_solution(solucao, best_solution);
    clone_solution(solucao, new_solution);

    for (int i = 1; i < size - 1; i++) {
        for (int j = i + 1; j < size; j++) {
            new_solution = build_reinsert(solucao, i, j, matriz_distancias, size);

            if (new_solution.objective_function < best_solution.objective_function) {
                clone_solution(new_solution, best_solution);
                if (strategy == FIRST_IMPROVEMENT) goto END_OF_LOOP;
            }
        }
    }

    END_OF_LOOP:
        return best_solution;
}