//
// Created by Thiago on 18/04/2021.
//

#ifndef ALGORITMO_TCC_OPT_SOLUTION_H
#define ALGORITMO_TCC_OPT_SOLUTION_H


#include <vector>
#include "../configurations.h"
#include "distance-matrix.h"

class Opt_Solution {
public:
    int W;
    int C;
    int T;
    std::vector<int> vertices;

    Opt_Solution(int fo, int size, int total_cost, std::vector<int> vertices_of_solution);

    void concatenate(const Opt_Solution& other_solution, distance_matrix distance_matrix);

    Opt_Solution clone() const;

private:
    int concatenate_T(const Opt_Solution& other_solution, distance_matrix distance_matrix);
    int concatenate_C(const Opt_Solution& other_solution, distance_matrix distance_matrix);
    int calculate_new_vertex_distance(const Opt_Solution& other_solution, distance_matrix distance_matrix);
};

Opt_Solution concatenate_solutions(const Opt_Solution& solution_1, const Opt_Solution& solution_2, distance_matrix distance_matrix);

int test_opt_solution();

#endif //ALGORITMO_TCC_OPT_SOLUTION_H
