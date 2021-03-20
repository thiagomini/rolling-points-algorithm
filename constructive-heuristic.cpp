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

using namespace std;

unsigned int mersenne_twister_engine_seed(){
    //mt19937 dist (1234);  //for 32 bit systems
    mt19937_64 dist (time(nullptr)); //for 64 bit systems
    return dist();
}

unsigned int uniform_default(int max)
{
    uniform_int_distribution<size_t> u (0, max);
    default_random_engine e;  // generates unsigned random integers

    return u(e);
}

int * build_random_solution(size_t size) {
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

void test_build_random_solution() {
    int * random_solution = build_random_solution(3);
    int sum_of_nodes = sum_array(3, random_solution);

    assert(random_solution[0] == 0);
    assert(sum_of_nodes == 3);
}

void test_constructive_heuristic() {
    test_build_random_solution();
    cout << "[constructive-heuristic.cpp] Todos os testes foram realizados com sucesso!" << endl;
}