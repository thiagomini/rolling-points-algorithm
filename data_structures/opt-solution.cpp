//
// Created by Thiago on 17/04/2021.
//

#include <utility>
#include <vector>
#include "distance-matrix.h"
#include "opt-solution.h"

Opt_Solution::Opt_Solution(int fo, int size, int total_cost, std::vector<int> vertices_of_solution) {
    C = fo;
    W = size;
    T = total_cost;
    vertices = std::move(vertices_of_solution);
}

void Opt_Solution::concatenate(const Opt_Solution& other_solution, const distance_matrix distance_matrix) {
    int new_T = concatenate_T(other_solution, distance_matrix);
    int new_C = concatenate_C(other_solution, distance_matrix);
    int new_W = W + other_solution.W;

    T = new_T;
    C = new_C;
    W = new_W;

    vertices.insert(vertices.end(), other_solution.vertices.begin(), other_solution.vertices.end());
}

int Opt_Solution::concatenate_T(const Opt_Solution& other_solution, const distance_matrix distance_matrix) {
    int new_vertex_distance = calculate_new_edge_distance(other_solution, distance_matrix);
    return T + new_vertex_distance + other_solution.T;
}

int Opt_Solution::concatenate_C(const Opt_Solution& other_solution, distance_matrix distance_matrix) {
    int new_vertex_distance = calculate_new_edge_distance(other_solution, distance_matrix);
    return C + other_solution.W * (T + new_vertex_distance) + other_solution.C;
}

int Opt_Solution::calculate_new_edge_distance(const Opt_Solution& other_solution, distance_matrix distance_matrix) {
    int solution_1_last_vertex = vertices.back();
    int solution_2_first_vertex = other_solution.vertices.front();
    return distance_matrix.distances[solution_1_last_vertex * distance_matrix.size + solution_2_first_vertex];
}

Opt_Solution Opt_Solution::clone() const {
    return Opt_Solution(C, W, T, vertices);
}


Opt_Solution concatenate_solutions(const Opt_Solution& solution_1, const Opt_Solution& solution_2, distance_matrix distance_matrix) {
    Opt_Solution new_solution = solution_1.clone();
    new_solution.concatenate(solution_2, distance_matrix);
    return new_solution;
}