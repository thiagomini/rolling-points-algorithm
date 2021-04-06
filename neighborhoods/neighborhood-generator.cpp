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
            or_switch(neighbor, distance_matrix);
            break;

        case TWO_OPTIMAL:
            two_optimal_move(neighbor, distance_matrix);
            break;

        default:
            throw "neighborhood invalido!";
    }

    return neighbor;
}

Solution generate_random_neighbor(Solution &solution, const int *distance_matrix) {
    int random_neighorbood = RANDOM_BETWEEN(0, 3);
    Solution neighbor = generate_neighbor(solution, distance_matrix, random_neighorbood);
    return neighbor;
}