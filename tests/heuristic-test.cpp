//
// Created by Thiago on 21/03/2021.
//

#include <cassert>
#include "../heuristic.h"


void test_random_iterative_heuristic() {
    int distance_matrix[3][3] = {
            {0, 59, 73},
            {59, 0, 19},
            {73, 19, 0}
    };

    int best_fo = 137;

    Solution * best_solution = random_iterative_heuristic(reinterpret_cast<int *>(distance_matrix), 3);
    assert(best_solution->objective_function == best_fo);
}

void test_heuristic() {
    test_random_iterative_heuristic();
    cout << "[heuristic.cpp] Todos os testes passaram com sucesso!" << endl;
}

