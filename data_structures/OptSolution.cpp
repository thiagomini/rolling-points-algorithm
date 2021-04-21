//
// Created by Thiago on 17/04/2021.
//

#include <utility>
#include <vector>
#include "distance-matrix.h"
#include "OptSolution.h"

OptSolution::OptSolution(int fo, int size, int total_cost, std::vector<int> vertices_of_solution) {
    C = fo;
    W = size;
    T = total_cost;
    vertices = std::move(vertices_of_solution);
}

void OptSolution::concatenate(const OptSolution& other_solution, const distance_matrix distance_matrix) {
    int new_T = concatenate_T(other_solution, distance_matrix);
    int new_C = concatenate_C(other_solution, distance_matrix);
    int new_W = W + other_solution.W;

    T = new_T;
    C = new_C;
    W = new_W;

    vertices.insert(vertices.end(), other_solution.vertices.begin(), other_solution.vertices.end());
}

int OptSolution::concatenate_T(const OptSolution& other_solution, const distance_matrix distance_matrix) {
    int new_vertex_distance = calculate_new_edge_distance(other_solution, distance_matrix);
    return T + new_vertex_distance + other_solution.T;
}

int OptSolution::concatenate_C(const OptSolution& other_solution, distance_matrix distance_matrix) {
    int new_vertex_distance = calculate_new_edge_distance(other_solution, distance_matrix);
    return C + other_solution.W * (T + new_vertex_distance) + other_solution.C;
}

int OptSolution::calculate_new_edge_distance(const OptSolution& other_solution, distance_matrix distance_matrix) {
    int solution_1_last_vertex = vertices.back();
    int solution_2_first_vertex = other_solution.vertices.front();
    return distance_matrix.distances[solution_1_last_vertex * distance_matrix.size + solution_2_first_vertex];
}

OptSolution OptSolution::clone() const {
    return OptSolution(C, W, T, vertices);
}


OptSolution concatenate_solutions(const OptSolution& solution_1, const OptSolution& solution_2, distance_matrix distance_matrix) {
    OptSolution new_solution = solution_1.clone();
    new_solution.concatenate(solution_2, distance_matrix);
    return new_solution;
}