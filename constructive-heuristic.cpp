//
// Created by Thiago on 11/03/2021.
//

#include <cstdlib>
#include "constructive-heuristic.h"
#include <random>
#include <memory.h>
#include <ctime>

using namespace std;

vector<int> build_vertices_array(size_t size) {
    size_t
    size_of_pool = size - 1,
    selected_position,
    vertex_in_position,
    shuffled_array_cursor = 1;

    vector<int> shuffled_array = vector<int>(size); // Array randomizado

    int * vertices = build_crescent_array(size);

    shuffled_array[0] = vertices[0];

    vector<int> pool = vector<int>(vertices + 1, vertices + size); // Pool de onde os valores aleatórios serão escolhidos

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

   return shuffled_array;
}

Solution build_random_solution(const int * distance_matrix, int size) {
    vector<int> vertices_of_solution = build_vertices_array(size);
    static Solution built_solution;

    memcpy(built_solution.vertices, vertices_of_solution.data(), size * sizeof(int));

    built_solution.size_of_solution = size;
    calculate_objective_function(&built_solution, distance_matrix, size);
    return built_solution;
}

Solution build_greedy_solution(int size, const int * distance_matrix) {
    vector<int> vertices_of_solution(size);
    vertices_of_solution.push_back(0);

    int next_vertex;
    int distances[size];

    for (int i = 1; i < size; i++) {

    }
    return {
        .objective_function = 0
    };
}

int find_nearest_neighbor(int vertex, const int * distance_matrix) {
    return 0;
}


void calculate_build_random_solution_time(size_t size, const int * distance_matrix, int times) {
    clock_t begin, end;
    double time_spent;

    begin = clock();

    for (int i = 0; i < times; ++i) {
        build_random_solution(distance_matrix, size);
    }

    end = clock() - begin;
    time_spent = ((double) end) / CLOCKS_PER_SEC;
    printf("[build_random_solution] Tempo Gasto em Segundos: %f", time_spent);
}