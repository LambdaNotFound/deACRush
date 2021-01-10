#ifndef ACRUSH_BINARYSEARCH_H
#define ACRUSH_BINARYSEARCH_H

#include "StandardLibrary.h"

using namespace std;

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

};

#endif //ACRUSH_BINARYSEARCH_H
