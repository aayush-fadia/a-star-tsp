//
// Created by aayush on 9/29/21.
//
#include "input/input.h"

int main() {
    matrix_size m_sz = graphFromFile("/run/media/aayush/OS/Users/Aayush/Acads/AI/Assignments/AStarTSP/gen.txt");
    int *graph = m_sz.first;
    int size = m_sz.second;
    bool *allUnvisited = (bool *) (malloc(size * sizeof(bool)));
    memset(allUnvisited, false, size * sizeof(bool));
    cout << prims_mst(graph, size, allUnvisited, 0)<<endl;
}