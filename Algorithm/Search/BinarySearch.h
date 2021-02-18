#ifndef ACRUSH_BINARYSEARCH_H
#define ACRUSH_BINARYSEARCH_H

#include "StandardLibrary.h"

using namespace std;

class BinarySearch {
/**
 * C++ STL Interval is left-closed and right-opened: [left, right). It has several advantages:
 *
 * 1. mid = left + (right - left) / 2 <- mid always points the first index of second half.
 *
 *                   [left, right)
 *                     /        \
 *            [left, mid)      [mid + 1, right)
 *
 * 2. loop invariant: left < right. When left == right it terminates the loop iteration.
 *
 * 3. right - left == length of the interval.
 */

/**
 * When do need to search in left-closed and right-closed interval,
 * always drop right half of search space during last iteratioh, and return left.
 *
 *                   [left, right)
 *                     /        \
 *          [left, mid - 1]    [mid + 1, right]
 */

 /*
  * std::lower_bound(v.begin(), v.end(), target);
  *   the first element in the range [first, last) which does not compare less than the target
  *   !(a[i] < target), a[i] >= target
  *
  * std::upper_bound(v.begin(), v.end(), target)
  *   the first element in the range [first, last) which compares greater than target
  *   a[i] > target
  */
public:
    int lower_bound_iterative(std::vector<int>& nums, int target);

    int lower_bound_recursive(std::vector<int>& nums, int target, int low, int high);

    int upper_bound_iterative(std::vector<int>& nums, int target);

    int upper_bound_recursive(std::vector<int>& nums, int target, int low, int high);

/*
 * 35. Search Insert Position
 */
int searchInsert(vector<int>& nums, int target);

};

#endif //ACRUSH_BINARYSEARCH_H
