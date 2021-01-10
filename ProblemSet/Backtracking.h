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
 * ii. BFS
 */
public:
    vector<vector<int>> permute(vector<int>& nums);
private:
    void permuteHelper(vector<int>& nums, int level, vector<bool>& visited, vector<int>& out, vector<vector<int>>& res);

public:
    vector<vector<int> > permuteBFS(vector<int>& nums);

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
    void permuteUniqueHelper(vector<int> num, int i, int j, vector<vector<int>> &res);

};

#endif //ACRUSH_BACKTRACKING_H
