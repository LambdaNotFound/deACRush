#ifndef ACRUSH_TWOPOINTERS_H
#define ACRUSH_TWOPOINTERS_H

#include "StandardLibrary.h"

using namespace std;

class TwoPointers {
/*
 * 18. 4Sum
 *
 * Given an array nums of n integers and an integer target, are there elements a, b, c, and d in nums such that a + b + c + d = target? Find all unique quadruplets in the array which gives the sum of target.
 *
 * i. TwoPointers, Time: O(n^3)
 *
 */
public:
    vector<vector<int> > fourSum(vector<int>& nums, int target);

/*
 * 167. Two Sum II - Input array is sorted
 *
 * Your returned answers (both index1 and index2) are not zero-based.
 *
 * i. Binary Search
 * ii. Two Pointers <= LIKE, T: O(n)
 */
public:
    vector<int> twoSum(vector<int>& numbers, int target);

public:
    vector<int> twoSumBinarySearch(vector<int>& numbers, int target);

/*
 * 1574. Shortest Subarray to be Removed to Make Array Sorted
 */
public:
    int findLengthOfShortestSubarray(vector<int>& arr);

/**
 * Other
 */

/*
 * 68. Text Justification
 *
 * Input: words = ["This", "is", "an", "example", "of", "text", "justification."], maxWidth = 16
 * Output:
 * [
 * "This    is    an",
 * "example  of text",
 * "justification.  "
 * ]
 *
 */
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth);

};

#endif //ACRUSH_TWOPOINTERS_H
