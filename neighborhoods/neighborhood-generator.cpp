//
// Created by Thiago on 27/03/2021.
//

#include "neighborhood-generator.h"
#include "reinsertion.h"
#include "swap.h"
#include "or-opt.h"
#include "../utils/randomizer.h"
#include "2-optimal.h"

Solution generate_neighbor(Solution &solution, const int *distance_matrix, int neighborhood, int size) {
    Solution neighbor;
    clone_solution(solution,neighbor);

    switch (neighborhood) {
        case REINSERTION:
            reinsert(neighbor, distance_matrix, size);
            break;
        case SWAP:
            swap(neighbor, distance_matrix, size);
            break;
        case OR_OPT2:
            or_switch(neighbor, distance_matrix, 2, size);
            break;
        case OR_OPT3:
            or_switch(neighbor, distance_matrix, 3, size);
            break;

        case TWO_OPTIMAL:
            two_optimal_move(neighbor, distance_matrix, size);
            break;

        default:
            throw "neighborhood invalido!";
    }

    return neighbor;
}

Solution apply_local_search(Solution &solution, const int *distance_matrix, int neighborhood, int size, int strategy) {
    Solution generated_solution, best_solution;

    clone_solution(solution, best_solution);

    bool fo_got_better;

    do {
        fo_got_better = false;
        switch (neighborhood) {
            case REINSERTION:
                generated_solution = reinsert_opt(best_solution, distance_matrix, size, strategy);
                break;
            case SWAP:
                generated_solution = swap_opt(best_solution, distance_matrix, size, strategy);
                break;
            case OR_OPT2:
                generated_solution = or_opt_n(best_solution, distance_matrix, 2, size, strategy);
                break;
            case OR_OPT3:
                generated_solution = or_opt_n(best_solution, distance_matrix, 3, size, strategy);
                break;

            case TWO_OPTIMAL:
                generated_solution = two_optimal(best_solution, distance_matrix, size, strategy);
                break;

            default:
                throw "neighborhood invalido!";
        }

        if (compare(best_solution, generated_solution) > 0) {
            fo_got_better = true;
            clone_solution(generated_solution, best_solution);
        }
    } while (fo_got_better);

    return best_solution;
}

Solution apply_local_search(OptimizedMatrix optimized_matrix, const int *distance_matrix, int neighborhood, int size, int strategy) {
    Solution generated_solution;

    bool fo_got_better;

    switch (neighborhood) {
        case REINSERTION:
            generated_solution = reinsert_opt_2(distance_matrix, optimized_matrix, strategy);
            break;
        case SWAP:
            generated_solution = swap_opt_2(distance_matrix, optimized_matrix, strategy);
            break;
        case OR_OPT2:
            generated_solution = or_opt_n_2(distance_matrix, optimized_matrix, 2, strategy);
            break;
        case OR_OPT3:
            generated_solution = or_opt_n_2(distance_matrix, optimized_matrix, 3, strategy);
            break;

        case TWO_OPTIMAL:
            generated_solution = two_optimal_2(distance_matrix, optimized_matrix, strategy);
            break;

        default:
            throw "neighborhood invalido!";
    }
    return generated_solution;
}


Solution generate_random_neighbor(Solution &solution, const int *distance_matrix, int size) {
    int random_neighborhood = RANDOM_BETWEEN(0, 4);
    Solution neighbor = generate_neighbor(solution, distance_matrix, random_neighborhood, size);
    return neighbor;
}

Solution random_local_search(Solution &solution, const int *distance_matrix, int size, int strategy) {
    int random_neighorbood = RANDOM_BETWEEN(0, 4);
    Solution neighbor = apply_local_search(solution, distance_matrix, random_neighorbood, size, strategy);
    return neighbor;
}

Solution random_variable_neighborhood_descent(Solution &solution, const int *distance_matrix, int size) {
    int neighborhoods[5] = { SWAP, REINSERTION, OR_OPT2, OR_OPT3, TWO_OPTIMAL };
    double best_fo = solution.objective_function;

    START_OF_LOOP:
    shuffle_array(neighborhoods, 5);
    for (int neighborhood : neighborhoods) {
            solution = apply_local_search(solution, distance_matrix, neighborhood, size, BEST_IMPROVEMENT);
            if (solution.objective_function < best_fo){
                best_fo = solution.objective_function;
                goto START_OF_LOOP;
            }
        }

        return solution;
}