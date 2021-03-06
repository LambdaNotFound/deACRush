#ifndef ACRUSH_BINARYSEARCH_H
#define ACRUSH_BINARYSEARCH_H

#include "StandardLibrary.h"

using namespace std;

/**
 * std::lower_bound(v.begin(), v.end(), target);
 *   the first element in the range [first, last) which does not compare less than the target: first a[i] >= target
 *
 * std::upper_bound(v.begin(), v.end(), target)
 *   the first element in the range [first, last) which compares greater than target: first a[i] > target
 */

class BinarySearch {
/*
 * 4. Median of Two Sorted Arrays
 *
 * i. BinarySearch to find leftMedian from both nums1 and nums2
 * ii. findKthSmallestElement: drop k/2 elements on every binary search
 *
 */
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2);

public:
    double findMedianSortedArraysGeneral(vector<int>& nums1, vector<int>& nums2);
private:
    double findKthSmallestElement(vector<int>& nums1, int i, vector<int>& nums2, int j, int k);

/*
 * 278. First Bad Version
 */
public:
    int firstBadVersion(int n);
private:
    bool isBadVersion(int n) { return false; }

/*
 * 300. Longest Increasing Subsequence
 *
 * i. DP T: O(n^2), S: O(n)
 *
 * ii. BinarySearch T: O(nlgn) <= HARD
 */
public:
    int lengthOfLIS(vector<int>& nums);
private:
    int findUpperBound(const vector<int>& nums, const vector<int>& M, int len, int num);

public:
    int lengthOfLISDP(vector<int>& nums);

/*
 * 1428. Leftmost Column with at Least a One
 *
 * A row-sorted binary matrix means that all elements are 0 or 1 and each row of the matrix is sorted in non-decreasing order.
 * Given a row-sorted binary matrix binaryMatrix, return the index (0-indexed) of the leftmost column with a 1 in it. If such an index does not exist, return -1.
 */
class BinaryMatrix {
public:
    int get(int row, int col) { return 0; }
    vector<int> dimensions() { return {}; }
};

public:
    int leftMostColumnWithOne(BinaryMatrix &binaryMatrix);
};

#endif //ACRUSH_BINARYSEARCH_H
