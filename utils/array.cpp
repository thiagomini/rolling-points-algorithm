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
    printf("\n");
}

int * build_crescent_array(size_t size, int initial_value) {
    static int * array = new int[size];
    array[0] = initial_value;

    for (int i = 1; i < size; i++) {
        array[i] = array[i-1] + 1;
    }

    return array;
}

int sum_array(size_t size, const int array[]) {
    int sum = 0;

    for (int i = 0; i < size; i++) {
        sum += array[i];
    }

    return sum;
}

int * clone_array(int array[], size_t size) {
    static int * new_array = new int[size];

    for (size_t i = 0; i < size; i++) {
        new_array[i] = array[i];
    }
    return new_array;
}