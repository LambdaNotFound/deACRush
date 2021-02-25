#include "GraphTraversal.h"

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
