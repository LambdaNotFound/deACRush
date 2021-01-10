#ifndef ACRUSH_BACKTRACKING_H
#define ACRUSH_BACKTRACKING_H

#include "StandardLibrary.h"

using namespace std;

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

};

#endif //ACRUSH_BACKTRACKING_H
