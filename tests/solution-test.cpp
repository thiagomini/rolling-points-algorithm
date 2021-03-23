//
// Created by Thiago on 21/03/2021.
//

#include <cassert>
#include "../data_structures/solution.h"
#include "test-logger.h"

/**
 * Testa a comparação de duas soluções em ordem crescente
 */
int test_compare_unequal_asc_solutions() {
    print_sub_test_begin("compare", "Testando a comparacao entre duas solucoes com FOs crescentes");
    Solution solution_1 = { .objective_function = 10 };
    Solution solution_2 = { .objective_function = 20 };

    assert(compare(&solution_1, &solution_2) < 0);

    print_sub_test_end();

    return EXIT_SUCCESS;
}

/**
 * Testa a comparação de duas soluções em ordem descrescente
 */
int test_compare_unequal_desc_solutions() {
    print_sub_test_begin("compare", "Testando a comparacao entre duas solucoes com FOs descrescentes");
    Solution solution_1 = { .objective_function = 30 };
    Solution solution_2 = { .objective_function = 0 };

    assert(compare(&solution_1, &solution_2) > 0);

    print_sub_test_end();
    return EXIT_SUCCESS;
}

/**
 * Testa a comparação de duas soluções com mesmo valor de FO
 */
int test_compare_even_solutions() {
    print_sub_test_begin("compare", "Testando a comparacao entre duas solucoes com FOs iguais");
    Solution solution_1 = { .objective_function = 100 };
    Solution solution_2 = { .objective_function = 100 };

    assert(compare(&solution_1, &solution_2) == 0);

    print_sub_test_end();
    return EXIT_SUCCESS;
}

/**
 * Testa o cálculo da FO para o problema clássico de MLP (Sem considerar latência do V0)
 */
int test_calculate_objective_function_classical_problem() {
    print_sub_test_begin("calculate_objective_function", "Testando o calculo de FO (MLP Classico)");

    int matriz_distancias[3][3] = {
            {0, 59, 73},
            {59, 0, 19},
            {73, 19, 0}
    };

    Solution solution = {
            0,
            3
    };

    int chosen_vertices[3] = {0, 1, 2};
    solution.vertices = chosen_vertices;

    calculate_objective_function(&solution, reinterpret_cast<const int *>(matriz_distancias), 1);

    assert(solution.objective_function == 137);

    print_sub_test_end();
    return EXIT_SUCCESS;
}

/**
 * Testa o cálculo da FO para o problema de MLP variante (considerando a latência do V0)
 */
int test_calculate_objective_function_non_classical_problem() {
    print_sub_test_begin("calculate_objective_function", "Testando o calculo de FO (MLP variante)");
    int matriz_distancias[3][3] = {
            {0, 59, 73},
            {59, 0, 19},
            {73, 19, 0}
    };

    Solution solution = {
            0,
            3
    };

    int chosen_vertices[3] = {0, 1, 2};
    solution.vertices = chosen_vertices;

    calculate_objective_function(&solution, reinterpret_cast<const int *>(matriz_distancias), 0);

    assert(solution.objective_function == 288);
    print_sub_test_end();

    return EXIT_SUCCESS;
}

int test_clone_solution() {
    print_sub_test_begin("clone_solution", "Testando clonagem de solucao");

    // Arrange
    int vertices[] = {0, 1, 2, 3};

    Solution solution_1 = {
            .objective_function = 488,
            .size_of_solution = 4,
            .vertices = vertices
    },
    solution_2;

    // Act
    clone_solution(solution_1, solution_2);

    // Assert
    assert(solution_1.objective_function == solution_2.objective_function);
    assert(solution_1.size_of_solution == solution_2.size_of_solution);
    assert(solution_1.vertices[0] == solution_2.vertices[0]);
    assert(solution_1.vertices[1] == solution_2.vertices[1]);
    assert(solution_1.vertices[2] == solution_2.vertices[2]);
    assert(solution_1.vertices[3] == solution_2.vertices[3]);
    print_sub_test_end();

    return EXIT_SUCCESS;

}

int test_solution() {
    print_test_begin("solution.cpp");

    test_calculate_objective_function_classical_problem();
    test_calculate_objective_function_non_classical_problem();
    test_compare_unequal_asc_solutions();
    test_compare_unequal_desc_solutions();
    test_compare_even_solutions();
    test_clone_solution();

    print_test_end("solution.cpp");
    return EXIT_SUCCESS;
}
