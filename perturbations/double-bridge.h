//
// Created by Thiago on 13/04/2021.
//

#ifndef ALGORITMO_TCC_DOUBLE_BRIDGE_H
#define ALGORITMO_TCC_DOUBLE_BRIDGE_H

#include "../data_structures/solution.h"

Solution generate_double_bridge(Solution solution, const int * distance_matrix, int edge_1, int edge_2, int edge_3, int edge_4);

void execute_double_bridge(Solution &solution, const int * distance_matrix);


#endif //ALGORITMO_TCC_DOUBLE_BRIDGE_H
