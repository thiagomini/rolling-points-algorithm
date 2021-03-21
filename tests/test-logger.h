//
// Created by Thiago on 21/03/2021.
//

#ifndef ALGORITMO_TCC_TEST_LOGGER_H
#define ALGORITMO_TCC_TEST_LOGGER_H

#include <string>

using namespace std;

/**
 * Imprime no stdout o início de um módulo de testes
 * @param module_name Nome do módulo
 * @example
 *  print_test_begin("modulo.cpp");
 */
void print_test_begin(const string& module_name);

/**
 * Imprime no stdout o início de uma função de teste que está incluída em um arquivo de testes
 * @param function_name Nome do função a ser testada
 * @param description Descrição do teste
 * @example
 *  print_sub_test_begin("soma", "Testando a soma de dois numeros negativos");
 */
void print_sub_test_begin(const string& function_name, const string& description);

/**
 * Imprime no stdout o fim de um teste de uma função
 */
void print_sub_test_end();

/**
 * Imprime no stdout o fim de um módulo de testes
 * @param module_name Nome do módulo
 * @example
 *  print_test_end("meu-modulo.cpp");
 */
void print_test_end(const string& module_name);


#endif //ALGORITMO_TCC_TEST_LOGGER_H
