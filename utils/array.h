//
// Módulo com funções utilitárias para listas
//

#ifndef ALGORITMO_TCC_ARRAY_H
#define ALGORITMO_TCC_ARRAY_H

#include <cstdio>

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
 * Testa todas as funções do módulo <b>array.cpp</b>
 */
int test_array();

#endif //ALGORITMO_TCC_ARRAY_H
