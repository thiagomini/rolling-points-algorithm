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

int compare(Solution * solution_1, Solution * solution_2) {
    return solution_1->objective_function - solution_2->objective_function;
}

void print_solution(Solution * solution) {
    cout << "Solucao: " << endl
         << "FO: " << solution->objective_function << endl
         << "vertices: ";
    print_array(solution->vertices, solution->size_of_solution);
}