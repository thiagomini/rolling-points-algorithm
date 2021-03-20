//
// Created by Thiago on 11/03/2021.
//

#include <cstdlib>
#include "constructive-heuristic.h"
#include <random>
#include <ctime>
#include <memory.h>

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

unsigned int * build_random_solution(unsigned int * vertices, size_t size) {
    unsigned int size_of_pool = size, selected_position, vertex_in_position, shuffled_array_cursor = 0;
    auto * pool = new unsigned int[size];
    static auto * shuffled_array = new unsigned int[size];

    memcpy(&pool, &vertices, sizeof(vertices[0]));

   while(size_of_pool > 0) {
       selected_position = rand() % size_of_pool;
       vertex_in_position = pool[selected_position];

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