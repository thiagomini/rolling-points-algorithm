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

OptSolution build_swap(OptMatrix opt_matrix, int index_1, int index_2, distance_matrix distance_matrix) {
    // 1º - Escolher os dois vértices que serão trocados
    OptSolution solution = opt_matrix.get_full_solution();
    int vertex_1 = solution.vertices.at(index_1);
    int vertex_2 = solution.vertices.at(index_2);

    // 2º - trocar os vértices de posição
    solution.vertices.at(index_1) = vertex_2;
    solution.vertices.at(index_2) = vertex_1;

    // Encontrar o maior e o menor índice
    int greater_index, lower_index;
    if (index_1 > index_2) {
        greater_index = index_1;
        lower_index = index_2;
    } else {
        greater_index = index_2;
        lower_index = index_1;
    }

    // Definir e concatenar as sub-soluções
    std::vector<OptSolution> sub_solutions;
    sub_solutions.push_back(opt_matrix.get_solution(0, lower_index - 1));
    sub_solutions.push_back(opt_matrix.get_solution(greater_index, lower_index));

    if (greater_index != solution.vertices.size() - 1) {
        sub_solutions.push_back(opt_matrix.get_solution(greater_index + 1, (int) solution.vertices.size() - 1));
    }

    return concatenate_solutions(sub_solutions, distance_matrix);
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