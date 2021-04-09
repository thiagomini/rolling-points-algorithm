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

Solution build_swap(Solution solution, size_t posicao_1, size_t posicao_2, const int * matriz_distancias) {
    swap(solution, posicao_1, posicao_2, matriz_distancias);
    return solution;
}

Solution build_swap(Solution solution, const int * matriz_distancias) {
    swap(solution, matriz_distancias);
    return solution;
}

Solution swap_opt(Solution solucao, const int * matriz_distancias, int strategy) {
    #ifdef VERBOSE
        cout << "[swap_opt] Realizando Busca Local swap..." << endl;
    #endif
    Solution best_solution, new_solution;
    clone_solution(solucao, best_solution);
    clone_solution(solucao, new_solution);

    for (int i = 1; i < solucao.size_of_solution - 1; i++) {
        for (int j = i + 1; j < solucao.size_of_solution; j++) {
            new_solution = build_swap(solucao, i, j, matriz_distancias);
            if (new_solution.objective_function < best_solution.objective_function) {
                clone_solution(new_solution, best_solution);
                if (strategy == FIRST_IMPROVEMENT) goto END_OF_LOOP;
            }
        }
    }

    END_OF_LOOP:
        return best_solution;
}