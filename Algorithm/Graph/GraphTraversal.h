#ifndef ACRUSH_GRAPHTRAVERSAL_H
#define ACRUSH_GRAPHTRAVERSAL_H

#include "StandardLibrary.h"

using namespace std;

class GraphTraversal {
/**
 * Topological Sort (w/ Kahn's algorithm)
 */

/*
 * 207. Course Schedule
 *
 * There are a total of numCourses courses you have to take, labeled from 0 to numCourses-1.
 *
 * Some courses may have prerequisites, for example to take course 0 you have to first take course 1, which is expressed as a pair: [0,1]
 */
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites);

/*
 * 210. Course Schedule II
 */
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites);

/**
 * BFS
 */

/**
 * DFS
 */

/*
 * 419. Battleships in a Board
 *
 * i. trick
 */
public:
    int countBattleships(vector<vector<char>>& board);

/*
 * 200 Number of Islands
 */
public:
    int numIslands(vector<vector<char>>& grid);
private:
    void numIslandsHelper(const vector<vector<char>>& grid, vector<vector<bool>>& visited, int row, int col);

};

#endif //ACRUSH_GRAPHTRAVERSAL_H
