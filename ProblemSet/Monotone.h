#ifndef ACRUSH_MONOTONE_H
#define ACRUSH_MONOTONE_H

#include "StandardLibrary.h"

using namespace std;

class Monotone {
/**
 * Monotonic Stack
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
