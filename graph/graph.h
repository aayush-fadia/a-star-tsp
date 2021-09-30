#include<iostream>
#include<cstdlib>
#include<cstring>
#include<map>
#include<queue>
#include<climits>

using namespace std;

int index(int src, int dest, int size);

int prims_mst(const int *adjacency_list, int size, const bool *visited, int current_node);

int random_int(int max);

int *generateGraph(int size, int connectivity);