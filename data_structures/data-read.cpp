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

#define STRING_MATCH 0

using namespace std;

/**
 * Lê os dados de um arquivo .tsp cujo tipo de peso seja EUC_2D.
 * para mais detalhes, verificar documentação do <a href="http://comopt.ifi.uni-heidelberg.de/software/TSPLIB95/tsp95.pdf">TSPLIB95</a>
 * @example
 * NAME: st70<br>
 * TYPE: TSP<br>
 * COMMENT: 70-city problem (Smith/Thompson)<br>
 * DIMENSION: 70<br>
 * EDGE_WEIGHT_TYPE : EUC_2D<br>
 * NODE_COORD_SECTION<br>
 * 1 64 96<br>
 * 2 80 39<br>
 * 3 69 23<br>
 * @param file - caminho relativo do arquivo .tsp
 * @return lista de nós representados em 2 dimensões.
 */
node_2d * read_nodes_euc_2d(char *file) {
    FILE *f = fopen(file, "r");
    int nodes_in_file = 0;

    if (f == nullptr) {
        cerr << "Erro ao abrir o arquivo " << file;
        exit(EXIT_FAILURE);
    }


    cout << "lendo dados do arquivo: " << file;
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


// Testes

void test_read_nodes_euc_2d() {
    char arquivo[] = "../instances/test_tsp_euc_2d.tsp";
    node_2d * read_nodes = read_nodes_euc_2d(arquivo);

    int expected_nodes[3][3] = {
            {1, 64, 96},
            {2, 80, 39},
            {3, 69, 23},
    };

    assert(read_nodes != nullptr);

    for (int i = 0; i < 3; ++i) {
        assert(read_nodes[i].number == expected_nodes[i][0]);
        assert(read_nodes[i].x == expected_nodes[i][1]);
        assert(read_nodes[i].y == expected_nodes[i][2]);
    }

    cout << "\n[data-read.cpp] Todos os testes passaram com sucesso!\n";
}