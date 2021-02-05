#include "DivideAndConquer.h"

// 169. Majority Element
int DivideAndConquer::majorityElement(vector<int>& nums) {
    return majorityElementHelper(nums, 0, (int)nums.size());
}
int DivideAndConquer::majorityElementHelper(vector<int>& nums, int left, int right) {
    if (left == right - 1)
        return nums[left];

    int mid = left + (right - left) / 2;
    int leftMajority = majorityElementHelper(nums, left, mid);
    int rightMajority = majorityElementHelper(nums, mid, right);

    if (leftMajority == rightMajority)
        return leftMajority;
    else {
        int leftMajorityCountInRight = count(nums, mid, right, leftMajority);
        int rightMajorityCountInLeft = count(nums, left, mid, rightMajority);

        if (leftMajorityCountInRight > rightMajorityCountInLeft)
            return leftMajority;
        else
            return rightMajority;
    }
}
int DivideAndConquer::count(vector<int>& nums, int left, int right, int target) {
    int count = 0;
    for (int i = left; i < right; ++i)
        if (nums[i] == target)
            ++count;
    return count;
}
