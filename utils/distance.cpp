//
// Created by Thiago on 13/03/2021.
//

#include "distance.h"
#include "iostream"

using namespace std;

int calculate_euclidean_distance_2d(node_2d node_1, node_2d node_2) {
    int distance_x = node_2.x - node_1.x;
    int distance_y = node_2.y - node_1.y;
    int distance_of_nodes = lround(sqrt(distance_x*distance_x + distance_y*distance_y));
    return distance_of_nodes;
}