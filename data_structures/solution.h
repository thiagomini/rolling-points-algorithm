//
// Arquivo para definir a estrutura de uma Solução e funções relacionadas
//


#ifndef ALGORITMO_TCC_SOLUTION_H
#define ALGORITMO_TCC_SOLUTION_H
#include "../configurations.h"
#include "iostream"
#include "../utils/array.h"

using namespace std;

/**
 * Estrutura que representa uma solução do problema MLP
 * @param objective_function Valor da Função Objetivo da solução
 * @param size_of_solution Tamanho da solução em vértices
 * @param vertices Ponteiro para array de vértices que compõe a solução
 */
typedef struct {
    int objective_function;
    size_t size_of_solution;
    int * vertices;
} Solution;

/**
 * Calcula o valor da FO de uma solução por meio da latência total do ciclo hamiltoniano
 * @param solucao  Ponteiro para a solução
 * @param matriz_distancias  A matriz de distâncias dos nós do problema
 * @param problem_class  Indica a classe do problema MLP que está sendo tratado. Caso seja <b>1</b>, é o problema
 * clássico, ou seja, não é contabilizado a última aresta (para o vértice inicial) quando calcular a latência total.
 * Caso seja <b>0</b>, o problema considerará a última aresta no cálculo da FO
 */
void calculate_objective_function(Solution * solucao, const int * matriz_distancias, int problem_class = CLASSICAL_PROBLEM);

/**
 * Função que compara duas soluções de acordo com o valor da função objetivo
 * @param solution_1
 * @param solution_2
 * @return 0 se ambas as soluções possuem a mesma FO, > 0 se a primeira solução possui FO maior que a segunda e < 0 do contrário
 */
int compare(Solution * solution_1, Solution * solution_2);

void print_solution(Solution * solution);

/**
 * Clona uma solução
 * @param origem
 * @param destino
 */
void clone_solution(Solution &origem, Solution &destino);

/**
 * Testa todas as funções do Módulo solution.cpp
 */
int test_solution();

#endif //ALGORITMO_TCC_SOLUTION_H
