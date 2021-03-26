//
// Created by Thiago on 21/03/2021.
//

#include "../constructive-heuristic.h"
#include "test-logger.h"
#include "cassert"

int test_build_vertices_array() {
    print_sub_test_begin("build_vertices_array", "Testando a construcao de um array de vertices aleatorios");
    vector<int> random_solution = build_vertices_array(3);
    int sum_of_nodes = sum_array(3, random_solution.data());

    assert(random_solution[0] == 0);
    assert(sum_of_nodes == 3);

    print_sub_test_end();
    return EXIT_SUCCESS;
}

int test_build_random_solution() {
    print_sub_test_begin("build_random_solution", "Testando a construcao de solucao aleatoria");
    int distance_matrix[3][3] = {
            {0, 59, 73},
            {59, 0, 19},
            {73, 19, 0}
    };

    Solution solution = build_random_solution(3, reinterpret_cast<const int *>(distance_matrix));
    assert(solution.size_of_solution == 3);
    assert(solution.objective_function > 0);
    assert(solution.vertices[0] == 0);

    print_sub_test_end();
    return EXIT_SUCCESS;
}

int test_constructive_heuristic() {
    print_test_begin("constructive-heuristic.cpp");
    test_build_vertices_array();
    test_build_random_solution();
    print_test_end("constructive-heuristic.cpp");
    return EXIT_SUCCESS;
}