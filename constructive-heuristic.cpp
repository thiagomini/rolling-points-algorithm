//
// Created by Thiago on 11/03/2021.
//

#include <cstdlib>
#include "constructive-heuristic.h"
#include <random>
#include <memory.h>
#include <cassert>
#include "iostream"

using namespace std;

vector<int> build_vertices_array(size_t size) {
    size_t
    size_of_pool = size - 1,
    selected_position,
    vertex_in_position,
    shuffled_array_cursor = 1;

    auto * pool = new int[size_of_pool]; // Pool de onde os valores aleatórios serão escolhidos
    static vector<int> shuffled_array = vector<int>(size); // Array randomizado

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

Solution build_random_solution(size_t size, const int * distance_matrix) {
    vector<int> vertices_of_solution = build_vertices_array(size);
    static Solution built_solution;

    built_solution.vertices = vertices_of_solution;
    built_solution.size_of_solution = size;
    calculate_objective_function(&built_solution, distance_matrix);
    return built_solution;
}