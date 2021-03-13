#include <ctime>
#include <functional>
#include "heuristica-construtiva.h"
#include "distance.h"
#include "iostream"

using namespace std;

void uniform_default();
void mersenne_twister_engine_seed();
void execute_tests();

int main() {
    srand(time(NULL));

    execute_tests();

    return EXIT_SUCCESS;

}

void calculate_time() {
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
}

void execute_tests() {
    cout << "Iniciando Rotina de Testes...\n";
    test_calculate_euclidean_distance_2d();
}
