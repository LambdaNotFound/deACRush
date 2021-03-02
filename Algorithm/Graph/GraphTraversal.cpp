#include "GraphTraversal.h"

// 207. Course Schedule
bool GraphTraversal::canFinish(int numCourses, vector<vector<int>>& prerequisites) {
    vector<int> res;
    vector<vector<int> > adjacencyList(numCourses, vector<int>(0));
    vector<int> edgeIn(numCourses, 0);
    for (auto& a : prerequisites) {
        adjacencyList[a[1]].push_back(a[0]);
        ++edgeIn[a[0]];
    }

    queue<int> q;
    for (int i = 0; i < numCourses; ++i)
        if (edgeIn[i] == 0)
            q.push(i);

    while (!q.empty()) {
        int tmp = q.front(); q.pop();
        res.push_back(tmp);

        for (auto& a : adjacencyList[tmp]) {
            --edgeIn[a];
            if (edgeIn[a] == 0)
                q.push(a);
        }
    }

    if (res.size() != numCourses)
        res.clear();

    return res.size() == numCourses;
}

// 210. Course Schedule II
vector<int> GraphTraversal::findOrder(int numCourses, vector<vector<int>>& prerequisites) {
    vector<int> res;
    vector<vector<int> > adjacencyList(numCourses, vector<int>(0));
    vector<int> edgeIn(numCourses, 0);
    for (auto& a : prerequisites) {
        adjacencyList[a[1]].push_back(a[0]);
        ++edgeIn[a[0]];
    }

    queue<int> q;
    for (int i = 0; i < numCourses; ++i)
        if (edgeIn[i] == 0)
            q.push(i);

    while (!q.empty()) {
        int tmp = q.front(); q.pop();
        res.push_back(tmp);

        for (auto& a : adjacencyList[tmp]) {
            --edgeIn[a];
            if (edgeIn[a] == 0)
                q.push(a);
        }
    }

    if (res.size() != numCourses)
        res.clear();

    return res;
}

// 419. Battleships in a Board
int GraphTraversal::countBattleships(vector<vector<char>>& board) {
    if (board.empty())
        return 0;

    int res = 0, m = board.size(), n = board[0].size();
    for (int i = 0; i < m; ++i)
        for (int j = 0; j < n; ++j) {
            if (board[i][j] != 'X' ||
                (i > 0 && board[i - 1][j] == 'X') ||
                (j > 0 && board[i][j - 1] == 'X')
            )
                continue;
            ++res;
        }

    return res;
}

// 200 Number of Islands
int GraphTraversal::numIslands(vector<vector<char>>& grid) {
    if (grid.empty())
        return 0;

    int m = grid.size(), n = grid[0].size(), count = 0;
    vector<vector<bool>> visited(m, vector<bool>(n));
    for (int i = 0; i < m; ++i)
        for (int j = 0; j < n; ++j) {
            if (grid[i][j] != '1' || visited[i][j])
                continue;
            numIslandsHelper(grid, visited, i, j);
            ++count;
        }

    return count;
}
void GraphTraversal::numIslandsHelper(const vector<vector<char>>& grid, vector<vector<bool>>& visited, int row, int col) {
    int m = grid.size(), n = grid[0].size();
    if (row < 0 || row >= m || col < 0 || col >= n)
        return;
    if (grid[row][col] != '1' || visited[row][col])
        return;

    visited[row][col] = true;

    vector<int> diffX = { 0, 1, 0, -1 };
    vector<int> diffY = { 1, 0, -1, 0 };
    for (int k = 0; k < 4; ++k)
        numIslandsHelper(grid, visited, row + diffY[k], col + diffX[k]);
}
