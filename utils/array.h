//
// Módulo com funções utilitárias para listas
//

#ifndef ALGORITMO_TCC_ARRAY_H
#define ALGORITMO_TCC_ARRAY_H

#include <cstdio>
#include <vector>

/**
 * Duplica os valores de uma lista
 * @param array - Ponteiro para o array que é necessário duplicar
 * @param size - Tamanho do array
 */
void double_array(int * array, int size);

/**
 * Verifica se um determinado número está contido em um array
 * @param number - Número a ser pesquisado
 * @param array - Ponteiro para o array onde o número deve ser buscado
 * @param size - Tamanho do array
 * @return
 */
int is_number_in_array(unsigned int number, const unsigned int * array, int size);

/**
 * Imprime os elementos de um array no stdout
 * @param array O array de elemtnos a serem impressos
 * @param size O tamanho do array
 */
void print_array(const void * array, int size);

/**
 * Constrói um array contendo inteiros entre o valor inicial e o tamanho, incrementando em 1
 * @param size - Tamanho total do array
 * @param initial_value - Valor inicial do array
 * @return Um array em ordem crescente
 */
int * build_crescent_array(size_t size, int initial_value = 0);

/**
 * Retorna a soma de todos os elementos contidos no array
 * @param size - Tamanho do array
 * @param array - ponteiro para o array
 * @return A soma inteira dos elementos
 */
int sum_array(size_t size, const int * array);

/**
 * Retorna um ponteiro para uma copia do array de entrada
 * @param array Array que será copiado
 * @param size Tamanho do array que será copiado
 * @return Ponteiro para array copiado
 */
int * clone_array(int array[], size_t size);

/**
 * Testa todas as funções do módulo <b>array.cpp</b>
 */
int test_array();

/**
 * Retorna uma copia de parte de um vector, de acordo com a posição inicial e final passadas
 * @param v - Vetor a ser copiado
 * @param begin - Posição inicial da cópia
 * @param end - Posição final da cópia
 * @return Sub-vector contendo os elementos entre as posições indicadas
 */
std::vector<int> slice(std::vector<int> &v, int begin, int end);

std::vector<int> slice(int * array, int begin, int end);

/**
 * Embaralha os elementos de um array
 * @param array
 * @param size
 */
void shuffle_array(int * array, int size);

/**
 * Calcula a média dos elementos de um array de <b>doubles</b>
 * @param array
 * @param size
 * @return
 */
double calculate_mean(double array[], int size);

#endif //ALGORITMO_TCC_ARRAY_H