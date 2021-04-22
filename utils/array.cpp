//
// Created by Thiago on 10/03/2021.
//

#include "array.h"
#include <cstdlib>
#include <cstdio>
#include "randomizer.h"

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

std::vector<int> slice(std::vector<int> &v, int begin, int end)
{
    std::vector<int> vec;

    end >= begin
    ? std::copy(v.begin() + begin, v.begin() + end + 1, std::back_inserter(vec))
    : std::copy(v.rbegin() + ((int) v.size() - 1 - begin), v.rbegin() + ((int) v.size() - 1 - end) + 1, std::back_inserter(vec));

    return vec;
}

void shuffle_array(int * array, int size) {
    std::vector<int> pool = vector<int>(array, array + size);

    int new_array[size];

    int selected_index; // índice do pool que será selecionado
    int new_positions_cursor = 0;

    while (!pool.empty()) {
        int size_of_pool = (int) pool.size();
        selected_index = size_of_pool == 1 ? 0 : RANDOM_BETWEEN(0, size_of_pool - 1);
        new_array[new_positions_cursor] = pool.at(selected_index);
        pool.erase(pool.begin() + selected_index);
        new_positions_cursor++;
    }

    for (int i = 0; i < size; i++) {
        array[i] = new_array[i];
    }
}

double calculate_mean(double array[], int size) {
    double total = 0;

    for (int i = 0; i < size; i++) {
        total += array[i];
    }

    return total / size;
}