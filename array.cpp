//
// Created by Thiago on 10/03/2021.
//

#include "array.h"
#include <cstdlib>
#include <cstdio>


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
