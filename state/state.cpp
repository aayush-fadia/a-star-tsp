//
// Created by aayush on 9/28/21.
//

#include "state.h"

State::State(const int *adjacencyMatrix, const int size, const bool *visited, const int currentNode, const int cost,
             const State *prev)
        : adjacency_matrix(adjacencyMatrix), size(size), visited(visited), current_node(currentNode), cost(cost),
          prev(prev) {
    int heuristic = prims_mst(adjacencyMatrix, size, visited, current_node);
    if (heuristic == -1) {
        this->total_cost = -1;
    } else {
        this->total_cost = cost + prims_mst(adjacencyMatrix, size, visited, current_node);
        // f = g + h
    }
}

vector<State *> State::successors() {
    vector<State *> successors;
    if (this->total_cost == -1) {
        return successors;
    }
    if ((this->allVisited()) && (this->current_node != 0)) {
        return successors;
    }
    for (int dst = 0; dst < size; dst++) {
        if ((!this->visited[dst]) && (this->adjacency_matrix[index(this->current_node, dst, this->size)] != -1)) {
            bool *new_visiteds = (bool *) malloc(this->size * sizeof(bool));
            memcpy(new_visiteds, this->visited, size * sizeof(bool));
            new_visiteds[dst] = true;
            successors.emplace_back(new State(this->adjacency_matrix, this->size, new_visiteds, dst,
                                              this->cost +
                                              adjacency_matrix[index(this->current_node, dst, this->size)],
                                              this));
        }
    }
    return successors;
}

bool State::allVisited() const {
    for (int i = 0; i < this->size; i++) {
        if (!this->visited[i]) {
            return false;
        }
    }
    return true;
}

bool State::finish() const {
    for (int i = 0; i < this->size; i++) {
        if (!this->visited[i]) {
            return false;
        }
    }
    return this->current_node == 0;
}
