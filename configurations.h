//
// Arquivo de configurações gerais do sistema
//

#ifndef ALGORITMO_TCC_CONFIGURATIONS_H
#define ALGORITMO_TCC_CONFIGURATIONS_H
#define NUMBER_OF_VERTICES 100

// Caso seja 1, indica que o MLP deve ser tratado sem considerar a latência do vértice inicial v0.
// Caso seja 0, a latência do vértice final ao inicial (v0) é considerada no cálculo da solução.
#define CLASSICAL_PROBLEM 1

// Indica se os algoritmos devem imprimir os passos em detalhes
//#define VERBOSE

void print_configurations();

#endif //ALGORITMO_TCC_CONFIGURATIONS_H
