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


node_2d * read_nodes_euc_2d(char *file);

void test_read_nodes_euc_2d();

#endif //ALGORITMO_TCC_DATA_READ_H
