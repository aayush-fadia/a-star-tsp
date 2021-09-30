#include "graph.h"

int prims_mst(const int *adjacency_list, const int &size, const bool *visited) {
    bool *included = (bool *) malloc(size * sizeof(bool));
    memcpy(included, visited, size * sizeof(bool));
    int num_included = 0;
    int not_included_node = 0;
    for (int i = 0; i < size; i++) {
        if (included[i]) {
            num_included += 1;
        } else {
            not_included_node = i;
        }
    }
    int *dst2cost = (int *) malloc(size * sizeof(int));
    memset(dst2cost, -1, size * sizeof(int));
    dst2cost[not_included_node] = 0;
    int total_cost = 0;
    while (num_included < size) {
        int min_cost_to_unvisited = INT_MAX;
        int min_cost_dest = -1;
        for (int j = 0; j < size; j++) {
            if ((!included[j]) && (dst2cost[j] >= 0) && (dst2cost[j] < min_cost_to_unvisited)) {
                min_cost_to_unvisited = dst2cost[j];
                min_cost_dest = j;
            }
        }
        if (min_cost_dest == -1) {
            return -1;
        }
        for (int dst = 0; dst < size; dst++) {
            if (dst2cost[dst] == -1) {
                dst2cost[dst] = adjacency_list[index(min_cost_dest, dst, size)];
            } else if (adjacency_list[index(min_cost_dest, dst, size)] != -1) {
                dst2cost[dst] = min(adjacency_list[index(min_cost_dest, dst, size)], dst2cost[dst]);
            }
        }
        included[min_cost_dest] = true;
        num_included++;
        total_cost += min_cost_to_unvisited;
    }
    return total_cost;
}

int random_int(int max) {
    return rand() % max;
}

int *generateGraph(int size, int connectivity) {
    int *adjacency_list = (int *) malloc(size * size * sizeof(int));
    memset(adjacency_list, -1, size * size * sizeof(int));
    for (int i = 0; i < size; i++) {
        for (int e = 0; e < connectivity; e++) {
            int dst = (random_int(size - 1) + i + 1) % size;
            int len = random_int(100);
            if (adjacency_list[index(i, dst, size)] == -1) {
                adjacency_list[index(i, dst, size)] = len;
                adjacency_list[index(dst, i, size)] = len;
            }
        }
    }
    return adjacency_list;
}
