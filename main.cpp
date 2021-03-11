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

    begin = clock();


    build_random_solution(10000);


    end = clock() - begin;
    time_spent = ((double) end) / CLOCKS_PER_SEC;

    printf("Tempo Gasto em Segundos: %f", time_spent);


    return 0;
}
