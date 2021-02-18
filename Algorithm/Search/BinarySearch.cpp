#include "BinarySearch.h"

/*
int BinarySearch::lower_bound_iterative(vector<int>& nums, int target) {
    int low = 0, high = nums.size() - 1;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (nums[mid] < target) // first a[i] >= target, lower_bound
            low = mid + 1;
        else
            high = mid - 1;
    }
    return low;
}
 */

int BinarySearch::lower_bound_iterative(vector<int>& nums, int target) {
    int low = 0, high = nums.size();

    while (low < high) { // [ ... ), high = nums.size()
        int mid = low + ((high - low) >> 1); // +, - has higher precedence over <<, >>
        if (nums[mid] < target)
            low = mid + 1;
        else
            high = mid;
    }

    return low; // first a[i] >= target, lower_bound
}

int BinarySearch::lower_bound_recursive(vector<int>& nums, int target, int low, int high) {
    if (low > high)
        return low;
    int mid = low + (high - low) / 2;
    if (nums[mid] < target)
        return lower_bound_recursive(nums, target, mid + 1, high);
    else
        return lower_bound_recursive(nums, target, low, mid - 1);
}

/*
int BinarySearch::upper_bound_iterative(vector<int>& nums, int target) {
    int low = 0, high = nums.size() - 1;

    while (low <= high) {
        int mid = low + ((high - low) >> 1);
        if (nums[mid] <= target) // a[i] > target
            low = mid + 1;
        else
            high = mid - 1;
    }

    return low;
}
 */

int BinarySearch::upper_bound_iterative(vector<int>& nums, int target) {
    int low = 0, high = nums.size();
    while (low < high) {
        int mid = low + (high - low) / 2;
        if (nums[mid] <= target)
            low = mid + 1;
        else
            high = mid;
    }
    return low;
}

int BinarySearch::upper_bound_recursive(vector<int>& nums, int target, int low, int high) {
    if (low > high)
        return low;
    int mid = low + (high - low) / 2;
    if (nums[mid] <= target)
        return upper_bound_recursive(nums, target, mid + 1, high);
    else
        return upper_bound_recursive(nums, target, low, mid - 1);
}

// 35. Search Insert Position
int BinarySearch::searchInsert(vector<int>& nums, int target) {
    int left = 0, right = nums.size();
    while (left < right) {
        int mid = left + (right - left) / 2;
        if (nums[mid] < target)
            left = mid + 1;
        else if (nums[mid] > target)
            right = mid;
        else
            return mid;
    }
    return left;
}
