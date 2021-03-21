//
// Created by Thiago on 13/03/2021.
//

#include "data-read.h"
#include "iostream"
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cassert>
#include "../utils/string-utils.h"
#include "../configurations.h"

#define STRING_MATCH 0

using namespace std;

node_2d * read_nodes_euc_2d(char *file) {
    FILE *f = fopen(file, "r");
    int nodes_in_file = 0;

    if (f == nullptr) {
        cerr << "Erro ao abrir o arquivo " << file;
        exit(EXIT_FAILURE);
    }


#ifdef VERBOSE
        cout << "lendo dados do arquivo: " << file;
#endif

    char * line_in_file = new char[100];

    line_in_file = fgets(line_in_file, 100, f);
    while(strcmp(line_in_file, "NODE_COORD_SECTION\n") != STRING_MATCH) {
        line_in_file = fgets(line_in_file, 100, f);

        if (starts_with_string(line_in_file, "DIMENSION")) {
            string parsed_line = string(line_in_file);
            size_t colon_position = parsed_line.find_first_of(':') + 1;;

            string only_number_string = parsed_line.substr(colon_position);

            nodes_in_file = strtol(only_number_string.c_str(), nullptr, 10);
        }
    }

    node_2d * list_of_nodes;
    list_of_nodes = static_cast<node_2d *>(calloc(nodes_in_file, sizeof(node_2d)));

    int node_number=0, node_x_coordinate=0, node_y_coordinate=0;
    int i=0;

    for (; i < nodes_in_file; ++i) {
        fscanf(f, "%d %d %d", &node_number, &node_x_coordinate, &node_y_coordinate);
        list_of_nodes[i].number = node_number;
        list_of_nodes[i].x = node_x_coordinate;
        list_of_nodes[i].y = node_y_coordinate;
    }

    return list_of_nodes;
};