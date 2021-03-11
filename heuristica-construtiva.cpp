//
// Created by Thiago on 11/03/2021.
//

#include <cstdlib>
#include <cstdio>
#include "heuristica-construtiva.h"
#include <random>
#include <ctime>
#include "array.h"

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

unsigned int * build_random_solution(int number_of_vertices) {
    static unsigned int * array;

    unsigned int random_number = (rand() % number_of_vertices) + 1;
    array = new unsigned int [number_of_vertices];
    array[0] = random_number;
    int current_position = 1;

    while (current_position < number_of_vertices) {
        random_number = (rand() % number_of_vertices) + 1;
        if(! is_number_in_array(random_number, array, current_position)) {
            array[current_position] = random_number;
            current_position++;
        }
    }

    return array;
}