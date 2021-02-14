#ifndef ACRUSH_BACKTRACKING_H
#define ACRUSH_BACKTRACKING_H

#include "StandardLibrary.h"

using namespace std;

struct TrieNode;

class Backtracking {
/*
 * 46. Permutations
 *
 * Given a collection of distinct integers, return all possible permutations.
 *
 * i. Backtracking
 * ii. BFS <= LIKE
 * iii. Swap
 */
public:
    vector<vector<int>> permute(vector<int>& nums);
private:
    void permuteHelper(vector<int>& nums, int level, vector<bool>& visited, vector<int>& out, vector<vector<int>>& res);

public:
    vector<vector<int> > permuteBFS(vector<int>& nums);

public:
    vector<vector<int>> permuteSwap(vector<int>& nums);
private:
    void permuteSwapHelper(vector<int>& nums, int start, vector<vector<int>>& res);

/*
 * 47. Permutations II
 *
 * Given a collection of numbers that might contain duplicates, return all possible unique permutations.
 *
 * i. Backtracking
 */
public:
    vector<vector<int>> permuteUnique(vector<int>& nums);
private:
    void permuteUniqueHelper(vector<int>& nums, int level, vector<bool>& visited, vector<int>& out, vector<vector<int>>& res);

/*
 * 79. Word Search
 *
 * Given an m x n board and a word, find if the word exists in the grid.
 *
 * i. Backtracking. cannot use memorization due to visited states.
 */
public:
    bool exist(vector<vector<char>>& board, string word);
private:
    bool existHelper(int row, int col, vector<vector<bool>>& visited, vector<vector<char>>& board, string& word);

/*
 * 212. Word Search II
 *
 * Given an m x n board of characters and a list of strings words, return all words on the board.
 *
 * i. Backtracking w/ memorization.
 */
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words);
private:
    void findWordsHelper(int row, int col, vector<vector<bool>>& visited, TrieNode* cur, const vector<vector<char>>& board, vector<string>& res);

};

#endif //ACRUSH_BACKTRACKING_H
