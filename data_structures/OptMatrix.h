//
// Created by Thiago on 19/04/2021.
//

#ifndef ALGORITMO_TCC_OPTMATRIX_H
#define ALGORITMO_TCC_OPTMATRIX_H


#include <vector>
#include "OptSolution.h"

class OptMatrix {
public:

    std::vector<std::vector<OptSolution>> matrix;

    OptMatrix(int size, const std::vector<int>& vertices, distance_matrix);

    /**
     * Retorna uma solução da matriz na linha e coluna indicadas
     * @param row - Índice da linha.
     * @param column - Índice da coluna
     * @return A solução da matriz na linha <b>row</b> e coluna <b>column</b>.
     */
    OptSolution get_solution(int row, int column);

private:

    /**
     * Inicializa o array de vértices para cada subsequência da matriz de soluções, de acordo com a posição da mesma. Uma
     * solução na posição [i][j] indica uma subsequência que vai do vértice i ao vértice j na solução original.
     * @example
     * int vertices[3] = {0, 1, 2}; <br>
     * matrix[0][0] = {0}; <br>
     * matrix[0][1] = {0, 1}; <br>
     * matrix[0][2] = {0, 1, 2}; <br>
     * matrix[1][0] = {1, 0}; <br>
     * matrix[1][1] = {1}; <br>
     * matrix[1][2] = {1, 2} <br>
     * ...
     * @param vertices
     */
    void initialize_vertices(std::vector<int> vertices);

};

int test_opt_matrix();


#endif //ALGORITMO_TCC_OPTMATRIX_H
