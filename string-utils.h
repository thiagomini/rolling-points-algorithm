//
// Created by Thiago on 13/03/2021.
//

#ifndef ALGORITMO_TCC_STRING_UTILS_H
#define ALGORITMO_TCC_STRING_UTILS_H

using namespace std;

/**
 * Indica se uma string começa com a outra string passada como parâmetro.
 * @param search_string - A string "maior"
 * @param sub_string - A string "menor", que deverá ser encontrada no começo da string "maior"
 * @return <b>true</b> caso encontre a segunda string dentro da primeira, <b>false</b> do contrário.
 */
bool starts_with_string(string search_string, string sub_string);

/**
 * Encontra a posição de um determinado caractere em uma string
 * @param string - A string a ser buscada o caractere
 * @param character - O caractere a ser encontrado
 * @return A posição do caractere na string (0-based)
 */
int find_char_position(char * string, char character);

int test_string_utils();

#endif //ALGORITMO_TCC_STRING_UTILS_H
