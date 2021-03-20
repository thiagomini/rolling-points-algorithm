//
// Arquivo para definir a estrutura de uma Solução e funções relacionadas
//


#ifndef ALGORITMO_TCC_SOLUTION_H
#define ALGORITMO_TCC_SOLUTION_H

typedef struct {
    int objective_function;
    int size_of_solution;
    int * vertices;
} Solution;

/**
 * Calcula o valor da FO de uma solução por meio da latência total do ciclo hamiltoniano
 * @param solucao - Ponteiro para a solução
 * @param matriz_distancias - A matriz de distâncias dos nós do problema
 */
void calculate_objective_function(Solution * solucao, const int ** matriz_distancias);

void test_solution();

#endif //ALGORITMO_TCC_SOLUTION_H
