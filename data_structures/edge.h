//
// Created by Thiago on 03/04/2021.
//

#ifndef ALGORITMO_TCC_EDGE_H
#define ALGORITMO_TCC_EDGE_H

#include <vector>
#include "solution.h"

/**
 * Estrutura que representa uma aresta direcionada do grafo. A direção é indicada por first_node -> second_node
 */
typedef struct {
    int first_node;
    int second_node;
} edge;

/**
 * Extrai um conjunto de arestas de uma solução, contando com a aresta que liga o último nó ao nó inicial
 * @param solution - Ponteiro para a solução
 * @return vetor de arestas da solução
 */
std::vector<edge> extract_edges(Solution &solution);

/**
 * Compara se duas arestas são equivalentes, ou seja, o primeiro e o segundo nós são iguais
 * @param edge_1 - Primeira aresta a ser comparada
 * @param edge_2 - Segunda aresta a ser comparada
 * @return <b>true</b> caso as arestas sejam iguais, <b>false</b> do contrário
 */
bool edges_are_equal(edge edge_1, edge edge_2);

/**
 * Inverte o direcionamento da aresta, ou seja, o first_node passa a ser o second_node e vice-versa.
 * @param edge
 */
void swap_edge(edge &edge);

int test_edge();

#endif //ALGORITMO_TCC_EDGE_H
