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

int test_clone_array() {
    print_sub_test_begin("clone_array", "Testando clonagem de um array");

    int array[4] = { 2, 4, 6, 8 };
    int * cloned_array = clone_array(array, 4);

    assert(array[0] == cloned_array[0]);
    assert(array[1] == cloned_array[1]);
    assert(array[2] == cloned_array[2]);
    assert(array[3] == cloned_array[3]);

    print_sub_test_end();

    return EXIT_SUCCESS;
}

int test_clone_array_maintain_original() {
    print_sub_test_begin("clone_array", "Testando clonagem de um array sem Efeito Colateral");

    int array[4] = { 2, 4, 6, 8 };
    int * cloned_array = clone_array(array, 4);

    cloned_array[0] = 10;

    assert(array[0] == 2);
    assert(cloned_array[0] == 10);

    print_sub_test_end();

    return EXIT_SUCCESS;
}

int test_slice_array() {
    print_sub_test_begin("slice", "Testando copia parcial de um vector");

    vector<int> array = { 2, 4, 6, 8 };
    vector<int> sliced_array = slice(array, 0, 1);

    assert(sliced_array.size() == 2);
    assert(sliced_array[0] == 2);
    assert(sliced_array[1] == 4);

    print_sub_test_end();

    return EXIT_SUCCESS;
}

int test_slice_array_single_element() {
    print_sub_test_begin("slice", "Testando copia de apenas um elemento de um vector");

    vector<int> array = { 2, 4, 6, 8 };
    vector<int> sliced_array = slice(array, 0, 0);

    assert(sliced_array.size() == 1);
    assert(sliced_array[0] == 2);
    print_sub_test_end();

    return EXIT_SUCCESS;
}

int test_shuffle_array() {
    print_sub_test_begin("shuffle_array", "Testando shuffle de um array");

    int array[6] = {1, 2, 3, 4, 5, 6};
    shuffle_array(array, 4);

    bool same_order = array[0] == 1 &&
            array[1] == 2 &&
            array[2] == 3 &&
            array[3] == 4 &&
            array[4] == 5 &&
            array[5] == 6;

    bool all_elements_are_different = true;

    for (int i = 0; i < 6; i++) {
        for (int j = i + 1; j < 5; j++) {
            if (array[i] == array[j]) {
                all_elements_are_different = false;
                goto ASSERT;
            }
        }
    }

    ASSERT:
        assert(same_order == false);
        assert(all_elements_are_different == true);
        print_sub_test_end();
        return EXIT_SUCCESS;
}


int test_array() {
    print_test_begin("array.cpp");

    test_build_crescent_array();
    test_sum_array();
    test_clone_array();
    test_clone_array_maintain_original();
    test_slice_array();
    test_slice_array_single_element();
    test_shuffle_array();
    print_test_end("array.cpp");

    return EXIT_SUCCESS;
}

