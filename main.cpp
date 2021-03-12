#include <iostream>
#include <ctime>
#include "array.h"
#include <random>
#include <iostream>
#include <functional>
#include "heuristica-construtiva.h"

using namespace std;

void uniform_default();
void mersenne_twister_engine_seed();

int main() {
    srand(time(NULL));
    clock_t begin, end;
    double time_spent;
    unsigned int i;
    unsigned int vertices[10] = {
            1,2,3,4,5,6,7,8,9,10
    };

    unsigned int * solution;

    begin = clock();


    for (i=0; i<500000; i++) {
        build_random_solution(vertices, 10);
    }

    end = clock() - begin;
    time_spent = ((double) end) / CLOCKS_PER_SEC;

    printf("Tempo Gasto em Segundos: %f", time_spent);


    return 0;
}
