#ifndef ACRUSH_MONOTONE_H
#define ACRUSH_MONOTONE_H

#include "StandardLibrary.h"

using namespace std;

class Monotone {
/*
 * 239. Sliding Window Maximum
 *
 * i. Monotonic queue, compare the max with left-most element in current window
 * ii. multiset
 *
 */
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k);

};

#endif //ACRUSH_MONOTONE_H
