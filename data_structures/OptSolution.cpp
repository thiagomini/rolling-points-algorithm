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

    if (vertices.end() != other_solution.vertices.begin()) {
        vertices.insert(vertices.end(), other_solution.vertices.begin(), other_solution.vertices.end());
    }

}

int OptSolution::concatenate_T(const OptSolution& other_solution, const distance_matrix distance_matrix) {
    int new_vertex_distance = calculate_new_edge_distance(other_solution, distance_matrix);
    return T + new_vertex_distance + other_solution.T;
}

int OptSolution::concatenate_C(const OptSolution& other_solution, distance_matrix distance_matrix) {
    int new_vertex_distance = other_solution.vertices.front() == 0 && CLASSICAL_PROBLEM
            ? 0
            : calculate_new_edge_distance(other_solution, distance_matrix);

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

bool OptSolution::equals(const OptSolution& other_solution) const {
    return T == other_solution.T &&
        C == other_solution.C &&
        W == other_solution.W &&
        vertices == other_solution.vertices;
}

OptSolution::OptSolution() {
    C = 0;
    T = 0;
    W = 0;
}

OptSolution::OptSolution(int size, std::vector<int> vertices_of_solution) {
    W = size;
    C = 0;
    T = 0;
    vertices = std::move(vertices_of_solution);
}


OptSolution concatenate_solutions(const OptSolution& solution_1, const OptSolution& solution_2, distance_matrix distance_matrix) {
    OptSolution new_solution = solution_1.clone();
    new_solution.concatenate(solution_2, distance_matrix);
    return new_solution;
}

OptSolution concatenate_solutions(std::vector<OptSolution> solutions, distance_matrix distance_matrix) {
    OptSolution result = solutions.at(0);

    for (int i = 1; i < (int) solutions.size(); ++i) {
        result.concatenate(solutions.at(i), distance_matrix);
    }

    return result;
}