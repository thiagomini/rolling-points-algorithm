//
// Created by Thiago on 19/04/2021.
//

#include "OptMatrix.h"
#include "../utils/array.h"


OptMatrix::OptMatrix(int size, const std::vector<int>& vertices, distance_matrix distance_matrix) {
    matrix.resize(size);
    initialize_vertices(vertices);

    for (int i = 1; i < size; ++i) {
        matrix.at(i).at(i).W = 1;
    }

    for (int i = 2; i <= size; i++) {
        for (int row = 0; row <= size - i; row++) {
            int column = row + (i - 1);
            OptSolution previous_solution =  matrix.at(row).at(column - 1);
            OptSolution next_solution = matrix.at(column).at(column);
            matrix.at(row).at(column) = concatenate_solutions(previous_solution, next_solution, distance_matrix);
        }
    }

    for (int i = 2; i <= size; i++) {
        for (int row = i - 1; row <= size - 1; row++) {
            int column = row - (i - 1);
            OptSolution previous_solution =  matrix.at(row).at(row);
            OptSolution next_solution = matrix.at(row - 1).at(column);
            matrix.at(row).at(column) = concatenate_solutions(previous_solution, next_solution, distance_matrix);
        }
    }
}

OptSolution OptMatrix::get_solution(int row, int column) {
    return matrix.at(row).at(column);
}

void OptMatrix::initialize_vertices(std::vector<int> vertices) {
    int size = (int) matrix.size();

    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            matrix.at(i).push_back(OptSolution(0, 0, 0, slice(vertices, i, j)));
        }
    }

}

OptSolution OptMatrix::get_full_solution() {
    return matrix.at(0).back();
}

void OptMatrix::concatenate_new_solution(OptSolution new_solution, distance_matrix distance_matrix) {
    OptSolution original_solution = get_full_solution();

    std::vector<OptSolution> sub_solutions;
    int size = (int) new_solution.vertices.size();

    for (int i = 0; i < size; ++i) {

    }
}

int OptMatrix::getSize() {
    return (int) matrix.size();
}
