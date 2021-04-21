//
// Created by Thiago on 19/04/2021.
//

#ifndef ALGORITMO_TCC_OPTMATRIX_H
#define ALGORITMO_TCC_OPTMATRIX_H


#include <vector>
#include "OptSolution.h"

class OptMatrix {
public:

    std::vector<std::vector<OptSolution>> opt_matrix;

    OptMatrix(int size, const std::vector<int>& vertices, distance_matrix);

};


#endif //ALGORITMO_TCC_OPTMATRIX_H
