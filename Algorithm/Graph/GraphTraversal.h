#ifndef ACRUSH_GRAPHTRAVERSAL_H
#define ACRUSH_GRAPHTRAVERSAL_H

#include "StandardLibrary.h"

using namespace std;

class GraphTraversal {
/**
 * BFS
 */

/**
 * DFS
 */

/*
 * 200 Number of Islands
 */
public:
    int numIslands(vector<vector<char>>& grid);
private:
    void numIslandsHelper(const vector<vector<char>>& grid, vector<vector<bool>>& visited, int row, int col);

};

#endif //ACRUSH_GRAPHTRAVERSAL_H
