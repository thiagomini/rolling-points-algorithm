//
// Created by Thiago on 20/03/2021.
//

#include <cstdio>
#include "solution.h"
#include <iostream>
#include <cassert>

using namespace std;

template <size_t rows, size_t cols>
void calculate_objective_function(Solution * solucao, int (&matriz_distancias)[rows][cols]) {
    static int latency = 0;
    int distance, vertice_1, vertice_2;
    for (size_t i = 0; i < solucao->size_of_solution; i++) {
        vertice_1 = solucao->vertices[i];
        vertice_2 = i == solucao->size_of_solution - 1 ? solucao->vertices[0] : solucao->vertices[i + 1];
        distance = matriz_distancias[vertice_1][vertice_2];
        latency += distance;
    }
    solucao->objective_function = latency;
}


void test_calculate_objective_function() {
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

    calculate_objective_function(&solution, matriz_distancias);

    assert(solution.objective_function == 151);
}

void test_solution() {
    test_calculate_objective_function();
    cout << "[solution.cpp] Todos os testes passaram com sucesso!\n";
}