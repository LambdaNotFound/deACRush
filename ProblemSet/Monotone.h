#ifndef ACRUSH_MONOTONE_H
#define ACRUSH_MONOTONE_H

#include "StandardLibrary.h"

using namespace std;

struct ListNode;

class Monotone {
/**
 * Monotonic Stack
 *
 * monotonic decending stack
 */

/*
 * 496. Next Greater Element I
 *
 * i. w/ hashmap
 */
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2);

/*
 * 503. Next Greater Element II
 *
 * i. double read-only array w/ virtual index
 */
public:
    vector<int> nextGreaterElements(vector<int>& nums);

/*
 * 1019. Next Greater Node In Linked List
 */
public:
    vector<int> nextLargerNodes(ListNode* head);

/*
 * 739. Daily Temperatures
 *
 * Given a list of daily temperatures T, return a list such that, for each day in the input, tells you how many days you would have to wait until a warmer temperature. If there is no future day for which this is possible, put 0 instead.
 * For example, given the list of temperatures T = [73, 74, 75, 71, 69, 72, 76, 73], your output should be [1, 1, 4, 2, 1, 1, 0, 0].
 */
public:
    vector<int> dailyTemperatures(vector<int>& T);

/*
 * 402. Remove K Digits
 *
 * Given a non-negative integer num represented as a string, remove k digits from the number so that the new number is the smallest possible.
 *
 * i. generate mono asc stack, keep first (n - k) digits, trim '0' and k digits
 */
public:
    string removeKdigits(string num, int k);

/*
 * 42. Trapping Rain Water
 *
 * i. w/ mono descending stack <= LIKE
 *
 *   S = (min(height[s.top()], height[i]) - bottom) * (i - s.top() - 1)
 *
 *   X
 *   X X       #
 *   X X       #
 *   X X X X * #
 *   X X X X X #
 *   -----------
 *      <- t B i
 *
 *   X
 *   X X . . . #
 *   X X . . . #
 *   X X X X * #
 *   X X X X X #
 *   -----------
 *  <- t B     i
 *
 */
public:
    int trap(vector<int>& height);

/*
 * 84. Largest Rectangle in Histogram
 *
 * i. w/ mono ascending stack <= LIKE
 *
 *   S = heights[s.top()] * (s.empty() ? i : i - s.top() - 1)
 *
 *           A
 *       X X A
 *     X X X A
 *   X X X X A #
 *   -----------
 *      <- t H i
 *
 *           X
 *       X B B
 *     X X B B
 *   X X X B B #
 *   -----------
 *    <- t H   i
 *
 *           X
 *       C C C
 *     X C C C
 *   X X C C C #
 *   -----------
 *  <- t H     i
 */
public:
    int largestRectangleArea(vector<int>& heights);

/**
 * Monotonic Queue
 */

/*
 * 239. Sliding Window Maximum
 *
 * i. Monotonic queue, compare the max with left-most element in current window. Time: O(n)
 * ii. multiset
 *
 */
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k);


public:
    vector<int> maxSlidingWindowMultiSet(vector<int>& nums, int k);
};

#endif //ACRUSH_MONOTONE_H
