//
// Created by aayush on 9/28/21.
//

#include "solver.h"

int main(int argc, char **argv) {
    int *graph;
    int size;
    if (argc == 2) {
        cout << "Loading Graph from file..." << endl;
        matrix_size graph_size = graphFromFile(
                argv[1]);
        size = graph_size.second;
        graph = graph_size.first;
    } else if (argc == 3) {
        cout << "Generating Graph..." << endl;
        size = stoi(argv[1]);
        int conn = stoi(argv[2]);
        graph = generateGraph(size, conn);
    } else {
        cout << "Missing Filename or num_nodes and avg_connectivity" << endl;
    }
    tqdm bar;
    bool *allUnvisited = (bool *) (malloc(size * sizeof(bool)));
    memset(allUnvisited, false, size * sizeof(bool));
    auto *to_expand = new State(graph, size, allUnvisited, 0, 0, nullptr); //Initial State
    vector<State *> successors;
    priority_queue<State *, vector<State *>, state_comparator> fringe_list; // Heap
    fringe_list.push(to_expand);
    long expanded = 0;
    long seen = 1;
    while ((!to_expand->finish()) && (!fringe_list.empty())) {
        expanded++;
        bar.progress(expanded, seen);
        successors = to_expand->successors();
        for (State *successor: successors) {
            fringe_list.push(successor);
            seen++;
        }
        to_expand = fringe_list.top();
        fringe_list.pop();
    }
    bar.finish();
    if (to_expand->finish()) {
        const State *prev = to_expand;
        cout << "Solved with a cost of " << prev->cost << endl;
        vector<int> nodes;
        while (prev->prev != nullptr) {
            nodes.push_back(prev->current_node);
            prev = prev->prev;
        }
        for (int n: nodes) {
            cout << n << " ";
        }
        cout << "0\n";
    } else {
        cout << "Unsolvable!";
    }
    return 0;
}
