//
// Created by aayush on 9/29/21.
//

#include "input.h"

pair<int *, int> graphFromFile(const string &file_name) {
    ifstream inFile(file_name);
    string text;
    int lineno = 0;
    int size;
    int *adjacency_matrix;
    while (getline(inFile, text)) {
        if (lineno == 0) {
            size = stoi(text);
            adjacency_matrix = (int *) malloc(size * size * sizeof(int));
        } else {
            istringstream ss(text);
            int col = 0;
            int row = lineno - 1;
            string num;
            while (ss >> num) {
                adjacency_matrix[index(col, row, size)] = stoi(num);
                col++;
            }
        }
        lineno++;
    }
    return matrix_size{adjacency_matrix, size};
}
