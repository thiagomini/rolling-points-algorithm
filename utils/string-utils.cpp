//
// Created by Thiago on 13/03/2021.
//

#include <string>
#include <cstring>
#include "string-utils.h"

using namespace std;

bool starts_with_string(const string search_string, const string sub_string) {
    return search_string.find(sub_string) == 0;
}

int find_char_position(string string, char character) {
    char * position_of_character;
    position_of_character = strchr(string.c_str(), character);
    return position_of_character ? (int)(position_of_character - string.c_str()) : -1;
}

bool strings_are_equal(const char *string1, const char *string2) {
    return strcmp(string1, string2) == STRING_MATCH;
}