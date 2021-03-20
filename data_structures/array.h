//
// Created by Thiago on 10/03/2021.
//

#ifndef ALGORITMO_TCC_ARRAY_H
#define ALGORITMO_TCC_ARRAY_H

/**
 * Duplica os valores de uma lista
 * @param array - Ponteiro para o array que é necessário duplicar
 * @param size - Tamanho do array
 */
void double_array(int * array, int size);

/**
 * Gera um vetor com valores aleatórios entre 0 e max - 1
 * @param size - Tamanho do vetor alocado
 * @param max - Valor máximo gerado para cada elemento
 * @return
 */
int * yield_random_array(int size, int max);

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

#endif //ALGORITMO_TCC_ARRAY_H
