//
// Created by aayush on 9/28/21.
//

#ifndef ASTARTSPCPP_STATE_H
#define ASTARTSPCPP_STATE_H

#include "graph/graph.h"
#include <set>

#endif //ASTARTSPCPP_STATE_H

class State {
public:

    State(const int *adjacencyMatrix, int size, const bool *visited, int currentNode, int cost,
          const State *prev);

    const int *adjacency_matrix;
    int size;
    const bool *visited;
    int current_node;
    int cost;
    int total_cost;
    const State *prev;


    vector<State *> successors();

    bool finish() const;

    bool allVisited() const;
};

struct state_comparator {
    bool operator()(const State *a, const State *b) {
        if (a->total_cost == -1) {
            return true;
        }
        if (b->total_cost == -1) {
            return false;
        }
        return a->total_cost > b->total_cost;
    }
};