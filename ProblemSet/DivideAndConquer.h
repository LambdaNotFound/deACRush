#ifndef ACRUSH_DIVIDEANDCONQUER_H
#define ACRUSH_DIVIDEANDCONQUER_H

#include "StandardLibrary.h"

using namespace std;

class DivideAndConquer {

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

};

#endif //ACRUSH_DIVIDEANDCONQUER_H
