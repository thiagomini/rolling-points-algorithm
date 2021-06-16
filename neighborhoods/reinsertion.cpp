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

OptimizedSolution build_reinsert(OptimizedMatrix optimized_matrix, int posicao_1, int posicao_2, const int * matriz_distancias) {
    std::vector<OptimizedSolution> sub_solutions;
    sub_solutions.reserve(5);
    int last_index_of_matrix = optimized_matrix.size - 1;

    if (posicao_2 > posicao_1) {
        sub_solutions.push_back(optimized_matrix.get_solution(0, posicao_1 - 1));

        if (posicao_1 + 1 == posicao_2) {
            sub_solutions.push_back(optimized_matrix.get_solution(posicao_2, posicao_1));
        } else {
            sub_solutions.push_back(optimized_matrix.get_solution(posicao_1 + 1, posicao_2));
            sub_solutions.push_back(optimized_matrix.get_solution(posicao_1, posicao_1));
        }

        if (posicao_2 + 1 <= last_index_of_matrix) {
            sub_solutions.push_back(optimized_matrix.get_solution(posicao_2 + 1, last_index_of_matrix));
        }
    } else {
        sub_solutions.push_back(optimized_matrix.get_solution(0, posicao_2 - 1));
        if (posicao_1 == posicao_2 + 1) {
            sub_solutions.push_back(optimized_matrix.get_solution(posicao_1, posicao_2));
        } else {
            sub_solutions.push_back(optimized_matrix.get_solution(posicao_1, posicao_1));
            sub_solutions.push_back(optimized_matrix.get_solution(posicao_2, posicao_1 - 1));
        }

        if (posicao_1 + 1 <= last_index_of_matrix) {
            sub_solutions.push_back(optimized_matrix.get_solution(posicao_1 + 1, last_index_of_matrix));
        }
    }

    return concatenate_solutions(sub_solutions, matriz_distancias, optimized_matrix.size);;
}

Solution build_reinsert(Solution solucao, const int * matriz_distancias, int size) {
    reinsert(solucao, matriz_distancias, size);
    return solucao;
}

Solution reinsert_opt(Solution solucao, const int * matriz_distancias, int size, int strategy) {
    #ifdef VERBOSE
        cout << "[reinsert_opt] Realizando Busca Local Reinsert..." << endl;
    #endif
    Solution best_solution, new_solution_1, new_solution_2, best_new_solution;
    clone_solution(solucao, best_solution);
    clone_solution(solucao, new_solution_1);

    for (int i = 1; i < size - 1; i++) {
        for (int j = i + 1; j < size; j++) {
            new_solution_1 = build_reinsert(solucao, i, j, matriz_distancias, size);
            new_solution_2 = build_reinsert(solucao, j, i, matriz_distancias, size);
            best_new_solution = new_solution_1.objective_function < new_solution_2.objective_function
                    ? new_solution_1
                    : new_solution_2;

            if (best_new_solution.objective_function < best_solution.objective_function) {
                clone_solution(best_new_solution, best_solution);
                if (strategy == FIRST_IMPROVEMENT) goto END_OF_LOOP;
            }
        }
    }

    END_OF_LOOP:
        return best_solution;
}

Solution reinsert_opt_2(const int * matriz_distancias, OptimizedMatrix optimized_matrix, int strategy) {
#ifdef VERBOSE
    cout << "[reinsert_opt] Realizando Busca Local Reinsert..." << endl;
#endif
    Solution best_solution = optimized_matrix.get_full_solution().to_normal_solution();
    int size = optimized_matrix.size;

    for (int i = 1; i < size - 1; i++) {
        for (int j = i + 1; j < size; j++) {
            OptimizedSolution new_solution_1 = build_reinsert(optimized_matrix, i, j, matriz_distancias);
            OptimizedSolution new_solution_2 = build_reinsert(optimized_matrix, j, i, matriz_distancias);

            OptimizedSolution best_new_solution = new_solution_1.C < new_solution_2.C
                                ? new_solution_1
                                : new_solution_2;

            if (best_new_solution.C < best_solution.objective_function) {
                best_solution = best_new_solution.to_normal_solution();
                if (strategy == FIRST_IMPROVEMENT) goto END_OF_LOOP;
            }
        }
    }

    END_OF_LOOP:
    return best_solution;
}