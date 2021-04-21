//
// Created by Thiago on 19/04/2021.
//

#include "OptMatrix.h"

OptMatrix::OptMatrix(int size, const std::vector<int>& vertices, distance_matrix distance_matrix) {
    opt_matrix.resize(size);

    for (int i = 0; i < size; ++i) {
        opt_matrix.at(i).at(i).T = 0;
        opt_matrix.at(i).at(i).C = 0;
        opt_matrix.at(i).at(i).W = i == 0 ? 0 : 1;
    }

    for (int i = 2; i <= size; i++) {
        for (int row = 0; row <= size - i; row++) {
            int column = row + (i - 1);
            OptSolution previous_solution =  opt_matrix.at(row).at(column - 1);
            OptSolution next_solution = opt_matrix.at(column).at(column);
            opt_matrix.at(row).at(column) = concatenate_solutions(previous_solution, next_solution, distance_matrix);
        }
    }

    for (int i = 2; i <= size; i++) {
        for (int row = i - 1; row <= size - 1; row++) {
            int column = row - (i - 1);
            OptSolution previous_solution =  opt_matrix.at(row).at(row);
            OptSolution next_solution = opt_matrix.at(row - 1).at(column);
            opt_matrix.at(row).at(column) = concatenate_solutions(previous_solution, next_solution, distance_matrix);
        }
    }
}
