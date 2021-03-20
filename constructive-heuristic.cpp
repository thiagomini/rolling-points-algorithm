//
// Created by Thiago on 11/03/2021.
//

#include <cstdlib>
#include "constructive-heuristic.h"
#include <random>
#include <ctime>
#include <memory.h>
#include <cassert>
#include "utils/array.h"
#include "iostream"
#include "data_structures/solution.h"

using namespace std;

/**
 * Constrói o array de vértices para a solução, sempre começando do vértice 0
 * @param size - Tamanho do array
 * @return
 */
int * build_vertices_array(size_t size) {
    size_t
    size_of_pool = size - 1,
    selected_position,
    vertex_in_position,
    shuffled_array_cursor = 1;

    auto * pool = new int[size_of_pool]; // Pool de onde os valores aleatórios serão escolhidos
    static auto * shuffled_array = new int[size]; // Array randomizado

    int * vertices = build_crescent_array(size);

    shuffled_array[0] = vertices[0];

    memcpy(pool, vertices + 1, sizeof(vertices[0] * size_of_pool));

   while(size_of_pool > 0) {
       selected_position = rand() % size_of_pool;
       vertex_in_position = pool[selected_position];

       // Substitui o valor escolhido da pool pelo último valor da mesma.
       if (selected_position != size_of_pool - 1 && size_of_pool > 1) {
           pool[selected_position] = pool[size_of_pool - 1];
       }

       shuffled_array[shuffled_array_cursor] = vertex_in_position;
       shuffled_array_cursor++;
       size_of_pool--;
   }

   delete[] pool;

   return shuffled_array;
}

Solution * build_random_solution(size_t size, const int * distance_matrix) {
    int * vertices_of_solution = build_vertices_array(size);
    static auto * built_solution = new Solution;

    built_solution->vertices = vertices_of_solution;
    built_solution->size_of_solution = size;
    calculate_objective_function(built_solution, distance_matrix);
    return built_solution;
}

void test_build_vertices_array() {
    int * random_solution = build_vertices_array(3);
    int sum_of_nodes = sum_array(3, random_solution);

    assert(random_solution[0] == 0);
    assert(sum_of_nodes == 3);
}

void test_build_random_solution() {
    int distance_matrix[3][3] = {
            {0, 59, 73},
            {59, 0, 19},
            {73, 19, 0}
    };

    Solution * solution = build_random_solution(3, reinterpret_cast<const int *>(distance_matrix));
    assert(solution->size_of_solution == 3);
    assert(solution->objective_function > 0);
    assert(solution->vertices[0] == 0);
}

void test_constructive_heuristic() {
    test_build_vertices_array();
    test_build_random_solution();
    cout << "[constructive-heuristic.cpp] Todos os testes foram realizados com sucesso!" << endl;
}