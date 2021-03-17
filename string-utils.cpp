//
// Created by Thiago on 13/03/2021.
//

#include <string>
#include <cassert>
#include <cstring>
#include "iostream"

using namespace std;

bool starts_with_string(const string search_string, const string sub_string) {
    return search_string.find(sub_string) == 0;
}

int find_char_position(const char * string, char character) {
    char * position_of_character;
    position_of_character = strchr(string, character);
    return position_of_character ? (int)(position_of_character - string) : -1;
}


int test_starts_with_string() {
    assert(starts_with_string("Ola mundo", "Ola") == true);
    assert(starts_with_string("OLA MUNDO", "OLA") == true);
    assert(starts_with_string("OLA MUNDO", "OLA ") == true);
    assert(starts_with_string("DIMENSION: 70", "DIMENSION") == true);
    assert(starts_with_string("OLA MUNDO", "Alou") == false);
    return 1;
}

int test_find_char_position() {
    assert(find_char_position("Ola mundo", 'O') == 0);
    assert(find_char_position("Ola mundo", 'o') == 8);
    assert(find_char_position("Alou Mundo", 'o') == 2);
    assert(find_char_position("Alou Mundo", ' ') == 4);
    return 1;
}

int test_string_utils() {
    test_starts_with_string();
    test_find_char_position();
    std::cout << "[string-utils.cpp] Todos os testes passaram com sucesso!\n";
}



#include "string-utils.h"
