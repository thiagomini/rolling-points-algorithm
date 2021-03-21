//
// Created by Thiago on 13/03/2021.
//

//
// Módulo contendo funções para ler dados de um arquivo .tsp e transformar em listas de nós
//

#include "node.h"
#include "iostream"
#ifndef ALGORITMO_TCC_DATA_READ_H
#define ALGORITMO_TCC_DATA_READ_H

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
 * @return Ponteiro para lista de nós representados em 2 dimensões.
 */
node_2d * read_nodes_euc_2d(char *file);

int test_data_read();

#endif //ALGORITMO_TCC_DATA_READ_H
