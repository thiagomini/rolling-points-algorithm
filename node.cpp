//
// Created by Thiago on 13/03/2021.
//

#include "node.h"

bool compare_nodes(const node_2d node_1, const node_2d node_2) {
    return node_1.number == node_2.number &&
        node_1.x == node_2.x &&
        node_1.y == node_2.y;
}