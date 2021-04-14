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

/**
 * Indica se o vetor de inteiros, cada um representando uma aresta, possui alguma aresta que é consecutiva.
 * @param edges - Vetor de inteiros representando arestas
 * @param size - Tamanho do vetor
 * @return <b>true</b> se existe alguma aresta que é consecutiva, <b>false</b< do contrário
 */
bool has_consecutive_edge(int *edges, int size);

/**
 * Retorna uma aresta de uma solução à partir da posição inicial. Caso a posição informada seja a última posição da
 * solução, o segundo nó da aresta será o primeiro nó da solução, que é o nó que fecha o ciclo hamiltoniano
 * @param initial_position - Posição inicial de onde a aresta será retornada
 * @param solution - Solução para recuperação da aresta
 * @example
 *  Solution solution = {
 *      .vertices = { 0, 1, 2 }
 *  };
 *
 *  get_edge(0, solution) // { .first_node = 0, .second_node = 1 }
 * @return A Aresta da solução
 */
edge get_edge(int initial_position, Solution solution);

/**
 * Retorna um vetor contendo as arestas indicadas pelas posições passadas como parâmetro
 * @param positions
 * @param size
 * @param solution
 * @return
 */
vector<edge> get_edges(int positions[], int size, const Solution& solution);

int test_edge();

#endif //ALGORITMO_TCC_EDGE_H
