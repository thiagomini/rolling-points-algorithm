//
// Created by Thiago on 13/03/2021.
//

//
// Módulo para representações de nós de um grafo
//

#ifndef ALGORITMO_TCC_NODE_H
#define ALGORITMO_TCC_NODE_H

typedef struct {
    int number;
    int x;
    int y;
} node_2d;

typedef struct {
    int number;
    int x;
    int y;
    int z;
} node_3d;

bool compare_nodes(node_2d node_1, node_2d node_2);



#endif //ALGORITMO_TCC_NODE_H
