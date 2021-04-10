//
// Created by Thiago on 27/03/2021.
//

#include "neighborhood-generator.h"
#include "reinsertion.h"
#include "swap.h"
#include "or-opt.h"
#include "../utils/randomizer.h"
#include "2-optimal.h"

Solution generate_neighbor(Solution &solution, const int *distance_matrix, int neighborhood) {
    Solution neighbor;
    clone_solution(solution,neighbor);

    switch (neighborhood) {
        case REINSERTION:
            reinsert(neighbor, distance_matrix);
            break;
        case SWAP:
            swap(neighbor, distance_matrix);
            break;
        case OR_OPT2:
            or_switch(neighbor, distance_matrix, 2);
            break;
        case OR_OPT3:
            or_switch(neighbor, distance_matrix, 3);
            break;

        case TWO_OPTIMAL:
            two_optimal_move(neighbor, distance_matrix);
            break;

        default:
            throw "neighborhood invalido!";
    }

    return neighbor;
}

Solution apply_local_search(Solution &solution, const int *distance_matrix, int neighborhood, int strategy) {
    Solution best_solution;

    switch (neighborhood) {
        case REINSERTION:
            best_solution = reinsert_opt(solution, distance_matrix, strategy);
            break;
        case SWAP:
            best_solution = swap_opt(solution, distance_matrix, strategy);
            break;
        case OR_OPT2:
            best_solution = or_opt_n(solution, distance_matrix, 2, strategy);
            break;
        case OR_OPT3:
            best_solution = or_opt_n(solution, distance_matrix, 3, strategy);
            break;

        case TWO_OPTIMAL:
            best_solution = two_optimal(solution, distance_matrix, strategy);
            break;

        default:
            throw "neighborhood invalido!";
    }

    return best_solution;
}

Solution generate_random_neighbor(Solution &solution, const int *distance_matrix) {
    int random_neighorbood = RANDOM_BETWEEN(0, 4);
    Solution neighbor = generate_neighbor(solution, distance_matrix, random_neighorbood);
    return neighbor;
}

Solution random_local_search(Solution &solution, const int *distance_matrix, int strategy) {
    int random_neighorbood = RANDOM_BETWEEN(0, 4);
    Solution neighbor = apply_local_search(solution, distance_matrix, random_neighorbood, strategy);
    return neighbor;
}

Solution random_variable_neighborhood_descent(Solution &solution, const int *distance_matrix) {

}