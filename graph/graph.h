#ifndef ASTARTSPCPP_GRAPH_H
#define ASTARTSPCPP_GRAPH_H

#include<iostream>
#include<cstdlib>
#include<cstring>
#include<map>
#include<queue>
#include<climits>

using namespace std;

inline int index(int src, int dest, int size) {
    return src * size + dest;
}

int prims_mst(const int *adjacency_list, const int &size, const bool *visited);

int random_int(int max);

int *generateGraph(int size, int connectivity);

#endif //ASTARTSPCPP_GRAPH_H