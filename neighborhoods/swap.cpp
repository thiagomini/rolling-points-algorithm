//
// Created by Thiago on 21/03/2021.
//

#include "swap.h"
#include "../utils/randomizer.h"


void swap(Solution &solucao, const int * matriz_distancias, int size) {
    size_t random_index_1 = RANDOM_BETWEEN(1, size - 1);
    size_t random_index_2 = RANDOM_BETWEEN(1, size - 1);

    while (random_index_2 == random_index_1) {
        random_index_2 = RANDOM_BETWEEN(1, size - 1);
    }

    swap(solucao, random_index_1, random_index_2, matriz_distancias);
}

void swap(Solution  &solucao, size_t posicao_1, size_t posicao_2, const int * matriz_distancias, int size) {
    int aux = solucao.vertices[posicao_1];
    solucao.vertices[posicao_1] = solucao.vertices[posicao_2];
    solucao.vertices[posicao_2] = aux;
    calculate_objective_function(&solucao, matriz_distancias, size);
}

Solution build_swap(Solution solution, size_t posicao_1, size_t posicao_2, const int * matriz_distancias, int size) {
    swap(solution, posicao_1, posicao_2, matriz_distancias, size);
    return solution;
}

Solution build_swap(Solution solution, const int * matriz_distancias) {
    swap(solution, matriz_distancias);
    return solution;
}

OptimizedSolution build_swap(OptimizedMatrix &opt_matrix, int index_1, int index_2, const int *distance_matrix) {
    // 1º - Escolher os dois vértices que serão trocados
    OptimizedSolution solution = opt_matrix.get_full_solution();

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
    std::vector<OptimizedSolution> sub_solutions;
    sub_solutions.reserve(5);

    int matrixSize = opt_matrix.size;

    sub_solutions.push_back(opt_matrix.get_solution(0, lower_index - 1));

    if (lower_index + 1 == greater_index) {
        sub_solutions.push_back(opt_matrix.get_solution(greater_index, lower_index));
    } else {
        sub_solutions.push_back(opt_matrix.get_solution(greater_index, greater_index));
        sub_solutions.push_back(opt_matrix.get_solution(lower_index + 1, greater_index - 1));
        sub_solutions.push_back(opt_matrix.get_solution(lower_index, lower_index));
    }

    if (greater_index != matrixSize - 1) {
        sub_solutions.push_back(opt_matrix.get_solution(greater_index + 1, (int) solution.size - 1));
    }

    return concatenate_solutions(sub_solutions, distance_matrix, opt_matrix.size);
}

OptimizedSolution build_swap(OptimizedMatrix &opt_matrix, const int * distance_matrix) {
    int size = opt_matrix.size;

    int random_index_1 = RANDOM_BETWEEN(0, size - 1);
    int random_index_2 = RANDOM_BETWEEN(0, size - 1);

    while (random_index_2 == random_index_1) {
        random_index_2 = RANDOM_BETWEEN(0, size - 1);
    }

    return build_swap(opt_matrix, random_index_1, random_index_2, distance_matrix);
}

Solution swap_opt(Solution solucao, const int * matriz_distancias, int size, int strategy) {
    #ifdef VERBOSE
        cout << "[swap_opt] Realizando Busca Local swap..." << endl;
    #endif
    Solution best_solution, new_solution;
    clone_solution(solucao, best_solution);
    clone_solution(solucao, new_solution);

    for (int i = 1; i < size - 1; i++) {
        for (int j = i + 1; j < size; j++) {
            new_solution = build_swap(solucao, i, j, matriz_distancias, size);
            if (new_solution.objective_function < best_solution.objective_function) {
                clone_solution(new_solution, best_solution);
                if (strategy == FIRST_IMPROVEMENT) goto END_OF_LOOP;
            }
        }
    }

    END_OF_LOOP:
        return best_solution;
}

Solution swap_opt_2(const int * matriz_distancias, OptimizedMatrix &optimized_matrix, int strategy) {
    #ifdef VERBOSE
        cout << "[swap_opt] Realizando Busca Local swap..." << endl;
    #endif
    Solution best_solution, solution = optimized_matrix.get_full_solution().to_normal_solution();
    OptimizedSolution opt_new_solution;
    int size = optimized_matrix.size;

    clone_solution(solution, best_solution);

    for (int i = 1; i < size - 1; i++) {
        for (int j = i + 1; j < size; j++) {
            opt_new_solution = build_swap(optimized_matrix, i, j, matriz_distancias);
            if (opt_new_solution.C < best_solution.objective_function) {
                best_solution = opt_new_solution.to_normal_solution();
                if (strategy == FIRST_IMPROVEMENT) goto END_OF_LOOP;
            }
        }
    }

    END_OF_LOOP:
        return best_solution;
}