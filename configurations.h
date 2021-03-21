//
// Created by Thiago on 20/03/2021.
//

#ifndef ALGORITMO_TCC_CONFIGURATIONS_H
#define ALGORITMO_TCC_CONFIGURATIONS_H

// Caso seja 1, indica que o MLP deve ser tratado sem considerar a latência do vértice inicial v0.
// Caso seja 0, a latência do vértice final ao inicial (v0) é considerada no cálculo da solução.
#define CLASSICAL_PROBLEM 1

void print_configurations();

#endif //ALGORITMO_TCC_CONFIGURATIONS_H
