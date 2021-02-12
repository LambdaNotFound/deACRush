#ifndef ACRUSH_DIVIDEANDCONQUER_H
#define ACRUSH_DIVIDEANDCONQUER_H

#include "StandardLibrary.h"

using namespace std;

struct TreeNode;

class DivideAndConquer {

/*
 * 95. Unique Binary Search Trees II
 *
 * i. DivideAndConquer w/ memorization
 */
public:
    vector<TreeNode*> generateTrees(int n);
private:
    vector<TreeNode*> generateTreesHelper(int begin, int end, unordered_map<string, vector<TreeNode*>>& memo);

/*
 * 169. Majority Element
 *
 * Given an array nums of size n, return the majority element.
 *
 * The majority element is the element that appears more than ⌊n / 2⌋ times. You may assume that the majority element always exists in the array.
 *
 * i. BitManipulation <= LIKE
 * ii. DivideAndConquer
 */
public:
    int majorityElement(vector<int>& nums);
private:
    int majorityElementHelper(vector<int>& nums, int left, int right);
    int count(vector<int>& nums, int left, int right, int target);

/*
 * 241. Different Ways to Add Parentheses
 *
 * Given a string of numbers and operators, return all possible results from computing all the different possible ways to group numbers and operators. The valid operators are +, - and *.
 *
 * i. DivideAndConquer w/ memorization
 */
public:
    vector<int> diffWaysToCompute(string input);
private:
    vector<int> diffWaysToComputeHelper(const string& s, unordered_map<string, vector<int>>& memo);

};

#endif //ACRUSH_DIVIDEANDCONQUER_H
