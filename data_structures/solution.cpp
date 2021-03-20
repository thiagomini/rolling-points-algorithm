//
// Created by Thiago on 20/03/2021.
//

#include <cstdio>
#include "solution.h"
#include <iostream>
#include <cassert>
#include "../configurations.h"
#include "../utils/array.h"

using namespace std;

void calculate_objective_function(Solution * solucao, const int * distance_matrix, int problem_class) {
    size_t number_of_latencies = solucao->size_of_solution - problem_class;

    int latencies [number_of_latencies];
    int distance, vertice_1, vertice_2;

    vertice_1 = solucao->vertices[0];
    vertice_2 = solucao->vertices[1];

    // Recupera a distância na posição: matriz[vertice_1][vertice_2]
    distance = distance_matrix[vertice_1 * solucao->size_of_solution + vertice_2];
    latencies[0] = distance;

    for (size_t i = 1; i < number_of_latencies; i++) {
        vertice_1 = solucao->vertices[i];
        vertice_2 = i == solucao->size_of_solution - 1 ? solucao->vertices[0] : solucao->vertices[i + 1];

        // Recupera a distância na posição: matriz[vertice_1][vertice_2]
        distance = distance_matrix[vertice_1 * solucao->size_of_solution + vertice_2];
        latencies[i] = latencies[i - 1] + distance;
    }

    int final_latency = sum_array(number_of_latencies, latencies);

    solucao->objective_function = final_latency;
}

void test_calculate_objective_function_classical_problem() {
    int matriz_distancias[3][3] = {
            {0, 59, 73},
            {59, 0, 19},
            {73, 19, 0}
    };

    Solution solution = {
            0,
            3
    };

    int chosen_vertices[3] = {0, 1, 2};
    solution.vertices = chosen_vertices;

    calculate_objective_function(&solution, reinterpret_cast<const int *>(matriz_distancias), 1);

    assert(solution.objective_function == 137);
}

void test_calculate_objective_function_non_classical_problem() {
    int matriz_distancias[3][3] = {
            {0, 59, 73},
            {59, 0, 19},
            {73, 19, 0}
    };

    Solution solution = {
            0,
            3
    };

    int chosen_vertices[3] = {0, 1, 2};
    solution.vertices = chosen_vertices;

    calculate_objective_function(&solution, reinterpret_cast<const int *>(matriz_distancias), 0);

    assert(solution.objective_function == 288);
}

void test_solution() {
    test_calculate_objective_function_classical_problem();
    test_calculate_objective_function_non_classical_problem();
    cout << "[solution.cpp] Todos os testes passaram com sucesso!" << endl;
}