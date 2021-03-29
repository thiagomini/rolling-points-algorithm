//
// Created by Thiago on 21/03/2021.
//

#include <cassert>
#include "test-logger.h"
#include "../utils/string-utils.h"

using namespace std;

/**
 * Testa várias possibilidades de uma string começar com outra string
 * @return
 */
int test_starts_with_string() {
    print_sub_test_begin("starts_with_string", "Testando encontrar uma substring dentro de outra");

    assert(starts_with_string("Ola mundo", "Ola") == true);
    assert(starts_with_string("OLA MUNDO", "OLA") == true);
    assert(starts_with_string("OLA MUNDO", "OLA ") == true);
    assert(starts_with_string("DIMENSION: 70", "DIMENSION") == true);
    assert(starts_with_string("OLA MUNDO", "Alou") == false);

    print_sub_test_end();

    return EXIT_SUCCESS;
}

/**
 * Testa a função para encontrar a posição de um caractere em uma string
 * @return
 */
int test_find_char_position() {
    print_sub_test_begin("find_char_position", "Testando encontrar posicao de caractere");

    assert(find_char_position("Ola mundo", 'O') == 0);
    assert(find_char_position("Ola mundo", 'o') == 8);
    assert(find_char_position("Alou Mundo", 'o') == 2);
    assert(find_char_position("Alou Mundo", ' ') == 4);

    print_sub_test_end();

    return EXIT_SUCCESS;
}

int test_strings_are_equal_true() {
    print_sub_test_begin("strings_are_equal", "Testando quando duas strings sao iguais");

    assert(strings_are_equal("Ola mundo", "Ola mundo") == true);
    print_sub_test_end();

    return EXIT_SUCCESS;
}

int test_strings_are_equal_false() {
    print_sub_test_begin("strings_are_equal", "Testando quando duas strings nao sao iguais");

    assert(strings_are_equal("Ola mundo", "Olá mundo") == false);
    print_sub_test_end();

    return EXIT_SUCCESS;
}

int test_string_utils() {
    print_test_begin("string-utils.cpp");

    test_starts_with_string();
    test_find_char_position();
    test_strings_are_equal_true();
    test_strings_are_equal_false();

    print_test_end("string-utils.cpp");

    return EXIT_SUCCESS;
}