#include <ctime>
#include <functional>
#include "constructive-heuristic.h"
#include "data_structures/data-read.h"
#include "utils/distance.h"
#include "iostream"
#include "utils/string-utils.h"
#include <string>
#include "data_structures/distance-matrix.h"
#include "data_structures/solution.h"
#include "utils/array.h"

#include "heuristic.h"

using namespace std;

void execute_tests();
void calculate_time();

int main() {
    srand(time(NULL));

    execute_tests();
//    calculate_time();

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

    end = clock() - begin;
    time_spent = ((double) end) / CLOCKS_PER_SEC;

    printf("Tempo Gasto em Segundos: %f", time_spent);
}

void execute_tests() {
    cout << "Iniciando Rotina de Testes...\n";
    test_calculate_euclidean_distance_2d();
    test_string_utils();
    test_read_nodes_euc_2d();
    test_distance_matrix();
    test_array();
    test_solution();
    test_constructive_heuristic();
    test_heuristic();
}
