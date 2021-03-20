//
// Created by Thiago on 10/03/2021.
//

#include "array.h"
#include <cstdlib>
#include <cstdio>
#include <cassert>
#include "iostream"

using namespace std;


void double_array(int * array, int size) {
    for (int i = 0; i < size; i++) {
        array[i] *= 2;
    }
}

int is_number_in_array(unsigned int number, const unsigned int * array, int size) {
    int initial_position;
    for (initial_position = 0; initial_position < size; initial_position++) {
        if (number == * (array + initial_position)) {
            return 1;
        }
    }
    return 0;
}

void print_array(const void * array, int size) {
    for (int i = 0; i < size; i++) {
        int parsed_int = * ((int *) array + i);
        printf("%d ", parsed_int);
    }
}

int * build_crescent_array(size_t size, int initial_value) {
    static int * array = new int[size];
    array[0] = initial_value;

    for (int i = 1; i < size; i++) {
        array[i] = array[i-1] + 1;
    }

    return array;
}

int sum_array(size_t size, const int * array) {
    int sum = 0;

    for (int i = 0; i < size; i++) {
        sum += array[i];
    }

    return sum;
}

void test_build_crescent_array() {
    int * built_array = build_crescent_array(3);
    for (int i = 0; i < 3; i++) {
        assert(built_array[i] == i);
    }
}

void test_sum_array() {
    int array[4] = { 2, 4, 6, 8 };
    assert(sum_array(4, array) == 20);
}

void test_array() {
    test_build_crescent_array();
    test_sum_array();
    cout << "[array.cpp] Todos os testes foram realizados com Sucesso!" << endl;
}