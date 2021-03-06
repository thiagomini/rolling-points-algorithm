//
// Módulo com utilitários para strings
//

#ifndef ALGORITMO_TCC_STRING_UTILS_H
#define ALGORITMO_TCC_STRING_UTILS_H
#define STRING_MATCH 0

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
int find_char_position(string string, char character);

/**
 * Testa todas as funções do módulo
 * @return 0 se todos os testes passaram, 1 do contrário
 */
int test_string_utils();

/**
 * Testa se duas strings são iguais
 * @param string1
 * @param string2
 * @return <b>true</b> caso sejam iguais, <b>false</b> do contrário.
 */
bool strings_are_equal(const char *string1, const char *string2);

#endif //ALGORITMO_TCC_STRING_UTILS_H
