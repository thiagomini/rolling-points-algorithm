//
// Created by Thiago on 21/03/2021.
//

#include <cassert>
#include "../utils/array.h"
#include "test-logger.h"

/**
 * Testa a geração de um array em ordem crescente
 */
int test_build_crescent_array() {
    print_sub_test_begin("build_crescent_array", "Testando criacao de array crescente");

    int * built_array = build_crescent_array(3);
    for (int i = 0; i < 3; i++) {
        assert(built_array[i] == i);
    }

    print_sub_test_end();
    return EXIT_SUCCESS;
}

/**
 * Testa a soma de todos os elementos de um array
 */
int test_sum_array() {
    print_sub_test_begin("sum_array", "Testando soma de elementos de um array");

    int array[4] = { 2, 4, 6, 8 };
    assert(sum_array(4, array) == 20);

    print_sub_test_end();

    return EXIT_SUCCESS;
}

int test_array() {
    print_test_begin("array.cpp");

    test_build_crescent_array();
    test_sum_array();

    print_test_end("array.cpp");

    return EXIT_SUCCESS;
}

