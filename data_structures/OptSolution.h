//
// Created by Thiago on 18/04/2021.
//

#ifndef ALGORITMO_TCC_OPTSOLUTION_H
#define ALGORITMO_TCC_OPTSOLUTION_H


#include <vector>
#include "../configurations.h"
#include "distance-matrix.h"


class OptSolution {

public:
    // Indica o tamanho da solução, descontando o V0
    int W;

    // Indica a soma da latência de cada vértice dessa solução
    int C;

    // Indica a soma do custo das arestas dessa solução
    int T;

    // A lista contendo os vértices da solução
    std::vector<int> vertices;

    /**
     *
     * @param fo - Valor da função objetivo da solução
     * @param size - O tamanho da solução, descontando-se o V0
     * @param total_cost - A soma do custo de cada aresta da solução
     * @param vertices_of_solution - A lista contendo os vértices da solução
     */
    OptSolution(int fo, int size, int total_cost, std::vector<int> vertices_of_solution);

    /**
     * Concatena a solução atual com uma nova, unindo o caminho parcial de ambas
     * @param other_solution
     * @param distance_matrix
     */
    void concatenate(const OptSolution& other_solution, distance_matrix distance_matrix);

    /**
     * Clona a solução atual
     * @return Uma nova solução com as mesmas propriedades que a original
     */
    OptSolution clone() const;

private:
    /**
     * Concatena o valor de T(S) da solução atual com a de outra solução
     * @param other_solution
     * @param distance_matrix
     * @return o novo valor de T(S)
     */
    int concatenate_T(const OptSolution& other_solution, distance_matrix distance_matrix);

    /**
     * Concatena o valor de C(S) da solução atual com a de uma outra solução
     * @param other_solution
     * @param distance_matrix
     * @return o novo valor de C(S)
     */
    int concatenate_C(const OptSolution& other_solution, distance_matrix distance_matrix);

    /**
     * Calcula a distância da nova aresta inserida ao concatenar-se duas soluções
     * @param other_solution
     * @param distance_matrix
     * @example
     * solucao_1 = { 0, 1, 2 }<br>
     * solucao_2 = { 3, 4, 5 }<br>
     * solucao_1.concatenate(solucao_2); // Nova aresta criada: {2, 3}
     * @return a distância da nova aresta criada
     */
    int calculate_new_edge_distance(const OptSolution& other_solution, distance_matrix distance_matrix);
};

/**
 * Cria uma nova solução à partir da concatenação de duas soluções distintas
 * @param solution_1
 * @param solution_2
 * @param distance_matrix
 * @return
 */
OptSolution concatenate_solutions(const OptSolution& solution_1, const OptSolution& solution_2, distance_matrix distance_matrix);

int test_opt_solution();

#endif //ALGORITMO_TCC_OPTSOLUTION_H
